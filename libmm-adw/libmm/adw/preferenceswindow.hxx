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
  class LIBMM_ADW_SYMEXPORT PreferencesWindow_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesWindow : public adw::Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PreferencesWindow CppObjectType;
    typedef PreferencesWindow_Class CppClassType;
    typedef AdwPreferencesWindow BaseObjectType;
    typedef AdwPreferencesWindowClass BaseClassType;
#endif

    PreferencesWindow (PreferencesWindow&& src) noexcept;
    auto
    operator= (PreferencesWindow&& src) noexcept -> PreferencesWindow&;

    PreferencesWindow (const PreferencesWindow&) = delete;
    auto
    operator= (const PreferencesWindow&) -> PreferencesWindow& = delete;

    ~PreferencesWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class PreferencesWindow_Class;
    static CppClassType preferenceswindow_class_;

  protected:
    explicit PreferencesWindow (const glib::ConstructParams& construct_params);
    explicit PreferencesWindow (AdwPreferencesWindow* castitem);

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
    PreferencesWindow ();

    auto
    add (PreferencesPage* page) -> void;

    auto
    add_toast (Toast* toast) -> void;

    auto
    close_subpage () -> void;

    auto
    get_can_navigate_back () const -> bool;

    auto
    get_search_enabled () const -> bool;

    auto
    get_visible_page () const -> PreferencesPage*;

    auto
    get_visible_page_name () const -> glib::ustring;

    auto
    present_subpage (gtk::Widget* subpage) -> void;

    auto
    remove (PreferencesPage* page) -> void;

    auto
    set_can_navigate_back (bool can_navigate_back) -> void;

    auto
    set_search_enabled (bool search_enabled) -> void;

    auto
    set_visible_page (PreferencesPage* page) -> void;

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
    property_visible_page () -> glib::PropertyProxy<PreferencesPage*>;

    auto
    property_visible_page () const
        -> glib::PropertyProxy_ReadOnly<PreferencesPage*>;

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
  wrap (AdwPreferencesWindow* object, bool take_copy = false) -> adw::PreferencesWindow*;
}

#endif
