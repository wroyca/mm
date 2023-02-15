// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACCELERATOR_H
#define _GTKMM_ACCELERATOR_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-gdk/enums.hxx>
#include <libmm-glib/ustring.hxx>

namespace Gtk
{

  namespace Accelerator
  {
    LIBMM_GTK_SYMEXPORT auto
    valid (guint keyval, Gdk::ModifierType modifiers) -> bool;

    LIBMM_GTK_SYMEXPORT auto
    parse (const Glib::ustring& accelerator,
           guint& accelerator_key,
           Gdk::ModifierType& accelerator_mods) -> bool;

    LIBMM_GTK_SYMEXPORT auto
    name (guint accelerator_key, Gdk::ModifierType accelerator_mods)
        -> Glib::ustring;

    LIBMM_GTK_SYMEXPORT auto
    get_label (guint accelerator_key, Gdk::ModifierType accelerator_mods)
        -> Glib::ustring;

    LIBMM_GTK_SYMEXPORT auto
    get_default_mod_mask () -> Gdk::ModifierType;

  } // namespace Accelerator

} // namespace Gtk
#endif
