// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESWINDOW_H
#define _LIBADWAITAMM_PREFERENCESWINDOW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/window.hxx>

#include <adwaita.h>
#include <libmm/adw/preferencespage.hxx>
#include <libmm/adw/toast.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT preferences_window_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_window : public adw::window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = preferences_window;
    using CppClassType = preferences_window_class;
    using BaseObjectType = AdwPreferencesWindow;
    using BaseClassType = AdwPreferencesWindowClass;
#endif

    preferences_window (preferences_window&& src) noexcept;
    auto
    operator= (preferences_window&& src) noexcept -> preferences_window&;

    preferences_window (const preferences_window&) = delete;
    auto
    operator= (const preferences_window&) -> preferences_window& = delete;

    ~preferences_window () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class preferences_window_class;
    static CppClassType preferenceswindow_class_;

  protected:
    explicit preferences_window (const glib::ConstructParams& construct_params);
    explicit preferences_window (AdwPreferencesWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPreferencesWindow*
    {
      return reinterpret_cast<AdwPreferencesWindow*> (gobject_);
    }

    auto
    gobj () const -> const AdwPreferencesWindow*
    {
      return reinterpret_cast<AdwPreferencesWindow*> (gobject_);
    }

  private:
  public:
    preferences_window ();

    auto
    add (preferences_page* page) -> void;

    auto
    add_toast (toast* toast) -> void;

    auto
    close_subpage () -> void;

    auto
    get_can_navigate_back () const -> bool;

    auto
    get_search_enabled () const -> bool;

    auto
    get_visible_page () const -> preferences_page*;

    auto
    get_visible_page_name () const -> glib::ustring;

    auto
    present_subpage (gtk::Widget* subpage) -> void;

    auto
    remove (preferences_page* page) -> void;

    auto
    set_can_navigate_back (bool can_navigate_back) -> void;

    auto
    set_search_enabled (bool search_enabled) -> void;

    auto
    set_visible_page (preferences_page* page) -> void;

    auto
    set_visible_page_name (const glib::ustring& name) -> void;

    auto
    property_can_navigate_back () -> glib::PropertyProxy<bool>;

    auto
    property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_search_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_search_enabled () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_page () -> glib::PropertyProxy<preferences_page*>;

    auto
    property_visible_page () const
        -> glib::PropertyProxy_ReadOnly<preferences_page*>;

    auto
    property_visible_page_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_visible_page_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwPreferencesWindow* object, bool take_copy = false) -> adw::preferences_window*;
}

#endif
