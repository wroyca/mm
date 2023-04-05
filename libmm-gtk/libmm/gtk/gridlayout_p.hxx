// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDLAYOUT_P_H
#define _GTKMM_GRIDLAYOUT_P_H

#include <libmm/gtk/layoutmanager_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GridLayout_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GridLayout;
    using BaseObjectType = GtkGridLayout;
    using BaseClassType = GtkGridLayoutClass;
    using CppClassParent = LayoutManager_Class;
    using BaseClassParent = GtkLayoutManagerClass;

    friend class GridLayout;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
