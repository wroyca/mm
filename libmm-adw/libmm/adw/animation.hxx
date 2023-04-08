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
  class LIBMM_ADW_SYMEXPORT animation_class;
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

  class LIBMM_ADW_SYMEXPORT animation : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = animation;
    using CppClassType = animation_class;
    using BaseObjectType = AdwAnimation;
    using BaseClassType = AdwAnimationClass;

    animation (const animation&) = delete;
    auto
    operator= (const animation&) -> animation& = delete;

  private:
    friend class animation_class;
    static CppClassType animation_class_;

  protected:
    explicit animation (const glib::ConstructParams& construct_params);
    explicit animation (AdwAnimation* castitem);

#endif

  public:
    animation (animation&& src) noexcept;
    auto
    operator= (animation&& src) noexcept -> animation&;

    ~animation () noexcept override;

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
    animation ();

  public:
    static auto
    create () -> glib::RefPtr<animation>;

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
  wrap (AdwAnimation* object, bool take_copy = false) -> glib::RefPtr<adw::animation>;
}

#endif
