// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <mm/adw/adw.hpp>

#include <mm/glib/mm-glib.hpp>
#include <mm/gtk/mm-gtk.hpp>


namespace Adw
{

class MM_ADW_API Window_Class : public Glib::Class
{
public:
  using CppObjectType   = Window;
  using BaseObjectType  = AdwWindow;
  using BaseClassType   = AdwWindowClass;
  using CppClassParent  = Gtk::Widget_Class;
  using BaseClassParent = GtkWidgetClass;

  friend class Window;

  auto init () -> const Glib::Class&;
  static auto class_init_function (void *g_class, void *class_data) -> void;
  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:
  static auto dispose_vfunc_callback (GObject *self) -> void;
};

} // namespace Adw
