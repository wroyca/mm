// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEVIEWCOLUMN_H
#define _GTKMM_TREEVIEWCOLUMN_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/button.hxx>
#include <libmm-gtk/celllayout.hxx>
#include <libmm-gtk/cellrenderer_generation.hxx>
#include <libmm-gtk/treeiter.hxx>
#include <libmm-gtk/treemodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeViewColumn = struct _GtkTreeViewColumn;
using GtkTreeViewColumnClass = struct _GtkTreeViewColumnClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeViewColumn_Class;
}
#endif

namespace Gtk
{

  class CellArea;
  class TreeView;

  class GTKMM_API TreeViewColumn : public Object,
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
    friend GTKMM_API class TreeViewColumn_Class;
    static CppClassType treeviewcolumn_class_;

  protected:
    explicit TreeViewColumn (const Glib::ConstructParams& construct_params);
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

    explicit TreeViewColumn (const Glib::ustring& title);
    TreeViewColumn (const Glib::ustring& title, CellRenderer& cell);

    template <class T_ModelColumnType>
    TreeViewColumn (const Glib::ustring& title,
                    const TreeModelColumn<T_ModelColumnType>& column);

    void
    pack_start (CellRenderer& cell, bool expand = true);

    void
    pack_end (CellRenderer& cell, bool expand = true);

    template <class T_ModelColumnType>
    void
    pack_start (const TreeModelColumn<T_ModelColumnType>& column,
                bool expand = true);

    template <class T_ModelColumnType>
    void
    pack_end (const TreeModelColumn<T_ModelColumnType>& column,
              bool expand = true);

    void
    clear ();

    void
    add_attribute (CellRenderer& cell_renderer,
                   const Glib::ustring& attribute,
                   int column);

    void
    add_attribute (const Glib::PropertyProxy_Base& property,
                   const TreeModelColumnBase& column);

    void
    add_attribute (Gtk::CellRenderer& cell,
                   const Glib::ustring& property_name,
                   const TreeModelColumnBase& column);

    void
    set_renderer (Gtk::CellRenderer& renderer,
                  const TreeModelColumnBase& column);

    typedef sigc::slot<void (CellRenderer*,
                             const Gtk::TreeModel::const_iterator&)>
        SlotTreeCellData;

    void
    set_cell_data_func (CellRenderer& cell_renderer,
                        const SlotTreeCellData& slot);

    void
    unset_cell_data_func (CellRenderer& cell_renderer);

    void
    clear_attributes (CellRenderer& cell_renderer);

    void
    set_spacing (int spacing);

    auto
    get_spacing () const -> int;

    void
    set_visible (bool visible = true);

    auto
    get_visible () const -> bool;

    void
    set_resizable (bool resizable = true);

    auto
    get_resizable () const -> bool;

    void
    set_sizing (Sizing type);

    auto
    get_sizing () -> Sizing;

    auto
    get_x_offset () const -> int;

    auto
    get_width () const -> int;

    auto
    get_fixed_width () const -> int;

    void
    set_fixed_width (int fixed_width);

    void
    set_min_width (int min_width);

    auto
    get_min_width () const -> int;

    void
    set_max_width (int max_width);

    auto
    get_max_width () const -> int;

    void
    clicked ();

    void
    set_title (const Glib::ustring& title);

    auto
    get_title () const -> Glib::ustring;

    void
    set_expand (bool expand = true);

    auto
    get_expand () const -> bool;

    void
    set_clickable (bool clickable = true);

    auto
    get_clickable () const -> bool;

    void
    set_widget (Gtk::Widget& widget);

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    void
    set_alignment (float xalign);

    void
    set_alignment (Align xalign);

    auto
    get_alignment () const -> float;

    void
    set_reorderable (bool reorderable = true);

    auto
    get_reorderable () const -> bool;

    void
    set_sort_column (const TreeModelColumnBase& sort_column_id);

    void
    set_sort_column (int sort_column_id);

    auto
    get_sort_column_id () const -> int;

    void
    set_sort_indicator (bool setting);

    auto
    get_sort_indicator () const -> bool;

    void
    set_sort_order (SortType order);

    auto
    get_sort_order () const -> SortType;

    void
    cell_set_cell_data (const Glib::RefPtr<TreeModel>& tree_model,
                        const TreeModel::iterator& iter,
                        bool is_expander,
                        bool is_expanded);

    void
    cell_get_size (int& x_offset, int& y_offset, int& width, int& height) const;

    auto
    cell_is_visible () const -> bool;

    void
    focus_cell (CellRenderer& cell);

    auto
    get_cell_position (const CellRenderer& cell_renderer,
                       int& start_pos,
                       int& width) const -> bool;

    void
    queue_resize ();

    auto
    get_tree_view () -> TreeView*;

    auto
    get_tree_view () const -> const TreeView*;

    auto
    get_button () -> Button*;

    auto
    get_button () const -> const Button*;

    auto
    signal_clicked () -> Glib::SignalProxy<void ()>;

    auto
    property_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resizable () -> Glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_x_offset () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_sizing () -> Glib::PropertyProxy<Sizing>;

    auto
    property_sizing () const -> Glib::PropertyProxy_ReadOnly<Sizing>;

    auto
    property_fixed_width () -> Glib::PropertyProxy<int>;

    auto
    property_fixed_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_min_width () -> Glib::PropertyProxy<int>;

    auto
    property_min_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width () -> Glib::PropertyProxy<int>;

    auto
    property_max_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_expand () -> Glib::PropertyProxy<bool>;

    auto
    property_expand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_clickable () -> Glib::PropertyProxy<bool>;

    auto
    property_clickable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_alignment () -> Glib::PropertyProxy<float>;

    auto
    property_alignment () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_reorderable () -> Glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sort_indicator () -> Glib::PropertyProxy<bool>;

    auto
    property_sort_indicator () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sort_order () -> Glib::PropertyProxy<SortType>;

    auto
    property_sort_order () const -> Glib::PropertyProxy_ReadOnly<SortType>;

    auto
    property_sort_column_id () -> Glib::PropertyProxy<int>;

    auto
    property_sort_column_id () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_cell_area () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    static auto
    class_init_ () -> const Glib::Class&;
#endif

  public:
  public:
  protected:
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T_ModelColumnType>
  inline void
  TreeViewColumn::pack_start (const TreeModelColumn<T_ModelColumnType>& column,
                              bool expand)
  {
    CellRenderer* pCellRenderer = manage (
        CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType> ());

    pack_start (*pCellRenderer, expand);
    set_renderer (*pCellRenderer, column);
  }

  template <class T_ModelColumnType>
  inline void
  TreeViewColumn::pack_end (const TreeModelColumn<T_ModelColumnType>& column,
                            bool expand)
  {
    CellRenderer* pCellRenderer = manage (
        CellRenderer_Generation::generate_cellrenderer<T_ModelColumnType> ());

    pack_end (*pCellRenderer, expand);
    set_renderer (*pCellRenderer, column);
  }

  template <class T_ModelColumnType>
  inline TreeViewColumn::TreeViewColumn (
      const Glib::ustring& title,
      const TreeModelColumn<T_ModelColumnType>& column)
    : Glib::ObjectBase (nullptr),
      Gtk::Object (Glib::ConstructParams (class_init_ (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    pack_start (column, true);
  }

#endif

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::TreeViewColumn::Sizing>
    : public Glib::Value_Enum<Gtk::TreeViewColumn::Sizing>
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
  wrap (GtkTreeViewColumn* object, bool take_copy = false) -> Gtk::TreeViewColumn*;
} // namespace Glib

#endif
