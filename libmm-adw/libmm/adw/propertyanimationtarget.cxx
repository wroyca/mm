// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/propertyanimationtarget.hxx>
#include <libmm/adw/propertyanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>

namespace Adw
{

  PropertyAnimationTarget::PropertyAnimationTarget (
      const Glib::RefPtr<Glib::Object>& object,
      const Glib::ustring& property_name)
    : Glib::ObjectBase (nullptr),
      AnimationTarget (Glib::ConstructParams (
          propertyanimationtarget_class_.init (),
          "object",
          Glib::unwrap (object),
          "pspec",
          g_object_class_find_property (G_OBJECT_GET_CLASS (object->gobj ()),
                                        property_name.c_str ()),
          nullptr))
  {
  }

} // namespace Adw

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwPropertyAnimationTarget* object, bool take_copy) -> Glib::RefPtr<Adw::PropertyAnimationTarget>
  {
    return Glib::make_refptr_for_instance<Adw::PropertyAnimationTarget> (
        dynamic_cast<Adw::PropertyAnimationTarget*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  PropertyAnimationTarget_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_property_animation_target_get_type ();
    }

    return *this;
  }

  auto
  PropertyAnimationTarget_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PropertyAnimationTarget ((AdwPropertyAnimationTarget*) object);
  }

  auto
  PropertyAnimationTarget::gobj_copy () -> AdwPropertyAnimationTarget*
  {
    reference ();
    return gobj ();
  }

  PropertyAnimationTarget::PropertyAnimationTarget (
      const Glib::ConstructParams& construct_params)
    : AnimationTarget (construct_params)
  {
  }

  PropertyAnimationTarget::PropertyAnimationTarget (
      AdwPropertyAnimationTarget* castitem)
    : AnimationTarget ((AdwAnimationTarget*) (castitem))
  {
  }

  PropertyAnimationTarget::PropertyAnimationTarget (
      PropertyAnimationTarget&& src) noexcept
    : AnimationTarget (std::move (src))
  {
  }

  auto
  PropertyAnimationTarget::operator= (PropertyAnimationTarget&& src) noexcept -> PropertyAnimationTarget&
  {
    AnimationTarget::operator= (std::move (src));
    return *this;
  }

  PropertyAnimationTarget::~PropertyAnimationTarget () noexcept {}

  PropertyAnimationTarget::CppClassType
      PropertyAnimationTarget::propertyanimationtarget_class_;

  auto
  PropertyAnimationTarget::get_type () -> GType
  {
    return propertyanimationtarget_class_.init ().get_type ();
  }

  auto
  PropertyAnimationTarget::get_base_type () -> GType
  {
    return adw_property_animation_target_get_type ();
  }

  PropertyAnimationTarget::PropertyAnimationTarget (
      const Glib::RefPtr<Glib::Object>& object,
      GParamSpec* pspec)
    : Glib::ObjectBase (nullptr),
      AnimationTarget (
          Glib::ConstructParams (propertyanimationtarget_class_.init (),
                                 "object",
                                 Glib::unwrap (object),
                                 "pspec",
                                 pspec,
                                 nullptr))
  {
  }

  PropertyAnimationTarget::PropertyAnimationTarget ()
    : Glib::ObjectBase (nullptr),
      AnimationTarget (
          Glib::ConstructParams (propertyanimationtarget_class_.init ()))
  {
  }

  auto
  PropertyAnimationTarget::create (const Glib::RefPtr<Glib::Object>& object,
                                   const Glib::ustring& property_name) -> Glib::RefPtr<PropertyAnimationTarget>
  {
    return Glib::make_refptr_for_instance<PropertyAnimationTarget> (
        new PropertyAnimationTarget (object, property_name));
  }

  auto
  PropertyAnimationTarget::create (const Glib::RefPtr<Glib::Object>& object,
                                   GParamSpec* pspec) -> Glib::RefPtr<PropertyAnimationTarget>
  {
    return Glib::make_refptr_for_instance<PropertyAnimationTarget> (
        new PropertyAnimationTarget (object, pspec));
  }

  auto
  PropertyAnimationTarget::get_object () const -> Glib::RefPtr<Glib::Object>
  {
    auto retvalue = Glib::wrap (adw_property_animation_target_get_object (
        const_cast<AdwPropertyAnimationTarget*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PropertyAnimationTarget::get_pspec () const -> GParamSpec*
  {
    return adw_property_animation_target_get_pspec (
        const_cast<AdwPropertyAnimationTarget*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::Object>>::value,
      "Type Glib::RefPtr<Glib::Object> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PropertyAnimationTarget::property_object () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::Object>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::Object>> (this,
                                                                     "object");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GParamSpec*>::value,
      "Type GParamSpec* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PropertyAnimationTarget::property_pspec () const -> Glib::PropertyProxy_ReadOnly<GParamSpec*>
  {
    return Glib::PropertyProxy_ReadOnly<GParamSpec*> (this, "pspec");
  }

} // namespace Adw
