// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/converter.hpp>
#include <mm/gio/private/converter_p.hpp>


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

using Flags = Gio::Converter::Flags;
using Result = Gio::Converter::Result;

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gio::Converter::Result>::value_type() -> GType
{
  return g_converter_result_get_type();
}

// static
auto Glib::Value<Gio::Converter::Flags>::value_type() -> GType
{
  return g_converter_flags_get_type();
}


namespace Glib
{

auto wrap(GConverter* object, bool take_copy) -> Glib::RefPtr<Gio::Converter>
{
  return Glib::make_refptr_for_instance<Gio::Converter>( dynamic_cast<Gio::Converter*> (Glib::wrap_auto_interface<Gio::Converter> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto Converter_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Converter_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_converter_get_type();
  }

  return *this;
}

void Converter_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->convert = &convert_vfunc_callback;
  klass->reset = &reset_vfunc_callback;

}

auto Converter_Class::convert_vfunc_callback(GConverter* self, const void* inbuf, gsize inbuf_size, void* outbuf, gsize outbuf_size, GConverterFlags flags, gsize* bytes_read, gsize* bytes_written, GError** error) -> GConverterResult
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
        return static_cast<GConverterResult>(obj->convert_vfunc(inbuf, inbuf_size, outbuf, outbuf_size, static_cast<Flags>(flags)
, *(bytes_read)
, *(bytes_written)
));
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        using RType = GConverterResult;
        return RType();
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
  if(base && base->convert)
    return (*base->convert)(self, inbuf, inbuf_size, outbuf, outbuf_size, flags, bytes_read, bytes_written, error);

  using RType = GConverterResult;
  return RType();
}
void Converter_Class::reset_vfunc_callback(GConverter* self)
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
        obj->reset_vfunc();
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
  if(base && base->reset)
    (*base->reset)(self);
}


auto Converter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Converter((GConverter*)(object));
}


/* The implementation: */

Converter::Converter()
:
  Glib::Interface(converter_class_.init())
{}

Converter::Converter(GConverter* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Converter::Converter(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Converter::Converter(Converter&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto Converter::operator=(Converter&& src) noexcept -> Converter&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Converter::~Converter() noexcept
{}

// static
void Converter::add_interface(GType gtype_implementer)
{
  converter_class_.init().add_interface(gtype_implementer);
}

Converter::CppClassType Converter::converter_class_; // initialize static member

auto Converter::get_type() -> GType
{
  return converter_class_.init().get_type();
}


auto Converter::get_base_type() -> GType
{
  return g_converter_get_type();
}


auto Converter::convert(const void* inbuf, gsize inbuf_size, void* outbuf, gsize outbuf_size, Flags flags, gsize& bytes_read, gsize& bytes_written) -> Result
{
  GError* gerror = nullptr;
  auto retvalue = static_cast<Result>(g_converter_convert(gobj(), inbuf, inbuf_size, outbuf, outbuf_size, static_cast<GConverterFlags>(flags), &(bytes_read), &(bytes_written), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void Converter::reset()
{
  g_converter_reset(gobj());
}


auto Gio::Converter::convert_vfunc(const void* inbuf, gsize inbuf_size, void* outbuf, gsize outbuf_size, Flags flags, gsize& bytes_read, gsize& bytes_written) -> Result
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->convert)
  {
    GError* gerror = nullptr;
    Result retval(static_cast<Result>((*base->convert)(gobj(),inbuf,inbuf_size,outbuf,outbuf_size,static_cast<GConverterFlags>(flags),&(bytes_read),&(bytes_written),&(gerror))));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = Result;
  return RType();
}
void Gio::Converter::reset_vfunc()
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->reset)
  {
    (*base->reset)(gobj());
  }
}


} // namespace Gio

