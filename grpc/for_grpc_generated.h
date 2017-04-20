// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_FORGRPC_SAMPLE_H_
#define FLATBUFFERS_GENERATED_FORGRPC_SAMPLE_H_

#include "flatbuffers/flatbuffers.h"

namespace sample {

struct Request;

struct Response;

struct Request FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TEXT = 4,
    VT_INTEGER = 6
  };
  const flatbuffers::String *text() const {
    return GetPointer<const flatbuffers::String *>(VT_TEXT);
  }
  int32_t integer() const {
    return GetField<int32_t>(VT_INTEGER, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_TEXT) &&
           verifier.Verify(text()) &&
           VerifyField<int32_t>(verifier, VT_INTEGER) &&
           verifier.EndTable();
  }
};

struct RequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_text(flatbuffers::Offset<flatbuffers::String> text) {
    fbb_.AddOffset(Request::VT_TEXT, text);
  }
  void add_integer(int32_t integer) {
    fbb_.AddElement<int32_t>(Request::VT_INTEGER, integer, 0);
  }
  RequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RequestBuilder &operator=(const RequestBuilder &);
  flatbuffers::Offset<Request> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Request>(end);
    fbb_.Required(o, Request::VT_TEXT);
    return o;
  }
};

inline flatbuffers::Offset<Request> CreateRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> text = 0,
    int32_t integer = 0) {
  RequestBuilder builder_(_fbb);
  builder_.add_integer(integer);
  builder_.add_text(text);
  return builder_.Finish();
}

inline flatbuffers::Offset<Request> CreateRequestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *text = nullptr,
    int32_t integer = 0) {
  return sample::CreateRequest(
      _fbb,
      text ? _fbb.CreateString(text) : 0,
      integer);
}

struct Response FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE = 4,
    VT_CORE = 6
  };
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  int32_t core() const {
    return GetField<int32_t>(VT_CORE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           VerifyField<int32_t>(verifier, VT_CORE) &&
           verifier.EndTable();
  }
};

struct ResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(Response::VT_MESSAGE, message);
  }
  void add_core(int32_t core) {
    fbb_.AddElement<int32_t>(Response::VT_CORE, core, 0);
  }
  ResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ResponseBuilder &operator=(const ResponseBuilder &);
  flatbuffers::Offset<Response> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Response>(end);
    fbb_.Required(o, Response::VT_MESSAGE);
    return o;
  }
};

inline flatbuffers::Offset<Response> CreateResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> message = 0,
    int32_t core = 0) {
  ResponseBuilder builder_(_fbb);
  builder_.add_core(core);
  builder_.add_message(message);
  return builder_.Finish();
}

inline flatbuffers::Offset<Response> CreateResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *message = nullptr,
    int32_t core = 0) {
  return sample::CreateResponse(
      _fbb,
      message ? _fbb.CreateString(message) : 0,
      core);
}

inline const sample::Request *GetRequest(const void *buf) {
  return flatbuffers::GetRoot<sample::Request>(buf);
}

inline bool VerifyRequestBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sample::Request>(nullptr);
}

inline void FinishRequestBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<sample::Request> root) {
  fbb.Finish(root);
}

}  // namespace sample

#endif  // FLATBUFFERS_GENERATED_FORGRPC_SAMPLE_H_
