// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/springanimation.hxx>
#include <libmm/adw/springanimation_p.hxx>

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
  wrap (AdwSpringAnimation* object, bool take_copy) -> glib::RefPtr<adw::SpringAnimation>
  {
    return glib::make_refptr_for_instance<adw::SpringAnimation> (
        dynamic_cast<adw::SpringAnimation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  SpringAnimation_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SpringAnimation_Class::class_init_function;

      register_derived_type (adw_spring_animation_get_type ());
    }

    return *this;
  }

  auto
  SpringAnimation_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SpringAnimation_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SpringAnimation ((AdwSpringAnimation*) object);
  }

  auto
  SpringAnimation::gobj_copy () -> AdwSpringAnimation*
  {
    reference ();
    return gobj ();
  }

  SpringAnimation::SpringAnimation (
      const glib::ConstructParams& construct_params)
    : Animation (construct_params)
  {
  }

  SpringAnimation::SpringAnimation (AdwSpringAnimation* castitem)
    : Animation ((AdwAnimation*) (castitem))
  {
  }

  SpringAnimation::SpringAnimation (SpringAnimation&& src) noexcept
    : Animation (std::move (src))
  {
  }

  auto
  SpringAnimation::operator= (SpringAnimation&& src) noexcept -> SpringAnimation&
  {
    Animation::operator= (std::move (src));
    return *this;
  }

  SpringAnimation::~SpringAnimation () noexcept {}

  SpringAnimation::CppClassType SpringAnimation::springanimation_class_;

  auto
  SpringAnimation::get_type () -> GType
  {
    return springanimation_class_.init ().get_type ();
  }

  auto
  SpringAnimation::get_base_type () -> GType
  {
    return adw_spring_animation_get_type ();
  }

  SpringAnimation::SpringAnimation (
      gtk::Widget* widget,
      double value_from,
      double value_to,
      const glib::RefPtr<SpringParams>& spring_params,
      const glib::RefPtr<AnimationTarget>& target)
    : glib::ObjectBase (nullptr),
      Animation (glib::ConstructParams (springanimation_class_.init (),
                                        "widget",
                                        (GtkWidget*) glib::unwrap (widget),
                                        "value_from",
                                        value_from,
                                        "value_to",
                                        value_to,
                                        "spring_params",
                                        glib::unwrap (spring_params),
                                        "target",
                                        glib::unwrap (target),
                                        nullptr))
  {
  }

  SpringAnimation::SpringAnimation ()
    : glib::ObjectBase (nullptr),
      Animation (glib::ConstructParams (springanimation_class_.init ()))
  {
  }

  auto
  SpringAnimation::create (gtk::Widget* widget,
                           double value_from,
                           double value_to,
                           const glib::RefPtr<SpringParams>& spring_params,
                           const glib::RefPtr<AnimationTarget>& target) -> glib::RefPtr<SpringAnimation>
  {
    return glib::make_refptr_for_instance<SpringAnimation> (
        new SpringAnimation (widget,
                             value_from,
                             value_to,
                             spring_params,
                             target));
  }

  auto
  SpringAnimation::get_clamp () const -> bool
  {
    return adw_spring_animation_get_clamp (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_epsilon () const -> double
  {
    return adw_spring_animation_get_epsilon (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_estimated_duration () const -> guint
  {
    return adw_spring_animation_get_estimated_duration (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_initial_velocity () const -> double
  {
    return adw_spring_animation_get_initial_velocity (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_spring_params () const -> glib::RefPtr<SpringParams>
  {
    auto retvalue = glib::wrap (adw_spring_animation_get_spring_params (
        const_cast<AdwSpringAnimation*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SpringAnimation::get_value_from () const -> double
  {
    return adw_spring_animation_get_value_from (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_value_to () const -> double
  {
    return adw_spring_animation_get_value_to (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::get_velocity () const -> double
  {
    return adw_spring_animation_get_velocity (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  SpringAnimation::set_clamp (bool clamp) -> void
  {
    adw_spring_animation_set_clamp (gobj (), static_cast<int> (clamp));
  }

  auto
  SpringAnimation::set_epsilon (double epsilon) -> void
  {
    adw_spring_animation_set_epsilon (gobj (), epsilon);
  }

  auto
  SpringAnimation::set_initial_velocity (double velocity) -> void
  {
    adw_spring_animation_set_initial_velocity (gobj (), velocity);
  }

  auto
  SpringAnimation::set_spring_params (
      const glib::RefPtr<SpringParams>& spring_params) -> void
  {
    adw_spring_animation_set_spring_params (gobj (),
                                            glib::unwrap (spring_params));
  }

  auto
  SpringAnimation::set_value_from (double epsilon) -> void
  {
    adw_spring_animation_set_value_from (gobj (), epsilon);
  }

  auto
  SpringAnimation::set_value_to (double epsilon) -> void
  {
    adw_spring_animation_set_value_to (gobj (), epsilon);
  }

  auto
  SpringAnimation::property_clamp () -> glib::PropertyProxy<bool>
  {
    return {this, "clamp"};
  }

  auto
  SpringAnimation::property_clamp () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "clamp"};
  }

  auto
  SpringAnimation::property_epsilon () -> glib::PropertyProxy<double>
  {
    return {this, "epsilon"};
  }

  auto
  SpringAnimation::property_epsilon () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "epsilon"};
  }

  auto
  SpringAnimation::property_estimated_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "estimated-duration"};
  }

  auto
  SpringAnimation::property_initial_velocity () -> glib::PropertyProxy<double>
  {
    return {this, "initial-velocity"};
  }

  auto
  SpringAnimation::property_initial_velocity () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "initial-velocity"};
  }

  auto
  SpringAnimation::property_spring_params () -> glib::PropertyProxy<glib::RefPtr<SpringParams>>
  {
    return {this, "spring-params"};
  }

  auto
  SpringAnimation::property_spring_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SpringParams>>
  {
    return {this, "spring-params"};
  }

  auto
  SpringAnimation::property_value_from () -> glib::PropertyProxy<double>
  {
    return {this, "value-from"};
  }

  auto
  SpringAnimation::property_value_from () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-from"};
  }

  auto
  SpringAnimation::property_value_to () -> glib::PropertyProxy<double>
  {
    return {this, "value-to"};
  }

  auto
  SpringAnimation::property_value_to () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-to"};
  }

  auto
  SpringAnimation::property_velocity () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "velocity"};
  }

} // namespace adw
