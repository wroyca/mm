// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACCELKEY_H
#define _GTKMM_ACCELKEY_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <gdk/gdkkeysyms.h>
#include <libmm/gdk/enums.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AccelKey
  {
  public:
    AccelKey ();

    AccelKey (guint accel_key,
              gdk::ModifierType accel_mods,
              const glib::ustring& accel_path = {});

    AccelKey (const glib::ustring& accelerator,
              const glib::ustring& accel_path = {});

    AccelKey (const AccelKey& src);

    auto
    operator= (const AccelKey& src) -> AccelKey&;

    auto
    is_null () const -> bool;

    auto
    get_key () const -> guint;

    auto
    get_mod () const -> gdk::ModifierType;

    auto
    get_path () const -> glib::ustring;

    auto
    get_abbrev () const -> glib::ustring;

  protected:
    guint key_;
    gdk::ModifierType mod_;
    glib::ustring path_;
  };

} // namespace gtk

#endif
