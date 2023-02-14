
#ifndef _GTKMM_COMBOBOX_P_H
#define _GTKMM_COMBOBOX_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API ComboBox_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ComboBox;
    using BaseObjectType = GtkComboBox;
    using BaseClassType = GtkComboBoxClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class ComboBox;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    changed_callback (GtkComboBox* self) -> void;
    static auto
    format_entry_text_callback (GtkComboBox* self, const gchar* p0) -> gchar*;
  };

} // namespace Gtk

#endif
