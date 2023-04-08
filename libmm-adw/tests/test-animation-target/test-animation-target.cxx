/*
 * Copyright (C) 2022 George Barrett <bob@bob131.so>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_property_animation_target_construct (void)
{
  auto widget = glib::RefPtr<gtk::Button> (new gtk::Button ());

  auto named_target = adw::property_animation_target::create (widget, "opacity");

  GParamSpec* target_pspec = named_target->get_pspec ();
  g_assert_true (target_pspec);
  g_assert_true (glib::ustring (target_pspec->name) == "opacity");

  auto pspec_target = adw::property_animation_target::create (widget,
                                                            target_pspec);
  g_assert_true (pspec_target->get_pspec () == target_pspec);

  target_pspec = pspec_target->get_pspec ();
  g_assert_true (target_pspec);
  g_assert_true (glib::ustring (target_pspec->name) == "opacity");
}

static void
test_adw_property_animation_target_basic (void)
{
  auto widget = glib::RefPtr<gtk::Button> (new gtk::Button ());

  auto target = adw::property_animation_target::create (widget, "opacity");
  auto animation = adw::timed_animation::create (widget.get (), 1, 0, 0, target);

  g_assert_true (widget->get_opacity () == 1);

  animation->play ();
  g_assert_true (widget->get_opacity () == 0);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/PropertyAnimationTarget/construct",
                   test_adw_property_animation_target_construct);
  g_test_add_func ("/Adwaita/PropertyAnimationTarget/basic",
                   test_adw_property_animation_target_basic);

  return g_test_run ();
}
