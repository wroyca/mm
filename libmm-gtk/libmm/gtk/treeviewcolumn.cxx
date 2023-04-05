// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treeviewcolumn.hxx>
  #include <libmm/gtk/treeviewcolumn_p.hxx>

  #include <gtk/gtk.h>

  #include <gtk/gtk.h>
  #include <libmm/gtk/cellarea.hxx>
  #include <libmm/gtk/treeview_private.hxx>

using Sizing = gtk::TreeViewColumn::Sizing;

namespace gtk
{

  auto
  TreeViewColumn::class_init_ () -> const glib::Class&
  {
    return treeviewcolumn_class_.init ();
  }

  TreeViewColumn::TreeViewColumn (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      Object (glib::ConstructParams (treeviewcolumn_class_.init (),
                                     "title",
                                     title.c_str (),
                                     nullptr))
  {
  }

  TreeViewColumn::TreeViewColumn (const glib::ustring& title,
                                  gtk::CellRenderer& cell)
    : glib::ObjectBase (nullptr),
      Object (glib::ConstructParams (treeviewcolumn_class_.init (),
                                     "title",
                                     title.c_str (),
                                     nullptr))
  {
    pack_start (cell, true);
  }

  auto
  TreeViewColumn::add_attribute (gtk::CellRenderer& cell,
                                 const glib::ustring& property_name,
                                 const TreeModelColumnBase& column) -> void
  {
    gtk_tree_view_column_add_attribute (gobj (),
                                        (GtkCellRenderer*) cell.gobj (),
                                        property_name.c_str (),
                                        column.index ());
  }

  auto
  TreeViewColumn::add_attribute (const glib::PropertyProxy_Base& property,
                                 const TreeModelColumnBase& column) -> void
  {
    gtk_tree_view_column_add_attribute (
        gobj (),
        (GtkCellRenderer*) property.get_object ()->gobj (),
        property.get_name (),
        column.index ());
  }

  auto
  TreeViewColumn::set_renderer (gtk::CellRenderer& renderer,
                                const TreeModelColumnBase& column) -> void
  {
    add_attribute (renderer._property_renderable (), column);
  }

  auto
  TreeViewColumn::set_cell_data_func (CellRenderer& cell_renderer,
                                      const SlotTreeCellData& slot) -> void
  {
    auto slot_copy = new SlotTreeCellData (slot);

    gtk_tree_view_column_set_cell_data_func (
        gobj (),
        cell_renderer.gobj (),
        &TreeView_Private::SignalProxy_CellData_gtk_callback,
        slot_copy,
        &TreeView_Private::SignalProxy_CellData_gtk_callback_destroy);
  }

  auto
  TreeViewColumn::unset_cell_data_func (CellRenderer& cell_renderer) -> void
  {
    gtk_tree_view_column_set_cell_data_func (gobj (),
                                             cell_renderer.gobj (),
                                             nullptr,
                                             nullptr,
                                             nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo TreeViewColumn_signal_clicked_info = {
      "clicked",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

auto
glib::Value<gtk::TreeViewColumn::Sizing>::value_type () -> GType
{
  return gtk_tree_view_column_sizing_get_type ();
}

namespace glib
{

  auto
  wrap (GtkTreeViewColumn* object, bool take_copy) -> gtk::TreeViewColumn*
  {
    return dynamic_cast<gtk::TreeViewColumn*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeViewColumn_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeViewColumn_Class::class_init_function;

      register_derived_type (gtk_tree_view_column_get_type ());

      CellLayout::add_interface (get_type ());
      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TreeViewColumn_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  TreeViewColumn_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TreeViewColumn ((GtkTreeViewColumn*) (o)));
  }

  TreeViewColumn::TreeViewColumn (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  TreeViewColumn::TreeViewColumn (GtkTreeViewColumn* castitem)
    : Object ((GObject*) (castitem))
  {
  }

  TreeViewColumn::TreeViewColumn (TreeViewColumn&& src) noexcept
    : Object (std::move (src)),
      CellLayout (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  TreeViewColumn::operator= (TreeViewColumn&& src) noexcept -> TreeViewColumn&
  {
    Object::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  TreeViewColumn::~TreeViewColumn () noexcept
  {
    destroy_ ();
  }

  TreeViewColumn::CppClassType TreeViewColumn::treeviewcolumn_class_;

  auto
  TreeViewColumn::get_type () -> GType
  {
    return treeviewcolumn_class_.init ().get_type ();
  }

  auto
  TreeViewColumn::get_base_type () -> GType
  {
    return gtk_tree_view_column_get_type ();
  }

  TreeViewColumn::TreeViewColumn ()
    : glib::ObjectBase (nullptr),
      Object (glib::ConstructParams (treeviewcolumn_class_.init ()))
  {
  }

  auto
  TreeViewColumn::pack_start (CellRenderer& cell, bool expand) -> void
  {
    gtk_tree_view_column_pack_start (gobj (),
                                     (cell).gobj (),
                                     static_cast<int> (expand));
  }

  auto
  TreeViewColumn::pack_end (CellRenderer& cell, bool expand) -> void
  {
    gtk_tree_view_column_pack_end (gobj (),
                                   (cell).gobj (),
                                   static_cast<int> (expand));
  }

  auto
  TreeViewColumn::clear () -> void
  {
    gtk_tree_view_column_clear (gobj ());
  }

  auto
  TreeViewColumn::add_attribute (CellRenderer& cell_renderer,
                                 const glib::ustring& attribute,
                                 int column) -> void
  {
    gtk_tree_view_column_add_attribute (gobj (),
                                        (cell_renderer).gobj (),
                                        attribute.c_str (),
                                        column);
  }

  auto
  TreeViewColumn::clear_attributes (CellRenderer& cell_renderer) -> void
  {
    gtk_tree_view_column_clear_attributes (gobj (), (cell_renderer).gobj ());
  }

  auto
  TreeViewColumn::set_spacing (int spacing) -> void
  {
    gtk_tree_view_column_set_spacing (gobj (), spacing);
  }

  auto
  TreeViewColumn::get_spacing () const -> int
  {
    return gtk_tree_view_column_get_spacing (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_visible (bool visible) -> void
  {
    gtk_tree_view_column_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  TreeViewColumn::get_visible () const -> bool
  {
    return gtk_tree_view_column_get_visible (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_resizable (bool resizable) -> void
  {
    gtk_tree_view_column_set_resizable (gobj (), static_cast<int> (resizable));
  }

  auto
  TreeViewColumn::get_resizable () const -> bool
  {
    return gtk_tree_view_column_get_resizable (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_sizing (Sizing type) -> void
  {
    gtk_tree_view_column_set_sizing (
        gobj (),
        static_cast<GtkTreeViewColumnSizing> (type));
  }

  auto
  TreeViewColumn::get_sizing () -> Sizing
  {
    return static_cast<Sizing> (gtk_tree_view_column_get_sizing (gobj ()));
  }

  auto
  TreeViewColumn::get_x_offset () const -> int
  {
    return gtk_tree_view_column_get_x_offset (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::get_width () const -> int
  {
    return gtk_tree_view_column_get_width (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::get_fixed_width () const -> int
  {
    return gtk_tree_view_column_get_fixed_width (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_fixed_width (int fixed_width) -> void
  {
    gtk_tree_view_column_set_fixed_width (gobj (), fixed_width);
  }

  auto
  TreeViewColumn::set_min_width (int min_width) -> void
  {
    gtk_tree_view_column_set_min_width (gobj (), min_width);
  }

  auto
  TreeViewColumn::get_min_width () const -> int
  {
    return gtk_tree_view_column_get_min_width (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_max_width (int max_width) -> void
  {
    gtk_tree_view_column_set_max_width (gobj (), max_width);
  }

  auto
  TreeViewColumn::get_max_width () const -> int
  {
    return gtk_tree_view_column_get_max_width (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::clicked () -> void
  {
    gtk_tree_view_column_clicked (gobj ());
  }

  auto
  TreeViewColumn::set_title (const glib::ustring& title) -> void
  {
    gtk_tree_view_column_set_title (gobj (), title.c_str ());
  }

  auto
  TreeViewColumn::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_tree_view_column_get_title (
            const_cast<GtkTreeViewColumn*> (gobj ())));
  }

  auto
  TreeViewColumn::set_expand (bool expand) -> void
  {
    gtk_tree_view_column_set_expand (gobj (), static_cast<int> (expand));
  }

  auto
  TreeViewColumn::get_expand () const -> bool
  {
    return gtk_tree_view_column_get_expand (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_clickable (bool clickable) -> void
  {
    gtk_tree_view_column_set_clickable (gobj (), static_cast<int> (clickable));
  }

  auto
  TreeViewColumn::get_clickable () const -> bool
  {
    return gtk_tree_view_column_get_clickable (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_widget (gtk::Widget& widget) -> void
  {
    gtk_tree_view_column_set_widget (gobj (), (widget).gobj ());
  }

  auto
  TreeViewColumn::get_widget () -> Widget*
  {
    return glib::wrap (gtk_tree_view_column_get_widget (gobj ()));
  }

  auto
  TreeViewColumn::get_widget () const -> const Widget*
  {
    return glib::wrap (gtk_tree_view_column_get_widget (
        const_cast<GtkTreeViewColumn*> (gobj ())));
  }

  auto
  TreeViewColumn::set_alignment (float xalign) -> void
  {
    gtk_tree_view_column_set_alignment (gobj (), xalign);
  }

  auto
  TreeViewColumn::set_alignment (Align xalign) -> void
  {
    gtk_tree_view_column_set_alignment (gobj (),
                                        _gtkmm_align_float_from_enum (xalign));
  }

  auto
  TreeViewColumn::get_alignment () const -> float
  {
    return gtk_tree_view_column_get_alignment (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_reorderable (bool reorderable) -> void
  {
    gtk_tree_view_column_set_reorderable (gobj (),
                                          static_cast<int> (reorderable));
  }

  auto
  TreeViewColumn::get_reorderable () const -> bool
  {
    return gtk_tree_view_column_get_reorderable (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_sort_column (const TreeModelColumnBase& sort_column_id) -> void
  {
    gtk_tree_view_column_set_sort_column_id (gobj (),
                                             (sort_column_id).index ());
  }

  auto
  TreeViewColumn::set_sort_column (int sort_column_id) -> void
  {
    gtk_tree_view_column_set_sort_column_id (gobj (), sort_column_id);
  }

  auto
  TreeViewColumn::get_sort_column_id () const -> int
  {
    return gtk_tree_view_column_get_sort_column_id (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_sort_indicator (bool setting) -> void
  {
    gtk_tree_view_column_set_sort_indicator (gobj (),
                                             static_cast<int> (setting));
  }

  auto
  TreeViewColumn::get_sort_indicator () const -> bool
  {
    return gtk_tree_view_column_get_sort_indicator (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::set_sort_order (SortType order) -> void
  {
    gtk_tree_view_column_set_sort_order (gobj (),
                                         static_cast<GtkSortType> (order));
  }

  auto
  TreeViewColumn::get_sort_order () const -> SortType
  {
    return static_cast<SortType> (gtk_tree_view_column_get_sort_order (
        const_cast<GtkTreeViewColumn*> (gobj ())));
  }

  auto
  TreeViewColumn::cell_set_cell_data (const glib::RefPtr<TreeModel>& tree_model,
                                      const TreeModel::iterator& iter,
                                      bool is_expander,
                                      bool is_expanded) -> void
  {
    gtk_tree_view_column_cell_set_cell_data (
        gobj (),
        glib::unwrap (tree_model),
        const_cast<GtkTreeIter*> ((iter).gobj ()),
        static_cast<int> (is_expander),
        static_cast<int> (is_expanded));
  }

  auto
  TreeViewColumn::cell_get_size (int& x_offset,
                                 int& y_offset,
                                 int& width,
                                 int& height) const -> void
  {
    gtk_tree_view_column_cell_get_size (
        const_cast<GtkTreeViewColumn*> (gobj ()),
        &(x_offset),
        &(y_offset),
        &(width),
        &(height));
  }

  auto
  TreeViewColumn::cell_is_visible () const -> bool
  {
    return gtk_tree_view_column_cell_is_visible (
        const_cast<GtkTreeViewColumn*> (gobj ()));
  }

  auto
  TreeViewColumn::focus_cell (CellRenderer& cell) -> void
  {
    gtk_tree_view_column_focus_cell (gobj (), (cell).gobj ());
  }

  auto
  TreeViewColumn::get_cell_position (const CellRenderer& cell_renderer,
                                     int& start_pos,
                                     int& width) const -> bool
  {
    return gtk_tree_view_column_cell_get_position (
        const_cast<GtkTreeViewColumn*> (gobj ()),
        const_cast<GtkCellRenderer*> ((cell_renderer).gobj ()),
        &(start_pos),
        &(width));
  }

  auto
  TreeViewColumn::queue_resize () -> void
  {
    gtk_tree_view_column_queue_resize (gobj ());
  }

  auto
  TreeViewColumn::get_tree_view () -> TreeView*
  {
    auto retvalue = glib::wrap (
        (GtkTreeView*) (gtk_tree_view_column_get_tree_view (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeViewColumn::get_tree_view () const -> const TreeView*
  {
    return const_cast<TreeViewColumn*> (this)->get_tree_view ();
  }

  auto
  TreeViewColumn::get_button () -> Button*
  {
    auto retvalue =
        glib::wrap ((GtkButton*) (gtk_tree_view_column_get_button (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TreeViewColumn::get_button () const -> const Button*
  {
    return const_cast<TreeViewColumn*> (this)->get_button ();
  }

  auto
  TreeViewColumn::signal_clicked () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &TreeViewColumn_signal_clicked_info);
  }

  auto
  TreeViewColumn::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  TreeViewColumn::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

  auto
  TreeViewColumn::property_resizable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "resizable");
  }

  auto
  TreeViewColumn::property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "resizable");
  }

  auto
  TreeViewColumn::property_x_offset () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "x-offset");
  }

  auto
  TreeViewColumn::property_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "width");
  }

  auto
  TreeViewColumn::property_spacing () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "spacing");
  }

  auto
  TreeViewColumn::property_spacing () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "spacing");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Sizing>::value,
      "Type Sizing cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeViewColumn::property_sizing () -> glib::PropertyProxy<Sizing>
  {
    return glib::PropertyProxy<Sizing> (this, "sizing");
  }

  auto
  TreeViewColumn::property_sizing () const -> glib::PropertyProxy_ReadOnly<Sizing>
  {
    return glib::PropertyProxy_ReadOnly<Sizing> (this, "sizing");
  }

  auto
  TreeViewColumn::property_fixed_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "fixed-width");
  }

  auto
  TreeViewColumn::property_fixed_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "fixed-width");
  }

  auto
  TreeViewColumn::property_min_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "min-width");
  }

  auto
  TreeViewColumn::property_min_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "min-width");
  }

  auto
  TreeViewColumn::property_max_width () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-width");
  }

  auto
  TreeViewColumn::property_max_width () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-width");
  }

  auto
  TreeViewColumn::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  TreeViewColumn::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  TreeViewColumn::property_expand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "expand");
  }

  auto
  TreeViewColumn::property_expand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "expand");
  }

  auto
  TreeViewColumn::property_clickable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "clickable");
  }

  auto
  TreeViewColumn::property_clickable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "clickable");
  }

  auto
  TreeViewColumn::property_widget () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "widget");
  }

  auto
  TreeViewColumn::property_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "widget");
  }

  auto
  TreeViewColumn::property_alignment () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "alignment");
  }

  auto
  TreeViewColumn::property_alignment () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "alignment");
  }

  auto
  TreeViewColumn::property_reorderable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reorderable");
  }

  auto
  TreeViewColumn::property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reorderable");
  }

  auto
  TreeViewColumn::property_sort_indicator () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "sort-indicator");
  }

  auto
  TreeViewColumn::property_sort_indicator () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "sort-indicator");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
      "Type SortType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeViewColumn::property_sort_order () -> glib::PropertyProxy<SortType>
  {
    return glib::PropertyProxy<SortType> (this, "sort-order");
  }

  auto
  TreeViewColumn::property_sort_order () const -> glib::PropertyProxy_ReadOnly<SortType>
  {
    return glib::PropertyProxy_ReadOnly<SortType> (this, "sort-order");
  }

  auto
  TreeViewColumn::property_sort_column_id () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "sort-column-id");
  }

  auto
  TreeViewColumn::property_sort_column_id () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "sort-column-id");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<CellArea>>::value,
      "Type glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TreeViewColumn::property_cell_area () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>> (this,
                                                                 "cell-area");
  }

} // namespace gtk

#endif
