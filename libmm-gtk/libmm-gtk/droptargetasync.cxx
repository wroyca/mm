


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/droptargetasync.hxx>
#include <libmm-gtk/droptargetasync_p.hxx>


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

#include <libmm-gio/slot_async.hxx>
#include <gtk/gtk.h>

namespace Gtk
{
auto DropTargetAsync::create(
  const Glib::RefPtr<const Gdk::ContentFormats>& formats, Gdk::DragAction actions) -> Glib::RefPtr<DropTargetAsync>
{
  // gtk_drop_target_async_new() drops our reference from formats. (transfer full)
  if (formats)
    formats->reference();
  return Glib::wrap(gtk_drop_target_async_new(
    const_cast<GdkContentFormats*>(Glib::unwrap(formats)),
    static_cast<GdkDragAction>(actions)));
}

auto DropTargetAsync::create(Gdk::DragAction actions) -> Glib::RefPtr<DropTargetAsync>
{
  return Glib::wrap(gtk_drop_target_async_new(nullptr, static_cast<GdkDragAction>(actions)));
}
}

namespace
{


auto DropTargetAsync_signal_accept_callback(GtkDropTargetAsync* self, GdkDrop* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<Gdk::Drop>&)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto DropTargetAsync_signal_accept_notify_callback(GtkDropTargetAsync* self, GdkDrop* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drop>&)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo DropTargetAsync_signal_accept_info =
{
  "accept",
  (GCallback) &DropTargetAsync_signal_accept_callback,
  (GCallback) &DropTargetAsync_signal_accept_notify_callback
};


auto DropTargetAsync_signal_drag_enter_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2,void* data) -> GdkDragAction
{
  using namespace Gtk;
  using SlotType = sigc::slot<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return static_cast<GdkDragAction>((*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, p2
));
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkDragAction;
  return RType();
}

auto DropTargetAsync_signal_drag_enter_notify_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2, void* data) -> GdkDragAction
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, p2
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkDragAction;
  return RType();
}

const Glib::SignalProxyInfo DropTargetAsync_signal_drag_enter_info =
{
  "drag-enter",
  (GCallback) &DropTargetAsync_signal_drag_enter_callback,
  (GCallback) &DropTargetAsync_signal_drag_enter_notify_callback
};


auto DropTargetAsync_signal_drag_motion_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2,void* data) -> GdkDragAction
{
  using namespace Gtk;
  using SlotType = sigc::slot<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return static_cast<GdkDragAction>((*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, p2
));
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkDragAction;
  return RType();
}

auto DropTargetAsync_signal_drag_motion_notify_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2, void* data) -> GdkDragAction
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, p2
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkDragAction;
  return RType();
}

const Glib::SignalProxyInfo DropTargetAsync_signal_drag_motion_info =
{
  "drag-motion",
  (GCallback) &DropTargetAsync_signal_drag_motion_callback,
  (GCallback) &DropTargetAsync_signal_drag_motion_notify_callback
};


auto DropTargetAsync_signal_drag_leave_callback (
  GtkDropTargetAsync *self, GdkDrop *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drop>&)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo DropTargetAsync_signal_drag_leave_info =
{
  "drag-leave",
  (GCallback) &DropTargetAsync_signal_drag_leave_callback,
  (GCallback) &DropTargetAsync_signal_drag_leave_callback
};


auto DropTargetAsync_signal_drop_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
                                               , p1
                                               , p2
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto DropTargetAsync_signal_drop_notify_callback(GtkDropTargetAsync* self, GdkDrop* p0, const gdouble p1, const gdouble p2, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  const auto obj = dynamic_cast<DropTargetAsync*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
, p2
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo DropTargetAsync_signal_drop_info =
{
  "drop",
  (GCallback) &DropTargetAsync_signal_drop_callback,
  (GCallback) &DropTargetAsync_signal_drop_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkDropTargetAsync* object, const bool take_copy) -> RefPtr<Gtk::DropTargetAsync>
{
  return Glib::make_refptr_for_instance<Gtk::DropTargetAsync>( dynamic_cast<Gtk::DropTargetAsync*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto DropTargetAsync_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DropTargetAsync_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_drop_target_async_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DropTargetAsync_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DropTargetAsync_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DropTargetAsync((GtkDropTargetAsync*)object);
}


/* The implementation: */

auto DropTargetAsync::gobj_copy() -> GtkDropTargetAsync*
{
  reference();
  return gobj();
}

DropTargetAsync::DropTargetAsync(const Glib::ConstructParams& construct_params)
:
  EventController(construct_params)
{

}

DropTargetAsync::DropTargetAsync(GtkDropTargetAsync* castitem)
:
  EventController((GtkEventController*)castitem)
{}


DropTargetAsync::DropTargetAsync(DropTargetAsync&& src) noexcept
: EventController(std::move(src))
{}

auto DropTargetAsync::operator=(DropTargetAsync&& src) noexcept -> DropTargetAsync&
{
  EventController::operator=(std::move(src));
  return *this;
}


DropTargetAsync::~DropTargetAsync() noexcept = default;

DropTargetAsync::CppClassType DropTargetAsync::droptargetasync_class_; // initialize static member

auto DropTargetAsync::get_type() -> GType
{
  return droptargetasync_class_.init().get_type();
}


auto DropTargetAsync::get_base_type() -> GType
{
  return gtk_drop_target_async_get_type();
}


auto DropTargetAsync::set_formats (const Glib::RefPtr <const Gdk::ContentFormats> &formats) -> void
{
  gtk_drop_target_async_set_formats(gobj(), const_cast<GdkContentFormats*>(Glib::unwrap(formats)));
}

auto DropTargetAsync::get_formats() -> Glib::RefPtr<Gdk::ContentFormats>
{
  auto retvalue = Glib::wrap(gtk_drop_target_async_get_formats(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DropTargetAsync::get_formats() const -> Glib::RefPtr<const Gdk::ContentFormats>
{
  return const_cast<DropTargetAsync*>(this)->get_formats();
}

auto DropTargetAsync::set_actions (Gdk::DragAction actions) -> void
{
  gtk_drop_target_async_set_actions(gobj(), static_cast<GdkDragAction>(actions));
}

auto DropTargetAsync::get_actions() const -> Gdk::DragAction
{
  return static_cast<Gdk::DragAction>(gtk_drop_target_async_get_actions(const_cast<GtkDropTargetAsync*>(gobj())));
}

auto DropTargetAsync::reject_drop (const Glib::RefPtr <Gdk::Drop> &drop) -> void
{
  gtk_drop_target_async_reject_drop(gobj(), Glib::unwrap(drop));
}


auto DropTargetAsync::signal_accept() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drop>&)>
{
  return {this, &DropTargetAsync_signal_accept_info};
}


auto DropTargetAsync::signal_drag_enter() -> Glib::SignalProxy<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>
{
  return {this, &DropTargetAsync_signal_drag_enter_info};
}


auto DropTargetAsync::signal_drag_motion() -> Glib::SignalProxy<Gdk::DragAction(const Glib::RefPtr<Gdk::Drop>&, double, double)>
{
  return {this, &DropTargetAsync_signal_drag_motion_info};
}


auto DropTargetAsync::signal_drag_leave() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drop>&)>
{
  return {this, &DropTargetAsync_signal_drag_leave_info};
}


auto DropTargetAsync::signal_drop() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drop>&, double, double)>
{
  return {this, &DropTargetAsync_signal_drop_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::DragAction>::value,
  "Type Gdk::DragAction cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropTargetAsync::property_actions() -> Glib::PropertyProxy< Gdk::DragAction >
{
  return {this, "actions"};
}

auto DropTargetAsync::property_actions() const -> Glib::PropertyProxy_ReadOnly< Gdk::DragAction >
{
  return {this, "actions"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::ContentFormats>>::value,
  "Type Glib::RefPtr<Gdk::ContentFormats> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DropTargetAsync::property_formats() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::ContentFormats> >
{
  return {this, "formats"};
}

auto DropTargetAsync::property_formats() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::ContentFormats> >
{
  return {this, "formats"};
}


} // namespace Gtk


