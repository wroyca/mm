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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT SpringAnimation_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT SpringAnimation : public Animation
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SpringAnimation;
    using CppClassType = SpringAnimation_Class;
    using BaseObjectType = AdwSpringAnimation;
    using BaseClassType = AdwSpringAnimationClass;

    SpringAnimation (const SpringAnimation&) = delete;
    auto
    operator= (const SpringAnimation&) -> SpringAnimation& = delete;

  private:
    friend class SpringAnimation_Class;
    static CppClassType springanimation_class_;

  protected:
    explicit SpringAnimation (const Glib::ConstructParams& construct_params);
    explicit SpringAnimation (AdwSpringAnimation* castitem);

#endif

  public:
    SpringAnimation (SpringAnimation&& src) noexcept;
    auto
    operator= (SpringAnimation&& src) noexcept -> SpringAnimation&;

    ~SpringAnimation () noexcept override;

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
    explicit SpringAnimation (Gtk::Widget* widget,
                              double value_from,
                              double value_to,
                              const Glib::RefPtr<SpringParams>& spring_params,
                              const Glib::RefPtr<AnimationTarget>& target);

  protected:
    SpringAnimation ();

  public:
    static auto
    create (Gtk::Widget* widget,
            double value_from,
            double value_to,
            const Glib::RefPtr<SpringParams>& spring_params,
            const Glib::RefPtr<AnimationTarget>& target)
        -> Glib::RefPtr<SpringAnimation>;

    auto
    get_clamp () const -> bool;

    auto
    get_epsilon () const -> double;

    auto
    get_estimated_duration () const -> guint;

    auto
    get_initial_velocity () const -> double;

    auto
    get_spring_params () const -> Glib::RefPtr<SpringParams>;

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
    set_spring_params (const Glib::RefPtr<SpringParams>& spring_params) -> void;

    auto
    set_value_from (double epsilon) -> void;

    auto
    set_value_to (double epsilon) -> void;

    auto
    property_clamp () -> Glib::PropertyProxy<bool>;

    auto
    property_clamp () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_epsilon () -> Glib::PropertyProxy<double>;

    auto
    property_epsilon () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_estimated_duration () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_initial_velocity () -> Glib::PropertyProxy<double>;

    auto
    property_initial_velocity () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_spring_params ()
        -> Glib::PropertyProxy<Glib::RefPtr<SpringParams>>;

    auto
    property_spring_params () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SpringParams>>;

    auto
    property_value_from () -> Glib::PropertyProxy<double>;

    auto
    property_value_from () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_value_to () -> Glib::PropertyProxy<double>;

    auto
    property_value_to () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_velocity () const -> Glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwSpringAnimation* object, bool take_copy = false) -> Glib::RefPtr<Adw::SpringAnimation>;
}

#endif
