// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEVIEW_H
#define _GTKMM_TREEVIEW_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <cstdlib>
#include <libmm-gtk/cellrenderer.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/scrollable.hxx>
#include <libmm-gtk/tooltip.hxx>
#include <libmm-gtk/treemodelcolumn.hxx>
#include <libmm-gtk/treeselection.hxx>
#include <libmm-gtk/treeviewcolumn.hxx>
#include <libmm-gtk/widget.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeView = struct _GtkTreeView;
using GtkTreeViewClass = struct _GtkTreeViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeView_Class;
}
#endif

namespace Gdk
{
  class ContentFormats;
}

namespace Gtk
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class TreeView;

  namespace TreeView_Private
  {

    template <class ColumnType>
    void
    _connect_auto_store_editable_signal_handler (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<ColumnType>& model_column);

    template <class ColumnType>
    inline void
    _connect_auto_store_numeric_editable_signal_handler (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<ColumnType>& model_column);

    template <class ColumnType>
    inline void
    _auto_store_on_cellrenderer_text_edited_string (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model);

    template <class ColumnType>
    inline void
    _auto_store_on_cellrenderer_text_edited_numerical (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model);

    template <class ColumnType>
    inline void
    _auto_cell_data_func (Gtk::CellRenderer* cell,
                          const Gtk::TreeModel::const_iterator& iter,
                          int model_column,
                          const Glib::ustring& format);

    template <typename T>
    auto
    _convert_from_ustring_to_numeric_type (const Glib::ustring& text) -> T;
  } // namespace TreeView_Private

#endif

  class TreeModel;

  class GTKMM_API TreeView : public Widget,
                             public Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TreeView CppObjectType;
    typedef TreeView_Class CppClassType;
    typedef GtkTreeView BaseObjectType;
    typedef GtkTreeViewClass BaseClassType;
#endif

    TreeView (TreeView&& src) noexcept;
    auto
    operator= (TreeView&& src) noexcept -> TreeView&;

    TreeView (const TreeView&) = delete;
    auto
    operator= (const TreeView&) -> TreeView& = delete;

    ~TreeView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class TreeView_Class;
    static CppClassType treeview_class_;

  protected:
    explicit TreeView (const Glib::ConstructParams& construct_params);
    explicit TreeView (GtkTreeView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeView*
    {
      return reinterpret_cast<GtkTreeView*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeView*
    {
      return reinterpret_cast<GtkTreeView*> (gobject_);
    }

  private:
  public:
    enum class DropPosition
    {
      BEFORE,
      AFTER,
      INTO_OR_BEFORE,
      INTO_OR_AFTER
    };

    enum class GridLines
    {
      NONE,
      HORIZONTAL,
      VERTICAL,
      BOTH
    };

    typedef TreeViewColumn Column;

    typedef TreeSelection Selection;

    TreeView ();

    explicit TreeView (const Glib::RefPtr<TreeModel>& model);

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    void
    set_model (const Glib::RefPtr<TreeModel>& model);

    void
    unset_model ();

    auto
    get_selection () -> Glib::RefPtr<TreeSelection>;

    auto
    get_selection () const -> Glib::RefPtr<const TreeSelection>;

    auto
    get_headers_visible () const -> bool;

    void
    set_headers_visible (bool headers_visible = true);

    void
    columns_autosize ();

    auto
    get_headers_clickable () const -> bool;

    void
    set_headers_clickable (bool setting = true);

    void
    set_activate_on_single_click (bool single = true);

    auto
    get_activate_on_single_click () const -> bool;

    auto
    append_column (TreeViewColumn& column) -> int;

    template <class ColumnType>
    inline auto
    append_column (const Glib::ustring& title,
                   const TreeModelColumn<ColumnType>& model_column) -> int;

    template <class ColumnType>
    inline auto
    append_column_numeric (const Glib::ustring& title,
                           const TreeModelColumn<ColumnType>& model_column,
                           const Glib::ustring& format) -> int;

    template <class ColumnType>
    inline auto
    append_column_editable (const Glib::ustring& title,
                            const TreeModelColumn<ColumnType>& model_column)
        -> int;

    template <class ColumnType>
    inline auto
    append_column_numeric_editable (
        const Glib::ustring& title,
        const TreeModelColumn<ColumnType>& model_column,
        const Glib::ustring& format) -> int;

    auto
    append_column (const Glib::ustring& title, CellRenderer& cell) -> int;

    auto
    remove_column (TreeViewColumn& column) -> int;

    void
    remove_all_columns ();

    auto
    insert_column (TreeViewColumn& column, int position) -> int;

    auto
    insert_column (const Glib::ustring& title, CellRenderer& cell, int position)
        -> int;

    template <class ColumnType>
    inline auto
    insert_column (const Glib::ustring& title,
                   const TreeModelColumn<ColumnType>& model_column,
                   int position) -> int;

    template <class ColumnType>
    inline auto
    insert_column_editable (const Glib::ustring& title,
                            const TreeModelColumn<ColumnType>& model_column,
                            int position) -> int;

    typedef TreeViewColumn::SlotTreeCellData SlotTreeCellData;

    auto
    insert_column_with_data_func (int position,
                                  const Glib::ustring& title,
                                  CellRenderer& cell,
                                  const SlotTreeCellData& slot) -> int;

    auto
    get_n_columns () const -> guint;

    auto
    get_column (int n) -> TreeViewColumn*;

    auto
    get_column (int n) const -> const TreeViewColumn*;

    auto
    get_column_cell_renderer (int n) -> CellRenderer*;

    auto
    get_column_cell_renderer (int n) const -> const CellRenderer*;

    auto
    get_columns () -> std::vector<TreeViewColumn*>;

    auto
    get_columns () const -> std::vector<const TreeViewColumn*>;

    void
    move_column_after (TreeViewColumn& column, TreeViewColumn& base_column);

    void
    move_column_to_start (TreeViewColumn& column);

    void
    set_expander_column (TreeViewColumn& column);

    void
    reset_expander_column ();

    auto
    get_expander_column () -> TreeViewColumn*;

    auto
    get_expander_column () const -> const TreeViewColumn*;

    typedef sigc::slot<
        bool (TreeView*, TreeViewColumn*, TreeViewColumn*, TreeViewColumn*)>
        SlotColumnDrop;

    void
    set_column_drag_function (const SlotColumnDrop& slot);

    void
    unset_column_drag_function ();

    void
    scroll_to_point (int tree_x, int tree_y);

    void
    scroll_to_cell (const TreeModel::Path& path,
                    TreeViewColumn& column,
                    float row_align,
                    float col_align);

    void
    scroll_to_cell (const TreeModel::Path& path, TreeViewColumn& column);

    void
    scroll_to_row (const TreeModel::Path& path, float row_align);

    void
    scroll_to_row (const TreeModel::Path& path);

    void
    scroll_to_column (TreeViewColumn& column, float col_align);

    void
    scroll_to_column (TreeViewColumn& column);

    void
    row_activated (const TreeModel::Path& path, TreeViewColumn& column);

    void
    expand_all ();

    void
    collapse_all ();

    void
    expand_to_path (const TreeModel::Path& path);

    auto
    expand_row (const TreeModel::Path& path, bool open_all) -> bool;

    auto
    collapse_row (const TreeModel::Path& path) -> bool;

    typedef sigc::slot<void (TreeView*, const TreeModel::Path&)> SlotMapping;

    void
    map_expanded_rows (const SlotMapping& slot);

    auto
    row_expanded (const TreeModel::Path& path) -> bool;

    void
    set_reorderable (bool reorderable = true);

    auto
    get_reorderable () const -> bool;

    void
    set_cursor (const TreeModel::Path& path,
                TreeViewColumn& focus_column,
                bool start_editing = false);

    void
    set_cursor (const TreeModel::Path& path,
                TreeViewColumn& focus_column,
                CellRenderer& focus_cell,
                bool start_editing = false);

    void
    set_cursor (const TreeModel::Path& path);

    void
    get_cursor (TreeModel::Path& path, TreeViewColumn*& focus_column);

    auto
    get_path_at_pos (int x,
                     int y,
                     TreeModel::Path& path,
                     TreeViewColumn*& column,
                     int& cell_x,
                     int& cell_y) const -> bool;

    auto
    get_path_at_pos (int x, int y, TreeModel::Path& path) const -> bool;

    void
    get_cell_area (const TreeModel::Path& path,
                   TreeViewColumn& column,
                   Gdk::Rectangle& rect) const;

    void
    get_background_area (const TreeModel::Path& path,
                         TreeViewColumn& column,
                         Gdk::Rectangle& rect) const;

    void
    get_visible_rect (Gdk::Rectangle& visible_rect) const;

    auto
    get_visible_range (TreeModel::Path& start_path,
                       TreeModel::Path& end_path) const -> bool;

    auto
    is_blank_at_pos (int x,
                     int y,
                     TreePath& path,
                     TreeViewColumn*& column,
                     int& cell_x,
                     int& cell_y) const -> bool;

    auto
    is_blank_at_pos (int x, int y) const -> bool;

    void
    enable_model_drag_source (
        const Glib::RefPtr<const Gdk::ContentFormats>& formats,
        Gdk::ModifierType start_button_mask =
            static_cast<Gdk::ModifierType> (GDK_MODIFIER_MASK),
        Gdk::DragAction actions = Gdk::DragAction::COPY |
                                  Gdk::DragAction::MOVE);

    void
    enable_model_drag_source (
        Gdk::ModifierType start_button_mask =
            static_cast<Gdk::ModifierType> (GDK_MODIFIER_MASK),
        Gdk::DragAction actions = Gdk::DragAction::COPY |
                                  Gdk::DragAction::MOVE);

    void
    enable_model_drag_dest (
        const Glib::RefPtr<const Gdk::ContentFormats>& formats,
        Gdk::DragAction actions = Gdk::DragAction::COPY |
                                  Gdk::DragAction::MOVE);

    void
    enable_model_drag_dest (Gdk::DragAction actions = Gdk::DragAction::COPY |
                                                      Gdk::DragAction::MOVE);

    void
    unset_rows_drag_source ();

    void
    unset_rows_drag_dest ();

    void
    set_drag_dest_row (const TreeModel::Path& path, DropPosition pos);

    void
    unset_drag_dest_row ();

    void
    get_drag_dest_row (TreeModel::Path& path, DropPosition& pos) const;

    auto
    get_dest_row_at_pos (int drag_x,
                         int drag_y,
                         TreeModel::Path& path,
                         DropPosition& pos) const -> bool;

    auto
    create_row_drag_icon (const TreeModel::Path& path) const
        -> Glib::RefPtr<Gdk::Paintable>;

    void
    set_enable_search (bool enable_search = true);

    auto
    get_enable_search () const -> bool;

    auto
    get_search_column () const -> int;

    void
    set_search_column (const TreeModelColumnBase& column);

    void
    set_search_column (int column);

    typedef sigc::slot<bool (const Glib::RefPtr<TreeModel>&,
                             int,
                             const Glib::ustring&,
                             const TreeModel::const_iterator&)>
        SlotSearchEqual;

    void
    set_search_equal_func (const SlotSearchEqual& slot);

    auto
    get_search_entry () -> Editable*;

    auto
    get_search_entry () const -> const Editable*;

    void
    set_search_entry (Editable& entry);

    void
    convert_widget_to_tree_coords (int wx, int wy, int& tx, int& ty) const;

    void
    convert_tree_to_widget_coords (int tx, int ty, int& wx, int& wy) const;

    void
    convert_widget_to_bin_window_coords (int wx,
                                         int wy,
                                         int& bx,
                                         int& by) const;

    void
    convert_bin_window_to_widget_coords (int bx,
                                         int by,
                                         int& wx,
                                         int& wy) const;

    void
    convert_tree_to_bin_window_coords (int tx, int ty, int& bx, int& by) const;

    void
    convert_bin_window_to_tree_coords (int bx, int by, int& tx, int& ty) const;

    void
    set_fixed_height_mode (bool enable = true);

    auto
    get_fixed_height_mode () const -> bool;

    void
    set_hover_selection (bool hover = true);

    auto
    get_hover_selection () const -> bool;

    void
    set_hover_expand (bool expand = true);

    auto
    get_hover_expand () const -> bool;

    void
    set_rubber_banding (bool enable = true);

    auto
    get_rubber_banding () const -> bool;

    auto
    is_rubber_banding_active () const -> bool;

    typedef sigc::slot<bool (const Glib::RefPtr<TreeModel>&,
                             const TreeModel::const_iterator&)>
        SlotRowSeparator;

    void
    set_row_separator_func (const SlotRowSeparator& slot);

    void
    unset_row_separator_func ();

    void
    set_grid_lines (GridLines grid_lines);

    auto
    get_grid_lines () const -> GridLines;

    void
    set_enable_tree_lines (bool enable = true);

    auto
    get_enable_tree_lines () const -> bool;

    void
    set_show_expanders (bool enabled = true);

    auto
    get_show_expanders () const -> bool;

    void
    set_level_indentation (int indentation);

    auto
    get_level_indentation () const -> int;

    void
    set_tooltip_row (const Glib::RefPtr<Tooltip>& tooltip,
                     const TreePath& path);

    void
    set_tooltip_cell (const Glib::RefPtr<Tooltip>& tooltip,
                      const TreeModel::Path* path,
                      TreeViewColumn* column,
                      CellRenderer* cell);

    auto
    get_tooltip_context_path (int x,
                              int y,
                              bool keyboard_tip,
                              TreeModel::Path& path) -> bool;

    auto
    get_tooltip_context_iter (int x,
                              int y,
                              bool keyboard_tip,
                              Gtk::TreeModel::iterator& iter) -> bool;

    void
    set_tooltip_column (int column);

    auto
    get_tooltip_column () const -> int;

    auto
    signal_row_activated ()
        -> Glib::SignalProxy<void (const TreeModel::Path&, TreeViewColumn*)>;

    auto
    signal_test_expand_row ()
        -> Glib::SignalProxy<bool (const TreeModel::iterator&,
                                   const TreeModel::Path&)>;

    auto
    signal_test_collapse_row ()
        -> Glib::SignalProxy<bool (const TreeModel::iterator&,
                                   const TreeModel::Path&)>;

    auto
    signal_row_expanded ()
        -> Glib::SignalProxy<void (const TreeModel::iterator&,
                                   const TreeModel::Path&)>;

    auto
    signal_row_collapsed ()
        -> Glib::SignalProxy<void (const TreeModel::iterator&,
                                   const TreeModel::Path&)>;

    auto
    signal_cursor_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_columns_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>;

    auto
    property_headers_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_headers_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_headers_clickable () -> Glib::PropertyProxy<bool>;

    auto
    property_headers_clickable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expander_column () -> Glib::PropertyProxy<TreeViewColumn*>;

    auto
    property_expander_column () const
        -> Glib::PropertyProxy_ReadOnly<TreeViewColumn*>;

    auto
    property_reorderable () -> Glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_search () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_search () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_search_column () -> Glib::PropertyProxy<int>;

    auto
    property_search_column () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_fixed_height_mode () -> Glib::PropertyProxy<bool>;

    auto
    property_fixed_height_mode () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hover_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_hover_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_hover_expand () -> Glib::PropertyProxy<bool>;

    auto
    property_hover_expand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_expanders () -> Glib::PropertyProxy<bool>;

    auto
    property_show_expanders () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_level_indentation () -> Glib::PropertyProxy<bool>;

    auto
    property_level_indentation () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_rubber_banding () -> Glib::PropertyProxy<bool>;

    auto
    property_rubber_banding () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_grid_lines () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_grid_lines () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_tree_lines () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_tree_lines () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_tooltip_column () -> Glib::PropertyProxy<int>;

    auto
    property_tooltip_column () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_activate_on_single_click () -> Glib::PropertyProxy<bool>;

    auto
    property_activate_on_single_click () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    template <class ColumnType>
    friend void
    _auto_store_on_cellrenderer_text_edited_string (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model);

    template <class ColumnType>
    friend void
    _auto_store_on_cellrenderer_text_edited_numerical (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model);

    void
    _auto_store_on_cellrenderer_toggle_edited_with_model (
        const Glib::ustring& path_string,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model);

    template <class ColumnType>
    friend void
    TreeView_Private::_connect_auto_store_editable_signal_handler (
        TreeView*,
        CellRenderer*,
        const TreeModelColumn<ColumnType>&);

#endif

  public:
  public:
  protected:
  };

  template <class ColumnType>
  inline auto
  TreeView::append_column (const Glib::ustring& title,
                           const TreeModelColumn<ColumnType>& model_column) -> int
  {
    TreeViewColumn* const pViewColumn =
        Gtk::manage (new TreeViewColumn (title, model_column));

    return append_column (*pViewColumn);
  }

  template <class ColumnType>
  inline auto
  TreeView::append_column_numeric (
      const Glib::ustring& title,
      const TreeModelColumn<ColumnType>& model_column,
      const Glib::ustring& format) -> int
  {
    TreeViewColumn* const pViewColumn =
        Gtk::manage (new TreeViewColumn (title));

    CellRenderer* pCellRenderer = manage (new CellRendererText ());
    pViewColumn->pack_start (*pCellRenderer);

    typedef void (*type_fptr) (Gtk::CellRenderer * cell,
                               const Gtk::TreeModel::const_iterator& iter,
                               int model_column,
                               const Glib::ustring& format);
    type_fptr fptr = TreeView_Private::_auto_cell_data_func<ColumnType>;

    auto slot = sigc::bind<-1> (sigc::bind<-1> (sigc::ptr_fun (fptr), format),
                                model_column.index ());

    pViewColumn->set_cell_data_func (*pCellRenderer, slot);

    return append_column (*pViewColumn);
  }

  template <class ColumnType>
  inline auto
  TreeView::append_column_numeric_editable (
      const Glib::ustring& title,
      const TreeModelColumn<ColumnType>& model_column,
      const Glib::ustring& format) -> int
  {
    int cols_count = append_column_numeric (title, model_column, format);

    CellRenderer* const cell = get_column_cell_renderer (cols_count - 1);
    if (cell)
    {
      TreeView_Private::_connect_auto_store_numeric_editable_signal_handler<
          ColumnType> (this, cell, model_column);
    }

    return cols_count;
  }

  template <class ColumnType>
  inline auto
  TreeView::append_column_editable (
      const Glib::ustring& title,
      const TreeModelColumn<ColumnType>& model_column) -> int
  {
    TreeViewColumn* const pViewColumn =
        Gtk::manage (new TreeViewColumn (title, model_column));

    CellRenderer* pCellRender = pViewColumn->get_first_cell ();
    TreeView_Private::_connect_auto_store_editable_signal_handler<ColumnType> (
        this,
        pCellRender,
        model_column);

    return append_column (*pViewColumn);
  }

  template <class ColumnType>
  inline auto
  TreeView::insert_column (const Glib::ustring& title,
                           const TreeModelColumn<ColumnType>& model_column,
                           int position) -> int
  {
    TreeViewColumn* const pViewColumn =
        Gtk::manage (new TreeViewColumn (title, model_column));

    return insert_column (*pViewColumn, position);
  }

  template <class ColumnType>
  inline auto
  TreeView::insert_column_editable (
      const Glib::ustring& title,
      const TreeModelColumn<ColumnType>& model_column,
      int position) -> int
  {
    TreeViewColumn* const pViewColumn =
        Gtk::manage (new TreeViewColumn (title, model_column));

    CellRenderer* pCellRender = pViewColumn->get_first_cell ();
    TreeView_Private::_connect_auto_store_editable_signal_handler (
        this,
        pCellRender,
        model_column);

    return insert_column (*pViewColumn, position);
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace TreeView_Private
  {

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<bool> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<bool>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<int> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<int>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<unsigned int> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<unsigned int>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<long> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<long>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<unsigned long> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<unsigned long>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<float> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<float>& model_column);

    template <>
    GTKMM_API void
    _connect_auto_store_editable_signal_handler<double> (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<double>& model_column);

  } // namespace TreeView_Private
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  namespace TreeView_Private
  {

    template <typename T>
    auto
    _convert_from_ustring_to_numeric_type (const Glib::ustring& text) -> T
    {
      return std::strtod (text.c_str (), nullptr);
    }

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<float> (const Glib::ustring& text)
        -> float;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<long double> (
        const Glib::ustring& text) -> long double;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<short> (const Glib::ustring& text)
        -> short;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<unsigned short> (
        const Glib::ustring& text) -> unsigned short;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<int> (const Glib::ustring& text)
        -> int;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<unsigned int> (
        const Glib::ustring& text) -> unsigned int;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<long> (const Glib::ustring& text)
        -> long;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<unsigned long> (
        const Glib::ustring& text) -> unsigned long;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<long long> (const Glib::ustring& text)
        -> long long;

    template <>
    GTKMM_API auto
    _convert_from_ustring_to_numeric_type<unsigned long long> (
        const Glib::ustring& text) -> unsigned long long;

    template <class ColumnType>
    inline void
    _connect_auto_store_editable_signal_handler (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<ColumnType>& model_column)
    {
      Gtk::CellRendererText* pCellText =
          dynamic_cast<Gtk::CellRendererText*> (pCellRenderer);

      if (pCellText)
      {
        pCellText->property_editable () = true;

        typedef void (*type_func) (const Glib::ustring&,
                                   const Glib::ustring&,
                                   int,
                                   const Glib::RefPtr<Gtk::TreeModel>&);
        type_func func =
            &(Gtk::TreeView_Private::
                  _auto_store_on_cellrenderer_text_edited_string<ColumnType>);
        sigc::slot<void (const Glib::ustring&,
                         const Glib::ustring&,
                         int,
                         const Glib::RefPtr<Gtk::TreeModel>&)>
            theslot = sigc::ptr_fun (func);

        pCellText->signal_edited ().connect (
            sigc::bind<-1> (sigc::bind<-1> (theslot, this_p->get_model ()),
                            model_column.index ()));
      }
    }

    template <class ColumnType>
    inline void
    _connect_auto_store_numeric_editable_signal_handler (
        Gtk::TreeView* this_p,
        Gtk::CellRenderer* pCellRenderer,
        const Gtk::TreeModelColumn<ColumnType>& model_column)
    {
      Gtk::CellRendererText* pCellText =
          dynamic_cast<Gtk::CellRendererText*> (pCellRenderer);
      if (pCellText)
      {
        pCellText->property_editable () = true;

        typedef void (*type_fptr) (const Glib::ustring& path_string,
                                   const Glib::ustring& new_text,
                                   int model_column,
                                   const Glib::RefPtr<Gtk::TreeModel>& model);
        type_fptr fptr =
            _auto_store_on_cellrenderer_text_edited_numerical<ColumnType>;

        pCellText->signal_edited ().connect (sigc::bind<-1> (
            sigc::bind<-1> (sigc::ptr_fun (fptr), this_p->get_model ()),
            model_column.index ()));
      }
    }

    template <class ColumnType>
    inline void
    _auto_store_on_cellrenderer_text_edited_string (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model)
    {
      Gtk::TreePath path (path_string);

      if (model)
      {
        auto iter = model->get_iter (path);
        if (iter)
        {
          Gtk::TreeRow row = *iter;
          row.set_value (model_column, (ColumnType) new_text);
        }
      }
    }

    template <class ColumnType>
    inline void
    _auto_store_on_cellrenderer_text_edited_numerical (
        const Glib::ustring& path_string,
        const Glib::ustring& new_text,
        int model_column,
        const Glib::RefPtr<Gtk::TreeModel>& model)
    {
      Gtk::TreePath path (path_string);

      if (model)
      {
        auto iter = model->get_iter (path);
        if (iter)
        {
          Gtk::TreeRow row = *iter;
          row.set_value (
              model_column,
              _convert_from_ustring_to_numeric_type<ColumnType> (new_text));
        }
      }
    }

    template <class ColumnType>
    inline void
    _auto_cell_data_func (Gtk::CellRenderer* cell,
                          const Gtk::TreeModel::const_iterator& iter,
                          int model_column,
                          const Glib::ustring& format)
    {
      Gtk::CellRendererText* pTextRenderer =
          dynamic_cast<Gtk::CellRendererText*> (cell);
      if (!pTextRenderer)
      {
        g_warning ("gtkmm: TextView: append_column_numeric() was used with a "
                   "non-numeric type.");
      }
      else
      {
        if (iter)
        {
          const auto row = *iter;
          ColumnType value = ColumnType ();
          row.get_value (model_column, value);

          char buff[20];
          int used = g_snprintf (buff, sizeof (buff), format.c_str (), value);
          if (used > 0)
          {
            pTextRenderer->property_text () = buff;
          }
        }
      }
    }

  } // namespace TreeView_Private
#endif

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::TreeView::DropPosition>
    : public Glib::Value_Enum<Gtk::TreeView::DropPosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::TreeView::GridLines>
    : public Glib::Value_Enum<Gtk::TreeView::GridLines>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeView* object, bool take_copy = false) -> Gtk::TreeView*;
} // namespace Glib

#endif
