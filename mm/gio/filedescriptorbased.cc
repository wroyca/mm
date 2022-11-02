/* Copyright (C) 2017 The giomm Development Team
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

#ifndef _WIN32

#include <mm/glib/mm-glib.h>

#include <mm/gio/filedescriptorbased.h>
#include <mm/gio/private/filedescriptorbased_p.h>

#include <gio/gio.h>
#include <gio/gfiledescriptorbased.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFileDescriptorBased* object, bool take_copy) -> Glib::RefPtr<Gio::FileDescriptorBased>
{
  return Glib::make_refptr_for_instance<Gio::FileDescriptorBased>( dynamic_cast<Gio::FileDescriptorBased*> (Glib::wrap_auto_interface<Gio::FileDescriptorBased> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto FileDescriptorBased_Class::init() -> const Glib::Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &FileDescriptorBased_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_file_descriptor_based_get_type();
  }

  return *this;
}

void FileDescriptorBased_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_fd = &get_fd_vfunc_callback;

}

auto FileDescriptorBased_Class::get_fd_vfunc_callback(GFileDescriptorBased* self) -> int
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
        return obj->get_fd_vfunc();
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
  if(base && base->get_fd)
    return (*base->get_fd)(self);

  using RType = int;
  return RType();
}


auto FileDescriptorBased_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileDescriptorBased((GFileDescriptorBased*)(object));
}


/* The implementation: */

FileDescriptorBased::FileDescriptorBased()
:
  Glib::Interface(filedescriptorbased_class_.init())
{}

FileDescriptorBased::FileDescriptorBased(GFileDescriptorBased* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

FileDescriptorBased::FileDescriptorBased(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

FileDescriptorBased::FileDescriptorBased(FileDescriptorBased&& src) noexcept
: Glib::Interface(std::move(src))
{}

auto FileDescriptorBased::operator=(FileDescriptorBased&& src) noexcept -> FileDescriptorBased&
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

FileDescriptorBased::~FileDescriptorBased() noexcept
{}

// static
void FileDescriptorBased::add_interface(GType gtype_implementer)
{
  filedescriptorbased_class_.init().add_interface(gtype_implementer);
}

FileDescriptorBased::CppClassType FileDescriptorBased::filedescriptorbased_class_; // initialize static member

auto FileDescriptorBased::get_type() -> GType
{
  return filedescriptorbased_class_.init().get_type();
}


auto FileDescriptorBased::get_base_type() -> GType
{
  return g_file_descriptor_based_get_type();
}


auto FileDescriptorBased::get_fd() const -> int
{
  return g_file_descriptor_based_get_fd(const_cast<GFileDescriptorBased*>(gobj()));
}


auto Gio::FileDescriptorBased::get_fd_vfunc() const -> int
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->get_fd)
  {
    int retval((*base->get_fd)(const_cast<GFileDescriptorBased*>(gobj())));
    return retval;
  }

  using RType = int;
  return RType();
}


} // namespace Gio

#endif // _WIN32
