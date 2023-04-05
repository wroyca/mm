// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/fontchooser.hxx>
  #include <libmm/gtk/fontchooser_p.hxx>

  #include <gtk/gtk.h>

using Level = gtk::FontChooser::Level;

namespace
{
  extern "C"
  {
    static auto
    SignalProxy_Filter_gtk_callback (const PangoFontFamily* family,
                                     const PangoFontFace* face,
                                     gpointer user_data) -> gboolean
    {
      auto the_slot =
          static_cast<gtk::FontChooser::SlotFontFilter*> (user_data);

      try
      {
        const glib::RefPtr<const pango::FontFamily> cppFamily =
            glib::wrap (const_cast<PangoFontFamily*> (family), true);
        const glib::RefPtr<const pango::FontFace> cppFace =
            glib::wrap (const_cast<PangoFontFace*> (face), true);
        return (*the_slot) (cppFamily, cppFace);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return false;
    }

    static auto
    SignalProxy_Filter_gtk_callback_destroy (void* data) -> void
    {
      delete static_cast<gtk::FontChooser::SlotFontFilter*> (data);
    }
  }
} // namespace

namespace gtk
{

  auto
  FontChooser::set_filter_func (const SlotFontFilter& slot) -> void
  {
    auto slot_copy = new SlotFontFilter (slot);
    gtk_font_chooser_set_filter_func (gobj (),
                                      &SignalProxy_Filter_gtk_callback,
                                      slot_copy,
                                      &SignalProxy_Filter_gtk_callback_destroy);
  }

} // namespace gtk

namespace
{

  static auto
  FontChooser_signal_font_activated_callback (GtkFontChooser* self,
                                              const gchar* p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<FontChooser*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo FontChooser_signal_font_activated_info = {
      "font-activated",
      (GCallback) &FontChooser_signal_font_activated_callback,
      (GCallback) &FontChooser_signal_font_activated_callback};

} // namespace

auto
glib::Value<gtk::FontChooser::Level>::value_type () -> GType
{
  return gtk_font_chooser_level_get_type ();
}

namespace glib
{

  auto
  wrap (GtkFontChooser* object, bool take_copy) -> glib::RefPtr<gtk::FontChooser>
  {
    return glib::make_refptr_for_instance<gtk::FontChooser> (
        dynamic_cast<gtk::FontChooser*> (
            glib::wrap_auto_interface<gtk::FontChooser> ((GObject*) (object),
                                                         take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FontChooser_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontChooser_Class::iface_init_function;

      gtype_ = gtk_font_chooser_get_type ();
    }

    return *this;
  }

  auto
  FontChooser_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->font_activated = &font_activated_callback;
  }

  auto
  FontChooser_Class::font_activated_callback (GtkFontChooser* self,
                                              const gchar* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_font_activated (
              glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->font_activated)
      (*base->font_activated) (self, p0);
  }

  auto
  FontChooser_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FontChooser ((GtkFontChooser*) (object));
  }

  FontChooser::FontChooser ()
    : glib::Interface (fontchooser_class_.init ())
  {
  }

  FontChooser::FontChooser (GtkFontChooser* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  FontChooser::FontChooser (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  FontChooser::FontChooser (FontChooser&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  FontChooser::operator= (FontChooser&& src) noexcept -> FontChooser&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  FontChooser::~FontChooser () noexcept {}

  auto
  FontChooser::add_interface (GType gtype_implementer) -> void
  {
    fontchooser_class_.init ().add_interface (gtype_implementer);
  }

  FontChooser::CppClassType FontChooser::fontchooser_class_;

  auto
  FontChooser::get_type () -> GType
  {
    return fontchooser_class_.init ().get_type ();
  }

  auto
  FontChooser::get_base_type () -> GType
  {
    return gtk_font_chooser_get_type ();
  }

  auto
  FontChooser::get_font_family () -> glib::RefPtr<pango::FontFamily>
  {
    auto retvalue = glib::wrap (gtk_font_chooser_get_font_family (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_family () const -> glib::RefPtr<const pango::FontFamily>
  {
    return const_cast<FontChooser*> (this)->get_font_family ();
  }

  auto
  FontChooser::get_font_face () -> glib::RefPtr<pango::FontFace>
  {
    auto retvalue = glib::wrap (gtk_font_chooser_get_font_face (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_face () const -> glib::RefPtr<const pango::FontFace>
  {
    return const_cast<FontChooser*> (this)->get_font_face ();
  }

  auto
  FontChooser::get_font_size () const -> int
  {
    return gtk_font_chooser_get_font_size (
        const_cast<GtkFontChooser*> (gobj ()));
  }

  auto
  FontChooser::get_font_desc () const -> pango::FontDescription
  {
    return glib::wrap (
        const_cast<PangoFontDescription*> (gtk_font_chooser_get_font_desc (
            const_cast<GtkFontChooser*> (gobj ()))),
        false);
  }

  auto
  FontChooser::set_font_desc (const pango::FontDescription& font_desc) -> void
  {
    gtk_font_chooser_set_font_desc (gobj (), (font_desc).gobj ());
  }

  auto
  FontChooser::get_font () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_font (const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_font (const glib::ustring& fontname) -> void
  {
    gtk_font_chooser_set_font (gobj (), fontname.c_str ());
  }

  auto
  FontChooser::get_preview_text () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_preview_text (
            const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_preview_text (const glib::ustring& text) -> void
  {
    gtk_font_chooser_set_preview_text (gobj (), text.c_str ());
  }

  auto
  FontChooser::get_show_preview_entry () const -> bool
  {
    return gtk_font_chooser_get_show_preview_entry (
        const_cast<GtkFontChooser*> (gobj ()));
  }

  auto
  FontChooser::set_show_preview_entry (bool show_preview_entry) -> void
  {
    gtk_font_chooser_set_show_preview_entry (
        gobj (),
        static_cast<int> (show_preview_entry));
  }

  auto
  FontChooser::set_font_map (const glib::RefPtr<pango::FontMap>& fontmap) -> void
  {
    gtk_font_chooser_set_font_map (gobj (), glib::unwrap (fontmap));
  }

  auto
  FontChooser::get_font_map () -> glib::RefPtr<pango::FontMap>
  {
    auto retvalue = glib::wrap (gtk_font_chooser_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_map () const -> glib::RefPtr<const pango::FontMap>
  {
    return const_cast<FontChooser*> (this)->get_font_map ();
  }

  auto
  FontChooser::set_level (Level level) -> void
  {
    gtk_font_chooser_set_level (gobj (),
                                static_cast<GtkFontChooserLevel> (level));
  }

  auto
  FontChooser::get_level () const -> Level
  {
    return static_cast<Level> (
        gtk_font_chooser_get_level (const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::get_font_features () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_font_features (
            const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::get_language () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_language (const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_language (const glib::ustring& language) -> void
  {
    gtk_font_chooser_set_language (gobj (), language.c_str ());
  }

  auto
  FontChooser::signal_font_activated () -> glib::SignalProxy<void (const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&)> (
        this,
        &FontChooser_signal_font_activated_info);
  }

  auto
  FontChooser::property_font () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "font");
  }

  auto
  FontChooser::property_font () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::FontDescription>::value,
      "Type pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontChooser::property_font_desc () -> glib::PropertyProxy<pango::FontDescription>
  {
    return glib::PropertyProxy<pango::FontDescription> (this, "font-desc");
  }

  auto
  FontChooser::property_font_desc () const -> glib::PropertyProxy_ReadOnly<pango::FontDescription>
  {
    return glib::PropertyProxy_ReadOnly<pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  FontChooser::property_preview_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "preview-text");
  }

  auto
  FontChooser::property_preview_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "preview-text");
  }

  auto
  FontChooser::property_show_preview_entry () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-preview-entry");
  }

  auto
  FontChooser::property_show_preview_entry () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-preview-entry");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Level>::value,
      "Type Level cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontChooser::property_level () -> glib::PropertyProxy<Level>
  {
    return glib::PropertyProxy<Level> (this, "level");
  }

  auto
  FontChooser::property_level () const -> glib::PropertyProxy_ReadOnly<Level>
  {
    return glib::PropertyProxy_ReadOnly<Level> (this, "level");
  }

  auto
  FontChooser::property_font_features () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font-features");
  }

  auto
  FontChooser::property_language () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "language");
  }

  auto
  FontChooser::property_language () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "language");
  }

  auto
  gtk::FontChooser::on_font_activated (const glib::ustring& fontname) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->font_activated)
      (*base->font_activated) (gobj (), fontname.c_str ());
  }

} // namespace gtk

#endif
