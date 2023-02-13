


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/applaunchcontext.hpp>
#include <mm/gio/private/applaunchcontext_p.hpp>


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

#include <mm/gio/appinfo.hpp>
#include <mm/gio/file.hpp>
#include <gio/gio.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GAppLaunchContext* object, const bool take_copy) -> RefPtr<Gio::AppLaunchContext>
{
  return Glib::make_refptr_for_instance<Gio::AppLaunchContext>( dynamic_cast<Gio::AppLaunchContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto AppLaunchContext_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppLaunchContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_app_launch_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto AppLaunchContext_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AppLaunchContext_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AppLaunchContext((GAppLaunchContext*)object);
}


/* The implementation: */

auto AppLaunchContext::gobj_copy() -> GAppLaunchContext*
{
  reference();
  return gobj();
}

AppLaunchContext::AppLaunchContext(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

AppLaunchContext::AppLaunchContext(GAppLaunchContext* castitem)
: Object((GObject*)castitem)
{}


AppLaunchContext::AppLaunchContext(AppLaunchContext&& src) noexcept
: Object(std::move(src))
{}

auto AppLaunchContext::operator=(AppLaunchContext&& src) noexcept -> AppLaunchContext&
{
  Object::operator=(std::move(src));
  return *this;
}


AppLaunchContext::~AppLaunchContext() noexcept = default;

AppLaunchContext::CppClassType AppLaunchContext::applaunchcontext_class_; // initialize static member

auto AppLaunchContext::get_type() -> GType
{
  return applaunchcontext_class_.init().get_type();
}


auto AppLaunchContext::get_base_type() -> GType
{
  return g_app_launch_context_get_type();
}


AppLaunchContext::AppLaunchContext()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(applaunchcontext_class_.init()))
{


}

auto AppLaunchContext::create() -> Glib::RefPtr<AppLaunchContext>
{
  return Glib::make_refptr_for_instance<AppLaunchContext>( new AppLaunchContext() );
}

auto AppLaunchContext::setenv (const Glib::ustring &variable, const Glib::ustring &value) -> void
{
  g_app_launch_context_setenv(gobj(), variable.c_str(), value.c_str());
}

auto AppLaunchContext::unsetenv (const Glib::ustring &variable) -> void
{
  g_app_launch_context_unsetenv(gobj(), variable.c_str());
}

auto AppLaunchContext::get_environment() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_app_launch_context_get_environment(const_cast<GAppLaunchContext*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto AppLaunchContext::get_display(const Glib::RefPtr<AppInfo>& info, const std::vector<Glib::RefPtr<File>>& files) -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_app_launch_context_get_display(gobj(), Glib::unwrap(info), Glib::ListHandler<Glib::RefPtr<File>>::vector_to_list(files).data()));
}

auto AppLaunchContext::get_startup_notify_id(const Glib::RefPtr<AppInfo>& info, const std::vector<Glib::RefPtr<File>>& files) -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_app_launch_context_get_startup_notify_id(gobj(), Glib::unwrap(info), Glib::ListHandler<Glib::RefPtr<File>>::vector_to_list(files).data()));
}

auto AppLaunchContext::launch_failed (const std::string &startup_notify_id) -> void
{
  g_app_launch_context_launch_failed(gobj(), startup_notify_id.c_str());
}


} // namespace Gio


