


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/multiselection.hxx>
#include <libmm-gtk/multiselection_p.hxx>


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

auto wrap(GtkMultiSelection* object, const bool take_copy) -> RefPtr<Gtk::MultiSelection>
{
  return Glib::make_refptr_for_instance<Gtk::MultiSelection>( dynamic_cast<Gtk::MultiSelection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto MultiSelection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MultiSelection_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_multi_selection_get_type();

  }

  return *this;
}


auto MultiSelection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MultiSelection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MultiSelection((GtkMultiSelection*)object);
}


/* The implementation: */

auto MultiSelection::gobj_copy() -> GtkMultiSelection*
{
  reference();
  return gobj();
}

MultiSelection::MultiSelection(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MultiSelection::MultiSelection(GtkMultiSelection* castitem)
: Object((GObject*)castitem)
{}


MultiSelection::MultiSelection(MultiSelection&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
  , SelectionModel(std::move(src))
{}

auto MultiSelection::operator=(MultiSelection&& src) noexcept -> MultiSelection&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  SelectionModel::operator=(std::move(src));
  return *this;
}


MultiSelection::~MultiSelection() noexcept = default;

MultiSelection::CppClassType MultiSelection::multiselection_class_; // initialize static member

auto MultiSelection::get_type() -> GType
{
  return multiselection_class_.init().get_type();
}


auto MultiSelection::get_base_type() -> GType
{
  return gtk_multi_selection_get_type();
}


MultiSelection::MultiSelection()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(multiselection_class_.init()))
{


}

MultiSelection::MultiSelection(const Glib::RefPtr<ListModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(multiselection_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto MultiSelection::create() -> Glib::RefPtr<MultiSelection>
{
  return Glib::make_refptr_for_instance<MultiSelection>( new MultiSelection() );
}

auto MultiSelection::create(const Glib::RefPtr<ListModel>& model) -> Glib::RefPtr<MultiSelection>
{
  return Glib::make_refptr_for_instance<MultiSelection>( new MultiSelection(model) );
}

auto MultiSelection::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_multi_selection_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto MultiSelection::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<MultiSelection*>(this)->get_model();
}

auto MultiSelection::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_multi_selection_set_model(gobj(), Glib::unwrap(model));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MultiSelection::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MultiSelection::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto MultiSelection::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto MultiSelection::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}


} // namespace Gtk


