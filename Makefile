
all: grpctest

sample.grpc.cc:
	flatc --cpp --grpc --gen-object-api sample.fbs

grpctest: sample.grpc.cc
	g++ -std=c++14 -Wl,-no-as-needed sample.grpc.fb.cc grpctest.cpp -lgrpc -lgrpc++ -lgpr -pthread -o grpctest

.PHONY: clean
clean:
	rm grpctest

