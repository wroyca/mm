// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUILDERSCOPE_P_H
#define _GTKMM_BUILDERSCOPE_P_H

#include <gtk/gtk.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT BuilderScope_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = BuilderScope;
    using BaseObjectType = GtkBuilderScope;
    using BaseClassType = GtkBuilderScopeInterface;
    using CppClassParent = glib::Interface_Class;

    friend class BuilderScope;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    get_type_from_name_vfunc_callback (GtkBuilderScope* self,
                                       GtkBuilder* builder,
                                       const char* type_name) -> GType;
  };

} // namespace gtk

#endif
