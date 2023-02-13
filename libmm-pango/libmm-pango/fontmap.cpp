


#include <mm/glib/mm-glib.hpp>

#include <mm/pango/fontmap.hpp>
#include <mm/pango/private/fontmap_p.hpp>


/*
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

#include <mm/pango/cairofontmapimpl.hpp>
#include <mm/pango/context.hpp>
#include <pango/pangocairo.h>

namespace Pango
{

// Custom wrap_new() because we want to create
// a CairoFontMapImpl if the underlying C class implements the PangoCairoFontMap interface.
auto FontMap_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  if (PANGO_IS_CAIRO_FONT_MAP(object))
     return new CairoFontMapImpl((PangoFontMap*)object);
  return new FontMap((PangoFontMap*)object);
}

auto FontMap::list_families() const -> std::vector<Glib::RefPtr<FontFamily>>
{
  //Get the array:
  PangoFontFamily** pFamilies = nullptr;
  int n_families = 0;
  pango_font_map_list_families(const_cast<PangoFontMap*>(gobj()), &pFamilies, &n_families);

  return Glib::ArrayHandler<Glib::RefPtr<FontFamily>>::array_to_vector
      (pFamilies, n_families, Glib::OWNERSHIP_SHALLOW);
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoFontMap* object, const bool take_copy) -> RefPtr<Pango::FontMap>
{
  return Glib::make_refptr_for_instance<Pango::FontMap>( dynamic_cast<Pango::FontMap*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto FontMap_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FontMap_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_font_map_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Gio::ListModel::add_interface(get_type());

  }

  return *this;
}


auto FontMap_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


/* The implementation: */

auto FontMap::gobj_copy() -> PangoFontMap*
{
  reference();
  return gobj();
}

FontMap::FontMap(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FontMap::FontMap(PangoFontMap* castitem)
: Object((GObject*)castitem)
{}


FontMap::FontMap(FontMap&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto FontMap::operator=(FontMap&& src) noexcept -> FontMap&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


FontMap::~FontMap() noexcept = default;

FontMap::CppClassType FontMap::fontmap_class_; // initialize static member

auto FontMap::get_type() -> GType
{
  return fontmap_class_.init().get_type();
}


auto FontMap::get_base_type() -> GType
{
  return pango_font_map_get_type();
}


auto FontMap::load_font(const Glib::RefPtr<Context>& context, const FontDescription& desc) const -> Glib::RefPtr<Font>
{
  return Glib::wrap(pango_font_map_load_font(const_cast<PangoFontMap*>(gobj()), Glib::unwrap(context), desc.gobj()));
}

auto FontMap::load_fontset(const Glib::RefPtr<Context>& context, const FontDescription& desc, const Language& language) const -> Glib::RefPtr<Fontset>
{
  return Glib::wrap(pango_font_map_load_fontset(const_cast<PangoFontMap*>(gobj()), Glib::unwrap(context), desc.gobj(), const_cast<PangoLanguage*>(language.gobj())));
}

auto FontMap::create_context() -> Glib::RefPtr<Context>
{
  return Glib::wrap(pango_font_map_create_context(gobj()));
}

auto FontMap::get_serial() const -> guint
{
  return pango_font_map_get_serial(const_cast<PangoFontMap*>(gobj()));
}

auto FontMap::get_family(const Glib::ustring& name) -> Glib::RefPtr<FontFamily>
{
  auto retvalue = Glib::wrap(pango_font_map_get_family(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FontMap::get_family(const Glib::ustring& name) const -> Glib::RefPtr<const FontFamily>
{
  return const_cast<FontMap*>(this)->get_family(name);
}


} // namespace Pango


