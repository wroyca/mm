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
  wrap (AdwTimedAnimation* object, bool take_copy) -> glib::RefPtr<adw::timed_animation>
  {
    return glib::make_refptr_for_instance<adw::timed_animation> (
        dynamic_cast<adw::timed_animation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  timed_animation_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_timed_animation_get_type ();
    }

    return *this;
  }

  auto
  timed_animation_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new timed_animation ((AdwTimedAnimation*) object);
  }

  auto
  timed_animation::gobj_copy () -> AdwTimedAnimation*
  {
    reference ();
    return gobj ();
  }

  timed_animation::timed_animation (const glib::ConstructParams& construct_params)
    : animation (construct_params)
  {
  }

  timed_animation::timed_animation (AdwTimedAnimation* castitem)
    : animation ((AdwAnimation*) (castitem))
  {
  }

  timed_animation::timed_animation (timed_animation&& src) noexcept
    : animation (std::move (src))
  {
  }

  auto
  timed_animation::operator= (timed_animation&& src) noexcept -> timed_animation&
  {
    animation::operator= (std::move (src));
    return *this;
  }

  timed_animation::~timed_animation () noexcept {}

  timed_animation::CppClassType timed_animation::timedanimation_class_;

  auto
  timed_animation::get_type () -> GType
  {
    return timedanimation_class_.init ().get_type ();
  }

  auto
  timed_animation::get_base_type () -> GType
  {
    return adw_timed_animation_get_type ();
  }

  timed_animation::timed_animation ()
    : glib::ObjectBase (nullptr),
      animation (glib::ConstructParams (timedanimation_class_.init ()))
  {
  }

  timed_animation::timed_animation (gtk::Widget* widget,
                                  double value_from,
                                  double value_to,
                                  guint duration,
                                  const glib::RefPtr<AnimationTarget>& target)
    : glib::ObjectBase (nullptr),
      animation (glib::ConstructParams (timedanimation_class_.init (),
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
  timed_animation::create (gtk::Widget* widget,
                          double value_from,
                          double value_to,
                          guint duration,
                          const glib::RefPtr<AnimationTarget>& target) -> glib::RefPtr<timed_animation>
  {
    return glib::make_refptr_for_instance<timed_animation> (
        new timed_animation (widget, value_from, value_to, duration, target));
  }

  auto
  timed_animation::get_alternate () const -> bool
  {
    return adw_timed_animation_get_alternate (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::get_duration () const -> guint
  {
    return adw_timed_animation_get_duration (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::get_easing () const -> Easing
  {
    return static_cast<Easing> (adw_timed_animation_get_easing (
        const_cast<AdwTimedAnimation*> (gobj ())));
  }

  auto
  timed_animation::get_repeat_count () const -> guint
  {
    return adw_timed_animation_get_repeat_count (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::get_reverse () const -> bool
  {
    return adw_timed_animation_get_reverse (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::get_value_from () const -> double
  {
    return adw_timed_animation_get_value_from (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::get_value_to () const -> double
  {
    return adw_timed_animation_get_value_to (
        const_cast<AdwTimedAnimation*> (gobj ()));
  }

  auto
  timed_animation::set_alternate (bool alternate) -> void
  {
    adw_timed_animation_set_alternate (gobj (), static_cast<int> (alternate));
  }

  auto
  timed_animation::set_duration (guint duration) -> void
  {
    adw_timed_animation_set_duration (gobj (), duration);
  }

  auto
  timed_animation::set_easing (Easing easing) -> void
  {
    adw_timed_animation_set_easing (gobj (), static_cast<AdwEasing> (easing));
  }

  auto
  timed_animation::set_repeat_count (guint repeat_count) -> void
  {
    adw_timed_animation_set_repeat_count (gobj (), repeat_count);
  }

  auto
  timed_animation::set_reverse (bool reverse) -> void
  {
    adw_timed_animation_set_reverse (gobj (), static_cast<int> (reverse));
  }

  auto
  timed_animation::set_value_from (double from) const -> void
  {
    adw_timed_animation_set_value_from (
        const_cast<AdwTimedAnimation*> (gobj ()),
        from);
  }

  auto
  timed_animation::set_value_to (double to) const -> void
  {
    adw_timed_animation_set_value_to (const_cast<AdwTimedAnimation*> (gobj ()),
                                      to);
  }

  auto
  timed_animation::property_alternate () -> glib::PropertyProxy<bool>
  {
    return {this, "alternate"};
  }

  auto
  timed_animation::property_alternate () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "alternate"};
  }

  auto
  timed_animation::property_duration () -> glib::PropertyProxy<guint>
  {
    return {this, "duration"};
  }

  auto
  timed_animation::property_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "duration"};
  }

  auto
  timed_animation::property_easing () -> glib::PropertyProxy<Easing>
  {
    return {this, "easing"};
  }

  auto
  timed_animation::property_easing () const -> glib::PropertyProxy_ReadOnly<Easing>
  {
    return {this, "easing"};
  }

  auto
  timed_animation::property_repeat_count () -> glib::PropertyProxy<guint>
  {
    return {this, "repeat-count"};
  }

  auto
  timed_animation::property_repeat_count () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "repeat-count"};
  }

  auto
  timed_animation::property_reverse () -> glib::PropertyProxy<bool>
  {
    return {this, "reverse"};
  }

  auto
  timed_animation::property_reverse () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reverse"};
  }

  auto
  timed_animation::property_value_from () -> glib::PropertyProxy<double>
  {
    return {this, "value-from"};
  }

  auto
  timed_animation::property_value_from () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-from"};
  }

  auto
  timed_animation::property_value_to () -> glib::PropertyProxy<double>
  {
    return {this, "value-to"};
  }

  auto
  timed_animation::property_value_to () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-to"};
  }

} // namespace adw
