
#ifndef _GTKMM_SELECTIONMODEL_P_H
#define _GTKMM_SELECTIONMODEL_P_H


#include <libmm-glib/interface_p.hpp>
#include <gtk/gtk.h>

#include <libmm-glib/interface_p.hpp>

namespace Gtk
{

class GTKMM_API SelectionModel_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = SelectionModel;
  using BaseObjectType = GtkSelectionModel;
  using BaseClassType = GtkSelectionModelInterface;
  using CppClassParent = Interface_Class;

  friend class SelectionModel;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto is_selected_vfunc_callback (GtkSelectionModel *self, guint position) -> gboolean;
  static auto get_selection_in_range_vfunc_callback (
    GtkSelectionModel *self, guint position, guint n_items) -> GtkBitset*;
  static auto select_item_vfunc_callback (
    GtkSelectionModel *self, guint position, gboolean unselect_rest) -> gboolean;
  static auto unselect_item_vfunc_callback (GtkSelectionModel *self, guint position) -> gboolean;
  static auto select_range_vfunc_callback (
    GtkSelectionModel *self, guint position, guint n_items, gboolean unselect_rest) -> gboolean;
  static auto unselect_range_vfunc_callback (
    GtkSelectionModel *self, guint position, guint n_items) -> gboolean;
  static auto select_all_vfunc_callback (GtkSelectionModel *self) -> gboolean;
  static auto unselect_all_vfunc_callback (GtkSelectionModel *self) -> gboolean;
  static auto set_selection_vfunc_callback (
    GtkSelectionModel *self, GtkBitset *selected, GtkBitset *mask) -> gboolean;
};


} // namespace Gtk


#endif /* _GTKMM_SELECTIONMODEL_P_H */

