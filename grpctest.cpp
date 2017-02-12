/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * And MizukiSonoko  ( mizuki.sonoko@gmail.com )
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thread>
#include <cassert>
#include <grpc++/grpc++.h>

#include "sample_generated.h"
#include "sample.grpc.fb.h"

using namespace sample;

// The callback implementation of our server, that derives from the generated
// code. It implements all rpcs specified in the FlatBuffers schema.
class ServiceImpl final : public sample::SampleService::Service {
  virtual ::grpc::Status Endpoint(
    ::grpc::ServerContext* context,
    const flatbuffers::BufferRef<SampleRoot> *request,
    flatbuffers::BufferRef<Response> *response
  ) override {

    auto sampleRootT = std::move(*request->GetRoot()->UnPack());

    assert(sampleRootT.wrapper.AsWrapper1() != nullptr);
    assert(sampleRootT.wrapper.AsWrapper1()->object.AsObject1() != nullptr); 
    assert(sampleRootT.wrapper.AsWrapper1()->object.AsObject1()->text != "object1_text");
    assert(sampleRootT.wrapper.AsWrapper1()->object.AsObject1()->boolean);

    auto responseT = ResponseT();
    responseT.status = 200;
    responseT.message = "Hello";

    fbb_.Clear();
    fbb_.Finish(Response::Pack( fbb_, &responseT));
    *response = flatbuffers::BufferRef<Response>(
      fbb_.GetBufferPointer(),
      fbb_.GetSize()
    );
    return grpc::Status::OK;
  }
 private:
  flatbuffers::FlatBufferBuilder fbb_;
};

// Track the server instance, so we can terminate it later.
grpc::Server *server_instance = nullptr;
// Mutex to protec this variable.
std::mutex wait_for_server;
std::condition_variable server_instance_cv;

// This function implements the server thread.
void RunServer() {
  auto server_address = "0.0.0.0:50051";
  // Callback interface we implemented above.
  ServiceImpl service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  // Start the server. Lock to change the variable we're changing.
  wait_for_server.lock();
  server_instance = builder.BuildAndStart().release();
  wait_for_server.unlock();
  server_instance_cv.notify_one();

  std::cout << "Server listening on " << server_address << std::endl;
  // This will block the thread and serve requests.
  server_instance->Wait();
}

int main(int /*argc*/, const char * /*argv*/[]) {
  // Launch server.
  std::thread server_thread(RunServer);

  // wait for server to spin up.
  std::unique_lock<std::mutex> lock(wait_for_server);
  while (!server_instance) server_instance_cv.wait(lock);

  // Now connect the client.
  auto channel = grpc::CreateChannel("localhost:50051",
                                     grpc::InsecureChannelCredentials());
  auto stub = SampleService::NewStub(channel);

  grpc::ClientContext context;

  auto object1T = Object1T();
  object1T.text = "object1_text";
  object1T.boolean = true;

  auto wrapper1T = Wrapper1T();
  wrapper1T.object.Set(std::move(object1T));

  auto sampleRootT = SampleRootT();
  sampleRootT.wrapper.Set(std::move(wrapper1T));

  flatbuffers::FlatBufferBuilder fbb;
  fbb.Finish(SampleRoot::Pack( fbb, &sampleRootT));
  auto request = flatbuffers::BufferRef<SampleRoot>(
    fbb.GetBufferPointer(),
    fbb.GetSize()
  );
  flatbuffers::BufferRef<Response> response;

  // The actual RPC.
  auto status = stub->Endpoint(&context, request, &response);

  if (status.ok()) {
    auto resp = response.GetRoot()->message();
    std::cout << "RPC response: " << resp->str() << std::endl;
    assert( resp->str() == "Hello");
  } else {
    std::cout << "RPC failed" << std::endl;
  }

  server_instance->Shutdown();

  server_thread.join();

  delete server_instance;

  return 0;
}

