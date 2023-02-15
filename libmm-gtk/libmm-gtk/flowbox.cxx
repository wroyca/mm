// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/flowbox.hxx>
#include <libmm-gtk/flowbox_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/adjustment.hxx>

namespace
{

  static auto
  FuncProxy_Foreach_gtk_callback (GtkFlowBox* box,
                                  GtkFlowBoxChild* child,
                                  void* data) -> void
  {
    auto the_slot = static_cast<Gtk::FlowBox::SlotSelectedForeach*> (data);

    try
    {
      (*the_slot) (Glib::wrap (box), Glib::wrap (child));
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
  }

  static auto
  SignalProxy_Filter_gtk_callback (GtkFlowBoxChild* child, void* data) -> gboolean
  {
    auto the_slot = static_cast<Gtk::FlowBox::SlotFilter*> (data);

    try
    {
      return (*the_slot) (Glib::wrap (child));
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
      return FALSE;
    }
  }

  static auto
  SignalProxy_Filter_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<Gtk::FlowBox::SlotFilter*> (data);
  }

  static auto
  SignalProxy_Sort_gtk_callback (GtkFlowBoxChild* child1,
                                 GtkFlowBoxChild* child2,
                                 void* data) -> int
  {
    auto the_slot = static_cast<Gtk::FlowBox::SlotSort*> (data);

    try
    {
      return (*the_slot) (Glib::wrap (child1), Glib::wrap (child2));
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
      return 0;
    }
  }

  static auto
  SignalProxy_Sort_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<Gtk::FlowBox::SlotSort*> (data);
  }

  static auto
  proxy_bind_model_create_widget_callback (void* item, void* data) -> GtkWidget*
  {
    auto& slot =
        *static_cast<Gtk::FlowBox::SlotCreateWidget<Glib::Object>*> (data);
    auto cobject = static_cast<GObject*> (item);

    try
    {
      Gtk::Widget* widget = slot (Glib::wrap (cobject, true));
      if (widget)
        return widget->gobj ();
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return nullptr;
  }

} // namespace

namespace Gtk
{

  auto
  FlowBox::selected_foreach (const SlotSelectedForeach& slot) -> void
  {
    SlotSelectedForeach slot_local_copy (slot);

    gtk_flow_box_selected_foreach (gobj (),
                                   &FuncProxy_Foreach_gtk_callback,
                                   &slot_local_copy);
  }

  auto
  FlowBox::set_filter_func (const SlotFilter& slot) -> void
  {
    auto slot_copy = new SlotFilter (slot);

    gtk_flow_box_set_filter_func (gobj (),
                                  &SignalProxy_Filter_gtk_callback,
                                  slot_copy,
                                  &SignalProxy_Filter_gtk_callback_destroy);
  }

  auto
  FlowBox::unset_filter_func () -> void
  {
    gtk_flow_box_set_filter_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  FlowBox::set_sort_func (const SlotSort& slot) -> void
  {
    auto slot_copy = new SlotSort (slot);

    gtk_flow_box_set_sort_func (gobj (),
                                &SignalProxy_Sort_gtk_callback,
                                slot_copy,
                                &SignalProxy_Sort_gtk_callback_destroy);
  }

  auto
  FlowBox::unset_sort_func () -> void
  {
    gtk_flow_box_set_sort_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  FlowBox::bind_model (const Glib::RefPtr<Gio::ListModel>& model,
                       const SlotCreateWidget<Glib::Object>& slot_create_widget) -> void
  {
    auto slot_copy = new SlotCreateWidget<Glib::Object> (slot_create_widget);

    gtk_flow_box_bind_model (
        gobj (),
        Glib::unwrap (model),
        &proxy_bind_model_create_widget_callback,
        slot_copy,
        &Glib::destroy_notify_delete<SlotCreateWidget<Glib::Object>>);
  }

} // namespace Gtk

namespace
{

  static auto
  FlowBox_signal_child_activated_callback (GtkFlowBox* self,
                                           GtkFlowBoxChild* p0,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (FlowBoxChild*)>;

    auto obj = dynamic_cast<FlowBox*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo FlowBox_signal_child_activated_info = {
      "child-activated",
      (GCallback) &FlowBox_signal_child_activated_callback,
      (GCallback) &FlowBox_signal_child_activated_callback};

  static const Glib::SignalProxyInfo
      FlowBox_signal_selected_children_changed_info = {
          "selected-children-changed",
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkFlowBox* object, bool take_copy) -> Gtk::FlowBox*
  {
    return dynamic_cast<Gtk::FlowBox*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FlowBox_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FlowBox_Class::class_init_function;

      register_derived_type (gtk_flow_box_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FlowBox_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FlowBox_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FlowBox ((GtkFlowBox*) (o)));
  }

  FlowBox::FlowBox (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  FlowBox::FlowBox (GtkFlowBox* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FlowBox::FlowBox (FlowBox&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  FlowBox::operator= (FlowBox&& src) noexcept -> FlowBox&
  {
    Gtk::Widget::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  FlowBox::~FlowBox () noexcept
  {
    destroy_ ();
  }

  FlowBox::CppClassType FlowBox::flowbox_class_;

  auto
  FlowBox::get_type () -> GType
  {
    return flowbox_class_.init ().get_type ();
  }

  auto
  FlowBox::get_base_type () -> GType
  {
    return gtk_flow_box_get_type ();
  }

  FlowBox::FlowBox ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (flowbox_class_.init ()))
  {
  }

  auto
  FlowBox::set_homogeneous (bool homogeneous) -> void
  {
    gtk_flow_box_set_homogeneous (gobj (), static_cast<int> (homogeneous));
  }

  auto
  FlowBox::get_homogeneous () const -> bool
  {
    return gtk_flow_box_get_homogeneous (const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::set_row_spacing (guint spacing) -> void
  {
    gtk_flow_box_set_row_spacing (gobj (), spacing);
  }

  auto
  FlowBox::get_row_spacing () const -> guint
  {
    return gtk_flow_box_get_row_spacing (const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::set_column_spacing (guint spacing) -> void
  {
    gtk_flow_box_set_column_spacing (gobj (), spacing);
  }

  auto
  FlowBox::get_column_spacing () const -> guint
  {
    return gtk_flow_box_get_column_spacing (const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::set_min_children_per_line (guint n_children) -> void
  {
    gtk_flow_box_set_min_children_per_line (gobj (), n_children);
  }

  auto
  FlowBox::get_min_children_per_line () const -> guint
  {
    return gtk_flow_box_get_min_children_per_line (
        const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::set_max_children_per_line (guint n_children) -> void
  {
    gtk_flow_box_set_max_children_per_line (gobj (), n_children);
  }

  auto
  FlowBox::get_max_children_per_line () const -> guint
  {
    return gtk_flow_box_get_max_children_per_line (
        const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::set_activate_on_single_click (bool single) -> void
  {
    gtk_flow_box_set_activate_on_single_click (gobj (),
                                               static_cast<int> (single));
  }

  auto
  FlowBox::get_activate_on_single_click () const -> bool
  {
    return gtk_flow_box_get_activate_on_single_click (
        const_cast<GtkFlowBox*> (gobj ()));
  }

  auto
  FlowBox::prepend (Widget& child) -> void
  {
    gtk_flow_box_prepend (gobj (), (child).gobj ());
  }

  auto
  FlowBox::append (Widget& child) -> void
  {
    gtk_flow_box_append (gobj (), (child).gobj ());
  }

  auto
  FlowBox::insert (Widget& widget, int position) -> void
  {
    gtk_flow_box_insert (gobj (), (widget).gobj (), position);
  }

  auto
  FlowBox::remove (Widget& widget) -> void
  {
    gtk_flow_box_remove (gobj (), (widget).gobj ());
  }

  auto
  FlowBox::get_child_at_index (int idx) -> FlowBoxChild*
  {
    return Glib::wrap (gtk_flow_box_get_child_at_index (gobj (), idx));
  }

  auto
  FlowBox::get_child_at_index (int idx) const -> const FlowBoxChild*
  {
    return const_cast<FlowBox*> (this)->get_child_at_index (idx);
  }

  auto
  FlowBox::get_child_at_pos (int x, int y) -> FlowBoxChild*
  {
    return Glib::wrap (gtk_flow_box_get_child_at_pos (gobj (), x, y));
  }

  auto
  FlowBox::get_child_at_pos (int x, int y) const -> const FlowBoxChild*
  {
    return const_cast<FlowBox*> (this)->get_child_at_pos (x, y);
  }

  auto
  FlowBox::get_selected_children () -> std::vector<Gtk::FlowBoxChild*>
  {
    return Glib::ListHandler<Gtk::FlowBoxChild*>::list_to_vector (
        gtk_flow_box_get_selected_children (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  FlowBox::get_selected_children () const -> std::vector<const Gtk::FlowBoxChild*>
  {
    return Glib::ListHandler<const Gtk::FlowBoxChild*>::list_to_vector (
        gtk_flow_box_get_selected_children (const_cast<GtkFlowBox*> (gobj ())),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  FlowBox::select_child (FlowBoxChild& child) -> void
  {
    gtk_flow_box_select_child (gobj (), (child).gobj ());
  }

  auto
  FlowBox::unselect_child (FlowBoxChild& child) -> void
  {
    gtk_flow_box_unselect_child (gobj (), (child).gobj ());
  }

  auto
  FlowBox::select_all () -> void
  {
    gtk_flow_box_select_all (gobj ());
  }

  auto
  FlowBox::unselect_all () -> void
  {
    gtk_flow_box_unselect_all (gobj ());
  }

  auto
  FlowBox::set_selection_mode (SelectionMode mode) -> void
  {
    gtk_flow_box_set_selection_mode (gobj (),
                                     static_cast<GtkSelectionMode> (mode));
  }

  auto
  FlowBox::get_selection_mode () const -> SelectionMode
  {
    return static_cast<SelectionMode> (
        gtk_flow_box_get_selection_mode (const_cast<GtkFlowBox*> (gobj ())));
  }

  auto
  FlowBox::set_hadjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_flow_box_set_hadjustment (gobj (), Glib::unwrap (adjustment));
  }

  auto
  FlowBox::set_vadjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_flow_box_set_vadjustment (gobj (), Glib::unwrap (adjustment));
  }

  auto
  FlowBox::invalidate_filter () -> void
  {
    gtk_flow_box_invalidate_filter (gobj ());
  }

  auto
  FlowBox::invalidate_sort () -> void
  {
    gtk_flow_box_invalidate_sort (gobj ());
  }

  auto
  FlowBox::signal_child_activated () -> Glib::SignalProxy<void (FlowBoxChild*)>
  {
    return Glib::SignalProxy<void (FlowBoxChild*)> (
        this,
        &FlowBox_signal_child_activated_info);
  }

  auto
  FlowBox::signal_selected_children_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &FlowBox_signal_selected_children_changed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
      "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FlowBox::property_selection_mode () -> Glib::PropertyProxy<SelectionMode>
  {
    return Glib::PropertyProxy<SelectionMode> (this, "selection-mode");
  }

  auto
  FlowBox::property_selection_mode () const -> Glib::PropertyProxy_ReadOnly<SelectionMode>
  {
    return Glib::PropertyProxy_ReadOnly<SelectionMode> (this, "selection-mode");
  }

  auto
  FlowBox::property_activate_on_single_click () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activate-on-single-click");
  }

  auto
  FlowBox::property_activate_on_single_click () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "activate-on-single-click");
  }

  auto
  FlowBox::property_accept_unpaired_release () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "accept-unpaired-release");
  }

  auto
  FlowBox::property_accept_unpaired_release () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "accept-unpaired-release");
  }

  auto
  FlowBox::property_homogeneous () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  FlowBox::property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  FlowBox::property_min_children_per_line () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "min-children-per-line");
  }

  auto
  FlowBox::property_min_children_per_line () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "min-children-per-line");
  }

  auto
  FlowBox::property_max_children_per_line () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "max-children-per-line");
  }

  auto
  FlowBox::property_max_children_per_line () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "max-children-per-line");
  }

  auto
  FlowBox::property_row_spacing () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "row-spacing");
  }

  auto
  FlowBox::property_row_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "row-spacing");
  }

  auto
  FlowBox::property_column_spacing () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "column-spacing");
  }

  auto
  FlowBox::property_column_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "column-spacing");
  }

} // namespace Gtk
