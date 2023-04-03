// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/fontdialog.hxx>
#include <libmm/gtk/fontdialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace Gtk
{
  auto
  FontDialog::choose_font_and_features_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> std::tuple<Pango::FontDescription, Glib::ustring, Pango::Language>
  {
    GError* gerror = nullptr;
    PangoFontDescription* font_desc = nullptr;
    char* font_features = nullptr;
    PangoLanguage* language = nullptr;

    (void) gtk_font_dialog_choose_font_and_features_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        Glib::unwrap (result),
        &font_desc,
        &font_features,
        &language,
        &gerror);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);

    return {Glib::wrap (font_desc),
            Glib::convert_return_gchar_ptr_to_ustring (font_features),
            Glib::wrap (language)};
  }
} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFontDialog* object, bool take_copy) -> Glib::RefPtr<Gtk::FontDialog>
  {
    return Glib::make_refptr_for_instance<Gtk::FontDialog> (
        dynamic_cast<Gtk::FontDialog*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_font_dialog_get_type ();
    }

    return *this;
  }

  auto
  FontDialog_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FontDialog ((GtkFontDialog*) object);
  }

  auto
  FontDialog::gobj_copy () -> GtkFontDialog*
  {
    reference ();
    return gobj ();
  }

  FontDialog::FontDialog (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FontDialog::FontDialog (GtkFontDialog* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FontDialog::FontDialog (FontDialog&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  FontDialog::operator= (FontDialog&& src) noexcept -> FontDialog&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  FontDialog::~FontDialog () noexcept {}

  FontDialog::CppClassType FontDialog::fontdialog_class_;

  auto
  FontDialog::get_type () -> GType
  {
    return fontdialog_class_.init ().get_type ();
  }

  auto
  FontDialog::get_base_type () -> GType
  {
    return gtk_font_dialog_get_type ();
  }

  FontDialog::FontDialog ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (fontdialog_class_.init ()))
  {
  }

  auto
  FontDialog::create () -> Glib::RefPtr<FontDialog>
  {
    return Glib::make_refptr_for_instance<FontDialog> (new FontDialog ());
  }

  auto
  FontDialog::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_font_dialog_get_title (const_cast<GtkFontDialog*> (gobj ())));
  }

  auto
  FontDialog::set_title (const Glib::ustring& title) -> void
  {
    gtk_font_dialog_set_title (gobj (), title.c_str ());
  }

  auto
  FontDialog::get_modal () const -> bool
  {
    return gtk_font_dialog_get_modal (const_cast<GtkFontDialog*> (gobj ()));
  }

  auto
  FontDialog::set_modal (bool modal) -> void
  {
    gtk_font_dialog_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  FontDialog::get_language () const -> Pango::Language
  {
    return Pango::Language (
        gtk_font_dialog_get_language (const_cast<GtkFontDialog*> (gobj ())));
  }

  auto
  FontDialog::set_language (const Pango::Language& language) -> void
  {
    gtk_font_dialog_set_language (
        gobj (),
        const_cast<PangoLanguage*> ((language).gobj ()));
  }

  auto
  FontDialog::get_font_map () -> Glib::RefPtr<Pango::FontMap>
  {
    auto retvalue = Glib::wrap (gtk_font_dialog_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialog::get_font_map () const -> Glib::RefPtr<const Pango::FontMap>
  {
    return const_cast<FontDialog*> (this)->get_font_map ();
  }

  auto
  FontDialog::set_font_map (const Glib::RefPtr<Pango::FontMap>& fontmap) -> void
  {
    gtk_font_dialog_set_font_map (gobj (), Glib::unwrap (fontmap));
  }

  auto
  FontDialog::get_filter () -> Glib::RefPtr<Filter>
  {
    auto retvalue = Glib::wrap (gtk_font_dialog_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialog::get_filter () const -> Glib::RefPtr<const Filter>
  {
    return const_cast<FontDialog*> (this)->get_filter ();
  }

  auto
  FontDialog::set_filter (const Glib::RefPtr<Filter>& filter) -> void
  {
    gtk_font_dialog_set_filter (gobj (), Glib::unwrap (filter));
  }

  auto
  FontDialog::choose_family (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Pango::FontFamily>& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_family (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        Glib::unwrap (initial_value),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_family (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Pango::FontFamily>& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_family (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        Glib::unwrap (initial_value),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_family_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Pango::FontFamily>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_font_dialog_choose_family_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_face (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Pango::FontFace>& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_face (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        Glib::unwrap (initial_value),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_face (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Pango::FontFace>& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_face (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        Glib::unwrap (initial_value),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_face_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
      const -> Glib::RefPtr<Pango::FontFace>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_font_dialog_choose_face_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_font (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Pango::FontDescription& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      const Gio::SlotAsyncReady& slot,
      const Pango::FontDescription& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
      const -> Pango::FontDescription
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_font_dialog_choose_font_finish (
                                    const_cast<GtkFontDialog*> (gobj ()),
                                    Glib::unwrap (result),
                                    &(gerror)),
                                false);
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_font_and_features (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Pango::FontDescription& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      const Gio::SlotAsyncReady& slot,
      const Pango::FontDescription& initial_value,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  FontDialog::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  FontDialog::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  FontDialog::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Language>::value,
      "Type Pango::Language cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialog::property_language () -> Glib::PropertyProxy<Pango::Language>
  {
    return Glib::PropertyProxy<Pango::Language> (this, "language");
  }

  auto
  FontDialog::property_language () const -> Glib::PropertyProxy_ReadOnly<Pango::Language>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Language> (this, "language");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Pango::FontMap>>::value,
      "Type Glib::RefPtr<Pango::FontMap> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialog::property_font_map () -> Glib::PropertyProxy<Glib::RefPtr<Pango::FontMap>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Pango::FontMap>> (this, "font-map");
  }

  auto
  FontDialog::property_font_map () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Pango::FontMap>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Pango::FontMap>> (
        this,
        "font-map");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Filter>>::value,
      "Type Glib::RefPtr<Filter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FontDialog::property_filter () -> Glib::PropertyProxy<Glib::RefPtr<Filter>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FontDialog::property_filter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>> (this, "filter");
  }

} // namespace Gtk
