// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLORCHOOSER_P_H
#define _GTKMM_COLORCHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ColorChooser_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = ColorChooser;
    using BaseObjectType = GtkColorChooser;
    using BaseClassType = GtkColorChooserInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class ColorChooser;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    color_activated_callback (GtkColorChooser* self, const GdkRGBA* p0) -> void;
  };

} // namespace Gtk

#endif

#endif