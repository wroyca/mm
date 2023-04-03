// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WINDOW_P_H
#define _GTKMM_WINDOW_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Window_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Window;
    using BaseObjectType = GtkWindow;
    using BaseClassType = GtkWindowClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Window;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
#ifndef GTKMM_DISABLE_DEPRECATED

    static auto
    keys_changed_callback (GtkWindow* self) -> void;
#endif

    static auto
    close_request_callback (GtkWindow* self) -> gboolean;

    static auto
    dispose_vfunc_callback (GObject* self) -> void;
  };

} // namespace Gtk

#endif
