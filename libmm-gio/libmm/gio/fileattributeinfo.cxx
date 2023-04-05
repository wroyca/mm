// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileattributeinfo.hxx>
#include <libmm/gio/fileattributeinfo_p.hxx>

#include <gio/gio.h>

namespace gio
{

  FileAttributeInfo::FileAttributeInfo (const GFileAttributeInfo* ginfo)
    : m_name (ginfo->name ? ginfo->name : ""),
      m_type (static_cast<FileAttributeType> (ginfo->type)),
      m_flags (static_cast<Flags> (ginfo->flags))
  {
  }

  FileAttributeInfo::FileAttributeInfo (const FileAttributeInfo& other)
  {
    *this = other;
  }

  auto
  FileAttributeInfo::operator= (const FileAttributeInfo& other) -> FileAttributeInfo& = default;

  FileAttributeInfo::FileAttributeInfo (FileAttributeInfo&& other) noexcept
    : m_name (std::move (other.m_name)),
      m_type (std::move (other.m_type)),
      m_flags (std::move (other.m_flags))
  {
  }

  auto
  FileAttributeInfo::operator= (FileAttributeInfo&& other) noexcept -> FileAttributeInfo&
  {
    m_name = std::move (other.m_name);
    m_type = std::move (other.m_type);
    m_flags = std::move (other.m_flags);

    return *this;
  }

  FileAttributeInfo::~FileAttributeInfo () = default;

  auto
  FileAttributeInfo::get_name () const -> std::string
  {
    return m_name;
  }

  auto
  FileAttributeInfo::get_type () const -> FileAttributeType
  {
    return m_type;
  }

  auto
  FileAttributeInfo::get_flags () const -> Flags
  {
    return m_flags;
  }

} // namespace gio

namespace
{
}

auto
glib::Value<gio::FileAttributeType>::value_type () -> GType
{
  return g_file_attribute_type_get_type ();
}

auto
glib::Value<gio::FileAttributeStatus>::value_type () -> GType
{
  return g_file_attribute_status_get_type ();
}

auto
glib::Value<gio::FileAttributeInfo::Flags>::value_type () -> GType
{
  return g_file_attribute_info_flags_get_type ();
}

namespace gio
{

}
