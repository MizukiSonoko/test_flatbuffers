
all: flatbuf_test

sample_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	flatc --cpp --grpc sample.fbs

flatbuf_test: sample_generated.h
	g++ -std=c++14 -Wl,-no-as-needed $(INCS) test.cpp -o $@

.PHONY: clean
clean:
	- rm flatbuf_test
	- rm sample_generated.h

