// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/aboutwindow.hxx>
#include <libmm-adw/aboutwindow_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static auto
  AboutWindow_signal_activate_link_callback (AdwAboutWindow* self,
                                             const gchar* p0,
                                             void* data) -> gboolean
  {
    using namespace Adw;
    using SlotType = sigc::slot<bool (const Glib::ustring&)>;

    auto obj = dynamic_cast<AboutWindow*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0)));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
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
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    auto obj = dynamic_cast<AboutWindow*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const Glib::SignalProxyInfo AboutWindow_signal_activate_link_info = {
      "activate-link",
      (GCallback) &AboutWindow_signal_activate_link_callback,
      (GCallback) &AboutWindow_signal_activate_link_notify_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwAboutWindow* object, bool take_copy) -> Adw::AboutWindow*
  {
    return dynamic_cast<Adw::AboutWindow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  AboutWindow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_about_window_get_type ();
    }

    return *this;
  }

  auto
  AboutWindow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new AboutWindow ((AdwAboutWindow*) (o));
  }

  AboutWindow::AboutWindow (const Glib::ConstructParams& construct_params)
    : Adw::Window (construct_params)
  {
  }

  AboutWindow::AboutWindow (AdwAboutWindow* castitem)
    : Adw::Window ((AdwWindow*) (castitem))
  {
  }

  AboutWindow::AboutWindow (AboutWindow&& src) noexcept
    : Adw::Window (std::move (src))
  {
  }

  auto
  AboutWindow::operator= (AboutWindow&& src) noexcept -> AboutWindow&
  {
    Adw::Window::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Adw::Window (Glib::ConstructParams (aboutwindow_class_.init ()))
  {
  }

  auto
  AboutWindow::get_application_icon () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_application_icon (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_application_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_application_name (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_comments () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_comments (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_copyright () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_copyright (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_debug_info () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_debug_info (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_debug_info_filename () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_debug_info_filename (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_developer_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_developer_name (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_issue_url () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_issue_url (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_license () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_license (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_release_notes () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_release_notes (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_release_notes_version () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_release_notes_version (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_support_url () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_support_url (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_translator_credits () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_translator_credits (
            const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_version () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_version (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_website () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_about_window_get_website (const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_license_type () const -> Gtk::License
  {
    return static_cast<Gtk::License> (adw_about_window_get_license_type (
        const_cast<AdwAboutWindow*> (gobj ())));
  }

  auto
  AboutWindow::get_artists () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        adw_about_window_get_artists (const_cast<AdwAboutWindow*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_designers () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        adw_about_window_get_designers (const_cast<AdwAboutWindow*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_developers () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        adw_about_window_get_developers (const_cast<AdwAboutWindow*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::get_documenters () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        adw_about_window_get_documenters (
            const_cast<AdwAboutWindow*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  AboutWindow::add_acknowledgement_section (
      const Glib::ustring& name,
      const std::vector<Glib::ustring>& people) -> void
  {
    adw_about_window_add_acknowledgement_section (
        gobj (),
        name.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (people).data ());
  }

  auto
  AboutWindow::add_credit_section (const Glib::ustring& name,
                                   const std::vector<Glib::ustring>& people) -> void
  {
    adw_about_window_add_credit_section (
        gobj (),
        name.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (people).data ());
  }

  auto
  AboutWindow::add_legal_section (const Glib::ustring& title,
                                  const Glib::ustring& copyright,
                                  Gtk::License license_type,
                                  const Glib::ustring& license) -> void
  {
    adw_about_window_add_legal_section (gobj (),
                                        title.c_str (),
                                        copyright.c_str (),
                                        static_cast<GtkLicense> (license_type),
                                        license.c_str ());
  }

  auto
  AboutWindow::add_link (const Glib::ustring& title, const Glib::ustring& url) -> void
  {
    adw_about_window_add_link (gobj (), title.c_str (), url.c_str ());
  }

  auto
  AboutWindow::set_application_icon (const Glib::ustring& application_icon) -> void
  {
    adw_about_window_set_application_icon (gobj (), application_icon.c_str ());
  }

  auto
  AboutWindow::set_application_name (const Glib::ustring& application_name) -> void
  {
    adw_about_window_set_application_name (gobj (), application_name.c_str ());
  }

  auto
  AboutWindow::set_artists (const std::vector<Glib::ustring>& artists) -> void
  {
    adw_about_window_set_artists (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (artists).data ());
  }

  auto
  AboutWindow::set_comments (const Glib::ustring& comments) -> void
  {
    adw_about_window_set_comments (gobj (), comments.c_str ());
  }

  auto
  AboutWindow::set_copyright (const Glib::ustring& copyright) -> void
  {
    adw_about_window_set_copyright (gobj (), copyright.c_str ());
  }

  auto
  AboutWindow::set_debug_info (const Glib::ustring& debug_info) -> void
  {
    adw_about_window_set_debug_info (gobj (), debug_info.c_str ());
  }

  auto
  AboutWindow::set_debug_info_filename (const Glib::ustring& filename) -> void
  {
    adw_about_window_set_debug_info_filename (gobj (), filename.c_str ());
  }

  auto
  AboutWindow::set_designers (const std::vector<Glib::ustring>& designers) -> void
  {
    adw_about_window_set_designers (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (designers).data ());
  }

  auto
  AboutWindow::set_developer_name (const Glib::ustring& developer_name) -> void
  {
    adw_about_window_set_developer_name (gobj (), developer_name.c_str ());
  }

  auto
  AboutWindow::set_developers (const std::vector<Glib::ustring>& developers) -> void
  {
    adw_about_window_set_developers (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (developers)
            .data ());
  }

  auto
  AboutWindow::set_documenters (const std::vector<Glib::ustring>& documenters) -> void
  {
    adw_about_window_set_documenters (
        gobj (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (documenters)
            .data ());
  }

  auto
  AboutWindow::set_issue_url (const Glib::ustring& issue_url) -> void
  {
    adw_about_window_set_issue_url (gobj (), issue_url.c_str ());
  }

  auto
  AboutWindow::set_license (const Glib::ustring& license) -> void
  {
    adw_about_window_set_license (gobj (), license.c_str ());
  }

  auto
  AboutWindow::set_license_type (Gtk::License license_type) -> void
  {
    adw_about_window_set_license_type (gobj (),
                                       static_cast<GtkLicense> (license_type));
  }

  auto
  AboutWindow::set_release_notes (const Glib::ustring& release_notes) -> void
  {
    adw_about_window_set_release_notes (gobj (), release_notes.c_str ());
  }

  auto
  AboutWindow::set_release_notes_version (const Glib::ustring& version) -> void
  {
    adw_about_window_set_release_notes_version (gobj (), version.c_str ());
  }

  auto
  AboutWindow::set_support_url (const Glib::ustring& support_url) -> void
  {
    adw_about_window_set_support_url (gobj (), support_url.c_str ());
  }

  auto
  AboutWindow::set_translator_credits (const Glib::ustring& translator_credits) -> void
  {
    adw_about_window_set_translator_credits (gobj (),
                                             translator_credits.c_str ());
  }

  auto
  AboutWindow::set_version (const Glib::ustring& version) -> void
  {
    adw_about_window_set_version (gobj (), version.c_str ());
  }

  auto
  AboutWindow::set_website (const Glib::ustring& website) -> void
  {
    adw_about_window_set_website (gobj (), website.c_str ());
  }

  auto
  AboutWindow::signal_activate_link () -> Glib::SignalProxy<bool (const Glib::ustring&)>
  {
    return Glib::SignalProxy<bool (const Glib::ustring&)> (
        this,
        &AboutWindow_signal_activate_link_info);
  }

  auto
  AboutWindow::property_support_url () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "support-url");
  }

  auto
  AboutWindow::property_support_url () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "support-url");
  }

  auto
  AboutWindow::property_application_icon () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "application-icon");
  }

  auto
  AboutWindow::property_application_icon () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "application-icon");
  }

  auto
  AboutWindow::property_translator_credits () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "translator-credits");
  }

  auto
  AboutWindow::property_translator_credits () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "translator-credits");
  }

  auto
  AboutWindow::property_copyright () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "copyright");
  }

  auto
  AboutWindow::property_copyright () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "copyright");
  }

  auto
  AboutWindow::property_release_notes () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "release-notes");
  }

  auto
  AboutWindow::property_release_notes () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "release-notes");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AboutWindow::property_designers () -> Glib::PropertyProxy<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy<std::vector<Glib::ustring>> (this, "designers");
  }

  auto
  AboutWindow::property_designers () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>> (
        this,
        "designers");
  }

  auto
  AboutWindow::property_application_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "application-name");
  }

  auto
  AboutWindow::property_application_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "application-name");
  }

  auto
  AboutWindow::property_developer_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "developer-name");
  }

  auto
  AboutWindow::property_developer_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "developer-name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AboutWindow::property_documenters () -> Glib::PropertyProxy<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy<std::vector<Glib::ustring>> (this,
                                                            "documenters");
  }

  auto
  AboutWindow::property_documenters () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>> (
        this,
        "documenters");
  }

  auto
  AboutWindow::property_debug_info () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "debug-info");
  }

  auto
  AboutWindow::property_debug_info () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "debug-info");
  }

  auto
  AboutWindow::property_website () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "website");
  }

  auto
  AboutWindow::property_website () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "website");
  }

  auto
  AboutWindow::property_version () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "version");
  }

  auto
  AboutWindow::property_version () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "version");
  }

  auto
  AboutWindow::property_comments () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "comments");
  }

  auto
  AboutWindow::property_comments () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "comments");
  }

  auto
  AboutWindow::property_release_notes_version () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "release-notes-version");
  }

  auto
  AboutWindow::property_release_notes_version () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (
        this,
        "release-notes-version");
  }

  auto
  AboutWindow::property_license () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "license");
  }

  auto
  AboutWindow::property_license () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "license");
  }

  auto
  AboutWindow::property_license_type () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "license-type");
  }

  auto
  AboutWindow::property_license_type () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "license-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AboutWindow::property_developers () -> Glib::PropertyProxy<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy<std::vector<Glib::ustring>> (this, "developers");
  }

  auto
  AboutWindow::property_developers () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>> (
        this,
        "developers");
  }

  auto
  AboutWindow::property_issue_url () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "issue-url");
  }

  auto
  AboutWindow::property_issue_url () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "issue-url");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AboutWindow::property_artists () -> Glib::PropertyProxy<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy<std::vector<Glib::ustring>> (this, "artists");
  }

  auto
  AboutWindow::property_artists () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>> (this,
                                                                     "artists");
  }

  auto
  AboutWindow::property_debug_info_filename () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "debug-info-filename");
  }

  auto
  AboutWindow::property_debug_info_filename () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "debug-info-filename");
  }

} // namespace Adw
