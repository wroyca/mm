// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/animationtarget.hxx>
#include <libmm-adw/animationtarget_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwAnimationTarget* object, bool take_copy) -> Glib::RefPtr<Adw::AnimationTarget>
  {
    return Glib::make_refptr_for_instance<Adw::AnimationTarget> (
        dynamic_cast<Adw::AnimationTarget*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  AnimationTarget_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AnimationTarget_Class::class_init_function;

      register_derived_type (adw_animation_target_get_type ());
    }

    return *this;
  }

  auto
  AnimationTarget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AnimationTarget_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AnimationTarget ((AdwAnimationTarget*) object);
  }

  auto
  AnimationTarget::gobj_copy () -> AdwAnimationTarget*
  {
    reference ();
    return gobj ();
  }

  AnimationTarget::AnimationTarget (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  AnimationTarget::AnimationTarget (AdwAnimationTarget* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  AnimationTarget::AnimationTarget (AnimationTarget&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  AnimationTarget::operator= (AnimationTarget&& src) noexcept -> AnimationTarget&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  AnimationTarget::~AnimationTarget () noexcept {}

  AnimationTarget::CppClassType AnimationTarget::animationtarget_class_;

  auto
  AnimationTarget::get_type () -> GType
  {
    return animationtarget_class_.init ().get_type ();
  }

  auto
  AnimationTarget::get_base_type () -> GType
  {
    return adw_animation_target_get_type ();
  }

  AnimationTarget::AnimationTarget ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (animationtarget_class_.init ()))
  {
  }

} // namespace Adw
