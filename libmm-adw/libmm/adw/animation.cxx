// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/animation.hxx>
#include <libmm/adw/animation_p.hxx>

#include <adwaita.h>
#include <libmm/adw/animationtarget.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo Animation_signal_done_info = {
      "done",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

auto
glib::Value<adw::AnimationState>::value_type () -> GType
{
  return adw_animation_state_get_type ();
}

namespace glib
{

  auto
  wrap (AdwAnimation* object, bool take_copy) -> glib::RefPtr<adw::Animation>
  {
    return glib::make_refptr_for_instance<adw::Animation> (
        dynamic_cast<adw::Animation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  Animation_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Animation_Class::class_init_function;

      register_derived_type (adw_animation_get_type ());
    }

    return *this;
  }

  auto
  Animation_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Animation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Animation ((AdwAnimation*) object);
  }

  auto
  Animation::gobj_copy () -> AdwAnimation*
  {
    reference ();
    return gobj ();
  }

  Animation::Animation (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  Animation::Animation (AdwAnimation* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  Animation::Animation (Animation&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  Animation::operator= (Animation&& src) noexcept -> Animation&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  Animation::~Animation () noexcept {}

  Animation::CppClassType Animation::animation_class_;

  auto
  Animation::get_type () -> GType
  {
    return animation_class_.init ().get_type ();
  }

  auto
  Animation::get_base_type () -> GType
  {
    return adw_animation_get_type ();
  }

  Animation::Animation ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (animation_class_.init ()))
  {
  }

  auto
  Animation::create () -> glib::RefPtr<Animation>
  {
    return glib::make_refptr_for_instance<Animation> (new Animation ());
  }

  auto
  Animation::get_state () const -> AnimationState
  {
    return static_cast<AnimationState> (
        adw_animation_get_state (const_cast<AdwAnimation*> (gobj ())));
  }

  auto
  Animation::get_value () const -> double
  {
    return adw_animation_get_value (const_cast<AdwAnimation*> (gobj ()));
  }

  auto
  Animation::get_target () const -> glib::RefPtr<AnimationTarget>
  {
    auto retvalue = glib::wrap (
        adw_animation_get_target (const_cast<AdwAnimation*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Animation::get_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_animation_get_widget (const_cast<AdwAnimation*> (gobj ())));
  }

  auto
  Animation::pause () -> void
  {
    adw_animation_pause (gobj ());
  }

  auto
  Animation::play () -> void
  {
    adw_animation_play (gobj ());
  }

  auto
  Animation::reset () -> void
  {
    adw_animation_reset (gobj ());
  }

  auto
  Animation::resume () -> void
  {
    adw_animation_resume (gobj ());
  }

  auto
  Animation::set_target (glib::RefPtr<AnimationTarget> target) -> void
  {
    adw_animation_set_target (gobj (),
                              (AdwAnimationTarget*) glib::unwrap (target));
  }

  auto
  Animation::skip () -> void
  {
    adw_animation_skip (gobj ());
  }

  auto
  Animation::signal_done () -> glib::SignalProxy<void ()>
  {
    return {this, &Animation_signal_done_info};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<AnimationState>::value,
      "Type AnimationState cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Animation::property_state () const -> glib::PropertyProxy_ReadOnly<AnimationState>
  {
    return {this, "state"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<AnimationTarget>>::value,
      "Type glib::RefPtr<AnimationTarget> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Animation::property_target () -> glib::PropertyProxy<glib::RefPtr<AnimationTarget>>
  {
    return {this, "target"};
  }

  auto
  Animation::property_target () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<AnimationTarget>>
  {
    return {this, "target"};
  }

  auto
  Animation::property_value () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value"};
  }

  auto
  Animation::property_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "widget"};
  }

} // namespace adw
