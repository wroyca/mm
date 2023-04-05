// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gdk/wrap_init.hxx>
#include <libmm/gio/init.hxx>
#include <libmm/glib/init.hxx>
#include <libmm/gtk/init.hxx>
#include <libmm/gtk/wrap_init.hxx>
#include <libmm/pango/wrap_init.hxx>

namespace gtk
{

  auto
  init_gtkmm_internals () -> void
  {
    static bool init_done = false;

    if (!init_done)
    {
      glib::init ();
      gio::init ();

      pango::wrap_init ();
      gdk::wrap_init ();
      gtk::wrap_init ();

      init_done = true;
    }
  }

} // namespace gtk
