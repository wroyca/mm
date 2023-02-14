

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooser.hxx>
#include <libmm-gtk/fontchooser_p.hxx>

#include <gtk/gtk.h>

using Level = Gtk::FontChooser::Level;

namespace
{
  extern "C"
  {
    static auto
    SignalProxy_Filter_gtk_callback (const PangoFontFamily* family,
                                     const PangoFontFace* face,
                                     const gpointer user_data) -> gboolean
    {
      const auto the_slot =
          static_cast<Gtk::FontChooser::SlotFontFilter*> (user_data);

      try
      {
        const Glib::RefPtr<const Pango::FontFamily> cppFamily =
            Glib::wrap (const_cast<PangoFontFamily*> (family), true);
        const Glib::RefPtr<const Pango::FontFace> cppFace =
            Glib::wrap (const_cast<PangoFontFace*> (face), true);
        return (*the_slot) (cppFamily, cppFace);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }

      return false;
    }

    static auto
    SignalProxy_Filter_gtk_callback_destroy (void* data) -> void
    {
      delete static_cast<Gtk::FontChooser::SlotFontFilter*> (data);
    }
  }
} // namespace

namespace Gtk
{

  auto
  FontChooser::set_filter_func (const SlotFontFilter& slot) -> void
  {
    const auto slot_copy = new SlotFontFilter (slot);
    gtk_font_chooser_set_filter_func (gobj (),
                                      &SignalProxy_Filter_gtk_callback,
                                      slot_copy,
                                      &SignalProxy_Filter_gtk_callback_destroy);
  }

} // namespace Gtk

namespace
{

  auto
  FontChooser_signal_font_activated_callback (GtkFontChooser* self,
                                              const gchar* p0,
                                              void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    const auto obj = dynamic_cast<FontChooser*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo FontChooser_signal_font_activated_info = {
      "font-activated",
      (GCallback) &FontChooser_signal_font_activated_callback,
      (GCallback) &FontChooser_signal_font_activated_callback};

} // namespace

auto
Glib::Value<Gtk::FontChooser::Level>::value_type () -> GType
{
  return gtk_font_chooser_level_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkFontChooser* object, const bool take_copy) -> RefPtr<Gtk::FontChooser>
  {
    return Glib::make_refptr_for_instance<Gtk::FontChooser> (
        Glib::wrap_auto_interface<Gtk::FontChooser> ((GObject*) object,
                                                     take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontChooser_Class::init () -> const Interface_Class&
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_font_activated (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
  FontChooser_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FontChooser ((GtkFontChooser*) object);
  }

  FontChooser::FontChooser ()
    : Interface (fontchooser_class_.init ())
  {
  }

  FontChooser::FontChooser (GtkFontChooser* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  FontChooser::FontChooser (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  FontChooser::FontChooser (FontChooser&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  FontChooser::operator= (FontChooser&& src) noexcept -> FontChooser&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  FontChooser::~FontChooser () noexcept = default;

  auto
  FontChooser::add_interface (const GType gtype_implementer) -> void
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
  FontChooser::get_font_family () -> Glib::RefPtr<Pango::FontFamily>
  {
    auto retvalue = Glib::wrap (gtk_font_chooser_get_font_family (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_family () const -> Glib::RefPtr<const Pango::FontFamily>
  {
    return const_cast<FontChooser*> (this)->get_font_family ();
  }

  auto
  FontChooser::get_font_face () -> Glib::RefPtr<Pango::FontFace>
  {
    auto retvalue = Glib::wrap (gtk_font_chooser_get_font_face (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_face () const -> Glib::RefPtr<const Pango::FontFace>
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
  FontChooser::get_font_desc () const -> Pango::FontDescription
  {
    return Glib::wrap (
        gtk_font_chooser_get_font_desc (const_cast<GtkFontChooser*> (gobj ())),
        false);
  }

  auto
  FontChooser::set_font_desc (const Pango::FontDescription& font_desc) -> void
  {
    gtk_font_chooser_set_font_desc (gobj (), font_desc.gobj ());
  }

  auto
  FontChooser::get_font () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_font (const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_font (const Glib::ustring& fontname) -> void
  {
    gtk_font_chooser_set_font (gobj (), fontname.c_str ());
  }

  auto
  FontChooser::get_preview_text () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_preview_text (
            const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_preview_text (const Glib::ustring& text) -> void
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
  FontChooser::set_show_preview_entry (const bool show_preview_entry) -> void
  {
    gtk_font_chooser_set_show_preview_entry (gobj (), show_preview_entry);
  }

  auto
  FontChooser::set_font_map (const Glib::RefPtr<Pango::FontMap>& fontmap) -> void
  {
    gtk_font_chooser_set_font_map (gobj (), Glib::unwrap (fontmap));
  }

  auto
  FontChooser::get_font_map () -> Glib::RefPtr<Pango::FontMap>
  {
    auto retvalue = Glib::wrap (gtk_font_chooser_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontChooser::get_font_map () const -> Glib::RefPtr<const Pango::FontMap>
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
  FontChooser::get_font_features () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_font_features (
            const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::get_language () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_font_chooser_get_language (const_cast<GtkFontChooser*> (gobj ())));
  }

  auto
  FontChooser::set_language (const Glib::ustring& language) -> void
  {
    gtk_font_chooser_set_language (gobj (), language.c_str ());
  }

  auto
  FontChooser::signal_font_activated () -> Glib::SignalProxy<void (const Glib::ustring&)>
  {
    return {this, &FontChooser_signal_font_activated_info};
  }

  auto
  FontChooser::property_font () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "font"};
  }

  auto
  FontChooser::property_font () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "font"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Pango::FontDescription>::value,
      "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontChooser::property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>
  {
    return {this, "font-desc"};
  }

  auto
  FontChooser::property_font_desc () const -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>
  {
    return {this, "font-desc"};
  }

  auto
  FontChooser::property_preview_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "preview-text"};
  }

  auto
  FontChooser::property_preview_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "preview-text"};
  }

  auto
  FontChooser::property_show_preview_entry () -> Glib::PropertyProxy<bool>
  {
    return {this, "show-preview-entry"};
  }

  auto
  FontChooser::property_show_preview_entry () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-preview-entry"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Level>::value,
      "Type Level cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontChooser::property_level () -> Glib::PropertyProxy<Level>
  {
    return {this, "level"};
  }

  auto
  FontChooser::property_level () const -> Glib::PropertyProxy_ReadOnly<Level>
  {
    return {this, "level"};
  }

  auto
  FontChooser::property_font_features () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "font-features"};
  }

  auto
  FontChooser::property_language () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "language"};
  }

  auto
  FontChooser::property_language () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "language"};
  }

  auto
  FontChooser::on_font_activated (const Glib::ustring& fontname) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->font_activated)
      (*base->font_activated) (gobj (), fontname.c_str ());
  }

} // namespace Gtk
