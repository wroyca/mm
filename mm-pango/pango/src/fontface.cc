// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <pangomm/fontface.h>
#include <pangomm/private/fontface_p.h>


/* 
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <pangomm/fontfamily.h>

namespace Pango
{

std::vector<int> FontFace::list_sizes() const
{
  int* sizes = nullptr;
  int n_sizes = 0;
  pango_font_face_list_sizes(const_cast<PangoFontFace*>(gobj()), &sizes, &n_sizes);

  return Glib::ArrayHandler<int>::array_to_vector(sizes, n_sizes, Glib::OWNERSHIP_SHALLOW); //The ArrayHandle will free the array.
}

} //namespace Pango

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Pango::FontFace> wrap(PangoFontFace* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Pango::FontFace>( dynamic_cast<Pango::FontFace*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

const Glib::Class& FontFace_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontFace_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_font_face_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void FontFace_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* FontFace_Class::wrap_new(GObject* object)
{
  return new FontFace((PangoFontFace*)object);
}


/* The implementation: */

PangoFontFace* FontFace::gobj_copy()
{
  reference();
  return gobj();
}

FontFace::FontFace(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

FontFace::FontFace(PangoFontFace* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


FontFace::FontFace(FontFace&& src) noexcept
: Glib::Object(std::move(src))
{}

FontFace& FontFace::operator=(FontFace&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


FontFace::~FontFace() noexcept
{}


FontFace::CppClassType FontFace::fontface_class_; // initialize static member

GType FontFace::get_type()
{
  return fontface_class_.init().get_type();
}


GType FontFace::get_base_type()
{
  return pango_font_face_get_type();
}


FontDescription FontFace::describe() const
{
  return FontDescription((pango_font_face_describe(const_cast<PangoFontFace*>(gobj()))));
}

Glib::ustring FontFace::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(pango_font_face_get_face_name(const_cast<PangoFontFace*>(gobj())));
}

bool FontFace::is_synthesized() const
{
  return pango_font_face_is_synthesized(const_cast<PangoFontFace*>(gobj()));
}

Glib::RefPtr<FontFamily> FontFace::get_family()
{
  auto retvalue = Glib::wrap(pango_font_face_get_family(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const FontFamily> FontFace::get_family() const
{
  return const_cast<FontFace*>(this)->get_family();
}


} // namespace Pango


