


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/dbusmethodinvocation_p.hxx>


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
#include <libmm-glib/error.hxx>
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusmessage.hxx>
#include <libmm-gio/dbusintrospection.hxx>

namespace Gio::DBus
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GDBusMethodInvocation* object, const bool take_copy) -> RefPtr<Gio::DBus::MethodInvocation>
{
  return Glib::make_refptr_for_instance<Gio::DBus::MethodInvocation>( dynamic_cast<Gio::DBus::MethodInvocation*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio::DBus
{


/* The *_Class implementation: */

auto MethodInvocation_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MethodInvocation_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_dbus_method_invocation_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MethodInvocation_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MethodInvocation_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MethodInvocation((GDBusMethodInvocation*)object);
}


/* The implementation: */

auto MethodInvocation::gobj_copy() -> GDBusMethodInvocation*
{
  reference();
  return gobj();
}

MethodInvocation::MethodInvocation(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MethodInvocation::MethodInvocation(GDBusMethodInvocation* castitem)
: Object((GObject*)castitem)
{}


MethodInvocation::MethodInvocation(MethodInvocation&& src) noexcept
: Object(std::move(src))
{}

auto MethodInvocation::operator=(MethodInvocation&& src) noexcept -> MethodInvocation&
{
  Object::operator=(std::move(src));
  return *this;
}


MethodInvocation::~MethodInvocation() noexcept = default;

MethodInvocation::CppClassType MethodInvocation::methodinvocation_class_; // initialize static member

auto MethodInvocation::get_type() -> GType
{
  return methodinvocation_class_.init().get_type();
}


auto MethodInvocation::get_base_type() -> GType
{
  return g_dbus_method_invocation_get_type();
}


auto MethodInvocation::get_sender() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_method_invocation_get_sender(const_cast<GDBusMethodInvocation*>(gobj())));
}

auto MethodInvocation::get_object_path() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_method_invocation_get_object_path(const_cast<GDBusMethodInvocation*>(gobj())));
}

auto MethodInvocation::get_interface_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_method_invocation_get_interface_name(const_cast<GDBusMethodInvocation*>(gobj())));
}

auto MethodInvocation::get_method_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_method_invocation_get_method_name(const_cast<GDBusMethodInvocation*>(gobj())));
}

auto MethodInvocation::get_method_info() const -> Glib::RefPtr<const MethodInfo>
{
  auto retvalue = Glib::wrap(const_cast<GDBusMethodInfo*>(g_dbus_method_invocation_get_method_info(const_cast<GDBusMethodInvocation*>(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MethodInvocation::get_connection() -> Glib::RefPtr<Connection>
{
  auto retvalue = Glib::wrap(g_dbus_method_invocation_get_connection(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MethodInvocation::get_connection() const -> Glib::RefPtr<const Connection>
{
  return const_cast<MethodInvocation*>(this)->get_connection();
}

auto MethodInvocation::get_message() -> Glib::RefPtr<Message>
{
  auto retvalue = Glib::wrap(g_dbus_method_invocation_get_message(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MethodInvocation::get_message() const -> Glib::RefPtr<const Message>
{
  return const_cast<MethodInvocation*>(this)->get_message();
}

auto MethodInvocation::get_parameters() const -> Glib::VariantContainerBase
{
  return Glib::VariantContainerBase(g_dbus_method_invocation_get_parameters(const_cast<GDBusMethodInvocation*>(gobj())), false);
}

auto MethodInvocation::return_value (const Glib::VariantContainerBase &parameters) -> void
{
  g_dbus_method_invocation_return_value(gobj(), const_cast<GVariant*>(parameters.gobj()));
}

#ifdef G_OS_UNIX
void MethodInvocation::return_value(const Glib::VariantContainerBase& parameters, const Glib::RefPtr<UnixFDList>& fd_list)
{
  g_dbus_method_invocation_return_value_with_unix_fd_list(gobj(), const_cast<GVariant*>((parameters).gobj()), Glib::unwrap(fd_list));
}
#endif // G_OS_UNIX

auto MethodInvocation::return_error (
  const Glib::ustring &domain, const int code, const Glib::ustring &message) -> void
{
  g_dbus_method_invocation_return_error_literal(gobj(), Glib::QueryQuark(domain).id(), code, message.c_str());
}

auto MethodInvocation::return_error (const Glib::Error &error) -> void
{
  g_dbus_method_invocation_return_gerror(gobj(), error.gobj());
}

auto MethodInvocation::return_dbus_error (
  const Glib::ustring &error_name, const Glib::ustring &error_message) -> void
{
  g_dbus_method_invocation_return_dbus_error(gobj(), error_name.c_str(), error_message.c_str());
}


} // namespace Gio


