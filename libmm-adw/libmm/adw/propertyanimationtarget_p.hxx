// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PROPERTYANIMATIONTARGET_P_H
#define _LIBADWAITAMM_PROPERTYANIMATIONTARGET_P_H

#include <libmm/adw/animationtarget_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT PropertyAnimationTarget_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PropertyAnimationTarget;
    using BaseObjectType = AdwPropertyAnimationTarget;
    using CppClassParent = AnimationTarget_Class;

    friend class PropertyAnimationTarget;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
