// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TIMEDANIMATION_H
#define _LIBADWAITAMM_TIMEDANIMATION_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <adwaita.h>
#include <libmm/adw/animation.hxx>
#include <libmm/adw/animationtarget.hxx>
#include <libmm/adw/easing.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwTimedAnimation = struct _AdwTimedAnimation;
using AdwTimedAnimationClass = struct _AdwTimedAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT timed_animation_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT timed_animation : public animation
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = timed_animation;
    using CppClassType = timed_animation_class;
    using BaseObjectType = AdwTimedAnimation;
    using BaseClassType = AdwTimedAnimationClass;

    timed_animation (const timed_animation&) = delete;
    auto
    operator= (const timed_animation&) -> timed_animation& = delete;

  private:
    friend class timed_animation_class;
    static CppClassType timedanimation_class_;

  protected:
    explicit timed_animation (const glib::ConstructParams& construct_params);
    explicit timed_animation (AdwTimedAnimation* castitem);

#endif

  public:
    timed_animation (timed_animation&& src) noexcept;
    auto
    operator= (timed_animation&& src) noexcept -> timed_animation&;

    ~timed_animation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwTimedAnimation*
    {
      return reinterpret_cast<AdwTimedAnimation*> (gobject_);
    }

    auto
    gobj () const -> const AdwTimedAnimation*
    {
      return reinterpret_cast<AdwTimedAnimation*> (gobject_);
    }

    auto
    gobj_copy () -> AdwTimedAnimation*;

  private:
  protected:
    timed_animation ();
    explicit timed_animation (gtk::Widget* widget,
                             double value_from,
                             double value_to,
                             guint duration,
                             const glib::RefPtr<AnimationTarget>& target);

  public:
    static auto
    create (gtk::Widget* widget,
            double value_from,
            double value_to,
            guint duration,
            const glib::RefPtr<AnimationTarget>& target)
        -> glib::RefPtr<timed_animation>;

    auto
    get_alternate () const -> bool;

    auto
    get_duration () const -> guint;

    auto
    get_easing () const -> Easing;

    auto
    get_repeat_count () const -> guint;

    auto
    get_reverse () const -> bool;

    auto
    get_value_from () const -> double;

    auto
    get_value_to () const -> double;

    auto
    set_alternate (bool alternate) -> void;

    auto
    set_duration (guint duration) -> void;

    auto
    set_easing (Easing easing) -> void;

    auto
    set_repeat_count (guint repeat_count) -> void;

    auto
    set_reverse (bool reverse) -> void;

    auto
    set_value_from (double from) const -> void;

    auto
    set_value_to (double to) const -> void;

    auto
    property_alternate () -> glib::PropertyProxy<bool>;

    auto
    property_alternate () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_duration () -> glib::PropertyProxy<guint>;

    auto
    property_duration () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_easing () -> glib::PropertyProxy<Easing>;

    auto
    property_easing () const -> glib::PropertyProxy_ReadOnly<Easing>;

    auto
    property_repeat_count () -> glib::PropertyProxy<guint>;

    auto
    property_repeat_count () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_reverse () -> glib::PropertyProxy<bool>;

    auto
    property_reverse () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_value_from () -> glib::PropertyProxy<double>;

    auto
    property_value_from () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_value_to () -> glib::PropertyProxy<double>;

    auto
    property_value_to () const -> glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwTimedAnimation* object, bool take_copy = false) -> glib::RefPtr<adw::timed_animation>;
}

#endif
