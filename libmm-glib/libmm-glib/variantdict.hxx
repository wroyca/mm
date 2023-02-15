// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_VARIANTDICT_H
#define _GLIBMM_VARIANTDICT_H

#include <libmm-glib/variant.hxx>

namespace Glib
{

  class GLIBMM_API VariantDict final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = VariantDict;
    using BaseObjectType = GVariantDict;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GVariantDict*;

    auto
    gobj () const -> const GVariantDict*;

    auto
    gobj_copy () const -> GVariantDict*;

    VariantDict () = delete;

    VariantDict (const VariantDict&) = delete;
    auto
    operator= (const VariantDict&) -> VariantDict& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (const VariantBase& from_asv) -> Glib::RefPtr<VariantDict>;

    static auto
    create () -> Glib::RefPtr<VariantDict>;

    auto
    lookup_value_variant (const Glib::ustring& key,
                          const VariantType& expected_type,
                          VariantBase& value) const -> bool;

    template <typename T_Value>
    auto
    lookup_value (const Glib::ustring& key, T_Value& value) const -> bool;

    auto
    contains (const Glib::ustring& key) const -> bool;

    auto
    insert_value_variant (const Glib::ustring& key, const VariantBase& value)
        -> void;

    template <typename T_Value>
    auto
    insert_value (const Glib::ustring& key, const T_Value& value) -> void;

    auto
    remove (const Glib::ustring& key) -> bool;

    auto
    clear () -> void;
  };

  template <typename T_Value>
  auto
  VariantDict::insert_value (const Glib::ustring& key, const T_Value& value) -> void
  {
    using type_glib_variant = Glib::Variant<T_Value>;

    return insert_value_variant (key, type_glib_variant::create (value));
  }

  template <typename T_Value>
  auto
  VariantDict::lookup_value (const Glib::ustring& key, T_Value& value) const -> bool
  {
    value = T_Value ();

    using type_glib_variant = Glib::Variant<T_Value>;

    Glib::VariantBase variantBase;
    const bool result = lookup_value_variant (
        key,
        type_glib_variant::variant_type (),
        variantBase);
    if (!result)
      return result;

    try
    {
      const type_glib_variant variantDerived =
          variantBase.cast_dynamic<type_glib_variant> (variantBase);
      value = variantDerived.get ();
    }
    catch (const std::bad_cast& ex)
    {
      return false;
    }

    return result;
  }

} // namespace Glib

namespace Glib
{

  GLIBMM_API
  auto
  wrap (GVariantDict* object, bool take_copy = false) -> Glib::RefPtr<Glib::VariantDict>;

} // namespace Glib

#endif
