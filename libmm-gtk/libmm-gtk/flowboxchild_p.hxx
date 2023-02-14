
#ifndef _GTKMM_FLOWBOXCHILD_P_H
#define _GTKMM_FLOWBOXCHILD_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API FlowBoxChild_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FlowBoxChild;
    using BaseObjectType = GtkFlowBoxChild;
    using BaseClassType = GtkFlowBoxChildClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class FlowBoxChild;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    activate_callback (GtkFlowBoxChild* self) -> void;
  };

} // namespace Gtk

#endif
