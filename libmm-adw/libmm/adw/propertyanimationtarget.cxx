// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/propertyanimationtarget.hxx>
#include <libmm/adw/propertyanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>

namespace adw
{

  PropertyAnimationTarget::PropertyAnimationTarget (
      const glib::RefPtr<glib::Object>& object,
      const glib::ustring& property_name)
    : glib::ObjectBase (nullptr),
      AnimationTarget (glib::ConstructParams (
          propertyanimationtarget_class_.init (),
          "object",
          glib::unwrap (object),
          "pspec",
          g_object_class_find_property (G_OBJECT_GET_CLASS (object->gobj ()),
                                        property_name.c_str ()),
          nullptr))
  {
  }

} // namespace adw

namespace
{
}

namespace glib
{

  auto
  wrap (AdwPropertyAnimationTarget* object, bool take_copy) -> glib::RefPtr<adw::PropertyAnimationTarget>
  {
    return glib::make_refptr_for_instance<adw::PropertyAnimationTarget> (
        dynamic_cast<adw::PropertyAnimationTarget*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  PropertyAnimationTarget_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_property_animation_target_get_type ();
    }

    return *this;
  }

  auto
  PropertyAnimationTarget_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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
      const glib::RefPtr<glib::Object>& object,
      GParamSpec* pspec)
    : glib::ObjectBase (nullptr),
      AnimationTarget (
          glib::ConstructParams (propertyanimationtarget_class_.init (),
                                 "object",
                                 glib::unwrap (object),
                                 "pspec",
                                 pspec,
                                 nullptr))
  {
  }

  PropertyAnimationTarget::PropertyAnimationTarget ()
    : glib::ObjectBase (nullptr),
      AnimationTarget (
          glib::ConstructParams (propertyanimationtarget_class_.init ()))
  {
  }

  auto
  PropertyAnimationTarget::create (const glib::RefPtr<glib::Object>& object,
                                   const glib::ustring& property_name) -> glib::RefPtr<PropertyAnimationTarget>
  {
    return glib::make_refptr_for_instance<PropertyAnimationTarget> (
        new PropertyAnimationTarget (object, property_name));
  }

  auto
  PropertyAnimationTarget::create (const glib::RefPtr<glib::Object>& object,
                                   GParamSpec* pspec) -> glib::RefPtr<PropertyAnimationTarget>
  {
    return glib::make_refptr_for_instance<PropertyAnimationTarget> (
        new PropertyAnimationTarget (object, pspec));
  }

  auto
  PropertyAnimationTarget::get_object () const -> glib::RefPtr<glib::Object>
  {
    auto retvalue = glib::wrap (adw_property_animation_target_get_object (
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::Object>>::value,
      "Type glib::RefPtr<glib::Object> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PropertyAnimationTarget::property_object () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Object>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Object>> (this,
                                                                     "object");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GParamSpec*>::value,
      "Type GParamSpec* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PropertyAnimationTarget::property_pspec () const -> glib::PropertyProxy_ReadOnly<GParamSpec*>
  {
    return glib::PropertyProxy_ReadOnly<GParamSpec*> (this, "pspec");
  }

} // namespace adw
