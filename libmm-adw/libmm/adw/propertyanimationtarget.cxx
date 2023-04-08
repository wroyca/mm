// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/propertyanimationtarget.hxx>
#include <libmm/adw/propertyanimationtarget_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>

namespace adw
{

  property_animation_target::property_animation_target (
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
  wrap (AdwPropertyAnimationTarget* object, bool take_copy) -> glib::RefPtr<adw::property_animation_target>
  {
    return glib::make_refptr_for_instance<adw::property_animation_target> (
        dynamic_cast<adw::property_animation_target*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  property_animation_target_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_property_animation_target_get_type ();
    }

    return *this;
  }

  auto
  property_animation_target_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new property_animation_target ((AdwPropertyAnimationTarget*) object);
  }

  auto
  property_animation_target::gobj_copy () -> AdwPropertyAnimationTarget*
  {
    reference ();
    return gobj ();
  }

  property_animation_target::property_animation_target (
      const glib::ConstructParams& construct_params)
    : AnimationTarget (construct_params)
  {
  }

  property_animation_target::property_animation_target (
      AdwPropertyAnimationTarget* castitem)
    : AnimationTarget ((AdwAnimationTarget*) (castitem))
  {
  }

  property_animation_target::property_animation_target (
      property_animation_target&& src) noexcept
    : AnimationTarget (std::move (src))
  {
  }

  auto
  property_animation_target::operator= (property_animation_target&& src) noexcept -> property_animation_target&
  {
    AnimationTarget::operator= (std::move (src));
    return *this;
  }

  property_animation_target::~property_animation_target () noexcept {}

  property_animation_target::CppClassType
      property_animation_target::propertyanimationtarget_class_;

  auto
  property_animation_target::get_type () -> GType
  {
    return propertyanimationtarget_class_.init ().get_type ();
  }

  auto
  property_animation_target::get_base_type () -> GType
  {
    return adw_property_animation_target_get_type ();
  }

  property_animation_target::property_animation_target (
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

  property_animation_target::property_animation_target ()
    : glib::ObjectBase (nullptr),
      AnimationTarget (
          glib::ConstructParams (propertyanimationtarget_class_.init ()))
  {
  }

  auto
  property_animation_target::create (const glib::RefPtr<glib::Object>& object,
                                   const glib::ustring& property_name) -> glib::RefPtr<property_animation_target>
  {
    return glib::make_refptr_for_instance<property_animation_target> (
        new property_animation_target (object, property_name));
  }

  auto
  property_animation_target::create (const glib::RefPtr<glib::Object>& object,
                                   GParamSpec* pspec) -> glib::RefPtr<property_animation_target>
  {
    return glib::make_refptr_for_instance<property_animation_target> (
        new property_animation_target (object, pspec));
  }

  auto
  property_animation_target::get_object () const -> glib::RefPtr<glib::Object>
  {
    auto retvalue = glib::wrap (adw_property_animation_target_get_object (
        const_cast<AdwPropertyAnimationTarget*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  property_animation_target::get_pspec () const -> GParamSpec*
  {
    return adw_property_animation_target_get_pspec (
        const_cast<AdwPropertyAnimationTarget*> (gobj ()));
  }

  auto
  property_animation_target::property_object () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Object>>
  {
    return {this, "object"};
  }

  auto
  property_animation_target::property_pspec () const -> glib::PropertyProxy_ReadOnly<GParamSpec*>
  {
    return {this, "pspec"};
  }

} // namespace adw
