// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPLAYOUT_P_H
#define _LIBADWAITAMM_CLAMPLAYOUT_P_H

#include <libmm-gtk/layoutmanager_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class ClampLayout_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ClampLayout;
    using BaseObjectType = AdwClampLayout;
    using CppClassParent = Gtk::LayoutManager_Class;

    friend class ClampLayout;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
