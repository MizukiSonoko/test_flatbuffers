
all: flatbuf_test

sample_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	flatc --cpp --grpc objects.fbs sample.fbs

sample2_generated.h:
	flatc --version
	sed -i -e "s/^flatc version.*/`flatc --version`/" README.md
	flatc --cpp --grpc objects.fbs sample2.fbs


flatbuf_test: sample_generated.h sample2_generated.h
	g++ -std=c++0x -Wl,-no-as-needed $(INCS) test.cpp -o $@

.PHONY: run
run: flatbuf_test
	./flatbuf_test

.PHONY: clean
clean:
	- rm flatbuf_test
	- rm sample_generated.h sample2_generated.h
