


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/shortcutsshortcut.hpp>
#include <libmm-gtk/shortcutsshortcut_p.hpp>


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

// static
auto Glib::Value<Gtk::ShortcutType>::value_type() -> GType
{
  return gtk_shortcut_type_get_type();
}


namespace Glib
{

auto wrap(GtkShortcutsShortcut* object, const bool take_copy) -> Gtk::ShortcutsShortcut*
{
  return dynamic_cast<Gtk::ShortcutsShortcut *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ShortcutsShortcut_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ShortcutsShortcut_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_shortcuts_shortcut_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto ShortcutsShortcut_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ShortcutsShortcut_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ShortcutsShortcut((GtkShortcutsShortcut*)o));

}


/* The implementation: */

ShortcutsShortcut::ShortcutsShortcut(const Glib::ConstructParams& construct_params)
:
  Widget(construct_params)
{
  }

ShortcutsShortcut::ShortcutsShortcut(GtkShortcutsShortcut* castitem)
:
  Widget((GtkWidget*)castitem)
{
  }


ShortcutsShortcut::ShortcutsShortcut(ShortcutsShortcut&& src) noexcept
: Widget(std::move(src))
{}

auto ShortcutsShortcut::operator=(ShortcutsShortcut&& src) noexcept -> ShortcutsShortcut&
{
  Widget::operator=(std::move(src));
  return *this;
}

ShortcutsShortcut::~ShortcutsShortcut() noexcept
{
  destroy_();
}

ShortcutsShortcut::CppClassType ShortcutsShortcut::shortcutsshortcut_class_; // initialize static member

auto ShortcutsShortcut::get_type() -> GType
{
  return shortcutsshortcut_class_.init().get_type();
}


auto ShortcutsShortcut::get_base_type() -> GType
{
  return gtk_shortcuts_shortcut_get_type();
}


ShortcutsShortcut::ShortcutsShortcut()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(shortcutsshortcut_class_.init()))
{


}


auto ShortcutsShortcut::property_accelerator() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "accelerator"};
}

auto ShortcutsShortcut::property_accelerator() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "accelerator"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Icon>>::value,
  "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ShortcutsShortcut::property_icon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >
{
  return {this, "icon"};
}

auto ShortcutsShortcut::property_icon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >
{
  return {this, "icon"};
}

auto ShortcutsShortcut::property_icon_set() -> Glib::PropertyProxy< bool >
{
  return {this, "icon-set"};
}

auto ShortcutsShortcut::property_icon_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "icon-set"};
}

auto ShortcutsShortcut::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto ShortcutsShortcut::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto ShortcutsShortcut::property_subtitle() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "subtitle"};
}

auto ShortcutsShortcut::property_subtitle() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "subtitle"};
}

auto ShortcutsShortcut::property_subtitle_set() -> Glib::PropertyProxy< bool >
{
  return {this, "subtitle-set"};
}

auto ShortcutsShortcut::property_subtitle_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "subtitle-set"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
  "Type TextDirection cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ShortcutsShortcut::property_direction() -> Glib::PropertyProxy< TextDirection >
{
  return {this, "direction"};
}

auto ShortcutsShortcut::property_direction() const -> Glib::PropertyProxy_ReadOnly< TextDirection >
{
  return {this, "direction"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<ShortcutType>::value,
  "Type ShortcutType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ShortcutsShortcut::property_shortcut_type() -> Glib::PropertyProxy< ShortcutType >
{
  return {this, "shortcut-type"};
}

auto ShortcutsShortcut::property_shortcut_type() const -> Glib::PropertyProxy_ReadOnly< ShortcutType >
{
  return {this, "shortcut-type"};
}

auto ShortcutsShortcut::property_action_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "action-name"};
}

auto ShortcutsShortcut::property_action_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "action-name"};
}


} // namespace Gtk


