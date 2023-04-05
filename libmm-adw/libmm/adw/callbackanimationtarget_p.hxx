// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CALLBACKANIMATIONTARGET_P_H
#define _LIBADWAITAMM_CALLBACKANIMATIONTARGET_P_H

#include <libmm/adw/animationtarget_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT CallbackAnimationTarget_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CallbackAnimationTarget;
    using BaseObjectType = AdwCallbackAnimationTarget;
    using CppClassParent = adw::AnimationTarget_Class;

    friend class CallbackAnimationTarget;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
