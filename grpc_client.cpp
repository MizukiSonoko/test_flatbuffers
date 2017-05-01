#include <csignal>
#include <chrono>
#include <atomic>
#include <thread>
#include <grpc++/grpc++.h>

#include "grpc/for_grpc.grpc.fb.h"
#include "grpc/for_grpc_generated.h"


using namespace sample;

flatbuffers::BufferRef<Request> make(int i){
    flatbuffers::FlatBufferBuilder fbb_;
    std::unique_ptr<std::vector<uint8_t>> nested_req_vec(
            new std::vector<uint8_t>()
    );
    {
        flatbuffers::FlatBufferBuilder fbb_nested;
        auto nested_req_offset = CreateNestedReq(
            fbb_nested,
            fbb_nested.CreateString("Nested request")
        );
        fbb_nested.Finish(nested_req_offset);
        auto buf = fbb_nested.GetBufferPointer();

        nested_req_vec->assign(
                buf, buf + fbb_nested.GetSize()
        );
    }
    auto msg = "Query!!";
    auto request_offset = CreateResponseDirect(
            fbb_,
            msg,
            i,
            nested_req_vec.get()
    );
    fbb_.Finish(request_offset);
    return flatbuffers::BufferRef<Request>(
            fbb_.GetBufferPointer(),fbb_.GetSize()
    );
}

int main(int argc, char* argv[]){

  // Now connect the client.
  auto channel = grpc::CreateChannel("172.17.0.6:50051",
                                     grpc::InsecureChannelCredentials());
  auto stub = SampleEndpoint::NewStub(channel);

  grpc::ClientContext context;

  // Build a request with the name set.
  flatbuffers::BufferRef<Response> response;

  // The actual RPC.
  auto req = make(10);
  auto stream = stub->Stream(&context, req);

  while (stream->Read(&response)) {
    auto resp = response.GetRoot()->message();
    std::cout << "RPC response: " << resp->str() << std::endl;
  }

}
