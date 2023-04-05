// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/combobox.hxx>
  #include <libmm/gtk/combobox_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gdk/device.hxx>
  #include <libmm/gtk/liststore.hxx>
  #include <libmm/gtk/treeview_private.hxx>

namespace gtk
{

  ComboBox::ComboBox (bool has_entry)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (combobox_class_.init (),
                                          "has-entry",
                                          gboolean (has_entry),
                                          nullptr))
  {
  }

  ComboBox::ComboBox (const glib::RefPtr<TreeModel>& model, bool has_entry)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (combobox_class_.init (),
                                          "model",
                                          glib::unwrap (model),
                                          "has-entry",
                                          gboolean (has_entry),
                                          nullptr))
  {
  }

  auto
  ComboBox::unset_active () -> void
  {
    gtk_combo_box_set_active (gobj (), -1);
  }

  auto
  ComboBox::get_active () -> TreeModel::iterator
  {
    gtk::TreeModel::iterator iter;

    auto model = get_model ();
    if (model)
    {
      gtk_combo_box_get_active_iter (gobj (), iter.gobj ());

      iter.set_model_gobject (model->gobj ());
    }

    return iter;
  }

  auto
  ComboBox::get_active () const -> TreeModel::const_iterator
  {
    gtk::TreeModel::const_iterator iter;

    const auto model = get_model ();
    if (model)
    {
      gtk_combo_box_get_active_iter (const_cast<GtkComboBox*> (gobj ()),
                                     iter.gobj ());

      iter.set_model_gobject (const_cast<GtkTreeModel*> (model->gobj ()));
    }

    return iter;
  }

  auto
  ComboBox::unset_model () -> void
  {
    gtk_combo_box_set_model (gobj (), nullptr);
  }

  auto
  ComboBox::set_row_separator_func (const SlotRowSeparator& slot) -> void
  {
    auto slot_copy = new SlotRowSeparator (slot);

    gtk_combo_box_set_row_separator_func (
        gobj (),
        &TreeView_Private::SignalProxy_RowSeparator_gtk_callback,
        slot_copy,
        &TreeView_Private::SignalProxy_RowSeparator_gtk_callback_destroy);
  }

  auto
  ComboBox::unset_row_separator_func () -> void
  {
    gtk_combo_box_set_row_separator_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  ComboBox::unset_child () -> void
  {
    gtk_combo_box_set_child (gobj (), nullptr);
  }

  auto
  ComboBox::get_entry () -> Entry*
  {
    return dynamic_cast<gtk::Entry*> (get_child ());
  }

  auto
  ComboBox::get_entry () const -> const Entry*
  {
    return dynamic_cast<const gtk::Entry*> (get_child ());
  }

  auto
  ComboBox::get_entry_text () const -> glib::ustring
  {
    const auto entry = get_entry ();
    if (!entry)
      return glib::ustring ();
    else
      return entry->get_text ();
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo ComboBox_signal_changed_info = {
      "changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  ComboBox_signal_format_entry_text_callback (GtkComboBox* self,
                                              const gchar* p0,
                                              void* data) -> gchar*
  {
    using namespace gtk;
    using SlotType = sigc::slot<glib::ustring (const TreeModel::Path&)>;

    auto obj = dynamic_cast<ComboBox*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return g_strdup (glib::c_str_or_nullptr (
              (*static_cast<SlotType*> (slot)) (TreeModel::Path (p0))));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gchar*;
    return RType ();
  }

  static auto
  ComboBox_signal_format_entry_text_notify_callback (GtkComboBox* self,
                                                     const gchar* p0,
                                                     void* data) -> gchar*
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const TreeModel::Path&)>;

    auto obj = dynamic_cast<ComboBox*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (TreeModel::Path (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gchar*;
    return RType ();
  }

  static const glib::SignalProxyInfo ComboBox_signal_format_entry_text_info = {
      "format-entry-text",
      (GCallback) &ComboBox_signal_format_entry_text_callback,
      (GCallback) &ComboBox_signal_format_entry_text_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkComboBox* object, bool take_copy) -> gtk::ComboBox*
  {
    return dynamic_cast<gtk::ComboBox*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ComboBox_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ComboBox_Class::class_init_function;

      register_derived_type (gtk_combo_box_get_type ());

      CellLayout::add_interface (get_type ());
      CellEditable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ComboBox_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->changed = &changed_callback;
    klass->format_entry_text = &format_entry_text_callback;
  }

  auto
  ComboBox_Class::changed_callback (GtkComboBox* self) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  ComboBox_Class::format_entry_text_callback (GtkComboBox* self,
                                              const gchar* p0) -> gchar*
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return g_strdup (glib::c_str_or_nullptr (
              obj->on_format_entry_text (TreeModel::Path (p0))));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->format_entry_text)
      return (*base->format_entry_text) (self, p0);

    using RType = gchar*;
    return RType ();
  }

  auto
  ComboBox_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ComboBox ((GtkComboBox*) (o)));
  }

  ComboBox::ComboBox (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ComboBox::ComboBox (GtkComboBox* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ComboBox::ComboBox (ComboBox&& src) noexcept
    : gtk::Widget (std::move (src)),
      CellLayout (std::move (src)),
      CellEditable (std::move (src))
  {
  }

  auto
  ComboBox::operator= (ComboBox&& src) noexcept -> ComboBox&
  {
    gtk::Widget::operator= (std::move (src));
    CellLayout::operator= (std::move (src));
    CellEditable::operator= (std::move (src));
    return *this;
  }

  ComboBox::~ComboBox () noexcept
  {
    destroy_ ();
  }

  ComboBox::CppClassType ComboBox::combobox_class_;

  auto
  ComboBox::get_type () -> GType
  {
    return combobox_class_.init ().get_type ();
  }

  auto
  ComboBox::get_base_type () -> GType
  {
    return gtk_combo_box_get_type ();
  }

  auto
  ComboBox::get_active_row_number () const -> int
  {
    return gtk_combo_box_get_active (const_cast<GtkComboBox*> (gobj ()));
  }

  auto
  ComboBox::set_active (int index) -> void
  {
    gtk_combo_box_set_active (gobj (), index);
  }

  auto
  ComboBox::set_active (const TreeModel::const_iterator& iter) -> void
  {
    gtk_combo_box_set_active_iter (gobj (),
                                   const_cast<GtkTreeIter*> ((iter).gobj ()));
  }

  auto
  ComboBox::get_model () -> glib::RefPtr<TreeModel>
  {
    auto retvalue = glib::wrap (gtk_combo_box_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ComboBox::get_model () const -> glib::RefPtr<const TreeModel>
  {
    return const_cast<ComboBox*> (this)->get_model ();
  }

  auto
  ComboBox::set_model (const glib::RefPtr<TreeModel>& model) -> void
  {
    gtk_combo_box_set_model (gobj (), glib::unwrap (model));
  }

  auto
  ComboBox::set_button_sensitivity (SensitivityType sensitivity) -> void
  {
    gtk_combo_box_set_button_sensitivity (
        gobj (),
        static_cast<GtkSensitivityType> (sensitivity));
  }

  auto
  ComboBox::get_button_sensitivity () const -> SensitivityType
  {
    return static_cast<SensitivityType> (gtk_combo_box_get_button_sensitivity (
        const_cast<GtkComboBox*> (gobj ())));
  }

  auto
  ComboBox::get_has_entry () const -> bool
  {
    return gtk_combo_box_get_has_entry (const_cast<GtkComboBox*> (gobj ()));
  }

  auto
  ComboBox::set_entry_text_column (const TreeModelColumnBase& text_column) const -> void
  {
    gtk_combo_box_set_entry_text_column (const_cast<GtkComboBox*> (gobj ()),
                                         (text_column).index ());
  }

  auto
  ComboBox::set_entry_text_column (int text_column) -> void
  {
    gtk_combo_box_set_entry_text_column (gobj (), text_column);
  }

  auto
  ComboBox::get_entry_text_column () const -> int
  {
    return gtk_combo_box_get_entry_text_column (
        const_cast<GtkComboBox*> (gobj ()));
  }

  auto
  ComboBox::set_popup_fixed_width (bool fixed) -> void
  {
    gtk_combo_box_set_popup_fixed_width (gobj (), static_cast<int> (fixed));
  }

  auto
  ComboBox::get_popup_fixed_width () const -> bool
  {
    return gtk_combo_box_get_popup_fixed_width (
        const_cast<GtkComboBox*> (gobj ()));
  }

  auto
  ComboBox::popup () -> void
  {
    gtk_combo_box_popup (gobj ());
  }

  auto
  ComboBox::popup (const glib::RefPtr<gdk::Device>& device) -> void
  {
    gtk_combo_box_popup_for_device (gobj (), glib::unwrap (device));
  }

  auto
  ComboBox::popdown () -> void
  {
    gtk_combo_box_popdown (gobj ());
  }

  auto
  ComboBox::get_id_column () const -> int
  {
    return gtk_combo_box_get_id_column (const_cast<GtkComboBox*> (gobj ()));
  }

  auto
  ComboBox::set_id_column (int id_column) -> void
  {
    gtk_combo_box_set_id_column (gobj (), id_column);
  }

  auto
  ComboBox::get_active_id () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_combo_box_get_active_id (const_cast<GtkComboBox*> (gobj ())));
  }

  auto
  ComboBox::set_active_id (const glib::ustring& active_id) -> bool
  {
    return gtk_combo_box_set_active_id (gobj (), active_id.c_str ());
  }

  auto
  ComboBox::set_child (Widget& child) -> void
  {
    gtk_combo_box_set_child (gobj (), (child).gobj ());
  }

  auto
  ComboBox::get_child () -> Widget*
  {
    return glib::wrap (gtk_combo_box_get_child (gobj ()));
  }

  auto
  ComboBox::get_child () const -> const Widget*
  {
    return const_cast<ComboBox*> (this)->get_child ();
  }

  auto
  ComboBox::signal_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &ComboBox_signal_changed_info);
  }

  auto
  ComboBox::signal_format_entry_text () -> glib::SignalProxy<glib::ustring (const TreeModel::Path&)>
  {
    return glib::SignalProxy<glib::ustring (const TreeModel::Path&)> (
        this,
        &ComboBox_signal_format_entry_text_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TreeModel>>::value,
      "Type glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboBox::property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<TreeModel>> (this, "model");
  }

  auto
  ComboBox::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>> (this,
                                                                  "model");
  }

  auto
  ComboBox::property_active () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "active");
  }

  auto
  ComboBox::property_active () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "active");
  }

  auto
  ComboBox::property_has_frame () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  ComboBox::property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  auto
  ComboBox::property_popup_shown () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "popup-shown");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SensitivityType>::value,
      "Type SensitivityType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ComboBox::property_button_sensitivity () -> glib::PropertyProxy<SensitivityType>
  {
    return glib::PropertyProxy<SensitivityType> (this, "button-sensitivity");
  }

  auto
  ComboBox::property_button_sensitivity () const -> glib::PropertyProxy_ReadOnly<SensitivityType>
  {
    return glib::PropertyProxy_ReadOnly<SensitivityType> (this,
                                                          "button-sensitivity");
  }

  auto
  ComboBox::property_popup_fixed_width () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "popup-fixed-width");
  }

  auto
  ComboBox::property_popup_fixed_width () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "popup-fixed-width");
  }

  auto
  ComboBox::property_has_entry () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-entry");
  }

  auto
  ComboBox::property_entry_text_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "entry-text-column");
  }

  auto
  ComboBox::property_entry_text_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "entry-text-column");
  }

  auto
  ComboBox::property_id_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "id-column");
  }

  auto
  ComboBox::property_id_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "id-column");
  }

  auto
  ComboBox::property_active_id () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "active-id");
  }

  auto
  ComboBox::property_active_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "active-id");
  }

  auto
  ComboBox::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  ComboBox::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  gtk::ComboBox::on_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  gtk::ComboBox::on_format_entry_text (const TreeModel::Path& path) -> glib::ustring
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->format_entry_text)
      return glib::convert_return_gchar_ptr_to_ustring (
          (*base->format_entry_text) (gobj (), (path).to_string ().c_str ()));

    using RType = glib::ustring;
    return RType ();
  }

} // namespace gtk

#endif
