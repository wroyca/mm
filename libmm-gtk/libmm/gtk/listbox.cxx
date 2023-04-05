// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/listbox.hxx>
#include <libmm/gtk/listbox_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

namespace
{

  auto
  SignalProxy_Filter_gtk_callback (GtkListBoxRow* row, void* data) -> gboolean
  {
    auto the_slot = static_cast<gtk::ListBox::SlotFilter*> (data);

    try
    {
      return (*the_slot) (glib::wrap (row));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
      return FALSE;
    }
  }

  auto
  SignalProxy_Filter_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<gtk::ListBox::SlotFilter*> (data);
  }

  auto
  SignalProxy_Sort_gtk_callback (GtkListBoxRow* row1,
                                 GtkListBoxRow* row2,
                                 void* data) -> int
  {
    auto the_slot = static_cast<gtk::ListBox::SlotSort*> (data);

    try
    {
      return (*the_slot) (glib::wrap (row1), glib::wrap (row2));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
      return 0;
    }
  }

  auto
  SignalProxy_Sort_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<gtk::ListBox::SlotSort*> (data);
  }

  auto
  SignalProxy_UpdateHeader_gtk_callback (GtkListBoxRow* row,
                                         GtkListBoxRow* before,
                                         void* data) -> void
  {
    auto the_slot = static_cast<gtk::ListBox::SlotUpdateHeader*> (data);

    try
    {
      (*the_slot) (glib::wrap (row), glib::wrap (before));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  auto
  SignalProxy_UpdateHeader_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<gtk::ListBox::SlotUpdateHeader*> (data);
  }

  static auto
  proxy_foreach_callback (GtkListBox*, GtkListBoxRow* row, void* data) -> void
  {
    typedef gtk::ListBox::SlotForeach SlotType;
    auto& slot = *static_cast<SlotType*> (data);

    try
    {
      slot (glib::wrap (row, true));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  static auto
  proxy_bind_model_create_widget_callback (void* item, void* data) -> GtkWidget*
  {
    auto& slot =
        *static_cast<gtk::ListBox::SlotCreateWidget<glib::Object>*> (data);
    auto cobject = static_cast<GObject*> (item);

    try
    {
      gtk::Widget* widget = slot (glib::wrap (cobject, true));
      if (widget)
        return widget->gobj ();
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
    return nullptr;
  }

} // namespace

namespace gtk
{

  auto
  ListBox::unselect_row () -> void
  {
    gtk_list_box_select_row (gobj (), nullptr);
  }

  auto
  ListBox::unset_placeholder () -> void
  {
    gtk_list_box_set_placeholder (gobj (), nullptr);
  }

  auto
  ListBox::set_filter_func (const SlotFilter& slot) -> void
  {
    auto slot_copy = new SlotFilter (slot);

    gtk_list_box_set_filter_func (gobj (),
                                  &SignalProxy_Filter_gtk_callback,
                                  slot_copy,
                                  &SignalProxy_Filter_gtk_callback_destroy);
  }

  auto
  ListBox::unset_filter_func () -> void
  {
    gtk_list_box_set_filter_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  ListBox::set_sort_func (const SlotSort& slot) -> void
  {
    auto slot_copy = new SlotSort (slot);

    gtk_list_box_set_sort_func (gobj (),
                                &SignalProxy_Sort_gtk_callback,
                                slot_copy,
                                &SignalProxy_Sort_gtk_callback_destroy);
  }

  auto
  ListBox::unset_sort_func () -> void
  {
    gtk_list_box_set_sort_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  ListBox::set_header_func (const SlotUpdateHeader& slot) -> void
  {
    auto slot_copy = new SlotUpdateHeader (slot);

    gtk_list_box_set_header_func (
        gobj (),
        &SignalProxy_UpdateHeader_gtk_callback,
        slot_copy,
        &SignalProxy_UpdateHeader_gtk_callback_destroy);
  }

  auto
  ListBox::unset_header_func () -> void
  {
    gtk_list_box_set_header_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  ListBox::selected_foreach (const SlotForeach& slot) -> void
  {
    SlotForeach slot_copy (slot);
    gtk_list_box_selected_foreach (gobj (),
                                   &proxy_foreach_callback,
                                   &slot_copy);
  }

  auto
  ListBox::bind_model (const glib::RefPtr<gio::ListModel>& model,
                       const SlotCreateWidget<glib::Object>& slot_create_widget) -> void
  {
    auto slot_copy = new SlotCreateWidget<glib::Object> (slot_create_widget);

    gtk_list_box_bind_model (
        gobj (),
        glib::unwrap (model),
        &proxy_bind_model_create_widget_callback,
        slot_copy,
        &glib::destroy_notify_delete<SlotCreateWidget<glib::Object>>);
  }

} // namespace gtk

namespace
{

  static auto
  ListBox_signal_row_selected_callback (GtkListBox* self,
                                        GtkListBoxRow* p0,
                                        void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (ListBoxRow*)>;

    auto obj = dynamic_cast<ListBox*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo ListBox_signal_row_selected_info = {
      "row-selected",
      (GCallback) &ListBox_signal_row_selected_callback,
      (GCallback) &ListBox_signal_row_selected_callback};

  static auto
  ListBox_signal_row_activated_callback (GtkListBox* self,
                                         GtkListBoxRow* p0,
                                         void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (ListBoxRow*)>;

    auto obj = dynamic_cast<ListBox*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo ListBox_signal_row_activated_info = {
      "row-activated",
      (GCallback) &ListBox_signal_row_activated_callback,
      (GCallback) &ListBox_signal_row_activated_callback};

  static const glib::SignalProxyInfo ListBox_signal_selected_rows_changed_info =
      {"selected-rows-changed",
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkListBox* object, bool take_copy) -> gtk::ListBox*
  {
    return dynamic_cast<gtk::ListBox*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ListBox_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListBox_Class::class_init_function;

      register_derived_type (gtk_list_box_get_type ());
    }

    return *this;
  }

  auto
  ListBox_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListBox_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ListBox ((GtkListBox*) (o)));
  }

  ListBox::ListBox (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ListBox::ListBox (GtkListBox* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ListBox::ListBox (ListBox&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ListBox::operator= (ListBox&& src) noexcept -> ListBox&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ListBox::~ListBox () noexcept
  {
    destroy_ ();
  }

  ListBox::CppClassType ListBox::listbox_class_;

  auto
  ListBox::get_type () -> GType
  {
    return listbox_class_.init ().get_type ();
  }

  auto
  ListBox::get_base_type () -> GType
  {
    return gtk_list_box_get_type ();
  }

  ListBox::ListBox ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (listbox_class_.init ()))
  {
  }

  auto
  ListBox::prepend (Widget& child) -> void
  {
    gtk_list_box_prepend (gobj (), (child).gobj ());
  }

  auto
  ListBox::append (Widget& child) -> void
  {
    gtk_list_box_append (gobj (), (child).gobj ());
  }

  auto
  ListBox::insert (Widget& child, int position) -> void
  {
    gtk_list_box_insert (gobj (), (child).gobj (), position);
  }

  auto
  ListBox::remove (Widget& child) -> void
  {
    gtk_list_box_remove (gobj (), (child).gobj ());
  }

  auto
  ListBox::get_selected_row () -> ListBoxRow*
  {
    return glib::wrap (gtk_list_box_get_selected_row (gobj ()));
  }

  auto
  ListBox::get_selected_row () const -> const ListBoxRow*
  {
    return const_cast<ListBox*> (this)->get_selected_row ();
  }

  auto
  ListBox::get_row_at_index (int index) -> ListBoxRow*
  {
    return glib::wrap (gtk_list_box_get_row_at_index (gobj (), index));
  }

  auto
  ListBox::get_row_at_index (int index) const -> const ListBoxRow*
  {
    return const_cast<ListBox*> (this)->get_row_at_index (index);
  }

  auto
  ListBox::get_row_at_y (int y) -> ListBoxRow*
  {
    return glib::wrap (gtk_list_box_get_row_at_y (gobj (), y));
  }

  auto
  ListBox::get_row_at_y (int y) const -> const ListBoxRow*
  {
    return const_cast<ListBox*> (this)->get_row_at_y (y);
  }

  auto
  ListBox::select_row (ListBoxRow& row) -> void
  {
    gtk_list_box_select_row (gobj (), (row).gobj ());
  }

  auto
  ListBox::set_placeholder (Widget& placeholder) -> void
  {
    gtk_list_box_set_placeholder (gobj (), (placeholder).gobj ());
  }

  auto
  ListBox::set_adjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_list_box_set_adjustment (gobj (), glib::unwrap (adjustment));
  }

  auto
  ListBox::get_adjustment () -> glib::RefPtr<Adjustment>
  {
    auto retvalue = glib::wrap (gtk_list_box_get_adjustment (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ListBox::get_adjustment () const -> glib::RefPtr<const Adjustment>
  {
    return const_cast<ListBox*> (this)->get_adjustment ();
  }

  auto
  ListBox::get_selected_rows () -> std::vector<ListBoxRow*>
  {
    return glib::ListHandler<ListBoxRow*>::list_to_vector (
        gtk_list_box_get_selected_rows (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  ListBox::get_selected_rows () const -> std::vector<ListBoxRow*>
  {
    return glib::ListHandler<ListBoxRow*>::list_to_vector (
        gtk_list_box_get_selected_rows (const_cast<GtkListBox*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  ListBox::unselect_row (ListBoxRow* row) -> void
  {
    gtk_list_box_unselect_row (gobj (), (GtkListBoxRow*) glib::unwrap (row));
  }

  auto
  ListBox::select_all () -> void
  {
    gtk_list_box_select_all (gobj ());
  }

  auto
  ListBox::unselect_all () -> void
  {
    gtk_list_box_unselect_all (gobj ());
  }

  auto
  ListBox::set_selection_mode (SelectionMode mode) -> void
  {
    gtk_list_box_set_selection_mode (gobj (),
                                     static_cast<GtkSelectionMode> (mode));
  }

  auto
  ListBox::get_selection_mode () const -> SelectionMode
  {
    return static_cast<SelectionMode> (
        gtk_list_box_get_selection_mode (const_cast<GtkListBox*> (gobj ())));
  }

  auto
  ListBox::invalidate_filter () -> void
  {
    gtk_list_box_invalidate_filter (gobj ());
  }

  auto
  ListBox::invalidate_sort () -> void
  {
    gtk_list_box_invalidate_sort (gobj ());
  }

  auto
  ListBox::invalidate_headers () -> void
  {
    gtk_list_box_invalidate_headers (gobj ());
  }

  auto
  ListBox::set_activate_on_single_click (bool single) -> void
  {
    gtk_list_box_set_activate_on_single_click (gobj (),
                                               static_cast<int> (single));
  }

  auto
  ListBox::get_activate_on_single_click () const -> bool
  {
    return gtk_list_box_get_activate_on_single_click (
        const_cast<GtkListBox*> (gobj ()));
  }

  auto
  ListBox::drag_unhighlight_row () -> void
  {
    gtk_list_box_drag_unhighlight_row (gobj ());
  }

  auto
  ListBox::drag_highlight_row (ListBoxRow& row) -> void
  {
    gtk_list_box_drag_highlight_row (gobj (), (row).gobj ());
  }

  auto
  ListBox::set_show_separators (bool show_separators) -> void
  {
    gtk_list_box_set_show_separators (gobj (),
                                      static_cast<int> (show_separators));
  }

  auto
  ListBox::get_show_separators () const -> bool
  {
    return gtk_list_box_get_show_separators (const_cast<GtkListBox*> (gobj ()));
  }

  auto
  ListBox::signal_row_selected () -> glib::SignalProxy<void (ListBoxRow*)>
  {
    return glib::SignalProxy<void (ListBoxRow*)> (
        this,
        &ListBox_signal_row_selected_info);
  }

  auto
  ListBox::signal_row_activated () -> glib::SignalProxy<void (ListBoxRow*)>
  {
    return glib::SignalProxy<void (ListBoxRow*)> (
        this,
        &ListBox_signal_row_activated_info);
  }

  auto
  ListBox::signal_selected_rows_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &ListBox_signal_selected_rows_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
      "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ListBox::property_selection_mode () -> glib::PropertyProxy<SelectionMode>
  {
    return glib::PropertyProxy<SelectionMode> (this, "selection-mode");
  }

  auto
  ListBox::property_selection_mode () const -> glib::PropertyProxy_ReadOnly<SelectionMode>
  {
    return glib::PropertyProxy_ReadOnly<SelectionMode> (this, "selection-mode");
  }

  auto
  ListBox::property_activate_on_single_click () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activate-on-single-click");
  }

  auto
  ListBox::property_activate_on_single_click () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "activate-on-single-click");
  }

  auto
  ListBox::property_accept_unpaired_release () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "accept-unpaired-release");
  }

  auto
  ListBox::property_accept_unpaired_release () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accept-unpaired-release");
  }

  auto
  ListBox::property_show_separators () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-separators");
  }

  auto
  ListBox::property_show_separators () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-separators");
  }

} // namespace gtk
