
#ifndef _GTKMM_SORTER_P_H
#define _GTKMM_SORTER_P_H


#include <libmm-glib/object_p.hpp>

#include <libmm-glib/class.hpp>

namespace Gtk
{

class GTKMM_API Sorter_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Sorter;
  using BaseObjectType = GtkSorter;
  using BaseClassType = GtkSorterClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class Sorter;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto compare_vfunc_callback (
    GtkSorter *self, gpointer item1, gpointer item2) -> GtkOrdering;
  static auto get_order_vfunc_callback (GtkSorter *self) -> GtkSorterOrder;
};


} // namespace Gtk


#endif /* _GTKMM_SORTER_P_H */

