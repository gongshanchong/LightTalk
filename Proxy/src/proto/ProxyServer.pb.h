// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProxyServer.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ProxyServer_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ProxyServer_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ProxyServer_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ProxyServer_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ProxyServer_2eproto;
namespace ik_Proxy {
class PoxryMessage;
struct PoxryMessageDefaultTypeInternal;
extern PoxryMessageDefaultTypeInternal _PoxryMessage_default_instance_;
class PoxryResponse;
struct PoxryResponseDefaultTypeInternal;
extern PoxryResponseDefaultTypeInternal _PoxryResponse_default_instance_;
}  // namespace ik_Proxy
PROTOBUF_NAMESPACE_OPEN
template<> ::ik_Proxy::PoxryMessage* Arena::CreateMaybeMessage<::ik_Proxy::PoxryMessage>(Arena*);
template<> ::ik_Proxy::PoxryResponse* Arena::CreateMaybeMessage<::ik_Proxy::PoxryResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ik_Proxy {

// ===================================================================

class PoxryMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ik_Proxy.PoxryMessage) */ {
 public:
  inline PoxryMessage() : PoxryMessage(nullptr) {}
  ~PoxryMessage() override;
  explicit PROTOBUF_CONSTEXPR PoxryMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PoxryMessage(const PoxryMessage& from);
  PoxryMessage(PoxryMessage&& from) noexcept
    : PoxryMessage() {
    *this = ::std::move(from);
  }

  inline PoxryMessage& operator=(const PoxryMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline PoxryMessage& operator=(PoxryMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PoxryMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const PoxryMessage* internal_default_instance() {
    return reinterpret_cast<const PoxryMessage*>(
               &_PoxryMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PoxryMessage& a, PoxryMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(PoxryMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PoxryMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PoxryMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PoxryMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PoxryMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PoxryMessage& from) {
    PoxryMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PoxryMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ik_Proxy.PoxryMessage";
  }
  protected:
  explicit PoxryMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTypeFieldNumber = 1,
    kRequestMsgFieldNumber = 2,
  };
  // bytes type = 1;
  void clear_type();
  const std::string& type() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_type(ArgT0&& arg0, ArgT... args);
  std::string* mutable_type();
  PROTOBUF_NODISCARD std::string* release_type();
  void set_allocated_type(std::string* type);
  private:
  const std::string& _internal_type() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_type(const std::string& value);
  std::string* _internal_mutable_type();
  public:

  // bytes request_msg = 2;
  void clear_request_msg();
  const std::string& request_msg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_request_msg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_request_msg();
  PROTOBUF_NODISCARD std::string* release_request_msg();
  void set_allocated_request_msg(std::string* request_msg);
  private:
  const std::string& _internal_request_msg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_request_msg(const std::string& value);
  std::string* _internal_mutable_request_msg();
  public:

  // @@protoc_insertion_point(class_scope:ik_Proxy.PoxryMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr type_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr request_msg_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ProxyServer_2eproto;
};
// -------------------------------------------------------------------

class PoxryResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ik_Proxy.PoxryResponse) */ {
 public:
  inline PoxryResponse() : PoxryResponse(nullptr) {}
  ~PoxryResponse() override;
  explicit PROTOBUF_CONSTEXPR PoxryResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PoxryResponse(const PoxryResponse& from);
  PoxryResponse(PoxryResponse&& from) noexcept
    : PoxryResponse() {
    *this = ::std::move(from);
  }

  inline PoxryResponse& operator=(const PoxryResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline PoxryResponse& operator=(PoxryResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PoxryResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const PoxryResponse* internal_default_instance() {
    return reinterpret_cast<const PoxryResponse*>(
               &_PoxryResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PoxryResponse& a, PoxryResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(PoxryResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PoxryResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PoxryResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PoxryResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PoxryResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const PoxryResponse& from) {
    PoxryResponse::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PoxryResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ik_Proxy.PoxryResponse";
  }
  protected:
  explicit PoxryResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTypeFieldNumber = 1,
    kResponseMsgFieldNumber = 2,
  };
  // bytes type = 1;
  void clear_type();
  const std::string& type() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_type(ArgT0&& arg0, ArgT... args);
  std::string* mutable_type();
  PROTOBUF_NODISCARD std::string* release_type();
  void set_allocated_type(std::string* type);
  private:
  const std::string& _internal_type() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_type(const std::string& value);
  std::string* _internal_mutable_type();
  public:

  // bytes response_msg = 2;
  void clear_response_msg();
  const std::string& response_msg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_response_msg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_response_msg();
  PROTOBUF_NODISCARD std::string* release_response_msg();
  void set_allocated_response_msg(std::string* response_msg);
  private:
  const std::string& _internal_response_msg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_response_msg(const std::string& value);
  std::string* _internal_mutable_response_msg();
  public:

  // @@protoc_insertion_point(class_scope:ik_Proxy.PoxryResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr type_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr response_msg_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ProxyServer_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PoxryMessage

// bytes type = 1;
inline void PoxryMessage::clear_type() {
  _impl_.type_.ClearToEmpty();
}
inline const std::string& PoxryMessage::type() const {
  // @@protoc_insertion_point(field_get:ik_Proxy.PoxryMessage.type)
  return _internal_type();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PoxryMessage::set_type(ArgT0&& arg0, ArgT... args) {
 
 _impl_.type_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ik_Proxy.PoxryMessage.type)
}
inline std::string* PoxryMessage::mutable_type() {
  std::string* _s = _internal_mutable_type();
  // @@protoc_insertion_point(field_mutable:ik_Proxy.PoxryMessage.type)
  return _s;
}
inline const std::string& PoxryMessage::_internal_type() const {
  return _impl_.type_.Get();
}
inline void PoxryMessage::_internal_set_type(const std::string& value) {
  
  _impl_.type_.Set(value, GetArenaForAllocation());
}
inline std::string* PoxryMessage::_internal_mutable_type() {
  
  return _impl_.type_.Mutable(GetArenaForAllocation());
}
inline std::string* PoxryMessage::release_type() {
  // @@protoc_insertion_point(field_release:ik_Proxy.PoxryMessage.type)
  return _impl_.type_.Release();
}
inline void PoxryMessage::set_allocated_type(std::string* type) {
  if (type != nullptr) {
    
  } else {
    
  }
  _impl_.type_.SetAllocated(type, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.type_.IsDefault()) {
    _impl_.type_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ik_Proxy.PoxryMessage.type)
}

// bytes request_msg = 2;
inline void PoxryMessage::clear_request_msg() {
  _impl_.request_msg_.ClearToEmpty();
}
inline const std::string& PoxryMessage::request_msg() const {
  // @@protoc_insertion_point(field_get:ik_Proxy.PoxryMessage.request_msg)
  return _internal_request_msg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PoxryMessage::set_request_msg(ArgT0&& arg0, ArgT... args) {
 
 _impl_.request_msg_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ik_Proxy.PoxryMessage.request_msg)
}
inline std::string* PoxryMessage::mutable_request_msg() {
  std::string* _s = _internal_mutable_request_msg();
  // @@protoc_insertion_point(field_mutable:ik_Proxy.PoxryMessage.request_msg)
  return _s;
}
inline const std::string& PoxryMessage::_internal_request_msg() const {
  return _impl_.request_msg_.Get();
}
inline void PoxryMessage::_internal_set_request_msg(const std::string& value) {
  
  _impl_.request_msg_.Set(value, GetArenaForAllocation());
}
inline std::string* PoxryMessage::_internal_mutable_request_msg() {
  
  return _impl_.request_msg_.Mutable(GetArenaForAllocation());
}
inline std::string* PoxryMessage::release_request_msg() {
  // @@protoc_insertion_point(field_release:ik_Proxy.PoxryMessage.request_msg)
  return _impl_.request_msg_.Release();
}
inline void PoxryMessage::set_allocated_request_msg(std::string* request_msg) {
  if (request_msg != nullptr) {
    
  } else {
    
  }
  _impl_.request_msg_.SetAllocated(request_msg, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.request_msg_.IsDefault()) {
    _impl_.request_msg_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ik_Proxy.PoxryMessage.request_msg)
}

// -------------------------------------------------------------------

// PoxryResponse

// bytes type = 1;
inline void PoxryResponse::clear_type() {
  _impl_.type_.ClearToEmpty();
}
inline const std::string& PoxryResponse::type() const {
  // @@protoc_insertion_point(field_get:ik_Proxy.PoxryResponse.type)
  return _internal_type();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PoxryResponse::set_type(ArgT0&& arg0, ArgT... args) {
 
 _impl_.type_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ik_Proxy.PoxryResponse.type)
}
inline std::string* PoxryResponse::mutable_type() {
  std::string* _s = _internal_mutable_type();
  // @@protoc_insertion_point(field_mutable:ik_Proxy.PoxryResponse.type)
  return _s;
}
inline const std::string& PoxryResponse::_internal_type() const {
  return _impl_.type_.Get();
}
inline void PoxryResponse::_internal_set_type(const std::string& value) {
  
  _impl_.type_.Set(value, GetArenaForAllocation());
}
inline std::string* PoxryResponse::_internal_mutable_type() {
  
  return _impl_.type_.Mutable(GetArenaForAllocation());
}
inline std::string* PoxryResponse::release_type() {
  // @@protoc_insertion_point(field_release:ik_Proxy.PoxryResponse.type)
  return _impl_.type_.Release();
}
inline void PoxryResponse::set_allocated_type(std::string* type) {
  if (type != nullptr) {
    
  } else {
    
  }
  _impl_.type_.SetAllocated(type, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.type_.IsDefault()) {
    _impl_.type_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ik_Proxy.PoxryResponse.type)
}

// bytes response_msg = 2;
inline void PoxryResponse::clear_response_msg() {
  _impl_.response_msg_.ClearToEmpty();
}
inline const std::string& PoxryResponse::response_msg() const {
  // @@protoc_insertion_point(field_get:ik_Proxy.PoxryResponse.response_msg)
  return _internal_response_msg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PoxryResponse::set_response_msg(ArgT0&& arg0, ArgT... args) {
 
 _impl_.response_msg_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:ik_Proxy.PoxryResponse.response_msg)
}
inline std::string* PoxryResponse::mutable_response_msg() {
  std::string* _s = _internal_mutable_response_msg();
  // @@protoc_insertion_point(field_mutable:ik_Proxy.PoxryResponse.response_msg)
  return _s;
}
inline const std::string& PoxryResponse::_internal_response_msg() const {
  return _impl_.response_msg_.Get();
}
inline void PoxryResponse::_internal_set_response_msg(const std::string& value) {
  
  _impl_.response_msg_.Set(value, GetArenaForAllocation());
}
inline std::string* PoxryResponse::_internal_mutable_response_msg() {
  
  return _impl_.response_msg_.Mutable(GetArenaForAllocation());
}
inline std::string* PoxryResponse::release_response_msg() {
  // @@protoc_insertion_point(field_release:ik_Proxy.PoxryResponse.response_msg)
  return _impl_.response_msg_.Release();
}
inline void PoxryResponse::set_allocated_response_msg(std::string* response_msg) {
  if (response_msg != nullptr) {
    
  } else {
    
  }
  _impl_.response_msg_.SetAllocated(response_msg, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.response_msg_.IsDefault()) {
    _impl_.response_msg_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:ik_Proxy.PoxryResponse.response_msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ik_Proxy

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ProxyServer_2eproto
