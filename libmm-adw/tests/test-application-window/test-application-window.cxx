/*
 * Copyright (C) 2020 Alexander Mikhaylenko <alexm@gnome.org>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_application_window_new (void)
{
  glib::RefPtr<gtk::Application> app; // none
  adw::application_window window (app);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ApplicationWindow/new",
                   test_adw_application_window_new);

  return g_test_run ();
}
