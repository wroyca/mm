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

namespace Gtk
{

  auto
  CellRendererCombo::_property_renderable () -> Glib::PropertyProxy_Base
  {
    return CellRendererText::_property_renderable ();
  }

} // namespace Gtk

namespace
{

  static auto
  CellRendererCombo_signal_changed_callback (GtkCellRendererCombo* self,
                                             const gchar* p0,
                                             GtkTreeIter* p1,
                                             void* data) -> void
  {
    using namespace Gtk;
    using SlotType =
        sigc::slot<void (const Glib::ustring&, const TreeModel::iterator&)>;

    auto obj = dynamic_cast<CellRendererCombo*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0),
              TreeModel::iterator (_get_model (self), p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo CellRendererCombo_signal_changed_info = {
      "changed",
      (GCallback) &CellRendererCombo_signal_changed_callback,
      (GCallback) &CellRendererCombo_signal_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkCellRendererCombo* object, bool take_copy) -> Gtk::CellRendererCombo*
  {
    return dynamic_cast<Gtk::CellRendererCombo*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererCombo_Class::init () -> const Glib::Class&
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
  CellRendererCombo_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererCombo ((GtkCellRendererCombo*) (o)));
  }

  CellRendererCombo::CellRendererCombo (
      const Glib::ConstructParams& construct_params)
    : Gtk::CellRendererText (construct_params)
  {
  }

  CellRendererCombo::CellRendererCombo (GtkCellRendererCombo* castitem)
    : Gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererCombo::CellRendererCombo (CellRendererCombo&& src) noexcept
    : Gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererCombo::operator= (CellRendererCombo&& src) noexcept -> CellRendererCombo&
  {
    Gtk::CellRendererText::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::CellRendererText (
          Glib::ConstructParams (cellrenderercombo_class_.init ()))
  {
  }

  auto
  CellRendererCombo::signal_changed () -> Glib::SignalProxy<void (const Glib::ustring&,
                                 const TreeModel::iterator&)>
  {
    return Glib::SignalProxy<void (const Glib::ustring&,
                                   const TreeModel::iterator&)> (
        this,
        &CellRendererCombo_signal_changed_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gtk::TreeModel>>::value,
      "Type Glib::RefPtr<Gtk::TreeModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRendererCombo::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gtk::TreeModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gtk::TreeModel>> (this, "model");
  }

  auto
  CellRendererCombo::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::TreeModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::TreeModel>> (this,
                                                                       "model");
  }

  auto
  CellRendererCombo::property_text_column () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "text-column");
  }

  auto
  CellRendererCombo::property_text_column () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "text-column");
  }

  auto
  CellRendererCombo::property_has_entry () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-entry");
  }

  auto
  CellRendererCombo::property_has_entry () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-entry");
  }

} // namespace Gtk

#endif