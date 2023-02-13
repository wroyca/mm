


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/accessible.hpp>
#include <mm/gtk/private/accessible_p.hpp>


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

using Role = Gtk::Accessible::Role;

namespace Gtk
{

auto Accessible::update_state (State state, const Glib::ValueBase &value) -> void
{
  auto c_state = static_cast<GtkAccessibleState>(state);
  gtk_accessible_update_state_value(gobj(), 1, &c_state, value.gobj());
}

auto Accessible::update_property (Property property, const Glib::ValueBase &value) -> void
{
  auto c_prop = static_cast<GtkAccessibleProperty>(property);
  gtk_accessible_update_property_value(gobj(), 1, &c_prop, value.gobj());
}

auto Accessible::update_relation (Relation relation, const Glib::ValueBase &value) -> void
{
  auto c_rel = static_cast<GtkAccessibleRelation>(relation);
  gtk_accessible_update_relation_value(gobj(), 1, &c_rel, value.gobj());
}

} // namespace Gtk

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::Accessible::Role>::value_type() -> GType
{
  return gtk_accessible_role_get_type();
}

// static
auto Glib::Value<Gtk::Accessible::State>::value_type() -> GType
{
  return gtk_accessible_state_get_type();
}

// static
auto Glib::Value<Gtk::Accessible::Property>::value_type() -> GType
{
  return gtk_accessible_property_get_type();
}

// static
auto Glib::Value<Gtk::Accessible::Relation>::value_type() -> GType
{
  return gtk_accessible_relation_get_type();
}


namespace Glib
{

auto wrap(GtkAccessible* object, const bool take_copy) -> RefPtr<Gtk::Accessible>
{
  return Glib::make_refptr_for_instance<Gtk::Accessible>( Glib::wrap_auto_interface<Gtk::Accessible> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto Accessible_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Accessible_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_accessible_get_type();
  }

  return *this;
}

auto Accessible_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Accessible_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Accessible((GtkAccessible*)object);
}


/* The implementation: */

Accessible::Accessible()
: Interface(accessible_class_.init())
{}

Accessible::Accessible(GtkAccessible* castitem)
: Interface((GObject*)castitem)
{}

Accessible::Accessible(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Accessible::Accessible(Accessible&& src) noexcept
: Interface(std::move(src))
{}

auto Accessible::operator=(Accessible&& src) noexcept -> Accessible&
{
  Interface::operator=(std::move(src));
  return *this;
}

Accessible::~Accessible() noexcept = default;

// static
auto Accessible::add_interface (
  const GType gtype_implementer) -> void
{
  accessible_class_.init().add_interface(gtype_implementer);
}

Accessible::CppClassType Accessible::accessible_class_; // initialize static member

auto Accessible::get_type() -> GType
{
  return accessible_class_.init().get_type();
}


auto Accessible::get_base_type() -> GType
{
  return gtk_accessible_get_type();
}


auto Accessible::get_accessible_role() const -> Role
{
  return static_cast<Role>(gtk_accessible_get_accessible_role(const_cast<GtkAccessible*>(gobj())));
}

auto Accessible::reset_state (State state) -> void
{
  gtk_accessible_reset_state(gobj(), static_cast<GtkAccessibleState>(state));
}

auto Accessible::reset_property (Property property) -> void
{
  gtk_accessible_reset_property(gobj(), static_cast<GtkAccessibleProperty>(property));
}

auto Accessible::reset_relation (Relation relation) -> void
{
  gtk_accessible_reset_relation(gobj(), static_cast<GtkAccessibleRelation>(relation));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Role>::value,
  "Type Role cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Accessible::property_accessible_role() -> Glib::PropertyProxy< Role >
{
  return {this, "accessible-role"};
}

auto Accessible::property_accessible_role() const -> Glib::PropertyProxy_ReadOnly< Role >
{
  return {this, "accessible-role"};
}


} // namespace Gtk


