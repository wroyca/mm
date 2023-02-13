


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/sizegroup.hpp>
#include <libmm-gtk/sizegroup_p.hpp>

#include <gtk/gtk.h>

/*
 * Copyright 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/vectorutils.hpp>

#include <gtk/gtk.h>

using Mode = Gtk::SizeGroup::Mode;

namespace Gtk
{

SizeGroup::SizeGroup(const Mode mode)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(sizegroup_class_.init(), "mode",mode, nullptr))
{}

} // namespace Gtk


namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::SizeGroup::Mode>::value_type() -> GType
{
  return gtk_size_group_mode_get_type();
}


namespace Glib
{

auto wrap(GtkSizeGroup* object, const bool take_copy) -> RefPtr<Gtk::SizeGroup>
{
  return Glib::make_refptr_for_instance<Gtk::SizeGroup>( dynamic_cast<Gtk::SizeGroup*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto SizeGroup_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SizeGroup_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_size_group_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Buildable::add_interface(get_type());

  }

  return *this;
}


auto SizeGroup_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SizeGroup_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new SizeGroup((GtkSizeGroup*)object);
}


/* The implementation: */

auto SizeGroup::gobj_copy() -> GtkSizeGroup*
{
  reference();
  return gobj();
}

SizeGroup::SizeGroup(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

SizeGroup::SizeGroup(GtkSizeGroup* castitem)
: Object((GObject*)castitem)
{}


SizeGroup::SizeGroup(SizeGroup&& src) noexcept
: Object(std::move(src))
  , Buildable(std::move(src))
{}

auto SizeGroup::operator=(SizeGroup&& src) noexcept -> SizeGroup&
{
  Object::operator=(std::move(src));
  Buildable::operator=(std::move(src));
  return *this;
}


SizeGroup::~SizeGroup() noexcept = default;

SizeGroup::CppClassType SizeGroup::sizegroup_class_; // initialize static member

auto SizeGroup::get_type() -> GType
{
  return sizegroup_class_.init().get_type();
}


auto SizeGroup::get_base_type() -> GType
{
  return gtk_size_group_get_type();
}


auto SizeGroup::create(
  const Mode mode) -> Glib::RefPtr<SizeGroup>
{
  return Glib::make_refptr_for_instance<SizeGroup>( new SizeGroup(mode) );
}

auto SizeGroup::set_mode (Mode mode) -> void
{
  gtk_size_group_set_mode(gobj(), static_cast<GtkSizeGroupMode>(mode));
}

auto SizeGroup::get_mode() const -> Mode
{
  return static_cast<Mode>(gtk_size_group_get_mode(const_cast<GtkSizeGroup*>(gobj())));
}

auto SizeGroup::add_widget (Widget &widget) -> void
{
  gtk_size_group_add_widget(gobj(), widget.gobj());
}

auto SizeGroup::remove_widget (Widget &widget) -> void
{
  gtk_size_group_remove_widget(gobj(), widget.gobj());
}

auto SizeGroup::get_widgets() -> std::vector<Widget*>
{
  return Glib::SListHandler<Widget*>::slist_to_vector(gtk_size_group_get_widgets(gobj()), Glib::OWNERSHIP_NONE);
}

auto SizeGroup::get_widgets() const -> std::vector<const Widget*>
{
  return Glib::SListHandler<const Widget*>::slist_to_vector(gtk_size_group_get_widgets(const_cast<GtkSizeGroup*>(gobj())), Glib::OWNERSHIP_NONE);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
  "Type Mode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto SizeGroup::property_mode() -> Glib::PropertyProxy< Mode >
{
  return {this, "mode"};
}

auto SizeGroup::property_mode() const -> Glib::PropertyProxy_ReadOnly< Mode >
{
  return {this, "mode"};
}


} // namespace Gtk


