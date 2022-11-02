// SPDX-License-Identifier: GPL-3.0-or-later
//

#pragma once

#include <mm/adw/adw.hpp>

#include <mm/gtk/mm-gtk.hpp>
#include <mm/glib/mm-glib.hpp>

#include <adwaita.h>

using AdwWindow      = struct _AdwWindow;
using AdwWindowClass = struct _AdwWindowClass;

namespace Adw
{
  class MM_ADW_API Window_Class;
  class MM_ADW_API Application;
  class MM_ADW_API Window : public Gtk::Window
  {
  public:
    using CppObjectType  = Window;
    using CppClassType   = Window_Class;
    using BaseObjectType = AdwWindow;
    using BaseClassType  = AdwWindowClass;

    // All constructors are hand-coded, because they connect a signal handler.
    explicit Window ();
    Window (Window&& src) noexcept;
   ~Window () noexcept override = default;
    Window& operator= (Window&& src) noexcept;

    // noncopyable
    Window (const Window &) = delete;
    auto operator= (const Window &) -> Window& = delete;

  private:
    friend MM_ADW_API class Window_Class;
    static CppClassType window_class_;

  protected:
    explicit Window (const Glib::ConstructParams &construct_params);
    explicit Window (AdwWindow *castitem);

  public:
    static auto get_type() -> GType G_GNUC_CONST;
    static auto get_base_type() -> GType G_GNUC_CONST;

    /// Provides access to the underlying C GObject.
    auto gobj() -> AdwWindow*
    {
      return reinterpret_cast<AdwWindow*>(gobject_);
    }

    /// Provides access to the underlying C GObject.
    auto gobj() const -> const AdwWindow*
    {
      return reinterpret_cast<AdwWindow*>(gobject_);
    }

    // Disambiguate calls to get_display(). Use Root::get_display(), not Widget::get_display().
    // gtk_widget_get_display() calls gtk_root_get_display(). There is no reason
    // to call gtk_widget_get_display() from a class that implements GtkRoot.
    using Root::get_display;
  };
} // namespace Adw
