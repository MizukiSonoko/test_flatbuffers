#include <csignal>
#include <chrono>
#include <atomic>
#include <thread>
#include <grpc++/grpc++.h>
#include <iostream>
#include "grpc/for_grpc.grpc.fb.h"
#include "grpc/for_grpc_generated.h"

using namespace sample;
static int count;

class ServiceImpl final : public sample::SampleEndpoint::Service {
    virtual ::grpc::Status Port(
            ::grpc::ServerContext* context,
            const flatbuffers::BufferRef<Request> *request,
            flatbuffers::BufferRef<Response> *response
    ) override {
        fbb_.Clear();
        std::unique_ptr<std::vector<uint8_t>> nested_res_vec(
                new std::vector<uint8_t>()
        );
        {
            flatbuffers::FlatBufferBuilder fbb_nested;
            auto nested_res_offset = CreateNestedRes(
                fbb_nested,
                fbb_nested.CreateString("Nested " + request->GetRoot()->text()->str())
            );
            fbb_nested.Finish(nested_res_offset);
            auto buf = fbb_nested.GetBufferPointer();

            nested_res_vec->assign(
                    buf, buf + fbb_nested.GetSize()
            );
        }
        auto msg = "Ok! " + request->GetRoot()->text()->str();
        auto response_offset = CreateResponseDirect(
                fbb_,
                msg.c_str(),
                request->GetRoot()->integer(),
                nested_res_vec.get()
        );
        fbb_.Finish(response_offset);
        *response = flatbuffers::BufferRef<Response>(
                fbb_.GetBufferPointer(),fbb_.GetSize()
        );
        return grpc::Status::OK;
    }

    flatbuffers::BufferRef<Response> make(int i){
        std::unique_ptr<std::vector<uint8_t>> nested_res_vec(
                new std::vector<uint8_t>()
        );
        {
            flatbuffers::FlatBufferBuilder fbb_nested;
            auto nested_res_offset = CreateNestedRes(
                fbb_nested,
                fbb_nested.CreateString("Nested ")
            );
            fbb_nested.Finish(nested_res_offset);
            auto buf = fbb_nested.GetBufferPointer();

            nested_res_vec->assign(
                    buf, buf + fbb_nested.GetSize()
            );
        }
        auto msg = "Ok! " + std::to_string(i);
        auto response_offset = CreateResponseDirect(
                fbb_,
                msg.c_str(),
                i,
                nested_res_vec.get()
        );
        fbb_.Finish(response_offset);
        return flatbuffers::BufferRef<Response>(
                fbb_.GetBufferPointer(),fbb_.GetSize()
        );
    }
    virtual ::grpc::Status Stream(
            ::grpc::ServerContext* context,
            const flatbuffers::BufferRef<Request> *request,
	    ::grpc::ServerWriter< flatbuffers::BufferRef<Response>>* writer
    ) override {
        
        //std::chrono::milliseconds dura( 3000 );
        std::cout <<"Start streming!! " << std::endl;
        for(long long int i = 0; i < 100; i++){
            std::cout <<"Streming! " << i << std::endl;
            //std::this_thread::sleep_for( dura );
            writer->Write(make(i));
            count++;
        }
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
    server = builder.BuildAndStart().release();
    wait_for_server.unlock();
    server_cv.notify_one();

    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int /*argc*/, const char * /*argv*/[]) {
    std::thread server_thread(run);

    std::unique_lock<std::mutex> lock(wait_for_server);
    while (!server) server_cv.wait(lock);

    while(count < 400){};

    server->Shutdown();
    server_thread.join();
    delete server;
    return 0;
}
