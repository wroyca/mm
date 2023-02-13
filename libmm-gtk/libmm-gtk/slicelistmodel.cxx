


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/slicelistmodel.hxx>
#include <libmm-gtk/slicelistmodel_p.hxx>


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

auto wrap(GtkSliceListModel* object, const bool take_copy) -> RefPtr<Gtk::SliceListModel>
{
  return Glib::make_refptr_for_instance<Gtk::SliceListModel>( dynamic_cast<Gtk::SliceListModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SliceListModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SliceListModel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_slice_list_model_get_type();

  }

  return *this;
}


auto SliceListModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SliceListModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SliceListModel((GtkSliceListModel*)object);
}


/* The implementation: */

auto SliceListModel::gobj_copy() -> GtkSliceListModel*
{
  reference();
  return gobj();
}

SliceListModel::SliceListModel(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SliceListModel::SliceListModel(GtkSliceListModel* castitem)
: Object((GObject*)castitem)
{}


SliceListModel::SliceListModel(SliceListModel&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
{}

auto SliceListModel::operator=(SliceListModel&& src) noexcept -> SliceListModel&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


SliceListModel::~SliceListModel() noexcept = default;

SliceListModel::CppClassType SliceListModel::slicelistmodel_class_; // initialize static member

auto SliceListModel::get_type() -> GType
{
  return slicelistmodel_class_.init().get_type();
}


auto SliceListModel::get_base_type() -> GType
{
  return gtk_slice_list_model_get_type();
}


SliceListModel::SliceListModel(const Glib::RefPtr<ListModel>& model, const guint offset, const guint size)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(slicelistmodel_class_.init(), "model", Glib::unwrap(model), "offset", offset, "size", size, nullptr))
{


}

auto SliceListModel::create(const Glib::RefPtr<ListModel>& model, const guint offset, const guint size) -> Glib::RefPtr<SliceListModel>
{
  return Glib::make_refptr_for_instance<SliceListModel>( new SliceListModel(model, offset, size) );
}

auto SliceListModel::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_slice_list_model_set_model(gobj(), Glib::unwrap(model));
}

auto SliceListModel::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_slice_list_model_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SliceListModel::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<SliceListModel*>(this)->get_model();
}

auto SliceListModel::set_offset (
  const guint offset) -> void
{
  gtk_slice_list_model_set_offset(gobj(), offset);
}

auto SliceListModel::get_offset() const -> guint
{
  return gtk_slice_list_model_get_offset(const_cast<GtkSliceListModel*>(gobj()));
}

auto SliceListModel::set_size (
  const guint size) -> void
{
  gtk_slice_list_model_set_size(gobj(), size);
}

auto SliceListModel::get_size() const -> guint
{
  return gtk_slice_list_model_get_size(const_cast<GtkSliceListModel*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SliceListModel::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SliceListModel::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SliceListModel::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SliceListModel::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}

auto SliceListModel::property_offset() -> Glib::PropertyProxy< guint >
{
  return {this, "offset"};
}

auto SliceListModel::property_offset() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "offset"};
}

auto SliceListModel::property_size() -> Glib::PropertyProxy< guint >
{
  return {this, "size"};
}

auto SliceListModel::property_size() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "size"};
}


} // namespace Gtk


