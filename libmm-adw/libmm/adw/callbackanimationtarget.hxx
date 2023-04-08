// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CALLBACKANIMATIONTARGET_H
#define _LIBADWAITAMM_CALLBACKANIMATIONTARGET_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/animationtarget.hxx>
#include <libmm/glib/mm-glib.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwCallbackAnimationTarget = struct _AdwCallbackAnimationTarget;
using AdwCallbackAnimationTargetClass = struct _AdwCallbackAnimationTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT callback_animation_target_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT callback_animation_target : public adw::AnimationTarget
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = callback_animation_target;
    using CppClassType = callback_animation_target_class;
    using BaseObjectType = AdwCallbackAnimationTarget;
    using BaseClassType = AdwCallbackAnimationTargetClass;

    callback_animation_target (const callback_animation_target&) = delete;
    auto
    operator= (const callback_animation_target&)
        -> callback_animation_target& = delete;

  private:
    friend class callback_animation_target_class;
    static CppClassType callbackanimationtarget_class_;

  protected:
    explicit callback_animation_target (
        const glib::ConstructParams& construct_params);
    explicit callback_animation_target (AdwCallbackAnimationTarget* castitem);

#endif

  public:
    callback_animation_target (callback_animation_target&& src) noexcept;
    auto
    operator= (callback_animation_target&& src) noexcept
        -> callback_animation_target&;

    ~callback_animation_target () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwCallbackAnimationTarget*
    {
      return reinterpret_cast<AdwCallbackAnimationTarget*> (gobject_);
    }

    auto
    gobj () const -> const AdwCallbackAnimationTarget*
    {
      return reinterpret_cast<AdwCallbackAnimationTarget*> (gobject_);
    }

    auto
    gobj_copy () -> AdwCallbackAnimationTarget*;

  private:
    static auto
    callback_function (double value, gpointer user_data) -> void;

  public:
    using SlotTarget = sigc::slot<void (double)>;

  protected:
    callback_animation_target ();
    callback_animation_target (const SlotTarget& slot_target);

  public:
    static auto
    create (const SlotTarget& slot_target)
        -> glib::RefPtr<callback_animation_target>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwCallbackAnimationTarget* object, bool take_copy = false) -> glib::RefPtr<adw::callback_animation_target>;
}

#endif
