


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/drop.hpp>
#include <mm/gdk/private/drop_p.hpp>


/* Copyright (C) 2018 The gtkmm Development Team
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

#include <mm/gio/cancellable.hpp>
#include <mm/gio/inputstream.hpp>
#include <mm/gio/slot_async.hpp>
#include <mm/gdk/contentformats.hpp>
#include <mm/gdk/device.hpp>
#include <mm/gdk/display.hpp>
#include <mm/gdk/drag.hpp>
#include <mm/gdk/surface.hpp>
#include <gdk/gdk.h>

namespace Gdk
{

auto Drop::refuse () -> void
{
  // see GDK docs
  gdk_drop_status(gobj(), static_cast<GdkDragAction>(0), static_cast<GdkDragAction>(0));
}

auto Drop::failed () -> void
{
  gdk_drop_finish(gobj(), static_cast<GdkDragAction>(0) /* see GDK docs */);
}

auto Drop::read_value_finish(const Glib::RefPtr<Gio::AsyncResult>& result) -> Glib::ValueBase
{
  GError* gerror = nullptr;
  const GValue* gvalue = gdk_drop_read_value_finish(gobj(), Glib::unwrap(result), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  Glib::ValueBase retvalue;
  retvalue.init(gvalue);
  return retvalue;
}

} // namespace Gdk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkDrop* object, const bool take_copy) -> RefPtr<Gdk::Drop>
{
  return Glib::make_refptr_for_instance<Gdk::Drop>( dynamic_cast<Gdk::Drop*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Drop_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Drop_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_drop_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Drop_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Drop_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Drop((GdkDrop*)object);
}


/* The implementation: */

auto Drop::gobj_copy() -> GdkDrop*
{
  reference();
  return gobj();
}

Drop::Drop(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Drop::Drop(GdkDrop* castitem)
: Object((GObject*)castitem)
{}


Drop::Drop(Drop&& src) noexcept
: Object(std::move(src))
{}

auto Drop::operator=(Drop&& src) noexcept -> Drop&
{
  Object::operator=(std::move(src));
  return *this;
}


Drop::~Drop() noexcept = default;

Drop::CppClassType Drop::drop_class_; // initialize static member

auto Drop::get_type() -> GType
{
  return drop_class_.init().get_type();
}


auto Drop::get_base_type() -> GType
{
  return gdk_drop_get_type();
}


auto Drop::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_drop_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drop::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<Drop*>(this)->get_display();
}

auto Drop::get_device() -> Glib::RefPtr<Device>
{
  auto retvalue = Glib::wrap(gdk_drop_get_device(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drop::get_device() const -> Glib::RefPtr<const Device>
{
  return const_cast<Drop*>(this)->get_device();
}

auto Drop::get_surface() -> Glib::RefPtr<Surface>
{
  auto retvalue = Glib::wrap(gdk_drop_get_surface(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drop::get_surface() const -> Glib::RefPtr<const Surface>
{
  return const_cast<Drop*>(this)->get_surface();
}

auto Drop::get_formats() -> Glib::RefPtr<ContentFormats>
{
  auto retvalue = Glib::wrap(gdk_drop_get_formats(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drop::get_formats() const -> Glib::RefPtr<const ContentFormats>
{
  return const_cast<Drop*>(this)->get_formats();
}

auto Drop::get_actions() const -> DragAction
{
  return static_cast<DragAction>(gdk_drop_get_actions(const_cast<GdkDrop*>(gobj())));
}

auto Drop::get_drag() -> Glib::RefPtr<Drag>
{
  auto retvalue = Glib::wrap(gdk_drop_get_drag(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Drop::get_drag() const -> Glib::RefPtr<const Drag>
{
  return const_cast<Drop*>(this)->get_drag();
}

auto Drop::status (DragAction actions, DragAction preferred) -> void
{
  gdk_drop_status(gobj(), static_cast<GdkDragAction>(actions), static_cast<GdkDragAction>(preferred));
}

auto Drop::finish (DragAction action) -> void
{
  gdk_drop_finish(gobj(), static_cast<GdkDragAction>(action));
}

auto Drop::read_async (
  const std::vector <Glib::ustring> &mime_types, const int io_priority, const Gio::SlotAsyncReady &slot,
  const Glib::RefPtr <Gio::Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new Gio::SlotAsyncReady(slot);

  gdk_drop_read_async(gobj(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(mime_types).data(), io_priority, Glib::unwrap(cancellable), &Gio::SignalProxy_async_callback, slot_copy);
}

auto Drop::read_async (
  const std::vector <Glib::ustring> &mime_types, const int io_priority,
  const Gio::SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new Gio::SlotAsyncReady(slot);

  gdk_drop_read_async(gobj(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(mime_types).data(), io_priority, nullptr, &Gio::SignalProxy_async_callback, slot_copy);
}

auto Drop::read_finish(const Glib::RefPtr<Gio::AsyncResult>& result, Glib::ustring& out_mime_type) -> Glib::RefPtr<Gio::InputStream>
{
  GError* gerror = nullptr;
  const char* g_out_mime_type = nullptr;
  auto retvalue = Glib::wrap(gdk_drop_read_finish(gobj(), Glib::unwrap(result), &g_out_mime_type, &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
out_mime_type = Glib::convert_const_gchar_ptr_to_ustring(g_out_mime_type);
  return retvalue;
}

auto Drop::read_value_async (
  const GType type, const int io_priority, const Gio::SlotAsyncReady &slot,
  const Glib::RefPtr <Gio::Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new Gio::SlotAsyncReady(slot);

  gdk_drop_read_value_async(gobj(), type, io_priority, Glib::unwrap(cancellable), &Gio::SignalProxy_async_callback, slot_copy);
}

auto Drop::read_value_async (
  const GType type, const int io_priority, const Gio::SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  const auto slot_copy = new Gio::SlotAsyncReady(slot);

  gdk_drop_read_value_async(gobj(), type, io_priority, nullptr, &Gio::SignalProxy_async_callback, slot_copy);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<DragAction>::value,
  "Type DragAction cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_actions() const -> Glib::PropertyProxy_ReadOnly< DragAction >
{
  return {this, "actions"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Device>>::value,
  "Type Glib::RefPtr<Device> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_device() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Device> >
{
  return {this, "device"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "display"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Drag>>::value,
  "Type Glib::RefPtr<Drag> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_drag() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Drag> >
{
  return {this, "drag"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ContentFormats>>::value,
  "Type Glib::RefPtr<ContentFormats> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ContentFormats> >
{
  return {this, "formats"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Surface>>::value,
  "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Drop::property_surface() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >
{
  return {this, "surface"};
}


} // namespace Gdk


