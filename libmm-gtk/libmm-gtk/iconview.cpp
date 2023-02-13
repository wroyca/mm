


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/iconview.hpp>
#include <libmm-gtk/iconview_p.hpp>


/* Copyright 1998-2004 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/vectorutils.hpp>

#include <libmm-gtk/adjustment.hpp>
#include <gtk/gtk.h>

namespace //anonymous namespace
{

auto proxy_foreach_callback (GtkIconView * /* icon_view */, GtkTreePath *path, void *data) -> void
{
  typedef Gtk::IconView::SlotForeach SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Gtk::TreeModel::Path(path, true));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

} //anonymous namespace


namespace Gtk
{

auto IconView::unset_model () -> void
{
  gtk_icon_view_set_model(gobj(), nullptr);
}

auto IconView::selected_foreach (const SlotForeach &slot) -> void
{
  SlotForeach slot_copy(slot);
  gtk_icon_view_selected_foreach(gobj(), &proxy_foreach_callback, &slot_copy);
}

auto IconView::get_item_at_pos(
  const int x, const int y, TreeModel::Path& path, CellRenderer*& cell) const -> bool
{
  GtkTreePath* cpath = nullptr;
  GtkCellRenderer* ccell = nullptr;
  const bool result = gtk_icon_view_get_item_at_pos(const_cast<GtkIconView*>(gobj()), x, y, &cpath, &ccell);

  path = Glib::wrap(cpath); //Don't take copy because the gtk_icon_view_get_item_at_pos documentation says we should free this.
  cell = Glib::wrap(ccell);
  return result;
}

auto IconView::get_item_at_pos(
  const int x, const int y, TreeModel::Path& path) const -> bool
{
  GtkTreePath* cpath = nullptr;
  const bool result = gtk_icon_view_get_item_at_pos(const_cast<GtkIconView*>(gobj()), x, y, &cpath, nullptr);

  path = Glib::wrap(cpath); //Don't take copy because the gtk_icon_view_get_item_at_pos documentation says we should free this.
  return result;
}

auto IconView::get_item_at_pos(
  const int x, const int y, CellRenderer*& cell) const -> bool
{
  GtkCellRenderer* ccell = nullptr;
  const bool result = gtk_icon_view_get_item_at_pos(const_cast<GtkIconView*>(gobj()), x, y, nullptr, &ccell);

  cell = Glib::wrap(ccell);
  return result;
}

auto IconView::get_visible_range(TreeModel::Path& start_path, TreeModel::Path& end_path) const -> bool
{
  GtkTreePath* cstart_path = nullptr;
  GtkTreePath* cend_path = nullptr;
  const bool result = gtk_icon_view_get_visible_range(const_cast<GtkIconView*>(gobj()), &cstart_path, &cend_path);

  start_path = Glib::wrap(cstart_path); //Don't take copy because the gtk_icon_view_get_visible_range documentation says we should free this.
  end_path = Glib::wrap(cend_path); //Don't take copy because the gtk_icon_view_get_visible_range documentation says we should free this.
  return result;
}


auto IconView::get_cursor(TreeModel::Path& path, CellRenderer*& cell) const -> bool
{
  GtkTreePath* cpath = nullptr;
  GtkCellRenderer* ccell = nullptr;
  const bool result = gtk_icon_view_get_cursor(const_cast<GtkIconView*>(gobj()), &cpath, &ccell);

  path = Glib::wrap(cpath); //Don't take copy because the gtk_icon_view_get_cursor documentation says we should free this.
  cell = Glib::wrap(ccell);
  return result;
}

auto IconView::get_cursor(TreeModel::Path& path) const -> bool
{
  GtkTreePath* cpath = nullptr;
  const bool result = gtk_icon_view_get_cursor(const_cast<GtkIconView*>(gobj()), &cpath, nullptr);

  path = Glib::wrap(cpath); //Don't take copy because the gtk_icon_view_get_cursor documentation says we should free this.
  return result;
}

auto IconView::get_cursor(CellRenderer*& cell) const -> bool
{
  GtkCellRenderer* ccell = nullptr;
  const bool result = gtk_icon_view_get_cursor(const_cast<GtkIconView*>(gobj()), nullptr, &ccell);

  cell = Glib::wrap(ccell);
  return result;
}

auto IconView::get_drag_dest_item (TreeModel::Path &path, DropPosition &pos) const -> void
{
  GtkTreePath* cpath = nullptr;
  gtk_icon_view_get_drag_dest_item(const_cast<GtkIconView*>(gobj()), &cpath, (GtkIconViewDropPosition*)&pos);
  if(cpath)
    path = TreeModel::Path(cpath, true /* make_a_copy */);
}

auto IconView::get_drag_dest_item (TreeModel::Path &path) const -> void
{
  GtkTreePath* cpath = nullptr;
  gtk_icon_view_get_drag_dest_item(const_cast<GtkIconView*>(gobj()), &cpath, nullptr);
  if(cpath)
    path = TreeModel::Path(cpath, true /* make_a_copy */);
}

auto IconView::get_drag_dest_item (DropPosition &pos) const -> void
{
   gtk_icon_view_get_drag_dest_item(const_cast<GtkIconView*>(gobj()), nullptr, (GtkIconViewDropPosition*)&pos);
}


auto IconView::get_dest_item_at_pos(
  const int drag_x, const int drag_y, TreeModel::Path& path, DropPosition& pos) const -> bool
{
  GtkTreePath* cpath = nullptr;
  const bool result = gtk_icon_view_get_dest_item_at_pos(const_cast<GtkIconView*>(gobj()), drag_x, drag_y, &cpath, (GtkIconViewDropPosition*)&pos);
  if(cpath)
    path = TreeModel::Path(cpath, true /* make_a_copy */);

  return result;
}

auto IconView::get_dest_item_at_pos(
  const int drag_x, const int drag_y, TreeModel::Path& path) const -> bool
{
  GtkTreePath* cpath = nullptr;
  const bool result = gtk_icon_view_get_dest_item_at_pos(const_cast<GtkIconView*>(gobj()), drag_x, drag_y, &cpath, nullptr);
  if(cpath)
    path = TreeModel::Path(cpath, true /* make_a_copy */);

  return result;
}

auto IconView::get_dest_item_at_pos(
  const int drag_x, const int drag_y, DropPosition& pos) const -> bool
{
  return gtk_icon_view_get_dest_item_at_pos(const_cast<GtkIconView*>(gobj()), drag_x, drag_y, nullptr, (GtkIconViewDropPosition*)&pos);
}

auto
IconView::get_tooltip_context_path(
  const int x, const int y, const bool keyboard_tip,
                                   TreeModel::Path& path) -> bool
{
  GtkTreePath* cpath = nullptr;

  const gboolean result =
    gtk_icon_view_get_tooltip_context(gobj(),
                                      x, y,
                                      keyboard_tip,
                                      nullptr,
                                      &cpath,
                                      nullptr);

  // If result is false, cpath is not modified, it's still 0.
  // wrap() can handle that situation.
  path = Glib::wrap(cpath, /* take_copy= */ false);

  return result;
}

auto
IconView::get_tooltip_context_iter(
  const int x, const int y, const bool keyboard_tip, TreeModel::iterator& iter) -> bool
{
  GtkTreeIter src_iter;

  const gboolean result =
    gtk_icon_view_get_tooltip_context(gobj(),
                                      x, y,
                                      keyboard_tip,
                                      nullptr,
                                      nullptr,
                                      &src_iter);

  iter = TreeModel::iterator(gtk_icon_view_get_model(this->gobj()), &src_iter);

  return result;
}

} // namespace Gtk


namespace
{


auto IconView_signal_item_activated_callback (
  GtkIconView *self, GtkTreePath *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&)>;

  const auto obj = dynamic_cast<IconView*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(
          TreePath(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo IconView_signal_item_activated_info =
{
  "item_activated",
  (GCallback) &IconView_signal_item_activated_callback,
  (GCallback) &IconView_signal_item_activated_callback
};


const Glib::SignalProxyInfo IconView_signal_selection_changed_info =
{
  "selection_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::IconView::DropPosition>::value_type() -> GType
{
  return gtk_icon_view_drop_position_get_type();
}


namespace Glib
{

auto wrap(GtkIconView* object, const bool take_copy) -> Gtk::IconView*
{
  return dynamic_cast<Gtk::IconView *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto IconView_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &IconView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_icon_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  Scrollable::add_interface(get_type());

  }

  return *this;
}


auto IconView_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto IconView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new IconView((GtkIconView*)o));

}


/* The implementation: */

IconView::IconView(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

IconView::IconView(GtkIconView* castitem)
: Widget((GtkWidget*)castitem)
{
  }


IconView::IconView(IconView&& src) noexcept
: Widget(std::move(src))
  , CellLayout(std::move(src))
  , Scrollable(std::move(src))
{}

auto IconView::operator=(IconView&& src) noexcept -> IconView&
{
  Widget::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  Scrollable::operator=(std::move(src));
  return *this;
}

IconView::~IconView() noexcept
{
  destroy_();
}

IconView::CppClassType IconView::iconview_class_; // initialize static member

auto IconView::get_type() -> GType
{
  return iconview_class_.init().get_type();
}


auto IconView::get_base_type() -> GType
{
  return gtk_icon_view_get_type();
}


IconView::IconView()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(iconview_class_.init()))
{


}

IconView::IconView(const Glib::RefPtr<TreeModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(iconview_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

IconView::IconView(const Glib::RefPtr<CellArea>& cell_area)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(iconview_class_.init(), "cell_area", Glib::unwrap(cell_area), nullptr))
{


}

auto IconView::set_model (const Glib::RefPtr <TreeModel> &model) -> void
{
  gtk_icon_view_set_model(gobj(), Glib::unwrap(model));
}

auto IconView::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_icon_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto IconView::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<IconView*>(this)->get_model();
}

auto IconView::set_text_column (
  const int column) -> void
{
  gtk_icon_view_set_text_column(gobj(), column);
}

auto IconView::set_text_column (const TreeModelColumnBase &model_column) -> void
{
  gtk_icon_view_set_text_column(gobj(), model_column.index());
}

auto IconView::get_text_column() const -> int
{
  return gtk_icon_view_get_text_column(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_markup_column (
  const int column) -> void
{
  gtk_icon_view_set_markup_column(gobj(), column);
}

auto IconView::set_markup_column (const TreeModelColumnBase &column) -> void
{
  gtk_icon_view_set_markup_column(gobj(), column.index());
}

auto IconView::get_markup_column() const -> int
{
  return gtk_icon_view_get_markup_column(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_pixbuf_column (
  const int column) -> void
{
  gtk_icon_view_set_pixbuf_column(gobj(), column);
}

auto IconView::set_pixbuf_column (const TreeModelColumnBase &column) -> void
{
  gtk_icon_view_set_pixbuf_column(gobj(), column.index());
}

auto IconView::get_pixbuf_column() const -> int
{
  return gtk_icon_view_get_pixbuf_column(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_item_orientation (Orientation orientation) -> void
{
  gtk_icon_view_set_item_orientation(gobj(), static_cast<GtkOrientation>(orientation));
}

auto IconView::get_item_orientation() const -> Orientation
{
  return static_cast<Orientation>(gtk_icon_view_get_item_orientation(const_cast<GtkIconView*>(gobj())));
}

auto IconView::set_columns (
  const int columns) -> void
{
  gtk_icon_view_set_columns(gobj(), columns);
}

auto IconView::get_columns() const -> int
{
  return gtk_icon_view_get_columns(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_item_width (
  const int item_width) -> void
{
  gtk_icon_view_set_item_width(gobj(), item_width);
}

auto IconView::get_icon_width() const -> int
{
  return gtk_icon_view_get_item_width(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_spacing (
  const int spacing) -> void
{
  gtk_icon_view_set_spacing(gobj(), spacing);
}

auto IconView::get_spacing() const -> int
{
  return gtk_icon_view_get_spacing(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_row_spacing (
  const int row_spacing) -> void
{
  gtk_icon_view_set_row_spacing(gobj(), row_spacing);
}

auto IconView::get_row_spacing() const -> int
{
  return gtk_icon_view_get_row_spacing(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_column_spacing (
  const int column_spacing) -> void
{
  gtk_icon_view_set_column_spacing(gobj(), column_spacing);
}

auto IconView::get_column_spacing() const -> int
{
  return gtk_icon_view_get_column_spacing(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_margin (
  const int margin) -> void
{
  gtk_icon_view_set_margin(gobj(), margin);
}

auto IconView::get_margin() const -> int
{
  return gtk_icon_view_get_margin(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_item_padding (
  const int item_padding) -> void
{
  gtk_icon_view_set_item_padding(gobj(), item_padding);
}

auto IconView::get_item_padding() const -> int
{
  return gtk_icon_view_get_item_padding(const_cast<GtkIconView*>(gobj()));
}

auto IconView::get_path_at_pos(
  const int x, const int y) const -> TreeModel::Path
{
  return TreePath(gtk_icon_view_get_path_at_pos(const_cast<GtkIconView*>(gobj()), x, y), false);
}

auto IconView::set_activate_on_single_click (
  const bool single) -> void
{
  gtk_icon_view_set_activate_on_single_click(gobj(), single);
}

auto IconView::get_activate_on_single_click() const -> bool
{
  return gtk_icon_view_get_activate_on_single_click(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_selection_mode (SelectionMode mode) -> void
{
  gtk_icon_view_set_selection_mode(gobj(), static_cast<GtkSelectionMode>(mode));
}

auto IconView::get_selection_mode() const -> SelectionMode
{
  return static_cast<SelectionMode>(gtk_icon_view_get_selection_mode(const_cast<GtkIconView*>(gobj())));
}

auto IconView::select_path (const TreeModel::Path &path) -> void
{
  gtk_icon_view_select_path(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::unselect_path (const TreeModel::Path &path) -> void
{
  gtk_icon_view_unselect_path(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::path_is_selected(const TreeModel::Path& path) const -> bool
{
  return gtk_icon_view_path_is_selected(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::get_item_row(const TreeModel::Path& path) const -> int
{
  return gtk_icon_view_get_item_row(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::get_item_column(const TreeModel::Path& path) const -> int
{
  return gtk_icon_view_get_item_column(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::get_selected_items() const -> std::vector<TreePath>
{
  return Glib::ListHandler<TreePath, TreePathTraits>::list_to_vector(gtk_icon_view_get_selected_items(const_cast<GtkIconView*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto IconView::select_all () -> void
{
  gtk_icon_view_select_all(gobj());
}

auto IconView::unselect_all () -> void
{
  gtk_icon_view_unselect_all(gobj());
}

auto IconView::item_activated (const TreeModel::Path &path) -> void
{
  gtk_icon_view_item_activated(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::set_cursor (
  const TreeModel::Path &path, CellRenderer &cell, const bool start_editing) -> void
{
  gtk_icon_view_set_cursor(gobj(), const_cast<GtkTreePath*>(path.gobj()), cell.gobj(), start_editing);
}

auto IconView::set_cursor (const TreeModel::Path &path, const bool start_editing) -> void
{
  gtk_icon_view_set_cursor(gobj(), const_cast<GtkTreePath*>(path.gobj()), nullptr, start_editing);
}

auto IconView::scroll_to_path (
  const TreeModel::Path &path, const bool use_align, const float row_align, const float col_align) -> void
{
  gtk_icon_view_scroll_to_path(gobj(), const_cast<GtkTreePath*>(path.gobj()), use_align, row_align, col_align);
}

auto IconView::enable_model_drag_source (
  const Glib::RefPtr <const Gdk::ContentFormats> &formats, Gdk::ModifierType start_button_mask,
  Gdk::DragAction actions) -> void
{
  gtk_icon_view_enable_model_drag_source(gobj(), static_cast<GdkModifierType>(start_button_mask), const_cast<GdkContentFormats*>(Glib::unwrap(formats)), static_cast<GdkDragAction>(actions));
}

auto IconView::enable_model_drag_dest (
  const Glib::RefPtr <const Gdk::ContentFormats> &formats, Gdk::DragAction actions) -> void
{
  gtk_icon_view_enable_model_drag_dest(gobj(), const_cast<GdkContentFormats*>(Glib::unwrap(formats)), static_cast<GdkDragAction>(actions));
}

auto IconView::unset_model_drag_source () -> void
{
  gtk_icon_view_unset_model_drag_source(gobj());
}

auto IconView::unset_model_drag_dest () -> void
{
  gtk_icon_view_unset_model_drag_dest(gobj());
}

auto IconView::set_reorderable (
  const bool reorderable) -> void
{
  gtk_icon_view_set_reorderable(gobj(), reorderable);
}

auto IconView::get_reorderable() const -> bool
{
  return gtk_icon_view_get_reorderable(const_cast<GtkIconView*>(gobj()));
}

auto IconView::set_drag_dest_item (const TreeModel::Path &path, DropPosition pos) -> void
{
  gtk_icon_view_set_drag_dest_item(gobj(), const_cast<GtkTreePath*>(path.gobj()), static_cast<GtkIconViewDropPosition>(pos));
}

auto IconView::create_drag_icon(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::Paintable>
{
  return Glib::wrap(gtk_icon_view_create_drag_icon(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj())));
}

auto IconView::get_cell_rect(const TreeModel::Path& path, const CellRenderer& cell, Gdk::Rectangle& rect) const -> bool
{
  GdkRectangle g_rect = GdkRectangle();
  const auto retvalue = gtk_icon_view_get_cell_rect(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj()), const_cast<GtkCellRenderer*>(cell.gobj()), &g_rect);
rect = Glib::wrap(&g_rect);
  return retvalue;
}

auto IconView::get_cell_rect(const TreeModel::Path& path, Gdk::Rectangle& rect) const -> bool
{
  GdkRectangle g_rect = GdkRectangle();
  const auto retvalue = gtk_icon_view_get_cell_rect(const_cast<GtkIconView*>(gobj()), const_cast<GtkTreePath*>(path.gobj()), nullptr, &g_rect);
rect = Glib::wrap(&g_rect);
  return retvalue;
}

auto IconView::set_tooltip_item (
  const Glib::RefPtr <Tooltip> &tooltip, const TreeModel::Path &path) -> void
{
  gtk_icon_view_set_tooltip_item(gobj(), Glib::unwrap(tooltip), const_cast<GtkTreePath*>(path.gobj()));
}

auto IconView::set_tooltip_cell (
  const Glib::RefPtr <Tooltip> &tooltip, const TreeModel::Path &path, CellRenderer &cell) -> void
{
  gtk_icon_view_set_tooltip_cell(gobj(), Glib::unwrap(tooltip), const_cast<GtkTreePath*>(path.gobj()), cell.gobj());
}

auto IconView::set_tooltip_column (
  const int column) -> void
{
  gtk_icon_view_set_tooltip_column(gobj(), column);
}

auto IconView::get_tooltip_column() const -> int
{
  return gtk_icon_view_get_tooltip_column(const_cast<GtkIconView*>(gobj()));
}


auto IconView::signal_item_activated() -> Glib::SignalProxy<void(const TreeModel::Path&)>
{
  return {this, &IconView_signal_item_activated_info};
}


auto IconView::signal_selection_changed() -> Glib::SignalProxy<void()>
{
  return {this, &IconView_signal_selection_changed_info};
}


auto IconView::property_pixbuf_column() -> Glib::PropertyProxy< int >
{
  return {this, "pixbuf-column"};
}

auto IconView::property_pixbuf_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pixbuf-column"};
}

auto IconView::property_text_column() -> Glib::PropertyProxy< int >
{
  return {this, "text-column"};
}

auto IconView::property_text_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "text-column"};
}

auto IconView::property_markup_column() -> Glib::PropertyProxy< int >
{
  return {this, "markup-column"};
}

auto IconView::property_markup_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "markup-column"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
  "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto IconView::property_selection_mode() -> Glib::PropertyProxy< SelectionMode >
{
  return {this, "selection-mode"};
}

auto IconView::property_selection_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >
{
  return {this, "selection-mode"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Orientation>::value,
  "Type Orientation cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto IconView::property_item_orientation() -> Glib::PropertyProxy< Orientation >
{
  return {this, "item-orientation"};
}

auto IconView::property_item_orientation() const -> Glib::PropertyProxy_ReadOnly< Orientation >
{
  return {this, "item-orientation"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto IconView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto IconView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto IconView::property_columns() -> Glib::PropertyProxy< int >
{
  return {this, "columns"};
}

auto IconView::property_columns() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "columns"};
}

auto IconView::property_item_width() -> Glib::PropertyProxy< int >
{
  return {this, "item-width"};
}

auto IconView::property_item_width() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "item-width"};
}

auto IconView::property_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "spacing"};
}

auto IconView::property_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "spacing"};
}

auto IconView::property_row_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "row-spacing"};
}

auto IconView::property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "row-spacing"};
}

auto IconView::property_column_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "column-spacing"};
}

auto IconView::property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "column-spacing"};
}

auto IconView::property_margin() -> Glib::PropertyProxy< int >
{
  return {this, "margin"};
}

auto IconView::property_margin() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "margin"};
}

auto IconView::property_reorderable() -> Glib::PropertyProxy< int >
{
  return {this, "reorderable"};
}

auto IconView::property_reorderable() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "reorderable"};
}

auto IconView::property_tooltip_column() -> Glib::PropertyProxy< int >
{
  return {this, "tooltip-column"};
}

auto IconView::property_tooltip_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "tooltip-column"};
}

auto IconView::property_item_padding() -> Glib::PropertyProxy< int >
{
  return {this, "item-padding"};
}

auto IconView::property_item_padding() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "item-padding"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellArea>>::value,
  "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto IconView::property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >
{
  return {this, "cell-area"};
}

auto IconView::property_activate_on_single_click() -> Glib::PropertyProxy< bool >
{
  return {this, "activate-on-single-click"};
}

auto IconView::property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activate-on-single-click"};
}


} // namespace Gtk


