


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/devicepad.hpp>
#include <libmm-gdk/devicepad_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gdk/gdk.h>

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gdk::DevicePad::Feature>::value_type() -> GType
{
  return gdk_device_pad_feature_get_type();
}


namespace Glib
{

auto wrap(GdkDevicePad* object, const bool take_copy) -> RefPtr<Gdk::DevicePad>
{
  return Glib::make_refptr_for_instance<Gdk::DevicePad>( Glib::wrap_auto_interface<Gdk::DevicePad> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gdk
{


/* The *_Class implementation: */

auto DevicePad_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &DevicePad_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gdk_device_pad_get_type();
  }

  return *this;
}

auto DevicePad_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto DevicePad_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DevicePad((GdkDevicePad*)object);
}


/* The implementation: */

DevicePad::DevicePad()
: Interface(devicepad_class_.init())
{}

DevicePad::DevicePad(GdkDevicePad* castitem)
: Interface((GObject*)castitem)
{}

DevicePad::DevicePad(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

DevicePad::DevicePad(DevicePad&& src) noexcept
: Interface(std::move(src))
{}

auto DevicePad::operator=(DevicePad&& src) noexcept -> DevicePad&
{
  Interface::operator=(std::move(src));
  return *this;
}

DevicePad::~DevicePad() noexcept = default;

// static
auto DevicePad::add_interface (
  const GType gtype_implementer) -> void
{
  devicepad_class_.init().add_interface(gtype_implementer);
}

DevicePad::CppClassType DevicePad::devicepad_class_; // initialize static member

auto DevicePad::get_type() -> GType
{
  return devicepad_class_.init().get_type();
}


auto DevicePad::get_base_type() -> GType
{
  return gdk_device_pad_get_type();
}


auto DevicePad::get_n_groups() const -> int
{
  return gdk_device_pad_get_n_groups(const_cast<GdkDevicePad*>(gobj()));
}

auto DevicePad::get_group_n_modes(
  const int group_idx) const -> int
{
  return gdk_device_pad_get_group_n_modes(const_cast<GdkDevicePad*>(gobj()), group_idx);
}

auto DevicePad::get_n_features(Feature feature) const -> int
{
  return gdk_device_pad_get_n_features(const_cast<GdkDevicePad*>(gobj()), static_cast<GdkDevicePadFeature>(feature));
}

auto DevicePad::get_feature_group(Feature feature, const int feature_idx) const -> int
{
  return gdk_device_pad_get_feature_group(const_cast<GdkDevicePad*>(gobj()), static_cast<GdkDevicePadFeature>(feature), feature_idx);
}


} // namespace Gdk


