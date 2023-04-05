/*
 * Copyright (C) 2019 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_preferences_window_add_remove (void)
{
  adw::PreferencesWindow window;
  adw::PreferencesPage page;

  window.add (&page);
  window.remove (&page);
}

static void
test_adw_preferences_window_add_toast (void)
{
  adw::PreferencesWindow window;
  adw::Toast* toast = new adw::Toast ("Test notification");
  window.add_toast (toast);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/PreferencesWindow/add_remove",
                   test_adw_preferences_window_add_remove);
  g_test_add_func ("/Adwaita/PreferencesWindow/add_toast",
                   test_adw_preferences_window_add_toast);

  return g_test_run ();
}
