


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/socketcontrolmessage.hxx>
#include <libmm-gio/socketcontrolmessage_p.hxx>


/* Copyright (C) 2010 The giomm Development Team
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
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{
// static
std::set<SocketControlMessage::DeserializeFunc> SocketControlMessage::m_deserialize_funcs;

auto SocketControlMessage_Class::deserialize_vfunc_callback(
  const int level, const int type, const gsize size, const gpointer data) -> GSocketControlMessage*
{
  // Loop through all registered deserialize functions.
  // Accept the returned message from the first function that has been able to
  // deserialize the message. g_socket_control_message_deserialize() loops
  // through all subclasses of GSocketControlMessage in this way.
  for (const auto deserialize_func : CppObjectType::m_deserialize_funcs)
  {
    try // Trap C++ exceptions which would normally be lost because this is a C callback.
    {
      // Call the function which has been registered with add_deserialize_func().
      Glib::RefPtr<SocketControlMessage> msg = deserialize_func(level, type, size, data);
      if (msg)
      {
        msg->reference(); // Give the caller a reference.
        return msg->gobj();
      }
    }
    catch (...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  // Don't call the original underlying C function (GSocketControlMessage.deserialize()).
  // Let g_socket_control_message_deserialize() do that as a last resort,
  // if it's appropriate.
  return nullptr;
}

// static
auto SocketControlMessage::add_deserialize_func (
  const DeserializeFunc func) -> void
{
  // std::set never contains duplicates.
  m_deserialize_funcs.insert(func);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GSocketControlMessage* object, const bool take_copy) -> RefPtr<Gio::SocketControlMessage>
{
  return Glib::make_refptr_for_instance<Gio::SocketControlMessage>( dynamic_cast<Gio::SocketControlMessage*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto SocketControlMessage_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketControlMessage_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_control_message_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SocketControlMessage_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->deserialize = &deserialize_vfunc_callback;
    klass->get_size = &get_size_vfunc_callback;
  klass->get_level = &get_level_vfunc_callback;
  klass->get_type = &get_type_vfunc_callback;
  klass->serialize = &serialize_vfunc_callback;

}

auto SocketControlMessage_Class::get_size_vfunc_callback(GSocketControlMessage* self) -> gsize
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
        return obj->get_size_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_size)
    return (*base->get_size)(self);

  using RType = gsize;
  return RType();
}
auto SocketControlMessage_Class::get_level_vfunc_callback(GSocketControlMessage* self) -> int
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
        return obj->get_level_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_level)
    return (*base->get_level)(self);

  using RType = int;
  return RType();
}
auto SocketControlMessage_Class::get_type_vfunc_callback(GSocketControlMessage* self) -> int
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
        return obj->get_type_vfunc();
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_type)
    return (*base->get_type)(self);

  using RType = int;
  return RType();
}
auto SocketControlMessage_Class::serialize_vfunc_callback (
  GSocketControlMessage *self, const gpointer data) -> void
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
        obj->serialize_vfunc(data);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->serialize)
    (*base->serialize)(self, data);
}


auto SocketControlMessage_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SocketControlMessage((GSocketControlMessage*)object);
}


/* The implementation: */

auto SocketControlMessage::gobj_copy() -> GSocketControlMessage*
{
  reference();
  return gobj();
}

SocketControlMessage::SocketControlMessage(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SocketControlMessage::SocketControlMessage(GSocketControlMessage* castitem)
: Object((GObject*)castitem)
{}


SocketControlMessage::SocketControlMessage(SocketControlMessage&& src) noexcept
: Object(std::move(src))
{}

auto SocketControlMessage::operator=(SocketControlMessage&& src) noexcept -> SocketControlMessage&
{
  Object::operator=(std::move(src));
  return *this;
}


SocketControlMessage::~SocketControlMessage() noexcept = default;

SocketControlMessage::CppClassType SocketControlMessage::socketcontrolmessage_class_; // initialize static member

auto SocketControlMessage::get_type() -> GType
{
  return socketcontrolmessage_class_.init().get_type();
}


auto SocketControlMessage::get_base_type() -> GType
{
  return g_socket_control_message_get_type();
}


SocketControlMessage::SocketControlMessage()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(socketcontrolmessage_class_.init()))
{


}

auto SocketControlMessage::deserialize(
  const int level, const int type, const gsize size, const gpointer data) -> Glib::RefPtr<SocketControlMessage>
{
  return Glib::wrap(g_socket_control_message_deserialize(level, type, size, data));
}

auto SocketControlMessage::get_level() const -> int
{
  return g_socket_control_message_get_level(const_cast<GSocketControlMessage*>(gobj()));
}

auto SocketControlMessage::get_msg_type() const -> int
{
  return g_socket_control_message_get_msg_type(const_cast<GSocketControlMessage*>(gobj()));
}

auto SocketControlMessage::get_size() const -> gsize
{
  return g_socket_control_message_get_size(const_cast<GSocketControlMessage*>(gobj()));
}

auto SocketControlMessage::serialize (
  const gpointer data) -> void
{
  g_socket_control_message_serialize(gobj(), data);
}


auto SocketControlMessage::get_size_vfunc() const -> gsize
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_size)
  {
    const gsize retval((*base->get_size)(const_cast<GSocketControlMessage*>(gobj())));
    return retval;
  }

  using RType = gsize;
  return RType();
}
auto SocketControlMessage::get_level_vfunc() const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_level)
  {
    const int retval((*base->get_level)(const_cast<GSocketControlMessage*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}
auto SocketControlMessage::get_type_vfunc() const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_type)
  {
    const int retval((*base->get_type)(const_cast<GSocketControlMessage*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}
auto SocketControlMessage::serialize_vfunc (
  const gpointer data) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->serialize)
  {
    (*base->serialize)(gobj(),data);
  }
}


} // namespace Gio


