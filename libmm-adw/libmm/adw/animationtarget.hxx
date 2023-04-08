// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ANIMATIONTARGET_H
#define _LIBADWAITAMM_ANIMATIONTARGET_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwAnimationTarget = struct _AdwAnimationTarget;
using AdwAnimationTargetClass = struct _AdwAnimationTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT animation_target_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT AnimationTarget : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AnimationTarget;
    using CppClassType = animation_target_class;
    using BaseObjectType = AdwAnimationTarget;
    using BaseClassType = AdwAnimationTargetClass;

    AnimationTarget (const AnimationTarget&) = delete;
    auto
    operator= (const AnimationTarget&) -> AnimationTarget& = delete;

  private:
    friend class animation_target_class;
    static CppClassType animationtarget_class_;

  protected:
    explicit AnimationTarget (const glib::ConstructParams& construct_params);
    explicit AnimationTarget (AdwAnimationTarget* castitem);

#endif

  public:
    AnimationTarget (AnimationTarget&& src) noexcept;
    auto
    operator= (AnimationTarget&& src) noexcept -> AnimationTarget&;

    ~AnimationTarget () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwAnimationTarget*
    {
      return reinterpret_cast<AdwAnimationTarget*> (gobject_);
    }

    auto
    gobj () const -> const AdwAnimationTarget*
    {
      return reinterpret_cast<AdwAnimationTarget*> (gobject_);
    }

    auto
    gobj_copy () -> AdwAnimationTarget*;

  private:
  protected:
    AnimationTarget ();

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwAnimationTarget* object, bool take_copy = false) -> glib::RefPtr<adw::AnimationTarget>;
}

#endif
