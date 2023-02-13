/* Copyright (C) 2005 The cairomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <libmm-cairo/win32_surface.hpp>
#include <libmm-cairo/private.hpp>

namespace Cairo
{

#ifdef CAIRO_HAS_WIN32_SURFACE

Win32Surface::Win32Surface(cairo_surface_t* cobject, const bool has_reference) :
    Surface(cobject, has_reference)
{}

Win32Surface::~Win32Surface()
{
  // surface is destroyed in base class
}

auto Win32Surface::get_dc () const -> HDC
{
  return cairo_win32_surface_get_dc(m_cobject);
}

auto Win32Surface::get_image () -> RefPtr <ImageSurface>
{
  RefPtr<ImageSurface> surface(new ImageSurface(cairo_win32_surface_get_image(cobj()),
                                                false /* no reference, owned by this win32surface*/));
  check_object_status_and_throw_exception(*this);
  return surface;
}

auto Win32Surface::create (
  const HDC hdc) -> RefPtr <Win32Surface>
{
  const auto cobject = cairo_win32_surface_create(hdc);
  check_status_and_throw_exception(cairo_surface_status(cobject));
  return make_refptr_for_instance<Win32Surface>(new Win32Surface(cobject, true /* has reference */));
}

auto Win32Surface::create_with_dib (Format format, const int width, const int height) -> RefPtr <Win32Surface>
{
  const auto cobject = cairo_win32_surface_create_with_dib((cairo_format_t)format, width, height);
  check_status_and_throw_exception(cairo_surface_status(cobject));
  return make_refptr_for_instance<Win32Surface>(new Win32Surface(cobject, true /* has reference */));
}

auto Win32Surface::create_with_ddb (
  const HDC hdc, Format format, const int width, const int height) -> RefPtr <Win32Surface>
{
  const auto cobject =
    cairo_win32_surface_create_with_ddb(hdc, (cairo_format_t)format, width, height);
  check_status_and_throw_exception(cairo_surface_status(cobject));
  return make_refptr_for_instance<Win32Surface>(new Win32Surface(cobject, true /* has reference */));
}

Win32PrintingSurface::Win32PrintingSurface(cairo_surface_t* cobject, const bool has_reference)
    : Surface(cobject, has_reference)
{
}

Win32PrintingSurface::~Win32PrintingSurface()
{
  // surface is destroyed in base class
}

auto Win32PrintingSurface::create (
  const HDC hdc) -> RefPtr <Win32PrintingSurface>
{
  const auto cobject = cairo_win32_surface_create(hdc);
  check_status_and_throw_exception(cairo_surface_status(cobject));
  return make_refptr_for_instance<Win32PrintingSurface>(new Win32PrintingSurface(cobject, true /* has reference */));
}

#endif // CAIRO_HAS_WIN32_SURFACE

} //namespace Cairo

// vim: ts=2 sw=2 et
