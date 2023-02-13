


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/singleselection.hxx>
#include <libmm-gtk/singleselection_p.hxx>


/* Copyright (C) 2019 The gtkmm Development Team
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

auto wrap(GtkSingleSelection* object, const bool take_copy) -> RefPtr<Gtk::SingleSelection>
{
  return Glib::make_refptr_for_instance<Gtk::SingleSelection>( dynamic_cast<Gtk::SingleSelection*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SingleSelection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SingleSelection_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_single_selection_get_type();

  }

  return *this;
}


auto SingleSelection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SingleSelection_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SingleSelection((GtkSingleSelection*)object);
}


/* The implementation: */

auto SingleSelection::gobj_copy() -> GtkSingleSelection*
{
  reference();
  return gobj();
}

SingleSelection::SingleSelection(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SingleSelection::SingleSelection(GtkSingleSelection* castitem)
: Object((GObject*)castitem)
{}


SingleSelection::SingleSelection(SingleSelection&& src) noexcept
: Object(std::move(src))
  ,
  ListModel(std::move(src))
  , SelectionModel(std::move(src))
{}

auto SingleSelection::operator=(SingleSelection&& src) noexcept -> SingleSelection&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  SelectionModel::operator=(std::move(src));
  return *this;
}


SingleSelection::~SingleSelection() noexcept = default;

SingleSelection::CppClassType SingleSelection::singleselection_class_; // initialize static member

auto SingleSelection::get_type() -> GType
{
  return singleselection_class_.init().get_type();
}


auto SingleSelection::get_base_type() -> GType
{
  return gtk_single_selection_get_type();
}


SingleSelection::SingleSelection()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(singleselection_class_.init()))
{


}

SingleSelection::SingleSelection(const Glib::RefPtr<ListModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(singleselection_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto SingleSelection::create() -> Glib::RefPtr<SingleSelection>
{
  return Glib::make_refptr_for_instance<SingleSelection>( new SingleSelection() );
}

auto SingleSelection::create(const Glib::RefPtr<ListModel>& model) -> Glib::RefPtr<SingleSelection>
{
  return Glib::make_refptr_for_instance<SingleSelection>( new SingleSelection(model) );
}

auto SingleSelection::get_model() -> Glib::RefPtr<ListModel>
{
  auto retvalue = Glib::wrap(gtk_single_selection_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SingleSelection::get_model() const -> Glib::RefPtr<const ListModel>
{
  return const_cast<SingleSelection*>(this)->get_model();
}

auto SingleSelection::set_model (const Glib::RefPtr <ListModel> &model) -> void
{
  gtk_single_selection_set_model(gobj(), Glib::unwrap(model));
}

auto SingleSelection::get_selected() const -> guint
{
  return gtk_single_selection_get_selected(const_cast<GtkSingleSelection*>(gobj()));
}

auto SingleSelection::set_selected (
  const guint position) -> void
{
  gtk_single_selection_set_selected(gobj(), position);
}

auto SingleSelection::get_selected_item() -> Glib::RefPtr<ObjectBase>
{
  auto retvalue = Glib::make_refptr_for_instance<ObjectBase>(Glib::wrap_auto(G_OBJECT(gtk_single_selection_get_selected_item(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto SingleSelection::get_selected_item() const -> Glib::RefPtr<const ObjectBase>
{
  return const_cast<SingleSelection*>(this)->get_selected_item();
}

auto SingleSelection::get_autoselect() const -> bool
{
  return gtk_single_selection_get_autoselect(const_cast<GtkSingleSelection*>(gobj()));
}

auto SingleSelection::set_autoselect (
  const bool autoselect) -> void
{
  gtk_single_selection_set_autoselect(gobj(), autoselect);
}

auto SingleSelection::get_can_unselect() const -> bool
{
  return gtk_single_selection_get_can_unselect(const_cast<GtkSingleSelection*>(gobj()));
}

auto SingleSelection::set_can_unselect (
  const bool can_unselect) -> void
{
  gtk_single_selection_set_can_unselect(gobj(), can_unselect);
}


auto SingleSelection::property_autoselect() -> Glib::PropertyProxy< bool >
{
  return {this, "autoselect"};
}

auto SingleSelection::property_autoselect() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "autoselect"};
}

auto SingleSelection::property_can_unselect() -> Glib::PropertyProxy< bool >
{
  return {this, "can-unselect"};
}

auto SingleSelection::property_can_unselect() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "can-unselect"};
}

auto SingleSelection::property_selected() -> Glib::PropertyProxy< guint >
{
  return {this, "selected"};
}

auto SingleSelection::property_selected() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "selected"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Glib::ObjectBase>>::value,
  "Type Glib::RefPtr<Glib::ObjectBase> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SingleSelection::property_selected_item() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ObjectBase> >
{
  return {this, "selected-item"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SingleSelection::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SingleSelection::property_model() -> Glib::PropertyProxy< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SingleSelection::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListModel> >
{
  return {this, "model"};
}

auto SingleSelection::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}


} // namespace Gtk


