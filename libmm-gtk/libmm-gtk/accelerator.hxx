#ifndef _GTKMM_ACCELERATOR_H
#define _GTKMM_ACCELERATOR_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-gdk/enums.hxx>
#include <libmm-glib/ustring.hxx>

namespace Gtk::Accelerator
{

  GTKMM_API
  auto
  valid (guint keyval, Gdk::ModifierType modifiers) -> bool;

  GTKMM_API
  auto
  parse (const Glib::ustring& accelerator,
         guint& accelerator_key,
         Gdk::ModifierType& accelerator_mods) -> bool;

  GTKMM_API
  auto
  name (guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring;

  GTKMM_API
  auto
  get_label (guint accelerator_key, Gdk::ModifierType accelerator_mods) -> Glib::ustring;

  GTKMM_API
  auto
  get_default_mod_mask () -> Gdk::ModifierType;

} // namespace Gtk::Accelerator
#endif
