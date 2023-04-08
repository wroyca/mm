// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_STYLEMANAGER_P_H
#define _LIBADWAITAMM_STYLEMANAGER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT style_manager_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = style_manager;
    using BaseObjectType = AdwStyleManager;
    using CppClassParent = glib::Object_Class;

    friend class style_manager;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
