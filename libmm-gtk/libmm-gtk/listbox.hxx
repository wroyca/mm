// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTBOX_H
#define _GTKMM_LISTBOX_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/liststore.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/listboxrow.hxx>
#include <libmm-gtk/widget.hxx>
#include <utility>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBox = struct _GtkListBox;
using GtkListBoxClass = struct _GtkListBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ListBox_Class;
}
#endif

namespace Gtk
{
  class Adjustment;

  class GTKMM_API ListBox : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ListBox CppObjectType;
    typedef ListBox_Class CppClassType;
    typedef GtkListBox BaseObjectType;
    typedef GtkListBoxClass BaseClassType;
#endif

    ListBox (ListBox&& src) noexcept;
    auto
    operator= (ListBox&& src) noexcept -> ListBox&;

    ListBox (const ListBox&) = delete;
    auto
    operator= (const ListBox&) -> ListBox& = delete;

    ~ListBox () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ListBox_Class;
    static CppClassType listbox_class_;

  protected:
    explicit ListBox (const Glib::ConstructParams& construct_params);
    explicit ListBox (GtkListBox* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListBox*
    {
      return reinterpret_cast<GtkListBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkListBox*
    {
      return reinterpret_cast<GtkListBox*> (gobject_);
    }

  private:
  public:
    ListBox ();

    typedef sigc::slot<bool (ListBoxRow*)> SlotFilter;

    typedef sigc::slot<int (ListBoxRow*, ListBoxRow*)> SlotSort;

    typedef sigc::slot<void (ListBoxRow*, ListBoxRow*)> SlotUpdateHeader;

    auto
    prepend (Widget& child) -> void;

    auto
    append (Widget& child) -> void;

    auto
    insert (Widget& child, int position) -> void;

    auto
    remove (Widget& child) -> void;

    auto
    get_selected_row () -> ListBoxRow*;

    auto
    get_selected_row () const -> const ListBoxRow*;

    auto
    get_row_at_index (int index) -> ListBoxRow*;

    auto
    get_row_at_index (int index) const -> const ListBoxRow*;

    auto
    get_row_at_y (int y) -> ListBoxRow*;

    auto
    get_row_at_y (int y) const -> const ListBoxRow*;

    auto
    select_row (ListBoxRow& row) -> void;

    auto
    unselect_row () -> void;

    auto
    set_placeholder (Widget& placeholder) -> void;

    auto
    unset_placeholder () -> void;

    auto
    set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void;

    auto
    get_adjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> Glib::RefPtr<const Adjustment>;

    typedef sigc::slot<void (ListBoxRow*)> SlotForeach;

    auto
    selected_foreach (const SlotForeach& slot) -> void;

    auto
    get_selected_rows () -> std::vector<ListBoxRow*>;

    auto
    get_selected_rows () const -> std::vector<ListBoxRow*>;

    auto
    unselect_row (ListBoxRow* row) -> void;

    auto
    select_all () -> void;

    auto
    unselect_all () -> void;

    auto
    set_selection_mode (SelectionMode mode) -> void;

    auto
    get_selection_mode () const -> SelectionMode;

    auto
    set_filter_func (const SlotFilter& slot) -> void;

    auto
    unset_filter_func () -> void;

    auto
    set_sort_func (const SlotSort& slot) -> void;

    auto
    unset_sort_func () -> void;

    auto
    set_header_func (const SlotUpdateHeader& slot) -> void;

    auto
    unset_header_func () -> void;

    auto
    invalidate_filter () -> void;

    auto
    invalidate_sort () -> void;

    auto
    invalidate_headers () -> void;

    auto
    set_activate_on_single_click (bool single = true) -> void;

    auto
    get_activate_on_single_click () const -> bool;

    auto
    drag_unhighlight_row () -> void;

    auto
    drag_highlight_row (ListBoxRow& row) -> void;

    template <typename T_item>
    using SlotCreateWidget =
        sigc::slot<Gtk::Widget*(const Glib::RefPtr<T_item>&)>;

    auto
    bind_model (const Glib::RefPtr<Gio::ListModel>& model,
                const SlotCreateWidget<Glib::Object>& slot_create_widget)
        -> void;

    template <typename T_item, typename T_slot>
    auto
    bind_list_store (const Glib::RefPtr<Gio::ListStore<T_item>>& store,
                     T_slot&& slot_create_widget) -> void;

    auto
    set_show_separators (bool show_separators = true) -> void;

    auto
    get_show_separators () const -> bool;

    auto
    property_selection_mode () -> Glib::PropertyProxy<SelectionMode>;

    auto
    property_selection_mode () const
        -> Glib::PropertyProxy_ReadOnly<SelectionMode>;

    auto
    property_activate_on_single_click () -> Glib::PropertyProxy<bool>;

    auto
    property_activate_on_single_click () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accept_unpaired_release () -> Glib::PropertyProxy<bool>;

    auto
    property_accept_unpaired_release () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_separators () -> Glib::PropertyProxy<bool>;

    auto
    property_show_separators () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_row_selected () -> Glib::SignalProxy<void (ListBoxRow*)>;

    auto
    signal_row_activated () -> Glib::SignalProxy<void (ListBoxRow*)>;

    auto
    signal_selected_rows_changed () -> Glib::SignalProxy<void ()>;

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
  ListBox::bind_list_store (const Glib::RefPtr<Gio::ListStore<T_item>>& store,
                            T_slot&& slot_create_widget) -> void
  {
    auto slot_copy = new SlotCreateWidget<T_item> (
        std::forward<T_slot> (slot_create_widget));

    gtk_list_box_bind_model (
        gobj (),
        store ? store->Gio::ListModel::gobj () : nullptr,
        &proxy_bind_list_store_create_widget_callback<T_item>,
        slot_copy,
        &Glib::destroy_notify_delete<SlotCreateWidget<T_item>>);
  }

  template <typename T_item>
  auto
  ListBox::proxy_bind_list_store_create_widget_callback (void* item, void* data) -> GtkWidget*
  {
    auto& slot = *static_cast<SlotCreateWidget<T_item>*> (data);
    auto cobject = static_cast<typename T_item::BaseObjectType*> (item);

    try
    {
      Gtk::Widget* widget =
          slot (std::dynamic_pointer_cast<T_item> (Glib::wrap (cobject, true)));
      if (widget)
        return widget->gobj ();
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return nullptr;
  }

#endif

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkListBox* object, bool take_copy = false) -> Gtk::ListBox*;
} // namespace Glib

#endif
