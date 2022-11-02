// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/selectionfiltermodel.hpp>
#include <mm/gtk/private/selectionfiltermodel_p.hpp>


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

auto wrap(GtkSelectionFilterModel* object, bool take_copy) -> Glib::RefPtr<Gtk::SelectionFilterModel>
{
  return Glib::make_refptr_for_instance<Gtk::SelectionFilterModel>( dynamic_cast<Gtk::SelectionFilterModel*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SelectionFilterModel_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SelectionFilterModel_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_selection_filter_model_get_type();

  }

  return *this;
}


auto SelectionFilterModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SelectionFilterModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SelectionFilterModel((GtkSelectionFilterModel*)object);
}


/* The implementation: */

auto SelectionFilterModel::gobj_copy() -> GtkSelectionFilterModel*
{
  reference();
  return gobj();
}

SelectionFilterModel::SelectionFilterModel(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

SelectionFilterModel::SelectionFilterModel(GtkSelectionFilterModel* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


SelectionFilterModel::SelectionFilterModel(SelectionFilterModel&& src) noexcept
: Glib::Object(std::move(src))
  , Gio::ListModel(std::move(src))
{}

auto SelectionFilterModel::operator=(SelectionFilterModel&& src) noexcept -> SelectionFilterModel&
{
  Glib::Object::operator=(std::move(src));
  Gio::ListModel::operator=(std::move(src));
  return *this;
}


SelectionFilterModel::~SelectionFilterModel() noexcept
{}


SelectionFilterModel::CppClassType SelectionFilterModel::selectionfiltermodel_class_; // initialize static member

auto SelectionFilterModel::get_type() -> GType
{
  return selectionfiltermodel_class_.init().get_type();
}


auto SelectionFilterModel::get_base_type() -> GType
{
  return gtk_selection_filter_model_get_type();
}


SelectionFilterModel::SelectionFilterModel(const Glib::RefPtr<SelectionModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(selectionfiltermodel_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto SelectionFilterModel::create(const Glib::RefPtr<SelectionModel>& model) -> Glib::RefPtr<SelectionFilterModel>
{
  return Glib::make_refptr_for_instance<SelectionFilterModel>( new SelectionFilterModel(model) );
}

auto SelectionFilterModel::set_model (const Glib::RefPtr <SelectionModel> &model) -> void
{
  gtk_selection_filter_model_set_model(gobj(), Glib::unwrap(model));
}

auto SelectionFilterModel::get_model() -> Glib::RefPtr<SelectionModel>
{
  auto retvalue = Glib::wrap(gtk_selection_filter_model_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SelectionFilterModel::get_model() const -> Glib::RefPtr<const SelectionModel>
{
  return const_cast<SelectionFilterModel*>(this)->get_model();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SelectionFilterModel::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return Glib::PropertyProxy_ReadOnly< GType >(this, "item-type");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SelectionModel>>::value,
  "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SelectionFilterModel::property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >
{
  return Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >(this, "model");
}

auto SelectionFilterModel::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >(this, "model");
}

auto SelectionFilterModel::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "n-items");
}


} // namespace Gtk


