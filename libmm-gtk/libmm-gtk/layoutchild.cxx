


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/layoutchild.hxx>
#include <libmm-gtk/layoutchild_p.hxx>


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

#include <libmm-gtk/layoutmanager.hxx>
#include <libmm-gtk/widget.hxx>
#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkLayoutChild* object, const bool take_copy) -> RefPtr<Gtk::LayoutChild>
{
  return Glib::make_refptr_for_instance<Gtk::LayoutChild>( dynamic_cast<Gtk::LayoutChild*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto LayoutChild_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LayoutChild_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_layout_child_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto LayoutChild_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto LayoutChild_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new LayoutChild((GtkLayoutChild*)object);
}


/* The implementation: */

auto LayoutChild::gobj_copy() -> GtkLayoutChild*
{
  reference();
  return gobj();
}

LayoutChild::LayoutChild(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

LayoutChild::LayoutChild(GtkLayoutChild* castitem)
: Object((GObject*)castitem)
{}


LayoutChild::LayoutChild(LayoutChild&& src) noexcept
: Object(std::move(src))
{}

auto LayoutChild::operator=(LayoutChild&& src) noexcept -> LayoutChild&
{
  Object::operator=(std::move(src));
  return *this;
}


LayoutChild::~LayoutChild() noexcept = default;

LayoutChild::CppClassType LayoutChild::layoutchild_class_; // initialize static member

auto LayoutChild::get_type() -> GType
{
  return layoutchild_class_.init().get_type();
}


auto LayoutChild::get_base_type() -> GType
{
  return gtk_layout_child_get_type();
}


LayoutChild::LayoutChild()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(layoutchild_class_.init()))
{


}

auto LayoutChild::get_layout_manager() -> Glib::RefPtr<LayoutManager>
{
  auto retvalue = Glib::wrap(gtk_layout_child_get_layout_manager(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutChild::get_layout_manager() const -> Glib::RefPtr<const LayoutManager>
{
  return const_cast<LayoutChild*>(this)->get_layout_manager();
}

auto LayoutChild::get_child_widget() -> Widget*
{
  return Glib::wrap(gtk_layout_child_get_child_widget(gobj()));
}

auto LayoutChild::get_child_widget() const -> const Widget*
{
  return const_cast<LayoutChild*>(this)->get_child_widget();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<LayoutManager>>::value,
  "Type Glib::RefPtr<LayoutManager> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto LayoutChild::property_layout_manager() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<LayoutManager> >
{
  return {this, "layout-manager"};
}

auto LayoutChild::property_child_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child-widget"};
}


} // namespace Gtk

