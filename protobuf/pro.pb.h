// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pro.proto

#ifndef PROTOBUF_pro_2eproto__INCLUDED
#define PROTOBUF_pro_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_pro_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultshelloworldImpl();
void InitDefaultshelloworld();
void InitDefaultsIndexImpl();
void InitDefaultsIndex();
void InitDefaultsalldexImpl();
void InitDefaultsalldex();
inline void InitDefaults() {
  InitDefaultshelloworld();
  InitDefaultsIndex();
  InitDefaultsalldex();
}
}  // namespace protobuf_pro_2eproto
namespace lm {
class Index;
class IndexDefaultTypeInternal;
extern IndexDefaultTypeInternal _Index_default_instance_;
class alldex;
class alldexDefaultTypeInternal;
extern alldexDefaultTypeInternal _alldex_default_instance_;
class helloworld;
class helloworldDefaultTypeInternal;
extern helloworldDefaultTypeInternal _helloworld_default_instance_;
}  // namespace lm
namespace lm {

// ===================================================================

class helloworld : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lm.helloworld) */ {
 public:
  helloworld();
  virtual ~helloworld();

  helloworld(const helloworld& from);

  inline helloworld& operator=(const helloworld& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  helloworld(helloworld&& from) noexcept
    : helloworld() {
    *this = ::std::move(from);
  }

  inline helloworld& operator=(helloworld&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const helloworld& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const helloworld* internal_default_instance() {
    return reinterpret_cast<const helloworld*>(
               &_helloworld_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(helloworld* other);
  friend void swap(helloworld& a, helloworld& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline helloworld* New() const PROTOBUF_FINAL { return New(NULL); }

  helloworld* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const helloworld& from);
  void MergeFrom(const helloworld& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(helloworld* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string str = 2;
  bool has_str() const;
  void clear_str();
  static const int kStrFieldNumber = 2;
  const ::std::string& str() const;
  void set_str(const ::std::string& value);
  #if LANG_CXX11
  void set_str(::std::string&& value);
  #endif
  void set_str(const char* value);
  void set_str(const char* value, size_t size);
  ::std::string* mutable_str();
  ::std::string* release_str();
  void set_allocated_str(::std::string* str);

  // required int32 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:lm.helloworld)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_str();
  void clear_has_str();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr str_;
  ::google::protobuf::int32 id_;
  friend struct ::protobuf_pro_2eproto::TableStruct;
  friend void ::protobuf_pro_2eproto::InitDefaultshelloworldImpl();
};
// -------------------------------------------------------------------

class Index : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lm.Index) */ {
 public:
  Index();
  virtual ~Index();

  Index(const Index& from);

  inline Index& operator=(const Index& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Index(Index&& from) noexcept
    : Index() {
    *this = ::std::move(from);
  }

  inline Index& operator=(Index&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Index& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Index* internal_default_instance() {
    return reinterpret_cast<const Index*>(
               &_Index_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Index* other);
  friend void swap(Index& a, Index& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Index* New() const PROTOBUF_FINAL { return New(NULL); }

  Index* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Index& from);
  void MergeFrom(const Index& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Index* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .lm.helloworld info = 2;
  int info_size() const;
  void clear_info();
  static const int kInfoFieldNumber = 2;
  const ::lm::helloworld& info(int index) const;
  ::lm::helloworld* mutable_info(int index);
  ::lm::helloworld* add_info();
  ::google::protobuf::RepeatedPtrField< ::lm::helloworld >*
      mutable_info();
  const ::google::protobuf::RepeatedPtrField< ::lm::helloworld >&
      info() const;

  // required int32 key = 1;
  bool has_key() const;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  ::google::protobuf::int32 key() const;
  void set_key(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:lm.Index)
 private:
  void set_has_key();
  void clear_has_key();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::lm::helloworld > info_;
  ::google::protobuf::int32 key_;
  friend struct ::protobuf_pro_2eproto::TableStruct;
  friend void ::protobuf_pro_2eproto::InitDefaultsIndexImpl();
};
// -------------------------------------------------------------------

class alldex : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lm.alldex) */ {
 public:
  alldex();
  virtual ~alldex();

  alldex(const alldex& from);

  inline alldex& operator=(const alldex& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  alldex(alldex&& from) noexcept
    : alldex() {
    *this = ::std::move(from);
  }

  inline alldex& operator=(alldex&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const alldex& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const alldex* internal_default_instance() {
    return reinterpret_cast<const alldex*>(
               &_alldex_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(alldex* other);
  friend void swap(alldex& a, alldex& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline alldex* New() const PROTOBUF_FINAL { return New(NULL); }

  alldex* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const alldex& from);
  void MergeFrom(const alldex& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(alldex* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .lm.Index index = 1;
  int index_size() const;
  void clear_index();
  static const int kIndexFieldNumber = 1;
  const ::lm::Index& index(int index) const;
  ::lm::Index* mutable_index(int index);
  ::lm::Index* add_index();
  ::google::protobuf::RepeatedPtrField< ::lm::Index >*
      mutable_index();
  const ::google::protobuf::RepeatedPtrField< ::lm::Index >&
      index() const;

  // @@protoc_insertion_point(class_scope:lm.alldex)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::lm::Index > index_;
  friend struct ::protobuf_pro_2eproto::TableStruct;
  friend void ::protobuf_pro_2eproto::InitDefaultsalldexImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// helloworld

// required int32 id = 1;
inline bool helloworld::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void helloworld::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void helloworld::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void helloworld::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 helloworld::id() const {
  // @@protoc_insertion_point(field_get:lm.helloworld.id)
  return id_;
}
inline void helloworld::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:lm.helloworld.id)
}

// required string str = 2;
inline bool helloworld::has_str() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void helloworld::set_has_str() {
  _has_bits_[0] |= 0x00000001u;
}
inline void helloworld::clear_has_str() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void helloworld::clear_str() {
  str_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_str();
}
inline const ::std::string& helloworld::str() const {
  // @@protoc_insertion_point(field_get:lm.helloworld.str)
  return str_.GetNoArena();
}
inline void helloworld::set_str(const ::std::string& value) {
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:lm.helloworld.str)
}
#if LANG_CXX11
inline void helloworld::set_str(::std::string&& value) {
  set_has_str();
  str_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:lm.helloworld.str)
}
#endif
inline void helloworld::set_str(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:lm.helloworld.str)
}
inline void helloworld::set_str(const char* value, size_t size) {
  set_has_str();
  str_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:lm.helloworld.str)
}
inline ::std::string* helloworld::mutable_str() {
  set_has_str();
  // @@protoc_insertion_point(field_mutable:lm.helloworld.str)
  return str_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* helloworld::release_str() {
  // @@protoc_insertion_point(field_release:lm.helloworld.str)
  clear_has_str();
  return str_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void helloworld::set_allocated_str(::std::string* str) {
  if (str != NULL) {
    set_has_str();
  } else {
    clear_has_str();
  }
  str_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), str);
  // @@protoc_insertion_point(field_set_allocated:lm.helloworld.str)
}

// -------------------------------------------------------------------

// Index

// required int32 key = 1;
inline bool Index::has_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Index::set_has_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Index::clear_has_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Index::clear_key() {
  key_ = 0;
  clear_has_key();
}
inline ::google::protobuf::int32 Index::key() const {
  // @@protoc_insertion_point(field_get:lm.Index.key)
  return key_;
}
inline void Index::set_key(::google::protobuf::int32 value) {
  set_has_key();
  key_ = value;
  // @@protoc_insertion_point(field_set:lm.Index.key)
}

// repeated .lm.helloworld info = 2;
inline int Index::info_size() const {
  return info_.size();
}
inline void Index::clear_info() {
  info_.Clear();
}
inline const ::lm::helloworld& Index::info(int index) const {
  // @@protoc_insertion_point(field_get:lm.Index.info)
  return info_.Get(index);
}
inline ::lm::helloworld* Index::mutable_info(int index) {
  // @@protoc_insertion_point(field_mutable:lm.Index.info)
  return info_.Mutable(index);
}
inline ::lm::helloworld* Index::add_info() {
  // @@protoc_insertion_point(field_add:lm.Index.info)
  return info_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::lm::helloworld >*
Index::mutable_info() {
  // @@protoc_insertion_point(field_mutable_list:lm.Index.info)
  return &info_;
}
inline const ::google::protobuf::RepeatedPtrField< ::lm::helloworld >&
Index::info() const {
  // @@protoc_insertion_point(field_list:lm.Index.info)
  return info_;
}

// -------------------------------------------------------------------

// alldex

// repeated .lm.Index index = 1;
inline int alldex::index_size() const {
  return index_.size();
}
inline void alldex::clear_index() {
  index_.Clear();
}
inline const ::lm::Index& alldex::index(int index) const {
  // @@protoc_insertion_point(field_get:lm.alldex.index)
  return index_.Get(index);
}
inline ::lm::Index* alldex::mutable_index(int index) {
  // @@protoc_insertion_point(field_mutable:lm.alldex.index)
  return index_.Mutable(index);
}
inline ::lm::Index* alldex::add_index() {
  // @@protoc_insertion_point(field_add:lm.alldex.index)
  return index_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::lm::Index >*
alldex::mutable_index() {
  // @@protoc_insertion_point(field_mutable_list:lm.alldex.index)
  return &index_;
}
inline const ::google::protobuf::RepeatedPtrField< ::lm::Index >&
alldex::index() const {
  // @@protoc_insertion_point(field_list:lm.alldex.index)
  return index_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace lm

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_pro_2eproto__INCLUDED