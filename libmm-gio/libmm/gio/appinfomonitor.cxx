// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/appinfomonitor.hxx>
#include <libmm/gio/appinfomonitor_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{

  const Glib::SignalProxyInfo AppInfoMonitor_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (GAppInfoMonitor* object, const bool take_copy) -> RefPtr<Gio::AppInfoMonitor>
  {
    return Glib::make_refptr_for_instance<Gio::AppInfoMonitor> (
        dynamic_cast<Gio::AppInfoMonitor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  AppInfoMonitor_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppInfoMonitor_Class::class_init_function;

      register_derived_type (g_app_info_monitor_get_type ());
    }

    return *this;
  }

  auto
  AppInfoMonitor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AppInfoMonitor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AppInfoMonitor ((GAppInfoMonitor*) object);
  }

  auto
  AppInfoMonitor::gobj_copy () -> GAppInfoMonitor*
  {
    reference ();
    return gobj ();
  }

  AppInfoMonitor::AppInfoMonitor (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  AppInfoMonitor::AppInfoMonitor (GAppInfoMonitor* castitem)
    : Object ((GObject*) castitem)
  {
  }

  AppInfoMonitor::AppInfoMonitor (AppInfoMonitor&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  AppInfoMonitor::operator= (AppInfoMonitor&& src) noexcept -> AppInfoMonitor&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  AppInfoMonitor::~AppInfoMonitor () noexcept = default;

  AppInfoMonitor::CppClassType AppInfoMonitor::appinfomonitor_class_;

  auto
  AppInfoMonitor::get_type () -> GType
  {
    return appinfomonitor_class_.init ().get_type ();
  }

  auto
  AppInfoMonitor::get_base_type () -> GType
  {
    return g_app_info_monitor_get_type ();
  }

  auto
  AppInfoMonitor::get () -> Glib::RefPtr<AppInfoMonitor>
  {
    return Glib::wrap (g_app_info_monitor_get ());
  }

  auto
  AppInfoMonitor::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return {this, &AppInfoMonitor_signal_changed_info};
  }

} // namespace Gio
