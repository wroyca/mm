// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/pollableoutputstream.hxx>
#include <libmm/gio/pollableoutputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/cancellable.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GPollableOutputStream* object, const bool take_copy) -> RefPtr<Gio::PollableOutputStream>
  {
    return Glib::make_refptr_for_instance<Gio::PollableOutputStream> (
        Glib::wrap_auto_interface<Gio::PollableOutputStream> ((GObject*) object,
                                                              take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  PollableOutputStream_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PollableOutputStream_Class::iface_init_function;

      gtype_ = g_pollable_output_stream_get_type ();
    }

    return *this;
  }

  auto
  PollableOutputStream_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->can_poll = &can_poll_vfunc_callback;
    klass->is_writable = &is_writable_vfunc_callback;
    klass->write_nonblocking = &write_nonblocking_vfunc_callback;
  }

  auto
  PollableOutputStream_Class::can_poll_vfunc_callback (
      GPollableOutputStream* self) -> gboolean
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
          return obj->can_poll_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->can_poll)
      return (*base->can_poll) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  PollableOutputStream_Class::is_writable_vfunc_callback (
      GPollableOutputStream* self) -> gboolean
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
          return obj->is_writable_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->is_writable)
      return (*base->is_writable) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  PollableOutputStream_Class::write_nonblocking_vfunc_callback (
      GPollableOutputStream* self,
      const void* buffer,
      const gsize count,
      GError** error) -> gssize
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
          return obj->write_nonblocking_vfunc (buffer, count);
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          return -1;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->write_nonblocking)
      return (*base->write_nonblocking) (self, buffer, count, error);

    using RType = gssize;
    return RType ();
  }

  auto
  PollableOutputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PollableOutputStream ((GPollableOutputStream*) object);
  }

  PollableOutputStream::PollableOutputStream ()
    : Interface (pollableoutputstream_class_.init ())
  {
  }

  PollableOutputStream::PollableOutputStream (GPollableOutputStream* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  PollableOutputStream::PollableOutputStream (
      const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  PollableOutputStream::PollableOutputStream (
      PollableOutputStream&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  PollableOutputStream::operator= (PollableOutputStream&& src) noexcept -> PollableOutputStream&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  PollableOutputStream::~PollableOutputStream () noexcept = default;

  auto
  PollableOutputStream::add_interface (const GType gtype_implementer) -> void
  {
    pollableoutputstream_class_.init ().add_interface (gtype_implementer);
  }

  PollableOutputStream::CppClassType
      PollableOutputStream::pollableoutputstream_class_;

  auto
  PollableOutputStream::get_type () -> GType
  {
    return pollableoutputstream_class_.init ().get_type ();
  }

  auto
  PollableOutputStream::get_base_type () -> GType
  {
    return g_pollable_output_stream_get_type ();
  }

  auto
  PollableOutputStream::can_poll () const -> bool
  {
    return g_pollable_output_stream_can_poll (
        const_cast<GPollableOutputStream*> (gobj ()));
  }

  auto
  PollableOutputStream::is_writable () const -> bool
  {
    return g_pollable_output_stream_is_writable (
        const_cast<GPollableOutputStream*> (gobj ()));
  }

  auto
  PollableOutputStream::write_nonblocking (
      const void* buffer,
      const gsize count,
      const Glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_pollable_output_stream_write_nonblocking (
        gobj (),
        buffer,
        count,
        Glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PollableOutputStream::write_nonblocking (const void* buffer,
                                           const gsize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_pollable_output_stream_write_nonblocking (gobj (),
                                                                      buffer,
                                                                      count,
                                                                      nullptr,
                                                                      &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PollableOutputStream::can_poll_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->can_poll)
    {
      const bool retval (
          (*base->can_poll) (const_cast<GPollableOutputStream*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  PollableOutputStream::is_writable_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->is_writable)
    {
      const bool retval (
          (*base->is_writable) (const_cast<GPollableOutputStream*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  PollableOutputStream::write_nonblocking_vfunc (const void* buffer,
                                                 const gsize count) -> gssize
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->write_nonblocking)
    {
      GError* gerror = nullptr;
      const gssize retval (
          (*base->write_nonblocking) (gobj (), buffer, count, &gerror));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = gssize;
    return RType ();
  }

} // namespace Gio
