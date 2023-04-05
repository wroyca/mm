// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ANIMATION_H
#define _LIBADWAITAMM_ANIMATION_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/animationtarget.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwAnimation = struct _AdwAnimation;
using AdwAnimationClass = struct _AdwAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT Animation_Class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT AnimationState
  {
    IDLE,
    PAUSED,
    PLAYING,
    FINISHED
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::AnimationState>
    : public glib::Value_Enum<adw::AnimationState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Animation : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Animation;
    using CppClassType = Animation_Class;
    using BaseObjectType = AdwAnimation;
    using BaseClassType = AdwAnimationClass;

    Animation (const Animation&) = delete;
    auto
    operator= (const Animation&) -> Animation& = delete;

  private:
    friend class Animation_Class;
    static CppClassType animation_class_;

  protected:
    explicit Animation (const glib::ConstructParams& construct_params);
    explicit Animation (AdwAnimation* castitem);

#endif

  public:
    Animation (Animation&& src) noexcept;
    auto
    operator= (Animation&& src) noexcept -> Animation&;

    ~Animation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwAnimation*
    {
      return reinterpret_cast<AdwAnimation*> (gobject_);
    }

    auto
    gobj () const -> const AdwAnimation*
    {
      return reinterpret_cast<AdwAnimation*> (gobject_);
    }

    auto
    gobj_copy () -> AdwAnimation*;

  private:
  protected:
    Animation ();

  public:
    static auto
    create () -> glib::RefPtr<Animation>;

    auto
    get_state () const -> AnimationState;

    auto
    get_value () const -> double;

    auto
    get_target () const -> glib::RefPtr<AnimationTarget>;

    auto
    get_widget () const -> gtk::Widget*;

    auto
    pause () -> void;

    auto
    play () -> void;

    auto
    reset () -> void;

    auto
    resume () -> void;

    auto
    set_target (glib::RefPtr<AnimationTarget> target) -> void;

    auto
    skip () -> void;

    auto
    property_state () const -> glib::PropertyProxy_ReadOnly<AnimationState>;

    auto
    property_target () -> glib::PropertyProxy<glib::RefPtr<AnimationTarget>>;

    auto
    property_target () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<AnimationTarget>>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    signal_done () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwAnimation* object, bool take_copy = false) -> glib::RefPtr<adw::Animation>;
}

#endif
