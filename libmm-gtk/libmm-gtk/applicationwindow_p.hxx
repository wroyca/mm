
#ifndef _GTKMM_APPLICATIONWINDOW_P_H
#define _GTKMM_APPLICATIONWINDOW_P_H

#include <libmm-gtk/window_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API ApplicationWindow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ApplicationWindow;
    using BaseObjectType = GtkApplicationWindow;
    using BaseClassType = GtkApplicationWindowClass;
    using CppClassParent = Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class ApplicationWindow;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
