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
test_adw_button_content_icon_name (void)
{
  adw::ButtonContent content;

  notified = 0;
  content.property_icon_name ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring icon_name;

  icon_name = content.get_property<glib::ustring> ("icon-name");
  g_assert_true (icon_name == "");

  content.set_icon_name ("");
  g_assert_true (notified == 0);

  content.set_icon_name ("document-open-symbolic");
  g_assert_true (content.get_icon_name () == "document-open-symbolic");
  g_assert_true (notified == 1);

  content.set_property<glib::ustring> ("icon-name", "");
  g_assert_true (content.get_icon_name () == "");
  g_assert_true (notified == 2);
}

static void
test_adw_button_content_label (void)
{
  adw::ButtonContent content;

  notified = 0;
  content.property_label ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring label;

  label = content.get_property<glib::ustring> ("label");
  g_assert_true (label == "");

  content.set_label ("");
  g_assert_true (notified == 0);

  content.set_label ("Open");
  g_assert_true (content.get_label () == "Open");
  g_assert_true (notified == 1);

  content.set_property<glib::ustring> ("label", "");
  g_assert_true (content.get_label () == "");
  g_assert_true (notified == 2);
}

static void
test_adw_button_content_use_underline (void)
{
  adw::ButtonContent content;
  bool use_underline;

  notified = 0;
  content.property_use_underline ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  use_underline = content.get_property<bool> ("use-underline");
  g_assert_false (use_underline);

  content.set_use_underline (false);
  g_assert_true (notified == 0);

  content.set_use_underline (true);
  g_assert_true (content.get_use_underline ());
  g_assert_true (notified == 1);

  content.set_property<bool> ("use-underline", false);
  g_assert_false (content.get_use_underline ());
  g_assert_true (notified == 2);
}

static void
test_adw_button_content_style_class_button (void)
{
  gtk::Window window;
  gtk::Button button;
  adw::ButtonContent content;

  window.set_child (button);
  window.present ();

  button.set_child (content);
  g_assert_true (button.has_css_class ("image-text-button"));

  button.unset_child ();
  g_assert_false (button.has_css_class ("image-text-button"));
}

static void
test_adw_button_content_style_class_split_button (void)
{
  gtk::Window window;
  adw::SplitButton button;
  adw::ButtonContent content;

  window.set_child (button);
  window.present ();

  button.set_child (&content);
  g_assert_true (button.has_css_class ("image-text-button"));

  button.set_child (nullptr);
  g_assert_false (button.has_css_class ("image-text-button"));
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ButtonContent/icon_name",
                   test_adw_button_content_icon_name);
  g_test_add_func ("/Adwaita/ButtonContent/label",
                   test_adw_button_content_label);
  g_test_add_func ("/Adwaita/ButtonContent/use_underline",
                   test_adw_button_content_use_underline);
  g_test_add_func ("/Adwaita/ButtonContent/style_class_button",
                   test_adw_button_content_style_class_button);
  g_test_add_func ("/Adwaita/ButtonContent/style_class_split_button",
                   test_adw_button_content_style_class_split_button);

  return g_test_run ();
}
