


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/pollableinputstream.hpp>
#include <libmm-gio/pollableinputstream_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <libmm-gio/cancellable.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GPollableInputStream* object, const bool take_copy) -> RefPtr<Gio::PollableInputStream>
{
  return Glib::make_refptr_for_instance<Gio::PollableInputStream>( Glib::wrap_auto_interface<Gio::PollableInputStream> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto PollableInputStream_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &PollableInputStream_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_pollable_input_stream_get_type();
  }

  return *this;
}

auto PollableInputStream_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->can_poll = &can_poll_vfunc_callback;
  klass->is_readable = &is_readable_vfunc_callback;
  klass->read_nonblocking = &read_nonblocking_vfunc_callback;

}

auto PollableInputStream_Class::can_poll_vfunc_callback(GPollableInputStream* self) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

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
        return obj->can_poll_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->can_poll)
    return (*base->can_poll)(self);

  using RType = gboolean;
  return RType();
}
auto PollableInputStream_Class::is_readable_vfunc_callback(GPollableInputStream* self) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

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
        return obj->is_readable_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->is_readable)
    return (*base->is_readable)(self);

  using RType = gboolean;
  return RType();
}
auto PollableInputStream_Class::read_nonblocking_vfunc_callback(GPollableInputStream* self, void* buffer, const gsize count, GError** error) -> gssize
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

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
        return obj->read_nonblocking_vfunc(buffer, count);
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        return -1;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->read_nonblocking)
    return (*base->read_nonblocking)(self, buffer, count, error);

  using RType = gssize;
  return RType();
}


auto PollableInputStream_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PollableInputStream((GPollableInputStream*)object);
}


/* The implementation: */

PollableInputStream::PollableInputStream()
: Interface(pollableinputstream_class_.init())
{}

PollableInputStream::PollableInputStream(GPollableInputStream* castitem)
: Interface((GObject*)castitem)
{}

PollableInputStream::PollableInputStream(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

PollableInputStream::PollableInputStream(PollableInputStream&& src) noexcept
: Interface(std::move(src))
{}

auto PollableInputStream::operator=(PollableInputStream&& src) noexcept -> PollableInputStream&
{
  Interface::operator=(std::move(src));
  return *this;
}

PollableInputStream::~PollableInputStream() noexcept = default;

// static
auto PollableInputStream::add_interface (
  const GType gtype_implementer) -> void
{
  pollableinputstream_class_.init().add_interface(gtype_implementer);
}

PollableInputStream::CppClassType PollableInputStream::pollableinputstream_class_; // initialize static member

auto PollableInputStream::get_type() -> GType
{
  return pollableinputstream_class_.init().get_type();
}


auto PollableInputStream::get_base_type() -> GType
{
  return g_pollable_input_stream_get_type();
}


auto PollableInputStream::can_poll() const -> bool
{
  return g_pollable_input_stream_can_poll(const_cast<GPollableInputStream*>(gobj()));
}

auto PollableInputStream::is_readable() const -> bool
{
  return g_pollable_input_stream_is_readable(const_cast<GPollableInputStream*>(gobj()));
}

auto PollableInputStream::read_nonblocking(void* buffer, const gsize count, const Glib::RefPtr<Cancellable>& cancellable) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_pollable_input_stream_read_nonblocking(gobj(), buffer, count, Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto PollableInputStream::read_nonblocking(void* buffer, const gsize count) -> gssize
{
  GError* gerror = nullptr;
  const auto retvalue = g_pollable_input_stream_read_nonblocking(gobj(), buffer, count, nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}


auto PollableInputStream::can_poll_vfunc() const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->can_poll)
  {
    const bool retval((*base->can_poll)(const_cast<GPollableInputStream*>(gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto PollableInputStream::is_readable_vfunc() const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->is_readable)
  {
    const bool retval((*base->is_readable)(const_cast<GPollableInputStream*>(gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto PollableInputStream::read_nonblocking_vfunc(void* buffer, const gsize count) -> gssize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->read_nonblocking)
  {
    GError* gerror = nullptr;
    const gssize retval((*base->read_nonblocking)(gobj(),buffer,count,&gerror));
    if(gerror)
      Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}


} // namespace Gio


