// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/texttag.hxx>
#include <libmm-gtk/texttag_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTextTag* object, bool take_copy) -> Glib::RefPtr<Gtk::TextTag>
  {
    return Glib::make_refptr_for_instance<Gtk::TextTag> (
        dynamic_cast<Gtk::TextTag*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextTag_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextTag_Class::class_init_function;

      register_derived_type (gtk_text_tag_get_type ());
    }

    return *this;
  }

  auto
  TextTag_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TextTag_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TextTag ((GtkTextTag*) object);
  }

  auto
  TextTag::gobj_copy () -> GtkTextTag*
  {
    reference ();
    return gobj ();
  }

  TextTag::TextTag (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TextTag::TextTag (GtkTextTag* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TextTag::TextTag (TextTag&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TextTag::operator= (TextTag&& src) noexcept -> TextTag&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  TextTag::~TextTag () noexcept {}

  TextTag::CppClassType TextTag::texttag_class_;

  auto
  TextTag::get_type () -> GType
  {
    return texttag_class_.init ().get_type ();
  }

  auto
  TextTag::get_base_type () -> GType
  {
    return gtk_text_tag_get_type ();
  }

  TextTag::TextTag ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (texttag_class_.init ()))
  {
  }

  TextTag::TextTag (const Glib::ustring& name)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (texttag_class_.init (),
                                           "name",
                                           name.c_str (),
                                           nullptr))
  {
  }

  auto
  TextTag::create () -> Glib::RefPtr<TextTag>
  {
    return Glib::make_refptr_for_instance<TextTag> (new TextTag ());
  }

  auto
  TextTag::create (const Glib::ustring& name) -> Glib::RefPtr<TextTag>
  {
    return Glib::make_refptr_for_instance<TextTag> (new TextTag (name));
  }

  auto
  TextTag::get_priority () const -> int
  {
    return gtk_text_tag_get_priority (const_cast<GtkTextTag*> (gobj ()));
  }

  auto
  TextTag::set_priority (int priority) -> void
  {
    gtk_text_tag_set_priority (gobj (), priority);
  }

  auto
  TextTag::tag_changed (bool size_changed) -> void
  {
    gtk_text_tag_changed (gobj (), static_cast<int> (size_changed));
  }

  auto
  TextTag::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  TextTag::property_background () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_WriteOnly<Glib::ustring> (this, "background");
  }

  auto
  TextTag::property_foreground () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_WriteOnly<Glib::ustring> (this, "foreground");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "background-rgba");
  }

  auto
  TextTag::property_background_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "background-rgba");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_foreground_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  TextTag::property_foreground_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  TextTag::property_font () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "font");
  }

  auto
  TextTag::property_font () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "font");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Pango::FontDescription>::value,
      "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_font_desc () -> Glib::PropertyProxy<Pango::FontDescription>
  {
    return Glib::PropertyProxy<Pango::FontDescription> (this, "font-desc");
  }

  auto
  TextTag::property_font_desc () const -> Glib::PropertyProxy_ReadOnly<Pango::FontDescription>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  TextTag::property_family () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "family");
  }

  auto
  TextTag::property_family () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "family");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Style>::value,
      "Type Pango::Style cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_style () -> Glib::PropertyProxy<Pango::Style>
  {
    return Glib::PropertyProxy<Pango::Style> (this, "style");
  }

  auto
  TextTag::property_style () const -> Glib::PropertyProxy_ReadOnly<Pango::Style>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Style> (this, "style");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Variant>::value,
      "Type Pango::Variant cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_variant () -> Glib::PropertyProxy<Pango::Variant>
  {
    return Glib::PropertyProxy<Pango::Variant> (this, "variant");
  }

  auto
  TextTag::property_variant () const -> Glib::PropertyProxy_ReadOnly<Pango::Variant>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Variant> (this, "variant");
  }

  auto
  TextTag::property_weight () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "weight");
  }

  auto
  TextTag::property_weight () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "weight");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Stretch>::value,
      "Type Pango::Stretch cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_stretch () -> Glib::PropertyProxy<Pango::Stretch>
  {
    return Glib::PropertyProxy<Pango::Stretch> (this, "stretch");
  }

  auto
  TextTag::property_stretch () const -> Glib::PropertyProxy_ReadOnly<Pango::Stretch>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Stretch> (this, "stretch");
  }

  auto
  TextTag::property_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "size");
  }

  auto
  TextTag::property_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  auto
  TextTag::property_size_points () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "size-points");
  }

  auto
  TextTag::property_size_points () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "size-points");
  }

  auto
  TextTag::property_scale () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "scale");
  }

  auto
  TextTag::property_scale () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "scale");
  }

  auto
  TextTag::property_pixels_above_lines () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "pixels-above-lines");
  }

  auto
  TextTag::property_pixels_above_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "pixels-above-lines");
  }

  auto
  TextTag::property_pixels_below_lines () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "pixels-below-lines");
  }

  auto
  TextTag::property_pixels_below_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "pixels-below-lines");
  }

  auto
  TextTag::property_pixels_inside_wrap () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "pixels-inside-wrap");
  }

  auto
  TextTag::property_pixels_inside_wrap () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "pixels-inside-wrap");
  }

  auto
  TextTag::property_editable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "editable");
  }

  auto
  TextTag::property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "editable");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<WrapMode>::value,
      "Type WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_wrap_mode () -> Glib::PropertyProxy<WrapMode>
  {
    return Glib::PropertyProxy<WrapMode> (this, "wrap-mode");
  }

  auto
  TextTag::property_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<WrapMode>
  {
    return Glib::PropertyProxy_ReadOnly<WrapMode> (this, "wrap-mode");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_justification () -> Glib::PropertyProxy<Justification>
  {
    return Glib::PropertyProxy<Justification> (this, "justification");
  }

  auto
  TextTag::property_justification () const -> Glib::PropertyProxy_ReadOnly<Justification>
  {
    return Glib::PropertyProxy_ReadOnly<Justification> (this, "justification");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
      "Type TextDirection cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_direction () -> Glib::PropertyProxy<TextDirection>
  {
    return Glib::PropertyProxy<TextDirection> (this, "direction");
  }

  auto
  TextTag::property_direction () const -> Glib::PropertyProxy_ReadOnly<TextDirection>
  {
    return Glib::PropertyProxy_ReadOnly<TextDirection> (this, "direction");
  }

  auto
  TextTag::property_left_margin () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "left-margin");
  }

  auto
  TextTag::property_left_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "left-margin");
  }

  auto
  TextTag::property_indent () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "indent");
  }

  auto
  TextTag::property_indent () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "indent");
  }

  auto
  TextTag::property_line_height () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "line-height");
  }

  auto
  TextTag::property_line_height () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "line-height");
  }

  auto
  TextTag::property_strikethrough () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "strikethrough");
  }

  auto
  TextTag::property_strikethrough () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_strikethrough_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "strikethrough-rgba");
  }

  auto
  TextTag::property_strikethrough_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "strikethrough-rgba");
  }

  auto
  TextTag::property_right_margin () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "right-margin");
  }

  auto
  TextTag::property_right_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "right-margin");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Underline>::value,
      "Type Pango::Underline cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_underline () -> Glib::PropertyProxy<Pango::Underline>
  {
    return Glib::PropertyProxy<Pango::Underline> (this, "underline");
  }

  auto
  TextTag::property_underline () const -> Glib::PropertyProxy_ReadOnly<Pango::Underline>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Underline> (this, "underline");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_underline_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "underline-rgba");
  }

  auto
  TextTag::property_underline_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "underline-rgba");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Overline>::value,
      "Type Pango::Overline cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_overline () -> Glib::PropertyProxy<Pango::Overline>
  {
    return Glib::PropertyProxy<Pango::Overline> (this, "overline");
  }

  auto
  TextTag::property_overline () const -> Glib::PropertyProxy_ReadOnly<Pango::Overline>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::Overline> (this, "overline");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_overline_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "overline-rgba");
  }

  auto
  TextTag::property_overline_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (this, "overline-rgba");
  }

  auto
  TextTag::property_rise () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "rise");
  }

  auto
  TextTag::property_rise () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "rise");
  }

  auto
  TextTag::property_background_full_height () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "background-full-height");
  }

  auto
  TextTag::property_background_full_height () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "background-full-height");
  }

  auto
  TextTag::property_language () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "language");
  }

  auto
  TextTag::property_language () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "language");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
      "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_tabs () -> Glib::PropertyProxy<Pango::TabArray>
  {
    return Glib::PropertyProxy<Pango::TabArray> (this, "tabs");
  }

  auto
  TextTag::property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::TabArray> (this, "tabs");
  }

  auto
  TextTag::property_invisible () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "invisible");
  }

  auto
  TextTag::property_invisible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "invisible");
  }

  auto
  TextTag::property_paragraph_background () -> Glib::PropertyProxy_WriteOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_WriteOnly<Glib::ustring> (
        this,
        "paragraph-background");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
      "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_paragraph_background_rgba () -> Glib::PropertyProxy<Gdk::RGBA>
  {
    return Glib::PropertyProxy<Gdk::RGBA> (this, "paragraph-background-rgba");
  }

  auto
  TextTag::property_paragraph_background_rgba () const -> Glib::PropertyProxy_ReadOnly<Gdk::RGBA>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::RGBA> (
        this,
        "paragraph-background-rgba");
  }

  auto
  TextTag::property_font_features () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "font-features");
  }

  auto
  TextTag::property_font_features () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "font-features");
  }

  auto
  TextTag::property_allow_breaks () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-breaks");
  }

  auto
  TextTag::property_allow_breaks () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-breaks");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::ShowFlags>::value,
      "Type Pango::ShowFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_show_spaces () -> Glib::PropertyProxy<Pango::ShowFlags>
  {
    return Glib::PropertyProxy<Pango::ShowFlags> (this, "show-spaces");
  }

  auto
  TextTag::property_show_spaces () const -> Glib::PropertyProxy_ReadOnly<Pango::ShowFlags>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::ShowFlags> (this, "show-spaces");
  }

  auto
  TextTag::property_insert_hyphens () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "insert-hyphens");
  }

  auto
  TextTag::property_insert_hyphens () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "insert-hyphens");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Pango::TextTransform>::value,
      "Type Pango::TextTransform cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextTag::property_text_transform () -> Glib::PropertyProxy<Pango::TextTransform>
  {
    return Glib::PropertyProxy<Pango::TextTransform> (this, "text-transform");
  }

  auto
  TextTag::property_text_transform () const -> Glib::PropertyProxy_ReadOnly<Pango::TextTransform>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::TextTransform> (
        this,
        "text-transform");
  }

  auto
  TextTag::property_word () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "word");
  }

  auto
  TextTag::property_word () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "word");
  }

  auto
  TextTag::property_sentence () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "sentence");
  }

  auto
  TextTag::property_sentence () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "sentence");
  }

  auto
  TextTag::property_accumulative_margin () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "accumulative-margin");
  }

  auto
  TextTag::property_accumulative_margin () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "accumulative-margin");
  }

  auto
  TextTag::property_background_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "background-set");
  }

  auto
  TextTag::property_background_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "background-set");
  }

  auto
  TextTag::property_foreground_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "foreground-set");
  }

  auto
  TextTag::property_foreground_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "foreground-set");
  }

  auto
  TextTag::property_family_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "family-set");
  }

  auto
  TextTag::property_family_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "family-set");
  }

  auto
  TextTag::property_style_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "style-set");
  }

  auto
  TextTag::property_style_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "style-set");
  }

  auto
  TextTag::property_variant_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "variant-set");
  }

  auto
  TextTag::property_variant_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "variant-set");
  }

  auto
  TextTag::property_weight_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "weight-set");
  }

  auto
  TextTag::property_weight_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "weight-set");
  }

  auto
  TextTag::property_stretch_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "stretch-set");
  }

  auto
  TextTag::property_stretch_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "stretch-set");
  }

  auto
  TextTag::property_size_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "size-set");
  }

  auto
  TextTag::property_size_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "size-set");
  }

  auto
  TextTag::property_scale_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "scale-set");
  }

  auto
  TextTag::property_scale_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "scale-set");
  }

  auto
  TextTag::property_pixels_above_lines_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "pixels-above-lines-set");
  }

  auto
  TextTag::property_pixels_above_lines_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "pixels-above-lines-set");
  }

  auto
  TextTag::property_pixels_below_lines_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "pixels-below-lines-set");
  }

  auto
  TextTag::property_pixels_below_lines_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "pixels-below-lines-set");
  }

  auto
  TextTag::property_pixels_inside_wrap_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "pixels-inside-wrap-set");
  }

  auto
  TextTag::property_pixels_inside_wrap_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "pixels-inside-wrap-set");
  }

  auto
  TextTag::property_editable_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "editable-set");
  }

  auto
  TextTag::property_editable_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "editable-set");
  }

  auto
  TextTag::property_wrap_mode_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "wrap-mode-set");
  }

  auto
  TextTag::property_wrap_mode_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "wrap-mode-set");
  }

  auto
  TextTag::property_justification_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "justification-set");
  }

  auto
  TextTag::property_justification_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "justification-set");
  }

  auto
  TextTag::property_left_margin_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "left-margin-set");
  }

  auto
  TextTag::property_left_margin_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "left-margin-set");
  }

  auto
  TextTag::property_indent_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "indent-set");
  }

  auto
  TextTag::property_indent_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "indent-set");
  }

  auto
  TextTag::property_line_height_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "line-height-set");
  }

  auto
  TextTag::property_line_height_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "line-height-set");
  }

  auto
  TextTag::property_strikethrough_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "strikethrough-set");
  }

  auto
  TextTag::property_strikethrough_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough-set");
  }

  auto
  TextTag::property_strikethrough_rgba_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "strikethrough-rgba-set");
  }

  auto
  TextTag::property_strikethrough_rgba_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough-rgba-set");
  }

  auto
  TextTag::property_right_margin_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "right-margin-set");
  }

  auto
  TextTag::property_right_margin_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "right-margin-set");
  }

  auto
  TextTag::property_underline_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "underline-set");
  }

  auto
  TextTag::property_underline_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "underline-set");
  }

  auto
  TextTag::property_underline_rgba_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "underline-rgba-set");
  }

  auto
  TextTag::property_underline_rgba_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "underline-rgba-set");
  }

  auto
  TextTag::property_overline_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "overline-set");
  }

  auto
  TextTag::property_overline_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "overline-set");
  }

  auto
  TextTag::property_overline_rgba_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "overline-rgba-set");
  }

  auto
  TextTag::property_overline_rgba_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "overline-rgba-set");
  }

  auto
  TextTag::property_rise_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "rise-set");
  }

  auto
  TextTag::property_rise_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "rise-set");
  }

  auto
  TextTag::property_background_full_height_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "background-full-height-set");
  }

  auto
  TextTag::property_background_full_height_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "background-full-height-set");
  }

  auto
  TextTag::property_language_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "language-set");
  }

  auto
  TextTag::property_language_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "language-set");
  }

  auto
  TextTag::property_tabs_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "tabs-set");
  }

  auto
  TextTag::property_tabs_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "tabs-set");
  }

  auto
  TextTag::property_invisible_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "invisible-set");
  }

  auto
  TextTag::property_invisible_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "invisible-set");
  }

  auto
  TextTag::property_paragraph_background_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "paragraph-background-set");
  }

  auto
  TextTag::property_paragraph_background_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "paragraph-background-set");
  }

  auto
  TextTag::property_fallback () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "fallback");
  }

  auto
  TextTag::property_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "fallback");
  }

  auto
  TextTag::property_fallback_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "fallback-set");
  }

  auto
  TextTag::property_fallback_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "fallback-set");
  }

  auto
  TextTag::property_letter_spacing () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "letter-spacing");
  }

  auto
  TextTag::property_letter_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "letter-spacing");
  }

  auto
  TextTag::property_letter_spacing_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "letter-spacing-set");
  }

  auto
  TextTag::property_letter_spacing_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "letter-spacing-set");
  }

  auto
  TextTag::property_font_features_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "font-features-set");
  }

  auto
  TextTag::property_font_features_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "font-features-set");
  }

  auto
  TextTag::property_allow_breaks_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "allow-breaks-set");
  }

  auto
  TextTag::property_allow_breaks_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "allow-breaks-set");
  }

  auto
  TextTag::property_show_spaces_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-spaces-set");
  }

  auto
  TextTag::property_show_spaces_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-spaces-set");
  }

  auto
  TextTag::property_insert_hyphens_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "insert-hyphens-set");
  }

  auto
  TextTag::property_insert_hyphens_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "insert-hyphens-set");
  }

  auto
  TextTag::property_text_transform_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "text-transform-set");
  }

  auto
  TextTag::property_text_transform_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "text-transform-set");
  }

  auto
  TextTag::property_word_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "word-set");
  }

  auto
  TextTag::property_word_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "word-set");
  }

  auto
  TextTag::property_sentence_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "sentence-set");
  }

  auto
  TextTag::property_sentence_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "sentence-set");
  }

} // namespace Gtk
