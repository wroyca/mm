// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/fontdescription.hxx>
#include <libmm/pango/fontdescription_p.hxx>

#include <libmm/glib/utility.hxx>

namespace pango
{

  FontDescription::FontDescription (const glib::ustring& font_name)
  {
    gobject_ = pango_font_description_from_string (font_name.c_str ());
  }

} // namespace pango

namespace
{
}

auto
glib::Value<pango::Style>::value_type () -> GType
{
  return pango_style_get_type ();
}

auto
glib::Value<pango::Variant>::value_type () -> GType
{
  return pango_variant_get_type ();
}

auto
glib::Value<pango::Stretch>::value_type () -> GType
{
  return pango_stretch_get_type ();
}

auto
glib::Value<pango::Weight>::value_type () -> GType
{
  return pango_weight_get_type ();
}

auto
glib::Value<pango::FontMask>::value_type () -> GType
{
  return pango_font_mask_get_type ();
}

auto
glib::Value<pango::Gravity>::value_type () -> GType
{
  return pango_gravity_get_type ();
}

namespace glib
{

  auto
  wrap (PangoFontDescription* object, const bool take_copy) -> pango::FontDescription
  {
    return pango::FontDescription (object, take_copy);
  }

} // namespace glib

namespace pango
{

  auto
  FontDescription::get_type () -> GType
  {
    return pango_font_description_get_type ();
  }

  FontDescription::FontDescription ()
    : gobject_ (pango_font_description_new ())
  {
  }

  FontDescription::FontDescription (const FontDescription& other)
    : gobject_ (other.gobject_ ? pango_font_description_copy (other.gobject_) :
                                 nullptr)
  {
  }

  FontDescription::FontDescription (FontDescription&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  FontDescription::operator= (FontDescription&& other) noexcept -> FontDescription&
  {
    FontDescription temp (std::move (other));
    swap (temp);
    return *this;
  }

  FontDescription::FontDescription (PangoFontDescription* gobject,
                                    const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? pango_font_description_copy (gobject) :
                                         gobject)
  {
  }

  auto
  FontDescription::operator= (const FontDescription& other) -> FontDescription&
  {
    FontDescription temp (other);
    swap (temp);
    return *this;
  }

  FontDescription::~FontDescription () noexcept
  {
    if (gobject_)
      pango_font_description_free (gobject_);
  }

  auto
  FontDescription::swap (FontDescription& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  FontDescription::gobj_copy () const -> PangoFontDescription*
  {
    return pango_font_description_copy (gobject_);
  }

  auto
  FontDescription::hash () const -> guint
  {
    return pango_font_description_hash (gobj ());
  }

  auto
  FontDescription::set_family (const glib::ustring& family) -> void
  {
    pango_font_description_set_family (gobj (), family.c_str ());
  }

  auto
  FontDescription::get_family () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        pango_font_description_get_family (gobj ()));
  }

  auto
  FontDescription::set_style (Style style) -> void
  {
    pango_font_description_set_style (gobj (), static_cast<PangoStyle> (style));
  }

  auto
  FontDescription::get_style () const -> Style
  {
    return static_cast<Style> (pango_font_description_get_style (gobj ()));
  }

  auto
  FontDescription::set_variant (Variant variant) -> void
  {
    pango_font_description_set_variant (gobj (),
                                        static_cast<PangoVariant> (variant));
  }

  auto
  FontDescription::get_variant () const -> Variant
  {
    return static_cast<Variant> (pango_font_description_get_variant (gobj ()));
  }

  auto
  FontDescription::set_weight (Weight weight) -> void
  {
    pango_font_description_set_weight (gobj (),
                                       static_cast<PangoWeight> (weight));
  }

  auto
  FontDescription::get_weight () const -> Weight
  {
    return static_cast<Weight> (pango_font_description_get_weight (gobj ()));
  }

  auto
  FontDescription::set_stretch (Stretch stretch) -> void
  {
    pango_font_description_set_stretch (gobj (),
                                        static_cast<PangoStretch> (stretch));
  }

  auto
  FontDescription::get_stretch () const -> Stretch
  {
    return static_cast<Stretch> (pango_font_description_get_stretch (gobj ()));
  }

  auto
  FontDescription::set_size (const int size) -> void
  {
    pango_font_description_set_size (gobj (), size);
  }

  auto
  FontDescription::get_size () const -> int
  {
    return pango_font_description_get_size (gobj ());
  }

  auto
  FontDescription::set_absolute_size (const double size) -> void
  {
    pango_font_description_set_absolute_size (gobj (), size);
  }

  auto
  FontDescription::get_size_is_absolute () const -> bool
  {
    return pango_font_description_get_size_is_absolute (gobj ());
  }

  auto
  FontDescription::set_gravity (Gravity gravity) -> void
  {
    pango_font_description_set_gravity (gobj (),
                                        static_cast<PangoGravity> (gravity));
  }

  auto
  FontDescription::get_gravity () const -> Gravity
  {
    return static_cast<Gravity> (pango_font_description_get_gravity (gobj ()));
  }

  auto
  FontDescription::set_variations (const glib::ustring& settings) -> void
  {
    pango_font_description_set_variations (gobj (), settings.c_str ());
  }

  auto
  FontDescription::get_variations () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        pango_font_description_get_variations (gobj ()));
  }

  auto
  FontDescription::get_set_fields () const -> FontMask
  {
    return static_cast<FontMask> (
        pango_font_description_get_set_fields (gobj ()));
  }

  auto
  FontDescription::unset_fields (FontMask to_unset) -> void
  {
    pango_font_description_unset_fields (gobj (),
                                         static_cast<PangoFontMask> (to_unset));
  }

  auto
  FontDescription::merge (const FontDescription& desc_to_merge,
                          const bool replace_existing) -> void
  {
    pango_font_description_merge (gobj (),
                                  desc_to_merge.gobj (),
                                  replace_existing);
  }

  auto
  FontDescription::better_match (const FontDescription& old_match,
                                 const FontDescription& new_match) const -> bool
  {
    return pango_font_description_better_match (gobj (),
                                                old_match.gobj (),
                                                new_match.gobj ());
  }

  auto
  FontDescription::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        pango_font_description_to_string (gobj ()));
  }

  auto
  FontDescription::to_filename () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        pango_font_description_to_filename (gobj ()));
  }

  auto
  operator== (const FontDescription& lhs, const FontDescription& rhs) -> bool
  {
    return pango_font_description_equal (lhs.gobj (), rhs.gobj ()) != 0;
  }

  auto
  operator!= (const FontDescription& lhs, const FontDescription& rhs) -> bool
  {
    return pango_font_description_equal (lhs.gobj (), rhs.gobj ()) == 0;
  }

} // namespace pango
