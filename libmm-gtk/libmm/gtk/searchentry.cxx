// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/searchentry.hxx>
#include <libmm/gtk/searchentry_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  SearchEntry::unset_key_capture_widget () -> void
  {
    gtk_search_entry_set_key_capture_widget (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo SearchEntry_signal_search_changed_info = {
      "search-changed",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SearchEntry_signal_next_match_info = {
      "next-match",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SearchEntry_signal_previous_match_info = {
      "previous-match",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SearchEntry_signal_stop_search_info = {
      "stop-search",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo SearchEntry_signal_search_started_info = {
      "search-started",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkSearchEntry* object, bool take_copy) -> gtk::SearchEntry*
  {
    return dynamic_cast<gtk::SearchEntry*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  SearchEntry_Class::init () -> const glib::Class&
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
  SearchEntry_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new SearchEntry ((GtkSearchEntry*) (o)));
  }

  SearchEntry::SearchEntry (const glib::ConstructParams& construct_params)
    : gtk::Entry (construct_params)
  {
  }

  SearchEntry::SearchEntry (GtkSearchEntry* castitem)
    : gtk::Entry ((GtkEntry*) (castitem))
  {
  }

  SearchEntry::SearchEntry (SearchEntry&& src) noexcept
    : gtk::Entry (std::move (src))
  {
  }

  auto
  SearchEntry::operator= (SearchEntry&& src) noexcept -> SearchEntry&
  {
    gtk::Entry::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Entry (glib::ConstructParams (searchentry_class_.init ()))
  {
  }

  auto
  SearchEntry::set_key_capture_widget (Widget& widget) -> void
  {
    gtk_search_entry_set_key_capture_widget (gobj (), (widget).gobj ());
  }

  auto
  SearchEntry::get_key_capture_widget () -> Widget*
  {
    return glib::wrap (gtk_search_entry_get_key_capture_widget (gobj ()));
  }

  auto
  SearchEntry::get_key_capture_widget () const -> const Widget*
  {
    return const_cast<SearchEntry*> (this)->get_key_capture_widget ();
  }

  auto
  SearchEntry::set_search_delay (unsigned int delay) -> void
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
  SearchEntry::signal_search_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SearchEntry_signal_search_changed_info);
  }

  auto
  SearchEntry::signal_next_match () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SearchEntry_signal_next_match_info);
  }

  auto
  SearchEntry::signal_previous_match () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SearchEntry_signal_previous_match_info);
  }

  auto
  SearchEntry::signal_stop_search () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SearchEntry_signal_stop_search_info);
  }

  auto
  SearchEntry::signal_search_started () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &SearchEntry_signal_search_started_info);
  }

  auto
  SearchEntry::property_placeholder_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "placeholder-text");
  }

  auto
  SearchEntry::property_placeholder_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "placeholder-text");
  }

  auto
  SearchEntry::property_activates_default () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  SearchEntry::property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  SearchEntry::property_search_delay () -> glib::PropertyProxy<unsigned int>
  {
    return glib::PropertyProxy<unsigned int> (this, "search-delay");
  }

  auto
  SearchEntry::property_search_delay () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "search-delay");
  }

} // namespace gtk
