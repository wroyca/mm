// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/devicepad.hxx>
#include <libmm-gdk/devicepad_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

auto
Glib::Value<Gdk::DevicePad::Feature>::value_type () -> GType
{
  return gdk_device_pad_feature_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkDevicePad* object, bool take_copy) -> Glib::RefPtr<Gdk::DevicePad>
  {
    return Glib::make_refptr_for_instance<Gdk::DevicePad> (
        dynamic_cast<Gdk::DevicePad*> (
            Glib::wrap_auto_interface<Gdk::DevicePad> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  DevicePad_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DevicePad_Class::iface_init_function;

      gtype_ = gdk_device_pad_get_type ();
    }

    return *this;
  }

  auto
  DevicePad_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  DevicePad_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DevicePad ((GdkDevicePad*) (object));
  }

  DevicePad::DevicePad ()
    : Glib::Interface (devicepad_class_.init ())
  {
  }

  DevicePad::DevicePad (GdkDevicePad* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  DevicePad::DevicePad (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  DevicePad::DevicePad (DevicePad&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  DevicePad::operator= (DevicePad&& src) noexcept -> DevicePad&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  DevicePad::~DevicePad () noexcept {}

  auto
  DevicePad::add_interface (GType gtype_implementer) -> void
  {
    devicepad_class_.init ().add_interface (gtype_implementer);
  }

  DevicePad::CppClassType DevicePad::devicepad_class_;

  auto
  DevicePad::get_type () -> GType
  {
    return devicepad_class_.init ().get_type ();
  }

  auto
  DevicePad::get_base_type () -> GType
  {
    return gdk_device_pad_get_type ();
  }

  auto
  DevicePad::get_n_groups () const -> int
  {
    return gdk_device_pad_get_n_groups (const_cast<GdkDevicePad*> (gobj ()));
  }

  auto
  DevicePad::get_group_n_modes (int group_idx) const -> int
  {
    return gdk_device_pad_get_group_n_modes (
        const_cast<GdkDevicePad*> (gobj ()),
        group_idx);
  }

  auto
  DevicePad::get_n_features (Feature feature) const -> int
  {
    return gdk_device_pad_get_n_features (
        const_cast<GdkDevicePad*> (gobj ()),
        static_cast<GdkDevicePadFeature> (feature));
  }

  auto
  DevicePad::get_feature_group (Feature feature, int feature_idx) const -> int
  {
    return gdk_device_pad_get_feature_group (
        const_cast<GdkDevicePad*> (gobj ()),
        static_cast<GdkDevicePadFeature> (feature),
        feature_idx);
  }

} // namespace Gdk
