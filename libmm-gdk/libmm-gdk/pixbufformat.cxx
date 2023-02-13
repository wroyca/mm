


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbufformat.hxx>
#include <libmm-gdk/pixbufformat_p.hxx>


/* Copyright (C) 2002 The gtkmm Development Team
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

#include <gdk-pixbuf/gdk-pixbuf.h>

namespace Gdk
{

PixbufFormat::PixbufFormat()
: gobject_(nullptr) //because only a gdk-pixbuf backend can create them.
{
}

} // namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkPixbufFormat* object, const bool take_copy) -> Gdk::PixbufFormat
{
  return Gdk::PixbufFormat(object, take_copy);
}

} // namespace Glib


namespace Gdk
{


// static
auto PixbufFormat::get_type() -> GType
{
  return gdk_pixbuf_format_get_type();
}


PixbufFormat::PixbufFormat(const PixbufFormat& other)
:
  gobject_ (other.gobject_ ? gdk_pixbuf_format_copy(other.gobject_) : nullptr)
{}

PixbufFormat::PixbufFormat(PixbufFormat&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

auto PixbufFormat::operator=(PixbufFormat&& other) noexcept -> PixbufFormat&
{
  PixbufFormat temp (std::move(other));
  swap(temp);
  return *this;
}

PixbufFormat::PixbufFormat(GdkPixbufFormat* gobject, const bool make_a_copy)
:
  // For BoxedType wrappers, make_a_copy is true by default.  The static
  // BoxedType wrappers must always take a copy, thus make_a_copy = true
  // ensures identical behaviour if the default argument is used.
  gobject_ (make_a_copy && gobject ? gdk_pixbuf_format_copy(gobject) : gobject)
{}

auto PixbufFormat::operator=(const PixbufFormat& other) -> PixbufFormat&
{
  PixbufFormat temp (other);
  swap(temp);
  return *this;
}

PixbufFormat::~PixbufFormat() noexcept
{
  if(gobject_)
    gdk_pixbuf_format_free(gobject_);
}

auto PixbufFormat::swap (PixbufFormat &other) noexcept -> void
{
  std::swap(gobject_, other.gobject_);
}

auto PixbufFormat::gobj_copy() const -> GdkPixbufFormat*
{
  return gdk_pixbuf_format_copy(gobject_);
}


auto PixbufFormat::get_name() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_name(const_cast<GdkPixbufFormat*>(gobj())));
}

auto PixbufFormat::get_description() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_description(const_cast<GdkPixbufFormat*>(gobj())));
}

auto PixbufFormat::get_mime_types() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gdk_pixbuf_format_get_mime_types(const_cast<GdkPixbufFormat*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto PixbufFormat::get_extensions() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(gdk_pixbuf_format_get_extensions(const_cast<GdkPixbufFormat*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto PixbufFormat::is_save_option_supported(const Glib::ustring& option_key) const -> bool
{
  return gdk_pixbuf_format_is_save_option_supported(const_cast<GdkPixbufFormat*>(gobj()), option_key.c_str());
}

auto PixbufFormat::is_writable() const -> bool
{
  return gdk_pixbuf_format_is_writable(const_cast<GdkPixbufFormat*>(gobj()));
}

auto PixbufFormat::is_scalable() const -> bool
{
  return gdk_pixbuf_format_is_scalable(const_cast<GdkPixbufFormat*>(gobj()));
}

auto PixbufFormat::is_disabled() const -> bool
{
  return gdk_pixbuf_format_is_disabled(const_cast<GdkPixbufFormat*>(gobj()));
}

auto PixbufFormat::set_disabled (
  const bool disabled) -> void
{
  gdk_pixbuf_format_set_disabled(gobj(), disabled);
}

auto PixbufFormat::get_license() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gdk_pixbuf_format_get_license(const_cast<GdkPixbufFormat*>(gobj())));
}


} // namespace Gdk

