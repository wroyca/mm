


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/cursor.hpp>
#include <mm/gdk/private/cursor_p.hpp>


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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gdk/gdk.h>

namespace Gdk
{

} //namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkCursor* object, const bool take_copy) -> RefPtr<Gdk::Cursor>
{
  return Glib::make_refptr_for_instance<Gdk::Cursor>( dynamic_cast<Gdk::Cursor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Cursor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Do not derive a GType, or use a derived class:
    gtype_ = gdk_cursor_get_type();

  }

  return *this;
}


auto Cursor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Cursor((GdkCursor*)object);
}


/* The implementation: */

auto Cursor::gobj_copy() -> GdkCursor*
{
  reference();
  return gobj();
}

Cursor::Cursor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Cursor::Cursor(GdkCursor* castitem)
: Object((GObject*)castitem)
{}


Cursor::Cursor(Cursor&& src) noexcept
: Object(std::move(src))
{}

auto Cursor::operator=(Cursor&& src) noexcept -> Cursor&
{
  Object::operator=(std::move(src));
  return *this;
}


Cursor::~Cursor() noexcept = default;

Cursor::CppClassType Cursor::cursor_class_; // initialize static member

auto Cursor::get_type() -> GType
{
  return cursor_class_.init().get_type();
}


auto Cursor::get_base_type() -> GType
{
  return gdk_cursor_get_type();
}


auto Cursor::create(const Glib::RefPtr<const Texture>& texture, const int hotspot_x, const int hotspot_y, const Glib::RefPtr<Cursor>& fallback) -> Glib::RefPtr<Cursor>
{
  return Glib::wrap(gdk_cursor_new_from_texture(const_cast<GdkTexture*>(Glib::unwrap(texture)), hotspot_x, hotspot_y, Glib::unwrap(fallback)));
}

auto Cursor::create(const Glib::ustring& name, const Glib::RefPtr<Cursor>& fallback) -> Glib::RefPtr<Cursor>
{
  return Glib::wrap(gdk_cursor_new_from_name(name.c_str(), Glib::unwrap(fallback)));
}

auto Cursor::get_fallback() -> Glib::RefPtr<Cursor>
{
  auto retvalue = Glib::wrap(gdk_cursor_get_fallback(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Cursor::get_fallback() const -> Glib::RefPtr<const Cursor>
{
  return const_cast<Cursor*>(this)->get_fallback();
}

auto Cursor::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_cursor_get_name(const_cast<GdkCursor*>(gobj())));
}

auto Cursor::get_texture() -> Glib::RefPtr<Texture>
{
  auto retvalue = Glib::wrap(gdk_cursor_get_texture(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Cursor::get_texture() const -> Glib::RefPtr<const Texture>
{
  return const_cast<Cursor*>(this)->get_texture();
}

auto Cursor::get_hotspot_x() const -> int
{
  return gdk_cursor_get_hotspot_x(const_cast<GdkCursor*>(gobj()));
}

auto Cursor::get_hotspot_y() const -> int
{
  return gdk_cursor_get_hotspot_y(const_cast<GdkCursor*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Cursor>>::value,
  "Type Glib::RefPtr<Cursor> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Cursor::property_fallback() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Cursor> >
{
  return {this, "fallback"};
}

auto Cursor::property_hotspot_x() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "hotspot-x"};
}

auto Cursor::property_hotspot_y() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "hotspot-y"};
}

auto Cursor::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Texture>>::value,
  "Type Glib::RefPtr<Texture> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Cursor::property_texture() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Texture> >
{
  return {this, "texture"};
}


} // namespace Gdk


