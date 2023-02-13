
#ifndef _GIOMM_LISTMODEL_P_H
#define _GIOMM_LISTMODEL_P_H


#include <mm/glib/private/interface_p.hpp>
#include <gio/gio.h>

#include <mm/glib/private/interface_p.hpp>

namespace Gio
{

class GIOMM_API ListModel_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ListModel;
  using BaseObjectType = GListModel;
  using BaseClassType = GListModelInterface;
  using CppClassParent = Interface_Class;

  friend class ListModel;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_item_type_vfunc_callback (GListModel *self) -> GType;
  static auto get_n_items_vfunc_callback (GListModel *self) -> guint;
  static auto get_item_vfunc_callback (GListModel *self, guint position) -> gpointer;
};


} // namespace Gio


#endif /* _GIOMM_LISTMODEL_P_H */

