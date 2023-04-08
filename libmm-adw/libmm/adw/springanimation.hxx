// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPRINGANIMATION_H
#define _LIBADWAITAMM_SPRINGANIMATION_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <adwaita.h>
#include <libmm/adw/animation.hxx>
#include <libmm/adw/springparams.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwSpringAnimation = struct _AdwSpringAnimation;
using AdwSpringAnimationClass = struct _AdwSpringAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT spring_animation_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT spring_animation : public animation
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = spring_animation;
    using CppClassType = spring_animation_class;
    using BaseObjectType = AdwSpringAnimation;
    using BaseClassType = AdwSpringAnimationClass;

    spring_animation (const spring_animation&) = delete;
    auto
    operator= (const spring_animation&) -> spring_animation& = delete;

  private:
    friend class spring_animation_class;
    static CppClassType springanimation_class_;

  protected:
    explicit spring_animation (const glib::ConstructParams& construct_params);
    explicit spring_animation (AdwSpringAnimation* castitem);

#endif

  public:
    spring_animation (spring_animation&& src) noexcept;
    auto
    operator= (spring_animation&& src) noexcept -> spring_animation&;

    ~spring_animation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSpringAnimation*
    {
      return reinterpret_cast<AdwSpringAnimation*> (gobject_);
    }

    auto
    gobj () const -> const AdwSpringAnimation*
    {
      return reinterpret_cast<AdwSpringAnimation*> (gobject_);
    }

    auto
    gobj_copy () -> AdwSpringAnimation*;

  private:
    explicit spring_animation (gtk::Widget* widget,
                              double value_from,
                              double value_to,
                              const glib::RefPtr<spring_params>& spring_params,
                              const glib::RefPtr<AnimationTarget>& target);

  protected:
    spring_animation ();

  public:
    static auto
    create (gtk::Widget* widget,
            double value_from,
            double value_to,
            const glib::RefPtr<spring_params>& spring_params,
            const glib::RefPtr<AnimationTarget>& target)
        -> glib::RefPtr<spring_animation>;

    auto
    get_clamp () const -> bool;

    auto
    get_epsilon () const -> double;

    auto
    get_estimated_duration () const -> guint;

    auto
    get_initial_velocity () const -> double;

    auto
    get_spring_params () const -> glib::RefPtr<spring_params>;

    auto
    get_value_from () const -> double;

    auto
    get_value_to () const -> double;

    auto
    get_velocity () const -> double;

    auto
    set_clamp (bool clamp) -> void;

    auto
    set_epsilon (double epsilon) -> void;

    auto
    set_initial_velocity (double velocity) -> void;

    auto
    set_spring_params (const glib::RefPtr<spring_params>& spring_params) -> void;

    auto
    set_value_from (double epsilon) -> void;

    auto
    set_value_to (double epsilon) -> void;

    auto
    property_clamp () -> glib::PropertyProxy<bool>;

    auto
    property_clamp () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_epsilon () -> glib::PropertyProxy<double>;

    auto
    property_epsilon () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_estimated_duration () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_initial_velocity () -> glib::PropertyProxy<double>;

    auto
    property_initial_velocity () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_spring_params ()
        -> glib::PropertyProxy<glib::RefPtr<spring_params>>;

    auto
    property_spring_params () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<spring_params>>;

    auto
    property_value_from () -> glib::PropertyProxy<double>;

    auto
    property_value_from () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_value_to () -> glib::PropertyProxy<double>;

    auto
    property_value_to () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_velocity () const -> glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwSpringAnimation* object, bool take_copy = false) -> glib::RefPtr<adw::spring_animation>;
}

#endif
