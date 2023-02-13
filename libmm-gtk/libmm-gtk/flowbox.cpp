


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/flowbox.hpp>
#include <libmm-gtk/flowbox_p.hpp>


/* Copyright (C) 2014 The gtkmm Development Team
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
#include <libmm-gtk/adjustment.hpp>

namespace
{

auto FuncProxy_Foreach_gtk_callback (GtkFlowBox *box, GtkFlowBoxChild *child, void *data) -> void
{
  const auto the_slot = static_cast<Gtk::FlowBox::SlotSelectedForeach*>(data);

  try
  {
    (*the_slot)(Glib::wrap(box), Glib::wrap(child));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
}

auto SignalProxy_Filter_gtk_callback(GtkFlowBoxChild* child, void* data) -> gboolean
{
  const auto the_slot = static_cast<Gtk::FlowBox::SlotFilter*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(child));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return FALSE;
  }
}

auto SignalProxy_Filter_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::FlowBox::SlotFilter*>(data);
}

auto SignalProxy_Sort_gtk_callback(GtkFlowBoxChild* child1, GtkFlowBoxChild* child2, void* data) -> int
{
  const auto the_slot = static_cast<Gtk::FlowBox::SlotSort*>(data);

  try
  {
    return (*the_slot)(Glib::wrap(child1), Glib::wrap(child2));
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
    return 0;
  }
}

auto SignalProxy_Sort_gtk_callback_destroy (void *data) -> void
{
  delete static_cast<Gtk::FlowBox::SlotSort*>(data);
}

auto proxy_bind_model_create_widget_callback(void* item, void* data) -> GtkWidget*
{
  const auto& slot = *static_cast<Gtk::FlowBox::SlotCreateWidget<Glib::Object>*>(data);
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

auto FlowBox::selected_foreach (const SlotSelectedForeach &slot) -> void
{
  SlotSelectedForeach slot_local_copy(slot);

  gtk_flow_box_selected_foreach(gobj(),
    &FuncProxy_Foreach_gtk_callback, &slot_local_copy);
}

auto FlowBox::set_filter_func (const SlotFilter &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when SignalProxy_Filter_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotFilter(slot);

  gtk_flow_box_set_filter_func(gobj(),
    &SignalProxy_Filter_gtk_callback, slot_copy,
    &SignalProxy_Filter_gtk_callback_destroy);
}

auto FlowBox::unset_filter_func () -> void
{
  gtk_flow_box_set_filter_func(gobj(), nullptr, nullptr, nullptr);
}

auto FlowBox::set_sort_func (const SlotSort &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when SignalProxy_Sort_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotSort(slot);

  gtk_flow_box_set_sort_func(gobj(),
    &SignalProxy_Sort_gtk_callback, slot_copy,
    &SignalProxy_Sort_gtk_callback_destroy);
}

auto FlowBox::unset_sort_func () -> void
{
  gtk_flow_box_set_sort_func(gobj(), nullptr, nullptr, nullptr);
}

auto FlowBox::bind_model (
  const Glib::RefPtr <Gio::ListModel> &model,
  const SlotCreateWidget <Glib::Object> &slot_create_widget) -> void
{
  // Create a copy of the slot.
  // It will be deleted by Glib::destroy_notify_delete<SlotCreateWidget>.
  const auto slot_copy = new SlotCreateWidget<Glib::Object>(slot_create_widget);

  gtk_flow_box_bind_model(gobj(), Glib::unwrap(model), &proxy_bind_model_create_widget_callback,
    slot_copy, &Glib::destroy_notify_delete<SlotCreateWidget<Glib::Object>>);
}

} //namespace Gtk


namespace
{


auto FlowBox_signal_child_activated_callback (
  GtkFlowBox *self, GtkFlowBoxChild *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(FlowBoxChild*)>;

  const auto obj = dynamic_cast<FlowBox*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo FlowBox_signal_child_activated_info =
{
  "child-activated",
  (GCallback) &FlowBox_signal_child_activated_callback,
  (GCallback) &FlowBox_signal_child_activated_callback
};


const Glib::SignalProxyInfo FlowBox_signal_selected_children_changed_info =
{
  "selected-children-changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkFlowBox* object, const bool take_copy) -> Gtk::FlowBox*
{
  return dynamic_cast<Gtk::FlowBox *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto FlowBox_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FlowBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_flow_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto FlowBox_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FlowBox_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new FlowBox((GtkFlowBox*)o));

}


/* The implementation: */

FlowBox::FlowBox(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

FlowBox::FlowBox(GtkFlowBox* castitem)
: Widget((GtkWidget*)castitem)
{
  }


FlowBox::FlowBox(FlowBox&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto FlowBox::operator=(FlowBox&& src) noexcept -> FlowBox&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

FlowBox::~FlowBox() noexcept
{
  destroy_();
}

FlowBox::CppClassType FlowBox::flowbox_class_; // initialize static member

auto FlowBox::get_type() -> GType
{
  return flowbox_class_.init().get_type();
}


auto FlowBox::get_base_type() -> GType
{
  return gtk_flow_box_get_type();
}


FlowBox::FlowBox()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(flowbox_class_.init()))
{


}

auto FlowBox::set_homogeneous (
  const bool homogeneous) -> void
{
  gtk_flow_box_set_homogeneous(gobj(), homogeneous);
}

auto FlowBox::get_homogeneous() const -> bool
{
  return gtk_flow_box_get_homogeneous(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::set_row_spacing (
  const guint spacing) -> void
{
  gtk_flow_box_set_row_spacing(gobj(), spacing);
}

auto FlowBox::get_row_spacing() const -> guint
{
  return gtk_flow_box_get_row_spacing(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::set_column_spacing (
  const guint spacing) -> void
{
  gtk_flow_box_set_column_spacing(gobj(), spacing);
}

auto FlowBox::get_column_spacing() const -> guint
{
  return gtk_flow_box_get_column_spacing(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::set_min_children_per_line (
  const guint n_children) -> void
{
  gtk_flow_box_set_min_children_per_line(gobj(), n_children);
}

auto FlowBox::get_min_children_per_line() const -> guint
{
  return gtk_flow_box_get_min_children_per_line(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::set_max_children_per_line (
  const guint n_children) -> void
{
  gtk_flow_box_set_max_children_per_line(gobj(), n_children);
}

auto FlowBox::get_max_children_per_line() const -> guint
{
  return gtk_flow_box_get_max_children_per_line(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::set_activate_on_single_click (
  const bool single) -> void
{
  gtk_flow_box_set_activate_on_single_click(gobj(), single);
}

auto FlowBox::get_activate_on_single_click() const -> bool
{
  return gtk_flow_box_get_activate_on_single_click(const_cast<GtkFlowBox*>(gobj()));
}

auto FlowBox::prepend (Widget &child) -> void
{
  gtk_flow_box_prepend(gobj(), child.gobj());
}

auto FlowBox::append (Widget &child) -> void
{
  gtk_flow_box_append(gobj(), child.gobj());
}

auto FlowBox::insert (Widget &widget, const int position) -> void
{
  gtk_flow_box_insert(gobj(), widget.gobj(), position);
}

auto FlowBox::remove (Widget &widget) -> void
{
  gtk_flow_box_remove(gobj(), widget.gobj());
}

auto FlowBox::get_child_at_index(
  const int idx) -> FlowBoxChild*
{
  return Glib::wrap(gtk_flow_box_get_child_at_index(gobj(), idx));
}

auto FlowBox::get_child_at_index(
  const int idx) const -> const FlowBoxChild*
{
  return const_cast<FlowBox*>(this)->get_child_at_index(idx);
}

auto FlowBox::get_child_at_pos(
  const int x, const int y) -> FlowBoxChild*
{
  return Glib::wrap(gtk_flow_box_get_child_at_pos(gobj(), x, y));
}

auto FlowBox::get_child_at_pos(
  const int x, const int y) const -> const FlowBoxChild*
{
  return const_cast<FlowBox*>(this)->get_child_at_pos(x, y);
}

auto FlowBox::get_selected_children() -> std::vector<FlowBoxChild *>
{
  return Glib::ListHandler<FlowBoxChild * >::list_to_vector(gtk_flow_box_get_selected_children(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto FlowBox::get_selected_children() const -> std::vector< const FlowBoxChild *>
{
  return Glib::ListHandler< const FlowBoxChild * >::list_to_vector(gtk_flow_box_get_selected_children(const_cast<GtkFlowBox*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

auto FlowBox::select_child (FlowBoxChild &child) -> void
{
  gtk_flow_box_select_child(gobj(), child.gobj());
}

auto FlowBox::unselect_child (FlowBoxChild &child) -> void
{
  gtk_flow_box_unselect_child(gobj(), child.gobj());
}

auto FlowBox::select_all () -> void
{
  gtk_flow_box_select_all(gobj());
}

auto FlowBox::unselect_all () -> void
{
  gtk_flow_box_unselect_all(gobj());
}

auto FlowBox::set_selection_mode (SelectionMode mode) -> void
{
  gtk_flow_box_set_selection_mode(gobj(), static_cast<GtkSelectionMode>(mode));
}

auto FlowBox::get_selection_mode() const -> SelectionMode
{
  return static_cast<SelectionMode>(gtk_flow_box_get_selection_mode(const_cast<GtkFlowBox*>(gobj())));
}

auto FlowBox::set_hadjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_flow_box_set_hadjustment(gobj(), Glib::unwrap(adjustment));
}

auto FlowBox::set_vadjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_flow_box_set_vadjustment(gobj(), Glib::unwrap(adjustment));
}

auto FlowBox::invalidate_filter () -> void
{
  gtk_flow_box_invalidate_filter(gobj());
}

auto FlowBox::invalidate_sort () -> void
{
  gtk_flow_box_invalidate_sort(gobj());
}


auto FlowBox::signal_child_activated() -> Glib::SignalProxy<void(FlowBoxChild*)>
{
  return {this, &FlowBox_signal_child_activated_info};
}


auto FlowBox::signal_selected_children_changed() -> Glib::SignalProxy<void()>
{
  return {this, &FlowBox_signal_selected_children_changed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
  "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FlowBox::property_selection_mode() -> Glib::PropertyProxy< SelectionMode >
{
  return {this, "selection-mode"};
}

auto FlowBox::property_selection_mode() const -> Glib::PropertyProxy_ReadOnly< SelectionMode >
{
  return {this, "selection-mode"};
}

auto FlowBox::property_activate_on_single_click() -> Glib::PropertyProxy< bool >
{
  return {this, "activate-on-single-click"};
}

auto FlowBox::property_activate_on_single_click() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activate-on-single-click"};
}

auto FlowBox::property_accept_unpaired_release() -> Glib::PropertyProxy< bool >
{
  return {this, "accept-unpaired-release"};
}

auto FlowBox::property_accept_unpaired_release() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "accept-unpaired-release"};
}

auto FlowBox::property_homogeneous() -> Glib::PropertyProxy< bool >
{
  return {this, "homogeneous"};
}

auto FlowBox::property_homogeneous() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "homogeneous"};
}

auto FlowBox::property_min_children_per_line() -> Glib::PropertyProxy< guint >
{
  return {this, "min-children-per-line"};
}

auto FlowBox::property_min_children_per_line() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "min-children-per-line"};
}

auto FlowBox::property_max_children_per_line() -> Glib::PropertyProxy< guint >
{
  return {this, "max-children-per-line"};
}

auto FlowBox::property_max_children_per_line() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "max-children-per-line"};
}

auto FlowBox::property_row_spacing() -> Glib::PropertyProxy< guint >
{
  return {this, "row-spacing"};
}

auto FlowBox::property_row_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "row-spacing"};
}

auto FlowBox::property_column_spacing() -> Glib::PropertyProxy< guint >
{
  return {this, "column-spacing"};
}

auto FlowBox::property_column_spacing() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "column-spacing"};
}


} // namespace Gtk


