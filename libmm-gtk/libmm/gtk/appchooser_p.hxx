// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSER_P_H
#define _GTKMM_APPCHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AppChooser_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = AppChooser;
    using BaseObjectType = GtkAppChooser;
    using BaseClassType = GtkAppChooserIface;
    using CppClassParent = glib::Interface_Class;

    friend class AppChooser;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif

#endif
