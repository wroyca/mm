


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/appinfomonitor.hxx>
#include <libmm-gio/appinfomonitor_p.hxx>


/* Copyright (C) 2022 The giomm Development Team
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

} // namespace Gio

namespace
{


const Glib::SignalProxyInfo AppInfoMonitor_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GAppInfoMonitor* object, const bool take_copy) -> RefPtr<Gio::AppInfoMonitor>
{
  return Glib::make_refptr_for_instance<Gio::AppInfoMonitor>( dynamic_cast<Gio::AppInfoMonitor*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto AppInfoMonitor_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppInfoMonitor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_app_info_monitor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto AppInfoMonitor_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AppInfoMonitor_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AppInfoMonitor((GAppInfoMonitor*)object);
}


/* The implementation: */

auto AppInfoMonitor::gobj_copy() -> GAppInfoMonitor*
{
  reference();
  return gobj();
}

AppInfoMonitor::AppInfoMonitor(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

AppInfoMonitor::AppInfoMonitor(GAppInfoMonitor* castitem)
: Object((GObject*)castitem)
{}


AppInfoMonitor::AppInfoMonitor(AppInfoMonitor&& src) noexcept
: Object(std::move(src))
{}

auto AppInfoMonitor::operator=(AppInfoMonitor&& src) noexcept -> AppInfoMonitor&
{
  Object::operator=(std::move(src));
  return *this;
}


AppInfoMonitor::~AppInfoMonitor() noexcept = default;

AppInfoMonitor::CppClassType AppInfoMonitor::appinfomonitor_class_; // initialize static member

auto AppInfoMonitor::get_type() -> GType
{
  return appinfomonitor_class_.init().get_type();
}


auto AppInfoMonitor::get_base_type() -> GType
{
  return g_app_info_monitor_get_type();
}


auto AppInfoMonitor::get() -> Glib::RefPtr<AppInfoMonitor>
{
  return Glib::wrap(g_app_info_monitor_get());
}


auto AppInfoMonitor::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &AppInfoMonitor_signal_changed_info};
}


} // namespace Gio


