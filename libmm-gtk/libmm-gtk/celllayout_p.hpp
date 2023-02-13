
#ifndef _GTKMM_CELLLAYOUT_P_H
#define _GTKMM_CELLLAYOUT_P_H


#include <libmm-glib/interface_p.hpp>

#include <libmm-glib/interface_p.hpp>

namespace Gtk
{

class GTKMM_API CellLayout_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = CellLayout;
  using BaseObjectType = GtkCellLayout;
  using BaseClassType = GtkCellLayoutIface;
  using CppClassParent = Interface_Class;

  friend class CellLayout;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto pack_start_vfunc_callback (
    GtkCellLayout *self, GtkCellRenderer *cell, gboolean expand) -> void;
  static auto pack_end_vfunc_callback (
    GtkCellLayout *self, GtkCellRenderer *cell, gboolean expand) -> void;
  static auto clear_vfunc_callback (GtkCellLayout *self) -> void;
  static auto add_attribute_vfunc_callback (
    GtkCellLayout *self, GtkCellRenderer *cell, const gchar *attribute, gint column) -> void;
  static auto clear_attributes_vfunc_callback (GtkCellLayout *self, GtkCellRenderer *cell) -> void;
  static auto reorder_vfunc_callback (
    GtkCellLayout *self, GtkCellRenderer *cell, gint position) -> void;
};


} // namespace Gtk


#endif /* _GTKMM_CELLLAYOUT_P_H */

