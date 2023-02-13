


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/fontface.hpp>
#include <libmm-pango/fontface_p.hpp>


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

#include <libmm-pango/fontfamily.hpp>

namespace Pango
{

auto FontFace::list_sizes() const -> std::vector<int>
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

auto wrap(PangoFontFace* object, const bool take_copy) -> RefPtr<Pango::FontFace>
{
  return Glib::make_refptr_for_instance<Pango::FontFace>( dynamic_cast<Pango::FontFace*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto FontFace_Class::init() -> const Class&
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


auto FontFace_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FontFace_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FontFace((PangoFontFace*)object);
}


/* The implementation: */

auto FontFace::gobj_copy() -> PangoFontFace*
{
  reference();
  return gobj();
}

FontFace::FontFace(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FontFace::FontFace(PangoFontFace* castitem)
: Object((GObject*)castitem)
{}


FontFace::FontFace(FontFace&& src) noexcept
: Object(std::move(src))
{}

auto FontFace::operator=(FontFace&& src) noexcept -> FontFace&
{
  Object::operator=(std::move(src));
  return *this;
}


FontFace::~FontFace() noexcept = default;

FontFace::CppClassType FontFace::fontface_class_; // initialize static member

auto FontFace::get_type() -> GType
{
  return fontface_class_.init().get_type();
}


auto FontFace::get_base_type() -> GType
{
  return pango_font_face_get_type();
}


auto FontFace::describe() const -> FontDescription
{
  return FontDescription(pango_font_face_describe(const_cast<PangoFontFace*>(gobj())));
}

auto FontFace::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(pango_font_face_get_face_name(const_cast<PangoFontFace*>(gobj())));
}

auto FontFace::is_synthesized() const -> bool
{
  return pango_font_face_is_synthesized(const_cast<PangoFontFace*>(gobj()));
}

auto FontFace::get_family() -> Glib::RefPtr<FontFamily>
{
  auto retvalue = Glib::wrap(pango_font_face_get_family(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontFace::get_family() const -> Glib::RefPtr<const FontFamily>
{
  return const_cast<FontFace*>(this)->get_family();
}


} // namespace Pango


