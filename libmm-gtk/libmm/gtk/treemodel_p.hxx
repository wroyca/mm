// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEMODEL_P_H
#define _GTKMM_TREEMODEL_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/interface_p.hxx>

  #include <libmm/glib/interface_p.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeModel_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = TreeModel;
    using BaseObjectType = GtkTreeModel;
    using BaseClassType = GtkTreeModelIface;
    using CppClassParent = Glib::Interface_Class;

    friend class TreeModel;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    row_changed_callback (GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1)
        -> void;
    static auto
    row_inserted_callback (GtkTreeModel* self, GtkTreePath* p0, GtkTreeIter* p1)
        -> void;
    static auto
    row_has_child_toggled_callback (GtkTreeModel* self,
                                    GtkTreePath* p0,
                                    GtkTreeIter* p1) -> void;
    static auto
    row_deleted_callback (GtkTreeModel* self, GtkTreePath* p0) -> void;
    static auto
    rows_reordered_callback (GtkTreeModel* self,
                             GtkTreePath* p0,
                             GtkTreeIter* p1,
                             gint* p2) -> void;

    static auto
    get_flags_vfunc_callback (GtkTreeModel* self) -> GtkTreeModelFlags;
    static auto
    get_n_columns_vfunc_callback (GtkTreeModel* self) -> gint;
    static auto
    get_column_type_vfunc_callback (GtkTreeModel* self, gint index) -> GType;
    static auto
    iter_next_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter)
        -> gboolean;
    static auto
    get_iter_vfunc_callback (GtkTreeModel* self,
                             GtkTreeIter* iter,
                             GtkTreePath* path) -> gboolean;
    static auto
    iter_children_vfunc_callback (GtkTreeModel* self,
                                  GtkTreeIter* iter,
                                  GtkTreeIter* parent) -> gboolean;
    static auto
    iter_parent_vfunc_callback (GtkTreeModel* self,
                                GtkTreeIter* iter,
                                GtkTreeIter* child) -> gboolean;
    static auto
    iter_nth_child_vfunc_callback (GtkTreeModel* self,
                                   GtkTreeIter* iter,
                                   GtkTreeIter* parent,
                                   int n) -> gboolean;
    static auto
    iter_n_children_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter)
        -> int;
    static auto
    iter_has_child_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter)
        -> gboolean;
    static auto
    ref_node_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter) -> void;
    static auto
    unref_node_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter) -> void;
    static auto
    get_path_vfunc_callback (GtkTreeModel* self, GtkTreeIter* iter)
        -> GtkTreePath*;
    static auto
    get_value_vfunc_callback (GtkTreeModel* self,
                              GtkTreeIter* iter,
                              gint column,
                              GValue* value) -> void;
  };

} // namespace Gtk

#endif

#endif
