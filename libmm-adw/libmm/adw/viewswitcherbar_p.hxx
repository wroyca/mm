// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSWITCHERBAR_P_H
#define _LIBADWAITAMM_VIEWSWITCHERBAR_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT view_switcher_bar_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = view_switcher_bar;
    using BaseObjectType = AdwViewSwitcherBar;
    using CppClassParent = gtk::Widget_Class;

    friend class view_switcher_bar;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
