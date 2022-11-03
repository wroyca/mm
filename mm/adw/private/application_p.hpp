// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <mm/adw/adw.hpp>

#include <mm/gtk/application.hpp>

#include <adwaita.h>

namespace Adw
{
  class MM_ADW_API Application_Class : public Gtk::Application, public Glib::Class
  {
  public:
    using CppObjectType   = Application;
    using BaseObjectType  = AdwApplication;
    using BaseClassType   = AdwApplicationClass;
    using CppClassParent  = Gtk::Application_Class;
    using BaseClassParent = GApplicationClass;

    friend class Application;

    auto init() -> const Class&;
    static auto class_init_function(void *g_class, void *class_data) -> void;
  };
}
