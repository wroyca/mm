// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/socketcontrolmessage.hxx>
#include <libmm/gio/socketcontrolmessage_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>

namespace Gio
{

  std::set<SocketControlMessage::DeserializeFunc>
      SocketControlMessage::m_deserialize_funcs;

  auto
  SocketControlMessage_Class::deserialize_vfunc_callback (const int level,
                                                          const int type,
                                                          const gsize size,
                                                          const gpointer data) -> GSocketControlMessage*
  {
    for (const auto deserialize_func : CppObjectType::m_deserialize_funcs)
    {
      try
      {
        Glib::RefPtr<SocketControlMessage> msg =
            deserialize_func (level, type, size, data);
        if (msg)
        {
          msg->reference ();
          return msg->gobj ();
        }
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    return nullptr;
  }

  auto
  SocketControlMessage::add_deserialize_func (const DeserializeFunc func) -> void
  {
    m_deserialize_funcs.insert (func);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GSocketControlMessage* object, const bool take_copy) -> RefPtr<Gio::SocketControlMessage>
  {
    return Glib::make_refptr_for_instance<Gio::SocketControlMessage> (
        dynamic_cast<Gio::SocketControlMessage*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SocketControlMessage_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SocketControlMessage_Class::class_init_function;

      register_derived_type (g_socket_control_message_get_type ());
    }

    return *this;
  }

  auto
  SocketControlMessage_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->deserialize = &deserialize_vfunc_callback;
    klass->get_size = &get_size_vfunc_callback;
    klass->get_level = &get_level_vfunc_callback;
    klass->get_type = &get_type_vfunc_callback;
    klass->serialize = &serialize_vfunc_callback;
  }

  auto
  SocketControlMessage_Class::get_size_vfunc_callback (
      GSocketControlMessage* self) -> gsize
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_size_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_size)
      return (*base->get_size) (self);

    using RType = gsize;
    return RType ();
  }

  auto
  SocketControlMessage_Class::get_level_vfunc_callback (
      GSocketControlMessage* self) -> int
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_level_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_level)
      return (*base->get_level) (self);

    using RType = int;
    return RType ();
  }

  auto
  SocketControlMessage_Class::get_type_vfunc_callback (
      GSocketControlMessage* self) -> int
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_type_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_type)
      return (*base->get_type) (self);

    using RType = int;
    return RType ();
  }

  auto
  SocketControlMessage_Class::serialize_vfunc_callback (
      GSocketControlMessage* self,
      const gpointer data) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->serialize_vfunc (data);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->serialize)
      (*base->serialize) (self, data);
  }

  auto
  SocketControlMessage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SocketControlMessage ((GSocketControlMessage*) object);
  }

  auto
  SocketControlMessage::gobj_copy () -> GSocketControlMessage*
  {
    reference ();
    return gobj ();
  }

  SocketControlMessage::SocketControlMessage (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SocketControlMessage::SocketControlMessage (GSocketControlMessage* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SocketControlMessage::SocketControlMessage (
      SocketControlMessage&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  SocketControlMessage::operator= (SocketControlMessage&& src) noexcept -> SocketControlMessage&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  SocketControlMessage::~SocketControlMessage () noexcept = default;

  SocketControlMessage::CppClassType
      SocketControlMessage::socketcontrolmessage_class_;

  auto
  SocketControlMessage::get_type () -> GType
  {
    return socketcontrolmessage_class_.init ().get_type ();
  }

  auto
  SocketControlMessage::get_base_type () -> GType
  {
    return g_socket_control_message_get_type ();
  }

  SocketControlMessage::SocketControlMessage ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (socketcontrolmessage_class_.init ()))
  {
  }

  auto
  SocketControlMessage::deserialize (const int level,
                                     const int type,
                                     const gsize size,
                                     const gpointer data) -> Glib::RefPtr<SocketControlMessage>
  {
    return Glib::wrap (
        g_socket_control_message_deserialize (level, type, size, data));
  }

  auto
  SocketControlMessage::get_level () const -> int
  {
    return g_socket_control_message_get_level (
        const_cast<GSocketControlMessage*> (gobj ()));
  }

  auto
  SocketControlMessage::get_msg_type () const -> int
  {
    return g_socket_control_message_get_msg_type (
        const_cast<GSocketControlMessage*> (gobj ()));
  }

  auto
  SocketControlMessage::get_size () const -> gsize
  {
    return g_socket_control_message_get_size (
        const_cast<GSocketControlMessage*> (gobj ()));
  }

  auto
  SocketControlMessage::serialize (const gpointer data) -> void
  {
    g_socket_control_message_serialize (gobj (), data);
  }

  auto
  SocketControlMessage::get_size_vfunc () const -> gsize
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_size)
    {
      const gsize retval (
          (*base->get_size) (const_cast<GSocketControlMessage*> (gobj ())));
      return retval;
    }

    using RType = gsize;
    return RType ();
  }

  auto
  SocketControlMessage::get_level_vfunc () const -> int
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_level)
    {
      const int retval (
          (*base->get_level) (const_cast<GSocketControlMessage*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  SocketControlMessage::get_type_vfunc () const -> int
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_type)
    {
      const int retval (
          (*base->get_type) (const_cast<GSocketControlMessage*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  SocketControlMessage::serialize_vfunc (const gpointer data) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->serialize)
    {
      (*base->serialize) (gobj (), data);
    }
  }

} // namespace Gio
