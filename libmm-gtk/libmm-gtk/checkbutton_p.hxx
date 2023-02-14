
#ifndef _GTKMM_CHECKBUTTON_P_H
#define _GTKMM_CHECKBUTTON_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API CheckButton_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CheckButton;
    using BaseObjectType = GtkCheckButton;
    using BaseClassType = GtkCheckButtonClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class CheckButton;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    toggled_callback (GtkCheckButton* self) -> void;
  };

} // namespace Gtk

#endif
