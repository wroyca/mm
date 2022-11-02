// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
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
  using CppClassParent = Glib::Interface_Class;

  friend class ListModel;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GType get_item_type_vfunc_callback(GListModel* self);
  static guint get_n_items_vfunc_callback(GListModel* self);
  static gpointer get_item_vfunc_callback(GListModel* self, guint position);
};


} // namespace Gio


#endif /* _GIOMM_LISTMODEL_P_H */

