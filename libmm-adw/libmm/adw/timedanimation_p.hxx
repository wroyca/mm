// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TIMEDANIMATION_P_H
#define _LIBADWAITAMM_TIMEDANIMATION_P_H

#include <libmm/adw/animation_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT timed_animation_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = timed_animation;
    using BaseObjectType = AdwTimedAnimation;
    using CppClassParent = animation_class;

    friend class timed_animation;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
