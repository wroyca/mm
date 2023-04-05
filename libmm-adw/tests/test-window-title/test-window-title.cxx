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
test_adw_window_title_title (void)
{
  adw::WindowTitle window_title ("Some title", "");

  notified = 0;
  window_title.property_title ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring title = window_title.get_property<glib::ustring> ("title");
  g_assert_true (title == "Some title");

  window_title.set_title ("Some title");
  g_assert_true (notified == 0);

  window_title.set_title ("Another title");
  g_assert_true (window_title.get_title () == "Another title");
  g_assert_true (notified == 1);

  window_title.set_property<glib::ustring> ("title", "Yet another title");
  g_assert_true (window_title.get_title () == "Yet another title");
  g_assert_true (notified == 2);
}

static void
test_adw_window_title_subtitle (void)
{
  adw::WindowTitle window_title ("", "Some subtitle");

  notified = 0;
  window_title.property_subtitle ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring subtitle =
      window_title.get_property<glib::ustring> ("subtitle");
  g_assert_true (subtitle == "Some subtitle");

  window_title.set_subtitle ("Some subtitle");
  g_assert_true (notified == 0);

  window_title.set_subtitle ("Another subtitle");
  g_assert_true (window_title.get_subtitle () == "Another subtitle");
  g_assert_true (notified == 1);

  window_title.set_property<glib::ustring> ("subtitle", "Yet another subtitle");
  g_assert_true (window_title.get_subtitle () == "Yet another subtitle");
  g_assert_true (notified == 2);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/WindowTitle/title", test_adw_window_title_title);
  g_test_add_func ("/Adwaita/WindowTitle/subtitle",
                   test_adw_window_title_subtitle);

  return g_test_run ();
}
