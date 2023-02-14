
#ifndef _GTKMM_FILECHOOSERWIDGET_P_H
#define _GTKMM_FILECHOOSERWIDGET_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API FileChooserWidget_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileChooserWidget;
    using BaseObjectType = GtkFileChooserWidget;
    using BaseClassType = GtkFileChooserWidgetClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class FileChooserWidget;
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
