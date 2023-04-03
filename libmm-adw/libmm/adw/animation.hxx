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
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT Animation_Class;
}
#endif

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT AnimationState
  {
    IDLE,
    PAUSED,
    PLAYING,
    FINISHED
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::AnimationState>
    : public Glib::Value_Enum<Adw::AnimationState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Animation : public Glib::Object
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
    explicit Animation (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<Animation>;

    auto
    get_state () const -> AnimationState;

    auto
    get_value () const -> double;

    auto
    get_target () const -> Glib::RefPtr<AnimationTarget>;

    auto
    get_widget () const -> Gtk::Widget*;

    auto
    pause () -> void;

    auto
    play () -> void;

    auto
    reset () -> void;

    auto
    resume () -> void;

    auto
    set_target (Glib::RefPtr<AnimationTarget> target) -> void;

    auto
    skip () -> void;

    auto
    property_state () const -> Glib::PropertyProxy_ReadOnly<AnimationState>;

    auto
    property_target () -> Glib::PropertyProxy<Glib::RefPtr<AnimationTarget>>;

    auto
    property_target () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<AnimationTarget>>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    signal_done () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwAnimation* object, bool take_copy = false) -> Glib::RefPtr<Adw::Animation>;
}

#endif
