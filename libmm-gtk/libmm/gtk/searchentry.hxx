// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SEARCHENTRY_H
#define _GTKMM_SEARCHENTRY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/entry.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSearchEntry = struct _GtkSearchEntry;
using GtkSearchEntryClass = struct _GtkSearchEntryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SearchEntry_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SearchEntry : public Entry
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef SearchEntry CppObjectType;
    typedef SearchEntry_Class CppClassType;
    typedef GtkSearchEntry BaseObjectType;
    typedef GtkSearchEntryClass BaseClassType;
#endif

    SearchEntry (SearchEntry&& src) noexcept;
    auto
    operator= (SearchEntry&& src) noexcept -> SearchEntry&;

    SearchEntry (const SearchEntry&) = delete;
    auto
    operator= (const SearchEntry&) -> SearchEntry& = delete;

    ~SearchEntry () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class SearchEntry_Class;
    static CppClassType searchentry_class_;

  protected:
    explicit SearchEntry (const glib::ConstructParams& construct_params);
    explicit SearchEntry (GtkSearchEntry* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSearchEntry*
    {
      return reinterpret_cast<GtkSearchEntry*> (gobject_);
    }

    auto
    gobj () const -> const GtkSearchEntry*
    {
      return reinterpret_cast<GtkSearchEntry*> (gobject_);
    }

  private:
  public:
    SearchEntry ();

    auto
    set_key_capture_widget (Widget& widget) -> void;

    auto
    get_key_capture_widget () -> Widget*;

    auto
    get_key_capture_widget () const -> const Widget*;
    auto
    unset_key_capture_widget () -> void;

    auto
    set_search_delay (unsigned int delay) -> void;

    auto
    get_search_delay () const -> unsigned int;

    auto
    signal_search_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_next_match () -> glib::SignalProxy<void ()>;

    auto
    signal_previous_match () -> glib::SignalProxy<void ()>;

    auto
    signal_stop_search () -> glib::SignalProxy<void ()>;

    auto
    signal_search_started () -> glib::SignalProxy<void ()>;

    auto
    property_placeholder_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_placeholder_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_activates_default () -> glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_search_delay () -> glib::PropertyProxy<unsigned int>;

    auto
    property_search_delay () const
        -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSearchEntry* object, bool take_copy = false) -> gtk::SearchEntry*;
} // namespace glib

#endif
