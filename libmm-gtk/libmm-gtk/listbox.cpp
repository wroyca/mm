


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/listbox.hpp>
#include <mm/gtk/private/listbox_p.hpp>


/* Copyright (C) 2013 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <mm/gtk/adjustment.hpp>

namespace
{

auto SignalProxy_Filter_gtk_callback(GtkListBoxRow* row, void* data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::ListBox::SlotFilter*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(row));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return FALSE;
  }
}

auto SignalProxy_Filter_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::ListBox::SlotFilter*>(data);
}

auto SignalProxy_Sort_gtk_callback(GtkListBoxRow* row1, GtkListBoxRow* row2, void* data) -> int
{
  const auto the_slot = static_cast<Gtk::ListBox::SlotSort*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(row1), Glib::wrap(row2));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return 0;
  }
}

auto SignalProxy_Sort_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::ListBox::SlotSort*>(data);
}

auto SignalProxy_UpdateHeader_gtk_callback (
  GtkListBoxRow *row, GtkListBoxRow *before, void *data) -> void
{
  const auto the_slot = static_cast<Gtk::ListBox::SlotUpdateHeader*>(data);

  try
  {
    (*the_slot)(Glib::wrap(row), Glib::wrap(before));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto SignalProxy_UpdateHeader_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::ListBox::SlotUpdateHeader*>(data);
}


auto proxy_foreach_callback (GtkListBox * /* list_box */, GtkListBoxRow *row, void *data) -> void
{
  typedef Gtk::ListBox::SlotForeach SlotType;
  const auto& slot = *static_cast<SlotType*>(data);

  try
  {
    slot(Glib::wrap(row, true));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto proxy_bind_model_create_widget_callback(void* item, void* data) -> GtkWidget*
{
  const auto& slot = *static_cast<Gtk::ListBox::SlotCreateWidget<Glib::Object>*>(data);
  const auto cobject = static_cast<GObject*>(item);

  try
  {
    // take_copy is true here, because wrap() returns a Glib::RefPtr<Glib::Object>.
    // cobject will be unreferenced when the RefPtr is deleted.
    Gtk::Widget* widget = slot(Glib::wrap(cobject, true));
    if (widget)
      return widget->gobj();
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  return nullptr;
}

} // anonymous namespace

namespace Gtk
{

auto ListBox::unselect_row () -> void
{
  gtk_list_box_select_row(gobj(), nullptr);
}

auto ListBox::unset_placeholder () -> void
{
  gtk_list_box_set_placeholder(gobj(), nullptr);
}

auto ListBox::set_filter_func (const SlotFilter &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when SignalProxy_Filter_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotFilter(slot);

  gtk_list_box_set_filter_func(gobj(),
    &SignalProxy_Filter_gtk_callback, slot_copy,
    &SignalProxy_Filter_gtk_callback_destroy);
}

auto ListBox::unset_filter_func () -> void
{
  gtk_list_box_set_filter_func(gobj(), nullptr, nullptr, nullptr);
}

auto ListBox::set_sort_func (const SlotSort &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when SignalProxy_Sort_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotSort(slot);

  gtk_list_box_set_sort_func(gobj(),
    &SignalProxy_Sort_gtk_callback, slot_copy,
    &SignalProxy_Sort_gtk_callback_destroy);
}

auto ListBox::unset_sort_func () -> void
{
  gtk_list_box_set_sort_func(gobj(), nullptr, nullptr, nullptr);
}

auto ListBox::set_header_func (const SlotUpdateHeader &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when SignalProxy_Sort_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotUpdateHeader(slot);

  gtk_list_box_set_header_func(gobj(),
    &SignalProxy_UpdateHeader_gtk_callback, slot_copy,
    &SignalProxy_UpdateHeader_gtk_callback_destroy);
}

auto ListBox::unset_header_func () -> void
{
  gtk_list_box_set_header_func(gobj(), nullptr, nullptr, nullptr);
}

auto ListBox::selected_foreach (const SlotForeach &slot) -> void
{
  SlotForeach slot_copy(slot); //TODO: Is this necessary?
  gtk_list_box_selected_foreach(gobj(), &proxy_foreach_callback, &slot_copy);
}

auto ListBox::bind_model (
  const Glib::RefPtr <Gio::ListModel> &model,
  const SlotCreateWidget <Glib::Object> &slot_create_widget) -> void
{
  // Create a copy of the slot.
  // It will be deleted by Glib::destroy_notify_delete<SlotCreateWidget>.
  const auto slot_copy = new SlotCreateWidget<Glib::Object>(slot_create_widget);

  gtk_list_box_bind_model(gobj(), Glib::unwrap(model), &proxy_bind_model_create_widget_callback,
    slot_copy, &Glib::destroy_notify_delete<SlotCreateWidget<Glib::Object>>);
}

} //namespace Gtk

namespace
{


auto ListBox_signal_row_selected_callback (GtkListBox *self, GtkListBoxRow *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(ListBoxRow*)>;

  const auto obj = dynamic_cast<ListBox*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ListBox_signal_row_selected_info =
{
  "row-selected",
  (GCallback) &ListBox_signal_row_selected_callback,
  (GCallback) &ListBox_signal_row_selected_callback
};


auto ListBox_signal_row_activated_callback (GtkListBox *self, GtkListBoxRow *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(ListBoxRow*)>;

  const auto obj = dynamic_cast<ListBox*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo ListBox_signal_row_activated_info =
{
  "row-activated",
  (GCallback) &ListBox_signal_row_activated_callback,
  (GCallback) &ListBox_signal_row_activated_callback
};


const Glib::SignalProxyInfo ListBox_signal_selected_rows_changed_info =
{
  "selected-rows-changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkListBox* object, const bool take_copy) -> Gtk::ListBox*
{
  return dynamic_cast<Gtk::ListBox *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ListBox_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ListBox_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListBox_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ListBox((GtkListBox*)o));

}


/* The implementation: */

ListBox::ListBox(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ListBox::ListBox(GtkListBox* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ListBox::ListBox(ListBox&& src) noexcept
: Widget(std::move(src))
{}

auto ListBox::operator=(ListBox&& src) noexcept -> ListBox&
{
  Widget::operator=(std::move(src));
  return *this;
}

ListBox::~ListBox() noexcept
{
  destroy_();
}

ListBox::CppClassType ListBox::listbox_class_; // initialize static member

auto ListBox::get_type() -> GType
{
  return listbox_class_.init().get_type();
}


auto ListBox::get_base_type() -> GType
{
  return gtk_list_box_get_type();
}


ListBox::ListBox()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(listbox_class_.init()))
{


}

auto ListBox::prepend (Widget &child) -> void
{
  gtk_list_box_prepend(gobj(), child.gobj());
}

auto ListBox::append (Widget &child) -> void
{
  gtk_list_box_append(gobj(), child.gobj());
}

auto ListBox::insert (Widget &child, const int position) -> void
{
  gtk_list_box_insert(gobj(), child.gobj(), position);
}

auto ListBox::remove (Widget &child) -> void
{
  gtk_list_box_remove(gobj(), child.gobj());
}

auto ListBox::get_selected_row() -> ListBoxRow*
{
  return Glib::wrap(gtk_list_box_get_selected_row(gobj()));
}

auto ListBox::get_selected_row() const -> const ListBoxRow*
{
  return const_cast<ListBox*>(this)->get_selected_row();
}

auto ListBox::get_row_at_index(
  const int index) -> ListBoxRow*
{
  return Glib::wrap(gtk_list_box_get_row_at_index(gobj(), index));
}

auto ListBox::get_row_at_index(
  const int index) const -> const ListBoxRow*
{
  return const_cast<ListBox*>(this)->get_row_at_index(index);
}

auto ListBox::get_row_at_y(
  const int y) -> ListBoxRow*
{
  return Glib::wrap(gtk_list_box_get_row_at_y(gobj(), y));
}

auto ListBox::get_row_at_y(
  const int y) const -> const ListBoxRow*
{
  return const_cast<ListBox*>(this)->get_row_at_y(y);
}

auto ListBox::select_row (ListBoxRow &row) -> void
{
  gtk_list_box_select_row(gobj(), row.gobj());
}

auto ListBox::set_placeholder (Widget &placeholder) -> void
{
  gtk_list_box_set_placeholder(gobj(), placeholder.gobj());
}

auto ListBox::set_adjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_list_box_set_adjustment(gobj(), Glib::unwrap(adjustment));
}

auto ListBox::get_adjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_list_box_get_adjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ListBox::get_adjustment() const -> Glib::RefPtr<const Adjustment>
{
  return const_cast<ListBox*>(this)->get_adjustment();
}

auto ListBox::get_selected_rows() -> std::vector<ListBoxRow*>
{
  return Glib::ListHandler<ListBoxRow*>::list_to_vector(gtk_list_box_get_selected_rows(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto ListBox::get_selected_rows() const -> std::vector<ListBoxRow*>
{
  return Glib::ListHandler<ListBoxRow*>::list_to_vector(gtk_list_box_get_selected_rows(const_cast<GtkListBox*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto ListBox::unselect_row (ListBoxRow *row) -> void
{
  gtk_list_box_unselect_row(gobj(), Glib::unwrap(row));
}

auto ListBox::select_all () -> void
{
  gtk_list_box_select_all(gobj());
}

auto ListBox::unselect_all () -> void
{
  gtk_list_box_unselect_all(gobj());
}

auto ListBox::set_selection_mode (SelectionMode mode) -> void
{
  gtk_list_box_set_selection_mode(gobj(), static_cast<GtkSelectionMode>(mode));
}

auto ListBox::get_selection_mode() const -> SelectionMode
{
  return static_cast<SelectionMode>(gtk_list_box_get_selection_mode(const_cast<GtkListBox*>(gobj())));
}

auto ListBox::invalidate_filter () -> void
{
  gtk_list_box_invalidate_filter(gobj());
}

auto ListBox::invalidate_sort () -> void
{
  gtk_list_box_invalidate_sort(gobj());
}

auto ListBox::invalidate_headers () -> void
{
  gtk_list_box_invalidate_headers(gobj());
}

auto ListBox::set_activate_on_single_click (
  const bool single) -> void
{
  gtk_list_box_set_activate_on_single_click(gobj(), single);
}

auto ListBox::get_activate_on_single_click() const -> bool
{
  return gtk_list_box_get_activate_on_single_click(const_cast<GtkListBox*>(gobj()));
}

auto ListBox::drag_unhighlight_row () -> void
{
  gtk_list_box_drag_unhighlight_row(gobj());
}

auto ListBox::drag_highlight_row (ListBoxRow &row) -> void
{
  gtk_list_box_drag_highlight_row(gobj(), row.gobj());
}

auto ListBox::set_show_separators (
  const bool show_separators) -> void
{
  gtk_list_box_set_show_separators(gobj(), show_separators);
}

auto ListBox::get_show_separators() const -> bool
{
  return gtk_list_box_get_show_separators(const_cast<GtkListBox*>(gobj()));
}


auto ListBox::signal_row_selected() -> Glib::SignalProxy<void(ListBoxRow*)>
{
  return {this, &ListBox_signal_row_selected_info};
}


auto ListBox::signal_row_activated() -> Glib::SignalProxy<void(ListBoxRow*)>
{
  return {this, &ListBox_signal_row_activated_info};
}


auto ListBox::signal_selected_rows_changed() -> Glib::SignalProxy<void()>
{
  return {this, &ListBox_signal_selected_rows_changed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
  "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ListBox::property_selection_mode() -> Glib::PropertyProxy< SelectionMode >
{
  return {this, "selection-mode"};
}

auto ListBox::property_selection_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >
{
  return {this, "selection-mode"};
}

auto ListBox::property_activate_on_single_click() -> Glib::PropertyProxy< bool >
{
  return {this, "activate-on-single-click"};
}

auto ListBox::property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activate-on-single-click"};
}

auto ListBox::property_accept_unpaired_release() -> Glib::PropertyProxy< bool >
{
  return {this, "accept-unpaired-release"};
}

auto ListBox::property_accept_unpaired_release() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "accept-unpaired-release"};
}

auto ListBox::property_show_separators() -> Glib::PropertyProxy< bool >
{
  return {this, "show-separators"};
}

auto ListBox::property_show_separators() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-separators"};
}


} // namespace Gtk


