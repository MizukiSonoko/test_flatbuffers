
# GRPC + Flatbuffers test
[![Build Status](https://travis-ci.org/MizukiSonoko/test_flatbuffers.svg?branch=master)](https://travis-ci.org/MizukiSonoko/test_flatbuffers)

I write grpc + flatbuffers software.

# pre
```sh
$ cd /tmp
$ git clone https://github.com/google/flatbuffers.git 
$ cd flatbuffers
$ cmake -G "Unix Makefiles" && make && make install
```

# Usage

```sh
$ cd test_flatbuffers
$ make
$ ./flatbuf_test
```


## Environment

### Flatc 
```sh
flatc version 1.6.0 (Apr  3 2017)
```

### OS
```sh
root@6f25b0087098:~# cat /etc/lsb-release
DISTRIB_ID=Ubuntu
DISTRIB_RELEASE=16.04
DISTRIB_CODENAME=xenial
DISTRIB_DESCRIPTION="Ubuntu 16.04.1 LTS"
```

### Kernel
```sh
root@6f25b0087098:~# uname -a
Linux 6f25b0087098 4.4.39-moby #1 SMP Fri Dec 16 07:34:12 UTC 2016 x86_64 x86_64 x86_64 GNU/Linux
```

### Compiler
```sh
g++ -v -dumpversion
5.4.0
```


## Bug

```sh
root@2e42d5766aa3:/opt/test_flatbuffers# ./flatbuf_test
flatbuf_test: test.cpp:105: int main(): Assertion `VerifySampleRootBuffer(verifier)' failed.
Aborted
```

## Valgrind 

```sh
==886== Memcheck, a memory error detector
==886== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==886== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==886== Command: ./flatbuf_test
==886== 
==886== Invalid read of size 4
==886==    at 0x406FD1: sample::SampleRoot* flatbuffers::GetMutableRoot<sample::SampleRoot>(void*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057FC: sample::SampleRoot const* flatbuffers::GetRoot<sample::SampleRoot>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404349: sample::GetSampleRoot(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401439: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fd4 is 852 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033A6: flatbuffers::Table::GetVTable() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033D3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406CFB: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40542F: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E6C: sample::SampleRoot::objects_type() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40144F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fd8 is 856 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033E3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406CFB: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40542F: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E6C: sample::SampleRoot::objects_type() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40144F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6040 is 960 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403404: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406CFB: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40542F: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E6C: sample::SampleRoot::objects_type() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40144F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6044 is 964 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406D21: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40542F: flatbuffers::Vector<unsigned char> const* flatbuffers::Table::GetPointer<flatbuffers::Vector<unsigned char> const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E6C: sample::SampleRoot::objects_type() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40144F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fdc is 860 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401457: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406072: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401491: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x407769: flatbuffers::IndirectHelper<unsigned char>::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4060AC: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401491: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe8 is 872 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406072: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4014CB: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x407769: flatbuffers::IndirectHelper<unsigned char>::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4060AC: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4014CB: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe9 is 873 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406072: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401505: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x407769: flatbuffers::IndirectHelper<unsigned char>::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4060AC: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401505: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fea is 874 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406072: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40153F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x407769: flatbuffers::IndirectHelper<unsigned char>::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4060AC: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057DF: sample::Object flatbuffers::Vector<unsigned char>::GetEnum<sample::Object>(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40153F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5feb is 875 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033A6: flatbuffers::Table::GetVTable() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033D3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406D57: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405455: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E8C: sample::SampleRoot::objects() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40156C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fd8 is 856 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033E3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406D57: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405455: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E8C: sample::SampleRoot::objects() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40156C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6040 is 960 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403404: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406D57: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405455: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E8C: sample::SampleRoot::objects() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40156C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6046 is 966 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406D7D: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405455: flatbuffers::Vector<flatbuffers::Offset<void> > const* flatbuffers::Table::GetPointer<flatbuffers::Vector<flatbuffers::Offset<void> > const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403E8C: sample::SampleRoot::objects() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40156C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe0 is 864 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401574: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405782: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015AE: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406F9D: flatbuffers::IndirectHelper<flatbuffers::Offset<void> >::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057BC: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015AE: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5ff0 is 880 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033A6: flatbuffers::Table::GetVTable() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033D3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406BF7: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4034E6: sample::Object1::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015C4: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6068 is 1,000 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033E3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406BF7: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4034E6: sample::Object1::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015C4: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6060 is 992 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403404: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406BF7: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4034E6: sample::Object1::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015C4: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6064 is 996 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406C1D: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4034E6: sample::Object1::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015C4: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6070 is 1,008 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015D6: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6074 is 1,012 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x4C32720: memcpy@@GLIBC_2.14 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4F5BB06: void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char const*>(char const*, char const*, std::forward_iterator_tag) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x4F5BC04: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, unsigned long, std::allocator<char> const&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x401FD4: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015D6: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6078 is 1,016 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x4C3272E: memcpy@@GLIBC_2.14 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4F5BB06: void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char const*>(char const*, char const*, std::forward_iterator_tag) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x4F5BC04: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, unsigned long, std::allocator<char> const&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x401FD4: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4015D6: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab607c is 1,020 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033A6: flatbuffers::Table::GetVTable() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033D3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E96: unsigned char flatbuffers::Table::GetField<unsigned char>(unsigned short, unsigned char) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40350B: sample::Object1::boolean() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40161F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6068 is 1,000 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033E3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E96: unsigned char flatbuffers::Table::GetField<unsigned char>(unsigned short, unsigned char) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40350B: sample::Object1::boolean() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40161F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6060 is 992 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403404: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E96: unsigned char flatbuffers::Table::GetField<unsigned char>(unsigned short, unsigned char) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40350B: sample::Object1::boolean() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40161F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6066 is 998 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x406C40: unsigned char flatbuffers::ReadScalar<unsigned char>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404EB4: unsigned char flatbuffers::Table::GetField<unsigned char>(unsigned short, unsigned char) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40350B: sample::Object1::boolean() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40161F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab606f is 1,007 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405782: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401658: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406F9D: flatbuffers::IndirectHelper<flatbuffers::Offset<void> >::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057BC: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401658: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5ff4 is 884 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406C1D: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4037FE: sample::Object2::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40166E: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab604c is 972 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401680: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6054 is 980 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x4C32758: memcpy@@GLIBC_2.14 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4F5BB06: void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char const*>(char const*, char const*, std::forward_iterator_tag) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x4F5BC04: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, unsigned long, std::allocator<char> const&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x401FD4: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401680: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab605e is 990 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033A6: flatbuffers::Table::GetVTable() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033D3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405130: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4016C9: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6048 is 968 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4033E3: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405130: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4016C9: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6040 is 960 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 2
==886==    at 0x404A3F: unsigned short flatbuffers::ReadScalar<unsigned short>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403404: flatbuffers::Table::GetOptionalFieldOffset(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405130: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4016C9: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6046 is 966 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40514E: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4016C9: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6050 is 976 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405782: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401705: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406F9D: flatbuffers::IndirectHelper<flatbuffers::Offset<void> >::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057BC: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401705: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5ff8 is 888 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406C1D: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403AFE: sample::Object3::text() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40171B: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6020 is 928 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40172D: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6028 is 936 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406C1D: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404E6B: flatbuffers::String const* flatbuffers::Table::GetPointer<flatbuffers::String const*>(unsigned short) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403B1E: sample::Object3::message() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401776: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6024 is 932 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401788: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6034 is 948 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405782: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4017DE: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406F9D: flatbuffers::IndirectHelper<flatbuffers::Offset<void> >::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057BC: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4017DE: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5ffc is 892 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401806: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab600c is 908 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 8
==886==    at 0x4C326C8: memcpy@@GLIBC_2.14 (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4F5BB06: void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char const*>(char const*, char const*, std::forward_iterator_tag) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x4F5BC04: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, unsigned long, std::allocator<char> const&) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==886==    by 0x401FD4: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401806: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6010 is 912 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40514E: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40184F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6008 is 904 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x406FD1: sample::SampleRoot* flatbuffers::GetMutableRoot<sample::SampleRoot>(void*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057FC: sample::SampleRoot const* flatbuffers::GetRoot<sample::SampleRoot>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404349: sample::GetSampleRoot(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401895: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fd4 is 852 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401901: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40191A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401958: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x405740: flatbuffers::Vector<flatbuffers::Offset<void> >::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x405782: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40198C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fec is 876 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DCE: unsigned int flatbuffers::ReadScalar<unsigned int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406F9D: flatbuffers::IndirectHelper<flatbuffers::Offset<void> >::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4057BC: flatbuffers::Vector<flatbuffers::Offset<void> >::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40198C: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5ff0 is 880 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x40575C: flatbuffers::Vector<unsigned char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x406072: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4019B2: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe4 is 868 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x407769: flatbuffers::IndirectHelper<unsigned char>::Read(unsigned char const*, unsigned int) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4060AC: flatbuffers::Vector<unsigned char>::Get(unsigned int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4019B2: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab5fe8 is 872 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 1
==886==    at 0x406C40: unsigned char flatbuffers::ReadScalar<unsigned char>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x404EB4: unsigned char flatbuffers::Table::GetField<unsigned char>(unsigned short, unsigned char) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40350B: sample::Object1::boolean() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4019ED: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab606f is 1,007 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401A14: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6074 is 1,012 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404DE9: int flatbuffers::ReadScalar<int>(void const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40514E: int flatbuffers::Table::GetField<int>(unsigned short, int) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x403823: sample::Object2::integer() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401AAA: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6050 is 976 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401ACD: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6054 is 980 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401B6F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6034 is 948 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== Invalid read of size 4
==886==    at 0x404D88: flatbuffers::Vector<char>::size() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40444F: flatbuffers::Vector<char>::Length() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401FAD: flatbuffers::String::str[abi:cxx11]() const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x401B9F: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Address 0x5ab6028 is 936 bytes inside a block of size 1,024 free'd
==886==    at 0x4C2F74B: operator delete[](void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x4020BC: flatbuffers::simple_allocator::deallocate(unsigned char*) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402188: flatbuffers::vector_downward::~vector_downward() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40279B: flatbuffers::FlatBufferBuilder::~FlatBufferBuilder() (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x40142A: main (in /opt/test_flatbuffers/flatbuf_test)
==886==  Block was alloc'd at
==886==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==886==    by 0x402097: flatbuffers::simple_allocator::allocate(unsigned long) const (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402111: flatbuffers::vector_downward::vector_downward(unsigned long, flatbuffers::simple_allocator const&) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x402634: flatbuffers::FlatBufferBuilder::FlatBufferBuilder(unsigned int, flatbuffers::simple_allocator const*) (in /opt/test_flatbuffers/flatbuf_test)
==886==    by 0x4010D9: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
flatbuf_test: test.cpp:105: int main(): Assertion `VerifySampleRootBuffer(verifier)' failed.
==886== 
==886== Process terminating with default action of signal 6 (SIGABRT)
==886==    at 0x5710428: raise (raise.c:54)
==886==    by 0x5712029: abort (abort.c:89)
==886==    by 0x5708BD6: __assert_fail_base (assert.c:92)
==886==    by 0x5708C81: __assert_fail (assert.c:101)
==886==    by 0x401CF1: main (in /opt/test_flatbuffers/flatbuf_test)
==886== 
==886== HEAP SUMMARY:
==886==     in use at exit: 73,984 bytes in 7 blocks
==886==   total heap usage: 22 allocs, 15 frees, 75,489 bytes allocated
==886== 
==886== LEAK SUMMARY:
==886==    definitely lost: 0 bytes in 0 blocks
==886==    indirectly lost: 0 bytes in 0 blocks
==886==      possibly lost: 0 bytes in 0 blocks
==886==    still reachable: 73,984 bytes in 7 blocks
==886==         suppressed: 0 bytes in 0 blocks
==886== Rerun with --leak-check=full to see details of leaked memory
==886== 
==886== For counts of detected and suppressed errors, rerun with: -v
==886== ERROR SUMMARY: 245 errors from 66 contexts (suppressed: 0 from 0)
```
