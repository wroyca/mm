// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TABPAGE_P_H
#define _LIBADWAITAMM_TABPAGE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT tab_page_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = tab_page;
    using BaseObjectType = AdwTabPage;
    using CppClassParent = glib::Object_Class;

    friend class tab_page;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
