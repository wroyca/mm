// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/monitor.hxx>
#include <libmm/gdk/monitor_p.hxx>

#include <libmm/gdk/display.hxx>

namespace
{

  static const glib::SignalProxyInfo Monitor_signal_invalidate_info = {
      "invalidate",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

auto
glib::Value<gdk::SubpixelLayout>::value_type () -> GType
{
  return gdk_subpixel_layout_get_type ();
}

namespace glib
{

  auto
  wrap (GdkMonitor* object, bool take_copy) -> glib::RefPtr<gdk::Monitor>
  {
    return glib::make_refptr_for_instance<gdk::Monitor> (
        dynamic_cast<gdk::Monitor*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Monitor_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Monitor_Class::class_init_function;

      register_derived_type (gdk_monitor_get_type ());
    }

    return *this;
  }

  auto
  Monitor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Monitor_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Monitor ((GdkMonitor*) object);
  }

  auto
  Monitor::gobj_copy () -> GdkMonitor*
  {
    reference ();
    return gobj ();
  }

  Monitor::Monitor (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Monitor::Monitor (GdkMonitor* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Monitor::Monitor (Monitor&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Monitor::operator= (Monitor&& src) noexcept -> Monitor&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Monitor::~Monitor () noexcept {}

  Monitor::CppClassType Monitor::monitor_class_;

  auto
  Monitor::get_type () -> GType
  {
    return monitor_class_.init ().get_type ();
  }

  auto
  Monitor::get_base_type () -> GType
  {
    return gdk_monitor_get_type ();
  }

  Monitor::Monitor ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (monitor_class_.init ()))
  {
  }

  auto
  Monitor::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_monitor_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Monitor::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<Monitor*> (this)->get_display ();
  }

  auto
  Monitor::get_geometry (Rectangle& geometry) const -> void
  {
    gdk_monitor_get_geometry (const_cast<GdkMonitor*> (gobj ()),
                              (geometry).gobj ());
  }

  auto
  Monitor::get_width_mm () const -> int
  {
    return gdk_monitor_get_width_mm (const_cast<GdkMonitor*> (gobj ()));
  }

  auto
  Monitor::get_height_mm () const -> int
  {
    return gdk_monitor_get_height_mm (const_cast<GdkMonitor*> (gobj ()));
  }

  auto
  Monitor::get_manufacturer () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_manufacturer (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::get_model () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_model (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::get_connector () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_connector (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::get_scale_factor () const -> int
  {
    return gdk_monitor_get_scale_factor (const_cast<GdkMonitor*> (gobj ()));
  }

  auto
  Monitor::get_refresh_rate () const -> int
  {
    return gdk_monitor_get_refresh_rate (const_cast<GdkMonitor*> (gobj ()));
  }

  auto
  Monitor::get_subpixel_layout () const -> SubpixelLayout
  {
    return static_cast<SubpixelLayout> (
        gdk_monitor_get_subpixel_layout (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::is_valid () const -> bool
  {
    return gdk_monitor_is_valid (const_cast<GdkMonitor*> (gobj ()));
  }

  auto
  Monitor::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_description (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::signal_invalidate () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Monitor_signal_invalidate_info);
  }

  auto
  Monitor::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "description");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Monitor::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  auto
  Monitor::property_manufacturer () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "manufacturer");
  }

  auto
  Monitor::property_model () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "model");
  }

  auto
  Monitor::property_connector () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "connector");
  }

  auto
  Monitor::property_scale_factor () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "scale-factor");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gdk::Rectangle>::value,
      "Type gdk::Rectangle cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Monitor::property_geometry () const -> glib::PropertyProxy_ReadOnly<gdk::Rectangle>
  {
    return glib::PropertyProxy_ReadOnly<gdk::Rectangle> (this, "geometry");
  }

  auto
  Monitor::property_width_mm () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width-mm");
  }

  auto
  Monitor::property_height_mm () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "height-mm");
  }

  auto
  Monitor::property_refresh_rate () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "refresh-rate");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SubpixelLayout>::value,
      "Type SubpixelLayout cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Monitor::property_subpixel_layout () const -> glib::PropertyProxy_ReadOnly<SubpixelLayout>
  {
    return glib::PropertyProxy_ReadOnly<SubpixelLayout> (this,
                                                         "subpixel-layout");
  }

  auto
  Monitor::property_valid () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "valid");
  }

} // namespace gdk
