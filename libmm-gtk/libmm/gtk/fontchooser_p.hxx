// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FONTCHOOSER_P_H
#define _GTKMM_FONTCHOOSER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FontChooser_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = FontChooser;
    using BaseObjectType = GtkFontChooser;
    using BaseClassType = GtkFontChooserIface;
    using CppClassParent = glib::Interface_Class;

    friend class FontChooser;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    font_activated_callback (GtkFontChooser* self, const gchar* p0) -> void;
  };

} // namespace gtk

#endif

#endif
