// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESWINDOW_H
#define _LIBADWAITAMM_PREFERENCESWINDOW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/window.hxx>

#include <adwaita.h>
#include <libmm-adw/preferencespage.hxx>
#include <libmm-adw/toast.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class PreferencesWindow_Class;
}
#endif

namespace Adw
{

  class PreferencesWindow : public Adw::Window
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
    explicit PreferencesWindow (const Glib::ConstructParams& construct_params);
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
    get_visible_page_name () const -> Glib::ustring;

    auto
    present_subpage (Gtk::Widget* subpage) -> void;

    auto
    remove (PreferencesPage* page) -> void;

    auto
    set_can_navigate_back (bool can_navigate_back) -> void;

    auto
    set_search_enabled (bool search_enabled) -> void;

    auto
    set_visible_page (PreferencesPage* page) -> void;

    auto
    set_visible_page_name (const Glib::ustring& name) -> void;

    auto
    property_can_navigate_back () -> Glib::PropertyProxy<bool>;

    auto
    property_can_navigate_back () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_search_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_search_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_page () -> Glib::PropertyProxy<PreferencesPage*>;

    auto
    property_visible_page () const
        -> Glib::PropertyProxy_ReadOnly<PreferencesPage*>;

    auto
    property_visible_page_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_visible_page_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwPreferencesWindow* object, bool take_copy = false) -> Adw::PreferencesWindow*;
}

#endif
