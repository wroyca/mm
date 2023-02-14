
#ifndef _GTKMM_COMBOBOXTEXT_P_H
#define _GTKMM_COMBOBOXTEXT_P_H

#include <libmm-gtk/combobox_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API ComboBoxText_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ComboBoxText;
    using BaseObjectType = GtkComboBoxText;
    using BaseClassType = GtkComboBoxTextClass;
    using CppClassParent = ComboBox_Class;
    using BaseClassParent = GtkComboBoxClass;

    friend class ComboBoxText;
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
