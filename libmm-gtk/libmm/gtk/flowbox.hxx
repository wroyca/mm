// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FLOWBOX_H
#define _GTKMM_FLOWBOX_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/liststore.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/gtk/flowboxchild.hxx>
#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>
#include <utility>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFlowBox = struct _GtkFlowBox;
using GtkFlowBoxClass = struct _GtkFlowBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FlowBox_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FlowBox : public Widget,
                            public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FlowBox CppObjectType;
    typedef FlowBox_Class CppClassType;
    typedef GtkFlowBox BaseObjectType;
    typedef GtkFlowBoxClass BaseClassType;
#endif

    FlowBox (FlowBox&& src) noexcept;
    auto
    operator= (FlowBox&& src) noexcept -> FlowBox&;

    FlowBox (const FlowBox&) = delete;
    auto
    operator= (const FlowBox&) -> FlowBox& = delete;

    ~FlowBox () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FlowBox_Class;
    static CppClassType flowbox_class_;

  protected:
    explicit FlowBox (const glib::ConstructParams& construct_params);
    explicit FlowBox (GtkFlowBox* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFlowBox*
    {
      return reinterpret_cast<GtkFlowBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkFlowBox*
    {
      return reinterpret_cast<GtkFlowBox*> (gobject_);
    }

  private:
  public:
    FlowBox ();

    typedef sigc::slot<void (FlowBox*, FlowBoxChild*)> SlotSelectedForeach;

    typedef sigc::slot<bool (FlowBoxChild*)> SlotFilter;

    typedef sigc::slot<int (FlowBoxChild*, FlowBoxChild*)> SlotSort;

    auto
    set_homogeneous (bool homogeneous = true) -> void;

    auto
    get_homogeneous () const -> bool;

    auto
    set_row_spacing (guint spacing) -> void;

    auto
    get_row_spacing () const -> guint;

    auto
    set_column_spacing (guint spacing) -> void;

    auto
    get_column_spacing () const -> guint;

    auto
    set_min_children_per_line (guint n_children) -> void;

    auto
    get_min_children_per_line () const -> guint;

    auto
    set_max_children_per_line (guint n_children) -> void;

    auto
    get_max_children_per_line () const -> guint;

    auto
    set_activate_on_single_click (bool single = true) -> void;

    auto
    get_activate_on_single_click () const -> bool;

    auto
    prepend (Widget& child) -> void;

    auto
    append (Widget& child) -> void;

    auto
    insert (Widget& widget, int position) -> void;

    auto
    remove (Widget& widget) -> void;

    auto
    get_child_at_index (int idx) -> FlowBoxChild*;

    auto
    get_child_at_index (int idx) const -> const FlowBoxChild*;

    auto
    get_child_at_pos (int x, int y) -> FlowBoxChild*;

    auto
    get_child_at_pos (int x, int y) const -> const FlowBoxChild*;

    auto
    selected_foreach (const SlotSelectedForeach& slot) -> void;

    auto
    get_selected_children () -> std::vector<gtk::FlowBoxChild*>;

    auto
    get_selected_children () const -> std::vector<const gtk::FlowBoxChild*>;

    auto
    select_child (FlowBoxChild& child) -> void;

    auto
    unselect_child (FlowBoxChild& child) -> void;

    auto
    select_all () -> void;

    auto
    unselect_all () -> void;

    auto
    set_selection_mode (SelectionMode mode = SelectionMode::NONE) -> void;

    auto
    get_selection_mode () const -> SelectionMode;

    auto
    set_hadjustment (const glib::RefPtr<Adjustment>& adjustment) -> void;

    auto
    set_vadjustment (const glib::RefPtr<Adjustment>& adjustment) -> void;

    auto
    set_filter_func (const SlotFilter& slot) -> void;

    auto
    unset_filter_func () -> void;

    auto
    invalidate_filter () -> void;

    auto
    set_sort_func (const SlotSort& slot) -> void;

    auto
    unset_sort_func () -> void;

    auto
    invalidate_sort () -> void;

    template <typename T_item>
    using SlotCreateWidget =
        sigc::slot<gtk::Widget*(const glib::RefPtr<T_item>&)>;

    auto
    bind_model (const glib::RefPtr<gio::ListModel>& model,
                const SlotCreateWidget<glib::Object>& slot_create_widget)
        -> void;

    template <typename T_item, typename T_slot>
    auto
    bind_list_store (const glib::RefPtr<gio::ListStore<T_item>>& store,
                     T_slot&& slot_create_widget) -> void;

    auto
    property_selection_mode () -> glib::PropertyProxy<SelectionMode>;

    auto
    property_selection_mode () const
        -> glib::PropertyProxy_ReadOnly<SelectionMode>;

    auto
    property_activate_on_single_click () -> glib::PropertyProxy<bool>;

    auto
    property_activate_on_single_click () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accept_unpaired_release () -> glib::PropertyProxy<bool>;

    auto
    property_accept_unpaired_release () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_min_children_per_line () -> glib::PropertyProxy<guint>;

    auto
    property_min_children_per_line () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_max_children_per_line () -> glib::PropertyProxy<guint>;

    auto
    property_max_children_per_line () const
        -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_row_spacing () -> glib::PropertyProxy<guint>;

    auto
    property_row_spacing () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_column_spacing () -> glib::PropertyProxy<guint>;

    auto
    property_column_spacing () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    signal_child_activated () -> glib::SignalProxy<void (FlowBoxChild*)>;

    auto
    signal_selected_children_changed () -> glib::SignalProxy<void ()>;

  private:
    template <typename T_item>
    static auto
    proxy_bind_list_store_create_widget_callback (void* item, void* data)
        -> GtkWidget*;

  public:
  public:
  protected:
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <typename T_item, typename T_slot>
  auto
  FlowBox::bind_list_store (const glib::RefPtr<gio::ListStore<T_item>>& store,
                            T_slot&& slot_create_widget) -> void
  {
    auto slot_copy = new SlotCreateWidget<T_item> (
        std::forward<T_slot> (slot_create_widget));

    gtk_flow_box_bind_model (
        gobj (),
        store ? store->gio::ListModel::gobj () : nullptr,
        &proxy_bind_list_store_create_widget_callback<T_item>,
        slot_copy,
        &glib::destroy_notify_delete<SlotCreateWidget<T_item>>);
  }

  template <typename T_item>
  auto
  FlowBox::proxy_bind_list_store_create_widget_callback (void* item, void* data) -> GtkWidget*
  {
    auto& slot = *static_cast<SlotCreateWidget<T_item>*> (data);
    auto cobject = static_cast<typename T_item::BaseObjectType*> (item);

    try
    {
      gtk::Widget* widget =
          slot (std::dynamic_pointer_cast<T_item> (glib::wrap (cobject, true)));
      if (widget)
        return widget->gobj ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return nullptr;
  }

#endif

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFlowBox* object, bool take_copy = false) -> gtk::FlowBox*;
} // namespace glib

#endif
