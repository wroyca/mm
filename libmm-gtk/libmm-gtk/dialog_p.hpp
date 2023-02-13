
#ifndef _GTKMM_DIALOG_P_H
#define _GTKMM_DIALOG_P_H


#include <mm/gtk/private/window_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API Dialog_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Dialog;
  using BaseObjectType = GtkDialog;
  using BaseClassType = GtkDialogClass;
  using CppClassParent = Window_Class;
  using BaseClassParent = GtkWindowClass;

  friend class Dialog;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto response_callback (GtkDialog *self, gint p0) -> void;

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_DIALOG_P_H */

