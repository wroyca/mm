// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ASYNCINITABLE_P_H
#define _GIOMM_ASYNCINITABLE_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT AsyncInitable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = AsyncInitable;
    using BaseObjectType = GAsyncInitable;
    using BaseClassType = GAsyncInitableIface;
    using CppClassParent = Interface_Class;

    friend class AsyncInitable;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    init_async_vfunc_callback (GAsyncInitable* self,
                               int io_priority,
                               GCancellable* cancellable,
                               GAsyncReadyCallback callback,
                               gpointer user_data) -> void;
    static auto
    init_finish_vfunc_callback (GAsyncInitable* self,
                                GAsyncResult* res,
                                GError** error) -> gboolean;
  };

} // namespace Gio

#endif
