// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileattributeinfolist.hxx>
#include <libmm/gio/fileattributeinfolist_p.hxx>

#include <gio/gio.h>

namespace gio
{

  FileAttributeInfoList::operator bool () const
  {
    return !empty ();
  }

  auto
  FileAttributeInfoList::empty () const -> bool
  {
    return gobj () == nullptr;
  }

  auto
  FileAttributeInfoList::lookup (const std::string& name) const -> FileAttributeInfo
  {
    const auto cobject = const_cast<GFileAttributeInfoList*> (gobj ());
    const GFileAttributeInfo* cinfo =
        g_file_attribute_info_list_lookup (cobject, name.c_str ());

    FileAttributeInfo info (cinfo);
    return info;
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GFileAttributeInfoList* object, const bool take_copy) -> RefPtr<gio::FileAttributeInfoList>
  {
    if (take_copy && object)
      g_file_attribute_info_list_ref (object);

    return glib::make_refptr_for_instance<gio::FileAttributeInfoList> (
        reinterpret_cast<gio::FileAttributeInfoList*> (object));
  }

} // namespace glib

namespace gio
{

  auto
  FileAttributeInfoList::create () -> glib::RefPtr<FileAttributeInfoList>
  {
    return glib::make_refptr_for_instance<FileAttributeInfoList> (
        reinterpret_cast<FileAttributeInfoList*> (
            g_file_attribute_info_list_new ()));
  }

  auto
  FileAttributeInfoList::reference () const -> void
  {
    g_file_attribute_info_list_ref (reinterpret_cast<GFileAttributeInfoList*> (
        const_cast<FileAttributeInfoList*> (this)));
  }

  auto
  FileAttributeInfoList::unreference () const -> void
  {
    g_file_attribute_info_list_unref (
        reinterpret_cast<GFileAttributeInfoList*> (
            const_cast<FileAttributeInfoList*> (this)));
  }

  auto
  FileAttributeInfoList::gobj () -> GFileAttributeInfoList*
  {
    return reinterpret_cast<GFileAttributeInfoList*> (this);
  }

  auto
  FileAttributeInfoList::gobj () const -> const GFileAttributeInfoList*
  {
    return reinterpret_cast<const GFileAttributeInfoList*> (this);
  }

  auto
  FileAttributeInfoList::gobj_copy () const -> GFileAttributeInfoList*
  {
    const auto gobject = reinterpret_cast<GFileAttributeInfoList*> (
        const_cast<FileAttributeInfoList*> (this));
    g_file_attribute_info_list_ref (gobject);
    return gobject;
  }

  auto
  FileAttributeInfoList::dup () const -> glib::RefPtr<FileAttributeInfoList>
  {
    return glib::wrap (g_file_attribute_info_list_dup (
        const_cast<GFileAttributeInfoList*> (gobj ())));
  }

  auto
  FileAttributeInfoList::add (const std::string& name,
                              FileAttributeType type,
                              FileAttributeInfo::Flags flags) -> void
  {
    g_file_attribute_info_list_add (
        gobj (),
        name.c_str (),
        static_cast<GFileAttributeType> (type),
        static_cast<GFileAttributeInfoFlags> (flags));
  }

} // namespace gio
