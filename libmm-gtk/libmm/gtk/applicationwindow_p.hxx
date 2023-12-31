// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPLICATIONWINDOW_P_H
#define _GTKMM_APPLICATIONWINDOW_P_H

#include <libmm/gtk/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ApplicationWindow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ApplicationWindow;
    using BaseObjectType = GtkApplicationWindow;
    using BaseClassType = GtkApplicationWindowClass;
    using CppClassParent = gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class ApplicationWindow;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
