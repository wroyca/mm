/*
 * Copyright (C) 2021 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 *
 * Author: Alexander Mikhaylenko <alexander.mikhaylenko@puri.sm>
 */

#include <libmm/adw/mm-adw.hxx>
#include <libmm/adw/init.hxx> // adw::init

int notified;

static void notify_cb() { notified++; }

static void test_adw_split_button_icon_name(void) {
  adw::split_button button;

  notified = 0;
  button.property_icon_name().signal_changed().connect(
      sigc::ptr_fun(notify_cb));

  glib::ustring icon_name = button.get_property<glib::ustring>("icon-name");
  g_assert_true(icon_name == "");

  button.set_icon_name("document-open-symbolic");
  g_assert_true(notified == 1);

  button.set_icon_name("document-open-symbolic");
  g_assert_true(button.get_icon_name() == "document-open-symbolic");
  g_assert_true(notified == 1);

  button.set_property<glib::ustring>("icon-name", "edit-find-symbolic");
  g_assert_true(button.get_icon_name() == "edit-find-symbolic");
  g_assert_true(notified == 2);

  button.set_label("Open");
  g_assert_true(button.get_icon_name() == "");
  g_assert_true(notified == 3);

  button.set_icon_name("document-open-symbolic");
  g_assert_true(button.get_icon_name() == "document-open-symbolic");
  g_assert_true(notified == 4);

  button.set_child(gtk::make_managed<gtk::Button>());
  g_assert_true(button.get_icon_name() == "");
  g_assert_true(notified == 5);
}

static void test_adw_split_button_label(void) {
  adw::split_button button;

  notified = 0;
  button.property_label().signal_changed().connect(sigc::ptr_fun(notify_cb));

  glib::ustring label = button.get_property<glib::ustring>("label");
  g_assert_true(label == "");

  button.set_label("Open");
  g_assert_true(notified == 1);

  button.set_label("Open");
  g_assert_true(button.get_label() == "Open");
  g_assert_true(notified == 1);

  button.set_property<glib::ustring>("label", "Find");
  g_assert_true(button.get_label() == "Find");
  g_assert_true(notified == 2);

  button.set_icon_name("document-open-symbolic");
  g_assert_true(button.get_label() == "");
  g_assert_true(notified == 3);

  button.set_label("Open");
  g_assert_true(button.get_label() == "Open");
  g_assert_true(notified == 4);

  button.set_child(gtk::make_managed<gtk::Button>());
  g_assert_true(button.get_label() == "");
  g_assert_true(notified == 5);
}

static void test_adw_split_button_use_underline(void) {
  adw::split_button button;

  notified = 0;
  button.property_use_underline().signal_changed().connect(
      sigc::ptr_fun(notify_cb));

  bool use_underline = button.get_property<bool>("use-underline");
  g_assert_false(use_underline);

  button.set_use_underline(false);
  g_assert_true(notified == 0);

  button.set_use_underline(true);
  g_assert_true(button.get_use_underline());
  g_assert_true(notified == 1);

  button.set_property<bool>("use-underline", false);
  g_assert_false(button.get_use_underline());
  g_assert_true(notified == 2);
}

static void test_adw_split_button_child(void) {
  adw::split_button button;

  gtk::Button *child1 = new gtk::Button();
  gtk::Button *child2 = new gtk::Button();
  gtk::Button *child3 = new gtk::Button();

  notified = 0;
  button.property_child().signal_changed().connect(sigc::ptr_fun(notify_cb));

  gtk::Widget *child = button.get_property<gtk::Widget *>("child");
  g_assert_true(child == nullptr);

  button.set_child(nullptr);
  g_assert_true(notified == 0);

  button.set_child(child1);
  g_assert_true(button.get_child() == child1);
  g_assert_true(notified == 1);

  button.set_property<gtk::Widget *>("child", child2);
  g_assert_true(button.get_child() == child2);
  g_assert_true(notified == 2);

  button.set_label("Open");
  g_assert_false(button.get_child() == child2);
  g_assert_true(notified == 3);

  button.set_child(child3);
  g_assert_true(button.get_child() == child3);
  g_assert_true(notified == 4);

  button.set_icon_name("document-open-symbolic");
  g_assert_false(button.get_child() == child3);
  g_assert_true(notified == 5);

  delete child3;
  delete child2;
  delete child1;
}

static void test_adw_split_button_menu_model(void) {
  adw::split_button button;

  glib::RefPtr<gio::MenuModel> model1 = gio::Menu::create();
  glib::RefPtr<gio::MenuModel> model2 = gio::Menu::create();

  notified = 0;
  button.property_menu_model().signal_changed().connect(
      sigc::ptr_fun(notify_cb));

  glib::RefPtr<gio::MenuModel> model =
      button.get_property<glib::RefPtr<gio::MenuModel>>("menu-model");
  g_assert_true(model == nullptr);
  g_assert_true(notified == 0);

  button.set_menu_model(model1);
  g_assert_true(button.get_menu_model() == model1);
  g_assert_true(notified == 1);

  button.set_property<glib::RefPtr<gio::MenuModel>>("menu-model", model2);
  g_assert_true(button.get_menu_model() == model2);
  g_assert_true(notified == 2);

  button.set_popover(gtk::make_managed<gtk::Popover>());
  g_assert_true(button.get_menu_model() == nullptr);
  g_assert_true(notified == 3);
}

static void test_adw_split_button_popover(void) {
  adw::split_button button;

  gtk::Popover *popover1 = new gtk::Popover();
  gtk::Popover *popover2 = new gtk::Popover();

  notified = 0;
  button.property_popover().signal_changed().connect(sigc::ptr_fun(notify_cb));

  gtk::Popover *popover = button.get_property<gtk::Popover *>("popover");
  g_assert_true(popover == nullptr);
  g_assert_true(notified == 0);

  button.set_popover(popover1);
  g_assert_true(button.get_popover() == popover1);
  g_assert_true(notified == 1);

  button.set_property<gtk::Popover *>("popover", popover2);
  g_assert_true(button.get_popover() == popover2);
  g_assert_true(notified == 2);

  glib::RefPtr<gio::MenuModel> model = gio::Menu::create();
  button.set_menu_model(model);
  g_assert_false(button.get_popover() == popover2);
  g_assert_true(notified == 3);

  delete popover2;
  delete popover1;
}

static void test_adw_split_button_direction(void) {
  adw::split_button button;

  notified = 0;
  button.property_direction().signal_changed().connect(
      sigc::ptr_fun(notify_cb));

  gtk::ArrowType direction = button.get_property<gtk::ArrowType>("direction");
  g_assert_true(direction == gtk::ArrowType::DOWN);

  button.set_direction(gtk::ArrowType::DOWN);
  g_assert_true(notified == 0);

  button.set_direction(gtk::ArrowType::UP);
  g_assert_true(button.get_direction() == gtk::ArrowType::UP);
  g_assert_true(notified == 1);

  button.set_property<gtk::ArrowType>("direction", gtk::ArrowType::DOWN);
  g_assert_true(button.get_direction() == gtk::ArrowType::DOWN);
  g_assert_true(notified == 2);
}

static void test_adw_split_button_dropdown_tooltip(void) {
  adw::split_button button;

  notified = 0;
  button.property_dropdown_tooltip().signal_changed().connect(
      sigc::ptr_fun(notify_cb));

  glib::ustring tooltip =
      button.get_property<glib::ustring>("dropdown-tooltip");
  g_assert_true(tooltip == "");
  g_assert_true(notified == 0);

  button.set_dropdown_tooltip("Some tooltip");
  g_assert_true(button.get_dropdown_tooltip() == "Some tooltip");
  g_assert_true(notified == 1);

  button.set_property<glib::ustring>("dropdown-tooltip", "Some other tooltip");
  g_assert_true(button.get_dropdown_tooltip() == "Some other tooltip");
  g_assert_true(notified == 2);
}

int main(int argc, char *argv[]) {
  gtk_test_init(&argc, &argv, NULL);
  adw::init();

  g_test_add_func("/Adwaita/SplitButton/icon_name",
                  test_adw_split_button_icon_name);
  g_test_add_func("/Adwaita/SplitButton/label", test_adw_split_button_label);
  g_test_add_func("/Adwaita/SplitButton/use_underline",
                  test_adw_split_button_use_underline);
  g_test_add_func("/Adwaita/SplitButton/child", test_adw_split_button_child);
  g_test_add_func("/Adwaita/SplitButton/menu_model",
                  test_adw_split_button_menu_model);
  g_test_add_func("/Adwaita/SplitButton/popover",
                  test_adw_split_button_popover);
  g_test_add_func("/Adwaita/SplitButton/direction",
                  test_adw_split_button_direction);
  g_test_add_func("/Adwaita/SplitButton/dropdown_tooltip",
                  test_adw_split_button_dropdown_tooltip);

  return g_test_run();
}
