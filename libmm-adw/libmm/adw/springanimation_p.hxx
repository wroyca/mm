// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPRINGANIMATION_P_H
#define _LIBADWAITAMM_SPRINGANIMATION_P_H

#include <libmm/adw/animation_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT spring_animation_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = spring_animation;
    using BaseObjectType = AdwSpringAnimation;
    using BaseClassType = AdwSpringAnimationClass;
    using CppClassParent = animation_class;
    using BaseClassParent = AdwAnimationClass;

    friend class spring_animation;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
