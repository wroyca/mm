


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/fileinfo_p.hxx>


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

// FileAttributeMatcher

auto
FileAttributeMatcher::create(const std::string& attributes) -> Glib::RefPtr<FileAttributeMatcher>
{
  return Glib::wrap(g_file_attribute_matcher_new(attributes.c_str()));
}

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<FileAttributeMatcher*>(gobject) is needed:
 *
 * A FileAttributeMatcher instance is in fact always a GFileAttributeMatcher instance.
 * Unfortunately, GFileAttributeMatcher cannot be a member of FileAttributeMatcher,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because FileAttributeMatcher does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GFileAttributeMatcher* object, const bool take_copy) -> RefPtr<Gio::FileAttributeMatcher>
{
  if(take_copy && object)
    g_file_attribute_matcher_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::FileAttributeMatcher>(reinterpret_cast<Gio::FileAttributeMatcher*>(object));
}

} // namespace Glib


namespace Gio
{

auto FileAttributeMatcher::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_file_attribute_matcher_ref(reinterpret_cast<GFileAttributeMatcher*>(const_cast<FileAttributeMatcher*>(this)));
}

auto FileAttributeMatcher::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_file_attribute_matcher_unref(reinterpret_cast<GFileAttributeMatcher*>(const_cast<FileAttributeMatcher*>(this)));
}

auto FileAttributeMatcher::gobj() -> GFileAttributeMatcher*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GFileAttributeMatcher*>(this);
}

auto FileAttributeMatcher::gobj() const -> const GFileAttributeMatcher*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GFileAttributeMatcher*>(this);
}

auto FileAttributeMatcher::gobj_copy() const -> GFileAttributeMatcher*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GFileAttributeMatcher*>(const_cast<FileAttributeMatcher*>(this));
  g_file_attribute_matcher_ref(gobject);
  return gobject;
}


auto FileAttributeMatcher::create_difference(const Glib::RefPtr<const FileAttributeMatcher>& subtract) const -> Glib::RefPtr<FileAttributeMatcher>
{
  return Glib::wrap(g_file_attribute_matcher_subtract(const_cast<GFileAttributeMatcher*>(gobj()), const_cast<GFileAttributeMatcher*>(Glib::unwrap(subtract))));
}

auto FileAttributeMatcher::matches(const std::string& attribute) const -> bool
{
  return g_file_attribute_matcher_matches(const_cast<GFileAttributeMatcher*>(gobj()), attribute.c_str());
}

auto FileAttributeMatcher::matches_only(const std::string& attribute) const -> bool
{
  return g_file_attribute_matcher_matches_only(const_cast<GFileAttributeMatcher*>(gobj()), attribute.c_str());
}

auto FileAttributeMatcher::enumerate_namespace(const std::string& ns) -> bool
{
  return g_file_attribute_matcher_enumerate_namespace(gobj(), ns.c_str());
}

auto FileAttributeMatcher::enumerate_next() -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_file_attribute_matcher_enumerate_next(gobj()));
}

auto FileAttributeMatcher::to_string() const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_file_attribute_matcher_to_string(const_cast<GFileAttributeMatcher*>(gobj())));
}


} // namespace Gio


namespace Glib
{

auto wrap(GFileInfo* object, const bool take_copy) -> RefPtr<Gio::FileInfo>
{
  return Glib::make_refptr_for_instance<Gio::FileInfo>( dynamic_cast<Gio::FileInfo*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FileInfo_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileInfo_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_info_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FileInfo_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileInfo_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileInfo((GFileInfo*)object);
}


/* The implementation: */

auto FileInfo::gobj_copy() -> GFileInfo*
{
  reference();
  return gobj();
}

FileInfo::FileInfo(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FileInfo::FileInfo(GFileInfo* castitem)
: Object((GObject*)castitem)
{}


FileInfo::FileInfo(FileInfo&& src) noexcept
: Object(std::move(src))
{}

auto FileInfo::operator=(FileInfo&& src) noexcept -> FileInfo&
{
  Object::operator=(std::move(src));
  return *this;
}


FileInfo::~FileInfo() noexcept = default;

FileInfo::CppClassType FileInfo::fileinfo_class_; // initialize static member

auto FileInfo::get_type() -> GType
{
  return fileinfo_class_.init().get_type();
}


auto FileInfo::get_base_type() -> GType
{
  return g_file_info_get_type();
}

FileInfo::FileInfo()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(fileinfo_class_.init()))
{


}

auto FileInfo::dup() const -> Glib::RefPtr<FileInfo>
{
  return Glib::wrap(g_file_info_dup(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::copy_into (Glib::RefPtr <FileInfo> &dest_info) const -> void
{
  g_file_info_copy_into(const_cast<GFileInfo*>(gobj()), Glib::unwrap(dest_info));
}

auto FileInfo::has_attribute(const std::string& attribute) const -> bool
{
  return g_file_info_has_attribute(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::has_namespace(const std::string& name_space) const -> bool
{
  return g_file_info_has_namespace(const_cast<GFileInfo*>(gobj()), name_space.c_str());
}

auto FileInfo::list_attributes(const std::string& name_space) const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_file_info_list_attributes(const_cast<GFileInfo*>(gobj()), name_space.empty() ? nullptr : name_space.c_str()), Glib::OWNERSHIP_DEEP);
}

auto FileInfo::list_attributes() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_file_info_list_attributes(const_cast<GFileInfo*>(gobj()), nullptr), Glib::OWNERSHIP_DEEP);
}

auto FileInfo::get_attribute_type(const std::string& attribute) const -> FileAttributeType
{
  return static_cast<FileAttributeType>(g_file_info_get_attribute_type(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::remove_attribute (const std::string &attribute) -> void
{
  g_file_info_remove_attribute(gobj(), attribute.c_str());
}

auto FileInfo::get_attribute_status(const std::string& attribute) const -> FileAttributeStatus
{
  return static_cast<FileAttributeStatus>(g_file_info_get_attribute_status(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::get_attribute_string(const std::string& attribute) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_file_info_get_attribute_string(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::get_attribute_strings(const std::string& attribute) const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_file_info_get_attribute_stringv(const_cast<GFileInfo*>(gobj()), attribute.c_str()), Glib::OWNERSHIP_NONE);
}

auto FileInfo::get_attribute_as_string(const std::string& attribute) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_file_info_get_attribute_as_string(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::get_attribute_byte_string(const std::string& attribute) const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_file_info_get_attribute_byte_string(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::get_attribute_boolean(const std::string& attribute) const -> bool
{
  return g_file_info_get_attribute_boolean(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::get_attribute_uint32(const std::string& attribute) const -> guint32
{
  return g_file_info_get_attribute_uint32(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::get_attribute_int32(const std::string& attribute) const -> gint32
{
  return g_file_info_get_attribute_int32(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::get_attribute_uint64(const std::string& attribute) const -> guint64
{
  return g_file_info_get_attribute_uint64(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::get_attribute_int64(const std::string& attribute) const -> gint64
{
  return g_file_info_get_attribute_int64(const_cast<GFileInfo*>(gobj()), attribute.c_str());
}

auto FileInfo::get_attribute_object(const std::string& attribute) const -> Glib::RefPtr<Object>
{
  return Glib::wrap(g_file_info_get_attribute_object(const_cast<GFileInfo*>(gobj()), attribute.c_str()));
}

auto FileInfo::set_attribute_status(const std::string& attribute, FileAttributeStatus status) -> bool
{
  return g_file_info_set_attribute_status(gobj(), attribute.c_str(), static_cast<GFileAttributeStatus>(status));
}

auto FileInfo::set_attribute_string (
  const std::string &attribute, const Glib::ustring &attr_value) -> void
{
  g_file_info_set_attribute_string(gobj(), attribute.c_str(), attr_value.c_str());
}

auto FileInfo::set_attribute_strings (
  const std::string &attribute, const std::vector <Glib::ustring> &attr_value) -> void
{
  g_file_info_set_attribute_stringv(gobj(), attribute.c_str(), const_cast<char**>(Glib::ArrayHandler<Glib::ustring>::vector_to_array(attr_value).data()));
}

auto FileInfo::set_attribute_byte_string (
  const std::string &attribute, const std::string &attr_value) -> void
{
  g_file_info_set_attribute_byte_string(gobj(), attribute.c_str(), attr_value.c_str());
}

auto FileInfo::set_attribute_boolean (const std::string &attribute, const bool attr_value) -> void
{
  g_file_info_set_attribute_boolean(gobj(), attribute.c_str(), attr_value);
}

auto FileInfo::set_attribute_uint32 (const std::string &attribute, const guint32 attr_value) -> void
{
  g_file_info_set_attribute_uint32(gobj(), attribute.c_str(), attr_value);
}

auto FileInfo::set_attribute_int32 (const std::string &attribute, const gint32 attr_value) -> void
{
  g_file_info_set_attribute_int32(gobj(), attribute.c_str(), attr_value);
}

auto FileInfo::set_attribute_uint64 (const std::string &attribute, const guint64 attr_value) -> void
{
  g_file_info_set_attribute_uint64(gobj(), attribute.c_str(), attr_value);
}

auto FileInfo::set_attribute_int64 (const std::string &attribute, const gint64 attr_value) -> void
{
  g_file_info_set_attribute_int64(gobj(), attribute.c_str(), attr_value);
}

auto FileInfo::set_attribute_object (
  const std::string &attribute, const Glib::RefPtr <Object> &attr_value) -> void
{
  g_file_info_set_attribute_object(gobj(), attribute.c_str(), Glib::unwrap(attr_value));
}

auto FileInfo::clear_status () -> void
{
  g_file_info_clear_status(gobj());
}

auto FileInfo::get_deletion_date() const -> Glib::DateTime
{
  return Glib::wrap(g_file_info_get_deletion_date(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_file_type() const -> FileType
{
  return static_cast<FileType>(g_file_info_get_file_type(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::is_hidden() const -> bool
{
  return g_file_info_get_is_hidden(const_cast<GFileInfo*>(gobj()));
}

auto FileInfo::is_backup() const -> bool
{
  return g_file_info_get_is_backup(const_cast<GFileInfo*>(gobj()));
}

auto FileInfo::is_symlink() const -> bool
{
  return g_file_info_get_is_symlink(const_cast<GFileInfo*>(gobj()));
}

auto FileInfo::get_name() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_file_info_get_name(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_display_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_file_info_get_display_name(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_edit_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_file_info_get_edit_name(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_icon() -> Glib::RefPtr<Icon>
{
  auto retvalue = Glib::wrap(g_file_info_get_icon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FileInfo::get_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<FileInfo*>(this)->get_icon();
}

auto FileInfo::get_symbolic_icon() -> Glib::RefPtr<Icon>
{
  auto retvalue = Glib::wrap(g_file_info_get_symbolic_icon(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FileInfo::get_symbolic_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<FileInfo*>(this)->get_symbolic_icon();
}

auto FileInfo::get_content_type() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_file_info_get_content_type(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_size() const -> goffset
{
  return g_file_info_get_size(const_cast<GFileInfo*>(gobj()));
}

auto FileInfo::get_modification_date_time() const -> Glib::DateTime
{
  return Glib::wrap(g_file_info_get_modification_date_time(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_access_date_time() const -> Glib::DateTime
{
  return Glib::wrap(g_file_info_get_access_date_time(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_creation_date_time() const -> Glib::DateTime
{
  return Glib::wrap(g_file_info_get_creation_date_time(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_symlink_target() const -> std::string
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_file_info_get_symlink_target(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_etag() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_file_info_get_etag(const_cast<GFileInfo*>(gobj())));
}

auto FileInfo::get_sort_order() const -> gint32
{
  return g_file_info_get_sort_order(const_cast<GFileInfo*>(gobj()));
}

auto FileInfo::set_attribute_mask (const Glib::RefPtr <FileAttributeMatcher> &mask) -> void
{
  g_file_info_set_attribute_mask(gobj(), Glib::unwrap(mask));
}

auto FileInfo::unset_attribute_mask () -> void
{
  g_file_info_unset_attribute_mask(gobj());
}

auto FileInfo::set_file_type (FileType type) -> void
{
  g_file_info_set_file_type(gobj(), static_cast<GFileType>(type));
}

auto FileInfo::set_is_hidden (
  const bool hidden) -> void
{
  g_file_info_set_is_hidden(gobj(), hidden);
}

auto FileInfo::set_is_symlink (
  const bool symlink) -> void
{
  g_file_info_set_is_symlink(gobj(), symlink);
}

auto FileInfo::set_name (const std::string &name) -> void
{
  g_file_info_set_name(gobj(), name.c_str());
}

auto FileInfo::set_display_name (const Glib::ustring &display_name) -> void
{
  g_file_info_set_display_name(gobj(), display_name.c_str());
}

auto FileInfo::set_edit_name (const Glib::ustring &edit_name) -> void
{
  g_file_info_set_edit_name(gobj(), edit_name.c_str());
}

auto FileInfo::set_icon (const Glib::RefPtr <Icon> &icon) -> void
{
  g_file_info_set_icon(gobj(), Glib::unwrap(icon));
}

auto FileInfo::set_symbolic_icon (const Glib::RefPtr <Icon> &icon) -> void
{
  g_file_info_set_symbolic_icon(gobj(), Glib::unwrap(icon));
}

auto FileInfo::set_content_type (const Glib::ustring &content_type) -> void
{
  g_file_info_set_content_type(gobj(), content_type.c_str());
}

auto FileInfo::set_size (
  const goffset size) -> void
{
  g_file_info_set_size(gobj(), size);
}

auto FileInfo::set_modification_date_time (const Glib::DateTime &mtime) -> void
{
  g_file_info_set_modification_date_time(gobj(), const_cast<GDateTime*>(mtime.gobj()));
}

auto FileInfo::set_access_date_time (const Glib::DateTime &atime) -> void
{
  g_file_info_set_access_date_time(gobj(), const_cast<GDateTime*>(atime.gobj()));
}

auto FileInfo::set_creation_date_time (const Glib::DateTime &creation_time) -> void
{
  g_file_info_set_creation_date_time(gobj(), const_cast<GDateTime*>(creation_time.gobj()));
}

auto FileInfo::set_symlink_target (const std::string &symlink_target) -> void
{
  g_file_info_set_symlink_target(gobj(), symlink_target.c_str());
}

auto FileInfo::set_sort_order (
  const gint32 sort_order) -> void
{
  g_file_info_set_sort_order(gobj(), sort_order);
}


} // namespace Gio


