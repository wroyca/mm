// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEVIEWCOLUMN_H
#define _GTKMM_TREEVIEWCOLUMN_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/buildable.hxx>
  #include <libmm/gtk/button.hxx>
  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/cellrenderer_generation.hxx>
  #include <libmm/gtk/treeiter.hxx>
  #include <libmm/gtk/treemodel.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeViewColumn = struct _GtkTreeViewColumn;
using GtkTreeViewColumnClass = struct _GtkTreeViewColumnClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TreeViewColumn_Class;
}
  #endif

namespace gtk
{

  class CellArea;
  class TreeView;

  class LIBMM_GTK_SYMEXPORT TreeViewColumn : public Object,
                                   public CellLayout,
                                   public Buildable
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TreeViewColumn CppObjectType;
    typedef TreeViewColumn_Class CppClassType;
    typedef GtkTreeViewColumn BaseObjectType;
    typedef GtkTreeViewColumnClass BaseClassType;
  #endif

    TreeViewColumn (TreeViewColumn&& src) noexcept;
    auto
    operator= (TreeViewColumn&& src) noexcept -> TreeViewColumn&;

    TreeViewColumn (const TreeViewColumn&) = delete;
    auto
    operator= (const TreeViewColumn&) -> TreeViewColumn& = delete;

    ~TreeViewColumn () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class TreeViewColumn_Class;
    static CppClassType treeviewcolumn_class_;

  protected:
    explicit TreeViewColumn (const glib::ConstructParams& construct_params);
    explicit TreeViewColumn (GtkTreeViewColumn* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkTreeViewColumn*
    {
      return reinterpret_cast<GtkTreeViewColumn*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeViewColumn*
    {
      return reinterpret_cast<GtkTreeViewColumn*> (gobject_);
    }

  private:
  public:
    enum class Sizing
    {
      GROW_ONLY,
      AUTOSIZE,
      FIXED
    };

    typedef TreeViewColumn Column;

    TreeViewColumn ();

    explicit TreeViewColumn (const glib::ustring& title);
    TreeViewColumn (const glib::ustring& title, CellRenderer& cell);

    template <class T_ModelColumnType>
    TreeViewColumn (const glib::ustring& title,
                    const TreeModelColumn<T_ModelColumnType>& column);

    auto
    pack_start (CellRenderer& cell, bool expand = true) -> void;

    auto
    pack_end (CellRenderer& cell, bool expand = true) -> void;

    template <class T_ModelColumnType>
    auto
    pack_start (const TreeModelColumn<T_ModelColumnType>& column,
                bool expand = true) -> void;

    template <class T_ModelColumnType>
    auto
    pack_end (const TreeModelColumn<T_ModelColumnType>& column,
              bool expand = true) -> void;

    auto
    clear () -> void;

    auto
    add_attribute (CellRenderer& cell_renderer,
                   const glib::ustring& attribute,
                   int column) -> void;

    auto
    add_attribute (const glib::PropertyProxy_Base& property,
                   const TreeModelColumnBase& column) -> void;

    auto
    add_attribute (gtk::CellRenderer& cell,
                   const glib::ustring& property_name,
                   const TreeModelColumnBase& column) -> void;

    auto
    set_renderer (gtk::CellRenderer& renderer,
                  const TreeModelColumnBase& column) -> void;

    typedef sigc::slot<void (CellRenderer*,
                             const gtk::TreeModel::const_iterator&)>
        SlotTreeCellData;

    auto
    set_cell_data_func (CellRenderer& cell_renderer,
                        const SlotTreeCellData& slot) -> void;

    auto
    unset_cell_data_func (CellRenderer& cell_renderer) -> void;

    auto
    clear_attributes (CellRenderer& cell_renderer) -> void;

    auto
    set_spacing (int spacing) -> void;

    auto
    get_spacing () const -> int;

    auto
    set_visible (bool visible = true) -> void;

    auto
    get_visible () const -> bool;

    auto
    set_resizable (bool resizable = true) -> void;

    auto
    get_resizable () const -> bool;

    auto
    set_sizing (Sizing type) -> void;

    auto
    get_sizing () -> Sizing;

    auto
    get_x_offset () const -> int;

    auto
    get_width () const -> int;

    auto
    get_fixed_width () const -> int;

    auto
    set_fixed_width (int fixed_width) -> void;

    auto
    set_min_width (int min_width) -> void;

    auto
    get_min_width () const -> int;

    auto
    set_max_width (int max_width) -> void;

    auto
    get_max_width () const -> int;

    auto
    clicked () -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_expand (bool expand = true) -> void;

    auto
    get_expand () const -> bool;

    auto
    set_clickable (bool clickable = true) -> void;

    auto
    get_clickable () const -> bool;

    auto
    set_widget (gtk::Widget& widget) -> void;

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    auto
    set_alignment (float xalign) -> void;

    auto
    set_alignment (Align xalign) -> void;

    auto
    get_alignment () const -> float;

    auto
    set_reorderable (bool reorderable = true) -> void;

    auto
    get_reorderable () const -> bool;

    auto
    set_sort_column (const TreeModelColumnBase& sort_column_id) -> void;

    auto
    set_sort_column (int sort_column_id) -> void;

    auto
    get_sort_column_id () const -> int;

    auto
    set_sort_indicator (bool setting) -> void;

    auto
    get_sort_indicator () const -> bool;

    auto
    set_sort_order (SortType order) -> void;

    auto
    get_sort_order () const -> SortType;

    auto
    cell_set_cell_data (const glib::RefPtr<TreeModel>& tree_model,
                        const TreeModel::iterator& iter,
                        bool is_expander,
                        bool is_expanded) -> void;

    auto
    cell_get_size (int& x_offset, int& y_offset, int& width, int& height) const
        -> void;

    auto
    cell_is_visible () const -> bool;

    auto
    focus_cell (CellRenderer& cell) -> void;

    auto
    get_cell_position (const CellRenderer& cell_renderer,
                       int& start_pos,
                       int& width) const -> bool;

    auto
    queue_resize () -> void;

    auto
    get_tree_view () -> TreeView*;

    auto
    get_tree_view () const -> const TreeView*;

    auto
    get_button () -> Button*;

    auto
    get_button () const -> const Button*;

    auto
    signal_clicked () -> glib::SignalProxy<void ()>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resizable () -> glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_x_offset () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_spacing () -> glib::PropertyProxy<int>;

    auto
    property_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_sizing () -> glib::PropertyProxy<Sizing>;

    auto
    property_sizing () const -> glib::PropertyProxy_ReadOnly<Sizing>;

    auto
    property_fixed_width () -> glib::PropertyProxy<int>;

    auto
    property_fixed_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_min_width () -> glib::PropertyProxy<int>;

    auto
    property_min_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width () -> glib::PropertyProxy<int>;

    auto
    property_max_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_expand () -> glib::PropertyProxy<bool>;

    auto
    property_expand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_clickable () -> glib::PropertyProxy<bool>;

    auto
    property_clickable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_alignment () -> glib::PropertyProxy<float>;

    auto
    property_alignment () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_reorderable () -> glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sort_indicator () -> glib::PropertyProxy<bool>;

    auto
    property_sort_indicator () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sort_order () -> glib::PropertyProxy<SortType>;

    auto
    property_sort_order () const -> glib::PropertyProxy_ReadOnly<SortType>;

    auto
    property_sort_column_id () -> glib::PropertyProxy<int>;

    auto
    property_sort_column_id () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_cell_area () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    static auto
    class_init_ () -> const glib::Class&;
  #endif

  public:
  public:
  protected:
  };

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T_ModelColumnType>
  inline auto
  TreeViewColumn::pack_start (const TreeModelColumn<T_ModelColumnType>& column,
                              bool expand) -> void
  {
    CellRenderer* pCellRenderer = manage (
        CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType> ());

    pack_start (*pCellRenderer, expand);
    set_renderer (*pCellRenderer, column);
  }

  template <class T_ModelColumnType>
  inline auto
  TreeViewColumn::pack_end (const TreeModelColumn<T_ModelColumnType>& column,
                            bool expand) -> void
  {
    CellRenderer* pCellRenderer = manage (
        CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType> ());

    pack_end (*pCellRenderer, expand);
    set_renderer (*pCellRenderer, column);
  }

  template <class T_ModelColumnType>
  inline TreeViewColumn::TreeViewColumn (
      const glib::ustring& title,
      const TreeModelColumn<T_ModelColumnType>& column)
    : glib::ObjectBase (nullptr),
      gtk::Object (glib::ConstructParams (class_init_ (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    pack_start (column, true);
  }

  #endif

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::TreeViewColumn::Sizing>
    : public glib::Value_Enum<gtk::TreeViewColumn::Sizing>
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
  wrap (GtkTreeViewColumn* object, bool take_copy = false) -> gtk::TreeViewColumn*;
} // namespace glib

#endif

#endif
