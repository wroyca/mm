


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileattributeinfolist.hxx>
#include <libmm-gio/fileattributeinfolist_p.hxx>


/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace Gio
{

FileAttributeInfoList::operator bool() const
{
  return !empty();
}

auto
FileAttributeInfoList::empty() const -> bool
{
  return gobj() == nullptr;
}

auto
FileAttributeInfoList::lookup(const std::string& name) const -> FileAttributeInfo
{
  const auto cobject = const_cast<GFileAttributeInfoList*>(gobj());
  const GFileAttributeInfo* cinfo = g_file_attribute_info_list_lookup(cobject, name.c_str());

  FileAttributeInfo info(cinfo);
  return info;
}

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<FileAttributeInfoList*>(gobject) is needed:
 *
 * A FileAttributeInfoList instance is in fact always a GFileAttributeInfoList instance.
 * Unfortunately, GFileAttributeInfoList cannot be a member of FileAttributeInfoList,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because FileAttributeInfoList does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GFileAttributeInfoList* object, const bool take_copy) -> RefPtr<Gio::FileAttributeInfoList>
{
  if(take_copy && object)
    g_file_attribute_info_list_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::FileAttributeInfoList>(reinterpret_cast<Gio::FileAttributeInfoList*>(object));
}

} // namespace Glib


namespace Gio
{

// static
auto FileAttributeInfoList::create() -> Glib::RefPtr<FileAttributeInfoList>
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<FileAttributeInfoList>(reinterpret_cast<FileAttributeInfoList*>(g_file_attribute_info_list_new()));
}

auto FileAttributeInfoList::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_file_attribute_info_list_ref(reinterpret_cast<GFileAttributeInfoList*>(const_cast<FileAttributeInfoList*>(this)));
}

auto FileAttributeInfoList::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_file_attribute_info_list_unref(reinterpret_cast<GFileAttributeInfoList*>(const_cast<FileAttributeInfoList*>(this)));
}

auto FileAttributeInfoList::gobj() -> GFileAttributeInfoList*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GFileAttributeInfoList*>(this);
}

auto FileAttributeInfoList::gobj() const -> const GFileAttributeInfoList*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GFileAttributeInfoList*>(this);
}

auto FileAttributeInfoList::gobj_copy() const -> GFileAttributeInfoList*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GFileAttributeInfoList*>(const_cast<FileAttributeInfoList*>(this));
  g_file_attribute_info_list_ref(gobject);
  return gobject;
}


auto FileAttributeInfoList::dup() const -> Glib::RefPtr<FileAttributeInfoList>
{
  return Glib::wrap(g_file_attribute_info_list_dup(const_cast<GFileAttributeInfoList*>(gobj())));
}

auto FileAttributeInfoList::add (
  const std::string &name, FileAttributeType type, FileAttributeInfo::Flags flags) -> void
{
  g_file_attribute_info_list_add(gobj(), name.c_str(), static_cast<GFileAttributeType>(type), static_cast<GFileAttributeInfoFlags>(flags));
}


} // namespace Gio

