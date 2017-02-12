
# GRPC + Flatbuffers test

I write grpc + flatbuffers software.

# State 

## Environment

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
root@6f25b0087098:~# make
flatc --cpp --grpc --gen-object-api sample.fbs
g++ -std=c++14 sample.grpc.fb.cc grpctest.cpp  -lgrpc++ -lgrpc++_reflection -lgpr -pthread -o grpctest
root@6f25b0087098:~# ./grpctest
Server listening on 0.0.0.0:50051
grpctest: grpctest.cpp:41: virtual grpc::Status ServiceImpl::Endpoint(grpc::ServerContext*, const flatbuffers::BufferRef<sample::SampleRoot>*, flatbuffers::BufferRef<sample::Response>*): Assertion `sampleRootT.wrapper.AsWrapper1()->object.AsObject1()->text != "object1_text"' failed.
Aborted
root@6f25b0087098:~# ./grpctest
Server listening on 0.0.0.0:50051
RPC failed
*** Error in `./grpctest': munmap_chunk(): invalid pointer: 0x00000000016406d0 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f68b60b87e5]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x1a8)[0x7f68b60c4ae8]
./grpctest[0x40f19a]
./grpctest[0x40f21a]
./grpctest[0x40d4ba]
./grpctest[0x40f444]
./grpctest[0x40bd54]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f68b6061830]
./grpctest[0x403e39]
======= Memory map: ========
00400000-00423000 r-xp 00000000 00:36 12918                              /tmp/sandbox/grpctest
00622000-00623000 r--p 00022000 00:36 12918                              /tmp/sandbox/grpctest
00623000-00624000 rw-p 00023000 00:36 12918                              /tmp/sandbox/grpctest
0162e000-01660000 rw-p 00000000 00:00 0                                  [heap]
7f68a0000000-7f68a0021000 rw-p 00000000 00:00 0
7f68a0021000-7f68a4000000 ---p 00000000 00:00 0
7f68a8000000-7f68a8021000 rw-p 00000000 00:00 0
7f68a8021000-7f68ac000000 ---p 00000000 00:00 0
7f68ae7fd000-7f68ae7fe000 ---p 00000000 00:00 0
7f68ae7fe000-7f68aeffe000 rw-p 00000000 00:00 0
7f68aeffe000-7f68aefff000 ---p 00000000 00:00 0
7f68aefff000-7f68af7ff000 rw-p 00000000 00:00 0
7f68af7ff000-7f68af800000 ---p 00000000 00:00 0
7f68af800000-7f68b0000000 rw-p 00000000 00:00 0
7f68b0000000-7f68b0021000 rw-p 00000000 00:00 0
7f68b0021000-7f68b4000000 ---p 00000000 00:00 0
7f68b4022000-7f68b402d000 r-xp 00000000 00:36 54                         /lib/x86_64-linux-gnu/libnss_files-2.23.so
7f68b402d000-7f68b422c000 ---p 0000b000 00:36 54                         /lib/x86_64-linux-gnu/libnss_files-2.23.so
7f68b422c000-7f68b422d000 r--p 0000a000 00:36 54                         /lib/x86_64-linux-gnu/libnss_files-2.23.so
7f68b422d000-7f68b422e000 rw-p 0000b000 00:36 54                         /lib/x86_64-linux-gnu/libnss_files-2.23.so
7f68b422e000-7f68b4234000 rw-p 00000000 00:00 0
7f68b45b5000-7f68b45b6000 ---p 00000000 00:00 0
7f68b45b6000-7f68b4db6000 rw-p 00000000 00:00 0
7f68b4db6000-7f68b4db9000 r-xp 00000000 00:36 40                         /lib/x86_64-linux-gnu/libdl-2.23.so
7f68b4db9000-7f68b4fb8000 ---p 00003000 00:36 40                         /lib/x86_64-linux-gnu/libdl-2.23.so
7f68b4fb8000-7f68b4fb9000 r--p 00002000 00:36 40                         /lib/x86_64-linux-gnu/libdl-2.23.so
7f68b4fb9000-7f68b4fba000 rw-p 00003000 00:36 40                         /lib/x86_64-linux-gnu/libdl-2.23.so
7f68b4fba000-7f68b51d4000 r-xp 00000000 00:36 562                        /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
7f68b51d4000-7f68b53d3000 ---p 0021a000 00:36 562                        /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
7f68b53d3000-7f68b53ef000 r--p 00219000 00:36 562                        /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
7f68b53ef000-7f68b53fb000 rw-p 00235000 00:36 562                        /lib/x86_64-linux-gnu/libcrypto.so.1.0.0
7f68b53fb000-7f68b53fe000 rw-p 00000000 00:00 0
7f68b53fe000-7f68b545c000 r-xp 00000000 00:36 561                        /lib/x86_64-linux-gnu/libssl.so.1.0.0
7f68b545c000-7f68b565c000 ---p 0005e000 00:36 561                        /lib/x86_64-linux-gnu/libssl.so.1.0.0
7f68b565c000-7f68b5660000 r--p 0005e000 00:36 561                        /lib/x86_64-linux-gnu/libssl.so.1.0.0
7f68b5660000-7f68b5667000 rw-p 00062000 00:36 561                        /lib/x86_64-linux-gnu/libssl.so.1.0.0
7f68b5667000-7f68b576f000 r-xp 00000000 00:36 90                         /lib/x86_64-linux-gnu/libm-2.23.so
7f68b576f000-7f68b596e000 ---p 00108000 00:36 90                         /lib/x86_64-linux-gnu/libm-2.23.so
7f68b596e000-7f68b596f000 r--p 00107000 00:36 90                         /lib/x86_64-linux-gnu/libm-2.23.so
7f68b596f000-7f68b5970000 rw-p 00108000 00:36 90                         /lib/x86_64-linux-gnu/libm-2.23.so
7f68b5970000-7f68b5977000 r-xp 00000000 00:36 84                         /lib/x86_64-linux-gnu/librt-2.23.so
7f68b5977000-7f68b5b76000 ---p 00007000 00:36 84                         /lib/x86_64-linux-gnu/librt-2.23.so
7f68b5b76000-7f68b5b77000 r--p 00006000 00:36 84                         /lib/x86_64-linux-gnu/librt-2.23.so
7f68b5b77000-7f68b5b78000 rw-p 00007000 00:36 84                         /lib/x86_64-linux-gnu/librt-2.23.so
7f68b5b78000-7f68b5c1c000 r-xp 00000000 00:36 5986                       /usr/local/lib/libgrpc.so.1.0.0
7f68b5c1c000-7f68b5e1b000 ---p 000a4000 00:36 5986                       /usr/local/lib/libgrpc.so.1.0.0
7f68b5e1b000-7f68b5e1e000 r--p 000a3000 00:36 5986                       /usr/local/lib/libgrpc.so.1.0.0
7f68b5e1e000-7f68b5e21000 rw-p 000a6000 00:36 5986                       /usr/local/lib/libgrpc.so.1.0.0
7f68b5e21000-7f68b5e27000 rw-p 00000000 00:00 0
7f68b5e27000-7f68b5e40000 r-xp 00000000 00:36 78                         /lib/x86_64-linux-gnu/libz.so.1.2.8
7f68b5e40000-7f68b603f000 ---p 00019000 00:36 78                         /lib/x86_64-linux-gnu/libz.so.1.2.8
7f68b603f000-7f68b6040000 r--p 00018000 00:36 78                         /lib/x86_64-linux-gnu/libz.so.1.2.8
7f68b6040000-7f68b6041000 rw-p 00019000 00:36 78                         /lib/x86_64-linux-gnu/libz.so.1.2.8
7f68b6041000-7f68b6200000 r-xp 00000000 00:36 42                         /lib/x86_64-linux-gnu/libc-2.23.so
7f68b6200000-7f68b6400000 ---p 001bf000 00:36 42                         /lib/x86_64-linux-gnu/libc-2.23.so
7f68b6400000-7f68b6404000 r--p 001bf000 00:36 42                         /lib/x86_64-linux-gnu/libc-2.23.so
7f68b6404000-7f68b6406000 rw-p 001c3000 00:36 42                         /lib/x86_64-linux-gnu/libc-2.23.so
7f68b6406000-7f68b640a000 rw-p 00000000 00:00 0
7f68b640a000-7f68b6422000 r-xp 00000000 00:36 82                         /lib/x86_64-linux-gnu/libpthread-2.23.so
7f68b6422000-7f68b6621000 ---p 00018000 00:36 82                         /lib/x86_64-linux-gnu/libpthread-2.23.so
7f68b6621000-7f68b6622000 r--p 00017000 00:36 82                         /lib/x86_64-linux-gnu/libpthread-2.23.so
7f68b6622000-7f68b6623000 rw-p 00018000 00:36 82                         /lib/x86_64-linux-gnu/libpthread-2.23.so
7f68b6623000-7f68b6627000 rw-p 00000000 00:00 0
7f68b6627000-7f68b663d000 r-xp 00000000 00:36 547                        /lib/x86_64-linux-gnu/libgcc_s.so.1
7f68b663d000-7f68b683c000 ---p 00016000 00:36 547                        /lib/x86_64-linux-gnu/libgcc_s.so.1
7f68b683c000-7f68b683d000 rw-p 00015000 00:36 547                        /lib/x86_64-linux-gnu/libgcc_s.so.1
7f68b683d000-7f68b69af000 r-xp 00000000 00:36 546                        /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7f68b69af000-7f68b6baf000 ---p 00172000 00:36 546                        /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7f68b6baf000-7f68b6bb9000 r--p 00172000 00:36 546                        /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7f68b6bb9000-7f68b6bbb000 rw-p 0017c000 00:36 546                        /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7f68b6bbb000-7f68b6bbf000 rw-p 00000000 00:00 0
7f68b6bbf000-7f68b6bcd000 r-xp 00000000 00:36 2287                       /usr/local/lib/libgpr.so.1.0.0
7f68b6bcd000-7f68b6dcc000 ---p 0000e000 00:36 2287                       /usr/local/lib/libgpr.so.1.0.0
7f68b6dcc000-7f68b6dcd000 r--p 0000d000 00:36 2287                       /usr/local/lib/libgpr.so.1.0.0
7f68b6dcd000-7f68b6dce000 rw-p 0000e000 00:36 2287                       /usr/local/lib/libgpr.so.1.0.0
7f68b6dce000-7f68b6e49000 r-xp 00000000 00:36 2289                       /usr/local/lib/libgrpc++.so.1.0.0
7f68b6e49000-7f68b7049000 ---p 0007b000 00:36 2289                       /usr/local/lib/libgrpc++.so.1.0.0
7f68b7049000-7f68b704c000 r--p 0007b000 00:36 2289                       /usr/local/lib/libgrpc++.so.1.0.0
7f68b704c000-7f68b704e000 rw-p 0007e000 00:36 2289                       /usr/local/lib/libgrpc++.so.1.0.0
7f68b704e000-7f68b7053000 rw-p 00000000 00:00 0
7f68b7053000-7f68b7079000 r-xp 00000000 00:36 35                         /lib/x86_64-linux-gnu/ld-2.23.so
7f68b7265000-7f68b726e000 rw-p 00000000 00:00 0
7f68b7275000-7f68b7278000 rw-p 00000000 00:00 0
7f68b7278000-7f68b7279000 r--p 00025000 00:36 35                         /lib/x86_64-linux-gnu/ld-2.23.so
7f68b7279000-7f68b727a000 rw-p 00026000 00:36 35                         /lib/x86_64-linux-gnu/ld-2.23.so
7f68b727a000-7f68b727b000 rw-p 00000000 00:00 0
7ffc1fc00000-7ffc1fc21000 rw-p 00000000 00:00 0                          [stack]
7ffc1fd7b000-7ffc1fd7d000 r--p 00000000 00:00 0                          [vvar]
7ffc1fd7d000-7ffc1fd7f000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
Aborted
root@6f25b0087098:~# ./grpctest
Server listening on 0.0.0.0:50051
RPC failed
Segmentation fault
```


