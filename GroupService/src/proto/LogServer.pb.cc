// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LogServer.proto

#include "LogServer.pb.h"

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

namespace ik {
PROTOBUF_CONSTEXPR LogRequest::LogRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.msg_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct LogRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LogRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LogRequestDefaultTypeInternal() {}
  union {
    LogRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LogRequestDefaultTypeInternal _LogRequest_default_instance_;
PROTOBUF_CONSTEXPR ErrorMsg::ErrorMsg(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.error_msg_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.state_)*/false
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ErrorMsgDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ErrorMsgDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ErrorMsgDefaultTypeInternal() {}
  union {
    ErrorMsg _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ErrorMsgDefaultTypeInternal _ErrorMsg_default_instance_;
PROTOBUF_CONSTEXPR LogResponse::LogResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.msg_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct LogResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LogResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LogResponseDefaultTypeInternal() {}
  union {
    LogResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LogResponseDefaultTypeInternal _LogResponse_default_instance_;
}  // namespace ik
static ::_pb::Metadata file_level_metadata_LogServer_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_LogServer_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_LogServer_2eproto[1];

const uint32_t TableStruct_LogServer_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ik::LogRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ik::LogRequest, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::ik::LogRequest, _impl_.msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ik::ErrorMsg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ik::ErrorMsg, _impl_.state_),
  PROTOBUF_FIELD_OFFSET(::ik::ErrorMsg, _impl_.error_msg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ik::LogResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ik::LogResponse, _impl_.msg_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::ik::LogRequest)},
  { 8, -1, -1, sizeof(::ik::ErrorMsg)},
  { 16, -1, -1, sizeof(::ik::LogResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::ik::_LogRequest_default_instance_._instance,
  &::ik::_ErrorMsg_default_instance_._instance,
  &::ik::_LogResponse_default_instance_._instance,
};

const char descriptor_table_protodef_LogServer_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017LogServer.proto\022\002ik\032\033google/protobuf/e"
  "mpty.proto\"\'\n\nLogRequest\022\014\n\004name\030\001 \001(\014\022\013"
  "\n\003msg\030\002 \001(\014\",\n\010ErrorMsg\022\r\n\005state\030\001 \001(\010\022\021"
  "\n\terror_msg\030\002 \001(\014\"(\n\013LogResponse\022\031\n\003msg\030"
  "\001 \001(\0132\014.ik.ErrorMsg2\254\001\n\014LogServerRpc\0222\n\010"
  "Log_INFO\022\016.ik.LogRequest\032\026.google.protob"
  "uf.Empty\0223\n\tLog_ERROR\022\016.ik.LogRequest\032\026."
  "google.protobuf.Empty\0223\n\tLog_FATAL\022\016.ik."
  "LogRequest\032\026.google.protobuf.EmptyB\003\200\001\001b"
  "\006proto3"
  ;
static const ::_pbi::DescriptorTable* const descriptor_table_LogServer_2eproto_deps[1] = {
  &::descriptor_table_google_2fprotobuf_2fempty_2eproto,
};
static ::_pbi::once_flag descriptor_table_LogServer_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_LogServer_2eproto = {
    false, false, 367, descriptor_table_protodef_LogServer_2eproto,
    "LogServer.proto",
    &descriptor_table_LogServer_2eproto_once, descriptor_table_LogServer_2eproto_deps, 1, 3,
    schemas, file_default_instances, TableStruct_LogServer_2eproto::offsets,
    file_level_metadata_LogServer_2eproto, file_level_enum_descriptors_LogServer_2eproto,
    file_level_service_descriptors_LogServer_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_LogServer_2eproto_getter() {
  return &descriptor_table_LogServer_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_LogServer_2eproto(&descriptor_table_LogServer_2eproto);
namespace ik {

// ===================================================================

class LogRequest::_Internal {
 public:
};

LogRequest::LogRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ik.LogRequest)
}
LogRequest::LogRequest(const LogRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  LogRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.msg_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_msg().empty()) {
    _this->_impl_.msg_.Set(from._internal_msg(), 
      _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:ik.LogRequest)
}

inline void LogRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.msg_){}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

LogRequest::~LogRequest() {
  // @@protoc_insertion_point(destructor:ik.LogRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LogRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
  _impl_.msg_.Destroy();
}

void LogRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void LogRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ik.LogRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  _impl_.msg_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LogRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
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

uint8_t* LogRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ik.LogRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes name = 1;
  if (!this->_internal_name().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_name(), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:ik.LogRequest)
  return target;
}

size_t LogRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ik.LogRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_name());
  }

  // bytes msg = 2;
  if (!this->_internal_msg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_msg());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LogRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    LogRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LogRequest::GetClassData() const { return &_class_data_; }


void LogRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<LogRequest*>(&to_msg);
  auto& from = static_cast<const LogRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ik.LogRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_msg().empty()) {
    _this->_internal_set_msg(from._internal_msg());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LogRequest::CopyFrom(const LogRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ik.LogRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogRequest::IsInitialized() const {
  return true;
}

void LogRequest::InternalSwap(LogRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.msg_, lhs_arena,
      &other->_impl_.msg_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata LogRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_LogServer_2eproto_getter, &descriptor_table_LogServer_2eproto_once,
      file_level_metadata_LogServer_2eproto[0]);
}

// ===================================================================

class ErrorMsg::_Internal {
 public:
};

ErrorMsg::ErrorMsg(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ik.ErrorMsg)
}
ErrorMsg::ErrorMsg(const ErrorMsg& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ErrorMsg* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.error_msg_){}
    , decltype(_impl_.state_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.error_msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.error_msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_error_msg().empty()) {
    _this->_impl_.error_msg_.Set(from._internal_error_msg(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.state_ = from._impl_.state_;
  // @@protoc_insertion_point(copy_constructor:ik.ErrorMsg)
}

inline void ErrorMsg::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.error_msg_){}
    , decltype(_impl_.state_){false}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.error_msg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.error_msg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ErrorMsg::~ErrorMsg() {
  // @@protoc_insertion_point(destructor:ik.ErrorMsg)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ErrorMsg::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.error_msg_.Destroy();
}

void ErrorMsg::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ErrorMsg::Clear() {
// @@protoc_insertion_point(message_clear_start:ik.ErrorMsg)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.error_msg_.ClearToEmpty();
  _impl_.state_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ErrorMsg::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool state = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.state_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes error_msg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_error_msg();
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

uint8_t* ErrorMsg::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ik.ErrorMsg)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool state = 1;
  if (this->_internal_state() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(1, this->_internal_state(), target);
  }

  // bytes error_msg = 2;
  if (!this->_internal_error_msg().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_error_msg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ik.ErrorMsg)
  return target;
}

size_t ErrorMsg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ik.ErrorMsg)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes error_msg = 2;
  if (!this->_internal_error_msg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_error_msg());
  }

  // bool state = 1;
  if (this->_internal_state() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ErrorMsg::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ErrorMsg::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ErrorMsg::GetClassData() const { return &_class_data_; }


void ErrorMsg::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ErrorMsg*>(&to_msg);
  auto& from = static_cast<const ErrorMsg&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ik.ErrorMsg)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_error_msg().empty()) {
    _this->_internal_set_error_msg(from._internal_error_msg());
  }
  if (from._internal_state() != 0) {
    _this->_internal_set_state(from._internal_state());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ErrorMsg::CopyFrom(const ErrorMsg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ik.ErrorMsg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorMsg::IsInitialized() const {
  return true;
}

void ErrorMsg::InternalSwap(ErrorMsg* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.error_msg_, lhs_arena,
      &other->_impl_.error_msg_, rhs_arena
  );
  swap(_impl_.state_, other->_impl_.state_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ErrorMsg::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_LogServer_2eproto_getter, &descriptor_table_LogServer_2eproto_once,
      file_level_metadata_LogServer_2eproto[1]);
}

// ===================================================================

class LogResponse::_Internal {
 public:
  static const ::ik::ErrorMsg& msg(const LogResponse* msg);
};

const ::ik::ErrorMsg&
LogResponse::_Internal::msg(const LogResponse* msg) {
  return *msg->_impl_.msg_;
}
LogResponse::LogResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ik.LogResponse)
}
LogResponse::LogResponse(const LogResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  LogResponse* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.msg_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_msg()) {
    _this->_impl_.msg_ = new ::ik::ErrorMsg(*from._impl_.msg_);
  }
  // @@protoc_insertion_point(copy_constructor:ik.LogResponse)
}

inline void LogResponse::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.msg_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

LogResponse::~LogResponse() {
  // @@protoc_insertion_point(destructor:ik.LogResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LogResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.msg_;
}

void LogResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void LogResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:ik.LogResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.msg_ != nullptr) {
    delete _impl_.msg_;
  }
  _impl_.msg_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LogResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .ik.ErrorMsg msg = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_msg(), ptr);
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

uint8_t* LogResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ik.LogResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .ik.ErrorMsg msg = 1;
  if (this->_internal_has_msg()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::msg(this),
        _Internal::msg(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ik.LogResponse)
  return target;
}

size_t LogResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ik.LogResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .ik.ErrorMsg msg = 1;
  if (this->_internal_has_msg()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.msg_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LogResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    LogResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LogResponse::GetClassData() const { return &_class_data_; }


void LogResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<LogResponse*>(&to_msg);
  auto& from = static_cast<const LogResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ik.LogResponse)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_msg()) {
    _this->_internal_mutable_msg()->::ik::ErrorMsg::MergeFrom(
        from._internal_msg());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LogResponse::CopyFrom(const LogResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ik.LogResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogResponse::IsInitialized() const {
  return true;
}

void LogResponse::InternalSwap(LogResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.msg_, other->_impl_.msg_);
}

::PROTOBUF_NAMESPACE_ID::Metadata LogResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_LogServer_2eproto_getter, &descriptor_table_LogServer_2eproto_once,
      file_level_metadata_LogServer_2eproto[2]);
}

// ===================================================================

LogServerRpc::~LogServerRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* LogServerRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_LogServer_2eproto);
  return file_level_service_descriptors_LogServer_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* LogServerRpc::GetDescriptor() {
  return descriptor();
}

void LogServerRpc::Log_INFO(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::ik::LogRequest*,
                         ::PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_INFO() not implemented.");
  done->Run();
}

void LogServerRpc::Log_ERROR(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::ik::LogRequest*,
                         ::PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_ERROR() not implemented.");
  done->Run();
}

void LogServerRpc::Log_FATAL(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::ik::LogRequest*,
                         ::PROTOBUF_NAMESPACE_ID::Empty*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Log_FATAL() not implemented.");
  done->Run();
}

void LogServerRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_LogServer_2eproto[0]);
  switch(method->index()) {
    case 0:
      Log_INFO(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::ik::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    case 1:
      Log_ERROR(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::ik::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    case 2:
      Log_FATAL(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::ik::LogRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::PROTOBUF_NAMESPACE_ID::Empty*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& LogServerRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::ik::LogRequest::default_instance();
    case 1:
      return ::ik::LogRequest::default_instance();
    case 2:
      return ::ik::LogRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& LogServerRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    case 1:
      return ::PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    case 2:
      return ::PROTOBUF_NAMESPACE_ID::Empty::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

LogServerRpc_Stub::LogServerRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
LogServerRpc_Stub::LogServerRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
LogServerRpc_Stub::~LogServerRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void LogServerRpc_Stub::Log_INFO(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::ik::LogRequest* request,
                              ::PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void LogServerRpc_Stub::Log_ERROR(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::ik::LogRequest* request,
                              ::PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void LogServerRpc_Stub::Log_FATAL(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::ik::LogRequest* request,
                              ::PROTOBUF_NAMESPACE_ID::Empty* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace ik
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ik::LogRequest*
Arena::CreateMaybeMessage< ::ik::LogRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ik::LogRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::ik::ErrorMsg*
Arena::CreateMaybeMessage< ::ik::ErrorMsg >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ik::ErrorMsg >(arena);
}
template<> PROTOBUF_NOINLINE ::ik::LogResponse*
Arena::CreateMaybeMessage< ::ik::LogResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ik::LogResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
