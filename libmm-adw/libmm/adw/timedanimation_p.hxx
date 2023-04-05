// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TIMEDANIMATION_P_H
#define _LIBADWAITAMM_TIMEDANIMATION_P_H

#include <libmm/adw/animation_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT TimedAnimation_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TimedAnimation;
    using BaseObjectType = AdwTimedAnimation;
    using CppClassParent = Animation_Class;

    friend class TimedAnimation;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
