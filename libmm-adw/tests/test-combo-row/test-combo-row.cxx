/*
 * Copyright (C) 2018 Purism SPC
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
test_adw_combo_row_set_for_enum (void)
{
  adw::combo_row row;
  glib::RefPtr<gtk::Expression<glib::ustring>> expr;
  glib::RefPtr<gio::ListModel> model;
  glib::RefPtr<adw::enum_list_item> item;

  g_assert_true (row.get_model () == nullptr);

  expr = gtk::PropertyExpression<glib::ustring>::create (
      adw::enum_list_item::get_type (),
      "nick");
  row.set_expression (expr);

  // Enums don't have a way to retrieve its GType in gtkmm.
  model = adw::enum_list_model::create (GTK_TYPE_ORIENTATION);
  row.set_model (model);

  model = row.get_model ();
  g_assert_true (model != nullptr);

  g_assert_true (model->get_n_items () == 2);

  item = std::dynamic_pointer_cast<adw::enum_list_item> (model->get_object (0));
  g_assert_true (item != nullptr);
  g_assert_true (item->get_nick () == "horizontal");

  item = std::dynamic_pointer_cast<adw::enum_list_item> (model->get_object (1));
  g_assert_true (item != nullptr);
  g_assert_true (item->get_nick () == "vertical");
}

static void
test_adw_combo_row_selected (void)
{
  adw::combo_row row;
  glib::RefPtr<gio::ListModel> model;
  int selected = 0;

  notified = 0;
  row.property_selected ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  selected = row.get_property<int> ("selected");
  g_assert_true (selected == -1);

  row.set_selected (-1);
  g_assert_true (notified == 0);

  // Enums don't have a way to retrieve its GType in gtkmm.
  model = adw::enum_list_model::create (GTK_TYPE_SELECTION_MODE);
  row.set_model (model);

  g_assert_true (row.get_selected () == 0);
  g_assert_true (notified == 1);

  row.set_selected (3);
  g_assert_true (row.get_selected () == 3);
  g_assert_true (notified == 2);

  row.set_property<int> ("selected", 1);
  g_assert_true (row.get_selected () == 1);
  g_assert_true (notified == 3);
}

static void
test_adw_combo_row_use_subtitle (void)
{
  adw::combo_row row;

  notified = 0;
  row.property_use_subtitle ().signal_changed ().connect (
      sigc::ptr_fun (notify_cb));

  g_assert_false (row.get_use_subtitle ());

  row.set_use_subtitle (false);
  g_assert_true (notified == 0);

  row.set_use_subtitle (true);
  g_assert_true (row.get_use_subtitle ());
  g_assert_true (notified == 1);

  row.set_property<bool> ("use-subtitle", false);
  bool use_subtitle = row.get_property<bool> ("use-subtitle");
  g_assert_false (use_subtitle);
  g_assert_true (notified == 2);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/ComboRow/set_for_enum",
                   test_adw_combo_row_set_for_enum);
  g_test_add_func ("/Adwaita/ComboRow/selected", test_adw_combo_row_selected);
  g_test_add_func ("/Adwaita/ComboRow/use_subtitle",
                   test_adw_combo_row_use_subtitle);

  return g_test_run ();
}
