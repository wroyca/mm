
#ifndef _GTKMM_INSCRIPTION_P_H
#define _GTKMM_INSCRIPTION_P_H


#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

class GTKMM_API Inscription_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Inscription;
  using BaseObjectType = GtkInscription;
  using CppClassParent = Widget_Class;

  friend class Inscription;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_INSCRIPTION_P_H */

