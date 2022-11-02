// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/multisorter.hpp>
#include <mm/gtk/private/multisorter_p.hpp>


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

auto wrap(GtkMultiSorter* object, bool take_copy) -> Glib::RefPtr<Gtk::MultiSorter>
{
  return Glib::make_refptr_for_instance<Gtk::MultiSorter>( dynamic_cast<Gtk::MultiSorter*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto MultiSorter_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MultiSorter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_multi_sorter_get_type();

  }

  return *this;
}


void MultiSorter_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MultiSorter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MultiSorter((GtkMultiSorter*)object);
}


/* The implementation: */

auto MultiSorter::gobj_copy() -> GtkMultiSorter*
{
  reference();
  return gobj();
}

MultiSorter::MultiSorter(const Glib::ConstructParams& construct_params)
:
  Gtk::Sorter(construct_params)
{

}

MultiSorter::MultiSorter(GtkMultiSorter* castitem)
:
  Gtk::Sorter((GtkSorter*)(castitem))
{}


MultiSorter::MultiSorter(MultiSorter&& src) noexcept
: Gtk::Sorter(std::move(src))
  , Gio::ListModel(std::move(src))
  , Buildable(std::move(src))
{}

auto MultiSorter::operator=(MultiSorter&& src) noexcept -> MultiSorter&
{
  Gtk::Sorter::operator=(std::move(src));
  Gio::ListModel::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


MultiSorter::~MultiSorter() noexcept
{}


MultiSorter::CppClassType MultiSorter::multisorter_class_; // initialize static member

auto MultiSorter::get_type() -> GType
{
  return multisorter_class_.init().get_type();
}


auto MultiSorter::get_base_type() -> GType
{
  return gtk_multi_sorter_get_type();
}


MultiSorter::MultiSorter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Sorter(Glib::ConstructParams(multisorter_class_.init()))
{


}

auto MultiSorter::create() -> Glib::RefPtr<MultiSorter>
{
  return Glib::make_refptr_for_instance<MultiSorter>( new MultiSorter() );
}

void MultiSorter::append(const Glib::RefPtr<Sorter>& sorter)
{
  gtk_multi_sorter_append(gobj(), Glib::unwrap_copy(sorter));
}

void MultiSorter::remove(guint position)
{
  gtk_multi_sorter_remove(gobj(), position);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MultiSorter::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return Glib::PropertyProxy_ReadOnly< GType >(this, "item-type");
}

auto MultiSorter::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return Glib::PropertyProxy_ReadOnly< unsigned int >(this, "n-items");
}


} // namespace Gtk


