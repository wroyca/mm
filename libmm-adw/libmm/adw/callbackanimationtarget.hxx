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
  class LIBMM_ADW_SYMEXPORT CallbackAnimationTarget_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT CallbackAnimationTarget : public adw::AnimationTarget
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CallbackAnimationTarget;
    using CppClassType = CallbackAnimationTarget_Class;
    using BaseObjectType = AdwCallbackAnimationTarget;
    using BaseClassType = AdwCallbackAnimationTargetClass;

    CallbackAnimationTarget (const CallbackAnimationTarget&) = delete;
    auto
    operator= (const CallbackAnimationTarget&)
        -> CallbackAnimationTarget& = delete;

  private:
    friend class CallbackAnimationTarget_Class;
    static CppClassType callbackanimationtarget_class_;

  protected:
    explicit CallbackAnimationTarget (
        const glib::ConstructParams& construct_params);
    explicit CallbackAnimationTarget (AdwCallbackAnimationTarget* castitem);

#endif

  public:
    CallbackAnimationTarget (CallbackAnimationTarget&& src) noexcept;
    auto
    operator= (CallbackAnimationTarget&& src) noexcept
        -> CallbackAnimationTarget&;

    ~CallbackAnimationTarget () noexcept override;

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
    CallbackAnimationTarget ();
    CallbackAnimationTarget (const SlotTarget& slot_target);

  public:
    static auto
    create (const SlotTarget& slot_target)
        -> glib::RefPtr<CallbackAnimationTarget>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwCallbackAnimationTarget* object, bool take_copy = false) -> glib::RefPtr<adw::CallbackAnimationTarget>;
}

#endif
