// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/adw/init.hxx>
#include <libmm/adw/wrap_init.hxx>
#include <libmm/gtk/init.hxx>

auto
adw::init () -> void
{
  gtk::init_gtkmm_internals ();
  wrap_init ();
}
