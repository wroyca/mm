// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treeview.hxx>
  #include <libmm/gtk/treeview_p.hxx>

  #include <gtk/gtk.h>

  #include <climits>
  #include <gtk/gtk.h>
  #include <libmm/gdk/contentformats.hxx>
  #include <libmm/glib/vectorutils.hxx>
  #include <libmm/gtk/entry.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treemodelfilter.hxx>
  #include <libmm/gtk/treemodelsort.hxx>
  #include <libmm/gtk/treeview_private.hxx>
  #include <libmm/gtk/treeviewcolumn.hxx>

using GridLines = gtk::TreeView::GridLines;

static auto
SignalProxy_Mapping_gtk_callback (GtkTreeView* tree_view,
                                  GtkTreePath* path,
                                  void* data) -> void
{
  auto the_slot = static_cast<gtk::TreeView::SlotMapping*> (data);

  try
  {
    (*the_slot) (glib::wrap (tree_view), gtk::TreePath (path, true));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }
}

static auto
SignalProxy_SearchEqual_gtk_callback (GtkTreeModel* model,
                                      int column,
                                      const char* key,
                                      GtkTreeIter* iter,
                                      void* data) -> gboolean
{
  auto the_slot = static_cast<gtk::TreeView::SlotSearchEqual*> (data);

  try
  {
    return (*the_slot) (glib::wrap (model, true),
                        column,
                        key,
                        gtk::TreeModel::const_iterator (model, iter));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }

  return 0;
}

static auto
SignalProxy_SearchEqual_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::TreeView::SlotSearchEqual*> (data);
}

static auto
SignalProxy_ColumnDrop_gtk_callback (GtkTreeView* tree_view,
                                     GtkTreeViewColumn* column,
                                     GtkTreeViewColumn* prev_column,
                                     GtkTreeViewColumn* next_column,
                                     void* data) -> gboolean
{
  auto the_slot = static_cast<gtk::TreeView::SlotColumnDrop*> (data);

  try
  {
    return (*the_slot) (glib::wrap (tree_view),
                        glib::wrap (column),
                        glib::wrap (prev_column),
                        glib::wrap (next_column));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }

  return 0;
}

static auto
SignalProxy_ColumnDrop_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::TreeView::SlotColumnDrop*> (data);
}

namespace gtk
{

  auto
  TreeView::insert_column_with_data_func (int position,
                                          const glib::ustring& title,
                                          CellRenderer& cell,
                                          const SlotTreeCellData& slot) -> int
  {
    auto slot_copy = new SlotTreeCellData (slot);

    return gtk_tree_view_insert_column_with_data_func (
        gobj (),
        position,
        title.c_str (),
        cell.gobj (),
        &TreeView_Private::SignalProxy_CellData_gtk_callback,
        slot_copy,
        &TreeView_Private::SignalProxy_CellData_gtk_callback_destroy);
  }

  auto
  TreeView::set_cursor (const TreeModel::Path& path) -> void
  {
    gtk_tree_view_set_cursor (gobj (),
                              const_cast<GtkTreePath*> (path.gobj ()),
                              nullptr,
                              false);
  }

  auto
  TreeView::get_cursor (TreeModel::Path& path, TreeViewColumn*& focus_column) -> void
  {
    GtkTreePath* pTreePath = nullptr;
    GtkTreeViewColumn* pTreeViewColumn = nullptr;
    gtk_tree_view_get_cursor (gobj (), &pTreePath, &pTreeViewColumn);

    path = TreeModel::Path (pTreePath, false);
    focus_column = glib::wrap (pTreeViewColumn);
  }

  auto
  TreeView::enable_model_drag_source (gdk::ModifierType start_button_mask,
                                      gdk::DragAction actions) -> void
  {
    enable_model_drag_source (
        gdk::ContentFormats::create (GTK_TYPE_TREE_ROW_DATA),
        start_button_mask,
        actions);
  }

  auto
  TreeView::enable_model_drag_dest (gdk::DragAction actions) -> void
  {
    enable_model_drag_dest (
        gdk::ContentFormats::create (GTK_TYPE_TREE_ROW_DATA),
        actions);
  }

  auto
  TreeView::get_path_at_pos (int x,
                             int y,
                             TreeModel::Path& path,
                             TreeViewColumn*& column,
                             int& cell_x,
                             int& cell_y) const -> bool
  {
    GtkTreePath* pTreePath = nullptr;
    GtkTreeViewColumn* pTreeViewColumn = nullptr;
    const bool result = gtk_tree_view_get_path_at_pos (
        const_cast<GtkTreeView*> (gobj ()),
        x,
        y,
        &pTreePath,
        &pTreeViewColumn,
        &cell_x,
        &cell_y);

    path = TreeModel::Path (pTreePath, false);
    column = glib::wrap (pTreeViewColumn);
    return result;
  }

  auto
  TreeView::get_path_at_pos (int x, int y, TreeModel::Path& path) const -> bool
  {
    GtkTreePath* pTreePath = nullptr;
    const bool result = gtk_tree_view_get_path_at_pos (
        const_cast<GtkTreeView*> (gobj ()),
        x,
        y,
        &pTreePath,
        nullptr,
        nullptr,
        nullptr);

    path = TreeModel::Path (pTreePath, false);
    return result;
  }

  auto
  TreeView::insert_column (const glib::ustring& title,
                           CellRenderer& cell,
                           int position) -> int
  {
    return gtk_tree_view_insert_column_with_attributes (
        gobj (),
        position,
        const_cast<char*> (title.c_str ()),
        cell.gobj (),
        nullptr);
  }

  auto
  TreeView::append_column (const glib::ustring& title, CellRenderer& cell) -> int
  {
    return insert_column (title, cell, -1);
  }

  auto
  TreeView::get_drag_dest_row (TreeModel::Path& path, DropPosition& pos) const -> void
  {
    GtkTreePath* pTreePath = nullptr;
    gtk_tree_view_get_drag_dest_row (const_cast<GtkTreeView*> (gobj ()),
                                     &pTreePath,
                                     (GtkTreeViewDropPosition*) &pos);
    path = TreeModel::Path (pTreePath, true);
  }

  auto
  TreeView::get_dest_row_at_pos (int drag_x,
                                 int drag_y,
                                 TreeModel::Path& path,
                                 DropPosition& pos) const -> bool
  {
    GtkTreePath* pTreePath = nullptr;
    const bool bResult = gtk_tree_view_get_dest_row_at_pos (
        const_cast<GtkTreeView*> (gobj ()),
        drag_x,
        drag_y,
        &pTreePath,
        (GtkTreeViewDropPosition*) &pos);

    path = TreeModel::Path (pTreePath, true);
    return bResult;
  }

  auto
  TreeView::map_expanded_rows (const SlotMapping& slot) -> void
  {
    gtk_tree_view_map_expanded_rows (gobj (),
                                     &SignalProxy_Mapping_gtk_callback,
                                     const_cast<SlotMapping*> (&slot));
  }

  auto
  TreeView::set_search_equal_func (const SlotSearchEqual& slot) -> void
  {
    auto slot_copy = new SlotSearchEqual (slot);

    gtk_tree_view_set_search_equal_func (
        gobj (),
        &SignalProxy_SearchEqual_gtk_callback,
        slot_copy,
        &SignalProxy_SearchEqual_gtk_callback_destroy);
  }

  auto
  TreeView::set_column_drag_function (const SlotColumnDrop& slot) -> void
  {
    auto slot_copy = new SlotColumnDrop (slot);

    gtk_tree_view_set_column_drag_function (
        gobj (),
        &SignalProxy_ColumnDrop_gtk_callback,
        slot_copy,
        &SignalProxy_ColumnDrop_gtk_callback_destroy);
  }

  auto
  TreeView::unset_column_drag_function () -> void
  {
    gtk_tree_view_set_column_drag_function (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  TreeView::scroll_to_cell (const TreeModel::Path& path,
                            TreeViewColumn& column,
                            float row_align,
                            float col_align) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  const_cast<GtkTreePath*> (path.gobj ()),
                                  column.gobj (),
                                  TRUE,
                                  row_align,
                                  col_align);
  }

  auto
  TreeView::scroll_to_cell (const TreeModel::Path& path, TreeViewColumn& column) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  const_cast<GtkTreePath*> (path.gobj ()),
                                  column.gobj (),
                                  FALSE,
                                  0.0,
                                  0.0);
  }

  auto
  TreeView::scroll_to_row (const TreeModel::Path& path, float row_align) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  const_cast<GtkTreePath*> (path.gobj ()),
                                  nullptr,
                                  TRUE,
                                  row_align,
                                  0.0);
  }

  auto
  TreeView::scroll_to_row (const TreeModel::Path& path) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  const_cast<GtkTreePath*> (path.gobj ()),
                                  nullptr,
                                  FALSE,
                                  0.0,
                                  0.0);
  }

  auto
  TreeView::scroll_to_column (TreeViewColumn& column, float col_align) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  nullptr,
                                  column.gobj (),
                                  TRUE,
                                  0.0,
                                  col_align);
  }

  auto
  TreeView::scroll_to_column (TreeViewColumn& column) -> void
  {
    gtk_tree_view_scroll_to_cell (gobj (),
                                  nullptr,
                                  column.gobj (),
                                  FALSE,
                                  0.0,
                                  0.0);
  }

  auto
  TreeView::remove_all_columns () -> void
  {
    std::vector<gtk::TreeView::Column*> vecViewColumns (get_columns ());

    for (std::vector<gtk::TreeView::Column*>::iterator
             iter (vecViewColumns.begin ()),
         columns_end (vecViewColumns.end ());
         iter != columns_end;
         ++iter)
    {
      gtk::TreeView::Column* pViewColumn (*iter);

      if (pViewColumn)
      {
        remove_column (*pViewColumn);
      }
    }
  }

  auto
  TreeView::get_column_cell_renderer (int n) -> CellRenderer*
  {
    auto pColumn = get_column (n);
    if (pColumn)
      return pColumn->get_first_cell ();
    else
      return nullptr;
  }

  auto
  TreeView::get_column_cell_renderer (int n) const -> const CellRenderer*
  {
    auto pRenderer = const_cast<TreeView*> (this)->get_column_cell_renderer (n);
    return pRenderer;
  }

  auto
  TreeView::reset_expander_column () -> void
  {
    gtk_tree_view_set_expander_column (gobj (), nullptr);
  }

  auto
  TreeView::_auto_store_on_cellrenderer_toggle_edited_with_model (
      const glib::ustring& path_string,
      int model_column,
      const glib::RefPtr<gtk::TreeModel>& model) -> void
  {
    gtk::TreePath path (path_string);

    if (model)
    {
      auto iter = model->get_iter (path);
      if (iter)
      {
        auto row = *iter;

        bool bActive = false;
        row.get_value (model_column, bActive);
        bActive = !bActive;

        row.set_value (model_column, bActive);
      }
    }
  }

  auto
  TreeView::move_column_to_start (TreeViewColumn& column) -> void
  {
    gtk_tree_view_move_column_after (gobj (), (column).gobj (), nullptr);
  }

  auto
  TreeView::set_row_separator_func (const SlotRowSeparator& slot) -> void
  {
    auto slot_copy = new SlotRowSeparator (slot);

    gtk_tree_view_set_row_separator_func (
        gobj (),
        &TreeView_Private::SignalProxy_RowSeparator_gtk_callback,
        slot_copy,
        &TreeView_Private::SignalProxy_RowSeparator_gtk_callback_destroy);
  }

  auto
  TreeView::get_visible_range (TreeModel::Path& start_path,
                               TreeModel::Path& end_path) const -> bool
  {
    GtkTreePath* pTreePathStart = nullptr;
    GtkTreePath* pTreePathEnd = nullptr;
    bool result = gtk_tree_view_get_visible_range (
        const_cast<GtkTreeView*> (gobj ()),
        &pTreePathStart,
        &pTreePathEnd);

    start_path = TreeModel::Path (pTreePathStart, false);
    end_path = TreeModel::Path (pTreePathEnd, false);
    return result;
  }

  auto
  TreeView::unset_model () -> void
  {
    gtk_tree_view_set_model (gobj (), nullptr);
  }

  auto
  TreeView::get_tooltip_context_path (int x,
                                      int y,
                                      bool keyboard_tip,
                                      TreeModel::Path& path) -> bool
  {
    GtkTreePath* cpath = nullptr;

    gboolean result = gtk_tree_view_get_tooltip_context (gobj (),
                                                         x,
                                                         y,
                                                         keyboard_tip,
                                                         nullptr,
                                                         &cpath,
                                                         nullptr);

    path = glib::wrap (cpath, false);

    return result;
  }

  auto
  TreeView::get_tooltip_context_iter (int x,
                                      int y,
                                      bool keyboard_tip,
                                      gtk::TreeModel::iterator& iter) -> bool
  {
    GtkTreeIter src_iter;

    gboolean result = gtk_tree_view_get_tooltip_context (gobj (),
                                                         x,
                                                         y,
                                                         keyboard_tip,
                                                         nullptr,
                                                         nullptr,
                                                         &src_iter);

    iter = TreeModel::iterator (gtk_tree_view_get_model (this->gobj ()),
                                &src_iter);

    return result;
  }

  auto
  TreeView::is_blank_at_pos (int x,
                             int y,
                             TreePath& path,
                             TreeViewColumn*& column,
                             int& cell_x,
                             int& cell_y) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    GtkTreeViewColumn* pcolumn = nullptr;
    const bool result = gtk_tree_view_is_blank_at_pos (
        const_cast<GtkTreeView*> (gobj ()),
        x,
        y,
        &cpath,
        &pcolumn,
        &(cell_x),
        &(cell_y));

    path = TreePath (cpath, false);
    column = glib::wrap (pcolumn);
    return result;
  }

  auto
  TreeView::is_blank_at_pos (int x, int y) const -> bool
  {
    return gtk_tree_view_is_blank_at_pos (const_cast<GtkTreeView*> (gobj ()),
                                          x,
                                          y,
                                          nullptr,
                                          nullptr,
                                          nullptr,
                                          nullptr);
  }

  auto
  TreeView::unset_drag_dest_row () -> void
  {
    gtk_tree_view_set_drag_dest_row (gobj (),
                                     nullptr,
                                     GTK_TREE_VIEW_DROP_BEFORE);
  }

  auto
  TreeView::unset_row_separator_func () -> void
  {
    gtk_tree_view_set_row_separator_func (gobj (), nullptr, nullptr, nullptr);
  }

  namespace TreeView_Private
  {

    template <>
    auto
    _connect_auto_store_editable_signal_handler<bool> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<bool>& model_column) -> void
    {
      gtk::CellRendererToggle* pCellToggle =
          dynamic_cast<gtk::CellRendererToggle*> (pCellRenderer);
      if (pCellToggle)
      {
        pCellToggle->property_activatable () = true;

        sigc::slot<void (const glib::ustring&, int)> slot_temp =
            sigc::bind<-1> (
                sigc::mem_fun (
                    *this_p,
                    &gtk::TreeView::
                        _auto_store_on_cellrenderer_toggle_edited_with_model),
                this_p->get_model ());

        pCellToggle->signal_toggled ().connect (
            sigc::bind<-1> (slot_temp, model_column.index ()));
      }
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<int> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<int>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<int> (this_p,
                                                                pCellRenderer,
                                                                model_column);
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<unsigned int> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<unsigned int>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<unsigned int> (
          this_p,
          pCellRenderer,
          model_column);
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<long> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<long>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<long> (this_p,
                                                                 pCellRenderer,
                                                                 model_column);
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<unsigned long> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<unsigned long>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<unsigned long> (
          this_p,
          pCellRenderer,
          model_column);
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<float> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<float>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<float> (this_p,
                                                                  pCellRenderer,
                                                                  model_column);
    }

    template <>
    auto
    _connect_auto_store_editable_signal_handler<double> (
        gtk::TreeView* this_p,
        gtk::CellRenderer* pCellRenderer,
        const gtk::TreeModelColumn<double>& model_column) -> void
    {
      _connect_auto_store_numeric_editable_signal_handler<double> (
          this_p,
          pCellRenderer,
          model_column);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<float> (const glib::ustring& text)
        -> float
    {
      return std::strtof (text.c_str (), nullptr);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<long double> (
        const glib::ustring& text) -> long double
    {
      return std::strtold (text.c_str (), nullptr);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<short> (const glib::ustring& text)
        -> short
    {
      const auto result = std::strtol (text.c_str (), nullptr, 0);
      return (result < SHRT_MIN) ?
                 SHRT_MIN :
                 ((result > SHRT_MAX) ? SHRT_MAX : static_cast<short> (result));
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<unsigned short> (
        const glib::ustring& text) -> unsigned short
    {
      const auto result = std::strtoul (text.c_str (), nullptr, 0);
      return (result > USHRT_MAX) ? USHRT_MAX :
                                    static_cast<unsigned short> (result);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<int> (const glib::ustring& text)
        -> int
    {
      const auto result = std::strtol (text.c_str (), nullptr, 0);
      return (result < INT_MIN) ?
                 INT_MIN :
                 ((result > INT_MAX) ? INT_MAX : static_cast<int> (result));
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<unsigned int> (
        const glib::ustring& text) -> unsigned int
    {
      const auto result = std::strtoul (text.c_str (), nullptr, 0);
      return (result > UINT_MAX) ? UINT_MAX :
                                   static_cast<unsigned int> (result);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<long> (const glib::ustring& text)
        -> long
    {
      return std::strtol (text.c_str (), nullptr, 0);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<unsigned long> (
        const glib::ustring& text) -> unsigned long
    {
      return std::strtoul (text.c_str (), nullptr, 0);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<long long> (const glib::ustring& text)
        -> long long
    {
      return std::strtoll (text.c_str (), nullptr, 0);
    }

    template <>
    auto
    _convert_from_ustring_to_numeric_type<unsigned long long> (
        const glib::ustring& text) -> unsigned long long
    {
      return std::strtoull (text.c_str (), nullptr, 0);
    }

  } // namespace TreeView_Private

} // namespace gtk

namespace
{

  static auto
  TreeView_signal_row_activated_callback (GtkTreeView* self,
                                          GtkTreePath* p0,
                                          GtkTreeViewColumn* p1,
                                          void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const TreeModel::Path&, TreeViewColumn*)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (gtk::TreePath (p0, true),
                                            glib::wrap (p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TreeView_signal_row_activated_info = {
      "row-activated",
      (GCallback) &TreeView_signal_row_activated_callback,
      (GCallback) &TreeView_signal_row_activated_callback};

  static auto
  TreeView_signal_test_expand_row_callback (GtkTreeView* self,
                                            GtkTreeIter* p0,
                                            GtkTreePath* p1,
                                            void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<bool (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  TreeView_signal_test_expand_row_notify_callback (GtkTreeView* self,
                                                   GtkTreeIter* p0,
                                                   GtkTreePath* p1,
                                                   void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo TreeView_signal_test_expand_row_info = {
      "test-expand-row",
      (GCallback) &TreeView_signal_test_expand_row_callback,
      (GCallback) &TreeView_signal_test_expand_row_notify_callback};

  static auto
  TreeView_signal_test_collapse_row_callback (GtkTreeView* self,
                                              GtkTreeIter* p0,
                                              GtkTreePath* p1,
                                              void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<bool (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  TreeView_signal_test_collapse_row_notify_callback (GtkTreeView* self,
                                                     GtkTreeIter* p0,
                                                     GtkTreePath* p1,
                                                     void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo TreeView_signal_test_collapse_row_info = {
      "test-collapse-row",
      (GCallback) &TreeView_signal_test_collapse_row_callback,
      (GCallback) &TreeView_signal_test_collapse_row_notify_callback};

  static auto
  TreeView_signal_row_expanded_callback (GtkTreeView* self,
                                         GtkTreeIter* p0,
                                         GtkTreePath* p1,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TreeView_signal_row_expanded_info = {
      "row-expanded",
      (GCallback) &TreeView_signal_row_expanded_callback,
      (GCallback) &TreeView_signal_row_expanded_callback};

  static auto
  TreeView_signal_row_collapsed_callback (GtkTreeView* self,
                                          GtkTreeIter* p0,
                                          GtkTreePath* p1,
                                          void* data) -> void
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const TreeModel::iterator&, const TreeModel::Path&)>;

    auto obj = dynamic_cast<TreeView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              TreeModel::iterator (gtk_tree_view_get_model (self), p0),
              gtk::TreePath (p1, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TreeView_signal_row_collapsed_info = {
      "row-collapsed",
      (GCallback) &TreeView_signal_row_collapsed_callback,
      (GCallback) &TreeView_signal_row_collapsed_callback};

  static const glib::SignalProxyInfo TreeView_signal_cursor_changed_info = {
      "cursor-changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo TreeView_signal_columns_changed_info = {
      "columns-changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gtk::TreeView::DropPosition>::value_type () -> GType
{
  return gtk_tree_view_drop_position_get_type ();
}

auto
glib::Value<gtk::TreeView::GridLines>::value_type () -> GType
{
  return gtk_tree_view_grid_lines_get_type ();
}

namespace glib
{

  auto
  wrap (GtkTreeView* object, bool take_copy) -> gtk::TreeView*
  {
    return dynamic_cast<gtk::TreeView*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeView_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeView_Class::class_init_function;

      register_derived_type (gtk_tree_view_get_type ());

      Scrollable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TreeView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeView_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TreeView ((GtkTreeView*) (o)));
  }

  TreeView::TreeView (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  TreeView::TreeView (GtkTreeView* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TreeView::TreeView (TreeView&& src) noexcept
    : gtk::Widget (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  TreeView::operator= (TreeView&& src) noexcept -> TreeView&
  {
    gtk::Widget::operator= (std::move (src));
    Scrollable::operator= (std::move (src));
    return *this;
  }

  TreeView::~TreeView () noexcept
  {
    destroy_ ();
  }

  TreeView::CppClassType TreeView::treeview_class_;

  auto
  TreeView::get_type () -> GType
  {
    return treeview_class_.init ().get_type ();
  }

  auto
  TreeView::get_base_type () -> GType
  {
    return gtk_tree_view_get_type ();
  }

  TreeView::TreeView ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (treeview_class_.init ()))
  {
  }

  TreeView::TreeView (const glib::RefPtr<TreeModel>& model)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (treeview_class_.init (),
                                          "model",
                                          glib::unwrap (model),
                                          nullptr))
  {
  }

  auto
  TreeView::get_model () -> glib::RefPtr<TreeModel>
  {
    auto retvalue = glib::wrap (gtk_tree_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeView::get_model () const -> glib::RefPtr<const TreeModel>
  {
    auto retvalue = glib::wrap (
        gtk_tree_view_get_model (const_cast<GtkTreeView*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeView::set_model (const glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_tree_view_set_model (gobj (), glib::unwrap (model));
  }

  auto
  TreeView::get_selection () -> glib::RefPtr<TreeSelection>
  {
    auto retvalue = glib::wrap (gtk_tree_view_get_selection (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeView::get_selection () const -> glib::RefPtr<const TreeSelection>
  {
    return const_cast<TreeView*> (this)->get_selection ();
  }

  auto
  TreeView::get_headers_visible () const -> bool
  {
    return gtk_tree_view_get_headers_visible (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_headers_visible (bool headers_visible) -> void
  {
    gtk_tree_view_set_headers_visible (gobj (),
                                       static_cast<int> (headers_visible));
  }

  auto
  TreeView::columns_autosize () -> void
  {
    gtk_tree_view_columns_autosize (gobj ());
  }

  auto
  TreeView::get_headers_clickable () const -> bool
  {
    return gtk_tree_view_get_headers_clickable (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_headers_clickable (bool setting) -> void
  {
    gtk_tree_view_set_headers_clickable (gobj (), static_cast<int> (setting));
  }

  auto
  TreeView::set_activate_on_single_click (bool single) -> void
  {
    gtk_tree_view_set_activate_on_single_click (gobj (),
                                                static_cast<int> (single));
  }

  auto
  TreeView::get_activate_on_single_click () const -> bool
  {
    return gtk_tree_view_get_activate_on_single_click (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::append_column (TreeViewColumn& column) -> int
  {
    return gtk_tree_view_append_column (gobj (), (column).gobj ());
  }

  auto
  TreeView::remove_column (TreeViewColumn& column) -> int
  {
    return gtk_tree_view_remove_column (gobj (), (column).gobj ());
  }

  auto
  TreeView::insert_column (TreeViewColumn& column, int position) -> int
  {
    return gtk_tree_view_insert_column (gobj (), (column).gobj (), position);
  }

  auto
  TreeView::get_n_columns () const -> guint
  {
    return gtk_tree_view_get_n_columns (const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::get_column (int n) -> TreeViewColumn*
  {
    return glib::wrap (gtk_tree_view_get_column (gobj (), n));
  }

  auto
  TreeView::get_column (int n) const -> const TreeViewColumn*
  {
    return const_cast<TreeView*> (this)->get_column (n);
  }

  auto
  TreeView::get_columns () -> std::vector<TreeViewColumn*>
  {
    return glib::ListHandler<TreeViewColumn*>::list_to_vector (
        gtk_tree_view_get_columns (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TreeView::get_columns () const -> std::vector<const TreeViewColumn*>
  {
    return glib::ListHandler<const TreeViewColumn*>::list_to_vector (
        gtk_tree_view_get_columns (const_cast<GtkTreeView*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TreeView::move_column_after (TreeViewColumn& column,
                               TreeViewColumn& base_column) -> void
  {
    gtk_tree_view_move_column_after (gobj (),
                                     (column).gobj (),
                                     (base_column).gobj ());
  }

  auto
  TreeView::set_expander_column (TreeViewColumn& column) -> void
  {
    gtk_tree_view_set_expander_column (gobj (), (column).gobj ());
  }

  auto
  TreeView::get_expander_column () -> TreeViewColumn*
  {
    return glib::wrap (gtk_tree_view_get_expander_column (gobj ()));
  }

  auto
  TreeView::get_expander_column () const -> const TreeViewColumn*
  {
    return const_cast<TreeView*> (this)->get_expander_column ();
  }

  auto
  TreeView::scroll_to_point (int tree_x, int tree_y) -> void
  {
    gtk_tree_view_scroll_to_point (gobj (), tree_x, tree_y);
  }

  auto
  TreeView::row_activated (const TreeModel::Path& path, TreeViewColumn& column) -> void
  {
    gtk_tree_view_row_activated (gobj (),
                                 const_cast<GtkTreePath*> ((path).gobj ()),
                                 (column).gobj ());
  }

  auto
  TreeView::expand_all () -> void
  {
    gtk_tree_view_expand_all (gobj ());
  }

  auto
  TreeView::collapse_all () -> void
  {
    gtk_tree_view_collapse_all (gobj ());
  }

  auto
  TreeView::expand_to_path (const TreeModel::Path& path) -> void
  {
    gtk_tree_view_expand_to_path (gobj (),
                                  const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeView::expand_row (const TreeModel::Path& path, bool open_all) -> bool
  {
    return gtk_tree_view_expand_row (gobj (),
                                     const_cast<GtkTreePath*> ((path).gobj ()),
                                     static_cast<int> (open_all));
  }

  auto
  TreeView::collapse_row (const TreeModel::Path& path) -> bool
  {
    return gtk_tree_view_collapse_row (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeView::row_expanded (const TreeModel::Path& path) -> bool
  {
    return gtk_tree_view_row_expanded (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeView::set_reorderable (bool reorderable) -> void
  {
    gtk_tree_view_set_reorderable (gobj (), static_cast<int> (reorderable));
  }

  auto
  TreeView::get_reorderable () const -> bool
  {
    return gtk_tree_view_get_reorderable (const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_cursor (const TreeModel::Path& path,
                        TreeViewColumn& focus_column,
                        bool start_editing) -> void
  {
    gtk_tree_view_set_cursor (gobj (),
                              const_cast<GtkTreePath*> ((path).gobj ()),
                              (focus_column).gobj (),
                              static_cast<int> (start_editing));
  }

  auto
  TreeView::set_cursor (const TreeModel::Path& path,
                        TreeViewColumn& focus_column,
                        CellRenderer& focus_cell,
                        bool start_editing) -> void
  {
    gtk_tree_view_set_cursor_on_cell (gobj (),
                                      const_cast<GtkTreePath*> ((path).gobj ()),
                                      (focus_column).gobj (),
                                      (focus_cell).gobj (),
                                      static_cast<int> (start_editing));
  }

  auto
  TreeView::get_cell_area (const TreeModel::Path& path,
                           TreeViewColumn& column,
                           gdk::Rectangle& rect) const -> void
  {
    gtk_tree_view_get_cell_area (const_cast<GtkTreeView*> (gobj ()),
                                 const_cast<GtkTreePath*> ((path).gobj ()),
                                 (column).gobj (),
                                 (rect).gobj ());
  }

  auto
  TreeView::get_background_area (const TreeModel::Path& path,
                                 TreeViewColumn& column,
                                 gdk::Rectangle& rect) const -> void
  {
    gtk_tree_view_get_background_area (
        const_cast<GtkTreeView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()),
        (column).gobj (),
        (rect).gobj ());
  }

  auto
  TreeView::get_visible_rect (gdk::Rectangle& visible_rect) const -> void
  {
    gtk_tree_view_get_visible_rect (const_cast<GtkTreeView*> (gobj ()),
                                    (visible_rect).gobj ());
  }

  auto
  TreeView::enable_model_drag_source (
      const glib::RefPtr<const gdk::ContentFormats>& formats,
      gdk::ModifierType start_button_mask,
      gdk::DragAction actions) -> void
  {
    gtk_tree_view_enable_model_drag_source (
        gobj (),
        static_cast<GdkModifierType> (start_button_mask),
        const_cast<GdkContentFormats*> (glib::unwrap (formats)),
        static_cast<GdkDragAction> (actions));
  }

  auto
  TreeView::enable_model_drag_dest (
      const glib::RefPtr<const gdk::ContentFormats>& formats,
      gdk::DragAction actions) -> void
  {
    gtk_tree_view_enable_model_drag_dest (
        gobj (),
        const_cast<GdkContentFormats*> (glib::unwrap (formats)),
        static_cast<GdkDragAction> (actions));
  }

  auto
  TreeView::unset_rows_drag_source () -> void
  {
    gtk_tree_view_unset_rows_drag_source (gobj ());
  }

  auto
  TreeView::unset_rows_drag_dest () -> void
  {
    gtk_tree_view_unset_rows_drag_dest (gobj ());
  }

  auto
  TreeView::set_drag_dest_row (const TreeModel::Path& path, DropPosition pos) -> void
  {
    gtk_tree_view_set_drag_dest_row (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()),
        static_cast<GtkTreeViewDropPosition> (pos));
  }

  auto
  TreeView::create_row_drag_icon (const TreeModel::Path& path) const -> glib::RefPtr<gdk::Paintable>
  {
    return glib::wrap (gtk_tree_view_create_row_drag_icon (
        const_cast<GtkTreeView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ())));
  }

  auto
  TreeView::set_enable_search (bool enable_search) -> void
  {
    gtk_tree_view_set_enable_search (gobj (), static_cast<int> (enable_search));
  }

  auto
  TreeView::get_enable_search () const -> bool
  {
    return gtk_tree_view_get_enable_search (const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::get_search_column () const -> int
  {
    return gtk_tree_view_get_search_column (const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_search_column (const TreeModelColumnBase& column) -> void
  {
    gtk_tree_view_set_search_column (gobj (), (column).index ());
  }

  auto
  TreeView::set_search_column (int column) -> void
  {
    gtk_tree_view_set_search_column (gobj (), column);
  }

  auto
  TreeView::get_search_entry () -> Editable*
  {
    return dynamic_cast<Editable*> (
        glib::wrap_auto ((GObject*) (gtk_tree_view_get_search_entry (gobj ())),
                         false));
  }

  auto
  TreeView::get_search_entry () const -> const Editable*
  {
    return const_cast<TreeView*> (this)->get_search_entry ();
  }

  auto
  TreeView::set_search_entry (Editable& entry) -> void
  {
    gtk_tree_view_set_search_entry (gobj (), (entry).gobj ());
  }

  auto
  TreeView::convert_widget_to_tree_coords (int wx,
                                           int wy,
                                           int& tx,
                                           int& ty) const -> void
  {
    gtk_tree_view_convert_widget_to_tree_coords (
        const_cast<GtkTreeView*> (gobj ()),
        wx,
        wy,
        &(tx),
        &(ty));
  }

  auto
  TreeView::convert_tree_to_widget_coords (int tx,
                                           int ty,
                                           int& wx,
                                           int& wy) const -> void
  {
    gtk_tree_view_convert_tree_to_widget_coords (
        const_cast<GtkTreeView*> (gobj ()),
        tx,
        ty,
        &(wx),
        &(wy));
  }

  auto
  TreeView::convert_widget_to_bin_window_coords (int wx,
                                                 int wy,
                                                 int& bx,
                                                 int& by) const -> void
  {
    gtk_tree_view_convert_widget_to_bin_window_coords (
        const_cast<GtkTreeView*> (gobj ()),
        wx,
        wy,
        &(bx),
        &(by));
  }

  auto
  TreeView::convert_bin_window_to_widget_coords (int bx,
                                                 int by,
                                                 int& wx,
                                                 int& wy) const -> void
  {
    gtk_tree_view_convert_bin_window_to_widget_coords (
        const_cast<GtkTreeView*> (gobj ()),
        bx,
        by,
        &(wx),
        &(wy));
  }

  auto
  TreeView::convert_tree_to_bin_window_coords (int tx,
                                               int ty,
                                               int& bx,
                                               int& by) const -> void
  {
    gtk_tree_view_convert_tree_to_bin_window_coords (
        const_cast<GtkTreeView*> (gobj ()),
        tx,
        ty,
        &(bx),
        &(by));
  }

  auto
  TreeView::convert_bin_window_to_tree_coords (int bx,
                                               int by,
                                               int& tx,
                                               int& ty) const -> void
  {
    gtk_tree_view_convert_bin_window_to_tree_coords (
        const_cast<GtkTreeView*> (gobj ()),
        bx,
        by,
        &(tx),
        &(ty));
  }

  auto
  TreeView::set_fixed_height_mode (bool enable) -> void
  {
    gtk_tree_view_set_fixed_height_mode (gobj (), static_cast<int> (enable));
  }

  auto
  TreeView::get_fixed_height_mode () const -> bool
  {
    return gtk_tree_view_get_fixed_height_mode (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_hover_selection (bool hover) -> void
  {
    gtk_tree_view_set_hover_selection (gobj (), static_cast<int> (hover));
  }

  auto
  TreeView::get_hover_selection () const -> bool
  {
    return gtk_tree_view_get_hover_selection (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_hover_expand (bool expand) -> void
  {
    gtk_tree_view_set_hover_expand (gobj (), static_cast<int> (expand));
  }

  auto
  TreeView::get_hover_expand () const -> bool
  {
    return gtk_tree_view_get_hover_expand (const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_rubber_banding (bool enable) -> void
  {
    gtk_tree_view_set_rubber_banding (gobj (), static_cast<int> (enable));
  }

  auto
  TreeView::get_rubber_banding () const -> bool
  {
    return gtk_tree_view_get_rubber_banding (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::is_rubber_banding_active () const -> bool
  {
    return gtk_tree_view_is_rubber_banding_active (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_grid_lines (GridLines grid_lines) -> void
  {
    gtk_tree_view_set_grid_lines (
        gobj (),
        static_cast<GtkTreeViewGridLines> (grid_lines));
  }

  auto
  TreeView::get_grid_lines () const -> GridLines
  {
    return static_cast<GridLines> (
        gtk_tree_view_get_grid_lines (const_cast<GtkTreeView*> (gobj ())));
  }

  auto
  TreeView::set_enable_tree_lines (bool enable) -> void
  {
    gtk_tree_view_set_enable_tree_lines (gobj (), static_cast<int> (enable));
  }

  auto
  TreeView::get_enable_tree_lines () const -> bool
  {
    return gtk_tree_view_get_enable_tree_lines (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_show_expanders (bool enabled) -> void
  {
    gtk_tree_view_set_show_expanders (gobj (), static_cast<int> (enabled));
  }

  auto
  TreeView::get_show_expanders () const -> bool
  {
    return gtk_tree_view_get_show_expanders (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_level_indentation (int indentation) -> void
  {
    gtk_tree_view_set_level_indentation (gobj (), indentation);
  }

  auto
  TreeView::get_level_indentation () const -> int
  {
    return gtk_tree_view_get_level_indentation (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::set_tooltip_row (const glib::RefPtr<Tooltip>& tooltip,
                             const TreePath& path) -> void
  {
    gtk_tree_view_set_tooltip_row (gobj (),
                                   glib::unwrap (tooltip),
                                   const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeView::set_tooltip_cell (const glib::RefPtr<Tooltip>& tooltip,
                              const TreeModel::Path* path,
                              TreeViewColumn* column,
                              CellRenderer* cell) -> void
  {
    gtk_tree_view_set_tooltip_cell (
        gobj (),
        glib::unwrap (tooltip),
        ((path) ? const_cast<GtkTreePath*> ((path)->gobj ()) : nullptr),
        (GtkTreeViewColumn*) glib::unwrap (column),
        (GtkCellRenderer*) glib::unwrap (cell));
  }

  auto
  TreeView::set_tooltip_column (int column) -> void
  {
    gtk_tree_view_set_tooltip_column (gobj (), column);
  }

  auto
  TreeView::get_tooltip_column () const -> int
  {
    return gtk_tree_view_get_tooltip_column (
        const_cast<GtkTreeView*> (gobj ()));
  }

  auto
  TreeView::signal_row_activated () -> glib::SignalProxy<void (const TreeModel::Path&, TreeViewColumn*)>
  {
    return glib::SignalProxy<void (const TreeModel::Path&, TreeViewColumn*)> (
        this,
        &TreeView_signal_row_activated_info);
  }

  auto
  TreeView::signal_test_expand_row () -> glib::SignalProxy<bool (const TreeModel::iterator&,
                                 const TreeModel::Path&)>
  {
    return glib::SignalProxy<bool (const TreeModel::iterator&,
                                   const TreeModel::Path&)> (
        this,
        &TreeView_signal_test_expand_row_info);
  }

  auto
  TreeView::signal_test_collapse_row () -> glib::SignalProxy<bool (const TreeModel::iterator&,
                                 const TreeModel::Path&)>
  {
    return glib::SignalProxy<bool (const TreeModel::iterator&,
                                   const TreeModel::Path&)> (
        this,
        &TreeView_signal_test_collapse_row_info);
  }

  auto
  TreeView::signal_row_expanded () -> glib::SignalProxy<void (const TreeModel::iterator&,
                                 const TreeModel::Path&)>
  {
    return glib::SignalProxy<void (const TreeModel::iterator&,
                                   const TreeModel::Path&)> (
        this,
        &TreeView_signal_row_expanded_info);
  }

  auto
  TreeView::signal_row_collapsed () -> glib::SignalProxy<void (const TreeModel::iterator&,
                                 const TreeModel::Path&)>
  {
    return glib::SignalProxy<void (const TreeModel::iterator&,
                                   const TreeModel::Path&)> (
        this,
        &TreeView_signal_row_collapsed_info);
  }

  auto
  TreeView::signal_cursor_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &TreeView_signal_cursor_changed_info);
  }

  auto
  TreeView::signal_columns_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &TreeView_signal_columns_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TreeModel>>::value,
      "Type glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeView::property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<TreeModel>> (this, "model");
  }

  auto
  TreeView::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

  auto
  TreeView::property_headers_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "headers-visible");
  }

  auto
  TreeView::property_headers_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "headers-visible");
  }

  auto
  TreeView::property_headers_clickable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "headers-clickable");
  }

  auto
  TreeView::property_headers_clickable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "headers-clickable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<TreeViewColumn*>::value,
      "Type TreeViewColumn* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeView::property_expander_column () -> glib::PropertyProxy<TreeViewColumn*>
  {
    return glib::PropertyProxy<TreeViewColumn*> (this, "expander-column");
  }

  auto
  TreeView::property_expander_column () const -> glib::PropertyProxy_ReadOnly<TreeViewColumn*>
  {
    return glib::PropertyProxy_ReadOnly<TreeViewColumn*> (this,
                                                          "expander-column");
  }

  auto
  TreeView::property_reorderable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reorderable");
  }

  auto
  TreeView::property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reorderable");
  }

  auto
  TreeView::property_enable_search () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-search");
  }

  auto
  TreeView::property_enable_search () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-search");
  }

  auto
  TreeView::property_search_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "search-column");
  }

  auto
  TreeView::property_search_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "search-column");
  }

  auto
  TreeView::property_fixed_height_mode () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "fixed-height-mode");
  }

  auto
  TreeView::property_fixed_height_mode () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "fixed-height-mode");
  }

  auto
  TreeView::property_hover_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hover-selection");
  }

  auto
  TreeView::property_hover_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hover-selection");
  }

  auto
  TreeView::property_hover_expand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "hover-expand");
  }

  auto
  TreeView::property_hover_expand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "hover-expand");
  }

  auto
  TreeView::property_show_expanders () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-expanders");
  }

  auto
  TreeView::property_show_expanders () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-expanders");
  }

  auto
  TreeView::property_level_indentation () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "level-indentation");
  }

  auto
  TreeView::property_level_indentation () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "level-indentation");
  }

  auto
  TreeView::property_rubber_banding () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "rubber-banding");
  }

  auto
  TreeView::property_rubber_banding () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "rubber-banding");
  }

  auto
  TreeView::property_enable_grid_lines () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-grid-lines");
  }

  auto
  TreeView::property_enable_grid_lines () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-grid-lines");
  }

  auto
  TreeView::property_enable_tree_lines () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-tree-lines");
  }

  auto
  TreeView::property_enable_tree_lines () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-tree-lines");
  }

  auto
  TreeView::property_tooltip_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "tooltip-column");
  }

  auto
  TreeView::property_tooltip_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "tooltip-column");
  }

  auto
  TreeView::property_activate_on_single_click () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activate-on-single-click");
  }

  auto
  TreeView::property_activate_on_single_click () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "activate-on-single-click");
  }

} // namespace gtk

#endif
