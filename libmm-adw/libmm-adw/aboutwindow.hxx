// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ABOUTWINDOW_H
#define _LIBADWAITAMM_ABOUTWINDOW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/window.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class AboutWindow_Class;
}
#endif

namespace Adw
{

  class AboutWindow : public Adw::Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AboutWindow CppObjectType;
    typedef AboutWindow_Class CppClassType;
    typedef AdwAboutWindow BaseObjectType;
    typedef AdwAboutWindowClass BaseClassType;
#endif

    AboutWindow (AboutWindow&& src) noexcept;
    auto
    operator= (AboutWindow&& src) noexcept -> AboutWindow&;

    AboutWindow (const AboutWindow&) = delete;
    auto
    operator= (const AboutWindow&) -> AboutWindow& = delete;

    ~AboutWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class AboutWindow_Class;
    static CppClassType aboutwindow_class_;

  protected:
    explicit AboutWindow (const Glib::ConstructParams& construct_params);
    explicit AboutWindow (AdwAboutWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwAboutWindow*
    {
      return reinterpret_cast<AdwAboutWindow*> (gobject_);
    }

    auto
    gobj () const -> const AdwAboutWindow*
    {
      return reinterpret_cast<AdwAboutWindow*> (gobject_);
    }

  private:
  public:
    AboutWindow ();

    auto
    get_application_icon () const -> Glib::ustring;

    auto
    get_application_name () const -> Glib::ustring;

    auto
    get_comments () const -> Glib::ustring;

    auto
    get_copyright () const -> Glib::ustring;

    auto
    get_debug_info () const -> Glib::ustring;

    auto
    get_debug_info_filename () const -> Glib::ustring;

    auto
    get_developer_name () const -> Glib::ustring;

    auto
    get_issue_url () const -> Glib::ustring;

    auto
    get_license () const -> Glib::ustring;

    auto
    get_release_notes () const -> Glib::ustring;

    auto
    get_release_notes_version () const -> Glib::ustring;

    auto
    get_support_url () const -> Glib::ustring;

    auto
    get_translator_credits () const -> Glib::ustring;

    auto
    get_version () const -> Glib::ustring;

    auto
    get_website () const -> Glib::ustring;

    auto
    get_license_type () const -> Gtk::License;

    auto
    get_artists () const -> std::vector<Glib::ustring>;

    auto
    get_designers () const -> std::vector<Glib::ustring>;

    auto
    get_developers () const -> std::vector<Glib::ustring>;

    auto
    get_documenters () const -> std::vector<Glib::ustring>;

    auto
    add_acknowledgement_section (const Glib::ustring& name,
                                 const std::vector<Glib::ustring>& people)
        -> void;

    auto
    add_credit_section (const Glib::ustring& name,
                        const std::vector<Glib::ustring>& people) -> void;

    auto
    add_legal_section (const Glib::ustring& title,
                       const Glib::ustring& copyright,
                       Gtk::License license_type,
                       const Glib::ustring& license) -> void;

    auto
    add_link (const Glib::ustring& title, const Glib::ustring& url) -> void;

    auto
    set_application_icon (const Glib::ustring& application_icon) -> void;

    auto
    set_application_name (const Glib::ustring& application_name) -> void;

    auto
    set_artists (const std::vector<Glib::ustring>& artists) -> void;

    auto
    set_comments (const Glib::ustring& comments) -> void;

    auto
    set_copyright (const Glib::ustring& copyright) -> void;

    auto
    set_debug_info (const Glib::ustring& debug_info) -> void;

    auto
    set_debug_info_filename (const Glib::ustring& filename) -> void;

    auto
    set_designers (const std::vector<Glib::ustring>& designers) -> void;

    auto
    set_developer_name (const Glib::ustring& developer_name) -> void;

    auto
    set_developers (const std::vector<Glib::ustring>& developers) -> void;

    auto
    set_documenters (const std::vector<Glib::ustring>& documenters) -> void;

    auto
    set_issue_url (const Glib::ustring& issue_url) -> void;

    auto
    set_license (const Glib::ustring& license) -> void;

    auto
    set_license_type (Gtk::License license_type) -> void;

    auto
    set_release_notes (const Glib::ustring& release_notes) -> void;

    auto
    set_release_notes_version (const Glib::ustring& version) -> void;

    auto
    set_support_url (const Glib::ustring& support_url) -> void;

    auto
    set_translator_credits (const Glib::ustring& translator_credits) -> void;

    auto
    set_version (const Glib::ustring& version) -> void;

    auto
    set_website (const Glib::ustring& website) -> void;

    auto
    property_support_url () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_support_url () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_application_icon () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_application_icon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_translator_credits () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_translator_credits () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_copyright () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_copyright () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_release_notes () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_release_notes () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_designers () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_designers () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_application_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_application_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_developer_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_developer_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_documenters () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_documenters () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_debug_info () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_debug_info () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_website () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_website () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_version () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_version () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_comments () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_comments () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_release_notes_version () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_release_notes_version () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_license () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_license () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_license_type () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_license_type () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_developers () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_developers () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_issue_url () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_issue_url () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_artists () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_artists () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_debug_info_filename () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_debug_info_filename () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    signal_activate_link () -> Glib::SignalProxy<bool (const Glib::ustring&)>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwAboutWindow* object, bool take_copy = false) -> Adw::AboutWindow*;
}

#endif
