// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLABLE_P_H
#define _GTKMM_SCROLLABLE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Scrollable_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = Scrollable;
    using BaseObjectType = GtkScrollable;
    using BaseClassType = GtkScrollableInterface;
    using CppClassParent = glib::Interface_Class;

    friend class Scrollable;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_border_vfunc_callback (GtkScrollable* self, GtkBorder* border)
        -> gboolean;
  };

} // namespace gtk

#endif
