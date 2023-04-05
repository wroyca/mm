// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/aboutdialog.hxx>
#include <libmm/gtk/aboutdialog_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  AboutDialog::AboutDialog (bool use_header_bar)
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (aboutdialog_class_.init (),
                                          "use-header-bar",
                                          static_cast<int> (use_header_bar),
                                          nullptr))
  {
  }

  auto
  AboutDialog::set_logo_default () -> void
  {
    gtk_about_dialog_set_logo (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static auto
  AboutDialog_signal_activate_link_callback (GtkAboutDialog* self,
                                             const gchar* p0,
                                             void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const std::string&)>;

    auto obj = dynamic_cast<AboutDialog*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_stdstring (p0)));
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
  AboutDialog_signal_activate_link_notify_callback (GtkAboutDialog* self,
                                                    const gchar* p0,
                                                    void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const std::string&)>;

    auto obj = dynamic_cast<AboutDialog*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_stdstring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo AboutDialog_signal_activate_link_info = {
      "activate-link",
      (GCallback) &AboutDialog_signal_activate_link_callback,
      (GCallback) &AboutDialog_signal_activate_link_notify_callback};

} // namespace

auto
glib::Value<gtk::License>::value_type () -> GType
{
  return gtk_license_get_type ();
}

namespace glib
{

  auto
  wrap (GtkAboutDialog* object, bool take_copy) -> gtk::AboutDialog*
  {
    return dynamic_cast<gtk::AboutDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  AboutDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AboutDialog_Class::class_init_function;

      register_derived_type (gtk_about_dialog_get_type ());
    }

    return *this;
  }

  auto
  AboutDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AboutDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new AboutDialog ((GtkAboutDialog*) (o));
  }

  AboutDialog::AboutDialog (const glib::ConstructParams& construct_params)
    : gtk::Window (construct_params)
  {
  }

  AboutDialog::AboutDialog (GtkAboutDialog* castitem)
    : gtk::Window ((GtkWindow*) (castitem))
  {
  }

  AboutDialog::AboutDialog (AboutDialog&& src) noexcept
    : gtk::Window (std::move (src))
  {
  }

  auto
  AboutDialog::operator= (AboutDialog&& src) noexcept -> AboutDialog&
  {
    gtk::Window::operator= (std::move (src));
    return *this;
  }

  AboutDialog::~AboutDialog () noexcept
  {
    destroy_ ();
  }

  AboutDialog::CppClassType AboutDialog::aboutdialog_class_;

  auto
  AboutDialog::get_type () -> GType
  {
    return aboutdialog_class_.init ().get_type ();
  }

  auto
  AboutDialog::get_base_type () -> GType
  {
    return gtk_about_dialog_get_type ();
  }

  AboutDialog::AboutDialog ()
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (aboutdialog_class_.init ()))
  {
  }

  auto
  AboutDialog::get_program_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_program_name (
            const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_program_name (const glib::ustring& name) -> void
  {
    gtk_about_dialog_set_program_name (gobj (), name.c_str ());
  }

  auto
  AboutDialog::get_version () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_version (const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_version (const glib::ustring& version) -> void
  {
    gtk_about_dialog_set_version (gobj (), version.c_str ());
  }

  auto
  AboutDialog::get_copyright () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_copyright (const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_copyright (const glib::ustring& copyright) -> void
  {
    gtk_about_dialog_set_copyright (gobj (), copyright.c_str ());
  }

  auto
  AboutDialog::get_comments () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_comments (const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_comments (const glib::ustring& comments) -> void
  {
    gtk_about_dialog_set_comments (gobj (), comments.c_str ());
  }

  auto
  AboutDialog::get_license () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_license (const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_license (const glib::ustring& license) -> void
  {
    gtk_about_dialog_set_license (
        gobj (),
        license.empty () ? nullptr : license.c_str ());
  }

  auto
  AboutDialog::get_license_type () const -> License
  {
    return static_cast<License> (gtk_about_dialog_get_license_type (
        const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_license_type (License license_type) -> void
  {
    gtk_about_dialog_set_license_type (gobj (),
                                       static_cast<GtkLicense> (license_type));
  }

  auto
  AboutDialog::get_system_information () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_system_information (
            const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_system_information (const glib::ustring& system_information) -> void
  {
    gtk_about_dialog_set_system_information (
        gobj (),
        system_information.empty () ? nullptr : system_information.c_str ());
  }

  auto
  AboutDialog::get_website () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_website (const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_website (const glib::ustring& website) -> void
  {
    gtk_about_dialog_set_website (gobj (), website.c_str ());
  }

  auto
  AboutDialog::get_website_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_website_label (
            const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_website_label (const glib::ustring& website_label) -> void
  {
    gtk_about_dialog_set_website_label (gobj (), website_label.c_str ());
  }

  auto
  AboutDialog::get_authors () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_about_dialog_get_authors (const_cast<GtkAboutDialog*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutDialog::set_authors (const std::vector<glib::ustring>& authors) const -> void
  {
    gtk_about_dialog_set_authors (
        const_cast<GtkAboutDialog*> (gobj ()),
        glib::ArrayHandler<glib::ustring>::vector_to_array (authors).data ());
  }

  auto
  AboutDialog::get_documenters () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_about_dialog_get_documenters (
            const_cast<GtkAboutDialog*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutDialog::set_documenters (const std::vector<glib::ustring>& documenters) -> void
  {
    gtk_about_dialog_set_documenters (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (documenters)
            .data ());
  }

  auto
  AboutDialog::get_artists () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_about_dialog_get_artists (const_cast<GtkAboutDialog*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AboutDialog::set_artists (const std::vector<glib::ustring>& artists) -> void
  {
    gtk_about_dialog_set_artists (
        gobj (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (artists).data ());
  }

  auto
  AboutDialog::get_translator_credits () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_translator_credits (
            const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_translator_credits (const glib::ustring& translator_credits) -> void
  {
    gtk_about_dialog_set_translator_credits (gobj (),
                                             translator_credits.c_str ());
  }

  auto
  AboutDialog::get_logo () -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (gtk_about_dialog_get_logo (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AboutDialog::get_logo () const -> glib::RefPtr<const gdk::Paintable>
  {
    return const_cast<AboutDialog*> (this)->get_logo ();
  }

  auto
  AboutDialog::set_logo (const glib::RefPtr<const gdk::Paintable>& logo) -> void
  {
    gtk_about_dialog_set_logo (gobj (),
                               const_cast<GdkPaintable*> (glib::unwrap (logo)));
  }

  auto
  AboutDialog::get_logo_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_about_dialog_get_logo_icon_name (
            const_cast<GtkAboutDialog*> (gobj ())));
  }

  auto
  AboutDialog::set_logo_icon_name (const glib::ustring& icon_name) -> void
  {
    gtk_about_dialog_set_logo_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  AboutDialog::get_wrap_license () const -> bool
  {
    return gtk_about_dialog_get_wrap_license (
        const_cast<GtkAboutDialog*> (gobj ()));
  }

  auto
  AboutDialog::set_wrap_license (bool wrap_license) -> void
  {
    gtk_about_dialog_set_wrap_license (gobj (),
                                       static_cast<int> (wrap_license));
  }

  auto
  AboutDialog::add_credit_section (const glib::ustring& section_name,
                                   const std::vector<glib::ustring>& people) -> void
  {
    gtk_about_dialog_add_credit_section (
        gobj (),
        section_name.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (people).data ());
  }

  auto
  AboutDialog::signal_activate_link () -> glib::SignalProxy<bool (const std::string&)>
  {
    return glib::SignalProxy<bool (const std::string&)> (
        this,
        &AboutDialog_signal_activate_link_info);
  }

  auto
  AboutDialog::property_program_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "program-name");
  }

  auto
  AboutDialog::property_program_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "program-name");
  }

  auto
  AboutDialog::property_version () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "version");
  }

  auto
  AboutDialog::property_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "version");
  }

  auto
  AboutDialog::property_copyright () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "copyright");
  }

  auto
  AboutDialog::property_copyright () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "copyright");
  }

  auto
  AboutDialog::property_comments () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "comments");
  }

  auto
  AboutDialog::property_comments () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "comments");
  }

  auto
  AboutDialog::property_website () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "website");
  }

  auto
  AboutDialog::property_website () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "website");
  }

  auto
  AboutDialog::property_website_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "website-label");
  }

  auto
  AboutDialog::property_website_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "website-label");
  }

  auto
  AboutDialog::property_license () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "license");
  }

  auto
  AboutDialog::property_license () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "license");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<License>::value,
      "Type License cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_license_type () -> glib::PropertyProxy<License>
  {
    return glib::PropertyProxy<License> (this, "license-type");
  }

  auto
  AboutDialog::property_license_type () const -> glib::PropertyProxy_ReadOnly<License>
  {
    return glib::PropertyProxy_ReadOnly<License> (this, "license-type");
  }

  auto
  AboutDialog::property_system_information () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "system-information");
  }

  auto
  AboutDialog::property_system_information () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "system-information");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_authors () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "authors");
  }

  auto
  AboutDialog::property_authors () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (this,
                                                                     "authors");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_documenters () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this,
                                                            "documenters");
  }

  auto
  AboutDialog::property_documenters () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "documenters");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_translator_credits () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (
        this,
        "translator-credits");
  }

  auto
  AboutDialog::property_translator_credits () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (
        this,
        "translator-credits");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_artists () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "artists");
  }

  auto
  AboutDialog::property_artists () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (this,
                                                                     "artists");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AboutDialog::property_logo () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (this, "logo");
  }

  auto
  AboutDialog::property_logo () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (this,
                                                                       "logo");
  }

  auto
  AboutDialog::property_logo_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "logo-icon-name");
  }

  auto
  AboutDialog::property_logo_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "logo-icon-name");
  }

  auto
  AboutDialog::property_wrap_license () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "wrap-license");
  }

  auto
  AboutDialog::property_wrap_license () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "wrap-license");
  }

} // namespace gtk
