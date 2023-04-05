// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/attributes.hxx>
#include <libmm/pango/attributes_p.hxx>

#include <libmm/pango/context.hxx>

namespace pango
{

  Attribute::Attribute ()
    : gobject_ (0)
  {
  }

  Attribute::Attribute (const Attribute& src)
    : gobject_ (src.gobject_ ? pango_attribute_copy (src.gobject_) : nullptr)
  {
  }

  Attribute::Attribute (PangoAttribute* castitem, const bool take_copy)
  {
    if (take_copy)
    {
      if (castitem)
        gobject_ = pango_attribute_copy (castitem);
      else
        gobject_ = nullptr;
    }
    else
    {
      gobject_ = castitem;
    }
  }

  Attribute::~Attribute ()
  {
    if (gobject_)
      pango_attribute_destroy (gobject_);
    gobject_ = nullptr;
  }

  auto
  Attribute::operator= (const Attribute& src) -> Attribute&
  {
    auto* const new_gobject =
        src.gobject_ ? pango_attribute_copy (src.gobject_) : nullptr;

    if (gobject_)
      pango_attribute_destroy (gobject_);
    gobject_ = new_gobject;

    return *this;
  }

  auto
  Attribute::get_type () const -> AttrType
  {
    return (AttrType) (gobject_ ? gobj ()->klass->type : PANGO_ATTR_INVALID);
  }

  auto
  Attribute::register_type (const glib::ustring& name) -> AttrType
  {
    return (AttrType) pango_attr_type_register (name.c_str ());
  }

  auto
  Attribute::get_type_name (AttrType type) -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        pango_attr_type_get_name ((PangoAttrType) type));
  }

  auto
  Attribute::create_attr_family (const glib::ustring& family) -> AttrString
  {
    return glib::wrap (
        (PangoAttrString*) pango_attr_family_new (family.c_str ()));
  }

  auto
  Attribute::create_attr_language (const Language& language) -> AttrLanguage
  {
    return glib::wrap ((PangoAttrLanguage*) pango_attr_language_new (
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  Attribute::create_attr_foreground (const guint16 red,
                                     const guint16 green,
                                     const guint16 blue) -> AttrColor
  {
    return glib::wrap (
        (PangoAttrColor*) pango_attr_foreground_new (red, green, blue));
  }

  auto
  Attribute::create_attr_background (const guint16 red,
                                     const guint16 green,
                                     const guint16 blue) -> AttrColor
  {
    return glib::wrap (
        (PangoAttrColor*) pango_attr_background_new (red, green, blue));
  }

  auto
  Attribute::create_attr_foreground_alpha (const guint16 alpha) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_foreground_alpha_new (alpha));
  }

  auto
  Attribute::create_attr_background_alpha (const guint16 alpha) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_background_alpha_new (alpha));
  }

  auto
  Attribute::create_attr_size (const int size) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_size_new (size));
  }

  auto
  Attribute::create_attr_size_absolute (const int size) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_size_new_absolute (size));
  }

  auto
  Attribute::create_attr_style (Style style) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_style_new ((PangoStyle) style));
  }

  auto
  Attribute::create_attr_weight (Weight weight) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_weight_new ((PangoWeight) weight));
  }

  auto
  Attribute::create_attr_variant (Variant variant) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_variant_new ((PangoVariant) variant));
  }

  auto
  Attribute::create_attr_stretch (Stretch stretch) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_stretch_new ((PangoStretch) stretch));
  }

  auto
  Attribute::create_attr_font_desc (const FontDescription& desc) -> AttrFontDesc
  {
    return glib::wrap (
        (PangoAttrFontDesc*) pango_attr_font_desc_new (desc.gobj ()));
  }

  auto
  Attribute::create_attr_underline (Underline underline) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_underline_new ((PangoUnderline) underline));
  }

  auto
  Attribute::create_attr_underline_color (const guint16 red,
                                          const guint16 green,
                                          const guint16 blue) -> AttrColor
  {
    return glib::wrap (
        (PangoAttrColor*) pango_attr_underline_color_new (red, green, blue));
  }

  auto
  Attribute::create_attr_overline (Overline overline) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_overline_new ((PangoOverline) overline));
  }

  auto
  Attribute::create_attr_overline_color (const guint16 red,
                                         const guint16 green,
                                         const guint16 blue) -> AttrColor
  {
    return glib::wrap (
        (PangoAttrColor*) pango_attr_overline_color_new (red, green, blue));
  }

  auto
  Attribute::create_attr_strikethrough (const bool strikethrough) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_strikethrough_new (strikethrough));
  }

  auto
  Attribute::create_attr_strikethrough_color (const guint16 red,
                                              const guint16 green,
                                              const guint16 blue) -> AttrColor
  {
    return glib::wrap ((
        PangoAttrColor*) pango_attr_strikethrough_color_new (red, green, blue));
  }

  auto
  Attribute::create_attr_rise (const int rise) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_rise_new (rise));
  }

  auto
  Attribute::create_attr_baseline_shift (const int shift) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_baseline_shift_new (shift));
  }

  auto
  Attribute::create_attr_font_scale (FontScale scale) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_font_scale_new ((PangoFontScale) scale));
  }

  auto
  Attribute::create_attr_scale (const double scale_factor) -> AttrFloat
  {
    return glib::wrap ((PangoAttrFloat*) pango_attr_scale_new (scale_factor));
  }

  auto
  Attribute::create_attr_fallback (const bool enable_fallback) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_fallback_new (enable_fallback));
  }

  auto
  Attribute::create_attr_letter_spacing (const int letter_spacing) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_letter_spacing_new (letter_spacing));
  }

  auto
  Attribute::create_attr_shape (const Rectangle& ink_rect,
                                const Rectangle& logical_rect) -> AttrShape
  {
    return glib::wrap (
        (PangoAttrShape*) pango_attr_shape_new (ink_rect.gobj (),
                                                logical_rect.gobj ()));
  }

  auto
  Attribute::create_attr_gravity (Gravity gravity) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_gravity_new ((PangoGravity) gravity));
  }

  auto
  Attribute::create_attr_gravity_hint (GravityHint hint) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_gravity_hint_new ((PangoGravityHint) hint));
  }

  auto
  Attribute::create_attr_font_features (const glib::ustring& features) -> AttrString
  {
    return glib::wrap (
        (PangoAttrString*) pango_attr_font_features_new (features.c_str ()));
  }

  auto
  Attribute::create_attr_allow_breaks (const bool allow_breaks) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_allow_breaks_new (allow_breaks));
  }

  auto
  Attribute::create_attr_word () -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_word_new ());
  }

  auto
  Attribute::create_attr_sentence () -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_sentence_new ());
  }

  auto
  Attribute::create_attr_insert_hyphens (const bool insert_hyphens) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_insert_hyphens_new (insert_hyphens));
  }

  auto
  Attribute::create_attr_show (ShowFlags show) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_show_new ((PangoShowFlags) show));
  }

  auto
  Attribute::create_attr_line_height (const double factor) -> AttrFloat
  {
    return glib::wrap ((PangoAttrFloat*) pango_attr_line_height_new (factor));
  }

  auto
  Attribute::create_attr_line_height_absolute (const int height) -> AttrInt
  {
    return glib::wrap (
        (PangoAttrInt*) pango_attr_line_height_new_absolute (height));
  }

  auto
  Attribute::create_attr_text_transform (TextTransform transform) -> AttrInt
  {
    return glib::wrap ((PangoAttrInt*) pango_attr_text_transform_new (
        (PangoTextTransform) transform));
  }

  AttrString::AttrString () = default;

  AttrLanguage::AttrLanguage (const AttrLanguage& src) = default;

  AttrString::AttrString (PangoAttrString* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrString::operator= (const AttrString& src) -> AttrString& = default;

  auto
  AttrString::set_string (const glib::ustring& str) -> void
  {
    g_free (gobj ()->value);
    gobj ()->value = g_strdup (str.c_str ());
  }

  AttrLanguage::AttrLanguage () = default;

  AttrLanguage::AttrLanguage (PangoAttrLanguage* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrLanguage::operator= (const AttrLanguage& src) -> AttrLanguage& = default;

  AttrColor::AttrColor () = default;

  AttrColor::AttrColor (const AttrColor& src) = default;

  AttrColor::AttrColor (PangoAttrColor* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrColor::operator= (const AttrColor& src) -> AttrColor& = default;

  AttrInt::AttrInt () = default;

  AttrInt::AttrInt (const AttrInt& src) = default;

  AttrInt::AttrInt (PangoAttrInt* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrInt::operator= (const AttrInt& src) -> AttrInt& = default;

  AttrFloat::AttrFloat () = default;

  AttrFloat::AttrFloat (const AttrFloat& src) = default;

  AttrFloat::AttrFloat (PangoAttrFloat* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrFloat::operator= (const AttrFloat& src) -> AttrFloat& = default;

  AttrFontDesc::AttrFontDesc () = default;

  AttrFontDesc::AttrFontDesc (const AttrFontDesc& src) = default;

  AttrFontDesc::AttrFontDesc (PangoAttrFontDesc* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrFontDesc::operator= (const AttrFontDesc& src) -> AttrFontDesc& = default;

  auto
  AttrFontDesc::set_desc (const FontDescription& desc) -> void
  {
    pango_font_description_free (gobj ()->desc);
    gobj ()->desc = pango_font_description_copy (desc.gobj ());
  }

  AttrShape::AttrShape () = default;

  AttrShape::AttrShape (const AttrShape& src) = default;

  AttrShape::AttrShape (PangoAttrShape* castitem, const bool take_copy)
    : Attribute ((PangoAttribute*) castitem, take_copy)
  {
  }

  auto
  AttrShape::operator= (const AttrShape& src) -> AttrShape& = default;
} // namespace pango

namespace glib
{

  auto
  wrap (PangoAttribute* object, const bool take_copy) -> pango::Attribute
  {
    return pango::Attribute (object, take_copy);
  }

  auto
  wrap (PangoAttrString* object, const bool take_copy) -> pango::AttrString
  {
    return pango::AttrString (object, take_copy);
  }

  auto
  wrap (PangoAttrLanguage* object, const bool take_copy) -> pango::AttrLanguage
  {
    return pango::AttrLanguage (object, take_copy);
  }

  auto
  wrap (PangoAttrColor* object, const bool take_copy) -> pango::AttrColor
  {
    return pango::AttrColor (object, take_copy);
  }

  auto
  wrap (PangoAttrInt* object, const bool take_copy) -> pango::AttrInt
  {
    return pango::AttrInt (object, take_copy);
  }

  auto
  wrap (PangoAttrFloat* object, const bool take_copy) -> pango::AttrFloat
  {
    return pango::AttrFloat (object, take_copy);
  }

  auto
  wrap (PangoAttrFontDesc* object, const bool take_copy) -> pango::AttrFontDesc
  {
    return pango::AttrFontDesc (object, take_copy);
  }

  auto
  wrap (PangoAttrShape* object, const bool take_copy) -> pango::AttrShape
  {
    return pango::AttrShape (object, take_copy);
  }

} // namespace glib

namespace
{
}

auto
glib::Value<pango::AttrType>::value_type () -> GType
{
  return pango_attr_type_get_type ();
}

auto
glib::Value<pango::Underline>::value_type () -> GType
{
  return pango_underline_get_type ();
}

auto
glib::Value<pango::Overline>::value_type () -> GType
{
  return pango_overline_get_type ();
}

auto
glib::Value<pango::ShowFlags>::value_type () -> GType
{
  return pango_show_flags_get_type ();
}

auto
glib::Value<pango::TextTransform>::value_type () -> GType
{
  return pango_text_transform_get_type ();
}

auto
glib::Value<pango::BaselineShift>::value_type () -> GType
{
  return pango_baseline_shift_get_type ();
}

auto
glib::Value<pango::FontScale>::value_type () -> GType
{
  return pango_font_scale_get_type ();
}

namespace pango
{

  auto
  Attribute::get_start_index () const -> unsigned int
  {
    return gobj ()->start_index;
  }

  auto
  Attribute::get_end_index () const -> unsigned int
  {
    return gobj ()->end_index;
  }

  auto
  Attribute::set_start_index (const unsigned int& value) -> void
  {
    gobj ()->start_index = value;
  }

  auto
  Attribute::set_end_index (const unsigned int& value) -> void
  {
    gobj ()->end_index = value;
  }

  auto
  Attribute::equal (const Attribute& attr2) const -> bool
  {
    return pango_attribute_equal (gobj (), attr2.gobj ());
  }

} // namespace pango

namespace pango
{

  auto
  AttrString::get_string () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (gobj ()->value);
  }

} // namespace pango

namespace pango
{

  auto
  AttrLanguage::get_language () const -> Language
  {
    return Language (gobj ()->value);
  }

  auto
  AttrLanguage::set_language (const Language& value) -> void
  {
    gobj ()->value = const_cast<PangoLanguage*> (value.gobj ());
  }

} // namespace pango

namespace pango
{

  auto
  AttrColor::get_color () const -> Color
  {
    return Color (&gobj ()->color);
  }

  auto
  AttrColor::set_color (const Color& value) -> void
  {
    gobj ()->color = *value.gobj ();
  }

} // namespace pango

namespace pango
{

  auto
  AttrInt::get_value () const -> int
  {
    return gobj ()->value;
  }

  auto
  AttrInt::set_value (const int& value) -> void
  {
    gobj ()->value = value;
  }

} // namespace pango

namespace pango
{

  auto
  AttrFloat::get_value () const -> double
  {
    return gobj ()->value;
  }

  auto
  AttrFloat::set_value (const double& value) -> void
  {
    gobj ()->value = value;
  }

} // namespace pango

namespace pango
{

  auto
  AttrFontDesc::get_desc () const -> FontDescription
  {
    return FontDescription (gobj ()->desc);
  }

} // namespace pango

namespace pango
{

  auto
  AttrShape::get_ink_rect () const -> Rectangle
  {
    return Rectangle (&gobj ()->ink_rect);
  }

  auto
  AttrShape::get_logical_rect () const -> Rectangle
  {
    return Rectangle (&gobj ()->logical_rect);
  }

  auto
  AttrShape::set_ink_rect (const Rectangle& value) -> void
  {
    gobj ()->ink_rect = *value.gobj ();
  }

  auto
  AttrShape::set_logical_rect (const Rectangle& value) -> void
  {
    gobj ()->logical_rect = *value.gobj ();
  }

} // namespace pango
