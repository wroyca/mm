// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <mm/adw/adw.hpp>
#include <mm/gtk/mm-gtk.hpp>

#include <adwaita.h>

using AdwApplication      = _AdwApplication;
using AdwApplicationClass = _AdwApplicationClass;

namespace Adw
{
  class MM_ADW_API Application_Class;
  class MM_ADW_API Application : public Gtk::Application
  {
  public:
    using CppObjectType  = Application;
    using CppClassType   = Application_Class;
    using BaseObjectType = AdwApplication;
    using BaseClassType  = AdwApplicationClass;

    // noncopyable
    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

  private:
    friend class Application_Class;
    static CppClassType application_class_;

  protected:
    explicit Application(const Glib::ustring& application_id = {}, Gio::Application::Flags flags = Gio::Application::Flags::NONE);
    explicit Application(const Glib::ConstructParams& construct_params);
    explicit Application(GtkApplication* castitem);

  public:
    Application(Application&& src) noexcept;
    Application& operator=(Application&& src) noexcept;
   ~Application() noexcept override = default;

    static auto create(const Glib::ustring& application_id = {}, Gio::Application::Flags flags = Gio::Application::Flags::NONE) -> Glib::RefPtr<Application>;
  };
} // namespace Adw
