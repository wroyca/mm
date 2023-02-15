// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/converter.hxx>
#include <libmm-gio/converter_p.hxx>

#include <gio/gio.h>

using Flags = Gio::Converter::Flags;
using Result = Gio::Converter::Result;

namespace Gio
{

}

namespace
{
}

auto
Glib::Value<Gio::Converter::Result>::value_type () -> GType
{
  return g_converter_result_get_type ();
}

auto
Glib::Value<Gio::Converter::Flags>::value_type () -> GType
{
  return g_converter_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GConverter* object, const bool take_copy) -> RefPtr<Gio::Converter>
  {
    return Glib::make_refptr_for_instance<Gio::Converter> (
        Glib::wrap_auto_interface<Gio::Converter> ((GObject*) object,
                                                   take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  Converter_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Converter_Class::iface_init_function;

      gtype_ = g_converter_get_type ();
    }

    return *this;
  }

  auto
  Converter_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->convert = &convert_vfunc_callback;
    klass->reset = &reset_vfunc_callback;
  }

  auto
  Converter_Class::convert_vfunc_callback (GConverter* self,
                                           const void* inbuf,
                                           const gsize inbuf_size,
                                           void* outbuf,
                                           const gsize outbuf_size,
                                           GConverterFlags flags,
                                           gsize* bytes_read,
                                           gsize* bytes_written,
                                           GError** error) -> GConverterResult
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
          return static_cast<GConverterResult> (
              obj->convert_vfunc (inbuf,
                                  inbuf_size,
                                  outbuf,
                                  outbuf_size,
                                  static_cast<Flags> (flags),
                                  *bytes_read,
                                  *bytes_written));
        }
        catch (Glib::Error& errormm)
        {
          errormm.propagate (error);
          using RType = GConverterResult;
          return RType ();
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

    if (base && base->convert)
      return (*base->convert) (self,
                               inbuf,
                               inbuf_size,
                               outbuf,
                               outbuf_size,
                               flags,
                               bytes_read,
                               bytes_written,
                               error);

    using RType = GConverterResult;
    return RType ();
  }

  auto
  Converter_Class::reset_vfunc_callback (GConverter* self) -> void
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
          obj->reset_vfunc ();
          return;
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

    if (base && base->reset)
      (*base->reset) (self);
  }

  auto
  Converter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Converter ((GConverter*) object);
  }

  Converter::Converter ()
    : Interface (converter_class_.init ())
  {
  }

  Converter::Converter (GConverter* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Converter::Converter (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Converter::Converter (Converter&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Converter::operator= (Converter&& src) noexcept -> Converter&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Converter::~Converter () noexcept = default;

  auto
  Converter::add_interface (const GType gtype_implementer) -> void
  {
    converter_class_.init ().add_interface (gtype_implementer);
  }

  Converter::CppClassType Converter::converter_class_;

  auto
  Converter::get_type () -> GType
  {
    return converter_class_.init ().get_type ();
  }

  auto
  Converter::get_base_type () -> GType
  {
    return g_converter_get_type ();
  }

  auto
  Converter::convert (const void* inbuf,
                      const gsize inbuf_size,
                      void* outbuf,
                      const gsize outbuf_size,
                      Flags flags,
                      gsize& bytes_read,
                      gsize& bytes_written) -> Result
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<Result> (
        g_converter_convert (gobj (),
                             inbuf,
                             inbuf_size,
                             outbuf,
                             outbuf_size,
                             static_cast<GConverterFlags> (flags),
                             &bytes_read,
                             &bytes_written,
                             &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Converter::reset () -> void
  {
    g_converter_reset (gobj ());
  }

  auto
  Converter::convert_vfunc (const void* inbuf,
                            const gsize inbuf_size,
                            void* outbuf,
                            const gsize outbuf_size,
                            Flags flags,
                            gsize& bytes_read,
                            gsize& bytes_written) -> Result
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->convert)
    {
      GError* gerror = nullptr;
      const Result retval (static_cast<Result> (
          (*base->convert) (gobj (),
                            inbuf,
                            inbuf_size,
                            outbuf,
                            outbuf_size,
                            static_cast<GConverterFlags> (flags),
                            &bytes_read,
                            &bytes_written,
                            &gerror)));
      if (gerror)
        Glib::Error::throw_exception (gerror);
      return retval;
    }

    using RType = Result;
    return RType ();
  }

  auto
  Converter::reset_vfunc () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->reset)
    {
      (*base->reset) (gobj ());
    }
  }

} // namespace Gio
