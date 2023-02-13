


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/multifilter.hpp>
#include <libmm-gtk/multifilter_p.hpp>


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

auto wrap(GtkMultiFilter* object, const bool take_copy) -> RefPtr<Gtk::MultiFilter>
{
  return Glib::make_refptr_for_instance<Gtk::MultiFilter>( dynamic_cast<Gtk::MultiFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto MultiFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MultiFilter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_multi_filter_get_type();

  }

  return *this;
}


auto MultiFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MultiFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MultiFilter((GtkMultiFilter*)object);
}


/* The implementation: */

auto MultiFilter::gobj_copy() -> GtkMultiFilter*
{
  reference();
  return gobj();
}

MultiFilter::MultiFilter(const Glib::ConstructParams& construct_params)
: Filter(construct_params)
{

}

MultiFilter::MultiFilter(GtkMultiFilter* castitem)
: Filter((GtkFilter*)castitem)
{}


MultiFilter::MultiFilter(MultiFilter&& src) noexcept
: Filter(std::move(src))
  ,
  ListModel(std::move(src))
  , Buildable(std::move(src))
{}

auto MultiFilter::operator=(MultiFilter&& src) noexcept -> MultiFilter&
{
  Filter::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


MultiFilter::~MultiFilter() noexcept = default;

MultiFilter::CppClassType MultiFilter::multifilter_class_; // initialize static member

auto MultiFilter::get_type() -> GType
{
  return multifilter_class_.init().get_type();
}


auto MultiFilter::get_base_type() -> GType
{
  return gtk_multi_filter_get_type();
}


MultiFilter::MultiFilter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Filter(Glib::ConstructParams(multifilter_class_.init()))
{


}

auto MultiFilter::append (const Glib::RefPtr <Filter> &filter) -> void
{
  gtk_multi_filter_append(gobj(), unwrap_copy(filter));
}

auto MultiFilter::remove (
  const guint position) -> void
{
  gtk_multi_filter_remove(gobj(), position);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto MultiFilter::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

auto MultiFilter::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkAnyFilter* object, const bool take_copy) -> RefPtr<Gtk::AnyFilter>
{
  return Glib::make_refptr_for_instance<Gtk::AnyFilter>( dynamic_cast<Gtk::AnyFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto AnyFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AnyFilter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_any_filter_get_type();

  }

  return *this;
}


auto AnyFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AnyFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new AnyFilter((GtkAnyFilter*)object);
}


/* The implementation: */

auto AnyFilter::gobj_copy() -> GtkAnyFilter*
{
  reference();
  return gobj();
}

AnyFilter::AnyFilter(const Glib::ConstructParams& construct_params)
: MultiFilter(construct_params)
{

}

AnyFilter::AnyFilter(GtkAnyFilter* castitem)
: MultiFilter((GtkMultiFilter*)castitem)
{}


AnyFilter::AnyFilter(AnyFilter&& src) noexcept
: MultiFilter(std::move(src))
{}

auto AnyFilter::operator=(AnyFilter&& src) noexcept -> AnyFilter&
{
  MultiFilter::operator=(std::move(src));
  return *this;
}


AnyFilter::~AnyFilter() noexcept = default;

AnyFilter::CppClassType AnyFilter::anyfilter_class_; // initialize static member

auto AnyFilter::get_type() -> GType
{
  return anyfilter_class_.init().get_type();
}


auto AnyFilter::get_base_type() -> GType
{
  return gtk_any_filter_get_type();
}

AnyFilter::AnyFilter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
MultiFilter(Glib::ConstructParams(anyfilter_class_.init()))
{


}

auto AnyFilter::create() -> Glib::RefPtr<AnyFilter>
{
  return Glib::make_refptr_for_instance<AnyFilter>( new AnyFilter() );
}


} // namespace Gtk


namespace Glib
{

auto wrap(GtkEveryFilter* object, const bool take_copy) -> RefPtr<Gtk::EveryFilter>
{
  return Glib::make_refptr_for_instance<Gtk::EveryFilter>( dynamic_cast<Gtk::EveryFilter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto EveryFilter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EveryFilter_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_every_filter_get_type();

  }

  return *this;
}


auto EveryFilter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EveryFilter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EveryFilter((GtkEveryFilter*)object);
}


/* The implementation: */

auto EveryFilter::gobj_copy() -> GtkEveryFilter*
{
  reference();
  return gobj();
}

EveryFilter::EveryFilter(const Glib::ConstructParams& construct_params)
: MultiFilter(construct_params)
{

}

EveryFilter::EveryFilter(GtkEveryFilter* castitem)
: MultiFilter((GtkMultiFilter*)castitem)
{}


EveryFilter::EveryFilter(EveryFilter&& src) noexcept
: MultiFilter(std::move(src))
{}

auto EveryFilter::operator=(EveryFilter&& src) noexcept -> EveryFilter&
{
  MultiFilter::operator=(std::move(src));
  return *this;
}


EveryFilter::~EveryFilter() noexcept = default;

EveryFilter::CppClassType EveryFilter::everyfilter_class_; // initialize static member

auto EveryFilter::get_type() -> GType
{
  return everyfilter_class_.init().get_type();
}


auto EveryFilter::get_base_type() -> GType
{
  return gtk_every_filter_get_type();
}

EveryFilter::EveryFilter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
MultiFilter(Glib::ConstructParams(everyfilter_class_.init()))
{


}

auto EveryFilter::create() -> Glib::RefPtr<EveryFilter>
{
  return Glib::make_refptr_for_instance<EveryFilter>( new EveryFilter() );
}


} // namespace Gtk


