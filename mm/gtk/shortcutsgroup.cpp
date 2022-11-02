// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/shortcutsgroup.hpp>
#include <mm/gtk/private/shortcutsgroup_p.hpp>


/* Copyright (C) 2016 The gtkmm Development Team
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

namespace Gtk
{
void ShortcutsGroup::unset_view()
{
  // Set gtk+'s char* to nullptr.
  property_view().reset_value();
}
} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcutsGroup* object, bool take_copy) -> Gtk::ShortcutsGroup*
{
  return dynamic_cast<Gtk::ShortcutsGroup *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutsGroup_Class::init() -> const Glib::Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutsGroup_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_shortcuts_group_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void ShortcutsGroup_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutsGroup_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ShortcutsGroup((GtkShortcutsGroup*)(o)));

}


/* The implementation: */

ShortcutsGroup::ShortcutsGroup(const Glib::ConstructParams& construct_params)
:
  Box(construct_params)
{
  }

ShortcutsGroup::ShortcutsGroup(GtkShortcutsGroup* castitem)
:
  Box((GtkBox*)(castitem))
{
  }


ShortcutsGroup::ShortcutsGroup(ShortcutsGroup&& src) noexcept
: Box(std::move(src))
{}

auto ShortcutsGroup::operator=(ShortcutsGroup&& src) noexcept -> ShortcutsGroup&
{
  Box::operator=(std::move(src));
  return *this;
}

ShortcutsGroup::~ShortcutsGroup() noexcept
{
  destroy_();
}

ShortcutsGroup::CppClassType ShortcutsGroup::shortcutsgroup_class_; // initialize static member

auto ShortcutsGroup::get_type() -> GType
{
  return shortcutsgroup_class_.init().get_type();
}


auto ShortcutsGroup::get_base_type() -> GType
{
  return gtk_shortcuts_group_get_type();
}


ShortcutsGroup::ShortcutsGroup()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Box(Glib::ConstructParams(shortcutsgroup_class_.init()))
{


}


auto ShortcutsGroup::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "title");
}

auto ShortcutsGroup::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "title");
}

auto ShortcutsGroup::property_view() -> Glib::PropertyProxy< Glib::ustring >
{
  return Glib::PropertyProxy< Glib::ustring >(this, "view");
}

auto ShortcutsGroup::property_view() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "view");
}


} // namespace Gtk


