// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filterlistmodel.hxx>
#include <libmm/gtk/filterlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFilterListModel* object, bool take_copy) -> Glib::RefPtr<Gtk::FilterListModel>
  {
    return Glib::make_refptr_for_instance<Gtk::FilterListModel> (
        dynamic_cast<Gtk::FilterListModel*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FilterListModel_Class::init () -> const Glib::Class&
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
  FilterListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FilterListModel::FilterListModel (GtkFilterListModel* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FilterListModel::FilterListModel (FilterListModel&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src))
  {
  }

  auto
  FilterListModel::operator= (FilterListModel&& src) noexcept -> FilterListModel&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
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

  FilterListModel::FilterListModel (const Glib::RefPtr<Gio::ListModel>& model,
                                    const Glib::RefPtr<Filter>& filter)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (filterlistmodel_class_.init (),
                                           "model",
                                           Glib::unwrap (model),
                                           "filter",
                                           Glib::unwrap (filter),
                                           nullptr))
  {
  }

  auto
  FilterListModel::create (const Glib::RefPtr<Gio::ListModel>& model,
                           const Glib::RefPtr<Filter>& filter) -> Glib::RefPtr<FilterListModel>
  {
    return Glib::make_refptr_for_instance<FilterListModel> (
        new FilterListModel (model, filter));
  }

  auto
  FilterListModel::set_filter (const Glib::RefPtr<Filter>& filter) -> void
  {
    gtk_filter_list_model_set_filter (gobj (), Glib::unwrap (filter));
  }

  auto
  FilterListModel::get_filter () -> Glib::RefPtr<Filter>
  {
    auto retvalue = Glib::wrap (gtk_filter_list_model_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FilterListModel::get_filter () const -> Glib::RefPtr<const Filter>
  {
    return const_cast<FilterListModel*> (this)->get_filter ();
  }

  auto
  FilterListModel::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_filter_list_model_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  FilterListModel::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_filter_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FilterListModel::get_model () const -> Glib::RefPtr<const Gio::ListModel>
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
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Filter>>::value,
      "Type Glib::RefPtr<Filter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FilterListModel::property_filter () -> Glib::PropertyProxy<Glib::RefPtr<Filter>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FilterListModel::property_filter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>> (this, "filter");
  }

  auto
  FilterListModel::property_incremental () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "incremental");
  }

  auto
  FilterListModel::property_incremental () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "incremental");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FilterListModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FilterListModel::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  FilterListModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  FilterListModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  FilterListModel::property_pending () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "pending");
  }

} // namespace Gtk