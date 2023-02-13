


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/dragsource.hxx>
#include <libmm-gtk/dragsource_p.hxx>


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

#include <gtk/gtk.h>

namespace
{


auto DragSource_signal_prepare_callback(GtkDragSource* self, const gdouble p0, const gdouble p1,void* data) -> GdkContentProvider*
{
  using namespace Gtk;
  using SlotType = sigc::slot<Glib::RefPtr<Gdk::ContentProvider>(double, double)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return unwrap_copy((*static_cast<SlotType*>(slot))(p0
                                                           , p1
        ));
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkContentProvider*;
  return RType();
}

auto DragSource_signal_prepare_notify_callback(GtkDragSource* self, const gdouble p0, const gdouble p1, void* data) -> GdkContentProvider*
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(double, double)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkContentProvider*;
  return RType();
}

const Glib::SignalProxyInfo DragSource_signal_prepare_info =
{
  "prepare",
  (GCallback) &DragSource_signal_prepare_callback,
  (GCallback) &DragSource_signal_prepare_notify_callback
};


auto DragSource_signal_drag_begin_callback (GtkDragSource *self, GdkDrag *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drag>&)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo DragSource_signal_drag_begin_info =
{
  "drag-begin",
  (GCallback) &DragSource_signal_drag_begin_callback,
  (GCallback) &DragSource_signal_drag_begin_callback
};


auto DragSource_signal_drag_end_callback (
  GtkDragSource *self, GdkDrag *p0, const gboolean p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drag>&, bool)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo DragSource_signal_drag_end_info =
{
  "drag-end",
  (GCallback) &DragSource_signal_drag_end_callback,
  (GCallback) &DragSource_signal_drag_end_callback
};


auto DragSource_signal_drag_cancel_callback(GtkDragSource* self, GdkDrag* p0,GdkDragCancelReason p1,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<Gdk::Drag>&, Gdk::DragCancelReason)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
                                               , static_cast<Gdk::DragCancelReason>(p1)
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

auto DragSource_signal_drag_cancel_notify_callback(GtkDragSource* self, GdkDrag* p0,GdkDragCancelReason p1, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::Drag>&, Gdk::DragCancelReason)>;

  const auto obj = dynamic_cast<DragSource*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, static_cast<Gdk::DragCancelReason>(p1)
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

const Glib::SignalProxyInfo DragSource_signal_drag_cancel_info =
{
  "drag-cancel",
  (GCallback) &DragSource_signal_drag_cancel_callback,
  (GCallback) &DragSource_signal_drag_cancel_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkDragSource* object, const bool take_copy) -> RefPtr<Gtk::DragSource>
{
  return Glib::make_refptr_for_instance<Gtk::DragSource>( dynamic_cast<Gtk::DragSource*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto DragSource_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DragSource_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_drag_source_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DragSource_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DragSource_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DragSource((GtkDragSource*)object);
}


/* The implementation: */

auto DragSource::gobj_copy() -> GtkDragSource*
{
  reference();
  return gobj();
}

DragSource::DragSource(const Glib::ConstructParams& construct_params)
:
  GestureSingle(construct_params)
{

}

DragSource::DragSource(GtkDragSource* castitem)
:
  GestureSingle((GtkGestureSingle*)castitem)
{}


DragSource::DragSource(DragSource&& src) noexcept
: GestureSingle(std::move(src))
{}

auto DragSource::operator=(DragSource&& src) noexcept -> DragSource&
{
  GestureSingle::operator=(std::move(src));
  return *this;
}


DragSource::~DragSource() noexcept = default;

DragSource::CppClassType DragSource::dragsource_class_; // initialize static member

auto DragSource::get_type() -> GType
{
  return dragsource_class_.init().get_type();
}


auto DragSource::get_base_type() -> GType
{
  return gtk_drag_source_get_type();
}


DragSource::DragSource()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  GestureSingle(Glib::ConstructParams(dragsource_class_.init()))
{


}

auto DragSource::create() -> Glib::RefPtr<DragSource>
{
  return Glib::make_refptr_for_instance<DragSource>( new DragSource() );
}

auto DragSource::set_content (const Glib::RefPtr <Gdk::ContentProvider> &content) -> void
{
  gtk_drag_source_set_content(gobj(), Glib::unwrap(content));
}

auto DragSource::get_content() -> Glib::RefPtr<Gdk::ContentProvider>
{
  auto retvalue = Glib::wrap(gtk_drag_source_get_content(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DragSource::get_content() const -> Glib::RefPtr<const Gdk::ContentProvider>
{
  return const_cast<DragSource*>(this)->get_content();
}

auto DragSource::set_actions (Gdk::DragAction actions) -> void
{
  gtk_drag_source_set_actions(gobj(), static_cast<GdkDragAction>(actions));
}

auto DragSource::get_actions() const -> Gdk::DragAction
{
  return static_cast<Gdk::DragAction>(gtk_drag_source_get_actions(const_cast<GtkDragSource*>(gobj())));
}

auto DragSource::set_icon (
  const Glib::RefPtr <const Gdk::Paintable> &paintable, const int hot_x, const int hot_y) -> void
{
  gtk_drag_source_set_icon(gobj(), const_cast<GdkPaintable*>(Glib::unwrap(paintable)), hot_x, hot_y);
}

auto DragSource::drag_cancel () -> void
{
  gtk_drag_source_drag_cancel(gobj());
}

auto DragSource::get_drag() -> Glib::RefPtr<Gdk::Drag>
{
  auto retvalue = Glib::wrap(gtk_drag_source_get_drag(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DragSource::get_drag() const -> Glib::RefPtr<const Gdk::Drag>
{
  return const_cast<DragSource*>(this)->get_drag();
}


auto DragSource::signal_prepare() -> Glib::SignalProxy<Glib::RefPtr<Gdk::ContentProvider>(double, double)>
{
  return {this, &DragSource_signal_prepare_info};
}


auto DragSource::signal_drag_begin() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drag>&)>
{
  return {this, &DragSource_signal_drag_begin_info};
}


auto DragSource::signal_drag_end() -> Glib::SignalProxy<void(const Glib::RefPtr<Gdk::Drag>&, bool)>
{
  return {this, &DragSource_signal_drag_end_info};
}


auto DragSource::signal_drag_cancel() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::Drag>&, Gdk::DragCancelReason)>
{
  return {this, &DragSource_signal_drag_cancel_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::ContentProvider>>::value,
  "Type Glib::RefPtr<Gdk::ContentProvider> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DragSource::property_content() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::ContentProvider> >
{
  return {this, "content"};
}

auto DragSource::property_content() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::ContentProvider> >
{
  return {this, "content"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::DragAction>::value,
  "Type Gdk::DragAction cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DragSource::property_actions() -> Glib::PropertyProxy< Gdk::DragAction >
{
  return {this, "actions"};
}

auto DragSource::property_actions() const -> Glib::PropertyProxy_ReadOnly< Gdk::DragAction >
{
  return {this, "actions"};
}


} // namespace Gtk


