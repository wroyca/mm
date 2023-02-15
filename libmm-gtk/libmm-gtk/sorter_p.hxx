// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SORTER_P_H
#define _GTKMM_SORTER_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Sorter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Sorter;
    using BaseObjectType = GtkSorter;
    using BaseClassType = GtkSorterClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Sorter;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    compare_vfunc_callback (GtkSorter* self, gpointer item1, gpointer item2)
        -> GtkOrdering;
    static auto
    get_order_vfunc_callback (GtkSorter* self) -> GtkSorterOrder;
  };

} // namespace Gtk

#endif
