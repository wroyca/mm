// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSER_P_H
#define _GTKMM_APPCHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/interface_p.hxx>

  #include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API AppChooser_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = AppChooser;
    using BaseObjectType = GtkAppChooser;
    using BaseClassType = GtkAppChooserIface;
    using CppClassParent = Glib::Interface_Class;

    friend class AppChooser;

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

#endif
