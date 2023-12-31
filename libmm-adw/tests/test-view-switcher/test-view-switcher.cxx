/*
 * Copyright (C) 2019 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_view_switcher_policy (void)
{
  adw::view_switcher view_switcher;

  g_assert_true (view_switcher.get_policy () ==
                 adw::view_switcher_policy::NARROW);

  view_switcher.set_policy (adw::view_switcher_policy::WIDE);
  g_assert_true (view_switcher.get_policy () == adw::view_switcher_policy::WIDE);

  view_switcher.set_policy (adw::view_switcher_policy::NARROW);
  g_assert_true (view_switcher.get_policy () ==
                 adw::view_switcher_policy::NARROW);
}

static void
test_adw_view_switcher_stack (void)
{
  adw::view_switcher view_switcher;
  adw::view_stack* view_stack = gtk::make_managed<adw::view_stack> ();

  g_assert_true (view_switcher.get_stack () == nullptr);

  view_switcher.set_stack (view_stack);
  g_assert_true (view_switcher.get_stack () == view_stack);

  view_switcher.set_stack (nullptr);
  g_assert_true (view_switcher.get_stack () == nullptr);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ViewSwitcher/policy",
                   test_adw_view_switcher_policy);
  g_test_add_func ("/Adwaita/ViewSwitcher/stack", test_adw_view_switcher_stack);

  return g_test_run ();
}
