


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/fontfamily.hpp>
#include <mm/pango/private/fontfamily_p.hpp>


// -*- c++ -*-
/* $Id: fontfamily.ccg,v 1.1 2003/01/21 13:41:03 murrayc Exp $ */

/*
 *
 * Copyright 2001      The gtkmm Development Team
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

namespace Pango
{

auto FontFamily::list_faces() const -> std::vector<Glib::RefPtr<FontFace>>
{
  //Get the array:
  PangoFontFace** pFontFaces = nullptr;
  int n_fonts = 0;
  pango_font_family_list_faces(const_cast<PangoFontFamily*>(gobj()), &pFontFaces, &n_fonts);

  return Glib::ArrayHandler<Glib::RefPtr<FontFace>>::array_to_vector(pFontFaces, n_fonts, Glib::OWNERSHIP_SHALLOW);
}

} /* namespace Pango */


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoFontFamily* object, const bool take_copy) -> RefPtr<Pango::FontFamily>
{
  return Glib::make_refptr_for_instance<Pango::FontFamily>( dynamic_cast<Pango::FontFamily*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto FontFamily_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontFamily_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_font_family_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::ListModel::add_interface(get_type());

  }

  return *this;
}


auto FontFamily_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FontFamily_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FontFamily((PangoFontFamily*)object);
}


/* The implementation: */

auto FontFamily::gobj_copy() -> PangoFontFamily*
{
  reference();
  return gobj();
}

FontFamily::FontFamily(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FontFamily::FontFamily(PangoFontFamily* castitem)
: Object((GObject*)castitem)
{}


FontFamily::FontFamily(FontFamily&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto FontFamily::operator=(FontFamily&& src) noexcept -> FontFamily&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


FontFamily::~FontFamily() noexcept = default;

FontFamily::CppClassType FontFamily::fontfamily_class_; // initialize static member

auto FontFamily::get_type() -> GType
{
  return fontfamily_class_.init().get_type();
}


auto FontFamily::get_base_type() -> GType
{
  return pango_font_family_get_type();
}


auto FontFamily::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(pango_font_family_get_name(const_cast<PangoFontFamily*>(gobj())));
}

auto FontFamily::is_monospace() const -> bool
{
  return pango_font_family_is_monospace(const_cast<PangoFontFamily*>(gobj()));
}

auto FontFamily::is_variable() const -> bool
{
  return pango_font_family_is_variable(const_cast<PangoFontFamily*>(gobj()));
}

auto FontFamily::get_face(const Glib::ustring& name) -> Glib::RefPtr<FontFace>
{
  auto retvalue = Glib::wrap(pango_font_family_get_face(gobj(), name.empty() ? nullptr : name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontFamily::get_face(const Glib::ustring& name) const -> Glib::RefPtr<const FontFace>
{
  return const_cast<FontFamily*>(this)->get_face(name);
}


} // namespace Pango


