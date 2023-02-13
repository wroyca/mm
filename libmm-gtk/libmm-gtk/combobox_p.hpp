
#ifndef _GTKMM_COMBOBOX_P_H
#define _GTKMM_COMBOBOX_P_H


#include <mm/gtk/private/widget_p.hpp>

#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto changed_callback (GtkComboBox *self) -> void;
  static auto format_entry_text_callback (GtkComboBox *self, const gchar *p0) -> gchar*;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_COMBOBOX_P_H */

