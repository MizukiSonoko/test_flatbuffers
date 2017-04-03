// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SAMPLE2_SAMPLE_H_
#define FLATBUFFERS_GENERATED_SAMPLE2_SAMPLE_H_

#include "flatbuffers/flatbuffers.h"

#include "objects_generated.h"

namespace sample {

struct IndependentObject;

struct IndependentObject FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OBJECTS_TYPE = 4,
    VT_OBJECTS = 6
  };
  const flatbuffers::Vector<uint8_t> *objects_type() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_OBJECTS_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<void>> *objects() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_OBJECTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBJECTS_TYPE) &&
           verifier.Verify(objects_type()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OBJECTS) &&
           verifier.Verify(objects()) &&
           VerifyObjectVector(verifier, objects(), objects_type()) &&
           verifier.EndTable();
  }
};

struct IndependentObjectBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_objects_type(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> objects_type) {
    fbb_.AddOffset(IndependentObject::VT_OBJECTS_TYPE, objects_type);
  }
  void add_objects(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> objects) {
    fbb_.AddOffset(IndependentObject::VT_OBJECTS, objects);
  }
  IndependentObjectBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  IndependentObjectBuilder &operator=(const IndependentObjectBuilder &);
  flatbuffers::Offset<IndependentObject> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<IndependentObject>(end);
    return o;
  }
};

inline flatbuffers::Offset<IndependentObject> CreateIndependentObject(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> objects_type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> objects = 0) {
  IndependentObjectBuilder builder_(_fbb);
  builder_.add_objects(objects);
  builder_.add_objects_type(objects_type);
  return builder_.Finish();
}

inline flatbuffers::Offset<IndependentObject> CreateIndependentObjectDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *objects_type = nullptr,
    const std::vector<flatbuffers::Offset<void>> *objects = nullptr) {
  return sample::CreateIndependentObject(
      _fbb,
      objects_type ? _fbb.CreateVector<uint8_t>(*objects_type) : 0,
      objects ? _fbb.CreateVector<flatbuffers::Offset<void>>(*objects) : 0);
}

inline const sample::IndependentObject *GetIndependentObject(const void *buf) {
  return flatbuffers::GetRoot<sample::IndependentObject>(buf);
}

inline bool VerifyIndependentObjectBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<sample::IndependentObject>(nullptr);
}

inline void FinishIndependentObjectBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<sample::IndependentObject> root) {
  fbb.Finish(root);
}

}  // namespace sample

#endif  // FLATBUFFERS_GENERATED_SAMPLE2_SAMPLE_H_
