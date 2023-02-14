// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACCELKEY_H
#define _GTKMM_ACCELKEY_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <gdk/gdkkeysyms.h>
#include <libmm-gdk/enums.hxx>

namespace Gtk
{

  class GTKMM_API AccelKey
  {
  public:
    AccelKey ();

    AccelKey (guint accel_key,
              Gdk::ModifierType accel_mods,
              const Glib::ustring& accel_path = {});

    AccelKey (const Glib::ustring& accelerator,
              const Glib::ustring& accel_path = {});

    AccelKey (const AccelKey& src);

    auto
    operator= (const AccelKey& src) -> AccelKey&;

    auto
    is_null () const -> bool;

    auto
    get_key () const -> guint;

    auto
    get_mod () const -> Gdk::ModifierType;

    auto
    get_path () const -> Glib::ustring;

    auto
    get_abbrev () const -> Glib::ustring;

  protected:
    guint key_;
    Gdk::ModifierType mod_;
    Glib::ustring path_;
  };

} // namespace Gtk

#endif
