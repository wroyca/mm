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
test_adw_toast_title (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_title ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring title = toast->get_property<glib::ustring> ("title");
  g_assert_true (title == "Title");

  toast->set_title ("Another title");
  g_assert_true (toast->get_title () == "Another title");
  g_assert_true (notified == 1);

  toast->set_property<glib::ustring> ("title", "Title");
  g_assert_true (toast->get_title () == "Title");
  g_assert_true (notified == 2);
}

static void
test_adw_toast_button_label (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  g_assert_nonnull (toast);

  notified = 0;
  toast->property_button_label ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring button_label =
      toast->get_property<glib::ustring> ("button-label");
  g_assert_true (button_label == "");

  toast->set_button_label ("Button");
  g_assert_true (toast->get_button_label () == "Button");
  g_assert_true (notified == 1);

  toast->set_property<glib::ustring> ("button-label", "Button 2");
  g_assert_true (toast->get_button_label () == "Button 2");
  g_assert_true (notified == 2);
}

static void
test_adw_toast_action_name (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_action_name ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring action_name =
      toast->get_property<glib::ustring> ("action-name");
  g_assert_true (action_name == "");

  toast->set_action_name ("win.something");
  g_assert_true (toast->get_action_name () == "win.something");
  g_assert_true (notified == 1);

  toast->set_property<glib::ustring> ("action-name", "win.something-else");
  g_assert_true (toast->get_action_name () == "win.something-else");
  g_assert_true (notified == 2);
}

static void
test_adw_toast_action_target (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_action_target ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::VariantBase action_target =
      toast->get_property<glib::VariantBase> ("action-target");
  g_assert_false (action_target);

  glib::VariantBase variant = glib::Variant<gint32>::create (1);
  toast->set_action_target_value (glib::Variant<gint32>::create (1));
  g_assert_true (toast->get_action_target_value () == variant);
  g_assert_true (notified == 1);

  variant = glib::Variant<gint32>::create (2);
  toast->set_property<glib::VariantBase> ("action-target",
                                          glib::Variant<gint32>::create (2));
  g_assert_true (toast->get_action_target_value () == variant);
  g_assert_true (notified == 2);
}

static void
test_adw_toast_detailed_action_name (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  g_assert_true (toast->get_action_name () == "");
  g_assert_false (toast->get_action_target_value ());

  toast->set_detailed_action_name ("win.something");
  g_assert_true (toast->get_action_name () == "win.something");
  g_assert_false (toast->get_action_target_value ());

  toast->set_detailed_action_name ("win.something(2)");
  g_assert_true (toast->get_action_name () == "win.something");
  glib::VariantBase variant = glib::Variant<gint32>::create (2);
  g_assert_true (toast->get_action_target_value () == variant);
}

static void
test_adw_toast_priority (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_priority ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  adw::ToastPriority priority =
      toast->get_property<adw::ToastPriority> ("priority");
  g_assert_true (priority == adw::ToastPriority::NORMAL);

  toast->set_priority (adw::ToastPriority::HIGH);
  g_assert_true (toast->get_priority () == adw::ToastPriority::HIGH);
  g_assert_true (notified == 1);

  toast->set_property<adw::ToastPriority> ("priority",
                                           adw::ToastPriority::NORMAL);
  g_assert_true (toast->get_priority () == adw::ToastPriority::NORMAL);
  g_assert_true (notified == 2);
}

static void
test_adw_toast_timeout (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_timeout ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  guint timeout = toast->get_property<guint> ("timeout");
  g_assert_true (timeout == 5);

  toast->set_timeout (10);
  g_assert_true (toast->get_timeout () == 10);
  g_assert_true (notified == 1);

  toast->set_property<guint> ("timeout", 5);
  g_assert_true (toast->get_timeout () == 5);
  g_assert_true (notified == 2);
}

static void
test_adw_toast_dismiss (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");
  adw::ToastOverlay overlay;

  // This is not obvious: dismiss will emit the "dismiss" signal. When a toast
  // is added to an overlay, it stays in a queue until dismissed. At that point
  // the overlay won't own the reference to the toast anymore, so the toast
  // would be freed.
  // Avoid this if we want to keep using the toast after calling dismiss.
  toast->reference ();
  overlay.add_toast (toast.get ());
  toast->dismiss ();

  /* Repeat dismiss() calls should no-op */
  toast->reference ();
  overlay.add_toast (toast.get ());
  toast->dismiss ();
  toast->dismiss ();
  toast->dismiss ();
}

static void
test_adw_toast_custom_title (void)
{
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("Title");

  notified = 0;
  toast->property_custom_title ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  glib::ustring title = toast->get_property<glib::ustring> ("title");
  g_assert_true (title == "Title");
  gtk::Widget* widget = toast->get_property<gtk::Widget*> ("custom-title");
  g_assert_true (widget == nullptr);

  toast->set_title ("Another title");
  g_assert_true (notified == 0);

  widget = gtk::make_managed<gtk::Button> ("Custom title");
  toast->set_custom_title (widget);
  g_assert_true (toast->get_custom_title () == widget);
  g_assert_true (toast->get_title () == "");
  g_assert_true (notified == 1);

  toast->set_title ("Final title");
  g_assert_true (toast->get_custom_title () == nullptr);
  g_assert_true (toast->get_title () == "Final title");
  g_assert_true (notified == 2);
}

static void
test_adw_toast_custom_title_overlay (void)
{
  adw::ToastOverlay first_overlay;
  adw::ToastOverlay second_overlay;
  std::unique_ptr<gtk::Widget> widget =
      std::make_unique<gtk::Label> ("Custom title");
  std::unique_ptr<adw::Toast> toast = std::make_unique<adw::Toast> ("");

  toast->set_custom_title (widget.get ());

  toast->reference ();
  first_overlay.add_toast (toast.get ());
  toast->dismiss ();

  toast->reference ();
  second_overlay.add_toast (toast.get ());
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/Toast/title", test_adw_toast_title);
  g_test_add_func ("/Adwaita/Toast/button_label", test_adw_toast_button_label);
  g_test_add_func ("/Adwaita/Toast/action_name", test_adw_toast_action_name);
  g_test_add_func ("/Adwaita/Toast/action_target",
                   test_adw_toast_action_target);
  g_test_add_func ("/Adwaita/Toast/detailed_action_name",
                   test_adw_toast_detailed_action_name);
  g_test_add_func ("/Adwaita/Toast/priority", test_adw_toast_priority);
  g_test_add_func ("/Adwaita/Toast/timeout", test_adw_toast_timeout);
  g_test_add_func ("/Adwaita/Toast/dismiss", test_adw_toast_dismiss);
  g_test_add_func ("/Adwaita/Toast/custom_title", test_adw_toast_custom_title);
  g_test_add_func ("/Adwaita/Toast/custom_title_overlay",
                   test_adw_toast_custom_title_overlay);

  return g_test_run ();
}
