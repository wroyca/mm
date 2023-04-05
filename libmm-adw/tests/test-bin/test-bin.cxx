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
notify_cb (void)
{
  notified++;
}

static void
test_adw_bin_child (void)
{
  adw::Bin bin;

  notified = 0;
  bin.property_child ().signal_changed ().connect (sigc::ptr_fun (notify_cb));

  gtk::Widget* widget = bin.get_property<gtk::Widget*> ("child");
  g_assert_null (widget);

  bin.set_child (nullptr);
  g_assert_true (notified == 0);

  widget = gtk::make_managed<gtk::Button> ();
  bin.set_child (widget);
  g_assert_true (bin.get_child () == widget);
  g_assert_true (notified == 1);

  bin.set_property<gtk::Widget*> ("child", nullptr);
  g_assert_true (notified == 2);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/Bin/child", test_adw_bin_child);

  return g_test_run ();
}
