
#ifndef _GTKMM_GRIDLAYOUT_P_H
#define _GTKMM_GRIDLAYOUT_P_H


#include <libmm-gtk/layoutmanager_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gtk
{

class GTKMM_API GridLayout_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = GridLayout;
  using BaseObjectType = GtkGridLayout;
  using BaseClassType = GtkGridLayoutClass;
  using CppClassParent = LayoutManager_Class;
  using BaseClassParent = GtkLayoutManagerClass;

  friend class GridLayout;
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


#endif /* _GTKMM_GRIDLAYOUT_P_H */

