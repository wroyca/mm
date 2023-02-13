


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/shortcutssection.hpp>
#include <mm/gtk/private/shortcutssection_p.hpp>


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
} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkShortcutsSection* object, const bool take_copy) -> Gtk::ShortcutsSection*
{
  return dynamic_cast<Gtk::ShortcutsSection *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutsSection_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutsSection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_shortcuts_section_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ShortcutsSection_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutsSection_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ShortcutsSection((GtkShortcutsSection*)o));

}


/* The implementation: */

ShortcutsSection::ShortcutsSection(const Glib::ConstructParams& construct_params)
:
  Box(construct_params)
{
  }

ShortcutsSection::ShortcutsSection(GtkShortcutsSection* castitem)
:
  Box((GtkBox*)castitem)
{
  }


ShortcutsSection::ShortcutsSection(ShortcutsSection&& src) noexcept
: Box(std::move(src))
{}

auto ShortcutsSection::operator=(ShortcutsSection&& src) noexcept -> ShortcutsSection&
{
  Box::operator=(std::move(src));
  return *this;
}

ShortcutsSection::~ShortcutsSection() noexcept
{
  destroy_();
}

ShortcutsSection::CppClassType ShortcutsSection::shortcutssection_class_; // initialize static member

auto ShortcutsSection::get_type() -> GType
{
  return shortcutssection_class_.init().get_type();
}


auto ShortcutsSection::get_base_type() -> GType
{
  return gtk_shortcuts_section_get_type();
}


ShortcutsSection::ShortcutsSection()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Box(Glib::ConstructParams(shortcutssection_class_.init()))
{


}


auto ShortcutsSection::property_section_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "section-name"};
}

auto ShortcutsSection::property_section_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "section-name"};
}

auto ShortcutsSection::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto ShortcutsSection::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto ShortcutsSection::property_max_height() -> Glib::PropertyProxy< unsigned int >
{
  return {this, "max-height"};
}

auto ShortcutsSection::property_max_height() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "max-height"};
}


} // namespace Gtk


