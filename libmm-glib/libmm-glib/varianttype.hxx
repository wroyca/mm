
#ifndef _GLIBMM_VARIANTTYPE_H
#define _GLIBMM_VARIANTTYPE_H

#include <glib-object.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/value.hxx>
#include <string>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GVariantType GVariantType;
#endif

namespace Glib
{

  class GLIBMM_API VariantType
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantType;
    using BaseObjectType = GVariantType;
#endif

    VariantType ();

    explicit VariantType (GVariantType* castitem, bool make_a_copy = false);

    VariantType (const VariantType& src);
    auto
    operator= (const VariantType& src) -> VariantType&;

    VariantType (VariantType&& other) noexcept;
    auto
    operator= (VariantType&& other) noexcept -> VariantType&;

    ~VariantType () noexcept;

    void
    swap (VariantType& other) noexcept;

    auto
    gobj () -> GVariantType*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GVariantType*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GVariantType*;

  protected:
    GVariantType* gobject_;

  private:
  public:
    explicit VariantType (const GVariantType* castitem);

    explicit VariantType (const std::string& type_string);

    auto
    operator= (const GVariantType* castitem) -> VariantType&;

    static auto
    create_array (const VariantType& element) -> VariantType;

    static auto
    create_maybe (const VariantType& element) -> VariantType;

    static auto
    create_tuple (const std::vector<VariantType>& items) -> VariantType;

    static auto
    create_dict_entry (const VariantType& key, const VariantType& value)
        -> VariantType;

    auto
    get_string_length () const -> gsize;

    auto
    get_string () const -> std::string;

    auto
    is_definite () const -> bool;

    auto
    is_container () const -> bool;

    auto
    is_basic () const -> bool;

    auto
    is_maybe () const -> bool;

    auto
    is_array () const -> bool;

    auto
    is_tuple () const -> bool;

    auto
    is_dict_entry () const -> bool;

    auto
    is_variant () const -> bool;

    auto
    hash () const -> guint;

    auto
    equal (const VariantType& other) const -> bool;

    auto
    is_subtype_of (const VariantType& supertype) const -> bool;

    auto
    element () const -> VariantType;

    auto
    n_items () const -> gsize;

    auto
    key () const -> VariantType;

    auto
    value () const -> VariantType;

    auto
    get_item_types () const -> std::vector<VariantType>;
  };

  extern GLIBMM_API const VariantType VARIANT_TYPE_BOOL;

  extern GLIBMM_API const VariantType VARIANT_TYPE_BYTE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_INT16;

  extern GLIBMM_API const VariantType VARIANT_TYPE_UINT16;

  extern GLIBMM_API const VariantType VARIANT_TYPE_INT32;

  extern GLIBMM_API const VariantType VARIANT_TYPE_UINT32;

  extern GLIBMM_API const VariantType VARIANT_TYPE_INT64;

  extern GLIBMM_API const VariantType VARIANT_TYPE_UINT64;

  extern GLIBMM_API const VariantType VARIANT_TYPE_DOUBLE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_STRING;

  extern GLIBMM_API const VariantType VARIANT_TYPE_OBJECT_PATH;

  extern GLIBMM_API const VariantType VARIANT_TYPE_SIGNATURE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_VARIANT;

  extern GLIBMM_API const VariantType VARIANT_TYPE_HANDLE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_UNIT;

  extern GLIBMM_API const VariantType VARIANT_TYPE_ANY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_BASIC;

  extern GLIBMM_API const VariantType VARIANT_TYPE_MAYBE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_ARRAY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_TUPLE;

  extern GLIBMM_API const VariantType VARIANT_TYPE_DICT_ENTRY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_DICTIONARY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_STRING_ARRAY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_OBJECT_PATH_ARRAY;

  extern GLIBMM_API const VariantType VARIANT_TYPE_BYTESTRING;

  extern GLIBMM_API const VariantType VARIANT_TYPE_BYTESTRING_ARRAY;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <>
  class GLIBMM_API Value<Glib::VariantType> : public ValueBase_Boxed
  {
  public:
    using CppType = Glib::VariantType;
    using CType = GVariantType*;

    static auto
    value_type () -> GType;

    void
    set (const CppType& data);
    auto
    get () const -> CppType;
  };
#endif

} // namespace Glib

namespace Glib
{

  inline void
  swap (VariantType& lhs, VariantType& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GVariantType* object, bool take_copy = false) -> Glib::VariantType;

} // namespace Glib

#endif
