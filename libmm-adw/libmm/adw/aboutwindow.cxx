// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/adw/aboutwindow.hxx>
#include <libmm/adw/aboutwindow_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>
#include <libmm/glib/mm-glib.hxx>

namespace adw
{
  about_window::cpp_class_type about_window::about_window_class_;

  auto
  about_window_class::init () -> const glib::Class &
  {
    if (!gtype_)
      gtype_ = adw_about_window_get_type ();
    return *this;
  }

  auto
  about_window_class::wrap_new (GObject *object) -> glib::ObjectBase *
  {
    return new about_window (std::bit_cast<AdwAboutWindow *> (object));
  }

  namespace
  {
    auto
    signal_activate_link_callback (AdwAboutWindow *self,
                                   const gchar *p0,
                                   void *data) -> gboolean
    {
      if (dynamic_cast<about_window *> (
        glib::ObjectBase::_get_current_wrapper (std::bit_cast<GObject *> (self))))
      {
        try
        {
          if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
            return (*static_cast<sigc::slot<bool (const glib::ustring &)> *> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
      return 0;
    }

    auto
    signal_activate_link_notify_callback (AdwAboutWindow *self,
                                          const gchar *p0,
                                          void *data) -> gboolean
    {
      if (dynamic_cast<about_window *> (
        glib::ObjectBase::_get_current_wrapper (std::bit_cast<GObject *> (self))))
      {
        try
        {
          if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
            (*static_cast<sigc::slot<void (const glib::ustring &)> *> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
      return 0;
    }

    const glib::SignalProxyInfo signal_activate_link_info = {
      "activate-link",
      std::bit_cast<GCallback> (&signal_activate_link_callback),
      std::bit_cast<GCallback> (&signal_activate_link_notify_callback)
    };
  } // namespace

  about_window::about_window (): ObjectBase (nullptr), window (glib::ConstructParams (about_window_class_.init ())) { }
  about_window::about_window (about_window &&src) noexcept: window (std::move (src)) { }
  about_window::about_window (const glib::ConstructParams &construct_params): window (construct_params) { }
  about_window::about_window (AdwAboutWindow *cast_item): window (std::bit_cast<AdwWindow *> (cast_item)) {}
  about_window::~about_window () noexcept
  {
    destroy_ ();
  }

  auto
  about_window::operator= (about_window &&src) noexcept -> about_window &
  {
    window::operator= (std::move (src));
    return *this;
  }

  auto
  about_window::get_type () -> GType
  {
    return about_window_class_.init ().get_type ();
  }

  auto
  about_window::get_base_type () -> GType
  {
    return adw_about_window_get_type ();
  }

  auto
  about_window::gobj () -> AdwAboutWindow * {
    return reinterpret_cast<AdwAboutWindow *> (gobject_);
  }

  auto
  about_window::gobj () const -> const AdwAboutWindow * {
    return reinterpret_cast<AdwAboutWindow *> (gobject_);
  }

  auto
  about_window::get_application_icon () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_application_icon (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_application_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_application_name (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_comments () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_comments (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_copyright () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_copyright (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_debug_info () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_debug_info (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_debug_info_filename () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_debug_info_filename (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_developer_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_developer_name (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_issue_url () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_issue_url (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_license () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_license (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_release_notes () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_release_notes (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_release_notes_version () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_release_notes_version (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_support_url () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_support_url (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_translator_credits () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_translator_credits (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_version () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_version (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_website () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_about_window_get_website (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_license_type () const -> gtk::License
  {
    return static_cast<gtk::License> (
      adw_about_window_get_license_type (const_cast<AdwAboutWindow *> (gobj ())));
  }

  auto
  about_window::get_artists () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
      adw_about_window_get_artists (const_cast<AdwAboutWindow *> (gobj ())),glib::OWNERSHIP_NONE);
  }

  auto
  about_window::get_designers () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
      adw_about_window_get_designers (const_cast<AdwAboutWindow *> (gobj ())), glib::OWNERSHIP_NONE);
  }

  auto
  about_window::get_developers () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
      adw_about_window_get_developers (const_cast<AdwAboutWindow *> (gobj ())), glib::OWNERSHIP_NONE);
  }

  auto
  about_window::get_documenters () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
      adw_about_window_get_documenters (const_cast<AdwAboutWindow *> (gobj ())), glib::OWNERSHIP_NONE);
  }

  auto
  about_window::add_acknowledgement_section (const glib::ustring &name,
                                            const std::vector<glib::ustring> &people) -> void
  {
    adw_about_window_add_acknowledgement_section (gobj (), name.c_str (), glib::ArrayHandler<glib::ustring>::vector_to_array (people).data ());
  }

  auto
  about_window::add_credit_section (const glib::ustring &name,
                                   const std::vector<glib::ustring> &people) -> void
  {
    adw_about_window_add_credit_section (gobj (), name.c_str (), glib::ArrayHandler<glib::ustring>::vector_to_array (people).data ());
  }

  auto
  about_window::add_legal_section (const glib::ustring &title,
                                  const glib::ustring &copyright,
                                  gtk::License license_type,
                                  const glib::ustring &license) -> void
  {
    adw_about_window_add_legal_section (gobj (), title.c_str (), copyright.c_str (), static_cast<GtkLicense> (license_type), license.c_str ());
  }

  auto
  about_window::add_link (const glib::ustring &title,
                         const glib::ustring &url) -> void
  {
    adw_about_window_add_link (gobj (), title.c_str (), url.c_str ());
  }

  auto
  about_window::set_application_icon (const glib::ustring &application_icon) -> void
  {
    adw_about_window_set_application_icon (gobj (), application_icon.c_str ());
  }

  auto
  about_window::set_application_name (const glib::ustring &application_name) -> void
  {
    adw_about_window_set_application_name (gobj (), application_name.c_str ());
  }

  auto
  about_window::set_artists (const std::vector<glib::ustring> &artists) -> void
  {
    adw_about_window_set_artists (gobj (), glib::ArrayHandler<glib::ustring>::vector_to_array (artists).data ());
  }

  auto
  about_window::set_comments (const glib::ustring &comments) -> void
  {
    adw_about_window_set_comments (gobj (), comments.c_str ());
  }

  auto
  about_window::set_copyright (const glib::ustring &copyright) -> void
  {
    adw_about_window_set_copyright (gobj (), copyright.c_str ());
  }

  auto
  about_window::set_debug_info (const glib::ustring &debug_info) -> void
  {
    adw_about_window_set_debug_info (gobj (), debug_info.c_str ());
  }

  auto
  about_window::set_debug_info_filename (const glib::ustring &filename) -> void
  {
    adw_about_window_set_debug_info_filename (gobj (), filename.c_str ());
  }

  auto
  about_window::set_designers (const std::vector<glib::ustring> &designers) -> void
  {
    adw_about_window_set_designers (gobj (), glib::ArrayHandler<glib::ustring>::vector_to_array (designers).data ());
  }

  auto
  about_window::set_developer_name (const glib::ustring &developer_name) -> void
  {
    adw_about_window_set_developer_name (gobj (), developer_name.c_str ());
  }

  auto
  about_window::set_developers (const std::vector<glib::ustring> &developers) -> void
  {
    adw_about_window_set_developers (gobj (), glib::ArrayHandler<glib::ustring>::vector_to_array (developers).data ());
  }

  auto
  about_window::set_documenters (const std::vector<glib::ustring> &documenters) -> void
  {
    adw_about_window_set_documenters (gobj (), glib::ArrayHandler<glib::ustring>::vector_to_array (documenters).data ());
  }

  auto
  about_window::set_issue_url (const glib::ustring &issue_url) -> void
  {
    adw_about_window_set_issue_url (gobj (), issue_url.c_str ());
  }

  auto
  about_window::set_license (const glib::ustring &license) -> void
  {
    adw_about_window_set_license (gobj (), license.c_str ());
  }

  auto
  about_window::set_license_type (gtk::License license_type) -> void
  {
    adw_about_window_set_license_type (gobj (), static_cast<GtkLicense> (license_type));
  }

  auto
  about_window::set_release_notes (const glib::ustring &release_notes) -> void
  {
    adw_about_window_set_release_notes (gobj (), release_notes.c_str ());
  }

  auto
  about_window::set_release_notes_version (const glib::ustring &version) -> void
  {
    adw_about_window_set_release_notes_version (gobj (), version.c_str ());
  }

  auto
  about_window::set_support_url (const glib::ustring &support_url) -> void
  {
    adw_about_window_set_support_url (gobj (), support_url.c_str ());
  }

  auto
  about_window::set_translator_credits (const glib::ustring &translator_credits) -> void
  {
    adw_about_window_set_translator_credits (gobj (), translator_credits.c_str ());
  }

  auto
  about_window::set_version (const glib::ustring &version) -> void
  {
    adw_about_window_set_version (gobj (), version.c_str ());
  }

  auto
  about_window::set_website (const glib::ustring &website) -> void
  {
    adw_about_window_set_website (gobj (), website.c_str ());
  }


  auto
  about_window::property_support_url () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "support-url"};
  }

  auto
  about_window::property_support_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "support-url"};
  }

  auto
  about_window::property_application_icon () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "application-icon"};
  }

  auto
  about_window::property_application_icon () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "application-icon"};
  }

  auto
  about_window::property_translator_credits () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "translator-credits"};
  }

  auto
  about_window::property_translator_credits () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "translator-credits"};
  }

  auto
  about_window::property_copyright () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "copyright"};
  }

  auto
  about_window::property_copyright () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "copyright"};
  }

  auto
  about_window::property_release_notes () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "release-notes"};
  }

  auto
  about_window::property_release_notes () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "release-notes"};
  }

  auto
  about_window::property_designers () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return {this, "designers"};
  }

  auto
  about_window::property_designers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return {this, "designers"};
  }

  auto
  about_window::property_application_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "application-name"};
  }

  auto
  about_window::property_application_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "application-name"};
  }

  auto
  about_window::property_developer_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "developer-name"};
  }

  auto
  about_window::property_developer_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "developer-name"};
  }

  auto
  about_window::property_documenters () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return {this, "documenters"};
  }

  auto
  about_window::property_documenters () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return {this, "documenters"};
  }

  auto
  about_window::property_debug_info () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "debug-info"};
  }

  auto
  about_window::property_debug_info () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "debug-info"};
  }

  auto
  about_window::property_website () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "website"};
  }

  auto
  about_window::property_website () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "website"};
  }

  auto
  about_window::property_version () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "version"};
  }

  auto
  about_window::property_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "version"};
  }

  auto
  about_window::property_comments () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "comments"};
  }

  auto
  about_window::property_comments () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "comments"};
  }

  auto
  about_window::property_release_notes_version () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "release-notes-version"};
  }

  auto
  about_window::property_release_notes_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "release-notes-version"};
  }

  auto
  about_window::property_license () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "license"};
  }

  auto
  about_window::property_license () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "license"};
  }

  auto
  about_window::property_license_type () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "license-type"};
  }

  auto
  about_window::property_license_type () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "license-type"};
  }

  auto
  about_window::property_developers () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return {this, "developers"};
  }

  auto
  about_window::property_developers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return {this, "developers"};
  }

  auto
  about_window::property_issue_url () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "issue-url"};
  }

  auto
  about_window::property_issue_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "issue-url"};
  }

  auto
  about_window::property_artists () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return {this, "artists"};
  }

  auto
  about_window::property_artists () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return {this, "artists"};
  }

  auto
  about_window::property_debug_info_filename () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "debug-info-filename"};
  }

  auto
  about_window::property_debug_info_filename () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "debug-info-filename"};
  }

  auto
  about_window::signal_activate_link () -> glib::SignalProxy<bool  (const glib::ustring &)>
  {
    return {this, &signal_activate_link_info};
  }
} // namespace adw

namespace glib
{
  auto
  wrap (AdwAboutWindow *object,
        const bool take_copy) -> adw::about_window *
  {
    return dynamic_cast<adw::about_window *> (
      wrap_auto (std::bit_cast<GObject *> (object), take_copy));
  }
} // namespace glib
