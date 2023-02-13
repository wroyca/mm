
#ifndef _GTKMM_TOGGLEBUTTON_P_H
#define _GTKMM_TOGGLEBUTTON_P_H


#include <libmm-gtk/button_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API ToggleButton_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ToggleButton;
  using BaseObjectType = GtkToggleButton;
  using BaseClassType = GtkToggleButtonClass;
  using CppClassParent = Button_Class;
  using BaseClassParent = GtkButtonClass;

  friend class ToggleButton;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto toggled_callback (GtkToggleButton *self) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TOGGLEBUTTON_P_H */

