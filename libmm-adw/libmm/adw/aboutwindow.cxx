// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/aboutwindow.hxx>
#include <libmm/adw/aboutwindow_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static auto
  AboutWindow_signal_activate_link_callback (AdwAboutWindow* self,
                                             const gchar* p0,
                                             void* data) -> gboolean
  {
    using namespace adw;
    using SlotType = sigc::slot<bool (const glib::ustring&)>;

    auto obj = dynamic_cast<AboutWindow*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  AboutWindow_signal_activate_link_notify_callback (AdwAboutWindow* self,
                                                    const gchar* p0,
                                                    void* data) -> gboolean
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<AboutWindow*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo AboutWindow_signal_activate_link_info = {
      "activate-link",
      (GCallback) &AboutWindow_signal_activate_link_callback,
      (GCallback) &AboutWindow_signal_activate_link_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwAboutWindow* object, bool take_copy) -> adw::AboutWindow*
  {
    return dynamic_cast<adw::AboutWindow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  AboutWindow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_about_window_get_type ();
    }

    return *this;
  }

  auto
  AboutWindow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new AboutWindow ((AdwAboutWindow*) (o));
  }

  AboutWindow::AboutWindow (const glib::ConstructParams& construct_params)
    : adw::Window (construct_params)
  {
  }

  AboutWindow::AboutWindow (AdwAboutWindow* castitem)
    : adw::Window ((AdwWindow*) (castitem))
  {
  }

  AboutWindow::AboutWindow (AboutWindow&& src) noexcept
    : adw::Window (std::move (src))
  {
  }

  auto
  AboutWindow::operator= (AboutWindow&& src) noexcept -> AboutWindow&
  {
    adw::Window::operator= (std::move (src));
    return *this;
  }

  AboutWindow::~AboutWindow () noexcept
  {
    destroy_ ();
  }

  AboutWindow::CppClassType AboutWindow::aboutwindow_class_;

  auto
  AboutWindow::get_type () -> GType
  {
    return aboutwindow_class_.init ().get_type ();
  }

  auto
  AboutWindow::get_base_type () -> GType
  {
    return adw_about_window_get_type ();
  }

  AboutWindow::AboutWindow ()
    : glib::ObjectBase (nullptr),
      adw::Window (glib::ConstructParams (aboutwindow_class_.init ()))
  {
  }

  auto
  AboutWindow::get_application_icon () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_application_icon (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_application_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_application_name (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_comments () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_comments (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_copyright () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_copyright (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_debug_info () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_debug_info (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_debug_info_filename () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_debug_info_filename (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_developer_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_developer_name (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_issue_url () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_issue_url (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_license () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_license (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_release_notes () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_release_notes (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_release_notes_version () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_release_notes_version (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_support_url () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_support_url (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_translator_credits () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_translator_credits (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_version () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_version (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_website () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_website (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_license_type () const -> gtk::License
  {
    return static_cast<gtk::License> (adw_about_window_get_license_type (
        const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_artists () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        adw_about_window_get_artists (const_cast<AdwAboutWindow*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_designers () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        adw_about_window_get_designers (const_cast<AdwAboutWindow*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_developers () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        adw_about_window_get_developers (const_cast<AdwAboutWindow*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_documenters () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        adw_about_window_get_documenters (
            const_cast<AdwAboutWindow*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::add_acknowledgement_section (
      const glib::ustring& name,
      const std::vector<glib::ustring>& people) -> void
  {
    adw_about_window_add_acknowledgement_section (
        gobj (),
        name.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (people).data ());
  }

  auto
  AboutWindow::add_credit_section (const glib::ustring& name,
                                   const std::vector<glib::ustring>& people) -> void
  {
    adw_about_window_add_credit_section (
        gobj (),
        name.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (people).data ());
  }

  auto
  AboutWindow::add_legal_section (const glib::ustring& title,
                                  const glib::ustring& copyright,
                                  gtk::License license_type,
                                  const glib::ustring& license) -> void
  {
    adw_about_window_add_legal_section (gobj (),
                                        title.c_str (),
                                        copyright.c_str (),
                                        static_cast<GtkLicense> (license_type),
                                        license.c_str ());
  }

  auto
  AboutWindow::add_link (const glib::ustring& title, const glib::ustring& url) -> void
  {
    adw_about_window_add_link (gobj (), title.c_str (), url.c_str ());
  }

  auto
  AboutWindow::set_application_icon (const glib::ustring& application_icon) -> void
  {
    adw_about_window_set_application_icon (gobj (), application_icon.c_str ());
  }

  auto
  AboutWindow::set_application_name (const glib::ustring& application_name) -> void
  {
    adw_about_window_set_application_name (gobj (), application_name.c_str ());
  }

  auto
  AboutWindow::set_artists (const std::vector<glib::ustring>& artists) -> void
  {
    adw_about_window_set_artists (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (artists).data ());
  }

  auto
  AboutWindow::set_comments (const glib::ustring& comments) -> void
  {
    adw_about_window_set_comments (gobj (), comments.c_str ());
  }

  auto
  AboutWindow::set_copyright (const glib::ustring& copyright) -> void
  {
    adw_about_window_set_copyright (gobj (), copyright.c_str ());
  }

  auto
  AboutWindow::set_debug_info (const glib::ustring& debug_info) -> void
  {
    adw_about_window_set_debug_info (gobj (), debug_info.c_str ());
  }

  auto
  AboutWindow::set_debug_info_filename (const glib::ustring& filename) -> void
  {
    adw_about_window_set_debug_info_filename (gobj (), filename.c_str ());
  }

  auto
  AboutWindow::set_designers (const std::vector<glib::ustring>& designers) -> void
  {
    adw_about_window_set_designers (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (designers).data ());
  }

  auto
  AboutWindow::set_developer_name (const glib::ustring& developer_name) -> void
  {
    adw_about_window_set_developer_name (gobj (), developer_name.c_str ());
  }

  auto
  AboutWindow::set_developers (const std::vector<glib::ustring>& developers) -> void
  {
    adw_about_window_set_developers (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (developers)
            .data ());
  }

  auto
  AboutWindow::set_documenters (const std::vector<glib::ustring>& documenters) -> void
  {
    adw_about_window_set_documenters (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (documenters)
            .data ());
  }

  auto
  AboutWindow::set_issue_url (const glib::ustring& issue_url) -> void
  {
    adw_about_window_set_issue_url (gobj (), issue_url.c_str ());
  }

  auto
  AboutWindow::set_license (const glib::ustring& license) -> void
  {
    adw_about_window_set_license (gobj (), license.c_str ());
  }

  auto
  AboutWindow::set_license_type (gtk::License license_type) -> void
  {
    adw_about_window_set_license_type (gobj (),
                                       static_cast<GtkLicense> (license_type));
  }

  auto
  AboutWindow::set_release_notes (const glib::ustring& release_notes) -> void
  {
    adw_about_window_set_release_notes (gobj (), release_notes.c_str ());
  }

  auto
  AboutWindow::set_release_notes_version (const glib::ustring& version) -> void
  {
    adw_about_window_set_release_notes_version (gobj (), version.c_str ());
  }

  auto
  AboutWindow::set_support_url (const glib::ustring& support_url) -> void
  {
    adw_about_window_set_support_url (gobj (), support_url.c_str ());
  }

  auto
  AboutWindow::set_translator_credits (const glib::ustring& translator_credits) -> void
  {
    adw_about_window_set_translator_credits (gobj (),
                                             translator_credits.c_str ());
  }

  auto
  AboutWindow::set_version (const glib::ustring& version) -> void
  {
    adw_about_window_set_version (gobj (), version.c_str ());
  }

  auto
  AboutWindow::set_website (const glib::ustring& website) -> void
  {
    adw_about_window_set_website (gobj (), website.c_str ());
  }

  auto
  AboutWindow::signal_activate_link () -> glib::SignalProxy<bool (const glib::ustring&)>
  {
    return glib::SignalProxy<bool (const glib::ustring&)> (
        this,
        &AboutWindow_signal_activate_link_info);
  }

  auto
  AboutWindow::property_support_url () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "support-url");
  }

  auto
  AboutWindow::property_support_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "support-url");
  }

  auto
  AboutWindow::property_application_icon () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "application-icon");
  }

  auto
  AboutWindow::property_application_icon () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "application-icon");
  }

  auto
  AboutWindow::property_translator_credits () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "translator-credits");
  }

  auto
  AboutWindow::property_translator_credits () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "translator-credits");
  }

  auto
  AboutWindow::property_copyright () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "copyright");
  }

  auto
  AboutWindow::property_copyright () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "copyright");
  }

  auto
  AboutWindow::property_release_notes () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "release-notes");
  }

  auto
  AboutWindow::property_release_notes () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "release-notes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutWindow::property_designers () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "designers");
  }

  auto
  AboutWindow::property_designers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "designers");
  }

  auto
  AboutWindow::property_application_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "application-name");
  }

  auto
  AboutWindow::property_application_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "application-name");
  }

  auto
  AboutWindow::property_developer_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "developer-name");
  }

  auto
  AboutWindow::property_developer_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "developer-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutWindow::property_documenters () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this,
                                                            "documenters");
  }

  auto
  AboutWindow::property_documenters () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "documenters");
  }

  auto
  AboutWindow::property_debug_info () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "debug-info");
  }

  auto
  AboutWindow::property_debug_info () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "debug-info");
  }

  auto
  AboutWindow::property_website () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "website");
  }

  auto
  AboutWindow::property_website () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "website");
  }

  auto
  AboutWindow::property_version () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "version");
  }

  auto
  AboutWindow::property_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "version");
  }

  auto
  AboutWindow::property_comments () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "comments");
  }

  auto
  AboutWindow::property_comments () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "comments");
  }

  auto
  AboutWindow::property_release_notes_version () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "release-notes-version");
  }

  auto
  AboutWindow::property_release_notes_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (
        this,
        "release-notes-version");
  }

  auto
  AboutWindow::property_license () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "license");
  }

  auto
  AboutWindow::property_license () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "license");
  }

  auto
  AboutWindow::property_license_type () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "license-type");
  }

  auto
  AboutWindow::property_license_type () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "license-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutWindow::property_developers () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "developers");
  }

  auto
  AboutWindow::property_developers () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "developers");
  }

  auto
  AboutWindow::property_issue_url () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "issue-url");
  }

  auto
  AboutWindow::property_issue_url () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "issue-url");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutWindow::property_artists () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "artists");
  }

  auto
  AboutWindow::property_artists () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (this,
                                                                     "artists");
  }

  auto
  AboutWindow::property_debug_info_filename () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "debug-info-filename");
  }

  auto
  AboutWindow::property_debug_info_filename () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "debug-info-filename");
  }

} // namespace adw
