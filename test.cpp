#include "sample_generated.h"
#include <cassert>
#include <memory>

#include <iostream>

using namespace sample;

int main(){

    uint8_t *buf_ptr;
    // Encode test
    {
        flatbuffers::FlatBufferBuilder fbb;
        // union types.
        std::unique_ptr<std::vector<uint8_t>> types(new std::vector<uint8_t>());
        types->emplace_back(static_cast<uint8_t>(Object::Object_Object1));
        types->emplace_back(static_cast<uint8_t>(Object::Object_Object2));
        types->emplace_back(static_cast<uint8_t>(Object::Object_Object3));
        types->emplace_back(static_cast<uint8_t>(Object::Object_Object2));

        // union values.
        std::unique_ptr<std::vector<flatbuffers::Offset<void>>> objects(new std::vector<flatbuffers::Offset<void>>());
        objects->emplace_back(CreateObject1Direct(fbb, "naobou" ,  /*boolean=*/true).Union());
        objects->emplace_back(CreateObject2Direct(fbb, "kayanon",  /*integer=*/623).Union());
        objects->emplace_back(CreateObject3Direct(fbb, "inosuke",  /*str=*/"pray").Union());
        objects->emplace_back(CreateObject2Direct(fbb, "nanjolno", /*integer=*/123).Union());

        const auto sample_offset =
            CreateSampleRootDirect(fbb, types.get(), objects.get());
        FinishSampleRootBuffer(fbb, sample_offset);
        buf_ptr = fbb.GetBufferPointer();
        flatbuffers::Verifier verifier(buf_ptr, fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));
    }
    // Decode test
    {
        const SampleRoot *sample = GetSampleRoot(buf_ptr);
        assert(sample->objects_type()->size() == 4);
        assert(sample->objects_type()->GetEnum<Object>(0) == Object::Object_Object1);
        assert(sample->objects_type()->GetEnum<Object>(1) == Object::Object_Object2);
        assert(sample->objects_type()->GetEnum<Object>(2) == Object::Object_Object3);
        assert(sample->objects_type()->GetEnum<Object>(3) == Object::Object_Object2);

        assert(sample->objects()->size() == 4);
        {
            const Object1 *obj =
                reinterpret_cast<const Object1 *>(sample->objects()->Get(0));
            assert(obj->text()->str() == "naobou");
            assert(obj->boolean());
        }
        {
            const Object2 *obj =
                    reinterpret_cast<const Object2 *>(sample->objects()->Get(1));
            assert(obj->text()->str() == "kayanon");
            assert(obj->integer() == 623);
        }
        {
            const Object3 *obj =
                    reinterpret_cast<const Object3 *>(sample->objects()->Get(2));
            assert(obj->text()->str() == "inosuke");
            assert(obj->message()->str() == "pray");
        }
        {
            const Object2 *obj =
                    reinterpret_cast<const Object2 *>(sample->objects()->Get(3));
            assert(obj->text()->str() == "nanjolno");
            assert(obj->integer() == 123);
        }
    }
    {
        flatbuffers::FlatBufferBuilder fbb;
        const SampleRoot *sample = GetSampleRoot(buf_ptr);

        std::unique_ptr<std::vector<uint8_t>> types(new std::vector<uint8_t>());
        std::unique_ptr<std::vector<flatbuffers::Offset<void>>> objects(new std::vector<flatbuffers::Offset<void>>());

        assert(sample->objects_type()->size() == sample->objects()->size());
        for(int i=0;i < sample->objects()->size(); ++i){
            auto v = sample->objects()->Get(i);
            switch (sample->objects_type()->Get(i)){
                case  Object::Object_Object1: {
                    auto obj = reinterpret_cast<const Object1 *>(v);
                    objects->emplace_back(
                            CreateObject1Direct(fbb, obj->text()->str().c_str(), obj->boolean()).Union()); break;
                }
                case  Object::Object_Object2: {
                    auto obj = reinterpret_cast<const Object2 *>(v);
                    objects->emplace_back(
                            CreateObject2Direct(fbb, obj->text()->str().c_str(), obj->integer()).Union()); break;
                }
                case  Object::Object_Object3: {
                    auto obj = reinterpret_cast<const Object3 *>(v);
                    objects->emplace_back(
                            CreateObject3Direct(fbb, obj->text()->str().c_str(), obj->message()->str().c_str()).Union()); break;
                }
            }
        }

        const auto sample_offset =
            CreateSampleRootDirect(fbb,types.get(), objects.get());
        FinishSampleRootBuffer(fbb, sample_offset);
        auto buf = fbb.GetBufferPointer();
        flatbuffers::Verifier verifier(buf, fbb.GetSize());
        assert(VerifySampleRootBuffer(verifier));
    }
    return 0;
}
