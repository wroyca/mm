// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ANIMATION_P_H
#define _LIBADWAITAMM_ANIMATION_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT animation_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = animation;
    using BaseObjectType = AdwAnimation;
    using BaseClassType = AdwAnimationClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class animation;
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
