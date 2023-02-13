


#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/cairofontmap.hxx>
#include <libmm-pango/cairofontmap_p.hxx>


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

#include <pango/pangocairo.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoCairoFontMap* object, const bool take_copy) -> RefPtr<Pango::CairoFontMap>
{
  return Glib::make_refptr_for_instance<Pango::CairoFontMap>( Glib::wrap_auto_interface<Pango::CairoFontMap> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Pango
{


/* The *_Class implementation: */

auto CairoFontMap_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &CairoFontMap_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = pango_cairo_font_map_get_type();
  }

  return *this;
}

auto CairoFontMap_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto CairoFontMap_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CairoFontMap((PangoCairoFontMap*)object);
}


/* The implementation: */

CairoFontMap::CairoFontMap()
: Interface(cairofontmap_class_.init())
{}

CairoFontMap::CairoFontMap(PangoCairoFontMap* castitem)
: Interface((GObject*)castitem)
{}

CairoFontMap::CairoFontMap(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

CairoFontMap::CairoFontMap(CairoFontMap&& src) noexcept
: Interface(std::move(src))
{}

auto CairoFontMap::operator=(CairoFontMap&& src) noexcept -> CairoFontMap&
{
  Interface::operator=(std::move(src));
  return *this;
}

CairoFontMap::~CairoFontMap() noexcept = default;

// static
auto CairoFontMap::add_interface (
  const GType gtype_implementer) -> void
{
  cairofontmap_class_.init().add_interface(gtype_implementer);
}

CairoFontMap::CppClassType CairoFontMap::cairofontmap_class_; // initialize static member

auto CairoFontMap::get_type() -> GType
{
  return cairofontmap_class_.init().get_type();
}


auto CairoFontMap::get_base_type() -> GType
{
  return pango_cairo_font_map_get_type();
}


auto CairoFontMap::get_default() -> Glib::RefPtr<FontMap>
{

  auto retvalue = Glib::wrap(pango_cairo_font_map_get_default());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto CairoFontMap::set_default () -> void
{
  pango_cairo_font_map_set_default(gobj());
}

auto CairoFontMap::get_font_type() const -> Cairo::FontType
{
  return static_cast<Cairo::FontType>(pango_cairo_font_map_get_font_type(const_cast<PangoCairoFontMap*>(gobj())));
}

auto CairoFontMap::set_resolution (
  const double dpi) -> void
{
  pango_cairo_font_map_set_resolution(gobj(), dpi);
}

auto CairoFontMap::get_resolution() const -> double
{
  return pango_cairo_font_map_get_resolution(const_cast<PangoCairoFontMap*>(gobj()));
}


} // namespace Pango

