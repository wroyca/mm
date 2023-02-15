// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/timedanimation.hxx>
#include <libmm-adw/timedanimation_p.hxx>

#include <libmm-adw/animation.hxx>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwTimedAnimation* object, bool take_copy) -> Glib::RefPtr<Adw::TimedAnimation>
  {
    return Glib::make_refptr_for_instance<Adw::TimedAnimation> (
        dynamic_cast<Adw::TimedAnimation*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  TimedAnimation_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_timed_animation_get_type ();
    }

    return *this;
  }

  auto
  TimedAnimation_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TimedAnimation ((AdwTimedAnimation*) object);
  }

  auto
  TimedAnimation::gobj_copy () -> AdwTimedAnimation*
  {
    reference ();
    return gobj ();
  }

  TimedAnimation::TimedAnimation (const Glib::ConstructParams& construct_params)
    : Animation (construct_params)
  {
  }

  TimedAnimation::TimedAnimation (AdwTimedAnimation* castitem)
    : Animation ((AdwAnimation*) (castitem))
  {
  }

  TimedAnimation::TimedAnimation (TimedAnimation&& src) noexcept
    : Animation (std::move (src))
  {
  }

  auto
  TimedAnimation::operator= (TimedAnimation&& src) noexcept -> TimedAnimation&
  {
    Animation::operator= (std::move (src));
    return *this;
  }

  TimedAnimation::~TimedAnimation () noexcept {}

  TimedAnimation::CppClassType TimedAnimation::timedanimation_class_;

  auto
  TimedAnimation::get_type () -> GType
  {
    return timedanimation_class_.init ().get_type ();
  }

  auto
  TimedAnimation::get_base_type () -> GType
  {
    return adw_timed_animation_get_type ();
  }

  TimedAnimation::TimedAnimation ()
    : Glib::ObjectBase (nullptr),
      Animation (Glib::ConstructParams (timedanimation_class_.init ()))
  {
  }

  TimedAnimation::TimedAnimation (Gtk::Widget* widget,
                                  double value_from,
                                  double value_to,
                                  guint duration,
                                  const Glib::RefPtr<AnimationTarget>& target)
    : Glib::ObjectBase (nullptr),
      Animation (Glib::ConstructParams (timedanimation_class_.init (),
                                        "widget",
                                        (GtkWidget*) Glib::unwrap (widget),
                                        "value_from",
                                        value_from,
                                        "value_to",
                                        value_to,
                                        "duration",
                                        duration,
                                        "target",
                                        Glib::unwrap (target),
                                        nullptr))
  {
  }

  auto
  TimedAnimation::create (Gtk::Widget* widget,
                          double value_from,
                          double value_to,
                          guint duration,
                          const Glib::RefPtr<AnimationTarget>& target) -> Glib::RefPtr<TimedAnimation>
  {
    return Glib::make_refptr_for_instance<TimedAnimation> (
        new TimedAnimation (widget, value_from, value_to, duration, target));
  }

  auto
  TimedAnimation::get_alternate () const -> bool
  {
    return adw_timed_animation_get_alternate (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::get_duration () const -> guint
  {
    return adw_timed_animation_get_duration (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::get_easing () const -> Easing
  {
    return static_cast<Easing> (adw_timed_animation_get_easing (
        const_cast<AdwTimedAnimation*> (gobj ())));
  }

  auto
  TimedAnimation::get_repeat_count () const -> guint
  {
    return adw_timed_animation_get_repeat_count (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::get_reverse () const -> bool
  {
    return adw_timed_animation_get_reverse (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::get_value_from () const -> double
  {
    return adw_timed_animation_get_value_from (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::get_value_to () const -> double
  {
    return adw_timed_animation_get_value_to (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  TimedAnimation::set_alternate (bool alternate) -> void
  {
    adw_timed_animation_set_alternate (gobj (), static_cast<int> (alternate));
  }

  auto
  TimedAnimation::set_duration (guint duration) -> void
  {
    adw_timed_animation_set_duration (gobj (), duration);
  }

  auto
  TimedAnimation::set_easing (Easing easing) -> void
  {
    adw_timed_animation_set_easing (gobj (), static_cast<AdwEasing> (easing));
  }

  auto
  TimedAnimation::set_repeat_count (guint repeat_count) -> void
  {
    adw_timed_animation_set_repeat_count (gobj (), repeat_count);
  }

  auto
  TimedAnimation::set_reverse (bool reverse) -> void
  {
    adw_timed_animation_set_reverse (gobj (), static_cast<int> (reverse));
  }

  auto
  TimedAnimation::set_value_from (double from) const -> void
  {
    adw_timed_animation_set_value_from (
        const_cast<AdwTimedAnimation*> (gobj ()),
        from);
  }

  auto
  TimedAnimation::set_value_to (double to) const -> void
  {
    adw_timed_animation_set_value_to (const_cast<AdwTimedAnimation*> (gobj ()),
                                      to);
  }

  auto
  TimedAnimation::property_alternate () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "alternate");
  }

  auto
  TimedAnimation::property_alternate () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "alternate");
  }

  auto
  TimedAnimation::property_duration () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "duration");
  }

  auto
  TimedAnimation::property_duration () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "duration");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Easing>::value,
      "Type Easing cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TimedAnimation::property_easing () -> Glib::PropertyProxy<Easing>
  {
    return Glib::PropertyProxy<Easing> (this, "easing");
  }

  auto
  TimedAnimation::property_easing () const -> Glib::PropertyProxy_ReadOnly<Easing>
  {
    return Glib::PropertyProxy_ReadOnly<Easing> (this, "easing");
  }

  auto
  TimedAnimation::property_repeat_count () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "repeat-count");
  }

  auto
  TimedAnimation::property_repeat_count () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "repeat-count");
  }

  auto
  TimedAnimation::property_reverse () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "reverse");
  }

  auto
  TimedAnimation::property_reverse () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "reverse");
  }

  auto
  TimedAnimation::property_value_from () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "value-from");
  }

  auto
  TimedAnimation::property_value_from () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "value-from");
  }

  auto
  TimedAnimation::property_value_to () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "value-to");
  }

  auto
  TimedAnimation::property_value_to () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "value-to");
  }

} // namespace Adw
