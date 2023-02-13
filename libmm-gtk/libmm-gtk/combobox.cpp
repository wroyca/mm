


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/combobox.hpp>
#include <mm/gtk/private/combobox_p.hpp>


/*
 * Copyright 2003 The gtkmm Development Team
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

#include <mm/gdk/device.hpp>
#include <mm/gtk/liststore.hpp>
#include <mm/gtk/treeview_private.hpp> //For SignalProxy_RowSeparator.
#include <gtk/gtk.h>

namespace Gtk
{

ComboBox::ComboBox(const bool has_entry)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(combobox_class_.init(), "has-entry",gboolean(has_entry), nullptr))
{}

ComboBox::ComboBox(const Glib::RefPtr<TreeModel>& model, const bool has_entry)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(combobox_class_.init(), "model",Glib::unwrap(model),"has-entry",gboolean(has_entry), nullptr))
{}

auto ComboBox::unset_active () -> void
{
  gtk_combo_box_set_active(gobj(), -1 /* see GTK+ docs */);
}

auto ComboBox::get_active() -> TreeModel::iterator
{
  TreeModel::iterator iter;

  const auto model = get_model();
  if(model)
  {
    gtk_combo_box_get_active_iter(gobj(), iter.gobj());

    //It must be given the model, because the C++ wrapper has extra information.
    iter.set_model_gobject(model->gobj());
  }

  return iter;
}

auto ComboBox::get_active() const -> TreeModel::const_iterator
{
  TreeModel::const_iterator iter;

  const auto model = get_model();
  if(model)
  {
    gtk_combo_box_get_active_iter(const_cast<GtkComboBox*>(gobj()), iter.gobj());

    //It must be given the model, because the C++ wrapper has extra information.
    iter.set_model_gobject(const_cast<GtkTreeModel*>(model->gobj()));
  }

  return iter;
}


auto ComboBox::unset_model () -> void
{
  gtk_combo_box_set_model(gobj(), nullptr);
}


auto ComboBox::set_row_separator_func (const SlotRowSeparator &slot) -> void
{
  //Create a copy of the slot. A pointer to this will be passed through the callback's data parameter.
  //It will be deleted when SignalProxy_RowSeparator_gtk_callback_destroy() is called.
  const auto slot_copy = new SlotRowSeparator(slot);

  gtk_combo_box_set_row_separator_func(gobj(),
      &TreeView_Private::SignalProxy_RowSeparator_gtk_callback, slot_copy,
      &TreeView_Private::SignalProxy_RowSeparator_gtk_callback_destroy);
}

auto ComboBox::unset_row_separator_func () -> void
{
  gtk_combo_box_set_row_separator_func(gobj(), nullptr, nullptr, nullptr /* See C docs. */);
}

auto ComboBox::unset_child () -> void
{
  gtk_combo_box_set_child(gobj(), nullptr);
}

auto ComboBox::get_entry() -> Entry*
{
  return dynamic_cast<Entry *>(get_child());
}

auto ComboBox::get_entry() const -> const Entry*
{
  return dynamic_cast<const Entry *>(get_child());
}

auto ComboBox::get_entry_text() const -> Glib::ustring
{
  const auto entry = get_entry();
  if(!entry)
    return {};
  else
    return entry->get_text();
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo ComboBox_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto ComboBox_signal_format_entry_text_callback(GtkComboBox* self, const gchar* p0,void* data) -> gchar*
{
  using namespace Gtk;
  using SlotType = sigc::slot<Glib::ustring(const TreeModel::Path&)>;

  const auto obj = dynamic_cast<ComboBox*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return g_strdup(
          c_str_or_nullptr((*static_cast<SlotType*>(slot))(TreeModel::Path(p0)
)));
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gchar*;
  return RType();
}

auto ComboBox_signal_format_entry_text_notify_callback(GtkComboBox* self, const gchar* p0, void* data) -> gchar*
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const TreeModel::Path&)>;

  const auto obj = dynamic_cast<ComboBox*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(TreeModel::Path(p0)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gchar*;
  return RType();
}

const Glib::SignalProxyInfo ComboBox_signal_format_entry_text_info =
{
  "format-entry-text",
  (GCallback) &ComboBox_signal_format_entry_text_callback,
  (GCallback) &ComboBox_signal_format_entry_text_notify_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkComboBox* object, const bool take_copy) -> Gtk::ComboBox*
{
  return dynamic_cast<Gtk::ComboBox *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ComboBox_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ComboBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_combo_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  CellEditable::add_interface(get_type());

  }

  return *this;
}


auto ComboBox_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->changed = &changed_callback;
  klass->format_entry_text = &format_entry_text_callback;
}


auto ComboBox_Class::changed_callback (GtkComboBox *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_changed();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}
auto ComboBox_Class::format_entry_text_callback(GtkComboBox* self, const gchar* p0) -> gchar*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return g_strdup(
          c_str_or_nullptr(obj->on_format_entry_text(TreeModel::Path(p0)
)));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->format_entry_text)
    return (*base->format_entry_text)(self, p0);

  using RType = gchar*;
  return RType();
}


auto ComboBox_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ComboBox((GtkComboBox*)o));

}


/* The implementation: */

ComboBox::ComboBox(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ComboBox::ComboBox(GtkComboBox* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ComboBox::ComboBox(ComboBox&& src) noexcept
: Widget(std::move(src))
  , CellLayout(std::move(src))
  , CellEditable(std::move(src))
{}

auto ComboBox::operator=(ComboBox&& src) noexcept -> ComboBox&
{
  Widget::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  CellEditable::operator=(std::move(src));
  return *this;
}

ComboBox::~ComboBox() noexcept
{
  destroy_();
}

ComboBox::CppClassType ComboBox::combobox_class_; // initialize static member

auto ComboBox::get_type() -> GType
{
  return combobox_class_.init().get_type();
}


auto ComboBox::get_base_type() -> GType
{
  return gtk_combo_box_get_type();
}


auto ComboBox::get_active_row_number() const -> int
{
  return gtk_combo_box_get_active(const_cast<GtkComboBox*>(gobj()));
}

auto ComboBox::set_active (
  const int index) -> void
{
  gtk_combo_box_set_active(gobj(), index);
}

auto ComboBox::set_active (const TreeModel::const_iterator &iter) -> void
{
  gtk_combo_box_set_active_iter(gobj(), const_cast<GtkTreeIter*>(iter.gobj()));
}

auto ComboBox::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_combo_box_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ComboBox::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<ComboBox*>(this)->get_model();
}

auto ComboBox::set_model (const Glib::RefPtr <TreeModel> &model) -> void
{
  gtk_combo_box_set_model(gobj(), Glib::unwrap(model));
}

auto ComboBox::set_button_sensitivity (SensitivityType sensitivity) -> void
{
  gtk_combo_box_set_button_sensitivity(gobj(), static_cast<GtkSensitivityType>(sensitivity));
}

auto ComboBox::get_button_sensitivity() const -> SensitivityType
{
  return static_cast<SensitivityType>(gtk_combo_box_get_button_sensitivity(const_cast<GtkComboBox*>(gobj())));
}

auto ComboBox::get_has_entry() const -> bool
{
  return gtk_combo_box_get_has_entry(const_cast<GtkComboBox*>(gobj()));
}

auto ComboBox::set_entry_text_column (const TreeModelColumnBase &text_column) const -> void
{
  gtk_combo_box_set_entry_text_column(const_cast<GtkComboBox*>(gobj()), text_column.index());
}

auto ComboBox::set_entry_text_column (
  const int text_column) -> void
{
  gtk_combo_box_set_entry_text_column(gobj(), text_column);
}

auto ComboBox::get_entry_text_column() const -> int
{
  return gtk_combo_box_get_entry_text_column(const_cast<GtkComboBox*>(gobj()));
}

auto ComboBox::set_popup_fixed_width (
  const bool fixed) -> void
{
  gtk_combo_box_set_popup_fixed_width(gobj(), fixed);
}

auto ComboBox::get_popup_fixed_width() const -> bool
{
  return gtk_combo_box_get_popup_fixed_width(const_cast<GtkComboBox*>(gobj()));
}

auto ComboBox::popup () -> void
{
  gtk_combo_box_popup(gobj());
}

auto ComboBox::popup (const Glib::RefPtr <Gdk::Device> &device) -> void
{
  gtk_combo_box_popup_for_device(gobj(), Glib::unwrap(device));
}

auto ComboBox::popdown () -> void
{
  gtk_combo_box_popdown(gobj());
}

auto ComboBox::get_id_column() const -> int
{
  return gtk_combo_box_get_id_column(const_cast<GtkComboBox*>(gobj()));
}

auto ComboBox::set_id_column (
  const int id_column) -> void
{
  gtk_combo_box_set_id_column(gobj(), id_column);
}

auto ComboBox::get_active_id() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_combo_box_get_active_id(const_cast<GtkComboBox*>(gobj())));
}

auto ComboBox::set_active_id(const Glib::ustring& active_id) -> bool
{
  return gtk_combo_box_set_active_id(gobj(), active_id.c_str());
}

auto ComboBox::set_child (Widget &child) -> void
{
  gtk_combo_box_set_child(gobj(), child.gobj());
}

auto ComboBox::get_child() -> Widget*
{
  return Glib::wrap(gtk_combo_box_get_child(gobj()));
}

auto ComboBox::get_child() const -> const Widget*
{
  return const_cast<ComboBox*>(this)->get_child();
}


auto ComboBox::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &ComboBox_signal_changed_info};
}


auto ComboBox::signal_format_entry_text() -> Glib::SignalProxy<Glib::ustring(const TreeModel::Path&)>
{
  return {this, &ComboBox_signal_format_entry_text_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ComboBox::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto ComboBox::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto ComboBox::property_active() -> Glib::PropertyProxy< int >
{
  return {this, "active"};
}

auto ComboBox::property_active() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "active"};
}

auto ComboBox::property_has_frame() -> Glib::PropertyProxy< bool >
{
  return {this, "has-frame"};
}

auto ComboBox::property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-frame"};
}

auto ComboBox::property_popup_shown() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "popup-shown"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<SensitivityType>::value,
  "Type SensitivityType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ComboBox::property_button_sensitivity() -> Glib::PropertyProxy< SensitivityType >
{
  return {this, "button-sensitivity"};
}

auto ComboBox::property_button_sensitivity() const -> Glib::PropertyProxy_ReadOnly< SensitivityType >
{
  return {this, "button-sensitivity"};
}

auto ComboBox::property_popup_fixed_width() -> Glib::PropertyProxy< bool >
{
  return {this, "popup-fixed-width"};
}

auto ComboBox::property_popup_fixed_width() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "popup-fixed-width"};
}

auto ComboBox::property_has_entry() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-entry"};
}

auto ComboBox::property_entry_text_column() -> Glib::PropertyProxy< int >
{
  return {this, "entry-text-column"};
}

auto ComboBox::property_entry_text_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "entry-text-column"};
}

auto ComboBox::property_id_column() -> Glib::PropertyProxy< int >
{
  return {this, "id-column"};
}

auto ComboBox::property_id_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "id-column"};
}

auto ComboBox::property_active_id() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "active-id"};
}

auto ComboBox::property_active_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "active-id"};
}

auto ComboBox::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto ComboBox::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


auto ComboBox::on_changed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->changed)
    (*base->changed)(gobj());
}
auto ComboBox::on_format_entry_text(const TreeModel::Path& path) -> Glib::ustring
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->format_entry_text)
    return Glib::convert_return_gchar_ptr_to_ustring((*base->format_entry_text)(gobj(),path.to_string().c_str()));

  using RType = Glib::ustring;
  return {};
}


} // namespace Gtk


