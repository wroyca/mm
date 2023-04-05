// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrenderercombo.hxx>
  #include <libmm/gtk/cellrenderercombo_p.hxx>

  #include <gtk/gtk.h>

static auto
_get_model (GtkCellRendererCombo* renderer) -> GtkTreeModel*
{
  if (!renderer)
    return nullptr;

  GtkTreeModel* combo_model = nullptr;
  g_object_get (G_OBJECT (renderer), "model", &combo_model, nullptr);
  return combo_model;
}

namespace gtk
{

  auto
  CellRendererCombo::_property_renderable () -> glib::PropertyProxy_Base
  {
    return CellRendererText::_property_renderable ();
  }

} // namespace gtk

namespace
{

  static auto
  CellRendererCombo_signal_changed_callback (GtkCellRendererCombo* self,
                                             const gchar* p0,
                                             GtkTreeIter* p1,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType =
        sigc::slot<void (const glib::ustring&, const TreeModel::iterator&)>;

    auto obj = dynamic_cast<CellRendererCombo*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0),
              TreeModel::iterator (_get_model (self), p1));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellRendererCombo_signal_changed_info = {
      "changed",
      (GCallback) &CellRendererCombo_signal_changed_callback,
      (GCallback) &CellRendererCombo_signal_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkCellRendererCombo* object, bool take_copy) -> gtk::CellRendererCombo*
  {
    return dynamic_cast<gtk::CellRendererCombo*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererCombo_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererCombo_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_combo_get_type ());
    }

    return *this;
  }

  auto
  CellRendererCombo_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererCombo_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererCombo ((GtkCellRendererCombo*) (o)));
  }

  CellRendererCombo::CellRendererCombo (
      const glib::ConstructParams& construct_params)
    : gtk::CellRendererText (construct_params)
  {
  }

  CellRendererCombo::CellRendererCombo (GtkCellRendererCombo* castitem)
    : gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererCombo::CellRendererCombo (CellRendererCombo&& src) noexcept
    : gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererCombo::operator= (CellRendererCombo&& src) noexcept -> CellRendererCombo&
  {
    gtk::CellRendererText::operator= (std::move (src));
    return *this;
  }

  CellRendererCombo::~CellRendererCombo () noexcept
  {
    destroy_ ();
  }

  CellRendererCombo::CppClassType CellRendererCombo::cellrenderercombo_class_;

  auto
  CellRendererCombo::get_type () -> GType
  {
    return cellrenderercombo_class_.init ().get_type ();
  }

  auto
  CellRendererCombo::get_base_type () -> GType
  {
    return gtk_cell_renderer_combo_get_type ();
  }

  CellRendererCombo::CellRendererCombo ()
    : glib::ObjectBase (nullptr),
      gtk::CellRendererText (
          glib::ConstructParams (cellrenderercombo_class_.init ()))
  {
  }

  auto
  CellRendererCombo::signal_changed () -> glib::SignalProxy<void (const glib::ustring&,
                                 const TreeModel::iterator&)>
  {
    return glib::SignalProxy<void (const glib::ustring&,
                                   const TreeModel::iterator&)> (
        this,
        &CellRendererCombo_signal_changed_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gtk::TreeModel>>::value,
      "Type glib::RefPtr<gtk::TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererCombo::property_model () -> glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>> (this, "model");
  }

  auto
  CellRendererCombo::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>> (this,
                                                                       "model");
  }

  auto
  CellRendererCombo::property_text_column () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "text-column");
  }

  auto
  CellRendererCombo::property_text_column () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "text-column");
  }

  auto
  CellRendererCombo::property_has_entry () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-entry");
  }

  auto
  CellRendererCombo::property_has_entry () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-entry");
  }

} // namespace gtk

#endif
