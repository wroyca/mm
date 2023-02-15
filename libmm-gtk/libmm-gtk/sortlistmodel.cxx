// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/sortlistmodel.hxx>
#include <libmm-gtk/sortlistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSortListModel* object, bool take_copy) -> Glib::RefPtr<Gtk::SortListModel>
  {
    return Glib::make_refptr_for_instance<Gtk::SortListModel> (
        dynamic_cast<Gtk::SortListModel*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SortListModel_Class::init () -> const Glib::Class&
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
  SortListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SortListModel ((GtkSortListModel*) object);
  }

  auto
  SortListModel::gobj_copy () -> GtkSortListModel*
  {
    reference ();
    return gobj ();
  }

  SortListModel::SortListModel (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  SortListModel::SortListModel (GtkSortListModel* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  SortListModel::SortListModel (SortListModel&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src))
  {
  }

  auto
  SortListModel::operator= (SortListModel&& src) noexcept -> SortListModel&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
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

  SortListModel::SortListModel (const Glib::RefPtr<Gio::ListModel>& model,
                                const Glib::RefPtr<Sorter>& sorter)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (sortlistmodel_class_.init (),
                                           "model",
                                           Glib::unwrap (model),
                                           "sorter",
                                           Glib::unwrap (sorter),
                                           nullptr))
  {
  }

  auto
  SortListModel::create (const Glib::RefPtr<Gio::ListModel>& model,
                         const Glib::RefPtr<Sorter>& sorter) -> Glib::RefPtr<SortListModel>
  {
    return Glib::make_refptr_for_instance<SortListModel> (
        new SortListModel (model, sorter));
  }

  auto
  SortListModel::set_sorter (const Glib::RefPtr<Sorter>& sorter) -> void
  {
    gtk_sort_list_model_set_sorter (gobj (), Glib::unwrap (sorter));
  }

  auto
  SortListModel::get_sorter () -> Glib::RefPtr<Sorter>
  {
    auto retvalue = Glib::wrap (gtk_sort_list_model_get_sorter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SortListModel::get_sorter () const -> Glib::RefPtr<const Sorter>
  {
    return const_cast<SortListModel*> (this)->get_sorter ();
  }

  auto
  SortListModel::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_sort_list_model_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  SortListModel::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_sort_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SortListModel::get_model () const -> Glib::RefPtr<const Gio::ListModel>
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
  SortListModel::property_incremental () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "incremental");
  }

  auto
  SortListModel::property_incremental () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "incremental");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SortListModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SortListModel::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  SortListModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  SortListModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  SortListModel::property_pending () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "pending");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Sorter>>::value,
      "Type Glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SortListModel::property_sorter () -> Glib::PropertyProxy<Glib::RefPtr<Sorter>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Sorter>> (this, "sorter");
  }

  auto
  SortListModel::property_sorter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>> (this, "sorter");
  }

} // namespace Gtk
