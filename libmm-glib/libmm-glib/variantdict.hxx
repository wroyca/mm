
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

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

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

    void
    insert_value_variant (const Glib::ustring& key, const VariantBase& value);

    template <typename T_Value>
    void
    insert_value (const Glib::ustring& key, const T_Value& value);

    auto
    remove (const Glib::ustring& key) -> bool;

    void
    clear ();
  };

  template <typename T_Value>
  void
  VariantDict::insert_value (const Glib::ustring& key, const T_Value& value)
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
