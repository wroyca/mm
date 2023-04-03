// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUILDABLE_P_H
#define _GTKMM_BUILDABLE_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Buildable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Buildable;
    using BaseObjectType = GtkBuildable;
    using BaseClassType = GtkBuildableIface;
    using CppClassParent = Glib::Interface_Class;

    friend class Buildable;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    custom_tag_start_vfunc_callback (GtkBuildable* buildable,
                                     GtkBuilder* builder,
                                     GObject* child,
                                     const char* tagname,
                                     GtkBuildableParser* parser,
                                     gpointer* data) -> gboolean;
    static auto
    custom_tag_end_vfunc_callback (GtkBuildable* buildable,
                                   GtkBuilder* builder,
                                   GObject* child,
                                   const char* tagname,
                                   gpointer data) -> void;
  };

} // namespace Gtk

#endif
