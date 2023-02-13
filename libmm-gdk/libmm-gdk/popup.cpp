


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/popup.hpp>
#include <mm/gdk/private/popup_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
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


namespace Glib
{

auto wrap(GdkPopup* object, const bool take_copy) -> RefPtr<Gdk::Popup>
{
  return Glib::make_refptr_for_instance<Gdk::Popup>( Glib::wrap_auto_interface<Gdk::Popup> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gdk
{


/* The *_Class implementation: */

auto Popup_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Popup_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gdk_popup_get_type();
  }

  return *this;
}

auto Popup_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Popup_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Popup((GdkPopup*)object);
}


/* The implementation: */

Popup::Popup()
: Interface(popup_class_.init())
{}

Popup::Popup(GdkPopup* castitem)
: Interface((GObject*)castitem)
{}

Popup::Popup(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Popup::Popup(Popup&& src) noexcept
: Interface(std::move(src))
{}

auto Popup::operator=(Popup&& src) noexcept -> Popup&
{
  Interface::operator=(std::move(src));
  return *this;
}

Popup::~Popup() noexcept = default;

// static
auto Popup::add_interface (
  const GType gtype_implementer) -> void
{
  popup_class_.init().add_interface(gtype_implementer);
}

Popup::CppClassType Popup::popup_class_; // initialize static member

auto Popup::get_type() -> GType
{
  return popup_class_.init().get_type();
}


auto Popup::get_base_type() -> GType
{
  return gdk_popup_get_type();
}


auto Popup::present(
  const int width, const int height, const Glib::RefPtr<PopupLayout>& layout) -> bool
{
  return gdk_popup_present(gobj(), width, height, Glib::unwrap(layout));
}

auto Popup::get_surface_anchor() const -> Gravity
{
  return static_cast<Gravity>(gdk_popup_get_surface_anchor(const_cast<GdkPopup*>(gobj())));
}

auto Popup::get_rect_anchor() const -> Gravity
{
  return static_cast<Gravity>(gdk_popup_get_rect_anchor(const_cast<GdkPopup*>(gobj())));
}

auto Popup::get_parent() -> Glib::RefPtr<Surface>
{
  auto retvalue = Glib::wrap(gdk_popup_get_parent(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Popup::get_parent() const -> Glib::RefPtr<const Surface>
{
  return const_cast<Popup*>(this)->get_parent();
}

auto Popup::get_position_x() const -> int
{
  return gdk_popup_get_position_x(const_cast<GdkPopup*>(gobj()));
}

auto Popup::get_position_y() const -> int
{
  return gdk_popup_get_position_y(const_cast<GdkPopup*>(gobj()));
}

auto Popup::get_autohide() const -> bool
{
  return gdk_popup_get_autohide(const_cast<GdkPopup*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Surface>>::value,
  "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Popup::property_parent() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >
{
  return {this, "parent"};
}

auto Popup::property_autohide() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "autohide"};
}


} // namespace Gdk


