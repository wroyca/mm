


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/flattenlistmodel.hpp>
#include <libmm-gtk/flattenlistmodel_p.hpp>


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

auto wrap(GtkFlattenListModel* object, const bool take_copy) -> RefPtr<Gtk::FlattenListModel>
{
  return Glib::make_refptr_for_instance<Gtk::FlattenListModel>( dynamic_cast<Gtk::FlattenListModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto FlattenListModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FlattenListModel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_flatten_list_model_get_type();

  }

  return *this;
}


auto FlattenListModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FlattenListModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FlattenListModel((GtkFlattenListModel*)object);
}


/* The implementation: */

auto FlattenListModel::gobj_copy() -> GtkFlattenListModel*
{
  reference();
  return gobj();
}

FlattenListModel::FlattenListModel(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FlattenListModel::FlattenListModel(GtkFlattenListModel* castitem)
: Object((GObject*)castitem)
{}


FlattenListModel::FlattenListModel(FlattenListModel&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto FlattenListModel::operator=(FlattenListModel&& src) noexcept -> FlattenListModel&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


FlattenListModel::~FlattenListModel() noexcept = default;

FlattenListModel::CppClassType FlattenListModel::flattenlistmodel_class_; // initialize static member

auto FlattenListModel::get_type() -> GType
{
  return flattenlistmodel_class_.init().get_type();
}


auto FlattenListModel::get_base_type() -> GType
{
  return gtk_flatten_list_model_get_type();
}


FlattenListModel::FlattenListModel(const Glib::RefPtr<ListModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(flattenlistmodel_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto FlattenListModel::create(const Glib::RefPtr<ListModel>& model) -> Glib::RefPtr<FlattenListModel>
{
  return Glib::make_refptr_for_instance<FlattenListModel>( new FlattenListModel(model) );
}

auto FlattenListModel::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_flatten_list_model_set_model(gobj(), Glib::unwrap(model));
}

auto FlattenListModel::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_flatten_list_model_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FlattenListModel::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<FlattenListModel*>(this)->get_model();
}

auto FlattenListModel::get_model_for_item(
  const guint position) -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_flatten_list_model_get_model_for_item(gobj(), position));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FlattenListModel::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FlattenListModel::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto FlattenListModel::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto FlattenListModel::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}


} // namespace Gtk


