


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/initable.hpp>
#include <libmm-gio/initable_p.hpp>


/* Copyright (C) 2009 Jonathon Jongsma
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
#include <libmm-glib/error.hpp>
#include <libmm-glib/exceptionhandler.hpp>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GInitable* object, const bool take_copy) -> RefPtr<Gio::Initable>
{
  return Glib::make_refptr_for_instance<Gio::Initable>( Glib::wrap_auto_interface<Gio::Initable> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto Initable_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Initable_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_initable_get_type();
  }

  return *this;
}

auto Initable_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->init = &init_vfunc_callback;

}

auto Initable_Class::init_vfunc_callback(GInitable* self, GCancellable* cancellable, GError** error) -> gboolean
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
        return obj->init_vfunc(Glib::wrap(cancellable)
                               , error);
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
  if(base && base->init)
    return (*base->init)(self, cancellable, error);

  using RType = gboolean;
  return RType();
}


auto Initable_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Initable((GInitable*)object);
}


/* The implementation: */

Initable::Initable()
: Interface(initable_class_.init())
{}

Initable::Initable(GInitable* castitem)
: Interface((GObject*)castitem)
{}

Initable::Initable(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Initable::Initable(Initable&& src) noexcept
: Interface(std::move(src))
{}

auto Initable::operator=(Initable&& src) noexcept -> Initable&
{
  Interface::operator=(std::move(src));
  return *this;
}

Initable::~Initable() noexcept = default;

// static
auto Initable::add_interface (
  const GType gtype_implementer) -> void
{
  initable_class_.init().add_interface(gtype_implementer);
}

Initable::CppClassType Initable::initable_class_; // initialize static member

auto Initable::get_type() -> GType
{
  return initable_class_.init().get_type();
}


auto Initable::get_base_type() -> GType
{
  return g_initable_get_type();
}


auto Initable::init (const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  GError* gerror = nullptr;
  g_initable_init(gobj(), Glib::unwrap(cancellable), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto Initable::init () -> void
{
  GError* gerror = nullptr;
  g_initable_init(gobj(), nullptr, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}


auto Initable::init_vfunc(const Glib::RefPtr<Cancellable>& cancellable, GError** error) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->init)
  {
    const bool retval((*base->init)(gobj(),Glib::unwrap(cancellable),error));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gio


