// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INITABLE_P_H
#define _GIOMM_INITABLE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Initable_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Initable;
    using BaseObjectType = GInitable;
    using BaseClassType = GInitableIface;
    using CppClassParent = Interface_Class;

    friend class Initable;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    init_vfunc_callback (GInitable* self,
                         GCancellable* cancellable,
                         GError** error) -> gboolean;
  };

} // namespace gio

#endif
