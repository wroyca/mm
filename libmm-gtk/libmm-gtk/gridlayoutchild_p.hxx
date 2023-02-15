// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDLAYOUTCHILD_P_H
#define _GTKMM_GRIDLAYOUTCHILD_P_H

#include <libmm-gtk/layoutchild_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GridLayoutChild_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GridLayoutChild;
    using BaseObjectType = GtkGridLayoutChild;
    using BaseClassType = GtkGridLayoutChildClass;
    using CppClassParent = LayoutChild_Class;
    using BaseClassParent = GtkLayoutChildClass;

    friend class GridLayoutChild;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
