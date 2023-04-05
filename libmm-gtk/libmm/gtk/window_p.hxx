// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WINDOW_P_H
#define _GTKMM_WINDOW_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Window_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Window;
    using BaseObjectType = GtkWindow;
    using BaseClassType = GtkWindowClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Window;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

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

} // namespace gtk

#endif
