// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/variantdict.hxx>
#include <libmm/glib/variantdict_p.hxx>

#include <glib.h>

namespace Glib
{

  auto
  VariantDict::lookup_value_variant (const ustring& key,
                                     const VariantType& expected_type,
                                     VariantBase& value) const -> bool
  {
    const GVariant* const g_value = g_variant_dict_lookup_value (
        const_cast<GVariantDict*> (gobj ()),
        key.c_str (),
        expected_type.gobj ());
    if (!g_value)
      return false;

    value.init (g_value);
    return true;
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GVariantDict* object, const bool take_copy) -> RefPtr<VariantDict>
  {
    if (take_copy && object)
      g_variant_dict_ref (object);

    return Glib::make_refptr_for_instance<VariantDict> (
        reinterpret_cast<VariantDict*> (object));
  }

} // namespace Glib

namespace Glib
{

  auto
  VariantDict::reference () const -> void
  {
    g_variant_dict_ref (
        reinterpret_cast<GVariantDict*> (const_cast<VariantDict*> (this)));
  }

  auto
  VariantDict::unreference () const -> void
  {
    g_variant_dict_unref (
        reinterpret_cast<GVariantDict*> (const_cast<VariantDict*> (this)));
  }

  auto
  VariantDict::gobj () -> GVariantDict*
  {
    return reinterpret_cast<GVariantDict*> (this);
  }

  auto
  VariantDict::gobj () const -> const GVariantDict*
  {
    return reinterpret_cast<const GVariantDict*> (this);
  }

  auto
  VariantDict::gobj_copy () const -> GVariantDict*
  {
    const auto gobject =
        reinterpret_cast<GVariantDict*> (const_cast<VariantDict*> (this));
    g_variant_dict_ref (gobject);
    return gobject;
  }

  auto
  VariantDict::create (const VariantBase& from_asv) -> RefPtr<VariantDict>
  {
    return wrap (g_variant_dict_new (const_cast<GVariant*> (from_asv.gobj ())));
  }

  auto
  VariantDict::create () -> RefPtr<VariantDict>
  {
    return wrap (g_variant_dict_new (nullptr));
  }

  auto
  VariantDict::contains (const ustring& key) const -> bool
  {
    return g_variant_dict_contains (const_cast<GVariantDict*> (gobj ()),
                                    key.c_str ());
  }

  auto
  VariantDict::insert_value_variant (const ustring& key,
                                     const VariantBase& value) -> void
  {
    g_variant_dict_insert_value (gobj (),
                                 key.c_str (),
                                 const_cast<GVariant*> (value.gobj ()));
  }

  auto
  VariantDict::remove (const ustring& key) -> bool
  {
    return g_variant_dict_remove (gobj (), key.c_str ());
  }

  auto
  VariantDict::clear () -> void
  {
    g_variant_dict_clear (gobj ());
  }

} // namespace Glib
