// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ChatServer.proto

#include "ChatServer.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace ik_ChatServer {
PROTOBUF_CONSTEXPR MsgRequest::MsgRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.msg_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.id_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MsgRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MsgRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MsgRequestDefaultTypeInternal() {}
  union {
    MsgRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MsgRequestDefaultTypeInternal _MsgRequest_default_instance_;
}  // namespace ik_ChatServer
static ::_pb::Metadata file_level_metadata_ChatServer_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_ChatServer_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_ChatServer_2eproto = nullptr;

const uint32_t TableStruct_ChatServer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ik_ChatServer::MsgRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ik_ChatServer::MsgRequest, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::ik_ChatServer::MsgRequest, _impl_.msg_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ik_ChatServer::MsgRequest)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::ik_ChatServer::_MsgRequest_default_instance_._instance,
};

const char descriptor_table_protodef_ChatServer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\020ChatServer.proto\022\rik_ChatServer\"%\n\nMsg"
  "Request\022\n\n\002id\030\001 \001(\005\022\013\n\003msg\030\002 \001(\014b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_ChatServer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ChatServer_2eproto = {
    false, false, 80, descriptor_table_protodef_ChatServer_2eproto,
    "ChatServer.proto",
    &descriptor_table_ChatServer_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_ChatServer_2eproto::offsets,
    file_level_metadata_ChatServer_2eproto, file_level_enum_descriptors_ChatServer_2eproto,
    file_level_service_descriptors_ChatServer_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ChatServer_2eproto_getter() {
  return &descriptor_table_ChatServer_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ChatServer_2eproto(&descriptor_table_ChatServer_2eproto);
namespace ik_ChatServer {

// ===================================================================

class MsgRequest::_Internal {
 public:
};

MsgRequest::MsgRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ik_ChatServer.MsgRequest)
}
MsgRequest::MsgRequest(const MsgRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MsgRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.msg_){}
    , decltype(_impl_.id_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_msg().empty()) {
    _this->_impl_.msg_.Set(from._internal_msg(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.id_ = from._impl_.id_;
  // @@protoc_insertion_point(copy_constructor:ik_ChatServer.MsgRequest)
}

inline void MsgRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.msg_){}
    , decltype(_impl_.id_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

MsgRequest::~MsgRequest() {
  // @@protoc_insertion_point(destructor:ik_ChatServer.MsgRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MsgRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.msg_.Destroy();
}

void MsgRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MsgRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ik_ChatServer.MsgRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.msg_.ClearToEmpty();
  _impl_.id_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MsgRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes msg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_msg();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MsgRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ik_ChatServer.MsgRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // bytes msg = 2;
  if (!this->_internal_msg().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ik_ChatServer.MsgRequest)
  return target;
}

size_t MsgRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ik_ChatServer.MsgRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes msg = 2;
  if (!this->_internal_msg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  // int32 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MsgRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MsgRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MsgRequest::GetClassData() const { return &_class_data_; }


void MsgRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MsgRequest*>(&to_msg);
  auto& from = static_cast<const MsgRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ik_ChatServer.MsgRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_msg().empty()) {
    _this->_internal_set_msg(from._internal_msg());
  }
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MsgRequest::CopyFrom(const MsgRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ik_ChatServer.MsgRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MsgRequest::IsInitialized() const {
  return true;
}

void MsgRequest::InternalSwap(MsgRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.msg_, lhs_arena,
      &other->_impl_.msg_, rhs_arena
  );
  swap(_impl_.id_, other->_impl_.id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MsgRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ChatServer_2eproto_getter, &descriptor_table_ChatServer_2eproto_once,
      file_level_metadata_ChatServer_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace ik_ChatServer
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ik_ChatServer::MsgRequest*
Arena::CreateMaybeMessage< ::ik_ChatServer::MsgRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ik_ChatServer::MsgRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
