// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TIMEDANIMATION_H
#define _LIBADWAITAMM_TIMEDANIMATION_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <adwaita.h>
#include <libmm-adw/animation.hxx>
#include <libmm-adw/animationtarget.hxx>
#include <libmm-adw/easing.hxx>
#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwTimedAnimation = struct _AdwTimedAnimation;
using AdwTimedAnimationClass = struct _AdwTimedAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT TimedAnimation_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT TimedAnimation : public Animation
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TimedAnimation;
    using CppClassType = TimedAnimation_Class;
    using BaseObjectType = AdwTimedAnimation;
    using BaseClassType = AdwTimedAnimationClass;

    TimedAnimation (const TimedAnimation&) = delete;
    auto
    operator= (const TimedAnimation&) -> TimedAnimation& = delete;

  private:
    friend class TimedAnimation_Class;
    static CppClassType timedanimation_class_;

  protected:
    explicit TimedAnimation (const Glib::ConstructParams& construct_params);
    explicit TimedAnimation (AdwTimedAnimation* castitem);

#endif

  public:
    TimedAnimation (TimedAnimation&& src) noexcept;
    auto
    operator= (TimedAnimation&& src) noexcept -> TimedAnimation&;

    ~TimedAnimation () noexcept override;

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
    TimedAnimation ();
    explicit TimedAnimation (Gtk::Widget* widget,
                             double value_from,
                             double value_to,
                             guint duration,
                             const Glib::RefPtr<AnimationTarget>& target);

  public:
    static auto
    create (Gtk::Widget* widget,
            double value_from,
            double value_to,
            guint duration,
            const Glib::RefPtr<AnimationTarget>& target)
        -> Glib::RefPtr<TimedAnimation>;

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
    property_alternate () -> Glib::PropertyProxy<bool>;

    auto
    property_alternate () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_duration () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_easing () -> Glib::PropertyProxy<Easing>;

    auto
    property_easing () const -> Glib::PropertyProxy_ReadOnly<Easing>;

    auto
    property_repeat_count () -> Glib::PropertyProxy<guint>;

    auto
    property_repeat_count () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_reverse () -> Glib::PropertyProxy<bool>;

    auto
    property_reverse () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_value_from () -> Glib::PropertyProxy<double>;

    auto
    property_value_from () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_value_to () -> Glib::PropertyProxy<double>;

    auto
    property_value_to () const -> Glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwTimedAnimation* object, bool take_copy = false) -> Glib::RefPtr<Adw::TimedAnimation>;
}

#endif
