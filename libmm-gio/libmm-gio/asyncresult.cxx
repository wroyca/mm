


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/asyncresult_p.hxx>


/* Copyright (C) 2007 The giomm Development Team
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

//#include <gio/gasyncresult.h> //We are not allowed to include individual headers.
#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{

static auto
unwrap_objectbase_custom(const Glib::RefPtr<Glib::ObjectBase>& cpp_instance) -> GObject*
{
  return cpp_instance ? cpp_instance->gobj() : nullptr;
}

auto
AsyncResult::get_source_object_base() -> Glib::RefPtr<ObjectBase>
{
  // Glib::wrap(cobj) can't be used here. See tests/giomm_asyncresult_sourceobject
  // for a case where it would fail, and an explanation of why.
  // In short, the source object is not necessarily a Glib::Object. It may be
  // a Glib::Interface.

  const auto cobj = g_async_result_get_source_object(gobj());
  const auto cppobj = Glib::wrap_auto(cobj); // ObjectBase::_get_current_wrapper(cobj);
  return Glib::make_refptr_for_instance<ObjectBase>(
    cppobj); // g_async_result_get_source_object() gives us a ref, unusually.
}

auto
AsyncResult::get_source_object_base() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<AsyncResult*>(this)->get_source_object_base();
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GAsyncResult* object, const bool take_copy) -> RefPtr<Gio::AsyncResult>
{
  return Glib::make_refptr_for_instance<Gio::AsyncResult>( Glib::wrap_auto_interface<Gio::AsyncResult> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto AsyncResult_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &AsyncResult_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_async_result_get_type();
  }

  return *this;
}

auto AsyncResult_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_source_object = &get_source_object_vfunc_callback;
  klass->is_tagged = &is_tagged_vfunc_callback;

}

auto AsyncResult_Class::get_source_object_vfunc_callback(GAsyncResult* self) -> GObject*
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
        return unwrap_objectbase_custom(obj->get_source_object_vfunc());
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
  if(base && base->get_source_object)
    return (*base->get_source_object)(self);

  using RType = GObject*;
  return RType();
}
auto AsyncResult_Class::is_tagged_vfunc_callback(GAsyncResult* self, const gpointer source_tag) -> gboolean
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
        return obj->is_tagged_vfunc(source_tag);
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
  if(base && base->is_tagged)
    return (*base->is_tagged)(self, source_tag);

  using RType = gboolean;
  return RType();
}


auto AsyncResult_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AsyncResult((GAsyncResult*)object);
}


/* The implementation: */

AsyncResult::AsyncResult()
: Interface(asyncresult_class_.init())
{}

AsyncResult::AsyncResult(GAsyncResult* castitem)
: Interface((GObject*)castitem)
{}

AsyncResult::AsyncResult(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

AsyncResult::AsyncResult(AsyncResult&& src) noexcept
: Interface(std::move(src))
{}

auto AsyncResult::operator=(AsyncResult&& src) noexcept -> AsyncResult&
{
  Interface::operator=(std::move(src));
  return *this;
}

AsyncResult::~AsyncResult() noexcept = default;

// static
auto AsyncResult::add_interface (
  const GType gtype_implementer) -> void
{
  asyncresult_class_.init().add_interface(gtype_implementer);
}

AsyncResult::CppClassType AsyncResult::asyncresult_class_; // initialize static member

auto AsyncResult::get_type() -> GType
{
  return asyncresult_class_.init().get_type();
}


auto AsyncResult::get_base_type() -> GType
{
  return g_async_result_get_type();
}


auto AsyncResult::is_tagged(
  const gpointer source_tag) const -> bool
{
  return g_async_result_is_tagged(const_cast<GAsyncResult*>(gobj()), source_tag);
}


auto AsyncResult::get_source_object_vfunc() -> Glib::RefPtr<ObjectBase>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->get_source_object)
  {
    Glib::RefPtr<ObjectBase> retval(Glib::wrap((*base->get_source_object)(gobj())));
    return retval;
  }

  using RType = Glib::RefPtr<ObjectBase>;
  return {};
}
auto AsyncResult::is_tagged_vfunc(
  const gpointer source_tag) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->is_tagged)
  {
    const bool retval((*base->is_tagged)(gobj(),source_tag));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gio


