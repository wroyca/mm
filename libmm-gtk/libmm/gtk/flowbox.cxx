// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/flowbox.hxx>
#include <libmm/gtk/flowbox_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/adjustment.hxx>

namespace
{

  static auto
  FuncProxy_Foreach_gtk_callback (GtkFlowBox* box,
                                  GtkFlowBoxChild* child,
                                  void* data) -> void
  {
    auto the_slot = static_cast<gtk::FlowBox::SlotSelectedForeach*> (data);

    try
    {
      (*the_slot) (glib::wrap (box), glib::wrap (child));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }
  }

  static auto
  SignalProxy_Filter_gtk_callback (GtkFlowBoxChild* child, void* data) -> gboolean
  {
    auto the_slot = static_cast<gtk::FlowBox::SlotFilter*> (data);

    try
    {
      return (*the_slot) (glib::wrap (child));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
      return FALSE;
    }
  }

  static auto
  SignalProxy_Filter_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<gtk::FlowBox::SlotFilter*> (data);
  }

  static auto
  SignalProxy_Sort_gtk_callback (GtkFlowBoxChild* child1,
                                 GtkFlowBoxChild* child2,
                                 void* data) -> int
  {
    auto the_slot = static_cast<gtk::FlowBox::SlotSort*> (data);

    try
    {
      return (*the_slot) (glib::wrap (child1), glib::wrap (child2));
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
      return 0;
    }
  }

  static auto
  SignalProxy_Sort_gtk_callback_destroy (void* data) -> void
  {
    delete static_cast<gtk::FlowBox::SlotSort*> (data);
  }

  static auto
  proxy_bind_model_create_widget_callback (void* item, void* data) -> GtkWidget*
  {
    auto& slot =
        *static_cast<gtk::FlowBox::SlotCreateWidget<glib::Object>*> (data);
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
  FlowBox::bind_model (const glib::RefPtr<gio::ListModel>& model,
                       const SlotCreateWidget<glib::Object>& slot_create_widget) -> void
  {
    auto slot_copy = new SlotCreateWidget<glib::Object> (slot_create_widget);

    gtk_flow_box_bind_model (
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
  FlowBox_signal_child_activated_callback (GtkFlowBox* self,
                                           GtkFlowBoxChild* p0,
                                           void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (FlowBoxChild*)>;

    auto obj = dynamic_cast<FlowBox*> (
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

  static const glib::SignalProxyInfo FlowBox_signal_child_activated_info = {
      "child-activated",
      (GCallback) &FlowBox_signal_child_activated_callback,
      (GCallback) &FlowBox_signal_child_activated_callback};

  static const glib::SignalProxyInfo
      FlowBox_signal_selected_children_changed_info = {
          "selected-children-changed",
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkFlowBox* object, bool take_copy) -> gtk::FlowBox*
  {
    return dynamic_cast<gtk::FlowBox*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  FlowBox_Class::init () -> const glib::Class&
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
  FlowBox_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new FlowBox ((GtkFlowBox*) (o)));
  }

  FlowBox::FlowBox (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  FlowBox::FlowBox (GtkFlowBox* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FlowBox::FlowBox (FlowBox&& src) noexcept
    : gtk::Widget (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  FlowBox::operator= (FlowBox&& src) noexcept -> FlowBox&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (flowbox_class_.init ()))
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
    return glib::wrap (gtk_flow_box_get_child_at_index (gobj (), idx));
  }

  auto
  FlowBox::get_child_at_index (int idx) const -> const FlowBoxChild*
  {
    return const_cast<FlowBox*> (this)->get_child_at_index (idx);
  }

  auto
  FlowBox::get_child_at_pos (int x, int y) -> FlowBoxChild*
  {
    return glib::wrap (gtk_flow_box_get_child_at_pos (gobj (), x, y));
  }

  auto
  FlowBox::get_child_at_pos (int x, int y) const -> const FlowBoxChild*
  {
    return const_cast<FlowBox*> (this)->get_child_at_pos (x, y);
  }

  auto
  FlowBox::get_selected_children () -> std::vector<gtk::FlowBoxChild*>
  {
    return glib::ListHandler<gtk::FlowBoxChild*>::list_to_vector (
        gtk_flow_box_get_selected_children (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  FlowBox::get_selected_children () const -> std::vector<const gtk::FlowBoxChild*>
  {
    return glib::ListHandler<const gtk::FlowBoxChild*>::list_to_vector (
        gtk_flow_box_get_selected_children (const_cast<GtkFlowBox*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
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
  FlowBox::set_hadjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_flow_box_set_hadjustment (gobj (), glib::unwrap (adjustment));
  }

  auto
  FlowBox::set_vadjustment (const glib::RefPtr<Adjustment>& adjustment) -> void
  {
    gtk_flow_box_set_vadjustment (gobj (), glib::unwrap (adjustment));
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
  FlowBox::signal_child_activated () -> glib::SignalProxy<void (FlowBoxChild*)>
  {
    return glib::SignalProxy<void (FlowBoxChild*)> (
        this,
        &FlowBox_signal_child_activated_info);
  }

  auto
  FlowBox::signal_selected_children_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &FlowBox_signal_selected_children_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SelectionMode>::value,
      "Type SelectionMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FlowBox::property_selection_mode () -> glib::PropertyProxy<SelectionMode>
  {
    return glib::PropertyProxy<SelectionMode> (this, "selection-mode");
  }

  auto
  FlowBox::property_selection_mode () const -> glib::PropertyProxy_ReadOnly<SelectionMode>
  {
    return glib::PropertyProxy_ReadOnly<SelectionMode> (this, "selection-mode");
  }

  auto
  FlowBox::property_activate_on_single_click () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activate-on-single-click");
  }

  auto
  FlowBox::property_activate_on_single_click () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "activate-on-single-click");
  }

  auto
  FlowBox::property_accept_unpaired_release () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "accept-unpaired-release");
  }

  auto
  FlowBox::property_accept_unpaired_release () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accept-unpaired-release");
  }

  auto
  FlowBox::property_homogeneous () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "homogeneous");
  }

  auto
  FlowBox::property_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "homogeneous");
  }

  auto
  FlowBox::property_min_children_per_line () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "min-children-per-line");
  }

  auto
  FlowBox::property_min_children_per_line () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "min-children-per-line");
  }

  auto
  FlowBox::property_max_children_per_line () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "max-children-per-line");
  }

  auto
  FlowBox::property_max_children_per_line () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "max-children-per-line");
  }

  auto
  FlowBox::property_row_spacing () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "row-spacing");
  }

  auto
  FlowBox::property_row_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "row-spacing");
  }

  auto
  FlowBox::property_column_spacing () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "column-spacing");
  }

  auto
  FlowBox::property_column_spacing () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "column-spacing");
  }

} // namespace gtk
