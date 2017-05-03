
all: flatbuf_test grpc_server grpc_client

sample_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	flatc --cpp --grpc objects.fbs sample.fbs

sample2_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	flatc --cpp --grpc objects.fbs sample2.fbs


grpc/for_grpc_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	cd grpc; flatc --cpp --grpc for_grpc.fbs

flatbuf_test: sample_generated.h sample2_generated.h
	g++ -std=c++0x -Wl,-no-as-needed $(INCS) test.cpp -o $@

grpc_client: grpc/for_grpc_generated.h
	g++ -std=c++0x -g3 -O0 -Wl,-no-as-needed -lgrpc -lgrpc++ -lgpr -pthread $(INCS) grpc/for_grpc.grpc.fb.cc grpc_client.cpp -o $@

grpc_server: grpc/for_grpc_generated.h
	g++ -std=c++0x -g3 -O0 -Wl,-no-as-needed -lgrpc -lgrpc++ -lgpr -pthread $(INCS) grpc/for_grpc.grpc.fb.cc grpc_test.cpp -o $@

.PHONY: run
run: flatbuf_test
	./flatbuf_test

.PHONY: clean
clean:
	- rm flatbuf_test
	- rm sample_generated.h sample2_generated.h grpc/for_grpc_generated.h
