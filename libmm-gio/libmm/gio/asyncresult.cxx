// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/asyncresult_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  static auto
  unwrap_objectbase_custom (const glib::RefPtr<glib::ObjectBase>& cpp_instance) -> GObject*
  {
    return cpp_instance ? cpp_instance->gobj () : nullptr;
  }

  auto
  AsyncResult::get_source_object_base () -> glib::RefPtr<ObjectBase>
  {
    const auto cobj = g_async_result_get_source_object (gobj ());
    const auto cppobj = glib::wrap_auto (cobj);
    return glib::make_refptr_for_instance<ObjectBase> (cppobj);
  }

  auto
  AsyncResult::get_source_object_base () const -> glib::RefPtr<const ObjectBase>
  {
    return const_cast<AsyncResult*> (this)->get_source_object_base ();
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GAsyncResult* object, const bool take_copy) -> RefPtr<gio::AsyncResult>
  {
    return glib::make_refptr_for_instance<gio::AsyncResult> (
        glib::wrap_auto_interface<gio::AsyncResult> ((GObject*) object,
                                                     take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  AsyncResult_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AsyncResult_Class::iface_init_function;

      gtype_ = g_async_result_get_type ();
    }

    return *this;
  }

  auto
  AsyncResult_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_source_object = &get_source_object_vfunc_callback;
    klass->is_tagged = &is_tagged_vfunc_callback;
  }

  auto
  AsyncResult_Class::get_source_object_vfunc_callback (GAsyncResult* self) -> GObject*
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
          return unwrap_objectbase_custom (obj->get_source_object_vfunc ());
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

    if (base && base->get_source_object)
      return (*base->get_source_object) (self);

    using RType = GObject*;
    return RType ();
  }

  auto
  AsyncResult_Class::is_tagged_vfunc_callback (GAsyncResult* self,
                                               const gpointer source_tag) -> gboolean
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
          return obj->is_tagged_vfunc (source_tag);
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

    if (base && base->is_tagged)
      return (*base->is_tagged) (self, source_tag);

    using RType = gboolean;
    return RType ();
  }

  auto
  AsyncResult_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AsyncResult ((GAsyncResult*) object);
  }

  AsyncResult::AsyncResult ()
    : Interface (asyncresult_class_.init ())
  {
  }

  AsyncResult::AsyncResult (GAsyncResult* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  AsyncResult::AsyncResult (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  AsyncResult::AsyncResult (AsyncResult&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  AsyncResult::operator= (AsyncResult&& src) noexcept -> AsyncResult&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  AsyncResult::~AsyncResult () noexcept = default;

  auto
  AsyncResult::add_interface (const GType gtype_implementer) -> void
  {
    asyncresult_class_.init ().add_interface (gtype_implementer);
  }

  AsyncResult::CppClassType AsyncResult::asyncresult_class_;

  auto
  AsyncResult::get_type () -> GType
  {
    return asyncresult_class_.init ().get_type ();
  }

  auto
  AsyncResult::get_base_type () -> GType
  {
    return g_async_result_get_type ();
  }

  auto
  AsyncResult::is_tagged (const gpointer source_tag) const -> bool
  {
    return g_async_result_is_tagged (const_cast<GAsyncResult*> (gobj ()),
                                     source_tag);
  }

  auto
  AsyncResult::get_source_object_vfunc () -> glib::RefPtr<ObjectBase>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_source_object)
    {
      glib::RefPtr<ObjectBase> retval (
          glib::wrap ((*base->get_source_object) (gobj ())));
      return retval;
    }

    using RType = glib::RefPtr<ObjectBase>;
    return {};
  }

  auto
  AsyncResult::is_tagged_vfunc (const gpointer source_tag) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->is_tagged)
    {
      const bool retval ((*base->is_tagged) (gobj (), source_tag));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace gio
