// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TOPLEVEL_P_H
#define _GDKMM_TOPLEVEL_P_H

#include <gdk/gdk.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Toplevel_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Toplevel;
    using BaseObjectType = GdkToplevel;
    using BaseClassType = GdkToplevelInterface;
    using CppClassParent = glib::Interface_Class;

    friend class Toplevel;

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
