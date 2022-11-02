// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/attributes.hpp>
#include <mm/pango/private/attributes_p.hpp>


/*
 *
 * Copyright 2002 Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <mm/pango/context.hpp>

namespace Pango
{

Attribute::Attribute()
:
  gobject_(0)
{}

Attribute::Attribute(const Attribute& src)
:
  gobject_(src.gobject_ ? pango_attribute_copy(src.gobject_) : nullptr)
{}

Attribute::Attribute(PangoAttribute* castitem, bool take_copy)
{
  if(take_copy)
  {
    if(castitem)
      gobject_ = pango_attribute_copy(castitem);
    else
      gobject_ = nullptr;
  }
  else
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
}

Attribute::~Attribute()
{
  if(gobject_)
    pango_attribute_destroy(gobject_);
  gobject_ = nullptr;
}

auto Attribute::operator=(const Attribute& src) -> Attribute&
{
  auto* const new_gobject = (src.gobject_ ? pango_attribute_copy(src.gobject_) : nullptr);

  if(gobject_)
    pango_attribute_destroy(gobject_);
  gobject_ = new_gobject;

  return *this;
}

auto Attribute::get_type() const -> AttrType
{
  return (AttrType) ((gobject_) ? gobj()->klass->type : PANGO_ATTR_INVALID);
}

auto Attribute::register_type(const Glib::ustring& name) -> AttrType
{
  return (AttrType)pango_attr_type_register(name.c_str());
}

auto Attribute::get_type_name(AttrType type) -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(pango_attr_type_get_name((PangoAttrType)type));
}

auto Attribute::create_attr_family(const Glib::ustring& family) -> AttrString
{
  return Glib::wrap((PangoAttrString*)pango_attr_family_new(family.c_str()));
}

auto Attribute::create_attr_language(const Language& language) -> AttrLanguage
{
  return Glib::wrap((PangoAttrLanguage*)pango_attr_language_new(const_cast<PangoLanguage*>(language.gobj())));
}

auto Attribute::create_attr_foreground(guint16 red, guint16 green, guint16 blue) -> AttrColor
{
  return Glib::wrap((PangoAttrColor*)pango_attr_foreground_new(red, green, blue));
}

auto Attribute::create_attr_background(guint16 red, guint16 green, guint16 blue) -> AttrColor
{
  return Glib::wrap((PangoAttrColor*)pango_attr_background_new(red, green, blue));
}

auto Attribute::create_attr_foreground_alpha(guint16 alpha) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_foreground_alpha_new(alpha));
}

auto Attribute::create_attr_background_alpha(guint16 alpha) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_background_alpha_new(alpha));
}

auto Attribute::create_attr_size(int size) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_size_new(size));
}

auto Attribute::create_attr_size_absolute(int size) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_size_new_absolute(size));
}

auto Attribute::create_attr_style(Style style) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_style_new((PangoStyle)style));
}

auto Attribute::create_attr_weight(Weight weight) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_weight_new((PangoWeight)weight));
}

auto Attribute::create_attr_variant(Variant variant) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_variant_new((PangoVariant)variant));
}

auto Attribute::create_attr_stretch(Stretch stretch) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_stretch_new((PangoStretch)stretch));
}

auto Attribute::create_attr_font_desc(const FontDescription& desc) -> AttrFontDesc
{
  return Glib::wrap((PangoAttrFontDesc*)pango_attr_font_desc_new(desc.gobj()));
}

auto Attribute::create_attr_underline(Underline underline) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_underline_new((PangoUnderline)underline));
}

auto Attribute::create_attr_underline_color(guint16 red, guint16 green, guint16 blue) -> AttrColor
{
  return Glib::wrap((PangoAttrColor*)pango_attr_underline_color_new(red, green, blue));
}

auto Attribute::create_attr_overline(Overline overline) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_overline_new((PangoOverline)overline));
}

auto Attribute::create_attr_overline_color(guint16 red, guint16 green, guint16 blue) -> AttrColor
{
  return Glib::wrap((PangoAttrColor*)pango_attr_overline_color_new(red, green, blue));
}

auto Attribute::create_attr_strikethrough(bool strikethrough) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_strikethrough_new(strikethrough));
}

auto Attribute::create_attr_strikethrough_color(guint16 red, guint16 green, guint16 blue) -> AttrColor
{
  return Glib::wrap((PangoAttrColor*)pango_attr_strikethrough_color_new(red, green, blue));
}

auto Attribute::create_attr_rise(int rise) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_rise_new(rise));
}

auto Attribute::create_attr_baseline_shift(int shift) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_baseline_shift_new(shift));
}

auto Attribute::create_attr_font_scale(FontScale scale) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_font_scale_new((PangoFontScale)scale));
}

auto Attribute::create_attr_scale(double scale_factor) -> AttrFloat
{
  return Glib::wrap((PangoAttrFloat*)pango_attr_scale_new(scale_factor));
}

auto Attribute::create_attr_fallback(bool enable_fallback) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_fallback_new(enable_fallback));
}

auto Attribute::create_attr_letter_spacing(int letter_spacing) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_letter_spacing_new(letter_spacing));
}

auto Attribute::create_attr_shape(const Rectangle& ink_rect, const Rectangle& logical_rect) -> AttrShape
{
  return Glib::wrap((PangoAttrShape*)pango_attr_shape_new(ink_rect.gobj(), logical_rect.gobj()));
}

auto Attribute::create_attr_gravity(Gravity gravity) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_gravity_new((PangoGravity)gravity));
}

auto Attribute::create_attr_gravity_hint(GravityHint hint) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_gravity_hint_new((PangoGravityHint)hint));
}

auto Attribute::create_attr_font_features(const Glib::ustring& features) -> AttrString
{
  return Glib::wrap((PangoAttrString*)pango_attr_font_features_new(features.c_str()));
}

auto Attribute::create_attr_allow_breaks(bool allow_breaks) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_allow_breaks_new(allow_breaks));
}

auto Attribute::create_attr_word() -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_word_new());
}

auto Attribute::create_attr_sentence() -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_sentence_new());
}

auto Attribute::create_attr_insert_hyphens(bool insert_hyphens) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_insert_hyphens_new(insert_hyphens));
}

auto Attribute::create_attr_show(ShowFlags show) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_show_new((PangoShowFlags)show));
}

auto Attribute::create_attr_line_height(double factor) -> AttrFloat
{
  return Glib::wrap((PangoAttrFloat*)pango_attr_line_height_new(factor));
}

auto Attribute::create_attr_line_height_absolute(int height) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_line_height_new_absolute(height));
}

auto Attribute::create_attr_text_transform(TextTransform transform) -> AttrInt
{
  return Glib::wrap((PangoAttrInt*)pango_attr_text_transform_new((PangoTextTransform)transform));
}


AttrString::AttrString()
{}

AttrString::AttrString(const AttrString& src)
:
  Attribute(src)
{}

AttrString::AttrString(PangoAttrString* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrString::operator=(const AttrString& src) -> AttrString&
{
  Attribute::operator=(src);
  return *this;
}

void AttrString::set_string(const Glib::ustring& str)
{
  g_free(gobj()->value);
  gobj()->value = g_strdup(str.c_str());
}


AttrLanguage::AttrLanguage()
{}

AttrLanguage::AttrLanguage(const AttrLanguage& src)
:
  Attribute(src)
{}

AttrLanguage::AttrLanguage(PangoAttrLanguage* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrLanguage::operator=(const AttrLanguage& src) -> AttrLanguage&
{
  Attribute::operator=(src);
  return *this;
}


AttrColor::AttrColor()
{}

AttrColor::AttrColor(const AttrColor& src)
:
  Attribute(src)
{}

AttrColor::AttrColor(PangoAttrColor* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrColor::operator=(const AttrColor& src) -> AttrColor&
{
  Attribute::operator=(src);
  return *this;
}


AttrInt::AttrInt()
{}

AttrInt::AttrInt(const AttrInt& src)
:
  Attribute(src)
{}

AttrInt::AttrInt(PangoAttrInt* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrInt::operator=(const AttrInt& src) -> AttrInt&
{
  Attribute::operator=(src);
  return *this;
}


AttrFloat::AttrFloat()
{}

AttrFloat::AttrFloat(const AttrFloat& src)
:
  Attribute(src)
{}

AttrFloat::AttrFloat(PangoAttrFloat* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrFloat::operator=(const AttrFloat& src) -> AttrFloat&
{
  Attribute::operator=(src);
  return *this;
}


AttrFontDesc::AttrFontDesc()
{}

AttrFontDesc::AttrFontDesc(const AttrFontDesc& src)
:
  Attribute(src)
{}

AttrFontDesc::AttrFontDesc(PangoAttrFontDesc* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrFontDesc::operator=(const AttrFontDesc& src) -> AttrFontDesc&
{
  Attribute::operator=(src);
  return *this;
}

void AttrFontDesc::set_desc(const FontDescription& desc)
{
  pango_font_description_free(gobj()->desc);
  gobj()->desc = pango_font_description_copy(desc.gobj());
}


AttrShape::AttrShape()
{}

AttrShape::AttrShape(const AttrShape& src)
:
  Attribute(src)
{}

AttrShape::AttrShape(PangoAttrShape* castitem, bool take_copy)
:
  Attribute((PangoAttribute*)castitem, take_copy)
{}

auto AttrShape::operator=(const AttrShape& src) -> AttrShape&
{
  Attribute::operator=(src);
  return *this;
}

} //namespace Pango


namespace Glib
{

auto wrap(PangoAttribute* object, bool take_copy) -> Pango::Attribute
{
  return Pango::Attribute(object, take_copy);
}

auto wrap(PangoAttrString* object, bool take_copy) -> Pango::AttrString
{
  return Pango::AttrString(object, take_copy);
}

auto wrap(PangoAttrLanguage* object, bool take_copy) -> Pango::AttrLanguage
{
  return Pango::AttrLanguage(object, take_copy);
}

auto wrap(PangoAttrColor* object, bool take_copy) -> Pango::AttrColor
{
  return Pango::AttrColor(object, take_copy);
}

auto wrap(PangoAttrInt* object, bool take_copy) -> Pango::AttrInt
{
  return Pango::AttrInt(object, take_copy);
}

auto wrap(PangoAttrFloat* object, bool take_copy) -> Pango::AttrFloat
{
  return Pango::AttrFloat(object, take_copy);
}

auto wrap(PangoAttrFontDesc* object, bool take_copy) -> Pango::AttrFontDesc
{
  return Pango::AttrFontDesc(object, take_copy);
}

auto wrap(PangoAttrShape* object, bool take_copy) -> Pango::AttrShape
{
  return Pango::AttrShape(object, take_copy);
}

} //namespace Glib


namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::AttrType>::value_type() -> GType
{
  return pango_attr_type_get_type();
}

// static
auto Glib::Value<Pango::Underline>::value_type() -> GType
{
  return pango_underline_get_type();
}

// static
auto Glib::Value<Pango::Overline>::value_type() -> GType
{
  return pango_overline_get_type();
}

// static
auto Glib::Value<Pango::ShowFlags>::value_type() -> GType
{
  return pango_show_flags_get_type();
}

// static
auto Glib::Value<Pango::TextTransform>::value_type() -> GType
{
  return pango_text_transform_get_type();
}

// static
auto Glib::Value<Pango::BaselineShift>::value_type() -> GType
{
  return pango_baseline_shift_get_type();
}

// static
auto Glib::Value<Pango::FontScale>::value_type() -> GType
{
  return pango_font_scale_get_type();
}


namespace Pango
{


auto Attribute::get_start_index() const -> unsigned int
{
  return gobj()->start_index;
}

auto Attribute::get_end_index() const -> unsigned int
{
  return gobj()->end_index;
}

void Attribute::set_start_index(const unsigned int& value)
{
  gobj()->start_index = value;
}

void Attribute::set_end_index(const unsigned int& value)
{
  gobj()->end_index = value;
}

auto Attribute::equal(const Attribute& attr2) const -> bool
{
  return pango_attribute_equal(const_cast<PangoAttribute*>(gobj()), (attr2).gobj());
}


} // namespace Pango


namespace Pango
{


auto AttrString::get_string() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gobj()->value);
}


} // namespace Pango


namespace Pango
{


auto AttrLanguage::get_language() const -> Language
{
  return Language(gobj()->value);
}

void AttrLanguage::set_language(const Language& value)
{
  gobj()->value = const_cast<PangoLanguage*>((value).gobj());
}


} // namespace Pango


namespace Pango
{


auto AttrColor::get_color() const -> Color
{
  return Color(&(gobj()->color));
}

void AttrColor::set_color(const Color& value)
{
  gobj()->color = *(value).gobj();
}


} // namespace Pango


namespace Pango
{


auto AttrInt::get_value() const -> int
{
  return gobj()->value;
}

void AttrInt::set_value(const int& value)
{
  gobj()->value = value;
}


} // namespace Pango


namespace Pango
{


auto AttrFloat::get_value() const -> double
{
  return gobj()->value;
}

void AttrFloat::set_value(const double& value)
{
  gobj()->value = value;
}


} // namespace Pango


namespace Pango
{


auto AttrFontDesc::get_desc() const -> FontDescription
{
  return FontDescription((gobj()->desc));
}


} // namespace Pango


namespace Pango
{


auto AttrShape::get_ink_rect() const -> Rectangle
{
  return Rectangle(&(gobj()->ink_rect));
}

auto AttrShape::get_logical_rect() const -> Rectangle
{
  return Rectangle(&(gobj()->logical_rect));
}

void AttrShape::set_ink_rect(const Rectangle& value)
{
  gobj()->ink_rect = *(value).gobj();
}

void AttrShape::set_logical_rect(const Rectangle& value)
{
  gobj()->logical_rect = *(value).gobj();
}


} // namespace Pango

