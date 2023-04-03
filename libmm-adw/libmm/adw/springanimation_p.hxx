// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPRINGANIMATION_P_H
#define _LIBADWAITAMM_SPRINGANIMATION_P_H

#include <libmm/adw/animation_p.hxx>

#include <libmm/glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT SpringAnimation_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SpringAnimation;
    using BaseObjectType = AdwSpringAnimation;
    using BaseClassType = AdwSpringAnimationClass;
    using CppClassParent = Animation_Class;
    using BaseClassParent = AdwAnimationClass;

    friend class SpringAnimation;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
