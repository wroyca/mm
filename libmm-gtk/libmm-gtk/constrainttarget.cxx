


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/constrainttarget.hxx>
#include <libmm-gtk/constrainttarget_p.hxx>


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

auto wrap(GtkConstraintTarget* object, const bool take_copy) -> RefPtr<Gtk::ConstraintTarget>
{
  return Glib::make_refptr_for_instance<Gtk::ConstraintTarget>( Glib::wrap_auto_interface<Gtk::ConstraintTarget> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto ConstraintTarget_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &ConstraintTarget_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_constraint_target_get_type();
  }

  return *this;
}

auto ConstraintTarget_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto ConstraintTarget_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ConstraintTarget((GtkConstraintTarget*)object);
}


/* The implementation: */

ConstraintTarget::ConstraintTarget()
: Interface(constrainttarget_class_.init())
{}

ConstraintTarget::ConstraintTarget(GtkConstraintTarget* castitem)
: Interface((GObject*)castitem)
{}

ConstraintTarget::ConstraintTarget(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

ConstraintTarget::ConstraintTarget(ConstraintTarget&& src) noexcept
: Interface(std::move(src))
{}

auto ConstraintTarget::operator=(ConstraintTarget&& src) noexcept -> ConstraintTarget&
{
  Interface::operator=(std::move(src));
  return *this;
}

ConstraintTarget::~ConstraintTarget() noexcept = default;

// static
auto ConstraintTarget::add_interface (
  const GType gtype_implementer) -> void
{
  constrainttarget_class_.init().add_interface(gtype_implementer);
}

ConstraintTarget::CppClassType ConstraintTarget::constrainttarget_class_; // initialize static member

auto ConstraintTarget::get_type() -> GType
{
  return constrainttarget_class_.init().get_type();
}


auto ConstraintTarget::get_base_type() -> GType
{
  return gtk_constraint_target_get_type();
}


} // namespace Gtk


