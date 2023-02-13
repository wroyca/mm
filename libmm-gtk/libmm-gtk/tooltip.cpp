


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/tooltip.hpp>
#include <mm/gtk/private/tooltip_p.hpp>


/*
 * Copyright (C) 2007 The gtkmm Development Team
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

#include <gtk/gtk.h>

namespace Gtk
{

auto Tooltip::unset_markup () -> void
{
  gtk_tooltip_set_markup(gobj(), nullptr);
}

auto Tooltip::unset_text () -> void
{
  gtk_tooltip_set_text(gobj(), nullptr);
}

auto Tooltip::unset_icon () -> void
{
  gtk_tooltip_set_icon(gobj(), nullptr);
}

auto Tooltip::unset_custom () -> void
{
  gtk_tooltip_set_custom(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTooltip* object, const bool take_copy) -> RefPtr<Gtk::Tooltip>
{
  return Glib::make_refptr_for_instance<Gtk::Tooltip>( dynamic_cast<Gtk::Tooltip*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto Tooltip_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Tooltip_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tooltip_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Tooltip_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Tooltip_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Tooltip((GtkTooltip*)object);
}


/* The implementation: */

auto Tooltip::gobj_copy() -> GtkTooltip*
{
  reference();
  return gobj();
}

Tooltip::Tooltip(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Tooltip::Tooltip(GtkTooltip* castitem)
: Object((GObject*)castitem)
{}


Tooltip::Tooltip(Tooltip&& src) noexcept
: Object(std::move(src))
{}

auto Tooltip::operator=(Tooltip&& src) noexcept -> Tooltip&
{
  Object::operator=(std::move(src));
  return *this;
}


Tooltip::~Tooltip() noexcept = default;

Tooltip::CppClassType Tooltip::tooltip_class_; // initialize static member

auto Tooltip::get_type() -> GType
{
  return tooltip_class_.init().get_type();
}


auto Tooltip::get_base_type() -> GType
{
  return gtk_tooltip_get_type();
}


auto Tooltip::set_markup (const Glib::ustring &markup) -> void
{
  gtk_tooltip_set_markup(gobj(), markup.c_str());
}

auto Tooltip::set_text (const Glib::ustring &text) -> void
{
  gtk_tooltip_set_text(gobj(), text.c_str());
}

auto Tooltip::set_icon (const Glib::RefPtr <Gdk::Paintable> &paintable) -> void
{
  gtk_tooltip_set_icon(gobj(), Glib::unwrap(paintable));
}

auto Tooltip::set_icon (const Glib::RefPtr <Gio::Icon> &gicon) -> void
{
  gtk_tooltip_set_icon_from_gicon(gobj(), Glib::unwrap<Gio::Icon>(gicon));
}

auto Tooltip::set_icon (const Glib::ustring &icon_name) -> void
{
  gtk_tooltip_set_icon_from_icon_name(gobj(), icon_name.empty() ? nullptr : icon_name.c_str());
}

auto Tooltip::set_custom (Widget &custom_widget) -> void
{
  gtk_tooltip_set_custom(gobj(), custom_widget.gobj());
}

auto Tooltip::set_tip_area (const Gdk::Rectangle &rect) -> void
{
  gtk_tooltip_set_tip_area(gobj(), rect.gobj());
}


} // namespace Gtk


