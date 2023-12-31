// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPLAYOUT_P_H
#define _LIBADWAITAMM_CLAMPLAYOUT_P_H

#include <libmm/gtk/layoutmanager_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT clamp_layout_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = clamp_layout;
    using BaseObjectType = AdwClampLayout;
    using CppClassParent = gtk::LayoutManager_Class;

    friend class clamp_layout;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
