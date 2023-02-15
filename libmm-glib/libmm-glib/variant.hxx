// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VARIANT_H
#define _GLIBMM_VARIANT_H

#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/variantdbusstring.hxx>
#include <libmm-glib/variantiter.hxx>
#include <libmm-glib/varianttype.hxx>
#include <map>
#include <memory>
#include <stdexcept>
#include <tuple>
#include <typeinfo>
#include <utility>
#include <vector>

namespace Glib
{
  class Bytes;

  class VariantParseError : public Glib::Error
  {
  public:
    enum Code
    {
      FAILED,
      BASIC_TYPE_EXPECTED,
      CANNOT_INFER_TYPE,
      DEFINITE_TYPE_EXPECTED,
      INPUT_NOT_AT_END,
      INVALID_CHARACTER,
      INVALID_FORMAT_STRING,
      INVALID_OBJECT_PATH,
      INVALID_SIGNATURE,
      INVALID_TYPE_STRING,
      NO_COMMON_TYPE,
      NUMBER_OUT_OF_RANGE,
      NUMBER_TOO_BIG,
      TYPE_ERROR,
      UNEXPECTED_TOKEN,
      UNKNOWN_KEYWORD,
      UNTERMINATED_STRING_CONSTANT,
      VALUE_EXPECTED,
      RECURSION
    };

    LIBMM_GLIB_SYMEXPORT
    VariantParseError (Code error_code, const Glib::ustring& error_message);
    LIBMM_GLIB_SYMEXPORT explicit VariantParseError (GError* gobject);
    LIBMM_GLIB_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GLIB_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GLIB_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

  class LIBMM_GLIB_SYMEXPORT VariantBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantBase;
    using BaseObjectType = GVariant;
#endif

    VariantBase ();

    explicit VariantBase (GVariant* castitem, bool make_a_copy = false);

    VariantBase (const VariantBase& src);
    auto
    operator= (const VariantBase& src) -> VariantBase&;

    VariantBase (VariantBase&& other) noexcept;
    auto
    operator= (VariantBase&& other) noexcept -> VariantBase&;

    ~VariantBase () noexcept;

    auto
    swap (VariantBase& other) noexcept -> void;

    auto
    gobj () -> GVariant*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GVariant*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GVariant*;

  protected:
    GVariant* gobject_;

  private:
  public:
    explicit operator bool () const;

    auto
    init (const GVariant* cobject, bool take_a_reference = false) -> void;

    auto
    get_type () const -> VariantType;

    auto
    get_type_string () const -> std::string;

    auto
    is_floating () const -> bool;

    auto
    is_of_type (const VariantType& type) const -> bool;

    auto
    is_container () const -> bool;

    auto
    classify () const -> GVariantClass;

    auto
    get_size () const -> gsize;

    auto
    get_data () const -> gconstpointer;

    auto
    get_data_as_bytes () const -> Glib::RefPtr<const Glib::Bytes>;

    auto
    store (gpointer data) const -> void;

    auto
    print (bool type_annotate = false) const -> Glib::ustring;

    auto
    hash () const -> guint;

    auto
    equal (const VariantBase& other) const -> bool;

    auto
    operator== (const VariantBase& other) const -> bool;

    auto
    operator!= (const VariantBase& other) const -> bool;

    auto
    operator<(const VariantBase& other) const -> bool = delete;

    auto
    operator<= (const VariantBase& other) const -> bool = delete;

    auto
    operator> (const VariantBase& other) const -> bool = delete;

    auto
    operator>= (const VariantBase& other) const -> bool = delete;

    auto
    get_normal_form (VariantBase& result) const -> void;

    auto
    is_normal_form () const -> bool;

    auto
    byteswap (VariantBase& result) const -> void;

    auto
    check_format_string (const std::string& format_string,
                         bool copy_only = false) const -> bool;

    template <class V_CastTo>
    static auto
    cast_dynamic (const VariantBase& v) -> V_CastTo;

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    is_castable_to (const VariantType& supertype) const -> bool;
#endif
  };

  template <class V_CastTo>
  auto
  VariantBase::cast_dynamic (const VariantBase& v) -> V_CastTo
  {
    if (!(v.gobj ()))
    {
      return V_CastTo ();
    }
    if (v.is_castable_to (V_CastTo::variant_type ()))
    {
      return V_CastTo (const_cast<GVariant*> (v.gobj ()), true);
    }
    else
    {
      throw std::bad_cast ();
    }
  }

  class LIBMM_GLIB_SYMEXPORT VariantStringBase : public VariantBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantStringBase;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = GVariant*;
    using CppType = VariantStringBase;

    VariantStringBase ();

    explicit VariantStringBase (GVariant* castitem,
                                bool take_a_reference = false);

    static auto
    create_object_path (VariantStringBase& output,
                        const std::string& object_path) -> void;

    static auto
    is_object_path (const std::string& string) -> bool;

    static auto
    create_signature (VariantStringBase& output, const std::string& signature)
        -> void;

    static auto
    is_signature (const std::string& string) -> bool;
  };

  class LIBMM_GLIB_SYMEXPORT VariantContainerBase : public VariantBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantContainerBase;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = GVariant*;
    using CppType = VariantContainerBase;

    VariantContainerBase ();

    explicit VariantContainerBase (GVariant* castitem,
                                   bool take_a_reference = false);

    static auto
    create_tuple (const std::vector<VariantBase>& children)
        -> VariantContainerBase;

    static auto
    create_tuple (const VariantBase& child) -> VariantContainerBase;

    static auto
    create_maybe (const VariantType& child_type, const VariantBase& child = {})
        -> VariantContainerBase;

    auto
    get_n_children () const -> gsize;

    auto
    get_child (VariantBase& child, gsize index = 0) const -> void;

    auto
    get_child (gsize index = 0) -> VariantBase;

    auto
    get_maybe (VariantBase& maybe) const -> bool;

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    get_iter (const VariantType& container_variant_type) const -> VariantIter;
#endif
  };

  template <>
  LIBMM_GLIB_SYMEXPORT auto
  VariantBase::cast_dynamic<VariantContainerBase> (const VariantBase& v) -> VariantContainerBase;

  template <class T>
  class Variant : public VariantBase
  {
  public:
    using CppType = T;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<VariantBase> : public VariantContainerBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Variant<VariantBase>;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = GVariant*;
    using CppType = VariantBase;
    using CppContainerType = Variant<VariantBase>;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const VariantBase& data) -> Variant<VariantBase>;

    auto
    get (VariantBase& variant) const -> void;

    auto
    get () const -> VariantBase;
  };

  template <class T>
  class Variant<Variant<T>> : public VariantContainerBase
  {
  public:
    using CType = GVariant*;
    using CppType = Variant<T>;
    using CppContainerType = Variant<CppType>;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const Variant<T>& data) -> Variant<Variant<T>>;

    auto
    get () const -> Variant<T>;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<Glib::ustring> : public VariantStringBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Variant<Glib::ustring>;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = char*;
    using CppType = Glib::ustring;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const Glib::ustring& data) -> Variant<Glib::ustring>;

    auto
    get () const -> Glib::ustring;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<Glib::DBusObjectPathString>
    : public VariantStringBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Variant<Glib::DBusObjectPathString>;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = char*;
    using CppType = Glib::DBusObjectPathString;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const CppType& data) -> Variant<CppType>;

    auto
    get () const -> CppType;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<Glib::DBusSignatureString> : public VariantStringBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Variant<Glib::DBusSignatureString>;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = char*;
    using CppType = Glib::DBusSignatureString;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const CppType& data) -> Variant<CppType>;

    auto
    get () const -> CppType;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<std::string> : public VariantStringBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Variant<std::string>;
    using BaseObjectType = GVariant;
#endif

  private:
  public:
    using CType = char*;
    using CppType = std::string;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::string& data) -> Variant<std::string>;

    auto
    get () const -> std::string;
  };

  template <class K, class V>
  class Variant<std::pair<K, V>> : public VariantContainerBase
  {
  public:
    using CppType = std::pair<K, V>;
    using CppContainerType = Variant<CppType>;

    Variant ()
      : VariantContainerBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantContainerBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::pair<K, V>& data) -> Variant<std::pair<K, V>>;

    auto
    get () const -> std::pair<K, V>;
  };

  template <class T>
  class Variant<std::vector<T>> : public VariantContainerBase
  {
  public:
    using CppType = T;
    using CppContainerType = std::vector<T>;

    Variant ()
      : VariantContainerBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantContainerBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::vector<T>& data) -> Variant<std::vector<T>>;

    auto
    get_child (gsize index) const -> T;

    auto
    get () const -> std::vector<T>;

    auto
    get_iter () const -> VariantIter;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<std::vector<Glib::ustring>>
    : public VariantContainerBase
  {
  public:
    using CppType = Glib::ustring;
    using CppContainerType = std::vector<Glib::ustring>;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::vector<Glib::ustring>& data)
        -> Variant<std::vector<Glib::ustring>>;

    auto
    get_child (gsize index) const -> Glib::ustring;

    auto
    get () const -> std::vector<Glib::ustring>;

    auto
    get_iter () const -> VariantIter;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<std::vector<Glib::DBusObjectPathString>>
    : public VariantContainerBase
  {
  public:
    using CppType = Glib::DBusObjectPathString;
    using CppContainerType = std::vector<Glib::DBusObjectPathString>;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const CppContainerType& data) -> Variant<CppContainerType>;

    auto
    get_child (gsize index) const -> CppType;

    auto
    get () const -> CppContainerType;

    auto
    get_iter () const -> VariantIter;
  };

  template <>
  class LIBMM_GLIB_SYMEXPORT Variant<std::vector<std::string>>
    : public VariantContainerBase
  {
  public:
    using CppType = std::string;
    using CppContainerType = std::vector<std::string>;

    Variant ();

    explicit Variant (GVariant* castitem, bool take_a_reference = false);

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::vector<std::string>& data)
        -> Variant<std::vector<std::string>>;

    static auto
    create_from_object_paths (const std::vector<std::string>& paths)
        -> Variant<std::vector<std::string>>;

    auto
    get_child (gsize index) const -> std::string;

    auto
    get () const -> std::vector<std::string>;

    auto
    get_iter () const -> VariantIter;
  };

  template <class K, class V>
  class Variant<std::map<K, V>> : public VariantContainerBase
  {
  public:
    using CppType = std::pair<K, V>;
    using CppContainerType = std::map<K, V>;

    Variant ()
      : VariantContainerBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantContainerBase (castitem, take_a_reference)
    {
    }

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    static auto
    create (const std::map<K, V>& data) -> Variant<std::map<K, V>>;

    auto
    get_child (gsize index) const -> std::pair<K, V>;

    auto
    lookup (const K& key, V& value) const -> bool;

    auto
    get () const -> std::map<K, V>;

    auto
    get_iter () const -> VariantIter;
  };

  template <class... Types>
  class Variant<std::tuple<Types...>> : public VariantContainerBase
  {
  public:
    using CppContainerType = std::tuple<Types...>;

    Variant ()
      : VariantContainerBase ()
    {
    }

    explicit Variant (GVariant* castitem, bool take_a_reference = false)
      : VariantContainerBase (castitem, take_a_reference)
    {
    }

    static auto
    create (const std::tuple<Types...>& data) -> Variant<std::tuple<Types...>>;

    static auto
    variant_type () -> const VariantType& G_GNUC_CONST;

    template <class T>
    auto
    get_child (gsize index) const -> T;

    template <class T>
    auto
    get_child_variant (gsize index) const -> Variant<T>;

    auto
    get () const -> std::tuple<Types...>;

    auto
    get_iter () const -> VariantIter;
  };

} // namespace Glib

#define _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H
#include <libmm-glib/variant_basictypes.hxx>
#undef _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H

namespace Glib
{

  template <class T>
  Variant<Variant<T>>::Variant ()
    : VariantContainerBase ()
  {
  }

  template <class T>
  Variant<Variant<T>>::Variant (GVariant* castitem, bool take_a_reference)
    : VariantContainerBase (castitem, take_a_reference)
  {
  }

  template <class T>
  auto
  Variant<Variant<T>>::variant_type () -> const VariantType&
  {
    return VARIANT_TYPE_VARIANT;
  }

  template <class T>
  auto
  Variant<Variant<T>>::create (const Variant<T>& data) -> Variant<Variant<T>>
  {
    Variant<Variant<T>> result = Variant<Variant<T>> (
        g_variant_new_variant (const_cast<GVariant*> (data.gobj ())));
    return result;
  }

  template <class T>
  auto
  Variant<Variant<T>>::get () const -> Variant<T>
  {
    GVariant* const gvariant = g_variant_get_variant (gobject_);
    return Variant<T> (gvariant);
  }

  template <class K, class V>
  auto
  Variant<std::pair<K, V>>::variant_type () -> const VariantType&
  {
    static VariantType type (
        g_variant_type_new_dict_entry (Variant<K>::variant_type ().gobj (),
                                       Variant<V>::variant_type ().gobj ()));

    return type;
  }

  template <class K, class V>
  auto
  Variant<std::pair<K, V>>::create (const std::pair<K, V>& data) -> Variant<std::pair<K, V>>
  {
    Variant<K> key = Variant<K>::create (data.first);
    Variant<V> value = Variant<V>::create (data.second);

    Variant<std::pair<K, V>> result = Variant<std::pair<K, V>> (
        g_variant_new_dict_entry (key.gobj (), value.gobj ()));

    return result;
  }

  template <class K, class V>
  auto
  Variant<std::pair<K, V>>::get () const -> std::pair<K, V>
  {
    Variant<K> key;
    VariantContainerBase::get_child (key, 0);

    Variant<V> value;
    VariantContainerBase::get_child (value, 1);

    std::pair<K, V> result (key.get (), value.get ());

    return result;
  }

  template <class T>
  auto
  Variant<std::vector<T>>::variant_type () -> const VariantType&
  {
    static VariantType type =
        VariantType::create_array (Variant<T>::variant_type ());

    return type;
  }

  template <class T>
  auto
  Variant<std::vector<T>>::create (const std::vector<T>& data) -> Variant<std::vector<T>>
  {
    VariantType array_variant_type = Variant<std::vector<T>>::variant_type ();

    GVariantBuilder* builder =
        g_variant_builder_new (array_variant_type.gobj ());

    for (const auto& element : data)
    {
      Glib::Variant<T> variant = Glib::Variant<T>::create (element);
      g_variant_builder_add_value (builder, variant.gobj ());
    }

    Variant<std::vector<T>> result = Variant<std::vector<T>> (g_variant_new (
        reinterpret_cast<const gchar*> (array_variant_type.gobj ()),
        builder));

    g_variant_builder_unref (builder);

    return result;
  }

  template <class T>
  auto
  Variant<std::vector<T>>::get_child (gsize index) const -> T
  {
    if (index >= get_n_children ())
      throw std::out_of_range (
          "Variant< std::vector<T> >::get_child(): Index out of bounds.");

    Glib::Variant<T> variant;

    GVariant* gvariant =
        g_variant_get_child_value (const_cast<GVariant*> (gobj ()), index);

    variant.init (gvariant);
    return variant.get ();
  }

  template <class T>
  auto
  Variant<std::vector<T>>::get () const -> std::vector<T>
  {
    std::vector<T> result;

    for (gsize i = 0, n_children = get_n_children (); i < n_children; ++i)
    {
      Glib::Variant<T> variant;

      GVariant* gvariant =
          g_variant_get_child_value (const_cast<GVariant*> (gobj ()), i);

      variant.init (gvariant);
      result.emplace_back (variant.get ());
    }

    return result;
  }

  template <class T>
  auto
  Variant<std::vector<T>>::get_iter () const -> VariantIter
  {
    return VariantContainerBase::get_iter (variant_type ());
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::variant_type () -> const VariantType&
  {
    static VariantType type =
        VariantType::create_array (Variant<std::pair<K, V>>::variant_type ());

    return type;
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::create (const std::map<K, V>& data) -> Variant<std::map<K, V>>
  {
    VariantType element_variant_type =
        Variant<std::pair<K, V>>::variant_type ();

    VariantType array_variant_type = Variant<std::map<K, V>>::variant_type ();

    GVariantBuilder* builder =
        g_variant_builder_new (array_variant_type.gobj ());

    for (const auto& element : data)
    {
      auto dict_entry = Variant<std::pair<K, V>>::create (element);

      g_variant_builder_add_value (builder, dict_entry.gobj ());
    }

    Variant<std::map<K, V>> result = Variant<std::map<K, V>> (g_variant_new (
        reinterpret_cast<const gchar*> (array_variant_type.gobj ()),
        builder));

    g_variant_builder_unref (builder);

    return result;
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::get_child (gsize index) const -> std::pair<K, V>
  {
    Variant<std::pair<K, V>> dict_entry;
    VariantContainerBase::get_child (dict_entry, index);
    return dict_entry.get ();
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::lookup (const K& key, V& value) const -> bool
  {
    VariantIter iter = get_iter ();

    Variant<std::pair<K, V>> entry;

    while (iter.next_value (entry))
    {
      std::pair<K, V> element = entry.get ();

      if (element.first == key)
      {
        value = element.second;
        return true;
      }
    }

    return false;
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::get () const -> std::map<K, V>
  {
    std::map<K, V> result;
    VariantIter iter = get_iter ();
    Variant<std::pair<K, V>> entry;

    while (iter.next_value (entry))
    {
      result.insert (entry.get ());
    }

    return result;
  }

  template <class K, class V>
  auto
  Variant<std::map<K, V>>::get_iter () const -> VariantIter
  {
    return VariantContainerBase::get_iter (variant_type ());
  }

  template <class... Types>
  auto
  Variant<std::tuple<Types...>>::variant_type () -> const VariantType&
  {
    std::vector<VariantType> types;
    auto expander = [&types] (const VariantType& type) mutable -> int
    {
      types.push_back (type);
      return 0;
    };

    using swallow = int[];
    (void) swallow{(expander (Variant<Types>::variant_type ()))...};
    static auto type = VariantType::create_tuple (types);

    return type;
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace detail
  {
    template <class Tuple, std::size_t... Is>
    auto
    expand_tuple (std::vector<VariantBase>& variants,
                  const Tuple& t,
                  std::index_sequence<Is...>) -> void
    {
      using swallow = int[];
      auto expander = [&variants] (const VariantBase& variant) -> int
      {
        variants.push_back (variant);
        return 0;
      };
      (void) swallow{(expander (
          Variant<typename std::tuple_element<Is, Tuple>::type>::create (
              std::get<Is> (t))))...};
    }
  } // namespace detail
#endif

  template <class... Types>
  auto
  Variant<std::tuple<Types...>>::create (const std::tuple<Types...>& data) -> Variant<std::tuple<Types...>>
  {
    std::vector<Glib::VariantBase> variants;
    detail::expand_tuple (variants, data, std::index_sequence_for<Types...>{});

    using var_ptr = GVariant*;
    auto var_array = std::make_unique<var_ptr[]> (sizeof...(Types));

    for (std::vector<VariantBase>::size_type i = 0; i < variants.size (); i++)
      var_array[i] = const_cast<GVariant*> (variants[i].gobj ());

    Variant<std::tuple<Types...>> result = Variant<std::tuple<Types...>> (
        g_variant_new_tuple (var_array.get (), variants.size ()));

    return result;
  }

  template <class... Types>
  template <class T>
  auto
  Variant<std::tuple<Types...>>::get_child (gsize index) const -> T
  {
    Variant<T> entry;
    VariantContainerBase::get_child (entry, index);
    return entry.get ();
  }

  template <class... Types>
  template <class T>
  auto
  Variant<std::tuple<Types...>>::get_child_variant (gsize index) const -> Variant<T>
  {
    Variant<T> entry;
    VariantContainerBase::get_child (entry, index);
    return entry;
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace detail
  {

    template <class T>
    constexpr auto
    any_arg (T&& arg) -> int
    {
      (void) arg;
      return 0;
    }

    template <class Tuple, std::size_t... Is>
    auto
    assign_tuple (std::vector<VariantBase>& variants,
                  Tuple& t,
                  std::index_sequence<Is...>) -> void
    {
      int i = 0;
      using swallow = int[];
      (void) swallow{(any_arg (
          std::get<Is> (t) =
              VariantBase::cast_dynamic<
                  Variant<typename std::tuple_element<Is, Tuple>::type>> (
                  variants[i++])
                  .get ()))...};
    }
  } // namespace detail
#endif

  template <class... Types>
  auto
  Variant<std::tuple<Types...>>::get () const -> std::tuple<Types...>
  {
    std::tuple<Types...> data;
    int i = 0;

    std::vector<VariantBase> variants;
    using swallow = int[];
    auto expander = [&variants, &i] (const VariantBase& variant) -> int
    {
      variants.push_back (variant);
      return i++;
    };
    (void) swallow{(expander (get_child_variant<Types> (i)))...};
    detail::assign_tuple (variants, data, std::index_sequence_for<Types...>{});

    return data;
  }

  template <class... Types>
  auto
  Variant<std::tuple<Types...>>::get_iter () const -> VariantIter
  {
    const auto type = variant_type ();
    return VariantContainerBase::get_iter (type);
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <>
  class LIBMM_GLIB_SYMEXPORT Value<Glib::VariantBase> : public ValueBase_Variant
  {
  public:
    using CppType = Glib::VariantBase;

    auto
    set (CppType data) -> void;
    auto
    get () const -> CppType;
  };
#endif

} // namespace Glib

namespace Glib
{

  inline auto
  swap (VariantBase& lhs, VariantBase& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Glib

namespace Glib
{

  LIBMM_GLIB_SYMEXPORT
  auto
  wrap (GVariant* object, bool take_copy = false) -> Glib::VariantBase;

} // namespace Glib

#endif
