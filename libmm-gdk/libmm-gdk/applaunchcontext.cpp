


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/applaunchcontext.hpp>
#include <libmm-gdk/applaunchcontext_p.hpp>


/* Copyright (C) 2012 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-gdk/display.hpp>
#include <gdk/gdk.h>

namespace Gdk
{

} //namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkAppLaunchContext* object, const bool take_copy) -> RefPtr<Gdk::AppLaunchContext>
{
  return Glib::make_refptr_for_instance<Gdk::AppLaunchContext>( dynamic_cast<Gdk::AppLaunchContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
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
    register_derived_type(gdk_app_launch_context_get_type());

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
  return new AppLaunchContext((GdkAppLaunchContext*)object);
}


/* The implementation: */

auto AppLaunchContext::gobj_copy() -> GdkAppLaunchContext*
{
  reference();
  return gobj();
}

AppLaunchContext::AppLaunchContext(const Glib::ConstructParams& construct_params)
:
  Gio::AppLaunchContext(construct_params)
{

}

AppLaunchContext::AppLaunchContext(GdkAppLaunchContext* castitem)
:
  Gio::AppLaunchContext((GAppLaunchContext*)castitem)
{}


AppLaunchContext::AppLaunchContext(AppLaunchContext&& src) noexcept
: Gio::AppLaunchContext(std::move(src))
{}

auto AppLaunchContext::operator=(AppLaunchContext&& src) noexcept -> AppLaunchContext&
{
  Gio::AppLaunchContext::operator=(std::move(src));
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
  return gdk_app_launch_context_get_type();
}


AppLaunchContext::AppLaunchContext()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Gio::AppLaunchContext(Glib::ConstructParams(applaunchcontext_class_.init()))
{


}

auto AppLaunchContext::create() -> Glib::RefPtr<AppLaunchContext>
{
  return Glib::make_refptr_for_instance<AppLaunchContext>( new AppLaunchContext() );
}

auto AppLaunchContext::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_app_launch_context_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto AppLaunchContext::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<AppLaunchContext*>(this)->get_display();
}

auto AppLaunchContext::set_desktop (
  const int desktop) -> void
{
  gdk_app_launch_context_set_desktop(gobj(), desktop);
}

auto AppLaunchContext::set_timestamp (
  const guint32 timestamp) -> void
{
  gdk_app_launch_context_set_timestamp(gobj(), timestamp);
}

auto AppLaunchContext::set_icon (const Glib::RefPtr <Gio::Icon> &icon) -> void
{
  gdk_app_launch_context_set_icon(gobj(), Glib::unwrap<Gio::Icon>(icon));
}

auto AppLaunchContext::set_icon_name (const Glib::ustring &icon_name) -> void
{
  gdk_app_launch_context_set_icon_name(gobj(), icon_name.c_str());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto AppLaunchContext::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "display"};
}


} // namespace Gdk


