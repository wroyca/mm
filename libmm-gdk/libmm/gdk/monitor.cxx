// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/monitor.hxx>
#include <libmm/gdk/monitor_p.hxx>

#include <libmm/gdk/display.hxx>

namespace
{

  static const Glib::SignalProxyInfo Monitor_signal_invalidate_info = {
      "invalidate",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

auto
Glib::Value<Gdk::SubpixelLayout>::value_type () -> GType
{
  return gdk_subpixel_layout_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkMonitor* object, bool take_copy) -> Glib::RefPtr<Gdk::Monitor>
  {
    return Glib::make_refptr_for_instance<Gdk::Monitor> (
        dynamic_cast<Gdk::Monitor*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Monitor_Class::init () -> const Glib::Class&
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
  Monitor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Monitor ((GdkMonitor*) object);
  }

  auto
  Monitor::gobj_copy () -> GdkMonitor*
  {
    reference ();
    return gobj ();
  }

  Monitor::Monitor (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Monitor::Monitor (GdkMonitor* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Monitor::Monitor (Monitor&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Monitor::operator= (Monitor&& src) noexcept -> Monitor&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (monitor_class_.init ()))
  {
  }

  auto
  Monitor::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_monitor_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Monitor::get_display () const -> Glib::RefPtr<const Display>
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
  Monitor::get_manufacturer () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_manufacturer (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::get_model () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_model (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::get_connector () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  Monitor::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_monitor_get_description (const_cast<GdkMonitor*> (gobj ())));
  }

  auto
  Monitor::signal_invalidate () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Monitor_signal_invalidate_info);
  }

  auto
  Monitor::property_description () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "description");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Monitor::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

  auto
  Monitor::property_manufacturer () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "manufacturer");
  }

  auto
  Monitor::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "model");
  }

  auto
  Monitor::property_connector () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "connector");
  }

  auto
  Monitor::property_scale_factor () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "scale-factor");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::Rectangle>::value,
      "Type Gdk::Rectangle cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Monitor::property_geometry () const -> Glib::PropertyProxy_ReadOnly<Gdk::Rectangle>
  {
    return Glib::PropertyProxy_ReadOnly<Gdk::Rectangle> (this, "geometry");
  }

  auto
  Monitor::property_width_mm () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "width-mm");
  }

  auto
  Monitor::property_height_mm () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "height-mm");
  }

  auto
  Monitor::property_refresh_rate () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "refresh-rate");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SubpixelLayout>::value,
      "Type SubpixelLayout cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Monitor::property_subpixel_layout () const -> Glib::PropertyProxy_ReadOnly<SubpixelLayout>
  {
    return Glib::PropertyProxy_ReadOnly<SubpixelLayout> (this,
                                                         "subpixel-layout");
  }

  auto
  Monitor::property_valid () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "valid");
  }

} // namespace Gdk