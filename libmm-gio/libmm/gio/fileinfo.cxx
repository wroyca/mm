// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileinfo.hxx>
#include <libmm/gio/fileinfo_p.hxx>

#include <gio/gio.h>

namespace gio
{

  auto
  FileAttributeMatcher::create (const std::string& attributes) -> glib::RefPtr<FileAttributeMatcher>
  {
    return glib::wrap (g_file_attribute_matcher_new (attributes.c_str ()));
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GFileAttributeMatcher* object, const bool take_copy) -> RefPtr<gio::FileAttributeMatcher>
  {
    if (take_copy && object)
      g_file_attribute_matcher_ref (object);

    return glib::make_refptr_for_instance<gio::FileAttributeMatcher> (
        reinterpret_cast<gio::FileAttributeMatcher*> (object));
  }

} // namespace glib

namespace gio
{

  auto
  FileAttributeMatcher::reference () const -> void
  {
    g_file_attribute_matcher_ref (reinterpret_cast<GFileAttributeMatcher*> (
        const_cast<FileAttributeMatcher*> (this)));
  }

  auto
  FileAttributeMatcher::unreference () const -> void
  {
    g_file_attribute_matcher_unref (reinterpret_cast<GFileAttributeMatcher*> (
        const_cast<FileAttributeMatcher*> (this)));
  }

  auto
  FileAttributeMatcher::gobj () -> GFileAttributeMatcher*
  {
    return reinterpret_cast<GFileAttributeMatcher*> (this);
  }

  auto
  FileAttributeMatcher::gobj () const -> const GFileAttributeMatcher*
  {
    return reinterpret_cast<const GFileAttributeMatcher*> (this);
  }

  auto
  FileAttributeMatcher::gobj_copy () const -> GFileAttributeMatcher*
  {
    const auto gobject = reinterpret_cast<GFileAttributeMatcher*> (
        const_cast<FileAttributeMatcher*> (this));
    g_file_attribute_matcher_ref (gobject);
    return gobject;
  }

  auto
  FileAttributeMatcher::create_difference (
      const glib::RefPtr<const FileAttributeMatcher>& subtract) const -> glib::RefPtr<FileAttributeMatcher>
  {
    return glib::wrap (g_file_attribute_matcher_subtract (
        const_cast<GFileAttributeMatcher*> (gobj ()),
        const_cast<GFileAttributeMatcher*> (glib::unwrap (subtract))));
  }

  auto
  FileAttributeMatcher::matches (const std::string& attribute) const -> bool
  {
    return g_file_attribute_matcher_matches (
        const_cast<GFileAttributeMatcher*> (gobj ()),
        attribute.c_str ());
  }

  auto
  FileAttributeMatcher::matches_only (const std::string& attribute) const -> bool
  {
    return g_file_attribute_matcher_matches_only (
        const_cast<GFileAttributeMatcher*> (gobj ()),
        attribute.c_str ());
  }

  auto
  FileAttributeMatcher::enumerate_namespace (const std::string& ns) -> bool
  {
    return g_file_attribute_matcher_enumerate_namespace (gobj (), ns.c_str ());
  }

  auto
  FileAttributeMatcher::enumerate_next () -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_file_attribute_matcher_enumerate_next (gobj ()));
  }

  auto
  FileAttributeMatcher::to_string () const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_file_attribute_matcher_to_string (
            const_cast<GFileAttributeMatcher*> (gobj ())));
  }

} // namespace gio

namespace glib
{

  auto
  wrap (GFileInfo* object, const bool take_copy) -> RefPtr<gio::FileInfo>
  {
    return glib::make_refptr_for_instance<gio::FileInfo> (
        dynamic_cast<gio::FileInfo*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FileInfo_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileInfo_Class::class_init_function;

      register_derived_type (g_file_info_get_type ());
    }

    return *this;
  }

  auto
  FileInfo_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileInfo_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileInfo ((GFileInfo*) object);
  }

  auto
  FileInfo::gobj_copy () -> GFileInfo*
  {
    reference ();
    return gobj ();
  }

  FileInfo::FileInfo (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FileInfo::FileInfo (GFileInfo* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FileInfo::FileInfo (FileInfo&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  FileInfo::operator= (FileInfo&& src) noexcept -> FileInfo&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  FileInfo::~FileInfo () noexcept = default;

  FileInfo::CppClassType FileInfo::fileinfo_class_;

  auto
  FileInfo::get_type () -> GType
  {
    return fileinfo_class_.init ().get_type ();
  }

  auto
  FileInfo::get_base_type () -> GType
  {
    return g_file_info_get_type ();
  }

  FileInfo::FileInfo ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (fileinfo_class_.init ()))
  {
  }

  auto
  FileInfo::dup () const -> glib::RefPtr<FileInfo>
  {
    return glib::wrap (g_file_info_dup (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::copy_into (glib::RefPtr<FileInfo>& dest_info) const -> void
  {
    g_file_info_copy_into (const_cast<GFileInfo*> (gobj ()),
                           glib::unwrap (dest_info));
  }

  auto
  FileInfo::has_attribute (const std::string& attribute) const -> bool
  {
    return g_file_info_has_attribute (const_cast<GFileInfo*> (gobj ()),
                                      attribute.c_str ());
  }

  auto
  FileInfo::has_namespace (const std::string& name_space) const -> bool
  {
    return g_file_info_has_namespace (const_cast<GFileInfo*> (gobj ()),
                                      name_space.c_str ());
  }

  auto
  FileInfo::list_attributes (const std::string& name_space) const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_file_info_list_attributes (
            const_cast<GFileInfo*> (gobj ()),
            name_space.empty () ? nullptr : name_space.c_str ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  FileInfo::list_attributes () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_file_info_list_attributes (const_cast<GFileInfo*> (gobj ()), nullptr),
        glib::OWNERSHIP_DEEP);
  }

  auto
  FileInfo::get_attribute_type (const std::string& attribute) const -> FileAttributeType
  {
    return static_cast<FileAttributeType> (
        g_file_info_get_attribute_type (const_cast<GFileInfo*> (gobj ()),
                                        attribute.c_str ()));
  }

  auto
  FileInfo::remove_attribute (const std::string& attribute) -> void
  {
    g_file_info_remove_attribute (gobj (), attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_status (const std::string& attribute) const -> FileAttributeStatus
  {
    return static_cast<FileAttributeStatus> (
        g_file_info_get_attribute_status (const_cast<GFileInfo*> (gobj ()),
                                          attribute.c_str ()));
  }

  auto
  FileInfo::get_attribute_string (const std::string& attribute) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_file_info_get_attribute_string (const_cast<GFileInfo*> (gobj ()),
                                          attribute.c_str ()));
  }

  auto
  FileInfo::get_attribute_strings (const std::string& attribute) const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_file_info_get_attribute_stringv (const_cast<GFileInfo*> (gobj ()),
                                           attribute.c_str ()),
        glib::OWNERSHIP_NONE);
  }

  auto
  FileInfo::get_attribute_as_string (const std::string& attribute) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_file_info_get_attribute_as_string (const_cast<GFileInfo*> (gobj ()),
                                             attribute.c_str ()));
  }

  auto
  FileInfo::get_attribute_byte_string (const std::string& attribute) const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_file_info_get_attribute_byte_string (const_cast<GFileInfo*> (gobj ()),
                                               attribute.c_str ()));
  }

  auto
  FileInfo::get_attribute_boolean (const std::string& attribute) const -> bool
  {
    return g_file_info_get_attribute_boolean (const_cast<GFileInfo*> (gobj ()),
                                              attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_uint32 (const std::string& attribute) const -> guint32
  {
    return g_file_info_get_attribute_uint32 (const_cast<GFileInfo*> (gobj ()),
                                             attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_int32 (const std::string& attribute) const -> gint32
  {
    return g_file_info_get_attribute_int32 (const_cast<GFileInfo*> (gobj ()),
                                            attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_uint64 (const std::string& attribute) const -> guint64
  {
    return g_file_info_get_attribute_uint64 (const_cast<GFileInfo*> (gobj ()),
                                             attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_int64 (const std::string& attribute) const -> gint64
  {
    return g_file_info_get_attribute_int64 (const_cast<GFileInfo*> (gobj ()),
                                            attribute.c_str ());
  }

  auto
  FileInfo::get_attribute_object (const std::string& attribute) const -> glib::RefPtr<Object>
  {
    return glib::wrap (
        g_file_info_get_attribute_object (const_cast<GFileInfo*> (gobj ()),
                                          attribute.c_str ()));
  }

  auto
  FileInfo::set_attribute_status (const std::string& attribute,
                                  FileAttributeStatus status) -> bool
  {
    return g_file_info_set_attribute_status (
        gobj (),
        attribute.c_str (),
        static_cast<GFileAttributeStatus> (status));
  }

  auto
  FileInfo::set_attribute_string (const std::string& attribute,
                                  const glib::ustring& attr_value) -> void
  {
    g_file_info_set_attribute_string (gobj (),
                                      attribute.c_str (),
                                      attr_value.c_str ());
  }

  auto
  FileInfo::set_attribute_strings (const std::string& attribute,
                                   const std::vector<glib::ustring>& attr_value) -> void
  {
    g_file_info_set_attribute_stringv (
        gobj (),
        attribute.c_str (),
        const_cast<char**> (
            glib::ArrayHandler<glib::ustring>::vector_to_array (attr_value)
                .data ()));
  }

  auto
  FileInfo::set_attribute_byte_string (const std::string& attribute,
                                       const std::string& attr_value) -> void
  {
    g_file_info_set_attribute_byte_string (gobj (),
                                           attribute.c_str (),
                                           attr_value.c_str ());
  }

  auto
  FileInfo::set_attribute_boolean (const std::string& attribute,
                                   const bool attr_value) -> void
  {
    g_file_info_set_attribute_boolean (gobj (), attribute.c_str (), attr_value);
  }

  auto
  FileInfo::set_attribute_uint32 (const std::string& attribute,
                                  const guint32 attr_value) -> void
  {
    g_file_info_set_attribute_uint32 (gobj (), attribute.c_str (), attr_value);
  }

  auto
  FileInfo::set_attribute_int32 (const std::string& attribute,
                                 const gint32 attr_value) -> void
  {
    g_file_info_set_attribute_int32 (gobj (), attribute.c_str (), attr_value);
  }

  auto
  FileInfo::set_attribute_uint64 (const std::string& attribute,
                                  const guint64 attr_value) -> void
  {
    g_file_info_set_attribute_uint64 (gobj (), attribute.c_str (), attr_value);
  }

  auto
  FileInfo::set_attribute_int64 (const std::string& attribute,
                                 const gint64 attr_value) -> void
  {
    g_file_info_set_attribute_int64 (gobj (), attribute.c_str (), attr_value);
  }

  auto
  FileInfo::set_attribute_object (const std::string& attribute,
                                  const glib::RefPtr<Object>& attr_value) -> void
  {
    g_file_info_set_attribute_object (gobj (),
                                      attribute.c_str (),
                                      glib::unwrap (attr_value));
  }

  auto
  FileInfo::clear_status () -> void
  {
    g_file_info_clear_status (gobj ());
  }

  auto
  FileInfo::get_deletion_date () const -> glib::DateTime
  {
    return glib::wrap (
        g_file_info_get_deletion_date (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_file_type () const -> FileType
  {
    return static_cast<FileType> (
        g_file_info_get_file_type (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::is_hidden () const -> bool
  {
    return g_file_info_get_is_hidden (const_cast<GFileInfo*> (gobj ()));
  }

  auto
  FileInfo::is_backup () const -> bool
  {
    return g_file_info_get_is_backup (const_cast<GFileInfo*> (gobj ()));
  }

  auto
  FileInfo::is_symlink () const -> bool
  {
    return g_file_info_get_is_symlink (const_cast<GFileInfo*> (gobj ()));
  }

  auto
  FileInfo::get_name () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_file_info_get_name (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_display_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_file_info_get_display_name (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_edit_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_file_info_get_edit_name (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_file_info_get_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileInfo::get_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<FileInfo*> (this)->get_icon ();
  }

  auto
  FileInfo::get_symbolic_icon () -> glib::RefPtr<Icon>
  {
    auto retvalue = glib::wrap (g_file_info_get_symbolic_icon (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileInfo::get_symbolic_icon () const -> glib::RefPtr<const Icon>
  {
    return const_cast<FileInfo*> (this)->get_symbolic_icon ();
  }

  auto
  FileInfo::get_content_type () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_file_info_get_content_type (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_size () const -> goffset
  {
    return g_file_info_get_size (const_cast<GFileInfo*> (gobj ()));
  }

  auto
  FileInfo::get_modification_date_time () const -> glib::DateTime
  {
    return glib::wrap (g_file_info_get_modification_date_time (
        const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_access_date_time () const -> glib::DateTime
  {
    return glib::wrap (
        g_file_info_get_access_date_time (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_creation_date_time () const -> glib::DateTime
  {
    return glib::wrap (
        g_file_info_get_creation_date_time (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_symlink_target () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        g_file_info_get_symlink_target (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_etag () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_file_info_get_etag (const_cast<GFileInfo*> (gobj ())));
  }

  auto
  FileInfo::get_sort_order () const -> gint32
  {
    return g_file_info_get_sort_order (const_cast<GFileInfo*> (gobj ()));
  }

  auto
  FileInfo::set_attribute_mask (const glib::RefPtr<FileAttributeMatcher>& mask) -> void
  {
    g_file_info_set_attribute_mask (gobj (), glib::unwrap (mask));
  }

  auto
  FileInfo::unset_attribute_mask () -> void
  {
    g_file_info_unset_attribute_mask (gobj ());
  }

  auto
  FileInfo::set_file_type (FileType type) -> void
  {
    g_file_info_set_file_type (gobj (), static_cast<GFileType> (type));
  }

  auto
  FileInfo::set_is_hidden (const bool hidden) -> void
  {
    g_file_info_set_is_hidden (gobj (), hidden);
  }

  auto
  FileInfo::set_is_symlink (const bool symlink) -> void
  {
    g_file_info_set_is_symlink (gobj (), symlink);
  }

  auto
  FileInfo::set_name (const std::string& name) -> void
  {
    g_file_info_set_name (gobj (), name.c_str ());
  }

  auto
  FileInfo::set_display_name (const glib::ustring& display_name) -> void
  {
    g_file_info_set_display_name (gobj (), display_name.c_str ());
  }

  auto
  FileInfo::set_edit_name (const glib::ustring& edit_name) -> void
  {
    g_file_info_set_edit_name (gobj (), edit_name.c_str ());
  }

  auto
  FileInfo::set_icon (const glib::RefPtr<Icon>& icon) -> void
  {
    g_file_info_set_icon (gobj (), glib::unwrap (icon));
  }

  auto
  FileInfo::set_symbolic_icon (const glib::RefPtr<Icon>& icon) -> void
  {
    g_file_info_set_symbolic_icon (gobj (), glib::unwrap (icon));
  }

  auto
  FileInfo::set_content_type (const glib::ustring& content_type) -> void
  {
    g_file_info_set_content_type (gobj (), content_type.c_str ());
  }

  auto
  FileInfo::set_size (const goffset size) -> void
  {
    g_file_info_set_size (gobj (), size);
  }

  auto
  FileInfo::set_modification_date_time (const glib::DateTime& mtime) -> void
  {
    g_file_info_set_modification_date_time (
        gobj (),
        const_cast<GDateTime*> (mtime.gobj ()));
  }

  auto
  FileInfo::set_access_date_time (const glib::DateTime& atime) -> void
  {
    g_file_info_set_access_date_time (gobj (),
                                      const_cast<GDateTime*> (atime.gobj ()));
  }

  auto
  FileInfo::set_creation_date_time (const glib::DateTime& creation_time) -> void
  {
    g_file_info_set_creation_date_time (
        gobj (),
        const_cast<GDateTime*> (creation_time.gobj ()));
  }

  auto
  FileInfo::set_symlink_target (const std::string& symlink_target) -> void
  {
    g_file_info_set_symlink_target (gobj (), symlink_target.c_str ());
  }

  auto
  FileInfo::set_sort_order (const gint32 sort_order) -> void
  {
    g_file_info_set_sort_order (gobj (), sort_order);
  }

} // namespace gio
