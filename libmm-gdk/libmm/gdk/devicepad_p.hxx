// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DEVICEPAD_P_H
#define _GDKMM_DEVICEPAD_P_H

#include <gdk/gdk.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DevicePad_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = DevicePad;
    using BaseObjectType = GdkDevicePad;
    using BaseClassType = GdkDevicePadInterface;
    using CppClassParent = glib::Interface_Class;

    friend class DevicePad;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gdk

#endif
