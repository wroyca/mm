// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/seekable.h>
#include <giomm/private/seekable_p.h>


/* Copyright (C) 2007 The gtkmm Development Team
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

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::Seekable> wrap(GSeekable* object, bool take_copy)
{
  return Glib::make_refptr_for_instance<Gio::Seekable>( dynamic_cast<Gio::Seekable*> (Glib::wrap_auto_interface<Gio::Seekable> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

const Glib::Interface_Class& Seekable_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Seekable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_seekable_get_type();
  }

  return *this;
}

void Seekable_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


Glib::ObjectBase* Seekable_Class::wrap_new(GObject* object)
{
  return new Seekable((GSeekable*)(object));
}


/* The implementation: */

Seekable::Seekable()
:
  Glib::Interface(seekable_class_.init())
{}

Seekable::Seekable(GSeekable* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

Seekable::Seekable(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

Seekable::Seekable(Seekable&& src) noexcept
: Glib::Interface(std::move(src))
{}

Seekable& Seekable::operator=(Seekable&& src) noexcept
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

Seekable::~Seekable() noexcept
{}

// static
void Seekable::add_interface(GType gtype_implementer)
{
  seekable_class_.init().add_interface(gtype_implementer);
}

Seekable::CppClassType Seekable::seekable_class_; // initialize static member

GType Seekable::get_type()
{
  return seekable_class_.init().get_type();
}


GType Seekable::get_base_type()
{
  return g_seekable_get_type();
}


goffset Seekable::tell() const
{
  return g_seekable_tell(const_cast<GSeekable*>(gobj()));
}

bool Seekable::can_seek() const
{
  return g_seekable_can_seek(const_cast<GSeekable*>(gobj()));
}

bool Seekable::seek(goffset offset, Glib::SeekType type, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_seekable_seek(gobj(), offset, static_cast<GSeekType>(type), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool Seekable::seek(goffset offset, Glib::SeekType type)
{
  GError* gerror = nullptr;
  auto retvalue = g_seekable_seek(gobj(), offset, static_cast<GSeekType>(type), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool Seekable::can_truncate() const
{
  return g_seekable_can_truncate(const_cast<GSeekable*>(gobj()));
}

bool Seekable::truncate(goffset offset, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  auto retvalue = g_seekable_truncate(gobj(), offset, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool Seekable::truncate(goffset offset)
{
  GError* gerror = nullptr;
  auto retvalue = g_seekable_truncate(gobj(), offset, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


