// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/animation.hxx>
#include <libmm/adw/animation_p.hxx>

#include <adwaita.h>
#include <libmm/adw/animationtarget.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo Animation_signal_done_info = {
      "done",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

auto
Glib::Value<Adw::AnimationState>::value_type () -> GType
{
  return adw_animation_state_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwAnimation* object, bool take_copy) -> Glib::RefPtr<Adw::Animation>
  {
    return Glib::make_refptr_for_instance<Adw::Animation> (
        dynamic_cast<Adw::Animation*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  Animation_Class::init () -> const Glib::Class&
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
  Animation_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Animation ((AdwAnimation*) object);
  }

  auto
  Animation::gobj_copy () -> AdwAnimation*
  {
    reference ();
    return gobj ();
  }

  Animation::Animation (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  Animation::Animation (AdwAnimation* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  Animation::Animation (Animation&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  Animation::operator= (Animation&& src) noexcept -> Animation&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (animation_class_.init ()))
  {
  }

  auto
  Animation::create () -> Glib::RefPtr<Animation>
  {
    return Glib::make_refptr_for_instance<Animation> (new Animation ());
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
  Animation::get_target () const -> Glib::RefPtr<AnimationTarget>
  {
    auto retvalue = Glib::wrap (
        adw_animation_get_target (const_cast<AdwAnimation*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Animation::get_widget () const -> Gtk::Widget*
  {
    return Glib::wrap (
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
  Animation::set_target (Glib::RefPtr<AnimationTarget> target) -> void
  {
    adw_animation_set_target (gobj (),
                              (AdwAnimationTarget*) Glib::unwrap (target));
  }

  auto
  Animation::skip () -> void
  {
    adw_animation_skip (gobj ());
  }

  auto
  Animation::signal_done () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Animation_signal_done_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<AnimationState>::value,
      "Type AnimationState cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Animation::property_state () const -> Glib::PropertyProxy_ReadOnly<AnimationState>
  {
    return Glib::PropertyProxy_ReadOnly<AnimationState> (this, "state");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<AnimationTarget>>::value,
      "Type Glib::RefPtr<AnimationTarget> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Animation::property_target () -> Glib::PropertyProxy<Glib::RefPtr<AnimationTarget>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<AnimationTarget>> (this, "target");
  }

  auto
  Animation::property_target () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<AnimationTarget>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<AnimationTarget>> (
        this,
        "target");
  }

  auto
  Animation::property_value () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "value");
  }

  auto
  Animation::property_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "widget");
  }

} // namespace Adw
