// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <libmm/adw/window.hxx>
#include <libmm/adw/export.hxx>

#include <libmm/glib/ustring.hxx>

#include <adwaita.h>

namespace adw
{
  class LIBMM_ADW_SYMEXPORT about_window_class;
  class LIBMM_ADW_SYMEXPORT about_window : public Window
  {
    using cpp_object_type = about_window;
    using cpp_class_type = about_window_class;
    using base_object_type = AdwAboutWindow;
    using base_class_type = AdwAboutWindowClass;

  public:
    about_window ();
    about_window (about_window &&src) noexcept;
    about_window (const about_window &) = delete;
   ~about_window () noexcept override;

    auto operator= (about_window &&src) noexcept -> about_window &;
    auto operator= (const about_window &) -> about_window & = delete;

    static auto get_type () -> GType G_GNUC_CONST;
    static auto get_base_type () -> GType G_GNUC_CONST;

    auto gobj () -> AdwAboutWindow *;
    auto gobj () const -> const AdwAboutWindow *;

    auto get_application_icon () const -> glib::ustring;
    auto get_application_name () const -> glib::ustring;
    auto get_comments () const -> glib::ustring;
    auto get_copyright () const -> glib::ustring;
    auto get_debug_info () const -> glib::ustring;
    auto get_debug_info_filename () const -> glib::ustring;
    auto get_developer_name () const -> glib::ustring;
    auto get_issue_url () const -> glib::ustring;
    auto get_license () const -> glib::ustring;
    auto get_release_notes () const -> glib::ustring;
    auto get_release_notes_version () const -> glib::ustring;
    auto get_support_url () const -> glib::ustring;
    auto get_translator_credits () const -> glib::ustring;
    auto get_version () const -> glib::ustring;
    auto get_website () const -> glib::ustring;
    auto get_license_type () const -> gtk::License;
    auto get_artists () const -> std::vector<glib::ustring>;
    auto get_designers () const -> std::vector<glib::ustring>;
    auto get_developers () const -> std::vector<glib::ustring>;
    auto get_documenters () const -> std::vector<glib::ustring>;

    auto add_acknowledgement_section (const glib::ustring &name, const std::vector<glib::ustring> &people) -> void;
    auto add_credit_section (const glib::ustring &name, const std::vector<glib::ustring> &people) -> void;
    auto add_legal_section (const glib::ustring &title, const glib::ustring &copyright, gtk::License license_type, const glib::ustring &license) -> void;
    auto add_link (const glib::ustring &title, const glib::ustring &url) -> void;

    auto set_application_icon (const glib::ustring &application_icon) -> void;
    auto set_application_name (const glib::ustring &application_name) -> void;
    auto set_artists (const std::vector<glib::ustring> &artists) -> void;
    auto set_comments (const glib::ustring &comments) -> void;
    auto set_copyright (const glib::ustring &copyright) -> void;
    auto set_debug_info (const glib::ustring &debug_info) -> void;
    auto set_debug_info_filename (const glib::ustring &filename) -> void;
    auto set_designers (const std::vector<glib::ustring> &designers) -> void;
    auto set_developer_name (const glib::ustring &developer_name) -> void;
    auto set_developers (const std::vector<glib::ustring> &developers) -> void;
    auto set_documenters (const std::vector<glib::ustring> &documenters) -> void;
    auto set_issue_url (const glib::ustring &issue_url) -> void;
    auto set_license (const glib::ustring &license) -> void;
    auto set_license_type (gtk::License license_type) -> void;
    auto set_release_notes (const glib::ustring &release_notes) -> void;
    auto set_release_notes_version (const glib::ustring &version) -> void;
    auto set_support_url (const glib::ustring &support_url) -> void;
    auto set_translator_credits (const glib::ustring &translator_credits) -> void;
    auto set_version (const glib::ustring &version) -> void;
    auto set_website (const glib::ustring &website) -> void;

    auto property_support_url () -> glib::PropertyProxy<glib::ustring>;
    auto property_support_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_application_icon () -> glib::PropertyProxy<glib::ustring>;
    auto property_application_icon () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_translator_credits () -> glib::PropertyProxy<glib::ustring>;
    auto property_translator_credits () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_copyright () -> glib::PropertyProxy<glib::ustring>;
    auto property_copyright () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_release_notes () -> glib::PropertyProxy<glib::ustring>;
    auto property_release_notes () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_designers () -> glib::PropertyProxy<std::vector<glib::ustring>>;
    auto property_designers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;
    auto property_application_name () -> glib::PropertyProxy<glib::ustring>;
    auto property_application_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_developer_name () -> glib::PropertyProxy<glib::ustring>;
    auto property_developer_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_documenters () -> glib::PropertyProxy<std::vector<glib::ustring>>;
    auto property_documenters () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;
    auto property_debug_info () -> glib::PropertyProxy<glib::ustring>;
    auto property_debug_info () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_website () -> glib::PropertyProxy<glib::ustring>;
    auto property_website () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_version () -> glib::PropertyProxy<glib::ustring>;
    auto property_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_comments () -> glib::PropertyProxy<glib::ustring>;
    auto property_comments () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_release_notes_version () -> glib::PropertyProxy<glib::ustring>;
    auto property_release_notes_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_license () -> glib::PropertyProxy<glib::ustring>;
    auto property_license () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_license_type () -> glib::PropertyProxy<glib::ustring>;
    auto property_license_type () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_developers () -> glib::PropertyProxy<std::vector<glib::ustring>>;
    auto property_developers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;
    auto property_issue_url () -> glib::PropertyProxy<glib::ustring>;
    auto property_issue_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_artists () -> glib::PropertyProxy<std::vector<glib::ustring>>;
    auto property_artists () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;
    auto property_debug_info_filename () -> glib::PropertyProxy<glib::ustring>;
    auto property_debug_info_filename () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto signal_activate_link () -> glib::SignalProxy<bool  (const glib::ustring &)>;

  protected:
    explicit about_window (const glib::ConstructParams& construct_params);
    explicit about_window (AdwAboutWindow* cast_item);

  private:
    friend class about_window_class;
    static cpp_class_type about_window_class_;
  };
} // namespace adw

namespace glib
{
  auto wrap (AdwAboutWindow *object, bool take_copy = false) -> adw::about_window *;
}
