


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/resource.hxx>
#include <libmm-gio/resource_p.hxx>


/* Copyright (C) 2012 The giomm Development Team
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
// Hand-coded because we want Flags& instead of guint32&.
auto Resource::get_info (
  const std::string &path, gsize &size, Flags &flags,
  LookupFlags lookup_flags) const -> void
{
  guint32 file_flags = 0;
  GError* gerror = nullptr;
  // Ignore the gboolean return value from g_resource_get_info().
  // gerror is set if and only if the return value is FALSE.
  g_resource_get_info(const_cast<GResource*>(gobj()), path.c_str(),
    (GResourceLookupFlags)lookup_flags, &size, &file_flags, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  flags = static_cast<Flags>(file_flags);
}

auto Resource::get_file_exists (const std::string &path, LookupFlags lookup_flags) const -> void
{
  GError* gerror = nullptr;
  g_resource_get_info(const_cast<GResource*>(gobj()), path.c_str(),
    (GResourceLookupFlags)lookup_flags, nullptr, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
}

auto
Resource::get_file_exists_nothrow(const std::string& path, LookupFlags lookup_flags) const -> bool
{
  return g_resource_get_info(const_cast<GResource*>(gobj()), path.c_str(),
    (GResourceLookupFlags)lookup_flags, nullptr, nullptr, nullptr);
}

// Hand-coded because we want Flags& instead of guint32&.
// static
auto Resource::get_info_global (
  const std::string &path, gsize &size, Flags &flags, LookupFlags lookup_flags) -> void
{
  guint32 file_flags = 0;
  GError* gerror = nullptr;
  // Ignore the gboolean return value from g_resources_get_info().
  // gerror is set if and only if the return value is FALSE.
  g_resources_get_info(
    path.c_str(), (GResourceLookupFlags)lookup_flags, &size, &file_flags, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
  flags = static_cast<Flags>(file_flags);
}

// static
auto Resource::get_file_exists_global (const std::string &path, LookupFlags lookup_flags) -> void
{
  GError* gerror = nullptr;
  g_resources_get_info(path.c_str(), (GResourceLookupFlags)lookup_flags, nullptr, nullptr, &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);
}

// static
auto
Resource::get_file_exists_global_nothrow(const std::string& path, LookupFlags lookup_flags) -> bool
{
  return g_resources_get_info(
    path.c_str(), (GResourceLookupFlags)lookup_flags, nullptr, nullptr, nullptr);
}

} // namespace Gio

namespace
{
} // anonymous namespace


Gio::ResourceError::ResourceError(const Code error_code, const Glib::ustring& error_message)
: Error(G_RESOURCE_ERROR, error_code, error_message)
{}

Gio::ResourceError::ResourceError(GError* gobject)
: Error(gobject)
{}

auto Gio::ResourceError::code() const -> Code
{
  return static_cast<Code>(Error::code());
}

auto Gio::ResourceError::throw_func (GError *gobject) -> void
{
  throw ResourceError(gobject);
}

// static
auto Glib::Value<Gio::Resource::Flags>::value_type() -> GType
{
  return g_resource_flags_get_type();
}

// static
auto Glib::Value<Gio::Resource::LookupFlags>::value_type() -> GType
{
  return g_resource_lookup_flags_get_type();
}


/* Why reinterpret_cast<Resource*>(gobject) is needed:
 *
 * A Resource instance is in fact always a GResource instance.
 * Unfortunately, GResource cannot be a member of Resource,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because Resource does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GResource* object, const bool take_copy) -> RefPtr<Gio::Resource>
{
  if(take_copy && object)
    g_resource_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::Resource>(reinterpret_cast<Gio::Resource*>(object));
}

} // namespace Glib


namespace Gio
{

auto Resource::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_resource_ref(reinterpret_cast<GResource*>(const_cast<Resource*>(this)));
}

auto Resource::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_resource_unref(reinterpret_cast<GResource*>(const_cast<Resource*>(this)));
}

auto Resource::gobj() -> GResource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GResource*>(this);
}

auto Resource::gobj() const -> const GResource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GResource*>(this);
}

auto Resource::gobj_copy() const -> GResource*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GResource*>(const_cast<Resource*>(this));
  g_resource_ref(gobject);
  return gobject;
}


auto Resource::create_from_data(const Glib::RefPtr<const Glib::Bytes>& data) -> Glib::RefPtr<Resource>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resource_new_from_data(const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(data)), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::create_from_file(const std::string& filename) -> Glib::RefPtr<Resource>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resource_load(filename.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::open_stream(const std::string& path, LookupFlags lookup_flags) const -> Glib::RefPtr<InputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resource_open_stream(const_cast<GResource*>(gobj()), path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::lookup_data(const std::string& path, LookupFlags lookup_flags) const -> Glib::RefPtr<const Glib::Bytes>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resource_lookup_data(const_cast<GResource*>(gobj()), path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::enumerate_children(const std::string& path, LookupFlags lookup_flags) const -> std::vector<std::string>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ArrayHandler<std::string>::array_to_vector(g_resource_enumerate_children(const_cast<GResource*>(gobj()), path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::register_global () -> void
{
  g_resources_register(gobj());
}

auto Resource::unregister_global () -> void
{
  g_resources_unregister(gobj());
}

auto Resource::open_stream_global(const std::string& path, LookupFlags lookup_flags) -> Glib::RefPtr<InputStream>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resources_open_stream(path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::lookup_data_global(const std::string& path, LookupFlags lookup_flags) -> Glib::RefPtr<const Glib::Bytes>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_resources_lookup_data(path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto Resource::enumerate_children_global(const std::string& path, LookupFlags lookup_flags) -> std::vector<std::string>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::ArrayHandler<std::string>::array_to_vector(g_resources_enumerate_children(path.c_str(), static_cast<GResourceLookupFlags>(lookup_flags), &gerror), Glib::OWNERSHIP_DEEP);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


