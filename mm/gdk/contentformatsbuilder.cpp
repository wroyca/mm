// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/contentformatsbuilder.hpp>
#include <mm/gdk/private/contentformatsbuilder_p.hpp>


/* Copyright (C) 2017 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<ContentFormatsBuilder*>(gobject) is needed:
 *
 * A ContentFormatsBuilder instance is in fact always a GdkContentFormatsBuilder instance.
 * Unfortunately, GdkContentFormatsBuilder cannot be a member of ContentFormatsBuilder,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ContentFormatsBuilder does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GdkContentFormatsBuilder* object, bool take_copy) -> Glib::RefPtr<Gdk::ContentFormatsBuilder>
{
  if(take_copy && object)
    gdk_content_formats_builder_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gdk::ContentFormatsBuilder>(reinterpret_cast<Gdk::ContentFormatsBuilder*>(object));
}

} // namespace Glib


namespace Gdk
{

void ContentFormatsBuilder::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_content_formats_builder_ref(reinterpret_cast<GdkContentFormatsBuilder*>(const_cast<ContentFormatsBuilder*>(this)));
}

void ContentFormatsBuilder::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gdk_content_formats_builder_unref(reinterpret_cast<GdkContentFormatsBuilder*>(const_cast<ContentFormatsBuilder*>(this)));
}

auto ContentFormatsBuilder::gobj() -> GdkContentFormatsBuilder*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GdkContentFormatsBuilder*>(this);
}

auto ContentFormatsBuilder::gobj() const -> const GdkContentFormatsBuilder*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GdkContentFormatsBuilder*>(this);
}

auto ContentFormatsBuilder::gobj_copy() const -> GdkContentFormatsBuilder*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GdkContentFormatsBuilder*>(const_cast<ContentFormatsBuilder*>(this));
  gdk_content_formats_builder_ref(gobject);
  return gobject;
}


auto ContentFormatsBuilder::create() -> Glib::RefPtr<ContentFormatsBuilder>
{
  return Glib::wrap(gdk_content_formats_builder_new());
}

void ContentFormatsBuilder::add_formats(const Glib::RefPtr<const ContentFormats>& formats)
{
  gdk_content_formats_builder_add_formats(gobj(), Glib::unwrap(formats));
}

void ContentFormatsBuilder::add_mime_type(const Glib::ustring& mime_type)
{
  gdk_content_formats_builder_add_mime_type(gobj(), mime_type.c_str());
}

void ContentFormatsBuilder::add_gtype(GType gtype)
{
  gdk_content_formats_builder_add_gtype(gobj(), gtype);
}

auto ContentFormatsBuilder::to_formats() -> Glib::RefPtr<ContentFormats>
{
  return Glib::wrap(gdk_content_formats_builder_to_formats(gobj()));
}


} // namespace Gdk


