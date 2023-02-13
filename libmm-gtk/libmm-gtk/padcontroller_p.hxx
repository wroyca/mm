
#ifndef _GTKMM_PADCONTROLLER_P_H
#define _GTKMM_PADCONTROLLER_P_H


#include <libmm-gtk/eventcontroller_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API PadController_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PadController;
  using BaseObjectType = GtkPadController;
  using BaseClassType = GtkPadControllerClass;
  using CppClassParent = EventController_Class;
  using BaseClassParent = GtkEventControllerClass;

  friend class PadController;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_PADCONTROLLER_P_H */
