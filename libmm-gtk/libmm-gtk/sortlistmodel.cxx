


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/sortlistmodel.hxx>
#include <libmm-gtk/sortlistmodel_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkSortListModel* object, const bool take_copy) -> RefPtr<Gtk::SortListModel>
{
  return Glib::make_refptr_for_instance<Gtk::SortListModel>( dynamic_cast<Gtk::SortListModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SortListModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SortListModel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_sort_list_model_get_type();

  }

  return *this;
}


auto SortListModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SortListModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SortListModel((GtkSortListModel*)object);
}


/* The implementation: */

auto SortListModel::gobj_copy() -> GtkSortListModel*
{
  reference();
  return gobj();
}

SortListModel::SortListModel(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SortListModel::SortListModel(GtkSortListModel* castitem)
: Object((GObject*)castitem)
{}


SortListModel::SortListModel(SortListModel&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto SortListModel::operator=(SortListModel&& src) noexcept -> SortListModel&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


SortListModel::~SortListModel() noexcept = default;

SortListModel::CppClassType SortListModel::sortlistmodel_class_; // initialize static member

auto SortListModel::get_type() -> GType
{
  return sortlistmodel_class_.init().get_type();
}


auto SortListModel::get_base_type() -> GType
{
  return gtk_sort_list_model_get_type();
}


SortListModel::SortListModel(const Glib::RefPtr<ListModel>& model, const Glib::RefPtr<Sorter>& sorter)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(sortlistmodel_class_.init(), "model", Glib::unwrap(model), "sorter", Glib::unwrap(sorter), nullptr))
{


}

auto SortListModel::create(const Glib::RefPtr<ListModel>& model, const Glib::RefPtr<Sorter>& sorter) -> Glib::RefPtr<SortListModel>
{
  return Glib::make_refptr_for_instance<SortListModel>( new SortListModel(model, sorter) );
}

auto SortListModel::set_sorter (const Glib::RefPtr <Sorter> &sorter) -> void
{
  gtk_sort_list_model_set_sorter(gobj(), Glib::unwrap(sorter));
}

auto SortListModel::get_sorter() -> Glib::RefPtr<Sorter>
{
  auto retvalue = Glib::wrap(gtk_sort_list_model_get_sorter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SortListModel::get_sorter() const -> Glib::RefPtr<const Sorter>
{
  return const_cast<SortListModel*>(this)->get_sorter();
}

auto SortListModel::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_sort_list_model_set_model(gobj(), Glib::unwrap(model));
}

auto SortListModel::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_sort_list_model_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SortListModel::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<SortListModel*>(this)->get_model();
}

auto SortListModel::set_incremental (
  const bool incremental) -> void
{
  gtk_sort_list_model_set_incremental(gobj(), incremental);
}

auto SortListModel::get_incremental() const -> bool
{
  return gtk_sort_list_model_get_incremental(const_cast<GtkSortListModel*>(gobj()));
}

auto SortListModel::get_pending() const -> guint
{
  return gtk_sort_list_model_get_pending(const_cast<GtkSortListModel*>(gobj()));
}


auto SortListModel::property_incremental() -> Glib::PropertyProxy< bool >
{
  return {this, "incremental"};
}

auto SortListModel::property_incremental() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "incremental"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SortListModel::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SortListModel::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SortListModel::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SortListModel::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}

auto SortListModel::property_pending() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "pending"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Sorter>>::value,
  "Type Glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SortListModel::property_sorter() -> Glib::PropertyProxy< Glib::RefPtr<Sorter> >
{
  return {this, "sorter"};
}

auto SortListModel::property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >
{
  return {this, "sorter"};
}


} // namespace Gtk


