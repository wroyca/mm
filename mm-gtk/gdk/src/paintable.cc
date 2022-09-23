// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <gdkmm/paintable.h>
#include <gdkmm/private/paintable_p.h>


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

#include <gdk/gdk.h>
#include <gdkmm/snapshot.h>

using Flags = Gdk::Paintable::Flags;

namespace
{


static const Glib::SignalProxyInfo Paintable_signal_invalidate_contents_info =
{
  "invalidate-contents",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


static const Glib::SignalProxyInfo Paintable_signal_invalidate_size_info =
{
  "invalidate-size",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
GType Glib::Value<Gdk::Paintable::Flags>::value_type()
{
  return gdk_paintable_flags_get_type();
}


namespace Glib
{

Glib::RefPtr<Gdk::Paintable> wrap(GdkPaintable* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gdk::Paintable>( dynamic_cast<Gdk::Paintable*> (Glib::wrap_auto_interface<Gdk::Paintable> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gdk
{


/* The *_Class implementation: */

const Glib::Interface_Class& Paintable_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Paintable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gdk_paintable_get_type();
  }

  return *this;
}

void Paintable_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->snapshot = &snapshot_vfunc_callback;
  klass->get_current_image = &get_current_image_vfunc_callback;
  klass->get_flags = &get_flags_vfunc_callback;
  klass->get_intrinsic_width = &get_intrinsic_width_vfunc_callback;
  klass->get_intrinsic_height = &get_intrinsic_height_vfunc_callback;
  klass->get_intrinsic_aspect_ratio = &get_intrinsic_aspect_ratio_vfunc_callback;

}

void Paintable_Class::snapshot_vfunc_callback(GdkPaintable* self, GdkSnapshot* snapshot, double width, double height)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->snapshot_vfunc(Glib::wrap(snapshot, true)
, width, height);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->snapshot)
    (*base->snapshot)(self, snapshot, width, height);
}
GdkPaintable* Paintable_Class::get_current_image_vfunc_callback(GdkPaintable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return Glib::unwrap(obj->get_current_image_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_current_image)
    return (*base->get_current_image)(self);

  using RType = GdkPaintable*;
  return RType();
}
GdkPaintableFlags Paintable_Class::get_flags_vfunc_callback(GdkPaintable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<GdkPaintableFlags>(obj->get_flags_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_flags)
    return (*base->get_flags)(self);

  using RType = GdkPaintableFlags;
  return RType();
}
int Paintable_Class::get_intrinsic_width_vfunc_callback(GdkPaintable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_intrinsic_width_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_intrinsic_width)
    return (*base->get_intrinsic_width)(self);

  using RType = int;
  return RType();
}
int Paintable_Class::get_intrinsic_height_vfunc_callback(GdkPaintable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_intrinsic_height_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_intrinsic_height)
    return (*base->get_intrinsic_height)(self);

  using RType = int;
  return RType();
}
double Paintable_Class::get_intrinsic_aspect_ratio_vfunc_callback(GdkPaintable* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->get_intrinsic_aspect_ratio_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->get_intrinsic_aspect_ratio)
    return (*base->get_intrinsic_aspect_ratio)(self);

  using RType = double;
  return RType();
}


Glib::ObjectBase* Paintable_Class::wrap_new(GObject* object)
{
  return new Paintable((GdkPaintable*)(object));
}


/* The implementation: */

Paintable::Paintable()
:
  Glib::Interface(paintable_class_.init())
{}

Paintable::Paintable(GdkPaintable* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Paintable::Paintable(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Paintable::Paintable(Paintable&& src) noexcept
: Glib::Interface(std::move(src))
{}

Paintable& Paintable::operator=(Paintable&& src) noexcept
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Paintable::~Paintable() noexcept
{}

// static
void Paintable::add_interface(GType gtype_implementer)
{
  paintable_class_.init().add_interface(gtype_implementer);
}

Paintable::CppClassType Paintable::paintable_class_; // initialize static member

GType Paintable::get_type()
{
  return paintable_class_.init().get_type();
}


GType Paintable::get_base_type()
{
  return gdk_paintable_get_type();
}


void Paintable::snapshot(const Glib::RefPtr<Gdk::Snapshot>& snapshot, double width, double height)
{
  gdk_paintable_snapshot(gobj(), Glib::unwrap(snapshot), width, height);
}

Glib::RefPtr<const Paintable> Paintable::get_current_image() const
{
  return Glib::wrap(gdk_paintable_get_current_image(const_cast<GdkPaintable*>(gobj())));
}

Flags Paintable::get_flags() const
{
  return static_cast<Flags>(gdk_paintable_get_flags(const_cast<GdkPaintable*>(gobj())));
}

int Paintable::get_intrinsic_width() const
{
  return gdk_paintable_get_intrinsic_width(const_cast<GdkPaintable*>(gobj()));
}

int Paintable::get_intrinsic_height() const
{
  return gdk_paintable_get_intrinsic_height(const_cast<GdkPaintable*>(gobj()));
}

double Paintable::get_intrinsic_aspect_ratio() const
{
  return gdk_paintable_get_intrinsic_aspect_ratio(const_cast<GdkPaintable*>(gobj()));
}

void Paintable::compute_concrete_size(double specified_width, double specified_height, double default_width, double default_height, double& concrete_width, double& concrete_height) const
{
  gdk_paintable_compute_concrete_size(const_cast<GdkPaintable*>(gobj()), specified_width, specified_height, default_width, default_height, &(concrete_width), &(concrete_height));
}

void Paintable::invalidate_contents()
{
  gdk_paintable_invalidate_contents(gobj());
}

void Paintable::invalidate_size()
{
  gdk_paintable_invalidate_size(gobj());
}


Glib::SignalProxy<void()> Paintable::signal_invalidate_contents()
{
  return Glib::SignalProxy<void() >(this, &Paintable_signal_invalidate_contents_info);
}


Glib::SignalProxy<void()> Paintable::signal_invalidate_size()
{
  return Glib::SignalProxy<void() >(this, &Paintable_signal_invalidate_size_info);
}


void Gdk::Paintable::snapshot_vfunc(const Glib::RefPtr<Gdk::Snapshot>& snapshot, double width, double height) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->snapshot)
  {
    (*base->snapshot)(gobj(),Glib::unwrap(snapshot),width,height);
  }
}
Glib::RefPtr<Paintable> Gdk::Paintable::get_current_image_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_current_image)
  {
    Glib::RefPtr<Paintable> retval(Glib::wrap((*base->get_current_image)(const_cast<GdkPaintable*>(gobj())), true));
    return retval;
  }

  using RType = Glib::RefPtr<Paintable>;
  return RType();
}
Flags Gdk::Paintable::get_flags_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_flags)
  {
    Flags retval(static_cast<Flags>((*base->get_flags)(const_cast<GdkPaintable*>(gobj()))));
    return retval;
  }

  using RType = Flags;
  return RType();
}
int Gdk::Paintable::get_intrinsic_width_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_intrinsic_width)
  {
    int retval((*base->get_intrinsic_width)(const_cast<GdkPaintable*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}
int Gdk::Paintable::get_intrinsic_height_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_intrinsic_height)
  {
    int retval((*base->get_intrinsic_height)(const_cast<GdkPaintable*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}
double Gdk::Paintable::get_intrinsic_aspect_ratio_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_intrinsic_aspect_ratio)
  {
    double retval((*base->get_intrinsic_aspect_ratio)(const_cast<GdkPaintable*>(gobj())));
    return retval;
  }

  using RType = double;
  return RType();
}


} // namespace Gdk


