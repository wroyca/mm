// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/timedanimation.hxx>
#include <libmm/adw/timedanimation_p.hxx>

#include <libmm/adw/animation.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwTimedAnimation* object, bool take_copy) -> glib::RefPtr<adw::TimedAnimation>
  {
    return glib::make_refptr_for_instance<adw::TimedAnimation> (
        dynamic_cast<adw::TimedAnimation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  TimedAnimation_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_timed_animation_get_type ();
    }

    return *this;
  }

  auto
  TimedAnimation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TimedAnimation ((AdwTimedAnimation*) object);
  }

  auto
  TimedAnimation::gobj_copy () -> AdwTimedAnimation*
  {
    reference ();
    return gobj ();
  }

  TimedAnimation::TimedAnimation (const glib::ConstructParams& construct_params)
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
    : glib::ObjectBase (nullptr),
      Animation (glib::ConstructParams (timedanimation_class_.init ()))
  {
  }

  TimedAnimation::TimedAnimation (gtk::Widget* widget,
                                  double value_from,
                                  double value_to,
                                  guint duration,
                                  const glib::RefPtr<AnimationTarget>& target)
    : glib::ObjectBase (nullptr),
      Animation (glib::ConstructParams (timedanimation_class_.init (),
                                        "widget",
                                        (GtkWidget*) glib::unwrap (widget),
                                        "value_from",
                                        value_from,
                                        "value_to",
                                        value_to,
                                        "duration",
                                        duration,
                                        "target",
                                        glib::unwrap (target),
                                        nullptr))
  {
  }

  auto
  TimedAnimation::create (gtk::Widget* widget,
                          double value_from,
                          double value_to,
                          guint duration,
                          const glib::RefPtr<AnimationTarget>& target) -> glib::RefPtr<TimedAnimation>
  {
    return glib::make_refptr_for_instance<TimedAnimation> (
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
  TimedAnimation::property_alternate () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "alternate");
  }

  auto
  TimedAnimation::property_alternate () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "alternate");
  }

  auto
  TimedAnimation::property_duration () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "duration");
  }

  auto
  TimedAnimation::property_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "duration");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Easing>::value,
      "Type Easing cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TimedAnimation::property_easing () -> glib::PropertyProxy<Easing>
  {
    return glib::PropertyProxy<Easing> (this, "easing");
  }

  auto
  TimedAnimation::property_easing () const -> glib::PropertyProxy_ReadOnly<Easing>
  {
    return glib::PropertyProxy_ReadOnly<Easing> (this, "easing");
  }

  auto
  TimedAnimation::property_repeat_count () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "repeat-count");
  }

  auto
  TimedAnimation::property_repeat_count () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "repeat-count");
  }

  auto
  TimedAnimation::property_reverse () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reverse");
  }

  auto
  TimedAnimation::property_reverse () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reverse");
  }

  auto
  TimedAnimation::property_value_from () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "value-from");
  }

  auto
  TimedAnimation::property_value_from () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "value-from");
  }

  auto
  TimedAnimation::property_value_to () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "value-to");
  }

  auto
  TimedAnimation::property_value_to () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "value-to");
  }

} // namespace adw
