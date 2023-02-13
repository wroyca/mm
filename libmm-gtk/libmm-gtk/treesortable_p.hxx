
#ifndef _GTKMM_TREESORTABLE_P_H
#define _GTKMM_TREESORTABLE_P_H


#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

class GTKMM_API TreeSortable_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = TreeSortable;
  using BaseObjectType = GtkTreeSortable;
  using BaseClassType = GtkTreeSortableIface;
  using CppClassParent = Interface_Class;

  friend class TreeSortable;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static auto sort_column_changed_callback (GtkTreeSortable *self) -> void;

  //Callbacks (virtual functions):
  static auto get_sort_column_id_vfunc_callback (
    GtkTreeSortable *self, int *sort_column_id, GtkSortType *order) -> gboolean;
  static auto set_sort_column_id_vfunc_callback (
    GtkTreeSortable *self, int sort_column_id, GtkSortType order) -> void;
  static auto set_sort_func_vfunc_callback (
    GtkTreeSortable *self, int sort_column_id, GtkTreeIterCompareFunc func, gpointer data,
    GDestroyNotify destroy) -> void;
  static auto set_default_sort_func_vfunc_callback (
    GtkTreeSortable *self, GtkTreeIterCompareFunc func, gpointer data,
    GDestroyNotify destroy) -> void;
  static auto has_default_sort_func_vfunc_callback (GtkTreeSortable *self) -> gboolean;
  static auto sort_column_changed_vfunc_callback (GtkTreeSortable *self) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_TREESORTABLE_P_H */

