/*
 * Copyright (C) 2020 Andrei Lișiță <andreii.lisita@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
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
test_adw_status_page_icon_name (void)
{
  adw::status_page status_page;

  notified = 0;
  status_page.property_icon_name ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring icon_name =
      status_page.get_property<glib::ustring> ("icon-name");
  g_assert_true (icon_name == "");

  status_page.set_icon_name ("");
  g_assert_true (notified == 0);

  status_page.set_icon_name ("some-icon-symbolic");
  g_assert_true (status_page.get_icon_name () == "some-icon-symbolic");
  g_assert_true (notified == 1);

  status_page.set_property<glib::ustring> ("icon-name", "other-icon-symbolic");
  g_assert_true (status_page.get_icon_name () == "other-icon-symbolic");
  g_assert_true (notified == 2);
}

static void
test_adw_status_page_title (void)
{
  adw::status_page status_page;

  notified = 0;
  status_page.property_title ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring title = status_page.get_property<glib::ustring> ("title");
  g_assert_true (title == "");

  status_page.set_title ("");
  g_assert_true (notified == 0);

  status_page.set_title ("Some Title");
  g_assert_true (status_page.get_title () == "Some Title");
  g_assert_true (notified == 1);

  status_page.set_property<glib::ustring> ("title", "Other Title");
  g_assert_true (status_page.get_title () == "Other Title");
  g_assert_true (notified == 2);
}

static void
test_adw_status_page_description (void)
{
  adw::status_page status_page;

  notified = 0;
  status_page.property_description ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring description =
      status_page.get_property<glib::ustring> ("description");
  g_assert_true (description == "");

  status_page.set_description ("");
  g_assert_true (notified == 0);

  status_page.set_description ("Some description");
  g_assert_true (status_page.get_description () == "Some description");
  g_assert_true (notified == 1);

  status_page.set_property<glib::ustring> ("description", "Other description");
  g_assert_true (status_page.get_description () == "Other description");
  g_assert_true (notified == 2);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/StatusPage/icon_name",
                   test_adw_status_page_icon_name);
  g_test_add_func ("/Adwaita/StatusPage/title", test_adw_status_page_title);
  g_test_add_func ("/Adwaita/StatusPage/description",
                   test_adw_status_page_description);

  return g_test_run ();
}
