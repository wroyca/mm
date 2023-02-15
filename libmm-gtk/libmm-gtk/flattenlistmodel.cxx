// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/flattenlistmodel.hxx>
#include <libmm-gtk/flattenlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFlattenListModel* object, bool take_copy) -> Glib::RefPtr<Gtk::FlattenListModel>
  {
    return Glib::make_refptr_for_instance<Gtk::FlattenListModel> (
        dynamic_cast<Gtk::FlattenListModel*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FlattenListModel_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FlattenListModel_Class::class_init_function;

      gtype_ = gtk_flatten_list_model_get_type ();
    }

    return *this;
  }

  auto
  FlattenListModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FlattenListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FlattenListModel ((GtkFlattenListModel*) object);
  }

  auto
  FlattenListModel::gobj_copy () -> GtkFlattenListModel*
  {
    reference ();
    return gobj ();
  }

  FlattenListModel::FlattenListModel (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FlattenListModel::FlattenListModel (GtkFlattenListModel* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FlattenListModel::FlattenListModel (FlattenListModel&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src))
  {
  }

  auto
  FlattenListModel::operator= (FlattenListModel&& src) noexcept -> FlattenListModel&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
    return *this;
  }

  FlattenListModel::~FlattenListModel () noexcept {}

  FlattenListModel::CppClassType FlattenListModel::flattenlistmodel_class_;

  auto
  FlattenListModel::get_type () -> GType
  {
    return flattenlistmodel_class_.init ().get_type ();
  }

  auto
  FlattenListModel::get_base_type () -> GType
  {
    return gtk_flatten_list_model_get_type ();
  }

  FlattenListModel::FlattenListModel (const Glib::RefPtr<Gio::ListModel>& model)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (flattenlistmodel_class_.init (),
                                           "model",
                                           Glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  FlattenListModel::create (const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<FlattenListModel>
  {
    return Glib::make_refptr_for_instance<FlattenListModel> (
        new FlattenListModel (model));
  }

  auto
  FlattenListModel::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_flatten_list_model_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  FlattenListModel::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_flatten_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FlattenListModel::get_model () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<FlattenListModel*> (this)->get_model ();
  }

  auto
  FlattenListModel::get_model_for_item (guint position) -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (
        gtk_flatten_list_model_get_model_for_item (gobj (), position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FlattenListModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FlattenListModel::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  FlattenListModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  FlattenListModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace Gtk
