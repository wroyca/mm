/*
 * Copyright (C) 2020 Alexander Mikhaylenko <alexm@gnome.org>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // Adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_window_new (void)
{
  std::unique_ptr<Gtk::Widget> window = std::make_unique<Gtk::Window> ();
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  Adw::init ();

  g_test_add_func ("/Adwaita/Window/new", test_adw_window_new);

  return g_test_run ();
}
