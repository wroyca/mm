// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/pollableinputstream.hxx>
#include <libmm/gio/pollableinputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/cancellable.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GPollableInputStream* object, const bool take_copy) -> RefPtr<gio::PollableInputStream>
  {
    return glib::make_refptr_for_instance<gio::PollableInputStream> (
        glib::wrap_auto_interface<gio::PollableInputStream> ((GObject*) object,
                                                             take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  PollableInputStream_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PollableInputStream_Class::iface_init_function;

      gtype_ = g_pollable_input_stream_get_type ();
    }

    return *this;
  }

  auto
  PollableInputStream_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->can_poll = &can_poll_vfunc_callback;
    klass->is_readable = &is_readable_vfunc_callback;
    klass->read_nonblocking = &read_nonblocking_vfunc_callback;
  }

  auto
  PollableInputStream_Class::can_poll_vfunc_callback (
      GPollableInputStream* self) -> gboolean
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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
          glib::exception_handlers_invoke ();
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
  PollableInputStream_Class::is_readable_vfunc_callback (
      GPollableInputStream* self) -> gboolean
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->is_readable_vfunc ();
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->is_readable)
      return (*base->is_readable) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  PollableInputStream_Class::read_nonblocking_vfunc_callback (
      GPollableInputStream* self,
      void* buffer,
      const gsize count,
      GError** error) -> gssize
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->read_nonblocking_vfunc (buffer, count);
        }
        catch (glib::Error& errormm)
        {
          errormm.propagate (error);
          return -1;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->read_nonblocking)
      return (*base->read_nonblocking) (self, buffer, count, error);

    using RType = gssize;
    return RType ();
  }

  auto
  PollableInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new PollableInputStream ((GPollableInputStream*) object);
  }

  PollableInputStream::PollableInputStream ()
    : Interface (pollableinputstream_class_.init ())
  {
  }

  PollableInputStream::PollableInputStream (GPollableInputStream* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  PollableInputStream::PollableInputStream (
      const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  PollableInputStream::PollableInputStream (PollableInputStream&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  PollableInputStream::operator= (PollableInputStream&& src) noexcept -> PollableInputStream&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  PollableInputStream::~PollableInputStream () noexcept = default;

  auto
  PollableInputStream::add_interface (const GType gtype_implementer) -> void
  {
    pollableinputstream_class_.init ().add_interface (gtype_implementer);
  }

  PollableInputStream::CppClassType
      PollableInputStream::pollableinputstream_class_;

  auto
  PollableInputStream::get_type () -> GType
  {
    return pollableinputstream_class_.init ().get_type ();
  }

  auto
  PollableInputStream::get_base_type () -> GType
  {
    return g_pollable_input_stream_get_type ();
  }

  auto
  PollableInputStream::can_poll () const -> bool
  {
    return g_pollable_input_stream_can_poll (
        const_cast<GPollableInputStream*> (gobj ()));
  }

  auto
  PollableInputStream::is_readable () const -> bool
  {
    return g_pollable_input_stream_is_readable (
        const_cast<GPollableInputStream*> (gobj ()));
  }

  auto
  PollableInputStream::read_nonblocking (
      void* buffer,
      const gsize count,
      const glib::RefPtr<Cancellable>& cancellable) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_pollable_input_stream_read_nonblocking (
        gobj (),
        buffer,
        count,
        glib::unwrap (cancellable),
        &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PollableInputStream::read_nonblocking (void* buffer, const gsize count) -> gssize
  {
    GError* gerror = nullptr;
    const auto retvalue = g_pollable_input_stream_read_nonblocking (gobj (),
                                                                    buffer,
                                                                    count,
                                                                    nullptr,
                                                                    &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  PollableInputStream::can_poll_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->can_poll)
    {
      const bool retval (
          (*base->can_poll) (const_cast<GPollableInputStream*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  PollableInputStream::is_readable_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->is_readable)
    {
      const bool retval (
          (*base->is_readable) (const_cast<GPollableInputStream*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  PollableInputStream::read_nonblocking_vfunc (void* buffer, const gsize count) -> gssize
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->read_nonblocking)
    {
      GError* gerror = nullptr;
      const gssize retval (
          (*base->read_nonblocking) (gobj (), buffer, count, &gerror));
      if (gerror)
        glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = gssize;
    return RType ();
  }

} // namespace gio
