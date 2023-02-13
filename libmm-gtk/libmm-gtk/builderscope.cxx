


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/builderscope.hxx>
#include <libmm-gtk/builderscope_p.hxx>


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
#include <libmm-gtk/builder.hxx>

namespace Gtk
{

// Allow GtkBuilder to instantiate a gtkmm derived GType instead of the regular
// GTK GType, so we can, for instance, use our vfuncs and default signal handlers.
// static
auto BuilderScope_Class::get_type_from_name_vfunc_callback(
  GtkBuilderScope* self, GtkBuilder* builder, const char* type_name) -> GType
{
  if (!type_name)
    return G_TYPE_INVALID;

  GType gtype = G_TYPE_INVALID;

  // If a TreeModel (such as ListStore or TreeStore) is being built,
  // Buildable_Class may have requested no search for gtkmm-derived types.
  // See https://bugzilla.gnome.org/show_bug.cgi?id=742637
  const auto obj = dynamic_cast<Builder*>(
    Glib::ObjectBase::_get_current_wrapper((GObject*)builder));
  if (!(obj && obj->no_gtkmm_derived_types))
  {
    // See if there is a gtkmm version of the gclass:
    Glib::ustring classname_prefixed ("gtkmm__"); // gtkmm uses a prefix
    classname_prefixed += type_name;

    gtype = g_type_from_name(classname_prefixed.c_str());
  }

  if (gtype == G_TYPE_INVALID) // If it's not a registered typename
  {
    const auto base = static_cast<BaseClassType*>(
      // Get the parent interface of the interface (The original underlying C interface).
      g_type_interface_peek_parent(
      // Get the interface.
      g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type())));

    // Call the original underlying C function.
    if (base && base->get_type_from_name)
      gtype = (*base->get_type_from_name)(self, builder, type_name);
    else // If that's not possible, just use the normal GType.
      gtype = g_type_from_name(type_name);
  }

  return gtype;
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkBuilderScope* object, const bool take_copy) -> RefPtr<Gtk::BuilderScope>
{
  return Glib::make_refptr_for_instance<Gtk::BuilderScope>( Glib::wrap_auto_interface<Gtk::BuilderScope> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto BuilderScope_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &BuilderScope_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_builder_scope_get_type();
  }

  return *this;
}

auto BuilderScope_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->get_type_from_name = &get_type_from_name_vfunc_callback;

}


auto BuilderScope_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new BuilderScope((GtkBuilderScope*)object);
}


/* The implementation: */

BuilderScope::BuilderScope()
: Interface(builderscope_class_.init())
{}

BuilderScope::BuilderScope(GtkBuilderScope* castitem)
: Interface((GObject*)castitem)
{}

BuilderScope::BuilderScope(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

BuilderScope::BuilderScope(BuilderScope&& src) noexcept
: Interface(std::move(src))
{}

auto BuilderScope::operator=(BuilderScope&& src) noexcept -> BuilderScope&
{
  Interface::operator=(std::move(src));
  return *this;
}

BuilderScope::~BuilderScope() noexcept = default;

// static
auto BuilderScope::add_interface (
  const GType gtype_implementer) -> void
{
  builderscope_class_.init().add_interface(gtype_implementer);
}

BuilderScope::CppClassType BuilderScope::builderscope_class_; // initialize static member

auto BuilderScope::get_type() -> GType
{
  return builderscope_class_.init().get_type();
}


auto BuilderScope::get_base_type() -> GType
{
  return gtk_builder_scope_get_type();
}


} // namespace Gtk


