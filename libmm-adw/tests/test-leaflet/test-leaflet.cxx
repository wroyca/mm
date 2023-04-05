/*
 * Copyright (C) 2020 Alexander Mikhaylenko <alexm@gnome.org>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include <libmm/adw/init.hxx> // adw::init
#include <libmm/adw/mm-adw.hxx>

#include <array>

static void
assert_page_position (glib::RefPtr<gtk::SelectionModel> pages,
                      gtk::Widget* widget,
                      int position)
{
  glib::RefPtr<gio::ListModel> list_model =
      std::dynamic_pointer_cast<gio::ListModel> (pages);
  g_assert_true (list_model != nullptr);

  glib::RefPtr<adw::LeafletPage> page =
      std::dynamic_pointer_cast<adw::LeafletPage> (
          list_model->get_object (position));
  g_assert_true (page != nullptr);

  g_assert_true (widget->gobj () == page->get_child ()->gobj ());
}

static void
test_adw_leaflet_adjacent_child (void)
{
  adw::Leaflet leaflet;
  std::array<gtk::Widget*, 3> children;

  for (int i = 0; i < 3; i++)
  {
    children[i] = gtk::make_managed<gtk::Button> ();

    glib::RefPtr<adw::LeafletPage> page = leaflet.append (children[i]);

    if (i == 1)
      page->set_navigatable (false);
  }

  leaflet.set_visible_child (children[0]);

  gtk::Widget* result =
      leaflet.get_adjacent_child (adw::NavigationDirection::BACK);
  g_assert_null (result);

  result = leaflet.get_adjacent_child (adw::NavigationDirection::FORWARD);
  g_assert_true (result->gobj () == children[2]->gobj ());

  leaflet.set_visible_child (children[1]);

  result = leaflet.get_adjacent_child (adw::NavigationDirection::BACK);
  g_assert_true (result->gobj () == children[0]->gobj ());

  result = leaflet.get_adjacent_child (adw::NavigationDirection::FORWARD);
  g_assert_true (result->gobj () == children[2]->gobj ());

  leaflet.set_visible_child (children[2]);

  result = leaflet.get_adjacent_child (adw::NavigationDirection::BACK);
  g_assert_true (result->gobj () == children[0]->gobj ());

  result = leaflet.get_adjacent_child (adw::NavigationDirection::FORWARD);
  g_assert_null (result);
}

static void
test_adw_leaflet_navigate (void)
{
  adw::Leaflet leaflet;
  std::array<gtk::Widget*, 3> children;

  bool result = leaflet.navigate (adw::NavigationDirection::BACK);
  g_assert_false (result);

  result = leaflet.navigate (adw::NavigationDirection::FORWARD);
  g_assert_false (result);

  for (int i = 0; i < 3; i++)
  {
    children[i] = gtk::make_managed<gtk::Label> ("");

    glib::RefPtr<adw::LeafletPage> page = leaflet.append (children[i]);

    if (i == 1)
      page->set_navigatable (false);
  }

  leaflet.set_visible_child (children[0]);

  result = leaflet.navigate (adw::NavigationDirection::BACK);
  g_assert_false (result);

  result = leaflet.navigate (adw::NavigationDirection::FORWARD);
  g_assert_true (result);
  g_assert_true (leaflet.get_visible_child ()->gobj () == children[2]->gobj ());

  result = leaflet.navigate (adw::NavigationDirection::FORWARD);
  g_assert_false (result);

  result = leaflet.navigate (adw::NavigationDirection::BACK);
  g_assert_true (result);
  g_assert_true (leaflet.get_visible_child ()->gobj () == children[0]->gobj ());
}

static void
test_adw_leaflet_prepend (void)
{
  adw::Leaflet leaflet;
  std::array<gtk::Widget*, 2> labels;

  for (int i = 0; i < 2; i++)
  {
    labels[i] = gtk::make_managed<gtk::Label> ("");
  }

  glib::RefPtr<gtk::SelectionModel> pages = leaflet.get_pages ();

  leaflet.prepend (labels[1]);
  assert_page_position (pages, labels[1], 0);

  leaflet.prepend (labels[0]);
  assert_page_position (pages, labels[0], 0);
  assert_page_position (pages, labels[1], 1);
}

static void
test_adw_leaflet_insert_child_after (void)
{
  adw::Leaflet leaflet;
  std::array<gtk::Widget*, 3> labels;

  for (int i = 0; i < 3; i++)
  {
    labels[i] = gtk::make_managed<gtk::Label> ("");
  }

  glib::RefPtr<gtk::SelectionModel> pages = leaflet.get_pages ();

  leaflet.append (labels[2]);

  assert_page_position (pages, labels[2], 0);

  leaflet.insert_child_after (labels[0], nullptr);
  assert_page_position (pages, labels[0], 0);
  assert_page_position (pages, labels[2], 1);

  leaflet.insert_child_after (labels[1], labels[0]);
  assert_page_position (pages, labels[0], 0);
  assert_page_position (pages, labels[1], 1);
  assert_page_position (pages, labels[2], 2);
}

static void
test_adw_leaflet_reorder_child_after (void)
{
  adw::Leaflet leaflet;
  std::array<gtk::Widget*, 3> labels;

  for (int i = 0; i < 3; i++)
  {
    labels[i] = gtk::make_managed<gtk::Label> ("");

    leaflet.append (labels[i]);
  }

  glib::RefPtr<gtk::SelectionModel> pages = leaflet.get_pages ();

  assert_page_position (pages, labels[0], 0);
  assert_page_position (pages, labels[1], 1);
  assert_page_position (pages, labels[2], 2);

  leaflet.reorder_child_after (labels[2], nullptr);
  assert_page_position (pages, labels[2], 0);
  assert_page_position (pages, labels[0], 1);
  assert_page_position (pages, labels[1], 2);

  leaflet.reorder_child_after (labels[0], labels[1]);
  assert_page_position (pages, labels[2], 0);
  assert_page_position (pages, labels[1], 1);
  assert_page_position (pages, labels[0], 2);
}

int
main (int argc, char* argv[])
{
  gtk_test_init (&argc, &argv, NULL);
  adw::init ();

  g_test_add_func ("/Adwaita/Leaflet/adjacent_child",
                   test_adw_leaflet_adjacent_child);
  g_test_add_func ("/Adwaita/Leaflet/navigate", test_adw_leaflet_navigate);
  g_test_add_func ("/Adwaita/Leaflet/prepend", test_adw_leaflet_prepend);
  g_test_add_func ("/Adwaita/Leaflet/insert_child_after",
                   test_adw_leaflet_insert_child_after);
  g_test_add_func ("/Adwaita/Leaflet/reorder_child_after",
                   test_adw_leaflet_reorder_child_after);

  return g_test_run ();
}
