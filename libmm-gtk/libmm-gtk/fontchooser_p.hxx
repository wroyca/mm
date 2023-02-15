// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSER_P_H
#define _GTKMM_FONTCHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/interface_p.hxx>

  #include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API FontChooser_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = FontChooser;
    using BaseObjectType = GtkFontChooser;
    using BaseClassType = GtkFontChooserIface;
    using CppClassParent = Glib::Interface_Class;

    friend class FontChooser;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    font_activated_callback (GtkFontChooser* self, const gchar* p0) -> void;
  };

} // namespace Gtk

#endif

#endif
