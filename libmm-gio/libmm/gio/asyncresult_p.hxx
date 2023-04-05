// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_ASYNCRESULT_P_H
#define _GIOMM_ASYNCRESULT_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT AsyncResult_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = AsyncResult;
    using BaseObjectType = GAsyncResult;
    using BaseClassType = GAsyncResultIface;
    using CppClassParent = Interface_Class;

    friend class AsyncResult;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_source_object_vfunc_callback (GAsyncResult* self) -> GObject*;
    static auto
    is_tagged_vfunc_callback (GAsyncResult* self, gpointer source_tag)
        -> gboolean;
  };

} // namespace gio

#endif
