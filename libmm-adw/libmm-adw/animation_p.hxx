// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ANIMATION_P_H
#define _LIBADWAITAMM_ANIMATION_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class Animation_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Animation;
    using BaseObjectType = AdwAnimation;
    using BaseClassType = AdwAnimationClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Animation;
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
