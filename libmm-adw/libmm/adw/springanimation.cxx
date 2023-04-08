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
  wrap (AdwSpringAnimation* object, bool take_copy) -> glib::RefPtr<adw::spring_animation>
  {
    return glib::make_refptr_for_instance<adw::spring_animation> (
        dynamic_cast<adw::spring_animation*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  spring_animation_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &spring_animation_class::class_init_function;

      register_derived_type (adw_spring_animation_get_type ());
    }

    return *this;
  }

  auto
  spring_animation_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  spring_animation_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new spring_animation ((AdwSpringAnimation*) object);
  }

  auto
  spring_animation::gobj_copy () -> AdwSpringAnimation*
  {
    reference ();
    return gobj ();
  }

  spring_animation::spring_animation (
      const glib::ConstructParams& construct_params)
    : animation (construct_params)
  {
  }

  spring_animation::spring_animation (AdwSpringAnimation* castitem)
    : animation ((AdwAnimation*) (castitem))
  {
  }

  spring_animation::spring_animation (spring_animation&& src) noexcept
    : animation (std::move (src))
  {
  }

  auto
  spring_animation::operator= (spring_animation&& src) noexcept -> spring_animation&
  {
    animation::operator= (std::move (src));
    return *this;
  }

  spring_animation::~spring_animation () noexcept {}

  spring_animation::CppClassType spring_animation::springanimation_class_;

  auto
  spring_animation::get_type () -> GType
  {
    return springanimation_class_.init ().get_type ();
  }

  auto
  spring_animation::get_base_type () -> GType
  {
    return adw_spring_animation_get_type ();
  }

  spring_animation::spring_animation (
      gtk::Widget* widget,
      double value_from,
      double value_to,
      const glib::RefPtr<spring_params>& spring_params,
      const glib::RefPtr<AnimationTarget>& target)
    : glib::ObjectBase (nullptr),
      animation (glib::ConstructParams (springanimation_class_.init (),
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

  spring_animation::spring_animation ()
    : glib::ObjectBase (nullptr),
      animation (glib::ConstructParams (springanimation_class_.init ()))
  {
  }

  auto
  spring_animation::create (gtk::Widget* widget,
                           double value_from,
                           double value_to,
                           const glib::RefPtr<spring_params>& spring_params,
                           const glib::RefPtr<AnimationTarget>& target) -> glib::RefPtr<spring_animation>
  {
    return glib::make_refptr_for_instance<spring_animation> (
        new spring_animation (widget,
                             value_from,
                             value_to,
                             spring_params,
                             target));
  }

  auto
  spring_animation::get_clamp () const -> bool
  {
    return adw_spring_animation_get_clamp (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_epsilon () const -> double
  {
    return adw_spring_animation_get_epsilon (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_estimated_duration () const -> guint
  {
    return adw_spring_animation_get_estimated_duration (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_initial_velocity () const -> double
  {
    return adw_spring_animation_get_initial_velocity (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_spring_params () const -> glib::RefPtr<spring_params>
  {
    auto retvalue = glib::wrap (adw_spring_animation_get_spring_params (
        const_cast<AdwSpringAnimation*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  spring_animation::get_value_from () const -> double
  {
    return adw_spring_animation_get_value_from (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_value_to () const -> double
  {
    return adw_spring_animation_get_value_to (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::get_velocity () const -> double
  {
    return adw_spring_animation_get_velocity (
        const_cast<AdwSpringAnimation*> (gobj ()));
  }

  auto
  spring_animation::set_clamp (bool clamp) -> void
  {
    adw_spring_animation_set_clamp (gobj (), static_cast<int> (clamp));
  }

  auto
  spring_animation::set_epsilon (double epsilon) -> void
  {
    adw_spring_animation_set_epsilon (gobj (), epsilon);
  }

  auto
  spring_animation::set_initial_velocity (double velocity) -> void
  {
    adw_spring_animation_set_initial_velocity (gobj (), velocity);
  }

  auto
  spring_animation::set_spring_params (
      const glib::RefPtr<spring_params>& spring_params) -> void
  {
    adw_spring_animation_set_spring_params (gobj (),
                                            glib::unwrap (spring_params));
  }

  auto
  spring_animation::set_value_from (double epsilon) -> void
  {
    adw_spring_animation_set_value_from (gobj (), epsilon);
  }

  auto
  spring_animation::set_value_to (double epsilon) -> void
  {
    adw_spring_animation_set_value_to (gobj (), epsilon);
  }

  auto
  spring_animation::property_clamp () -> glib::PropertyProxy<bool>
  {
    return {this, "clamp"};
  }

  auto
  spring_animation::property_clamp () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "clamp"};
  }

  auto
  spring_animation::property_epsilon () -> glib::PropertyProxy<double>
  {
    return {this, "epsilon"};
  }

  auto
  spring_animation::property_epsilon () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "epsilon"};
  }

  auto
  spring_animation::property_estimated_duration () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "estimated-duration"};
  }

  auto
  spring_animation::property_initial_velocity () -> glib::PropertyProxy<double>
  {
    return {this, "initial-velocity"};
  }

  auto
  spring_animation::property_initial_velocity () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "initial-velocity"};
  }

  auto
  spring_animation::property_spring_params () -> glib::PropertyProxy<glib::RefPtr<spring_params>>
  {
    return {this, "spring-params"};
  }

  auto
  spring_animation::property_spring_params () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>
  {
    return {this, "spring-params"};
  }

  auto
  spring_animation::property_value_from () -> glib::PropertyProxy<double>
  {
    return {this, "value-from"};
  }

  auto
  spring_animation::property_value_from () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-from"};
  }

  auto
  spring_animation::property_value_to () -> glib::PropertyProxy<double>
  {
    return {this, "value-to"};
  }

  auto
  spring_animation::property_value_to () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "value-to"};
  }

  auto
  spring_animation::property_velocity () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return {this, "velocity"};
  }

} // namespace adw
