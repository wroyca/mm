// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SEARCHBAR_H
#define _GTKMM_SEARCHBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSearchBar = struct _GtkSearchBar;
using GtkSearchBarClass = struct _GtkSearchBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT SearchBar_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT SearchBar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef SearchBar CppObjectType;
    typedef SearchBar_Class CppClassType;
    typedef GtkSearchBar BaseObjectType;
    typedef GtkSearchBarClass BaseClassType;
#endif

    SearchBar (SearchBar&& src) noexcept;
    auto
    operator= (SearchBar&& src) noexcept -> SearchBar&;

    SearchBar (const SearchBar&) = delete;
    auto
    operator= (const SearchBar&) -> SearchBar& = delete;

    ~SearchBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class SearchBar_Class;
    static CppClassType searchbar_class_;

  protected:
    explicit SearchBar (const Glib::ConstructParams& construct_params);
    explicit SearchBar (GtkSearchBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSearchBar*
    {
      return reinterpret_cast<GtkSearchBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkSearchBar*
    {
      return reinterpret_cast<GtkSearchBar*> (gobject_);
    }

  private:
  public:
    SearchBar ();

    auto
    connect_entry (Editable& entry) -> void;

    auto
    get_search_mode () const -> bool;

    auto
    set_search_mode (bool search_mode = true) -> void;

    auto
    get_show_close_button () const -> bool;

    auto
    set_show_close_button (bool visible = true) -> void;

    auto
    set_key_capture_widget (Widget& widget) -> void;

    auto
    get_key_capture_widget () -> Widget*;

    auto
    get_key_capture_widget () const -> const Widget*;
    auto
    unset_key_capture_widget () -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_search_mode_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_search_mode_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_close_button () -> Glib::PropertyProxy<bool>;

    auto
    property_show_close_button () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_key_capture_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_key_capture_widget () const
        -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSearchBar* object, bool take_copy = false) -> Gtk::SearchBar*;
} // namespace Glib

#endif
