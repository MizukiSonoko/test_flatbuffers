
#include <csignal>
#include <atomic>
#include <thread>
#include <grpc++/grpc++.h>

#include "grpc/for_grpc.grpc.fb.h>
#include "grpc/for_grpc_generated.h>

std::atomic_bool running(true);

void signalHandler(int param) {;
    running = false;
}

using namespace sample;

class ServiceImpl final : public sample::SampleEndpoint::Service {
    virtual ::grpc::Status Port(
        ::grpc::ServerContext* context,
        const flatbuffers::BufferRef<Request> *request,
        flatbuffers::BufferRef<Response> *response
    ) override {
        fbb_.Clear();
        auto response_offset = CreateResponse(
             fbb_,
             fbb_.CreateString("Ok! " + request->GetRoot()->text()->str()),
             request->GetRoot()->integer()
        );
        fbb_.Finish(response_offset);
        *response = flatbuffers::BufferRef<Response>(
                fbb_.GetBufferPointer(),fbb_.GetSize()
        );
        return grpc::Status::OK;
    }
  private:
    flatbuffers::FlatBufferBuilder fbb_;
};

grpc::Server *server = nullptr;
std::mutex wait_for_server;
std::condition_variable server_cv;

void run() {
    auto server_address = "0.0.0.0:50051";

    ServiceImpl service;
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    wait_for_server.lock();
    server_instance = builder.BuildAndStart().release();
    wait_for_server.unlock();
    server_instance_cv.notify_one();

    std::cout << "Server listening on " << server_address << std::endl;
    server_instance->Wait();
}

int main(int /*argc*/, const char * /*argv*/[]) {
    std::signal(SIGINT, signalHandler);

    std::thread server_thread(run);

    std::unique_lock<std::mutex> lock(wait_for_server);
    while (!server) server_cv.wait(lock);

    while(running){};

    server->Shutdown();
    server_thread.join();
    delete server_instance;
    return 0;
}