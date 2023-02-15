// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_LISTMODEL_P_H
#define _GIOMM_LISTMODEL_P_H

#include <gio/gio.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT ListModel_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = ListModel;
    using BaseObjectType = GListModel;
    using BaseClassType = GListModelInterface;
    using CppClassParent = Interface_Class;

    friend class ListModel;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    get_item_type_vfunc_callback (GListModel* self) -> GType;
    static auto
    get_n_items_vfunc_callback (GListModel* self) -> guint;
    static auto
    get_item_vfunc_callback (GListModel* self, guint position) -> gpointer;
  };

} // namespace Gio

#endif
