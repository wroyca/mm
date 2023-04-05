// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/sortlistmodel.hxx>
#include <libmm/gtk/sortlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSortListModel* object, bool take_copy) -> glib::RefPtr<gtk::SortListModel>
  {
    return glib::make_refptr_for_instance<gtk::SortListModel> (
        dynamic_cast<gtk::SortListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SortListModel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SortListModel_Class::class_init_function;

      gtype_ = gtk_sort_list_model_get_type ();
    }

    return *this;
  }

  auto
  SortListModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SortListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SortListModel ((GtkSortListModel*) object);
  }

  auto
  SortListModel::gobj_copy () -> GtkSortListModel*
  {
    reference ();
    return gobj ();
  }

  SortListModel::SortListModel (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SortListModel::SortListModel (GtkSortListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SortListModel::SortListModel (SortListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  SortListModel::operator= (SortListModel&& src) noexcept -> SortListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  SortListModel::~SortListModel () noexcept {}

  SortListModel::CppClassType SortListModel::sortlistmodel_class_;

  auto
  SortListModel::get_type () -> GType
  {
    return sortlistmodel_class_.init ().get_type ();
  }

  auto
  SortListModel::get_base_type () -> GType
  {
    return gtk_sort_list_model_get_type ();
  }

  SortListModel::SortListModel (const glib::RefPtr<gio::ListModel>& model,
                                const glib::RefPtr<Sorter>& sorter)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (sortlistmodel_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           "sorter",
                                           glib::unwrap (sorter),
                                           nullptr))
  {
  }

  auto
  SortListModel::create (const glib::RefPtr<gio::ListModel>& model,
                         const glib::RefPtr<Sorter>& sorter) -> glib::RefPtr<SortListModel>
  {
    return glib::make_refptr_for_instance<SortListModel> (
        new SortListModel (model, sorter));
  }

  auto
  SortListModel::set_sorter (const glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_sort_list_model_set_sorter (gobj (), glib::unwrap (sorter));
  }

  auto
  SortListModel::get_sorter () -> glib::RefPtr<Sorter>
  {
    auto retvalue = glib::wrap (gtk_sort_list_model_get_sorter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SortListModel::get_sorter () const -> glib::RefPtr<const Sorter>
  {
    return const_cast<SortListModel*> (this)->get_sorter ();
  }

  auto
  SortListModel::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_sort_list_model_set_model (gobj (), glib::unwrap (model));
  }

  auto
  SortListModel::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_sort_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SortListModel::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<SortListModel*> (this)->get_model ();
  }

  auto
  SortListModel::set_incremental (bool incremental) -> void
  {
    gtk_sort_list_model_set_incremental (gobj (),
                                         static_cast<int> (incremental));
  }

  auto
  SortListModel::get_incremental () const -> bool
  {
    return gtk_sort_list_model_get_incremental (
        const_cast<GtkSortListModel*> (gobj ()));
  }

  auto
  SortListModel::get_pending () const -> guint
  {
    return gtk_sort_list_model_get_pending (
        const_cast<GtkSortListModel*> (gobj ()));
  }

  auto
  SortListModel::property_incremental () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "incremental");
  }

  auto
  SortListModel::property_incremental () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "incremental");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SortListModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SortListModel::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  SortListModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  SortListModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  SortListModel::property_pending () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "pending");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Sorter>>::value,
      "Type glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SortListModel::property_sorter () -> glib::PropertyProxy<glib::RefPtr<Sorter>>
  {
    return glib::PropertyProxy<glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  SortListModel::property_sorter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>> (this, "sorter");
  }

} // namespace gtk
