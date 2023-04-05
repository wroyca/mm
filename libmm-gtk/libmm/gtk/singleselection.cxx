// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/singleselection.hxx>
#include <libmm/gtk/singleselection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSingleSelection* object, bool take_copy) -> glib::RefPtr<gtk::SingleSelection>
  {
    return glib::make_refptr_for_instance<gtk::SingleSelection> (
        dynamic_cast<gtk::SingleSelection*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SingleSelection_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SingleSelection_Class::class_init_function;

      gtype_ = gtk_single_selection_get_type ();
    }

    return *this;
  }

  auto
  SingleSelection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SingleSelection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SingleSelection ((GtkSingleSelection*) object);
  }

  auto
  SingleSelection::gobj_copy () -> GtkSingleSelection*
  {
    reference ();
    return gobj ();
  }

  SingleSelection::SingleSelection (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SingleSelection::SingleSelection (GtkSingleSelection* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SingleSelection::SingleSelection (SingleSelection&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src)),
      SelectionModel (std::move (src))
  {
  }

  auto
  SingleSelection::operator= (SingleSelection&& src) noexcept -> SingleSelection&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    return *this;
  }

  SingleSelection::~SingleSelection () noexcept {}

  SingleSelection::CppClassType SingleSelection::singleselection_class_;

  auto
  SingleSelection::get_type () -> GType
  {
    return singleselection_class_.init ().get_type ();
  }

  auto
  SingleSelection::get_base_type () -> GType
  {
    return gtk_single_selection_get_type ();
  }

  SingleSelection::SingleSelection ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (singleselection_class_.init ()))
  {
  }

  SingleSelection::SingleSelection (const glib::RefPtr<gio::ListModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (singleselection_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  SingleSelection::create () -> glib::RefPtr<SingleSelection>
  {
    return glib::make_refptr_for_instance<SingleSelection> (
        new SingleSelection ());
  }

  auto
  SingleSelection::create (const glib::RefPtr<gio::ListModel>& model) -> glib::RefPtr<SingleSelection>
  {
    return glib::make_refptr_for_instance<SingleSelection> (
        new SingleSelection (model));
  }

  auto
  SingleSelection::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_single_selection_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SingleSelection::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<SingleSelection*> (this)->get_model ();
  }

  auto
  SingleSelection::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_single_selection_set_model (gobj (), glib::unwrap (model));
  }

  auto
  SingleSelection::get_selected () const -> guint
  {
    return gtk_single_selection_get_selected (
        const_cast<GtkSingleSelection*> (gobj ()));
  }

  auto
  SingleSelection::set_selected (guint position) -> void
  {
    gtk_single_selection_set_selected (gobj (), position);
  }

  auto
  SingleSelection::get_selected_item () -> glib::RefPtr<glib::ObjectBase>
  {
    auto retvalue =
        glib::make_refptr_for_instance<glib::ObjectBase> (glib::wrap_auto (
            G_OBJECT (gtk_single_selection_get_selected_item (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SingleSelection::get_selected_item () const -> glib::RefPtr<const glib::ObjectBase>
  {
    return const_cast<SingleSelection*> (this)->get_selected_item ();
  }

  auto
  SingleSelection::get_autoselect () const -> bool
  {
    return gtk_single_selection_get_autoselect (
        const_cast<GtkSingleSelection*> (gobj ()));
  }

  auto
  SingleSelection::set_autoselect (bool autoselect) -> void
  {
    gtk_single_selection_set_autoselect (gobj (),
                                         static_cast<int> (autoselect));
  }

  auto
  SingleSelection::get_can_unselect () const -> bool
  {
    return gtk_single_selection_get_can_unselect (
        const_cast<GtkSingleSelection*> (gobj ()));
  }

  auto
  SingleSelection::set_can_unselect (bool can_unselect) -> void
  {
    gtk_single_selection_set_can_unselect (gobj (),
                                           static_cast<int> (can_unselect));
  }

  auto
  SingleSelection::property_autoselect () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "autoselect");
  }

  auto
  SingleSelection::property_autoselect () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "autoselect");
  }

  auto
  SingleSelection::property_can_unselect () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "can-unselect");
  }

  auto
  SingleSelection::property_can_unselect () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "can-unselect");
  }

  auto
  SingleSelection::property_selected () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "selected");
  }

  auto
  SingleSelection::property_selected () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "selected");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::ObjectBase>>::value,
      "Type glib::RefPtr<glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SingleSelection::property_selected_item () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>> (
        this,
        "selected-item");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SingleSelection::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SingleSelection::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  SingleSelection::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  SingleSelection::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
