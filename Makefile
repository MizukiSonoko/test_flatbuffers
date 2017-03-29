
all: test

#sample_generated.h:
#	flatc --cpp --grpc --gen-object-api sample.fbs

test: #sample_generated.h
	g++ -std=c++14 -Wl,-no-as-needed sample_generated.h test.cpp -o test

.PHONY: clean
clean:
	rm test

