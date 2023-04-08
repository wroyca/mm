/*
 * Copyright (C) 2019 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

static void
test_adw_view_switcher_bar_stack (void)
{
  adw::view_switcher_bar bar;
  adw::view_stack* stack = gtk::make_managed<adw::view_stack> ();

  bar.set_stack (stack);
  g_assert_true (bar.get_stack () == stack);

  bar.set_stack (nullptr);
  g_assert_true (bar.get_stack () == nullptr);
}

static void
test_adw_view_switcher_bar_reveal (void)
{
  adw::view_switcher_bar bar;

  g_assert_false (bar.get_reveal ());

  bar.set_reveal (true);
  g_assert_true (bar.get_reveal ());

  bar.set_reveal (false);
  g_assert_false (bar.get_reveal ());
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ViewSwitcherBar/stack",
                   test_adw_view_switcher_bar_stack);
  g_test_add_func ("/Adwaita/ViewSwitcherBar/reveal",
                   test_adw_view_switcher_bar_reveal);

  return g_test_run ();
}
