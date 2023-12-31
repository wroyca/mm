// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/devicepad.hxx>
#include <libmm/gdk/devicepad_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

auto
glib::Value<gdk::DevicePad::Feature>::value_type () -> GType
{
  return gdk_device_pad_feature_get_type ();
}

namespace glib
{

  auto
  wrap (GdkDevicePad* object, bool take_copy) -> glib::RefPtr<gdk::DevicePad>
  {
    return glib::make_refptr_for_instance<gdk::DevicePad> (
        dynamic_cast<gdk::DevicePad*> (
            glib::wrap_auto_interface<gdk::DevicePad> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  DevicePad_Class::init () -> const glib::Interface_Class&
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
  DevicePad_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DevicePad ((GdkDevicePad*) (object));
  }

  DevicePad::DevicePad ()
    : glib::Interface (devicepad_class_.init ())
  {
  }

  DevicePad::DevicePad (GdkDevicePad* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  DevicePad::DevicePad (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  DevicePad::DevicePad (DevicePad&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  DevicePad::operator= (DevicePad&& src) noexcept -> DevicePad&
  {
    glib::Interface::operator= (std::move (src));
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

} // namespace gdk
