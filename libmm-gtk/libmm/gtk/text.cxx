// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/text.hxx>
#include <libmm/gtk/text_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkText* object, bool take_copy) -> gtk::Text*
  {
    return dynamic_cast<gtk::Text*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Text_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Text_Class::class_init_function;

      register_derived_type (gtk_text_get_type ());

      Editable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Text_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Text_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Text ((GtkText*) (o)));
  }

  Text::Text (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Text::Text (GtkText* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Text::Text (Text&& src) noexcept
    : gtk::Widget (std::move (src)),
      Editable (std::move (src))
  {
  }

  auto
  Text::operator= (Text&& src) noexcept -> Text&
  {
    gtk::Widget::operator= (std::move (src));
    Editable::operator= (std::move (src));
    return *this;
  }

  Text::~Text () noexcept
  {
    destroy_ ();
  }

  Text::CppClassType Text::text_class_;

  auto
  Text::get_type () -> GType
  {
    return text_class_.init ().get_type ();
  }

  auto
  Text::get_base_type () -> GType
  {
    return gtk_text_get_type ();
  }

  Text::Text ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (text_class_.init ()))
  {
  }

  Text::Text (const glib::RefPtr<EntryBuffer>& buffer)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (text_class_.init (),
                                          "buffer",
                                          glib::unwrap (buffer),
                                          nullptr))
  {
  }

  auto
  Text::get_buffer () -> glib::RefPtr<EntryBuffer>
  {
    auto retvalue = glib::wrap (gtk_text_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Text::get_buffer () const -> glib::RefPtr<const EntryBuffer>
  {
    return const_cast<Text*> (this)->get_buffer ();
  }

  auto
  Text::set_buffer (const glib::RefPtr<EntryBuffer>& buffer) -> void
  {
    gtk_text_set_buffer (gobj (), glib::unwrap (buffer));
  }

  auto
  Text::set_visibility (bool visible) -> void
  {
    gtk_text_set_visibility (gobj (), static_cast<int> (visible));
  }

  auto
  Text::get_visibility () const -> bool
  {
    return gtk_text_get_visibility (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_invisible_char (gunichar ch) -> void
  {
    gtk_text_set_invisible_char (gobj (), ch);
  }

  auto
  Text::unset_invisible_char () -> void
  {
    gtk_text_unset_invisible_char (gobj ());
  }

  auto
  Text::get_invisible_char () const -> gunichar
  {
    return gtk_text_get_invisible_char (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_overwrite_mode (bool overwrite) -> void
  {
    gtk_text_set_overwrite_mode (gobj (), static_cast<int> (overwrite));
  }

  auto
  Text::get_overwrite_mode () const -> bool
  {
    return gtk_text_get_overwrite_mode (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_max_length (int max) -> void
  {
    gtk_text_set_max_length (gobj (), max);
  }

  auto
  Text::get_max_length () const -> int
  {
    return gtk_text_get_max_length (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::get_text_length () const -> guint16
  {
    return gtk_text_get_text_length (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_activates_default (bool setting) -> void
  {
    gtk_text_set_activates_default (gobj (), static_cast<int> (setting));
  }

  auto
  Text::get_activates_default () const -> bool
  {
    return gtk_text_get_activates_default (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::get_placeholder_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_text_get_placeholder_text (const_cast<GtkText*> (gobj ())));
  }

  auto
  Text::set_placeholder_text (const glib::ustring& text) -> void
  {
    gtk_text_set_placeholder_text (gobj (), text.c_str ());
  }

  auto
  Text::set_input_purpose (InputPurpose purpose) -> void
  {
    gtk_text_set_input_purpose (gobj (),
                                static_cast<GtkInputPurpose> (purpose));
  }

  auto
  Text::get_input_purpose () const -> InputPurpose
  {
    return static_cast<InputPurpose> (
        gtk_text_get_input_purpose (const_cast<GtkText*> (gobj ())));
  }

  auto
  Text::set_input_hints (InputHints hints) -> void
  {
    gtk_text_set_input_hints (gobj (), static_cast<GtkInputHints> (hints));
  }

  auto
  Text::get_input_hints () const -> InputHints
  {
    return static_cast<InputHints> (
        gtk_text_get_input_hints (const_cast<GtkText*> (gobj ())));
  }

  auto
  Text::set_attributes (pango::AttrList& attrs) -> void
  {
    gtk_text_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Text::get_attributes () const -> pango::AttrList
  {
    return pango::AttrList (
        (gtk_text_get_attributes (const_cast<GtkText*> (gobj ()))));
  }

  auto
  Text::set_tabs (const pango::TabArray& tabs) -> void
  {
    gtk_text_set_tabs (gobj (), const_cast<pango::TabArray&> (tabs).gobj ());
  }

  auto
  Text::get_tabs () const -> pango::TabArray
  {
    return pango::TabArray (
        (gtk_text_get_tabs (const_cast<GtkText*> (gobj ()))));
  }

  auto
  Text::grab_focus_without_selecting () -> bool
  {
    return gtk_text_grab_focus_without_selecting (gobj ());
  }

  auto
  Text::set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_text_set_extra_menu (gobj (), glib::unwrap (model));
  }

  auto
  Text::get_extra_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_text_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Text::get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<Text*> (this)->get_extra_menu ();
  }

  auto
  Text::set_enable_emoji_completion (bool enable_emoji_completion) -> void
  {
    gtk_text_set_enable_emoji_completion (
        gobj (),
        static_cast<int> (enable_emoji_completion));
  }

  auto
  Text::get_enable_emoji_completion () const -> bool
  {
    return gtk_text_get_enable_emoji_completion (
        const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_propagate_text_width (bool propagate_text_width) -> void
  {
    gtk_text_set_propagate_text_width (gobj (),
                                       static_cast<int> (propagate_text_width));
  }

  auto
  Text::get_propagate_text_width () const -> bool
  {
    return gtk_text_get_propagate_text_width (const_cast<GtkText*> (gobj ()));
  }

  auto
  Text::set_truncate_multiline (bool truncate_multiline) -> void
  {
    gtk_text_set_truncate_multiline (gobj (),
                                     static_cast<int> (truncate_multiline));
  }

  auto
  Text::get_truncate_multiline () const -> bool
  {
    return gtk_text_get_truncate_multiline (const_cast<GtkText*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<EntryBuffer>>::value,
      "Type glib::RefPtr<EntryBuffer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_buffer () -> glib::PropertyProxy<glib::RefPtr<EntryBuffer>>
  {
    return glib::PropertyProxy<glib::RefPtr<EntryBuffer>> (this, "buffer");
  }

  auto
  Text::property_buffer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryBuffer>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryBuffer>> (this,
                                                                    "buffer");
  }

  auto
  Text::property_max_length () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-length");
  }

  auto
  Text::property_max_length () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-length");
  }

  auto
  Text::property_visibility () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visibility");
  }

  auto
  Text::property_visibility () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visibility");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gunichar>::value,
      "Type gunichar cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_invisible_char () -> glib::PropertyProxy<gunichar>
  {
    return glib::PropertyProxy<gunichar> (this, "invisible-char");
  }

  auto
  Text::property_invisible_char () const -> glib::PropertyProxy_ReadOnly<gunichar>
  {
    return glib::PropertyProxy_ReadOnly<gunichar> (this, "invisible-char");
  }

  auto
  Text::property_invisible_char_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "invisible-char-set");
  }

  auto
  Text::property_invisible_char_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "invisible-char-set");
  }

  auto
  Text::property_activates_default () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  Text::property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  Text::property_scroll_offset () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "scroll-offset");
  }

  auto
  Text::property_truncate_multiline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "truncate-multiline");
  }

  auto
  Text::property_truncate_multiline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "truncate-multiline");
  }

  auto
  Text::property_overwrite_mode () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "overwrite-mode");
  }

  auto
  Text::property_overwrite_mode () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "overwrite-mode");
  }

  auto
  Text::property_im_module () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "im-module");
  }

  auto
  Text::property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "im-module");
  }

  auto
  Text::property_placeholder_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "placeholder-text");
  }

  auto
  Text::property_placeholder_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "placeholder-text");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
      "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_input_purpose () -> glib::PropertyProxy<InputPurpose>
  {
    return glib::PropertyProxy<InputPurpose> (this, "input-purpose");
  }

  auto
  Text::property_input_purpose () const -> glib::PropertyProxy_ReadOnly<InputPurpose>
  {
    return glib::PropertyProxy_ReadOnly<InputPurpose> (this, "input-purpose");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
      "Type InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_input_hints () -> glib::PropertyProxy<InputHints>
  {
    return glib::PropertyProxy<InputHints> (this, "input-hints");
  }

  auto
  Text::property_input_hints () const -> glib::PropertyProxy_ReadOnly<InputHints>
  {
    return glib::PropertyProxy_ReadOnly<InputHints> (this, "input-hints");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::AttrList>::value,
      "Type pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return glib::PropertyProxy<pango::AttrList> (this, "attributes");
  }

  auto
  Text::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return glib::PropertyProxy_ReadOnly<pango::AttrList> (this, "attributes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::TabArray>::value,
      "Type pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_tabs () -> glib::PropertyProxy<pango::TabArray>
  {
    return glib::PropertyProxy<pango::TabArray> (this, "tabs");
  }

  auto
  Text::property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>
  {
    return glib::PropertyProxy_ReadOnly<pango::TabArray> (this, "tabs");
  }

  auto
  Text::property_enable_emoji_completion () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-emoji-completion");
  }

  auto
  Text::property_enable_emoji_completion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-emoji-completion");
  }

  auto
  Text::property_propagate_text_width () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "propagate-text-width");
  }

  auto
  Text::property_propagate_text_width () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "propagate-text-width");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Text::property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  Text::property_extra_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "extra-menu");
  }

} // namespace gtk
