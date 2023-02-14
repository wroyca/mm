
#ifndef _GTKMM_WINDOW_P_H
#define _GTKMM_WINDOW_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Window_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Window;
    using BaseObjectType = GtkWindow;
    using BaseClassType = GtkWindowClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Window;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    keys_changed_callback (GtkWindow* self) -> void;
    static auto
    close_request_callback (GtkWindow* self) -> gboolean;

    static auto
    dispose_vfunc_callback (GObject* self) -> void;
  };

} // namespace Gtk

#endif
