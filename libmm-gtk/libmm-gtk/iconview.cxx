// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/iconview.hxx>
  #include <libmm-gtk/iconview_p.hxx>

  #include <libmm-glib/vectorutils.hxx>

  #include <gtk/gtk.h>
  #include <libmm-gtk/adjustment.hxx>

namespace
{

  static auto
  proxy_foreach_callback (GtkIconView*, GtkTreePath* path, void* data) -> void
  {
    typedef Gtk::IconView::SlotForeach SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (Gtk::TreeModel::Path (path, true));
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
  }

} // namespace

namespace Gtk
{

  auto
  IconView::unset_model () -> void
  {
    gtk_icon_view_set_model (gobj (), nullptr);
  }

  auto
  IconView::selected_foreach (const SlotForeach& slot) -> void
  {
    SlotForeach slot_copy (slot);
    gtk_icon_view_selected_foreach (const_cast<GtkIconView*> (gobj ()),
                                    &proxy_foreach_callback,
                                    &slot_copy);
  }

  auto
  IconView::get_item_at_pos (int x,
                             int y,
                             TreeModel::Path& path,
                             CellRenderer*& cell) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    GtkCellRenderer* ccell = nullptr;
    bool result = gtk_icon_view_get_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        x,
        y,
        &cpath,
        &ccell);

    path = Glib::wrap (cpath);
    cell = Glib::wrap (ccell);
    return result;
  }

  auto
  IconView::get_item_at_pos (int x, int y, TreeModel::Path& path) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    bool result = gtk_icon_view_get_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        x,
        y,
        &cpath,
        nullptr);

    path = Glib::wrap (cpath);
    return result;
  }

  auto
  IconView::get_item_at_pos (int x, int y, CellRenderer*& cell) const -> bool
  {
    GtkCellRenderer* ccell = nullptr;
    bool result = gtk_icon_view_get_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        x,
        y,
        nullptr,
        &ccell);

    cell = Glib::wrap (ccell);
    return result;
  }

  auto
  IconView::get_visible_range (TreeModel::Path& start_path,
                               TreeModel::Path& end_path) const -> bool
  {
    GtkTreePath* cstart_path = nullptr;
    GtkTreePath* cend_path = nullptr;
    bool result = gtk_icon_view_get_visible_range (
        const_cast<GtkIconView*> (gobj ()),
        &cstart_path,
        &cend_path);

    start_path = Glib::wrap (cstart_path);
    end_path = Glib::wrap (cend_path);
    return result;
  }

  auto
  IconView::get_cursor (TreeModel::Path& path, CellRenderer*& cell) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    GtkCellRenderer* ccell = nullptr;
    bool result = gtk_icon_view_get_cursor (const_cast<GtkIconView*> (gobj ()),
                                            &cpath,
                                            &ccell);

    path = Glib::wrap (cpath);
    cell = Glib::wrap (ccell);
    return result;
  }

  auto
  IconView::get_cursor (TreeModel::Path& path) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    bool result = gtk_icon_view_get_cursor (const_cast<GtkIconView*> (gobj ()),
                                            &cpath,
                                            nullptr);

    path = Glib::wrap (cpath);
    return result;
  }

  auto
  IconView::get_cursor (CellRenderer*& cell) const -> bool
  {
    GtkCellRenderer* ccell = nullptr;
    bool result = gtk_icon_view_get_cursor (const_cast<GtkIconView*> (gobj ()),
                                            nullptr,
                                            &ccell);

    cell = Glib::wrap (ccell);
    return result;
  }

  auto
  IconView::get_drag_dest_item (TreeModel::Path& path, DropPosition& pos) const -> void
  {
    GtkTreePath* cpath = nullptr;
    gtk_icon_view_get_drag_dest_item (const_cast<GtkIconView*> (gobj ()),
                                      &cpath,
                                      (GtkIconViewDropPosition*) (&pos));
    if (cpath)
      path = Gtk::TreeModel::Path (cpath, true);
  }

  auto
  IconView::get_drag_dest_item (TreeModel::Path& path) const -> void
  {
    GtkTreePath* cpath = nullptr;
    gtk_icon_view_get_drag_dest_item (const_cast<GtkIconView*> (gobj ()),
                                      &cpath,
                                      nullptr);
    if (cpath)
      path = Gtk::TreeModel::Path (cpath, true);
  }

  auto
  IconView::get_drag_dest_item (DropPosition& pos) const -> void
  {
    gtk_icon_view_get_drag_dest_item (const_cast<GtkIconView*> (gobj ()),
                                      nullptr,
                                      (GtkIconViewDropPosition*) (&pos));
  }

  auto
  IconView::get_dest_item_at_pos (int drag_x,
                                  int drag_y,
                                  TreeModel::Path& path,
                                  DropPosition& pos) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    const bool result = gtk_icon_view_get_dest_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        drag_x,
        drag_y,
        &cpath,
        (GtkIconViewDropPosition*) (&pos));
    if (cpath)
      path = Gtk::TreeModel::Path (cpath, true);

    return result;
  }

  auto
  IconView::get_dest_item_at_pos (int drag_x,
                                  int drag_y,
                                  TreeModel::Path& path) const -> bool
  {
    GtkTreePath* cpath = nullptr;
    const bool result = gtk_icon_view_get_dest_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        drag_x,
        drag_y,
        &cpath,
        nullptr);
    if (cpath)
      path = Gtk::TreeModel::Path (cpath, true);

    return result;
  }

  auto
  IconView::get_dest_item_at_pos (int drag_x,
                                  int drag_y,
                                  DropPosition& pos) const -> bool
  {
    return gtk_icon_view_get_dest_item_at_pos (
        const_cast<GtkIconView*> (gobj ()),
        drag_x,
        drag_y,
        nullptr,
        (GtkIconViewDropPosition*) (&pos));
  }

  auto
  IconView::get_tooltip_context_path (int x,
                                      int y,
                                      bool keyboard_tip,
                                      TreeModel::Path& path) -> bool
  {
    GtkTreePath* cpath = nullptr;

    gboolean result = gtk_icon_view_get_tooltip_context (gobj (),
                                                         x,
                                                         y,
                                                         keyboard_tip,
                                                         nullptr,
                                                         &cpath,
                                                         nullptr);

    path = Glib::wrap (cpath, false);

    return result;
  }

  auto
  IconView::get_tooltip_context_iter (int x,
                                      int y,
                                      bool keyboard_tip,
                                      Gtk::TreeModel::iterator& iter) -> bool
  {
    GtkTreeIter src_iter;

    gboolean result = gtk_icon_view_get_tooltip_context (gobj (),
                                                         x,
                                                         y,
                                                         keyboard_tip,
                                                         nullptr,
                                                         nullptr,
                                                         &src_iter);

    iter = Gtk::TreeModel::iterator (gtk_icon_view_get_model (this->gobj ()),
                                     &src_iter);

    return result;
  }

} // namespace Gtk

namespace
{

  static auto
  IconView_signal_item_activated_callback (GtkIconView* self,
                                           GtkTreePath* p0,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const TreeModel::Path&)>;

    auto obj = dynamic_cast<IconView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Gtk::TreePath (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo IconView_signal_item_activated_info = {
      "item_activated",
      (GCallback) &IconView_signal_item_activated_callback,
      (GCallback) &IconView_signal_item_activated_callback};

  static const Glib::SignalProxyInfo IconView_signal_selection_changed_info = {
      "selection_changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gtk::IconView::DropPosition>::value_type () -> GType
{
  return gtk_icon_view_drop_position_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkIconView* object, bool take_copy) -> Gtk::IconView*
  {
    return dynamic_cast<Gtk::IconView*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  IconView_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &IconView_Class::class_init_function;

      register_derived_type (gtk_icon_view_get_type ());

      CellLayout::add_interface (get_type ());
      Scrollable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  IconView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  IconView_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new IconView ((GtkIconView*) (o)));
  }

  IconView::IconView (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  IconView::IconView (GtkIconView* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  IconView::IconView (IconView&& src) noexcept
    : Gtk::Widget (std::move (src)),
      CellLayout (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  IconView::operator= (IconView&& src) noexcept -> IconView&
  {
    Gtk::Widget::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    Scrollable::operator= (std::move (src));
    return *this;
  }

  IconView::~IconView () noexcept
  {
    destroy_ ();
  }

  IconView::CppClassType IconView::iconview_class_;

  auto
  IconView::get_type () -> GType
  {
    return iconview_class_.init ().get_type ();
  }

  auto
  IconView::get_base_type () -> GType
  {
    return gtk_icon_view_get_type ();
  }

  IconView::IconView ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (iconview_class_.init ()))
  {
  }

  IconView::IconView (const Glib::RefPtr<TreeModel>& model)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (iconview_class_.init (),
                                          "model",
                                          Glib::unwrap (model),
                                          nullptr))
  {
  }

  IconView::IconView (const Glib::RefPtr<CellArea>& cell_area)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (iconview_class_.init (),
                                          "cell_area",
                                          Glib::unwrap (cell_area),
                                          nullptr))
  {
  }

  auto
  IconView::set_model (const Glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_icon_view_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  IconView::get_model () -> Glib::RefPtr<TreeModel>
  {
    auto retvalue = Glib::wrap (gtk_icon_view_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  IconView::get_model () const -> Glib::RefPtr<const TreeModel>
  {
    return const_cast<IconView*> (this)->get_model ();
  }

  auto
  IconView::set_text_column (int column) -> void
  {
    gtk_icon_view_set_text_column (gobj (), column);
  }

  auto
  IconView::set_text_column (const TreeModelColumnBase& model_column) -> void
  {
    gtk_icon_view_set_text_column (gobj (), (model_column).index ());
  }

  auto
  IconView::get_text_column () const -> int
  {
    return gtk_icon_view_get_text_column (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_markup_column (int column) -> void
  {
    gtk_icon_view_set_markup_column (gobj (), column);
  }

  auto
  IconView::set_markup_column (const TreeModelColumnBase& column) -> void
  {
    gtk_icon_view_set_markup_column (gobj (), (column).index ());
  }

  auto
  IconView::get_markup_column () const -> int
  {
    return gtk_icon_view_get_markup_column (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_pixbuf_column (int column) -> void
  {
    gtk_icon_view_set_pixbuf_column (gobj (), column);
  }

  auto
  IconView::set_pixbuf_column (const TreeModelColumnBase& column) -> void
  {
    gtk_icon_view_set_pixbuf_column (gobj (), (column).index ());
  }

  auto
  IconView::get_pixbuf_column () const -> int
  {
    return gtk_icon_view_get_pixbuf_column (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_item_orientation (Orientation orientation) -> void
  {
    gtk_icon_view_set_item_orientation (
        gobj (),
        static_cast<GtkOrientation> (orientation));
  }

  auto
  IconView::get_item_orientation () const -> Orientation
  {
    return static_cast<Orientation> (gtk_icon_view_get_item_orientation (
        const_cast<GtkIconView*> (gobj ())));
  }

  auto
  IconView::set_columns (int columns) -> void
  {
    gtk_icon_view_set_columns (gobj (), columns);
  }

  auto
  IconView::get_columns () const -> int
  {
    return gtk_icon_view_get_columns (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_item_width (int item_width) -> void
  {
    gtk_icon_view_set_item_width (gobj (), item_width);
  }

  auto
  IconView::get_icon_width () const -> int
  {
    return gtk_icon_view_get_item_width (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_spacing (int spacing) -> void
  {
    gtk_icon_view_set_spacing (gobj (), spacing);
  }

  auto
  IconView::get_spacing () const -> int
  {
    return gtk_icon_view_get_spacing (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_row_spacing (int row_spacing) -> void
  {
    gtk_icon_view_set_row_spacing (gobj (), row_spacing);
  }

  auto
  IconView::get_row_spacing () const -> int
  {
    return gtk_icon_view_get_row_spacing (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_column_spacing (int column_spacing) -> void
  {
    gtk_icon_view_set_column_spacing (gobj (), column_spacing);
  }

  auto
  IconView::get_column_spacing () const -> int
  {
    return gtk_icon_view_get_column_spacing (
        const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_margin (int margin) -> void
  {
    gtk_icon_view_set_margin (gobj (), margin);
  }

  auto
  IconView::get_margin () const -> int
  {
    return gtk_icon_view_get_margin (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_item_padding (int item_padding) -> void
  {
    gtk_icon_view_set_item_padding (gobj (), item_padding);
  }

  auto
  IconView::get_item_padding () const -> int
  {
    return gtk_icon_view_get_item_padding (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::get_path_at_pos (int x, int y) const -> TreeModel::Path
  {
    return Gtk::TreePath (
        gtk_icon_view_get_path_at_pos (const_cast<GtkIconView*> (gobj ()),
                                       x,
                                       y),
        false);
  }

  auto
  IconView::set_activate_on_single_click (bool single) -> void
  {
    gtk_icon_view_set_activate_on_single_click (gobj (),
                                                static_cast<int> (single));
  }

  auto
  IconView::get_activate_on_single_click () const -> bool
  {
    return gtk_icon_view_get_activate_on_single_click (
        const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_selection_mode (SelectionMode mode) -> void
  {
    gtk_icon_view_set_selection_mode (gobj (),
                                      static_cast<GtkSelectionMode> (mode));
  }

  auto
  IconView::get_selection_mode () const -> SelectionMode
  {
    return static_cast<SelectionMode> (
        gtk_icon_view_get_selection_mode (const_cast<GtkIconView*> (gobj ())));
  }

  auto
  IconView::select_path (const TreeModel::Path& path) -> void
  {
    gtk_icon_view_select_path (gobj (),
                               const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::unselect_path (const TreeModel::Path& path) -> void
  {
    gtk_icon_view_unselect_path (gobj (),
                                 const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::path_is_selected (const TreeModel::Path& path) const -> bool
  {
    return gtk_icon_view_path_is_selected (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::get_item_row (const TreeModel::Path& path) const -> int
  {
    return gtk_icon_view_get_item_row (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::get_item_column (const TreeModel::Path& path) const -> int
  {
    return gtk_icon_view_get_item_column (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::get_selected_items () const -> std::vector<TreePath>
  {
    return Glib::ListHandler<TreePath, TreePathTraits>::list_to_vector (
        gtk_icon_view_get_selected_items (const_cast<GtkIconView*> (gobj ())),
        Glib::OWNERSHIP_DEEP);
  }

  auto
  IconView::select_all () -> void
  {
    gtk_icon_view_select_all (gobj ());
  }

  auto
  IconView::unselect_all () -> void
  {
    gtk_icon_view_unselect_all (gobj ());
  }

  auto
  IconView::item_activated (const TreeModel::Path& path) -> void
  {
    gtk_icon_view_item_activated (gobj (),
                                  const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::set_cursor (const TreeModel::Path& path,
                        CellRenderer& cell,
                        bool start_editing) -> void
  {
    gtk_icon_view_set_cursor (gobj (),
                              const_cast<GtkTreePath*> ((path).gobj ()),
                              (cell).gobj (),
                              static_cast<int> (start_editing));
  }

  auto
  IconView::set_cursor (const TreeModel::Path& path, bool start_editing) -> void
  {
    gtk_icon_view_set_cursor (gobj (),
                              const_cast<GtkTreePath*> ((path).gobj ()),
                              nullptr,
                              static_cast<int> (start_editing));
  }

  auto
  IconView::scroll_to_path (const TreeModel::Path& path,
                            bool use_align,
                            float row_align,
                            float col_align) -> void
  {
    gtk_icon_view_scroll_to_path (gobj (),
                                  const_cast<GtkTreePath*> ((path).gobj ()),
                                  static_cast<int> (use_align),
                                  row_align,
                                  col_align);
  }

  auto
  IconView::enable_model_drag_source (
      const Glib::RefPtr<const Gdk::ContentFormats>& formats,
      Gdk::ModifierType start_button_mask,
      Gdk::DragAction actions) -> void
  {
    gtk_icon_view_enable_model_drag_source (
        gobj (),
        static_cast<GdkModifierType> (start_button_mask),
        const_cast<GdkContentFormats*> (Glib::unwrap (formats)),
        static_cast<GdkDragAction> (actions));
  }

  auto
  IconView::enable_model_drag_dest (
      const Glib::RefPtr<const Gdk::ContentFormats>& formats,
      Gdk::DragAction actions) -> void
  {
    gtk_icon_view_enable_model_drag_dest (
        gobj (),
        const_cast<GdkContentFormats*> (Glib::unwrap (formats)),
        static_cast<GdkDragAction> (actions));
  }

  auto
  IconView::unset_model_drag_source () -> void
  {
    gtk_icon_view_unset_model_drag_source (gobj ());
  }

  auto
  IconView::unset_model_drag_dest () -> void
  {
    gtk_icon_view_unset_model_drag_dest (gobj ());
  }

  auto
  IconView::set_reorderable (bool reorderable) -> void
  {
    gtk_icon_view_set_reorderable (gobj (), static_cast<int> (reorderable));
  }

  auto
  IconView::get_reorderable () const -> bool
  {
    return gtk_icon_view_get_reorderable (const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::set_drag_dest_item (const TreeModel::Path& path, DropPosition pos) -> void
  {
    gtk_icon_view_set_drag_dest_item (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()),
        static_cast<GtkIconViewDropPosition> (pos));
  }

  auto
  IconView::create_drag_icon (const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::Paintable>
  {
    return Glib::wrap (gtk_icon_view_create_drag_icon (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ())));
  }

  auto
  IconView::get_cell_rect (const TreeModel::Path& path,
                           const CellRenderer& cell,
                           Gdk::Rectangle& rect) const -> bool
  {
    GdkRectangle g_rect = GdkRectangle ();
    auto retvalue = gtk_icon_view_get_cell_rect (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()),
        const_cast<GtkCellRenderer*> ((cell).gobj ()),
        &g_rect);
    rect = Glib::wrap (&(g_rect));
    return retvalue;
  }

  auto
  IconView::get_cell_rect (const TreeModel::Path& path,
                           Gdk::Rectangle& rect) const -> bool
  {
    GdkRectangle g_rect = GdkRectangle ();
    auto retvalue = gtk_icon_view_get_cell_rect (
        const_cast<GtkIconView*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ()),
        nullptr,
        &g_rect);
    rect = Glib::wrap (&(g_rect));
    return retvalue;
  }

  auto
  IconView::set_tooltip_item (const Glib::RefPtr<Tooltip>& tooltip,
                              const TreeModel::Path& path) -> void
  {
    gtk_icon_view_set_tooltip_item (gobj (),
                                    Glib::unwrap (tooltip),
                                    const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  IconView::set_tooltip_cell (const Glib::RefPtr<Tooltip>& tooltip,
                              const TreeModel::Path& path,
                              CellRenderer& cell) -> void
  {
    gtk_icon_view_set_tooltip_cell (gobj (),
                                    Glib::unwrap (tooltip),
                                    const_cast<GtkTreePath*> ((path).gobj ()),
                                    (cell).gobj ());
  }

  auto
  IconView::set_tooltip_column (int column) -> void
  {
    gtk_icon_view_set_tooltip_column (gobj (), column);
  }

  auto
  IconView::get_tooltip_column () const -> int
  {
    return gtk_icon_view_get_tooltip_column (
        const_cast<GtkIconView*> (gobj ()));
  }

  auto
  IconView::signal_item_activated () -> Glib::SignalProxy<void (const TreeModel::Path&)>
  {
    return Glib::SignalProxy<void (const TreeModel::Path&)> (
        this,
        &IconView_signal_item_activated_info);
  }

  auto
  IconView::signal_selection_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &IconView_signal_selection_changed_info);
  }

  auto
  IconView::property_pixbuf_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "pixbuf-column");
  }

  auto
  IconView::property_pixbuf_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "pixbuf-column");
  }

  auto
  IconView::property_text_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "text-column");
  }

  auto
  IconView::property_text_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "text-column");
  }

  auto
  IconView::property_markup_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "markup-column");
  }

  auto
  IconView::property_markup_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "markup-column");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
      "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconView::property_selection_mode () -> Glib::PropertyProxy<SelectionMode>
  {
    return Glib::PropertyProxy<SelectionMode> (this, "selection-mode");
  }

  auto
  IconView::property_selection_mode () const -> Glib::PropertyProxy_ReadOnly<SelectionMode>
  {
    return Glib::PropertyProxy_ReadOnly<SelectionMode> (this, "selection-mode");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Orientation>::value,
      "Type Orientation cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconView::property_item_orientation () -> Glib::PropertyProxy<Orientation>
  {
    return Glib::PropertyProxy<Orientation> (this, "item-orientation");
  }

  auto
  IconView::property_item_orientation () const -> Glib::PropertyProxy_ReadOnly<Orientation>
  {
    return Glib::PropertyProxy_ReadOnly<Orientation> (this, "item-orientation");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TreeModel>>::value,
      "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconView::property_model () -> Glib::PropertyProxy<Glib::RefPtr<TreeModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<TreeModel>> (this, "model");
  }

  auto
  IconView::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

  auto
  IconView::property_columns () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "columns");
  }

  auto
  IconView::property_columns () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "columns");
  }

  auto
  IconView::property_item_width () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "item-width");
  }

  auto
  IconView::property_item_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "item-width");
  }

  auto
  IconView::property_spacing () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "spacing");
  }

  auto
  IconView::property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "spacing");
  }

  auto
  IconView::property_row_spacing () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "row-spacing");
  }

  auto
  IconView::property_row_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "row-spacing");
  }

  auto
  IconView::property_column_spacing () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "column-spacing");
  }

  auto
  IconView::property_column_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "column-spacing");
  }

  auto
  IconView::property_margin () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "margin");
  }

  auto
  IconView::property_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "margin");
  }

  auto
  IconView::property_reorderable () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "reorderable");
  }

  auto
  IconView::property_reorderable () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "reorderable");
  }

  auto
  IconView::property_tooltip_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "tooltip-column");
  }

  auto
  IconView::property_tooltip_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "tooltip-column");
  }

  auto
  IconView::property_item_padding () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "item-padding");
  }

  auto
  IconView::property_item_padding () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "item-padding");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<CellArea>>::value,
      "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  IconView::property_cell_area () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>> (this,
                                                                 "cell-area");
  }

  auto
  IconView::property_activate_on_single_click () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activate-on-single-click");
  }

  auto
  IconView::property_activate_on_single_click () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "activate-on-single-click");
  }

} // namespace Gtk

#endif
