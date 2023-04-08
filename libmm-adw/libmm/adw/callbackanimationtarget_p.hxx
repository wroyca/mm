// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CALLBACKANIMATIONTARGET_P_H
#define _LIBADWAITAMM_CALLBACKANIMATIONTARGET_P_H

#include <libmm/adw/animationtarget_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT callback_animation_target_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = callback_animation_target;
    using BaseObjectType = AdwCallbackAnimationTarget;
    using CppClassParent = adw::animation_target_class;

    friend class callback_animation_target;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
