/*
 * Copyright (C) 2021 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Author: Alexander Mikhaylenko <alexander.mikhaylenko@puri.sm>
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

int notified;

static void
notify_cb ()
{
  notified++;
}

static void
test_adw_style_manager_color_scheme (void)
{
  glib::RefPtr<adw::StyleManager> manager = adw::StyleManager::get_default ();
  adw::ColorScheme color_scheme;

  notified = 0;
  sigc::connection conn =
      manager->property_color_scheme ().signal_changed ().connect (
          sigc::ptr_fun (notify_cb));

  color_scheme = manager->get_property<adw::ColorScheme> ("color-scheme");
  g_assert_true (color_scheme == adw::ColorScheme::DEFAULT);
  g_assert_true (notified == 0);

  manager->set_color_scheme (adw::ColorScheme::DEFAULT);
  g_assert_true (notified == 0);

  manager->set_color_scheme (adw::ColorScheme::PREFER_DARK);
  color_scheme = manager->get_property<adw::ColorScheme> ("color-scheme");
  g_assert_true (color_scheme == adw::ColorScheme::PREFER_DARK);
  g_assert_true (notified == 1);

  manager->set_property<adw::ColorScheme> ("color-scheme",
                                           adw::ColorScheme::PREFER_LIGHT);
  g_assert_true (manager->get_color_scheme () ==
                 adw::ColorScheme::PREFER_LIGHT);
  g_assert_true (notified == 2);

  conn.disconnect ();
  manager->set_color_scheme (adw::ColorScheme::DEFAULT);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/StyleManager/color_scheme",
                   test_adw_style_manager_color_scheme);

  return g_test_run ();
}
