// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gtk/gtk.h>
#include <libmm-glib/utility.hxx>
#include <libmm-gtk/accelerator.hxx>

namespace Gtk
{

  namespace Accelerator
  {

    auto
    valid (guint keyval, Gdk::ModifierType modifiers) -> bool
    {
      return gtk_accelerator_valid (keyval, (GdkModifierType) modifiers);
    }

    auto
    parse (const Glib::ustring& accelerator,
           guint& accelerator_key,
           Gdk::ModifierType& accelerator_mods) -> bool
    {
      auto mods = GdkModifierType (0);
      const auto result =
          gtk_accelerator_parse (accelerator.c_str (), &accelerator_key, &mods);

      accelerator_mods = static_cast<Gdk::ModifierType> (mods);
      return result;
    }

    auto
    name (guint accelerator_key, Gdk::ModifierType accelerator_mods)
        -> Glib::ustring
    {
      return Glib::convert_return_gchar_ptr_to_ustring (gtk_accelerator_name (
          accelerator_key,
          static_cast<GdkModifierType> (accelerator_mods)));
    }

    auto
    get_label (guint accelerator_key, Gdk::ModifierType accelerator_mods)
        -> Glib::ustring
    {
      return Glib::convert_return_gchar_ptr_to_ustring (
          gtk_accelerator_get_label (
              accelerator_key,
              static_cast<GdkModifierType> (accelerator_mods)));
    }

    auto
    get_default_mod_mask () -> Gdk::ModifierType
    {
      return static_cast<Gdk::ModifierType> (
          gtk_accelerator_get_default_mod_mask ());
    }

  } // namespace Accelerator

} // namespace Gtk
