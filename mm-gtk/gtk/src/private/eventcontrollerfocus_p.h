// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_EVENTCONTROLLERFOCUS_P_H
#define _GTKMM_EVENTCONTROLLERFOCUS_P_H


#include <gtkmm/private/eventcontroller_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class GTKMM_API EventControllerFocus_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = EventControllerFocus;
  using BaseObjectType = GtkEventControllerFocus;
  using BaseClassType = GtkEventControllerFocusClass;
  using CppClassParent = EventController_Class;
  using BaseClassParent = GtkEventControllerClass;

  friend class EventControllerFocus;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_EVENTCONTROLLERFOCUS_P_H */

