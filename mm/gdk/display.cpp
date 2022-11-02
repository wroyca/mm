// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gdk/display.hpp>
#include <mm/gdk/private/display_p.hpp>

#include <gdk/gdk.h>

/*
 * Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <vector>

#include <mm/gio/listmodel.hpp>
#include <mm/gdk/applaunchcontext.hpp>
#include <mm/gdk/clipboard.hpp>
#include <mm/gdk/glcontext.hpp>
#include <mm/gdk/seat.hpp>
#include <mm/gdk/monitor.hpp>
#include <mm/gdk/surface.hpp>
#include <gdk/gdk.h>

namespace Gdk
{
} //namespace Gdk

namespace
{


void Display_signal_closed_callback(GdkDisplay* self, gboolean p0,void* data)
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(bool)>;

  auto obj = dynamic_cast<Display*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Display_signal_closed_info =
{
  "closed",
  (GCallback) &Display_signal_closed_callback,
  (GCallback) &Display_signal_closed_callback
};


const Glib::SignalProxyInfo Display_signal_opened_info =
{
  "opened",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


void Display_signal_seat_added_callback(GdkDisplay* self, GdkSeat* p0,void* data)
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Seat>&)>;

  auto obj = dynamic_cast<Display*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Display_signal_seat_added_info =
{
  "seat-added",
  (GCallback) &Display_signal_seat_added_callback,
  (GCallback) &Display_signal_seat_added_callback
};


void Display_signal_seat_removed_callback(GdkDisplay* self, GdkSeat* p0,void* data)
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Seat>&)>;

  auto obj = dynamic_cast<Display*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Display_signal_seat_removed_info =
{
  "seat-removed",
  (GCallback) &Display_signal_seat_removed_callback,
  (GCallback) &Display_signal_seat_removed_callback
};


void Display_signal_setting_changed_callback(GdkDisplay* self, const gchar* p0,void* data)
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  auto obj = dynamic_cast<Display*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Display_signal_setting_changed_info =
{
  "setting-changed",
  (GCallback) &Display_signal_setting_changed_callback,
  (GCallback) &Display_signal_setting_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GdkDisplay* object, bool take_copy) -> Glib::RefPtr<Gdk::Display>
{
  return Glib::make_refptr_for_instance<Gdk::Display>( dynamic_cast<Gdk::Display*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto Display_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Display_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_display_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Display_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Display_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Display((GdkDisplay*)object);
}


/* The implementation: */

auto Display::gobj_copy() -> GdkDisplay*
{
  reference();
  return gobj();
}

Display::Display(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Display::Display(GdkDisplay* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Display::Display(Display&& src) noexcept
: Glib::Object(std::move(src))
{}

auto Display::operator=(Display&& src) noexcept -> Display&
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


Display::~Display() noexcept
{}


Display::CppClassType Display::display_class_; // initialize static member

auto Display::get_type() -> GType
{
  return display_class_.init().get_type();
}


auto Display::get_base_type() -> GType
{
  return gdk_display_get_type();
}


Display::Display()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(display_class_.init()))
{


}

auto Display::open(const Glib::ustring& display_name) -> Glib::RefPtr<Display>
{

  auto retvalue = Glib::wrap(gdk_display_open(display_name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

auto Display::get_name() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_display_get_name(const_cast<GdkDisplay*>(gobj())));
}

auto Display::device_is_grabbed(const Glib::RefPtr<const Gdk::Device>& device) const -> bool
{
  return gdk_display_device_is_grabbed(const_cast<GdkDisplay*>(gobj()), const_cast<GdkDevice*>(Glib::unwrap<Gdk::Device>(device)));
}

void Display::beep()
{
  gdk_display_beep(gobj());
}

void Display::sync()
{
  gdk_display_sync(gobj());
}

void Display::close()
{
  gdk_display_close(gobj());
}

auto Display::is_closed() const -> bool
{
  return gdk_display_is_closed(const_cast<GdkDisplay*>(gobj()));
}

auto Display::is_composited() const -> bool
{
  return gdk_display_is_composited(const_cast<GdkDisplay*>(gobj()));
}

auto Display::is_rgba() const -> bool
{
  return gdk_display_is_rgba(const_cast<GdkDisplay*>(gobj()));
}

void Display::put_event(const Glib::RefPtr<const Event>& event)
{
  gdk_display_put_event(gobj(), const_cast<GdkEvent*>(Glib::unwrap(event)));
}

auto Display::get_default() -> Glib::RefPtr<Display>
{

  auto retvalue = Glib::wrap(gdk_display_get_default());
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us
  return retvalue;
}

void Display::flush()
{
  gdk_display_flush(gobj());
}

auto Display::get_clipboard() -> Glib::RefPtr<Clipboard>
{
  auto retvalue = Glib::wrap(gdk_display_get_clipboard(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_clipboard() const -> Glib::RefPtr<const Clipboard>
{
  return const_cast<Display*>(this)->get_clipboard();
}

auto Display::get_primary_clipboard() -> Glib::RefPtr<Clipboard>
{
  auto retvalue = Glib::wrap(gdk_display_get_primary_clipboard(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_primary_clipboard() const -> Glib::RefPtr<const Clipboard>
{
  return const_cast<Display*>(this)->get_primary_clipboard();
}

auto Display::supports_input_shapes() const -> bool
{
  return gdk_display_supports_input_shapes(const_cast<GdkDisplay*>(gobj()));
}

void Display::prepare_gl()
{
  GError* gerror = nullptr;
  gdk_display_prepare_gl(gobj(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

auto Display::create_gl_context() -> Glib::RefPtr<GLContext>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(gdk_display_create_gl_context(gobj(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void Display::notify_startup_complete(const Glib::ustring& startup_id)
{
  gdk_display_notify_startup_complete(gobj(), startup_id.c_str());
}

auto Display::get_startup_notification_id() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gdk_display_get_startup_notification_id(const_cast<GdkDisplay*>(gobj())));
}

auto Display::get_app_launch_context() -> Glib::RefPtr<AppLaunchContext>
{
  auto retvalue = Glib::wrap(gdk_display_get_app_launch_context(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_app_launch_context() const -> Glib::RefPtr<const AppLaunchContext>
{
  return const_cast<Display*>(this)->get_app_launch_context();
}

auto Display::get_default_seat() -> Glib::RefPtr<Seat>
{
  auto retvalue = Glib::wrap(gdk_display_get_default_seat(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_default_seat() const -> Glib::RefPtr<const Seat>
{
  return const_cast<Display*>(this)->get_default_seat();
}

auto Display::list_seats() -> std::vector<Glib::RefPtr<Seat>>
{
  return Glib::ListHandler<Glib::RefPtr<Seat>>::list_to_vector(gdk_display_list_seats(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto Display::list_seats() const -> std::vector<Glib::RefPtr<const Seat>>
{
  return Glib::ListHandler<Glib::RefPtr<const Seat>>::list_to_vector(gdk_display_list_seats(const_cast<GdkDisplay*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto Display::get_monitors() -> Glib::RefPtr<Gio::ListModel>
{
  auto retvalue = Glib::wrap(gdk_display_get_monitors(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_monitors() const -> Glib::RefPtr<const Gio::ListModel>
{
  return const_cast<Display*>(this)->get_monitors();
}

auto Display::get_monitor_at_surface(const Glib::RefPtr<Surface>& surface) -> Glib::RefPtr<Monitor>
{
  auto retvalue = Glib::wrap(gdk_display_get_monitor_at_surface(gobj(), Glib::unwrap(surface)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Display::get_monitor_at_surface(const Glib::RefPtr<Surface>& surface) const -> Glib::RefPtr<const Monitor>
{
  return const_cast<Display*>(this)->get_monitor_at_surface(surface);
}


auto Display::signal_closed() -> Glib::SignalProxy<void(bool)>
{
  return Glib::SignalProxy<void(bool) >(this, &Display_signal_closed_info);
}


auto Display::signal_opened() -> Glib::SignalProxy<void()>
{
  return Glib::SignalProxy<void() >(this, &Display_signal_opened_info);
}


auto Display::signal_seat_added() -> Glib::SignalProxy<void(const Glib::RefPtr<Seat>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Seat>&) >(this, &Display_signal_seat_added_info);
}


auto Display::signal_seat_removed() -> Glib::SignalProxy<void(const Glib::RefPtr<Seat>&)>
{
  return Glib::SignalProxy<void(const Glib::RefPtr<Seat>&) >(this, &Display_signal_seat_removed_info);
}


auto Display::signal_setting_changed() -> Glib::SignalProxy<void(const Glib::ustring&)>
{
  return Glib::SignalProxy<void(const Glib::ustring&) >(this, &Display_signal_setting_changed_info);
}


auto Display::property_composited() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "composited");
}

auto Display::property_rgba() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "rgba");
}

auto Display::property_input_shapes() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "input-shapes");
}


} // namespace Gdk


