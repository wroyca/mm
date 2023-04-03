// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/binding.hxx>
#include <libmm/glib/binding_p.hxx>

using Flags = Glib::Binding::Flags;

#include <glib.h>
#include <libmm/glib/binding.hxx>

namespace
{
  struct BindingTransformSlots
  {
    BindingTransformSlots (const Glib::Binding::SlotTransform& transform_to,
                           const Glib::Binding::SlotTransform& transform_from)
      : from_source_to_target (transform_to),
        from_target_to_source (transform_from)
    {
    }

    Glib::Binding::SlotTransform from_source_to_target;
    Glib::Binding::SlotTransform from_target_to_source;
  };

  auto
  Binding_transform_callback_common (const GValue* from_value,
                                     GValue* to_value,
                                     Glib::Binding::SlotTransform& the_slot) -> gboolean
  {
    bool result = false;
    try
    {
      result = the_slot (from_value, to_value);
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return result;
  }

  auto
  Binding_transform_to_callback (GBinding*,
                                 const GValue* from_value,
                                 GValue* to_value,
                                 const gpointer user_data) -> gboolean
  {
    Glib::Binding::SlotTransform& the_slot =
        static_cast<BindingTransformSlots*> (user_data)->from_source_to_target;

    return Binding_transform_callback_common (from_value, to_value, the_slot);
  }

  auto
  Binding_transform_from_callback (GBinding*,
                                   const GValue* from_value,
                                   GValue* to_value,
                                   const gpointer user_data) -> gboolean
  {
    Glib::Binding::SlotTransform& the_slot =
        static_cast<BindingTransformSlots*> (user_data)->from_target_to_source;

    return Binding_transform_callback_common (from_value, to_value, the_slot);
  }

  auto
  Binding_transform_callback_destroy (const gpointer user_data) -> void
  {
    delete static_cast<BindingTransformSlots*> (user_data);
  }

} // namespace

namespace Glib
{

  auto
  Binding::bind_property_value (const PropertyProxy_Base& source_property,
                                const PropertyProxy_Base& target_property,
                                Flags flags,
                                const SlotTransform& transform_to,
                                const SlotTransform& transform_from) -> RefPtr<Binding>
  {
    GBinding* binding = nullptr;
    if (transform_to.empty () && transform_from.empty ())
    {
      binding = g_object_bind_property (source_property.get_object ()->gobj (),
                                        source_property.get_name (),
                                        target_property.get_object ()->gobj (),
                                        target_property.get_name (),
                                        (GBindingFlags) flags);
    }
    else
    {
      BindingTransformSlots* slots_copy =
          new BindingTransformSlots (transform_to, transform_from);

      binding = g_object_bind_property_full (
          source_property.get_object ()->gobj (),
          source_property.get_name (),
          target_property.get_object ()->gobj (),
          target_property.get_name (),
          (GBindingFlags) flags,
          transform_to.empty () ? nullptr : &Binding_transform_to_callback,
          transform_from.empty () ? nullptr : &Binding_transform_from_callback,
          slots_copy,
          &Binding_transform_callback_destroy);
    }

    if (!binding)
      return {};

    g_object_ref (binding);
    return Glib::make_refptr_for_instance<Binding> (new Binding (binding));
  }

  auto
  Binding::unbind () -> void
  {
    GObject* source = g_binding_dup_source (gobj ());
    if (source)
    {
      g_binding_unbind (gobj ());
      g_object_unref (source);
    }
  }

} // namespace Glib

namespace
{
}

auto
Glib::Value<Glib::Binding::Flags>::value_type () -> GType
{
  return g_binding_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GBinding* object, const bool take_copy) -> RefPtr<Binding>
  {
    return Glib::make_refptr_for_instance<Binding> (
        dynamic_cast<Binding*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Glib
{

  auto
  Binding_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Binding_Class::class_init_function;

      register_derived_type (g_binding_get_type ());
    }

    return *this;
  }

  auto
  Binding_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Binding_Class::wrap_new (GObject* object) -> ObjectBase*
  {
    return new Binding ((GBinding*) object);
  }

  auto
  Binding::gobj_copy () -> GBinding*
  {
    reference ();
    return gobj ();
  }

  Binding::Binding (const ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Binding::Binding (GBinding* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Binding::Binding (Binding&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Binding::operator= (Binding&& src) noexcept -> Binding&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Binding::~Binding () noexcept = default;

  Binding::CppClassType Binding::binding_class_;

  auto
  Binding::get_type () -> GType
  {
    return binding_class_.init ().get_type ();
  }

  auto
  Binding::get_base_type () -> GType
  {
    return g_binding_get_type ();
  }

#ifndef GLIBMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Binding::get_source () -> ObjectBase*
  {
    return wrap_auto (g_binding_get_source (gobj ()));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Binding::get_source () const -> const ObjectBase*
  {
    return const_cast<Binding*> (this)->get_source ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Binding::dup_source () -> RefPtr<ObjectBase>
  {
    return Glib::make_refptr_for_instance<ObjectBase> (
        wrap_auto (g_binding_dup_source (gobj ())));
  }

  auto
  Binding::dup_source () const -> RefPtr<const ObjectBase>
  {
    return const_cast<Binding*> (this)->dup_source ();
  }

  auto
  Binding::get_source_property () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_binding_get_source_property (const_cast<GBinding*> (gobj ())));
  }

#ifndef GLIBMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Binding::get_target () -> ObjectBase*
  {
    return wrap_auto (g_binding_get_target (gobj ()));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GLIBMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Binding::get_target () const -> const ObjectBase*
  {
    return const_cast<Binding*> (this)->get_target ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Binding::dup_target () -> RefPtr<ObjectBase>
  {
    return Glib::make_refptr_for_instance<ObjectBase> (
        wrap_auto (g_binding_dup_target (gobj ())));
  }

  auto
  Binding::dup_target () const -> RefPtr<const ObjectBase>
  {
    return const_cast<Binding*> (this)->dup_target ();
  }

  auto
  Binding::get_target_property () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_binding_get_target_property (const_cast<GBinding*> (gobj ())));
  }

  auto
  Binding::get_flags () const -> Flags
  {
    return static_cast<Flags> (
        g_binding_get_flags (const_cast<GBinding*> (gobj ())));
  }

  static_assert (
      Traits::ValueCompatibleWithWrapProperty<Flags>::value,
      "Type Flags cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Binding::property_flags () const -> PropertyProxy_ReadOnly<Flags>
  {
    return {this, "flags"};
  }

  static_assert (
      Traits::ValueCompatibleWithWrapProperty<RefPtr<ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Binding::property_source () const -> PropertyProxy_ReadOnly<RefPtr<ObjectBase>>
  {
    return {this, "source"};
  }

  auto
  Binding::property_source_property () const -> PropertyProxy_ReadOnly<ustring>
  {
    return {this, "source-property"};
  }

  static_assert (
      Traits::ValueCompatibleWithWrapProperty<RefPtr<ObjectBase>>::value,
      "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Binding::property_target () const -> PropertyProxy_ReadOnly<RefPtr<ObjectBase>>
  {
    return {this, "target"};
  }

  auto
  Binding::property_target_property () const -> PropertyProxy_ReadOnly<ustring>
  {
    return {this, "target-property"};
  }

} // namespace Glib
