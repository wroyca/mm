
#ifndef _GTKMM_STACKSWITCHER_P_H
#define _GTKMM_STACKSWITCHER_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API StackSwitcher_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = StackSwitcher;
    using BaseObjectType = GtkStackSwitcher;
    using BaseClassType = GtkStackSwitcherClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class StackSwitcher;
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
