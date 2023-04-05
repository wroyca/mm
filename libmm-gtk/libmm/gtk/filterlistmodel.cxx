// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filterlistmodel.hxx>
#include <libmm/gtk/filterlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFilterListModel* object, bool take_copy) -> glib::RefPtr<gtk::FilterListModel>
  {
    return glib::make_refptr_for_instance<gtk::FilterListModel> (
        dynamic_cast<gtk::FilterListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FilterListModel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FilterListModel_Class::class_init_function;

      gtype_ = gtk_filter_list_model_get_type ();
    }

    return *this;
  }

  auto
  FilterListModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FilterListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FilterListModel ((GtkFilterListModel*) object);
  }

  auto
  FilterListModel::gobj_copy () -> GtkFilterListModel*
  {
    reference ();
    return gobj ();
  }

  FilterListModel::FilterListModel (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FilterListModel::FilterListModel (GtkFilterListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FilterListModel::FilterListModel (FilterListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  FilterListModel::operator= (FilterListModel&& src) noexcept -> FilterListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  FilterListModel::~FilterListModel () noexcept {}

  FilterListModel::CppClassType FilterListModel::filterlistmodel_class_;

  auto
  FilterListModel::get_type () -> GType
  {
    return filterlistmodel_class_.init ().get_type ();
  }

  auto
  FilterListModel::get_base_type () -> GType
  {
    return gtk_filter_list_model_get_type ();
  }

  FilterListModel::FilterListModel (const glib::RefPtr<gio::ListModel>& model,
                                    const glib::RefPtr<Filter>& filter)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (filterlistmodel_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           "filter",
                                           glib::unwrap (filter),
                                           nullptr))
  {
  }

  auto
  FilterListModel::create (const glib::RefPtr<gio::ListModel>& model,
                           const glib::RefPtr<Filter>& filter) -> glib::RefPtr<FilterListModel>
  {
    return glib::make_refptr_for_instance<FilterListModel> (
        new FilterListModel (model, filter));
  }

  auto
  FilterListModel::set_filter (const glib::RefPtr<Filter>& filter) -> void
  {
    gtk_filter_list_model_set_filter (gobj (), glib::unwrap (filter));
  }

  auto
  FilterListModel::get_filter () -> glib::RefPtr<Filter>
  {
    auto retvalue = glib::wrap (gtk_filter_list_model_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FilterListModel::get_filter () const -> glib::RefPtr<const Filter>
  {
    return const_cast<FilterListModel*> (this)->get_filter ();
  }

  auto
  FilterListModel::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_filter_list_model_set_model (gobj (), glib::unwrap (model));
  }

  auto
  FilterListModel::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_filter_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FilterListModel::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<FilterListModel*> (this)->get_model ();
  }

  auto
  FilterListModel::set_incremental (bool incremental) -> void
  {
    gtk_filter_list_model_set_incremental (gobj (),
                                           static_cast<int> (incremental));
  }

  auto
  FilterListModel::get_incremental () const -> bool
  {
    return gtk_filter_list_model_get_incremental (
        const_cast<GtkFilterListModel*> (gobj ()));
  }

  auto
  FilterListModel::get_pending () const -> guint
  {
    return gtk_filter_list_model_get_pending (
        const_cast<GtkFilterListModel*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Filter>>::value,
      "Type glib::RefPtr<Filter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FilterListModel::property_filter () -> glib::PropertyProxy<glib::RefPtr<Filter>>
  {
    return glib::PropertyProxy<glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FilterListModel::property_filter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FilterListModel::property_incremental () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "incremental");
  }

  auto
  FilterListModel::property_incremental () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "incremental");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FilterListModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FilterListModel::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  FilterListModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  FilterListModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  FilterListModel::property_pending () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "pending");
  }

} // namespace gtk
