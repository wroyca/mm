


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/headerbar.hpp>
#include <mm/gtk/private/headerbar_p.hpp>


/*
 * Copyright 2013 The gtkmm Development Team
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

auto HeaderBar::unset_decoration_layout () -> void
{
  gtk_header_bar_set_decoration_layout(gobj(), nullptr);
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkHeaderBar* object, const bool take_copy) -> Gtk::HeaderBar*
{
  return dynamic_cast<Gtk::HeaderBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto HeaderBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &HeaderBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_header_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto HeaderBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto HeaderBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new HeaderBar((GtkHeaderBar*)o));

}


/* The implementation: */

HeaderBar::HeaderBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

HeaderBar::HeaderBar(GtkHeaderBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


HeaderBar::HeaderBar(HeaderBar&& src) noexcept
: Widget(std::move(src))
{}

auto HeaderBar::operator=(HeaderBar&& src) noexcept -> HeaderBar&
{
  Widget::operator=(std::move(src));
  return *this;
}

HeaderBar::~HeaderBar() noexcept
{
  destroy_();
}

HeaderBar::CppClassType HeaderBar::headerbar_class_; // initialize static member

auto HeaderBar::get_type() -> GType
{
  return headerbar_class_.init().get_type();
}


auto HeaderBar::get_base_type() -> GType
{
  return gtk_header_bar_get_type();
}


HeaderBar::HeaderBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(headerbar_class_.init()))
{


}

auto HeaderBar::set_title_widget (
  Widget &title_widget) -> void
{
  gtk_header_bar_set_title_widget(gobj(), title_widget.gobj());
}

auto HeaderBar::get_title_widget() -> Widget*
{
  return Glib::wrap(gtk_header_bar_get_title_widget(gobj()));
}

auto HeaderBar::get_title_widget() const -> const Widget*
{
  return const_cast<HeaderBar*>(this)->get_title_widget();
}

auto HeaderBar::pack_start (
  Widget &child) -> void
{
  gtk_header_bar_pack_start(gobj(), child.gobj());
}

auto HeaderBar::pack_end (
  Widget &child) -> void
{
  gtk_header_bar_pack_end(gobj(), child.gobj());
}

auto HeaderBar::remove (
  Widget &child) -> void
{
  gtk_header_bar_remove(gobj(), child.gobj());
}

auto HeaderBar::set_show_title_buttons (
  const bool setting) -> void
{
  gtk_header_bar_set_show_title_buttons(gobj(), setting);
}

auto HeaderBar::get_show_title_buttons() const -> bool
{
  return gtk_header_bar_get_show_title_buttons(const_cast<GtkHeaderBar*>(gobj()));
}

auto HeaderBar::set_decoration_layout (const Glib::ustring &layout) -> void
{
  gtk_header_bar_set_decoration_layout(gobj(), layout.c_str());
}

auto HeaderBar::get_decoration_layout() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_header_bar_get_decoration_layout(const_cast<GtkHeaderBar*>(gobj())));
}


auto HeaderBar::property_title_widget() -> Glib::PropertyProxy<Widget * >
{
  return {this, "title-widget"};
}

auto HeaderBar::property_title_widget() const -> Glib::PropertyProxy_ReadOnly<Widget * >
{
  return {this, "title-widget"};
}

auto HeaderBar::property_show_title_buttons() -> Glib::PropertyProxy< bool >
{
  return {this, "show-title-buttons"};
}

auto HeaderBar::property_show_title_buttons() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-title-buttons"};
}

auto HeaderBar::property_decoration_layout() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "decoration-layout"};
}

auto HeaderBar::property_decoration_layout() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "decoration-layout"};
}


} // namespace Gtk


