// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/texttag.hxx>
#include <libmm/gtk/texttag_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTextTag* object, bool take_copy) -> glib::RefPtr<gtk::TextTag>
  {
    return glib::make_refptr_for_instance<gtk::TextTag> (
        dynamic_cast<gtk::TextTag*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TextTag_Class::init () -> const glib::Class&
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
  TextTag_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TextTag ((GtkTextTag*) object);
  }

  auto
  TextTag::gobj_copy () -> GtkTextTag*
  {
    reference ();
    return gobj ();
  }

  TextTag::TextTag (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  TextTag::TextTag (GtkTextTag* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  TextTag::TextTag (TextTag&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  TextTag::operator= (TextTag&& src) noexcept -> TextTag&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (texttag_class_.init ()))
  {
  }

  TextTag::TextTag (const glib::ustring& name)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (texttag_class_.init (),
                                           "name",
                                           name.c_str (),
                                           nullptr))
  {
  }

  auto
  TextTag::create () -> glib::RefPtr<TextTag>
  {
    return glib::make_refptr_for_instance<TextTag> (new TextTag ());
  }

  auto
  TextTag::create (const glib::ustring& name) -> glib::RefPtr<TextTag>
  {
    return glib::make_refptr_for_instance<TextTag> (new TextTag (name));
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
  TextTag::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  TextTag::property_background () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "background");
  }

  auto
  TextTag::property_foreground () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (this, "foreground");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_background_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "background-rgba");
  }

  auto
  TextTag::property_background_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "background-rgba");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_foreground_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  TextTag::property_foreground_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "foreground-rgba");
  }

  auto
  TextTag::property_font () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "font");
  }

  auto
  TextTag::property_font () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::FontDescription>::value,
      "Type pango::FontDescription cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_font_desc () -> glib::PropertyProxy<pango::FontDescription>
  {
    return glib::PropertyProxy<pango::FontDescription> (this, "font-desc");
  }

  auto
  TextTag::property_font_desc () const -> glib::PropertyProxy_ReadOnly<pango::FontDescription>
  {
    return glib::PropertyProxy_ReadOnly<pango::FontDescription> (this,
                                                                 "font-desc");
  }

  auto
  TextTag::property_family () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "family");
  }

  auto
  TextTag::property_family () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "family");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Style>::value,
      "Type pango::Style cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_style () -> glib::PropertyProxy<pango::Style>
  {
    return glib::PropertyProxy<pango::Style> (this, "style");
  }

  auto
  TextTag::property_style () const -> glib::PropertyProxy_ReadOnly<pango::Style>
  {
    return glib::PropertyProxy_ReadOnly<pango::Style> (this, "style");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Variant>::value,
      "Type pango::Variant cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_variant () -> glib::PropertyProxy<pango::Variant>
  {
    return glib::PropertyProxy<pango::Variant> (this, "variant");
  }

  auto
  TextTag::property_variant () const -> glib::PropertyProxy_ReadOnly<pango::Variant>
  {
    return glib::PropertyProxy_ReadOnly<pango::Variant> (this, "variant");
  }

  auto
  TextTag::property_weight () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "weight");
  }

  auto
  TextTag::property_weight () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "weight");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Stretch>::value,
      "Type pango::Stretch cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_stretch () -> glib::PropertyProxy<pango::Stretch>
  {
    return glib::PropertyProxy<pango::Stretch> (this, "stretch");
  }

  auto
  TextTag::property_stretch () const -> glib::PropertyProxy_ReadOnly<pango::Stretch>
  {
    return glib::PropertyProxy_ReadOnly<pango::Stretch> (this, "stretch");
  }

  auto
  TextTag::property_size () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "size");
  }

  auto
  TextTag::property_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  auto
  TextTag::property_size_points () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "size-points");
  }

  auto
  TextTag::property_size_points () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "size-points");
  }

  auto
  TextTag::property_scale () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "scale");
  }

  auto
  TextTag::property_scale () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "scale");
  }

  auto
  TextTag::property_pixels_above_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-above-lines");
  }

  auto
  TextTag::property_pixels_above_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-above-lines");
  }

  auto
  TextTag::property_pixels_below_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-below-lines");
  }

  auto
  TextTag::property_pixels_below_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-below-lines");
  }

  auto
  TextTag::property_pixels_inside_wrap () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-inside-wrap");
  }

  auto
  TextTag::property_pixels_inside_wrap () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-inside-wrap");
  }

  auto
  TextTag::property_editable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editable");
  }

  auto
  TextTag::property_editable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<WrapMode>::value,
      "Type WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_wrap_mode () -> glib::PropertyProxy<WrapMode>
  {
    return glib::PropertyProxy<WrapMode> (this, "wrap-mode");
  }

  auto
  TextTag::property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<WrapMode>
  {
    return glib::PropertyProxy_ReadOnly<WrapMode> (this, "wrap-mode");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_justification () -> glib::PropertyProxy<Justification>
  {
    return glib::PropertyProxy<Justification> (this, "justification");
  }

  auto
  TextTag::property_justification () const -> glib::PropertyProxy_ReadOnly<Justification>
  {
    return glib::PropertyProxy_ReadOnly<Justification> (this, "justification");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
      "Type TextDirection cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_direction () -> glib::PropertyProxy<TextDirection>
  {
    return glib::PropertyProxy<TextDirection> (this, "direction");
  }

  auto
  TextTag::property_direction () const -> glib::PropertyProxy_ReadOnly<TextDirection>
  {
    return glib::PropertyProxy_ReadOnly<TextDirection> (this, "direction");
  }

  auto
  TextTag::property_left_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "left-margin");
  }

  auto
  TextTag::property_left_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "left-margin");
  }

  auto
  TextTag::property_indent () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "indent");
  }

  auto
  TextTag::property_indent () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "indent");
  }

  auto
  TextTag::property_line_height () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "line-height");
  }

  auto
  TextTag::property_line_height () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "line-height");
  }

  auto
  TextTag::property_strikethrough () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "strikethrough");
  }

  auto
  TextTag::property_strikethrough () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_strikethrough_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "strikethrough-rgba");
  }

  auto
  TextTag::property_strikethrough_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "strikethrough-rgba");
  }

  auto
  TextTag::property_right_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "right-margin");
  }

  auto
  TextTag::property_right_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "right-margin");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Underline>::value,
      "Type pango::Underline cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_underline () -> glib::PropertyProxy<pango::Underline>
  {
    return glib::PropertyProxy<pango::Underline> (this, "underline");
  }

  auto
  TextTag::property_underline () const -> glib::PropertyProxy_ReadOnly<pango::Underline>
  {
    return glib::PropertyProxy_ReadOnly<pango::Underline> (this, "underline");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_underline_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "underline-rgba");
  }

  auto
  TextTag::property_underline_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "underline-rgba");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::Overline>::value,
      "Type pango::Overline cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_overline () -> glib::PropertyProxy<pango::Overline>
  {
    return glib::PropertyProxy<pango::Overline> (this, "overline");
  }

  auto
  TextTag::property_overline () const -> glib::PropertyProxy_ReadOnly<pango::Overline>
  {
    return glib::PropertyProxy_ReadOnly<pango::Overline> (this, "overline");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_overline_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "overline-rgba");
  }

  auto
  TextTag::property_overline_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (this, "overline-rgba");
  }

  auto
  TextTag::property_rise () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "rise");
  }

  auto
  TextTag::property_rise () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "rise");
  }

  auto
  TextTag::property_background_full_height () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "background-full-height");
  }

  auto
  TextTag::property_background_full_height () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "background-full-height");
  }

  auto
  TextTag::property_language () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "language");
  }

  auto
  TextTag::property_language () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "language");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::TabArray>::value,
      "Type pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_tabs () -> glib::PropertyProxy<pango::TabArray>
  {
    return glib::PropertyProxy<pango::TabArray> (this, "tabs");
  }

  auto
  TextTag::property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>
  {
    return glib::PropertyProxy_ReadOnly<pango::TabArray> (this, "tabs");
  }

  auto
  TextTag::property_invisible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "invisible");
  }

  auto
  TextTag::property_invisible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "invisible");
  }

  auto
  TextTag::property_paragraph_background () -> glib::PropertyProxy_WriteOnly<glib::ustring>
  {
    return glib::PropertyProxy_WriteOnly<glib::ustring> (
        this,
        "paragraph-background");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::RGBA>::value,
      "Type gdk::RGBA cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_paragraph_background_rgba () -> glib::PropertyProxy<gdk::RGBA>
  {
    return glib::PropertyProxy<gdk::RGBA> (this, "paragraph-background-rgba");
  }

  auto
  TextTag::property_paragraph_background_rgba () const -> glib::PropertyProxy_ReadOnly<gdk::RGBA>
  {
    return glib::PropertyProxy_ReadOnly<gdk::RGBA> (
        this,
        "paragraph-background-rgba");
  }

  auto
  TextTag::property_font_features () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "font-features");
  }

  auto
  TextTag::property_font_features () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "font-features");
  }

  auto
  TextTag::property_allow_breaks () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-breaks");
  }

  auto
  TextTag::property_allow_breaks () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-breaks");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::ShowFlags>::value,
      "Type pango::ShowFlags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_show_spaces () -> glib::PropertyProxy<pango::ShowFlags>
  {
    return glib::PropertyProxy<pango::ShowFlags> (this, "show-spaces");
  }

  auto
  TextTag::property_show_spaces () const -> glib::PropertyProxy_ReadOnly<pango::ShowFlags>
  {
    return glib::PropertyProxy_ReadOnly<pango::ShowFlags> (this, "show-spaces");
  }

  auto
  TextTag::property_insert_hyphens () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "insert-hyphens");
  }

  auto
  TextTag::property_insert_hyphens () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "insert-hyphens");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          pango::TextTransform>::value,
      "Type pango::TextTransform cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextTag::property_text_transform () -> glib::PropertyProxy<pango::TextTransform>
  {
    return glib::PropertyProxy<pango::TextTransform> (this, "text-transform");
  }

  auto
  TextTag::property_text_transform () const -> glib::PropertyProxy_ReadOnly<pango::TextTransform>
  {
    return glib::PropertyProxy_ReadOnly<pango::TextTransform> (
        this,
        "text-transform");
  }

  auto
  TextTag::property_word () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "word");
  }

  auto
  TextTag::property_word () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "word");
  }

  auto
  TextTag::property_sentence () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "sentence");
  }

  auto
  TextTag::property_sentence () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "sentence");
  }

  auto
  TextTag::property_accumulative_margin () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "accumulative-margin");
  }

  auto
  TextTag::property_accumulative_margin () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accumulative-margin");
  }

  auto
  TextTag::property_background_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "background-set");
  }

  auto
  TextTag::property_background_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "background-set");
  }

  auto
  TextTag::property_foreground_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "foreground-set");
  }

  auto
  TextTag::property_foreground_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "foreground-set");
  }

  auto
  TextTag::property_family_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "family-set");
  }

  auto
  TextTag::property_family_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "family-set");
  }

  auto
  TextTag::property_style_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "style-set");
  }

  auto
  TextTag::property_style_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "style-set");
  }

  auto
  TextTag::property_variant_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "variant-set");
  }

  auto
  TextTag::property_variant_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "variant-set");
  }

  auto
  TextTag::property_weight_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "weight-set");
  }

  auto
  TextTag::property_weight_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "weight-set");
  }

  auto
  TextTag::property_stretch_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "stretch-set");
  }

  auto
  TextTag::property_stretch_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "stretch-set");
  }

  auto
  TextTag::property_size_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "size-set");
  }

  auto
  TextTag::property_size_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "size-set");
  }

  auto
  TextTag::property_scale_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "scale-set");
  }

  auto
  TextTag::property_scale_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "scale-set");
  }

  auto
  TextTag::property_pixels_above_lines_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "pixels-above-lines-set");
  }

  auto
  TextTag::property_pixels_above_lines_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "pixels-above-lines-set");
  }

  auto
  TextTag::property_pixels_below_lines_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "pixels-below-lines-set");
  }

  auto
  TextTag::property_pixels_below_lines_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "pixels-below-lines-set");
  }

  auto
  TextTag::property_pixels_inside_wrap_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "pixels-inside-wrap-set");
  }

  auto
  TextTag::property_pixels_inside_wrap_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "pixels-inside-wrap-set");
  }

  auto
  TextTag::property_editable_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editable-set");
  }

  auto
  TextTag::property_editable_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editable-set");
  }

  auto
  TextTag::property_wrap_mode_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "wrap-mode-set");
  }

  auto
  TextTag::property_wrap_mode_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "wrap-mode-set");
  }

  auto
  TextTag::property_justification_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "justification-set");
  }

  auto
  TextTag::property_justification_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "justification-set");
  }

  auto
  TextTag::property_left_margin_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "left-margin-set");
  }

  auto
  TextTag::property_left_margin_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "left-margin-set");
  }

  auto
  TextTag::property_indent_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "indent-set");
  }

  auto
  TextTag::property_indent_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "indent-set");
  }

  auto
  TextTag::property_line_height_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "line-height-set");
  }

  auto
  TextTag::property_line_height_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "line-height-set");
  }

  auto
  TextTag::property_strikethrough_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "strikethrough-set");
  }

  auto
  TextTag::property_strikethrough_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough-set");
  }

  auto
  TextTag::property_strikethrough_rgba_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "strikethrough-rgba-set");
  }

  auto
  TextTag::property_strikethrough_rgba_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "strikethrough-rgba-set");
  }

  auto
  TextTag::property_right_margin_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "right-margin-set");
  }

  auto
  TextTag::property_right_margin_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "right-margin-set");
  }

  auto
  TextTag::property_underline_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "underline-set");
  }

  auto
  TextTag::property_underline_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "underline-set");
  }

  auto
  TextTag::property_underline_rgba_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "underline-rgba-set");
  }

  auto
  TextTag::property_underline_rgba_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "underline-rgba-set");
  }

  auto
  TextTag::property_overline_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "overline-set");
  }

  auto
  TextTag::property_overline_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "overline-set");
  }

  auto
  TextTag::property_overline_rgba_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "overline-rgba-set");
  }

  auto
  TextTag::property_overline_rgba_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "overline-rgba-set");
  }

  auto
  TextTag::property_rise_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "rise-set");
  }

  auto
  TextTag::property_rise_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "rise-set");
  }

  auto
  TextTag::property_background_full_height_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "background-full-height-set");
  }

  auto
  TextTag::property_background_full_height_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "background-full-height-set");
  }

  auto
  TextTag::property_language_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "language-set");
  }

  auto
  TextTag::property_language_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "language-set");
  }

  auto
  TextTag::property_tabs_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "tabs-set");
  }

  auto
  TextTag::property_tabs_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "tabs-set");
  }

  auto
  TextTag::property_invisible_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "invisible-set");
  }

  auto
  TextTag::property_invisible_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "invisible-set");
  }

  auto
  TextTag::property_paragraph_background_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "paragraph-background-set");
  }

  auto
  TextTag::property_paragraph_background_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "paragraph-background-set");
  }

  auto
  TextTag::property_fallback () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "fallback");
  }

  auto
  TextTag::property_fallback () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "fallback");
  }

  auto
  TextTag::property_fallback_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "fallback-set");
  }

  auto
  TextTag::property_fallback_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "fallback-set");
  }

  auto
  TextTag::property_letter_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "letter-spacing");
  }

  auto
  TextTag::property_letter_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "letter-spacing");
  }

  auto
  TextTag::property_letter_spacing_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "letter-spacing-set");
  }

  auto
  TextTag::property_letter_spacing_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "letter-spacing-set");
  }

  auto
  TextTag::property_font_features_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "font-features-set");
  }

  auto
  TextTag::property_font_features_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "font-features-set");
  }

  auto
  TextTag::property_allow_breaks_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "allow-breaks-set");
  }

  auto
  TextTag::property_allow_breaks_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "allow-breaks-set");
  }

  auto
  TextTag::property_show_spaces_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-spaces-set");
  }

  auto
  TextTag::property_show_spaces_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-spaces-set");
  }

  auto
  TextTag::property_insert_hyphens_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "insert-hyphens-set");
  }

  auto
  TextTag::property_insert_hyphens_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "insert-hyphens-set");
  }

  auto
  TextTag::property_text_transform_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "text-transform-set");
  }

  auto
  TextTag::property_text_transform_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "text-transform-set");
  }

  auto
  TextTag::property_word_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "word-set");
  }

  auto
  TextTag::property_word_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "word-set");
  }

  auto
  TextTag::property_sentence_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "sentence-set");
  }

  auto
  TextTag::property_sentence_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "sentence-set");
  }

} // namespace gtk
