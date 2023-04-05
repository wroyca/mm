// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gtk/gtk.h>
#include <libmm/glib/utility.hxx>
#include <libmm/gtk/accelerator.hxx>

namespace gtk
{

  namespace Accelerator
  {

    auto
    valid (guint keyval, gdk::ModifierType modifiers) -> bool
    {
      return gtk_accelerator_valid (keyval, (GdkModifierType) modifiers);
    }

    auto
    parse (const glib::ustring& accelerator,
           guint& accelerator_key,
           gdk::ModifierType& accelerator_mods) -> bool
    {
      auto mods = GdkModifierType (0);
      const auto result =
          gtk_accelerator_parse (accelerator.c_str (), &accelerator_key, &mods);

      accelerator_mods = static_cast<gdk::ModifierType> (mods);
      return result;
    }

    auto
    name (guint accelerator_key, gdk::ModifierType accelerator_mods)
        -> glib::ustring
    {
      return glib::convert_return_gchar_ptr_to_ustring (gtk_accelerator_name (
          accelerator_key,
          static_cast<GdkModifierType> (accelerator_mods)));
    }

    auto
    get_label (guint accelerator_key, gdk::ModifierType accelerator_mods)
        -> glib::ustring
    {
      return glib::convert_return_gchar_ptr_to_ustring (
          gtk_accelerator_get_label (
              accelerator_key,
              static_cast<GdkModifierType> (accelerator_mods)));
    }

    auto
    get_default_mod_mask () -> gdk::ModifierType
    {
      return static_cast<gdk::ModifierType> (
          gtk_accelerator_get_default_mod_mask ());
    }

  } // namespace Accelerator

} // namespace gtk
