// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/fontdialog.hxx>
#include <libmm/gtk/fontdialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace gtk
{
  auto
  FontDialog::choose_font_and_features_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> std::tuple<pango::FontDescription, glib::ustring, pango::Language>
  {
    GError* gerror = nullptr;
    PangoFontDescription* font_desc = nullptr;
    char* font_features = nullptr;
    PangoLanguage* language = nullptr;

    (void) gtk_font_dialog_choose_font_and_features_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        glib::unwrap (result),
        &font_desc,
        &font_features,
        &language,
        &gerror);
    if (gerror)
      ::glib::Error::throw_exception (gerror);

    return {glib::wrap (font_desc),
            glib::convert_return_gchar_ptr_to_ustring (font_features),
            glib::wrap (language)};
  }
} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFontDialog* object, bool take_copy) -> glib::RefPtr<gtk::FontDialog>
  {
    return glib::make_refptr_for_instance<gtk::FontDialog> (
        dynamic_cast<gtk::FontDialog*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FontDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_font_dialog_get_type ();
    }

    return *this;
  }

  auto
  FontDialog_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FontDialog ((GtkFontDialog*) object);
  }

  auto
  FontDialog::gobj_copy () -> GtkFontDialog*
  {
    reference ();
    return gobj ();
  }

  FontDialog::FontDialog (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FontDialog::FontDialog (GtkFontDialog* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FontDialog::FontDialog (FontDialog&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  FontDialog::operator= (FontDialog&& src) noexcept -> FontDialog&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (fontdialog_class_.init ()))
  {
  }

  auto
  FontDialog::create () -> glib::RefPtr<FontDialog>
  {
    return glib::make_refptr_for_instance<FontDialog> (new FontDialog ());
  }

  auto
  FontDialog::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_font_dialog_get_title (const_cast<GtkFontDialog*> (gobj ())));
  }

  auto
  FontDialog::set_title (const glib::ustring& title) -> void
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
  FontDialog::get_language () const -> pango::Language
  {
    return pango::Language (
        gtk_font_dialog_get_language (const_cast<GtkFontDialog*> (gobj ())));
  }

  auto
  FontDialog::set_language (const pango::Language& language) -> void
  {
    gtk_font_dialog_set_language (
        gobj (),
        const_cast<PangoLanguage*> ((language).gobj ()));
  }

  auto
  FontDialog::get_font_map () -> glib::RefPtr<pango::FontMap>
  {
    auto retvalue = glib::wrap (gtk_font_dialog_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialog::get_font_map () const -> glib::RefPtr<const pango::FontMap>
  {
    return const_cast<FontDialog*> (this)->get_font_map ();
  }

  auto
  FontDialog::set_font_map (const glib::RefPtr<pango::FontMap>& fontmap) -> void
  {
    gtk_font_dialog_set_font_map (gobj (), glib::unwrap (fontmap));
  }

  auto
  FontDialog::get_filter () -> glib::RefPtr<Filter>
  {
    auto retvalue = glib::wrap (gtk_font_dialog_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontDialog::get_filter () const -> glib::RefPtr<const Filter>
  {
    return const_cast<FontDialog*> (this)->get_filter ();
  }

  auto
  FontDialog::set_filter (const glib::RefPtr<Filter>& filter) -> void
  {
    gtk_font_dialog_set_filter (gobj (), glib::unwrap (filter));
  }

  auto
  FontDialog::choose_family (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<pango::FontFamily>& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_family (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        glib::unwrap (initial_value),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_family (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<pango::FontFamily>& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_family (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        glib::unwrap (initial_value),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_family_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<pango::FontFamily>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_font_dialog_choose_family_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_face (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<pango::FontFace>& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_face (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        glib::unwrap (initial_value),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_face (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<pango::FontFace>& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_face (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        glib::unwrap (initial_value),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_face_finish (const glib::RefPtr<gio::AsyncResult>& result)
      const -> glib::RefPtr<pango::FontFace>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_font_dialog_choose_face_finish (
        const_cast<GtkFontDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_font (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const pango::FontDescription& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      const gio::SlotAsyncReady& slot,
      const pango::FontDescription& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_finish (const glib::RefPtr<gio::AsyncResult>& result)
      const -> pango::FontDescription
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_font_dialog_choose_font_finish (
                                    const_cast<GtkFontDialog*> (gobj ()),
                                    glib::unwrap (result),
                                    &(gerror)),
                                false);
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FontDialog::choose_font_and_features (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const pango::FontDescription& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        (parent).gobj (),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      const gio::SlotAsyncReady& slot,
      const pango::FontDescription& initial_value,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        const_cast<PangoFontDescription*> ((initial_value).gobj ()),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::choose_font_and_features (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_font_dialog_choose_font_and_features (
        const_cast<GtkFontDialog*> (gobj ()),
        nullptr,
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FontDialog::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  FontDialog::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  FontDialog::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  FontDialog::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Language>::value,
      "Type pango::Language cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialog::property_language () -> glib::PropertyProxy<pango::Language>
  {
    return glib::PropertyProxy<pango::Language> (this, "language");
  }

  auto
  FontDialog::property_language () const -> glib::PropertyProxy_ReadOnly<pango::Language>
  {
    return glib::PropertyProxy_ReadOnly<pango::Language> (this, "language");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<pango::FontMap>>::value,
      "Type glib::RefPtr<pango::FontMap> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialog::property_font_map () -> glib::PropertyProxy<glib::RefPtr<pango::FontMap>>
  {
    return glib::PropertyProxy<glib::RefPtr<pango::FontMap>> (this, "font-map");
  }

  auto
  FontDialog::property_font_map () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<pango::FontMap>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<pango::FontMap>> (
        this,
        "font-map");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Filter>>::value,
      "Type glib::RefPtr<Filter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FontDialog::property_filter () -> glib::PropertyProxy<glib::RefPtr<Filter>>
  {
    return glib::PropertyProxy<glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FontDialog::property_filter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>> (this, "filter");
  }

} // namespace gtk
