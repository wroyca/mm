

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileattributeinfolist.hxx>
#include <libmm-gio/fileattributeinfolist_p.hxx>

#include <gio/gio.h>

namespace Gio
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

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GFileAttributeInfoList* object, const bool take_copy) -> RefPtr<Gio::FileAttributeInfoList>
  {
    if (take_copy && object)
      g_file_attribute_info_list_ref (object);

    return Glib::make_refptr_for_instance<Gio::FileAttributeInfoList> (
        reinterpret_cast<Gio::FileAttributeInfoList*> (object));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileAttributeInfoList::create () -> Glib::RefPtr<FileAttributeInfoList>
  {
    return Glib::make_refptr_for_instance<FileAttributeInfoList> (
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
  FileAttributeInfoList::dup () const -> Glib::RefPtr<FileAttributeInfoList>
  {
    return Glib::wrap (g_file_attribute_info_list_dup (
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

} // namespace Gio
