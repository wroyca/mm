// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/flattenlistmodel.hxx>
#include <libmm/gtk/flattenlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFlattenListModel* object, bool take_copy) -> glib::RefPtr<gtk::FlattenListModel>
  {
    return glib::make_refptr_for_instance<gtk::FlattenListModel> (
        dynamic_cast<gtk::FlattenListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FlattenListModel_Class::init () -> const glib::Class&
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
  FlattenListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FlattenListModel::FlattenListModel (GtkFlattenListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FlattenListModel::FlattenListModel (FlattenListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  FlattenListModel::operator= (FlattenListModel&& src) noexcept -> FlattenListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
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

  FlattenListModel::FlattenListModel (const glib::RefPtr<gio::ListModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (flattenlistmodel_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  FlattenListModel::create (const glib::RefPtr<gio::ListModel>& model) -> glib::RefPtr<FlattenListModel>
  {
    return glib::make_refptr_for_instance<FlattenListModel> (
        new FlattenListModel (model));
  }

  auto
  FlattenListModel::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_flatten_list_model_set_model (gobj (), glib::unwrap (model));
  }

  auto
  FlattenListModel::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_flatten_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FlattenListModel::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<FlattenListModel*> (this)->get_model ();
  }

  auto
  FlattenListModel::get_model_for_item (guint position) -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (
        gtk_flatten_list_model_get_model_for_item (gobj (), position));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FlattenListModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FlattenListModel::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  FlattenListModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  FlattenListModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
