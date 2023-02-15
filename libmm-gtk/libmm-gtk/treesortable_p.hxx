// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREESORTABLE_P_H
#define _GTKMM_TREESORTABLE_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/interface_p.hxx>

  #include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API TreeSortable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = TreeSortable;
    using BaseObjectType = GtkTreeSortable;
    using BaseClassType = GtkTreeSortableIface;
    using CppClassParent = Glib::Interface_Class;

    friend class TreeSortable;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    sort_column_changed_callback (GtkTreeSortable* self) -> void;

    static auto
    get_sort_column_id_vfunc_callback (GtkTreeSortable* self,
                                       int* sort_column_id,
                                       GtkSortType* order) -> gboolean;
    static auto
    set_sort_column_id_vfunc_callback (GtkTreeSortable* self,
                                       int sort_column_id,
                                       GtkSortType order) -> void;
    static auto
    set_sort_func_vfunc_callback (GtkTreeSortable* self,
                                  int sort_column_id,
                                  GtkTreeIterCompareFunc func,
                                  gpointer data,
                                  GDestroyNotify destroy) -> void;
    static auto
    set_default_sort_func_vfunc_callback (GtkTreeSortable* self,
                                          GtkTreeIterCompareFunc func,
                                          gpointer data,
                                          GDestroyNotify destroy) -> void;
    static auto
    has_default_sort_func_vfunc_callback (GtkTreeSortable* self) -> gboolean;
    static auto
    sort_column_changed_vfunc_callback (GtkTreeSortable* self) -> void;
  };

} // namespace Gtk

#endif

#endif
