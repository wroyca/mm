/*
 * Copyright (C) 2021 Maximiliano Sandoval <msandova@gnome.org>
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
test_adw_toast_overlay_child (void)
{
  adw::toast_overlay toast_overlay;

  notified = 0;
  toast_overlay.property_child ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  gtk::Widget* widget = toast_overlay.get_property<gtk::Widget*> ("child");
  g_assert_true (widget == nullptr);

  toast_overlay.set_child (nullptr);
  g_assert_true (notified == 0);

  widget = gtk::make_managed<gtk::Button> ();
  toast_overlay.set_child (widget);
  g_assert_true (toast_overlay.get_child () == widget);
  g_assert_true (notified == 1);

  toast_overlay.set_property<gtk::Widget*> ("child", nullptr);
  g_assert_true (toast_overlay.get_child () == nullptr);
  g_assert_true (notified == 2);
}

static void
test_adw_toast_overlay_add_toast (void)
{
  adw::toast_overlay toast_overlay;
  std::unique_ptr<adw::toast> toast =
      std::make_unique<adw::toast> ("Test Notification");

  toast->reference ();
  toast_overlay.add_toast (toast.get ());
  toast->reference ();
  toast_overlay.add_toast (toast.get ());
  toast->reference ();
  toast_overlay.add_toast (toast.get ());
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ToastOverlay/child", test_adw_toast_overlay_child);
  g_test_add_func ("/Adwaita/ToastOverlay/add_toast",
                   test_adw_toast_overlay_add_toast);

  return g_test_run ();
}
