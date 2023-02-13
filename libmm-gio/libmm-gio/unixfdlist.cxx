


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/unixfdlist.hxx>
#include <libmm-gio/unixfdlist_p.hxx>


/* Copyright (C) 2010 The giomm Development Team
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

#include <gio/gunixfdlist.h>
#include <libmm-glib/error.hxx>

namespace Gio
{

UnixFDList::UnixFDList(const std::vector<int>&  fds)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  // g_unix_fd_list_new_from_array() must be called.
  // Its parameters don't correspond to properties.
  // __CONSTRUCT() + g_unit_fd_list_append() is not an alternative.
  // g_unit_fd_list_append() duplicates the file descriptor,
  // but g_unix_fd_list_new_from_array() does not.
Object((GObject*)g_unix_fd_list_new_from_array(Glib::ArrayHandler<int>::vector_to_array(fds).data(), fds.size()))
{
}

UnixFDList::UnixFDList(const std::vector<int>&  fds, const int n_fds)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  // g_unix_fd_list_new_from_array() must be called.
  // Its parameters don't correspond to properties.
  // __CONSTRUCT() + g_unit_fd_list_append() is not an alternative.
  // g_unit_fd_list_append() duplicates the file descriptor,
  // but g_unix_fd_list_new_from_array() does not.
Object((GObject*)g_unix_fd_list_new_from_array(Glib::ArrayHandler<int>::vector_to_array(fds).data(), n_fds))
{
}

auto
UnixFDList::peek_fds() const -> const std::vector<int>
{
  int length = 0;
  const auto fds = g_unix_fd_list_peek_fds(const_cast<GUnixFDList*>(gobj()), &length);
  // The array is terminated with a -1, but that terminating element is
  // not included in the length that g_unix_fd_list_peek_fds() returns.
  return Glib::ArrayHandler<int>::array_to_vector(fds, length, Glib::OWNERSHIP_NONE);
}

auto
UnixFDList::steal_fds() -> std::vector<int>
{
  int length = 0;
  const auto fds = g_unix_fd_list_steal_fds(gobj(), &length);
  // The array is terminated with a -1, but that terminating element is
  // not included in the length that g_unix_fd_list_steal_fds() returns.
  return Glib::ArrayHandler<int>::array_to_vector(fds, length, Glib::OWNERSHIP_DEEP);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GUnixFDList* object, const bool take_copy) -> RefPtr<Gio::UnixFDList>
{
  return Glib::make_refptr_for_instance<Gio::UnixFDList>( dynamic_cast<Gio::UnixFDList*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto UnixFDList_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &UnixFDList_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_unix_fd_list_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto UnixFDList_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto UnixFDList_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new UnixFDList((GUnixFDList*)object);
}


/* The implementation: */

auto UnixFDList::gobj_copy() -> GUnixFDList*
{
  reference();
  return gobj();
}

UnixFDList::UnixFDList(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

UnixFDList::UnixFDList(GUnixFDList* castitem)
: Object((GObject*)castitem)
{}


UnixFDList::UnixFDList(UnixFDList&& src) noexcept
: Object(std::move(src))
{}

auto UnixFDList::operator=(UnixFDList&& src) noexcept -> UnixFDList&
{
  Object::operator=(std::move(src));
  return *this;
}


UnixFDList::~UnixFDList() noexcept = default;

UnixFDList::CppClassType UnixFDList::unixfdlist_class_; // initialize static member

auto UnixFDList::get_type() -> GType
{
  return unixfdlist_class_.init().get_type();
}


auto UnixFDList::get_base_type() -> GType
{
  return g_unix_fd_list_get_type();
}


UnixFDList::UnixFDList()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(unixfdlist_class_.init()))
{


}

auto UnixFDList::create() -> Glib::RefPtr<UnixFDList>
{
  return Glib::make_refptr_for_instance<UnixFDList>( new UnixFDList() );
}

auto UnixFDList::create(const std::vector<int>& fds) -> Glib::RefPtr<UnixFDList>
{
  return Glib::make_refptr_for_instance<UnixFDList>( new UnixFDList(fds) );
}

auto UnixFDList::create(const std::vector<int>& fds, const int n_fds) -> Glib::RefPtr<UnixFDList>
{
  return Glib::make_refptr_for_instance<UnixFDList>( new UnixFDList(fds, n_fds) );
}

auto UnixFDList::get_length() const -> int
{
  return g_unix_fd_list_get_length(const_cast<GUnixFDList*>(gobj()));
}

auto UnixFDList::get(
  const int index) const -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_fd_list_get(const_cast<GUnixFDList*>(gobj()), index, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto UnixFDList::append(
  const int fd) -> int
{
  GError* gerror = nullptr;
  const auto retvalue = g_unix_fd_list_append(gobj(), fd, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


