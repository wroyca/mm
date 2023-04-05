// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ICONVIEW_H
#define _GTKMM_ICONVIEW_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <vector>

  #include <libmm/gtk/cellarea.hxx>
  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/cellrenderer.hxx>
  #include <libmm/gtk/scrollable.hxx>
  #include <libmm/gtk/tooltip.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treepath.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconView = struct _GtkIconView;
using GtkIconViewClass = struct _GtkIconViewClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT IconView_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT IconView : public Widget,
                             public CellLayout,
                             public Scrollable
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef IconView CppObjectType;
    typedef IconView_Class CppClassType;
    typedef GtkIconView BaseObjectType;
    typedef GtkIconViewClass BaseClassType;
  #endif

    IconView (IconView&& src) noexcept;
    auto
    operator= (IconView&& src) noexcept -> IconView&;

    IconView (const IconView&) = delete;
    auto
    operator= (const IconView&) -> IconView& = delete;

    ~IconView () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class IconView_Class;
    static CppClassType iconview_class_;

  protected:
    explicit IconView (const glib::ConstructParams& construct_params);
    explicit IconView (GtkIconView* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkIconView*
    {
      return reinterpret_cast<GtkIconView*> (gobject_);
    }

    auto
    gobj () const -> const GtkIconView*
    {
      return reinterpret_cast<GtkIconView*> (gobject_);
    }

  private:
  public:
    enum class DropPosition
    {
      NO_DROP,
      DROP_INTO,
      DROP_LEFT,
      DROP_RIGHT,
      DROP_ABOVE,
      DROP_BELOW
    };

    IconView ();
    explicit IconView (const glib::RefPtr<TreeModel>& model);

    explicit IconView (const glib::RefPtr<CellArea>& cell_area);

    auto
    set_model (const glib::RefPtr<TreeModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<TreeModel>;

    auto
    get_model () const -> glib::RefPtr<const TreeModel>;

    auto
    unset_model () -> void;

    auto
    set_text_column (int column) -> void;

    auto
    set_text_column (const TreeModelColumnBase& model_column) -> void;

    auto
    get_text_column () const -> int;

    auto
    set_markup_column (int column) -> void;

    auto
    set_markup_column (const TreeModelColumnBase& column) -> void;

    auto
    get_markup_column () const -> int;

    auto
    set_pixbuf_column (int column) -> void;

    auto
    set_pixbuf_column (const TreeModelColumnBase& column) -> void;

    auto
    get_pixbuf_column () const -> int;

    auto
    set_item_orientation (Orientation orientation) -> void;

    auto
    get_item_orientation () const -> Orientation;

    auto
    set_columns (int columns) -> void;

    auto
    get_columns () const -> int;

    auto
    set_item_width (int item_width) -> void;

    auto
    get_icon_width () const -> int;

    auto
    set_spacing (int spacing) -> void;

    auto
    get_spacing () const -> int;

    auto
    set_row_spacing (int row_spacing) -> void;

    auto
    get_row_spacing () const -> int;

    auto
    set_column_spacing (int column_spacing) -> void;

    auto
    get_column_spacing () const -> int;

    auto
    set_margin (int margin) -> void;

    auto
    get_margin () const -> int;

    auto
    set_item_padding (int item_padding) -> void;

    auto
    get_item_padding () const -> int;

    auto
    get_path_at_pos (int x, int y) const -> TreeModel::Path;

    auto
    get_item_at_pos (int x,
                     int y,
                     TreeModel::Path& path,
                     CellRenderer*& cell) const -> bool;

    auto
    get_item_at_pos (int x, int y, TreeModel::Path& path) const -> bool;

    auto
    get_item_at_pos (int x, int y, CellRenderer*& cell) const -> bool;

    auto
    get_visible_range (TreeModel::Path& start_path,
                       TreeModel::Path& end_path) const -> bool;

    auto
    set_activate_on_single_click (bool single = true) -> void;

    auto
    get_activate_on_single_click () const -> bool;

    using SlotForeach = sigc::slot<void (const TreeModel::Path&)>;

    auto
    selected_foreach (const SlotForeach& slot) -> void;

    auto
    set_selection_mode (SelectionMode mode) -> void;

    auto
    get_selection_mode () const -> SelectionMode;

    auto
    select_path (const TreeModel::Path& path) -> void;

    auto
    unselect_path (const TreeModel::Path& path) -> void;

    auto
    path_is_selected (const TreeModel::Path& path) const -> bool;

    auto
    get_item_row (const TreeModel::Path& path) const -> int;

    auto
    get_item_column (const TreeModel::Path& path) const -> int;

    auto
    get_selected_items () const -> std::vector<TreePath>;

    auto
    select_all () -> void;

    auto
    unselect_all () -> void;

    auto
    item_activated (const TreeModel::Path& path) -> void;

    auto
    set_cursor (const TreeModel::Path& path,
                CellRenderer& cell,
                bool start_editing) -> void;

    auto
    set_cursor (const TreeModel::Path& path, bool start_editing) -> void;

    auto
    get_cursor (TreeModel::Path& path, CellRenderer*& cell) const -> bool;

    auto
    get_cursor (TreeModel::Path& path) const -> bool;

    auto
    get_cursor (CellRenderer*& cell) const -> bool;

    auto
    scroll_to_path (const TreeModel::Path& path,
                    bool use_align,
                    float row_align,
                    float col_align) -> void;

    auto
    enable_model_drag_source (
        const glib::RefPtr<const gdk::ContentFormats>& formats,
        gdk::ModifierType start_button_mask =
            static_cast<gdk::ModifierType> (GDK_MODIFIER_MASK),
        gdk::DragAction actions = gdk::DragAction::COPY | gdk::DragAction::MOVE)
        -> void;

    auto
    enable_model_drag_dest (
        const glib::RefPtr<const gdk::ContentFormats>& formats,
        gdk::DragAction actions = gdk::DragAction::COPY | gdk::DragAction::MOVE)
        -> void;

    auto
    unset_model_drag_source () -> void;

    auto
    unset_model_drag_dest () -> void;

    auto
    set_reorderable (bool reorderable = true) -> void;

    auto
    get_reorderable () const -> bool;

    auto
    set_drag_dest_item (const TreeModel::Path& path, DropPosition pos) -> void;

    auto
    get_drag_dest_item (TreeModel::Path& path, DropPosition& pos) const -> void;

    auto
    get_drag_dest_item (TreeModel::Path& path) const -> void;

    auto
    get_drag_dest_item (DropPosition& pos) const -> void;

    auto
    get_dest_item_at_pos (int drag_x,
                          int drag_y,
                          TreeModel::Path& path,
                          DropPosition& pos) const -> bool;

    auto
    get_dest_item_at_pos (int drag_x, int drag_y, TreeModel::Path& path) const
        -> bool;

    auto
    get_dest_item_at_pos (int drag_x, int drag_y, DropPosition& pos) const
        -> bool;

    auto
    create_drag_icon (const TreeModel::Path& path) const
        -> glib::RefPtr<gdk::Paintable>;

    auto
    get_cell_rect (const TreeModel::Path& path,
                   const CellRenderer& cell,
                   gdk::Rectangle& rect) const -> bool;

    auto
    get_cell_rect (const TreeModel::Path& path, gdk::Rectangle& rect) const
        -> bool;

    auto
    set_tooltip_item (const glib::RefPtr<Tooltip>& tooltip,
                      const TreeModel::Path& path) -> void;

    auto
    set_tooltip_cell (const glib::RefPtr<Tooltip>& tooltip,
                      const TreeModel::Path& path,
                      CellRenderer& cell) -> void;

    auto
    set_tooltip_cell (const glib::RefPtr<Tooltip>& tooltip,
                      const TreeModel::Path& path) -> void;

    auto
    get_tooltip_context_path (int x,
                              int y,
                              bool keyboard_tip,
                              TreeModel::Path& path) -> bool;

    auto
    get_tooltip_context_iter (int x,
                              int y,
                              bool keyboard_tip,
                              gtk::TreeModel::iterator& iter) -> bool;

    auto
    set_tooltip_column (int column) -> void;

    auto
    get_tooltip_column () const -> int;

    auto
    signal_item_activated ()
        -> glib::SignalProxy<void (const TreeModel::Path&)>;

    auto
    signal_selection_changed () -> glib::SignalProxy<void ()>;

    auto
    property_pixbuf_column () -> glib::PropertyProxy<int>;

    auto
    property_pixbuf_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text_column () -> glib::PropertyProxy<int>;

    auto
    property_text_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_markup_column () -> glib::PropertyProxy<int>;

    auto
    property_markup_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_selection_mode () -> glib::PropertyProxy<SelectionMode>;

    auto
    property_selection_mode () const
        -> glib::PropertyProxy_ReadOnly<SelectionMode>;

    auto
    property_item_orientation () -> glib::PropertyProxy<Orientation>;

    auto
    property_item_orientation () const
        -> glib::PropertyProxy_ReadOnly<Orientation>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>;

    auto
    property_columns () -> glib::PropertyProxy<int>;

    auto
    property_columns () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_item_width () -> glib::PropertyProxy<int>;

    auto
    property_item_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_spacing () -> glib::PropertyProxy<int>;

    auto
    property_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_row_spacing () -> glib::PropertyProxy<int>;

    auto
    property_row_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_column_spacing () -> glib::PropertyProxy<int>;

    auto
    property_column_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_margin () -> glib::PropertyProxy<int>;

    auto
    property_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_reorderable () -> glib::PropertyProxy<int>;

    auto
    property_reorderable () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tooltip_column () -> glib::PropertyProxy<int>;

    auto
    property_tooltip_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_item_padding () -> glib::PropertyProxy<int>;

    auto
    property_item_padding () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_cell_area () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>;

    auto
    property_activate_on_single_click () -> glib::PropertyProxy<bool>;

    auto
    property_activate_on_single_click () const
        -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::IconView::DropPosition>
    : public glib::Value_Enum<gtk::IconView::DropPosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkIconView* object, bool take_copy = false) -> gtk::IconView*;
} // namespace glib

#endif

#endif
