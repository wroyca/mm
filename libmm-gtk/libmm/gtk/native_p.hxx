// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NATIVE_P_H
#define _GTKMM_NATIVE_P_H

#include <gdk/gdk.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Native_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Native;
    using BaseObjectType = GtkNative;
    using BaseClassType = GtkNativeInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class Native;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
