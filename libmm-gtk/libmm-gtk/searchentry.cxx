


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/searchentry.hpp>
#include <libmm-gtk/searchentry_p.hpp>


/* Copyright 2012 The gtkmm Development Team
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

auto SearchEntry::unset_key_capture_widget () -> void
{
  gtk_search_entry_set_key_capture_widget(gobj(), nullptr);
}

} // namespace Gtk

namespace
{


const Glib::SignalProxyInfo SearchEntry_signal_search_changed_info =
{
  "search-changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo SearchEntry_signal_next_match_info =
{
  "next-match",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo SearchEntry_signal_previous_match_info =
{
  "previous-match",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo SearchEntry_signal_stop_search_info =
{
  "stop-search",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


const Glib::SignalProxyInfo SearchEntry_signal_search_started_info =
{
  "search-started",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkSearchEntry* object, const bool take_copy) -> Gtk::SearchEntry*
{
  return dynamic_cast<Gtk::SearchEntry *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto SearchEntry_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SearchEntry_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_search_entry_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto SearchEntry_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto SearchEntry_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new SearchEntry((GtkSearchEntry*)o));

}


/* The implementation: */

SearchEntry::SearchEntry(const Glib::ConstructParams& construct_params)
: Entry(construct_params)
{
  }

SearchEntry::SearchEntry(GtkSearchEntry* castitem)
: Entry((GtkEntry*)castitem)
{
  }


SearchEntry::SearchEntry(SearchEntry&& src) noexcept
: Entry(std::move(src))
{}

auto SearchEntry::operator=(SearchEntry&& src) noexcept -> SearchEntry&
{
  Entry::operator=(std::move(src));
  return *this;
}

SearchEntry::~SearchEntry() noexcept
{
  destroy_();
}

SearchEntry::CppClassType SearchEntry::searchentry_class_; // initialize static member

auto SearchEntry::get_type() -> GType
{
  return searchentry_class_.init().get_type();
}


auto SearchEntry::get_base_type() -> GType
{
  return gtk_search_entry_get_type();
}


SearchEntry::SearchEntry()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Entry(Glib::ConstructParams(searchentry_class_.init()))
{


}

auto SearchEntry::set_key_capture_widget (Widget &widget) -> void
{
  gtk_search_entry_set_key_capture_widget(gobj(), widget.gobj());
}

auto SearchEntry::get_key_capture_widget() -> Widget*
{
  return Glib::wrap(gtk_search_entry_get_key_capture_widget(gobj()));
}

auto SearchEntry::get_key_capture_widget() const -> const Widget*
{
  return const_cast<SearchEntry*>(this)->get_key_capture_widget();
}

auto SearchEntry::set_search_delay (
  const unsigned int delay) -> void
{
  gtk_search_entry_set_search_delay(gobj(), delay);
}

auto SearchEntry::get_search_delay() const -> unsigned int
{
  return gtk_search_entry_get_search_delay(const_cast<GtkSearchEntry*>(gobj()));
}


auto SearchEntry::signal_search_changed() -> Glib::SignalProxy<void()>
{
  return {this, &SearchEntry_signal_search_changed_info};
}


auto SearchEntry::signal_next_match() -> Glib::SignalProxy<void()>
{
  return {this, &SearchEntry_signal_next_match_info};
}


auto SearchEntry::signal_previous_match() -> Glib::SignalProxy<void()>
{
  return {this, &SearchEntry_signal_previous_match_info};
}


auto SearchEntry::signal_stop_search() -> Glib::SignalProxy<void()>
{
  return {this, &SearchEntry_signal_stop_search_info};
}


auto SearchEntry::signal_search_started() -> Glib::SignalProxy<void()>
{
  return {this, &SearchEntry_signal_search_started_info};
}


auto SearchEntry::property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto SearchEntry::property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto SearchEntry::property_activates_default() -> Glib::PropertyProxy< bool >
{
  return {this, "activates-default"};
}

auto SearchEntry::property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activates-default"};
}

auto SearchEntry::property_search_delay() -> Glib::PropertyProxy< unsigned int >
{
  return {this, "search-delay"};
}

auto SearchEntry::property_search_delay() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "search-delay"};
}


} // namespace Gtk


