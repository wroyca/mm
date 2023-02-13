


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filterlistmodel.hxx>
#include <libmm-gtk/filterlistmodel_p.hxx>


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

auto wrap(GtkFilterListModel* object, const bool take_copy) -> RefPtr<Gtk::FilterListModel>
{
  return Glib::make_refptr_for_instance<Gtk::FilterListModel>( dynamic_cast<Gtk::FilterListModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto FilterListModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FilterListModel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_filter_list_model_get_type();

  }

  return *this;
}


auto FilterListModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FilterListModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FilterListModel((GtkFilterListModel*)object);
}


/* The implementation: */

auto FilterListModel::gobj_copy() -> GtkFilterListModel*
{
  reference();
  return gobj();
}

FilterListModel::FilterListModel(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FilterListModel::FilterListModel(GtkFilterListModel* castitem)
: Object((GObject*)castitem)
{}


FilterListModel::FilterListModel(FilterListModel&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto FilterListModel::operator=(FilterListModel&& src) noexcept -> FilterListModel&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


FilterListModel::~FilterListModel() noexcept = default;

FilterListModel::CppClassType FilterListModel::filterlistmodel_class_; // initialize static member

auto FilterListModel::get_type() -> GType
{
  return filterlistmodel_class_.init().get_type();
}


auto FilterListModel::get_base_type() -> GType
{
  return gtk_filter_list_model_get_type();
}


FilterListModel::FilterListModel(const Glib::RefPtr<ListModel>& model, const Glib::RefPtr<Filter>& filter)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(filterlistmodel_class_.init(), "model", Glib::unwrap(model), "filter", Glib::unwrap(filter), nullptr))
{


}

auto FilterListModel::create(const Glib::RefPtr<ListModel>& model, const Glib::RefPtr<Filter>& filter) -> Glib::RefPtr<FilterListModel>
{
  return Glib::make_refptr_for_instance<FilterListModel>( new FilterListModel(model, filter) );
}

auto FilterListModel::set_filter (const Glib::RefPtr <Filter> &filter) -> void
{
  gtk_filter_list_model_set_filter(gobj(), Glib::unwrap(filter));
}

auto FilterListModel::get_filter() -> Glib::RefPtr<Filter>
{
  auto retvalue = Glib::wrap(gtk_filter_list_model_get_filter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FilterListModel::get_filter() const -> Glib::RefPtr<const Filter>
{
  return const_cast<FilterListModel*>(this)->get_filter();
}

auto FilterListModel::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_filter_list_model_set_model(gobj(), Glib::unwrap(model));
}

auto FilterListModel::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_filter_list_model_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FilterListModel::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<FilterListModel*>(this)->get_model();
}

auto FilterListModel::set_incremental (
  const bool incremental) -> void
{
  gtk_filter_list_model_set_incremental(gobj(), incremental);
}

auto FilterListModel::get_incremental() const -> bool
{
  return gtk_filter_list_model_get_incremental(const_cast<GtkFilterListModel*>(gobj()));
}

auto FilterListModel::get_pending() const -> guint
{
  return gtk_filter_list_model_get_pending(const_cast<GtkFilterListModel*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Filter>>::value,
  "Type Glib::RefPtr<Filter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FilterListModel::property_filter() -> Glib::PropertyProxy< Glib::RefPtr<Filter> >
{
  return {this, "filter"};
}

auto FilterListModel::property_filter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Filter> >
{
  return {this, "filter"};
}

auto FilterListModel::property_incremental() -> Glib::PropertyProxy< bool >
{
  return {this, "incremental"};
}

auto FilterListModel::property_incremental() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "incremental"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FilterListModel::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FilterListModel::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto FilterListModel::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto FilterListModel::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}

auto FilterListModel::property_pending() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "pending"};
}


} // namespace Gtk

