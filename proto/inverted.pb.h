// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: inverted.proto

#ifndef PROTOBUF_inverted_2eproto__INCLUDED
#define PROTOBUF_inverted_2eproto__INCLUDED

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

namespace protobuf_inverted_2eproto {
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
void InitDefaultsIntImpl();
void InitDefaultsInt();
void InitDefaultsinvered_indexImpl();
void InitDefaultsinvered_index();
void InitDefaultsinvered_hashImpl();
void InitDefaultsinvered_hash();
inline void InitDefaults() {
  InitDefaultsInt();
  InitDefaultsinvered_index();
  InitDefaultsinvered_hash();
}
}  // namespace protobuf_inverted_2eproto
namespace inverm {
class Int;
class IntDefaultTypeInternal;
extern IntDefaultTypeInternal _Int_default_instance_;
class invered_hash;
class invered_hashDefaultTypeInternal;
extern invered_hashDefaultTypeInternal _invered_hash_default_instance_;
class invered_index;
class invered_indexDefaultTypeInternal;
extern invered_indexDefaultTypeInternal _invered_index_default_instance_;
}  // namespace inverm
namespace inverm {

// ===================================================================

class Int : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:inverm.Int) */ {
 public:
  Int();
  virtual ~Int();

  Int(const Int& from);

  inline Int& operator=(const Int& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Int(Int&& from) noexcept
    : Int() {
    *this = ::std::move(from);
  }

  inline Int& operator=(Int&& from) noexcept {
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
  static const Int& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Int* internal_default_instance() {
    return reinterpret_cast<const Int*>(
               &_Int_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Int* other);
  friend void swap(Int& a, Int& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Int* New() const PROTOBUF_FINAL { return New(NULL); }

  Int* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Int& from);
  void MergeFrom(const Int& from);
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
  void InternalSwap(Int* other);
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

  // required int32 docid = 1;
  bool has_docid() const;
  void clear_docid();
  static const int kDocidFieldNumber = 1;
  ::google::protobuf::int32 docid() const;
  void set_docid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:inverm.Int)
 private:
  void set_has_docid();
  void clear_has_docid();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::int32 docid_;
  friend struct ::protobuf_inverted_2eproto::TableStruct;
  friend void ::protobuf_inverted_2eproto::InitDefaultsIntImpl();
};
// -------------------------------------------------------------------

class invered_index : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:inverm.invered_index) */ {
 public:
  invered_index();
  virtual ~invered_index();

  invered_index(const invered_index& from);

  inline invered_index& operator=(const invered_index& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  invered_index(invered_index&& from) noexcept
    : invered_index() {
    *this = ::std::move(from);
  }

  inline invered_index& operator=(invered_index&& from) noexcept {
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
  static const invered_index& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const invered_index* internal_default_instance() {
    return reinterpret_cast<const invered_index*>(
               &_invered_index_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(invered_index* other);
  friend void swap(invered_index& a, invered_index& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline invered_index* New() const PROTOBUF_FINAL { return New(NULL); }

  invered_index* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const invered_index& from);
  void MergeFrom(const invered_index& from);
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
  void InternalSwap(invered_index* other);
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

  // repeated .inverm.Int docid_vector = 2;
  int docid_vector_size() const;
  void clear_docid_vector();
  static const int kDocidVectorFieldNumber = 2;
  const ::inverm::Int& docid_vector(int index) const;
  ::inverm::Int* mutable_docid_vector(int index);
  ::inverm::Int* add_docid_vector();
  ::google::protobuf::RepeatedPtrField< ::inverm::Int >*
      mutable_docid_vector();
  const ::google::protobuf::RepeatedPtrField< ::inverm::Int >&
      docid_vector() const;

  // required string key = 1;
  bool has_key() const;
  void clear_key();
  static const int kKeyFieldNumber = 1;
  const ::std::string& key() const;
  void set_key(const ::std::string& value);
  #if LANG_CXX11
  void set_key(::std::string&& value);
  #endif
  void set_key(const char* value);
  void set_key(const char* value, size_t size);
  ::std::string* mutable_key();
  ::std::string* release_key();
  void set_allocated_key(::std::string* key);

  // @@protoc_insertion_point(class_scope:inverm.invered_index)
 private:
  void set_has_key();
  void clear_has_key();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::inverm::Int > docid_vector_;
  ::google::protobuf::internal::ArenaStringPtr key_;
  friend struct ::protobuf_inverted_2eproto::TableStruct;
  friend void ::protobuf_inverted_2eproto::InitDefaultsinvered_indexImpl();
};
// -------------------------------------------------------------------

class invered_hash : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:inverm.invered_hash) */ {
 public:
  invered_hash();
  virtual ~invered_hash();

  invered_hash(const invered_hash& from);

  inline invered_hash& operator=(const invered_hash& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  invered_hash(invered_hash&& from) noexcept
    : invered_hash() {
    *this = ::std::move(from);
  }

  inline invered_hash& operator=(invered_hash&& from) noexcept {
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
  static const invered_hash& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const invered_hash* internal_default_instance() {
    return reinterpret_cast<const invered_hash*>(
               &_invered_hash_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(invered_hash* other);
  friend void swap(invered_hash& a, invered_hash& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline invered_hash* New() const PROTOBUF_FINAL { return New(NULL); }

  invered_hash* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const invered_hash& from);
  void MergeFrom(const invered_hash& from);
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
  void InternalSwap(invered_hash* other);
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

  // repeated .inverm.invered_index index = 1;
  int index_size() const;
  void clear_index();
  static const int kIndexFieldNumber = 1;
  const ::inverm::invered_index& index(int index) const;
  ::inverm::invered_index* mutable_index(int index);
  ::inverm::invered_index* add_index();
  ::google::protobuf::RepeatedPtrField< ::inverm::invered_index >*
      mutable_index();
  const ::google::protobuf::RepeatedPtrField< ::inverm::invered_index >&
      index() const;

  // @@protoc_insertion_point(class_scope:inverm.invered_hash)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::inverm::invered_index > index_;
  friend struct ::protobuf_inverted_2eproto::TableStruct;
  friend void ::protobuf_inverted_2eproto::InitDefaultsinvered_hashImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Int

// required int32 docid = 1;
inline bool Int::has_docid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Int::set_has_docid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Int::clear_has_docid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Int::clear_docid() {
  docid_ = 0;
  clear_has_docid();
}
inline ::google::protobuf::int32 Int::docid() const {
  // @@protoc_insertion_point(field_get:inverm.Int.docid)
  return docid_;
}
inline void Int::set_docid(::google::protobuf::int32 value) {
  set_has_docid();
  docid_ = value;
  // @@protoc_insertion_point(field_set:inverm.Int.docid)
}

// -------------------------------------------------------------------

// invered_index

// required string key = 1;
inline bool invered_index::has_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void invered_index::set_has_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void invered_index::clear_has_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void invered_index::clear_key() {
  key_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_key();
}
inline const ::std::string& invered_index::key() const {
  // @@protoc_insertion_point(field_get:inverm.invered_index.key)
  return key_.GetNoArena();
}
inline void invered_index::set_key(const ::std::string& value) {
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:inverm.invered_index.key)
}
#if LANG_CXX11
inline void invered_index::set_key(::std::string&& value) {
  set_has_key();
  key_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:inverm.invered_index.key)
}
#endif
inline void invered_index::set_key(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:inverm.invered_index.key)
}
inline void invered_index::set_key(const char* value, size_t size) {
  set_has_key();
  key_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:inverm.invered_index.key)
}
inline ::std::string* invered_index::mutable_key() {
  set_has_key();
  // @@protoc_insertion_point(field_mutable:inverm.invered_index.key)
  return key_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* invered_index::release_key() {
  // @@protoc_insertion_point(field_release:inverm.invered_index.key)
  clear_has_key();
  return key_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void invered_index::set_allocated_key(::std::string* key) {
  if (key != NULL) {
    set_has_key();
  } else {
    clear_has_key();
  }
  key_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), key);
  // @@protoc_insertion_point(field_set_allocated:inverm.invered_index.key)
}

// repeated .inverm.Int docid_vector = 2;
inline int invered_index::docid_vector_size() const {
  return docid_vector_.size();
}
inline void invered_index::clear_docid_vector() {
  docid_vector_.Clear();
}
inline const ::inverm::Int& invered_index::docid_vector(int index) const {
  // @@protoc_insertion_point(field_get:inverm.invered_index.docid_vector)
  return docid_vector_.Get(index);
}
inline ::inverm::Int* invered_index::mutable_docid_vector(int index) {
  // @@protoc_insertion_point(field_mutable:inverm.invered_index.docid_vector)
  return docid_vector_.Mutable(index);
}
inline ::inverm::Int* invered_index::add_docid_vector() {
  // @@protoc_insertion_point(field_add:inverm.invered_index.docid_vector)
  return docid_vector_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::inverm::Int >*
invered_index::mutable_docid_vector() {
  // @@protoc_insertion_point(field_mutable_list:inverm.invered_index.docid_vector)
  return &docid_vector_;
}
inline const ::google::protobuf::RepeatedPtrField< ::inverm::Int >&
invered_index::docid_vector() const {
  // @@protoc_insertion_point(field_list:inverm.invered_index.docid_vector)
  return docid_vector_;
}

// -------------------------------------------------------------------

// invered_hash

// repeated .inverm.invered_index index = 1;
inline int invered_hash::index_size() const {
  return index_.size();
}
inline void invered_hash::clear_index() {
  index_.Clear();
}
inline const ::inverm::invered_index& invered_hash::index(int index) const {
  // @@protoc_insertion_point(field_get:inverm.invered_hash.index)
  return index_.Get(index);
}
inline ::inverm::invered_index* invered_hash::mutable_index(int index) {
  // @@protoc_insertion_point(field_mutable:inverm.invered_hash.index)
  return index_.Mutable(index);
}
inline ::inverm::invered_index* invered_hash::add_index() {
  // @@protoc_insertion_point(field_add:inverm.invered_hash.index)
  return index_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::inverm::invered_index >*
invered_hash::mutable_index() {
  // @@protoc_insertion_point(field_mutable_list:inverm.invered_hash.index)
  return &index_;
}
inline const ::google::protobuf::RepeatedPtrField< ::inverm::invered_index >&
invered_hash::index() const {
  // @@protoc_insertion_point(field_list:inverm.invered_hash.index)
  return index_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace inverm

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_inverted_2eproto__INCLUDED
