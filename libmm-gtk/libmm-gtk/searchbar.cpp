


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/searchbar.hpp>
#include <mm/gtk/private/searchbar_p.hpp>


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

auto SearchBar::unset_key_capture_widget () -> void
{
  gtk_search_bar_set_key_capture_widget(gobj(), nullptr);
}

auto SearchBar::unset_child () -> void
{
  gtk_search_bar_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkSearchBar* object, const bool take_copy) -> Gtk::SearchBar*
{
  return dynamic_cast<Gtk::SearchBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto SearchBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SearchBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_search_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SearchBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SearchBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new SearchBar((GtkSearchBar*)o));

}


/* The implementation: */

SearchBar::SearchBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

SearchBar::SearchBar(GtkSearchBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


SearchBar::SearchBar(SearchBar&& src) noexcept
: Widget(std::move(src))
{}

auto SearchBar::operator=(SearchBar&& src) noexcept -> SearchBar&
{
  Widget::operator=(std::move(src));
  return *this;
}

SearchBar::~SearchBar() noexcept
{
  destroy_();
}

SearchBar::CppClassType SearchBar::searchbar_class_; // initialize static member

auto SearchBar::get_type() -> GType
{
  return searchbar_class_.init().get_type();
}


auto SearchBar::get_base_type() -> GType
{
  return gtk_search_bar_get_type();
}


SearchBar::SearchBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(searchbar_class_.init()))
{


}

auto SearchBar::connect_entry (Editable &entry) -> void
{
  gtk_search_bar_connect_entry(gobj(), entry.gobj());
}

auto SearchBar::get_search_mode() const -> bool
{
  return gtk_search_bar_get_search_mode(const_cast<GtkSearchBar*>(gobj()));
}

auto SearchBar::set_search_mode (
  const bool search_mode) -> void
{
  gtk_search_bar_set_search_mode(gobj(), search_mode);
}

auto SearchBar::get_show_close_button() const -> bool
{
  return gtk_search_bar_get_show_close_button(const_cast<GtkSearchBar*>(gobj()));
}

auto SearchBar::set_show_close_button (
  const bool visible) -> void
{
  gtk_search_bar_set_show_close_button(gobj(), visible);
}

auto SearchBar::set_key_capture_widget (Widget &widget) -> void
{
  gtk_search_bar_set_key_capture_widget(gobj(), widget.gobj());
}

auto SearchBar::get_key_capture_widget() -> Widget*
{
  return Glib::wrap(gtk_search_bar_get_key_capture_widget(gobj()));
}

auto SearchBar::get_key_capture_widget() const -> const Widget*
{
  return const_cast<SearchBar*>(this)->get_key_capture_widget();
}

auto SearchBar::set_child (Widget &child) -> void
{
  gtk_search_bar_set_child(gobj(), child.gobj());
}

auto SearchBar::get_child() -> Widget*
{
  return Glib::wrap(gtk_search_bar_get_child(gobj()));
}

auto SearchBar::get_child() const -> const Widget*
{
  return const_cast<SearchBar*>(this)->get_child();
}


auto SearchBar::property_search_mode_enabled() -> Glib::PropertyProxy< bool >
{
  return {this, "search-mode-enabled"};
}

auto SearchBar::property_search_mode_enabled() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "search-mode-enabled"};
}

auto SearchBar::property_show_close_button() -> Glib::PropertyProxy< bool >
{
  return {this, "show-close-button"};
}

auto SearchBar::property_show_close_button() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-close-button"};
}

auto SearchBar::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto SearchBar::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}

auto SearchBar::property_key_capture_widget() -> Glib::PropertyProxy< Widget* >
{
  return {this, "key-capture-widget"};
}

auto SearchBar::property_key_capture_widget() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "key-capture-widget"};
}


} // namespace Gtk


