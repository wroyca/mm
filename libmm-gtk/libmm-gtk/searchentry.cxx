// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/searchentry.hxx>
#include <libmm-gtk/searchentry_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  SearchEntry::unset_key_capture_widget () -> void
  {
    gtk_search_entry_set_key_capture_widget (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{

  const Glib::SignalProxyInfo SearchEntry_signal_search_changed_info = {
      "search-changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo SearchEntry_signal_next_match_info = {
      "next-match",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo SearchEntry_signal_previous_match_info = {
      "previous-match",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo SearchEntry_signal_stop_search_info = {
      "stop-search",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo SearchEntry_signal_search_started_info = {
      "search-started",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkSearchEntry* object, const bool take_copy) -> Gtk::SearchEntry*
  {
    return dynamic_cast<Gtk::SearchEntry*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SearchEntry_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SearchEntry_Class::class_init_function;

      register_derived_type (gtk_search_entry_get_type ());
    }

    return *this;
  }

  auto
  SearchEntry_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SearchEntry_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new SearchEntry ((GtkSearchEntry*) o));
  }

  SearchEntry::SearchEntry (const Glib::ConstructParams& construct_params)
    : Entry (construct_params)
  {
  }

  SearchEntry::SearchEntry (GtkSearchEntry* castitem)
    : Entry ((GtkEntry*) castitem)
  {
  }

  SearchEntry::SearchEntry (SearchEntry&& src) noexcept
    : Entry (std::move (src))
  {
  }

  auto
  SearchEntry::operator= (SearchEntry&& src) noexcept -> SearchEntry&
  {
    Entry::operator= (std::move (src));
    return *this;
  }

  SearchEntry::~SearchEntry () noexcept
  {
    destroy_ ();
  }

  SearchEntry::CppClassType SearchEntry::searchentry_class_;

  auto
  SearchEntry::get_type () -> GType
  {
    return searchentry_class_.init ().get_type ();
  }

  auto
  SearchEntry::get_base_type () -> GType
  {
    return gtk_search_entry_get_type ();
  }

  SearchEntry::SearchEntry ()
    : ObjectBase (nullptr),
      Entry (Glib::ConstructParams (searchentry_class_.init ()))
  {
  }

  auto
  SearchEntry::set_key_capture_widget (Widget& widget) -> void
  {
    gtk_search_entry_set_key_capture_widget (gobj (), widget.gobj ());
  }

  auto
  SearchEntry::get_key_capture_widget () -> Widget*
  {
    return Glib::wrap (gtk_search_entry_get_key_capture_widget (gobj ()));
  }

  auto
  SearchEntry::get_key_capture_widget () const -> const Widget*
  {
    return const_cast<SearchEntry*> (this)->get_key_capture_widget ();
  }

  auto
  SearchEntry::set_search_delay (const unsigned int delay) -> void
  {
    gtk_search_entry_set_search_delay (gobj (), delay);
  }

  auto
  SearchEntry::get_search_delay () const -> unsigned int
  {
    return gtk_search_entry_get_search_delay (
        const_cast<GtkSearchEntry*> (gobj ()));
  }

  auto
  SearchEntry::signal_search_changed () -> Glib::SignalProxy<void ()>
  {
    return {this, &SearchEntry_signal_search_changed_info};
  }

  auto
  SearchEntry::signal_next_match () -> Glib::SignalProxy<void ()>
  {
    return {this, &SearchEntry_signal_next_match_info};
  }

  auto
  SearchEntry::signal_previous_match () -> Glib::SignalProxy<void ()>
  {
    return {this, &SearchEntry_signal_previous_match_info};
  }

  auto
  SearchEntry::signal_stop_search () -> Glib::SignalProxy<void ()>
  {
    return {this, &SearchEntry_signal_stop_search_info};
  }

  auto
  SearchEntry::signal_search_started () -> Glib::SignalProxy<void ()>
  {
    return {this, &SearchEntry_signal_search_started_info};
  }

  auto
  SearchEntry::property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "placeholder-text"};
  }

  auto
  SearchEntry::property_placeholder_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "placeholder-text"};
  }

  auto
  SearchEntry::property_activates_default () -> Glib::PropertyProxy<bool>
  {
    return {this, "activates-default"};
  }

  auto
  SearchEntry::property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "activates-default"};
  }

  auto
  SearchEntry::property_search_delay () -> Glib::PropertyProxy<unsigned int>
  {
    return {this, "search-delay"};
  }

  auto
  SearchEntry::property_search_delay () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "search-delay"};
  }

} // namespace Gtk
