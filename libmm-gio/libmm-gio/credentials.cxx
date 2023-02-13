


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/credentials.hpp>
#include <libmm-gio/credentials_p.hpp>


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

#include <gio/gio.h>
#include <libmm-glib/error.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GCredentials* object, const bool take_copy) -> RefPtr<Gio::Credentials>
{
  return Glib::make_refptr_for_instance<Gio::Credentials>( dynamic_cast<Gio::Credentials*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Credentials_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Credentials_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_credentials_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Credentials_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Credentials_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Credentials((GCredentials*)object);
}


/* The implementation: */

auto Credentials::gobj_copy() -> GCredentials*
{
  reference();
  return gobj();
}

Credentials::Credentials(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Credentials::Credentials(GCredentials* castitem)
: Object((GObject*)castitem)
{}


Credentials::Credentials(Credentials&& src) noexcept
: Object(std::move(src))
{}

auto Credentials::operator=(Credentials&& src) noexcept -> Credentials&
{
  Object::operator=(std::move(src));
  return *this;
}


Credentials::~Credentials() noexcept = default;

Credentials::CppClassType Credentials::credentials_class_; // initialize static member

auto Credentials::get_type() -> GType
{
  return credentials_class_.init().get_type();
}


auto Credentials::get_base_type() -> GType
{
  return g_credentials_get_type();
}


Credentials::Credentials()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(credentials_class_.init()))
{


}

auto Credentials::create() -> Glib::RefPtr<Credentials>
{
  return Glib::make_refptr_for_instance<Credentials>( new Credentials() );
}

auto Credentials::to_string() const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_credentials_to_string(const_cast<GCredentials*>(gobj())));
}

auto Credentials::get_native(Type native_type) -> gpointer
{
  return g_credentials_get_native(gobj(), static_cast<GCredentialsType>(native_type));
}

auto Credentials::set_native (Type native_type, const gpointer native) -> void
{
  g_credentials_set_native(gobj(), static_cast<GCredentialsType>(native_type), native);
}

auto Credentials::is_same_user(const Glib::RefPtr<const Credentials>& other_credentials) -> bool
{
  GError* gerror = nullptr;
  const auto retvalue = g_credentials_is_same_user(gobj(), const_cast<GCredentials*>(Glib::unwrap<Credentials>(other_credentials)), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

#ifdef G_OS_UNIX
auto Credentials::get_unix_user() -> uid_t
{
  GError* gerror = nullptr;
  auto retvalue = g_credentials_get_unix_user(gobj(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Credentials::set_unix_user(uid_t uid) -> bool
{
  GError* gerror = nullptr;
  auto retvalue = g_credentials_set_unix_user(gobj(), uid, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}
#endif // G_OS_UNIX

#ifdef G_OS_UNIX
auto Credentials::get_unix_pid() const -> pid_t
{
  GError* gerror = nullptr;
  auto retvalue = g_credentials_get_unix_pid(const_cast<GCredentials*>(gobj()), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}
#endif // G_OS_UNIX


} // namespace Gio


