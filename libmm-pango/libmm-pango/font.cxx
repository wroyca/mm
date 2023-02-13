


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/font.hpp>
#include <libmm-pango/font_p.hpp>


/*
 * Copyright 1998-1999 The Gtk-- Development Team
 * Copyright 2001      Free Software Foundation
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

#include <libmm-pango/fontface.hpp>
#include <libmm-pango/fontmap.hpp>

namespace Pango
{

auto Font::get_metrics() const -> FontMetrics
{
  return FontMetrics(pango_font_get_metrics(const_cast<PangoFont*>(gobj()), 0));
}

auto Font::get_glyph_ink_extents(
  const Glyph glyph) const -> Rectangle
{
  Rectangle ink_rect;
  pango_font_get_glyph_extents(const_cast<PangoFont*>(gobj()), glyph, ink_rect.gobj(), 0);
  return ink_rect;
}

auto Font::get_glyph_logical_extents(
  const Glyph glyph) const -> Rectangle
{
  Rectangle logical_rect;
  pango_font_get_glyph_extents(const_cast<PangoFont*>(gobj()), glyph, 0, logical_rect.gobj());
  return logical_rect;
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoFont* object, const bool take_copy) -> RefPtr<Pango::Font>
{
  return Glib::make_refptr_for_instance<Pango::Font>( dynamic_cast<Pango::Font*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto Font_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Font_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_font_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Font_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Font_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Font((PangoFont*)object);
}


/* The implementation: */

auto Font::gobj_copy() -> PangoFont*
{
  reference();
  return gobj();
}

Font::Font(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Font::Font(PangoFont* castitem)
: Object((GObject*)castitem)
{}


Font::Font(Font&& src) noexcept
: Object(std::move(src))
{}

auto Font::operator=(Font&& src) noexcept -> Font&
{
  Object::operator=(std::move(src));
  return *this;
}


Font::~Font() noexcept = default;

Font::CppClassType Font::font_class_; // initialize static member

auto Font::get_type() -> GType
{
  return font_class_.init().get_type();
}


auto Font::get_base_type() -> GType
{
  return pango_font_get_type();
}


auto Font::describe() const -> FontDescription
{
  return FontDescription(pango_font_describe(const_cast<PangoFont*>(gobj())));
}

auto Font::describe_with_absolute_size() const -> FontDescription
{
  return FontDescription(pango_font_describe_with_absolute_size(const_cast<PangoFont*>(gobj())));
}

auto Font::get_coverage(const Language& language) const -> Glib::RefPtr<Coverage>
{
  return Glib::wrap(pango_font_get_coverage(const_cast<PangoFont*>(gobj()), const_cast<PangoLanguage*>(language.gobj())));
}

auto Font::get_metrics(const Language& language) const -> FontMetrics
{
  return FontMetrics(pango_font_get_metrics(const_cast<PangoFont*>(gobj()), const_cast<PangoLanguage*>(language.gobj())));
}

auto Font::get_glyph_extents (
  const Glyph glyph, Rectangle &ink_rect, Rectangle &logical_rect) const -> void
{
  pango_font_get_glyph_extents(const_cast<PangoFont*>(gobj()), glyph, ink_rect.gobj(), logical_rect.gobj());
}

auto Font::get_font_map() -> Glib::RefPtr<FontMap>
{
  return Glib::wrap(pango_font_get_font_map(gobj()));
}

auto Font::get_font_map() const -> Glib::RefPtr<const FontMap>
{
  return const_cast<Font*>(this)->get_font_map();
}

auto Font::get_face() -> Glib::RefPtr<FontFace>
{
  auto retvalue = Glib::wrap(pango_font_get_face(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Font::get_face() const -> Glib::RefPtr<const FontFace>
{
  return const_cast<Font*>(this)->get_face();
}

auto Font::has_char(
  const gunichar wc) const -> bool
{
  return pango_font_has_char(const_cast<PangoFont*>(gobj()), wc);
}


} // namespace Pango


