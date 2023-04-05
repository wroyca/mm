// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ABOUTDIALOG_H
#define _GTKMM_ABOUTDIALOG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/paintable.hxx>
#include <libmm/gtk/window.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAboutDialog = struct _GtkAboutDialog;
using GtkAboutDialogClass = struct _GtkAboutDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AboutDialog_Class;
}
#endif

namespace gtk
{

  enum class License
  {
    UNKNOWN,
    CUSTOM,
    GPL_2_0,
    GPL_3_0,
    LGPL_2_1,
    LGPL_3_0,
    BSD,
    MIT_X11,
    ARTISTIC,
    GPL_2_0_ONLY,
    GPL_3_0_ONLY,
    LGPL_2_1_ONLY,
    LGPL_3_0_ONLY,
    AGPL_3_0,
    AGPL_3_0_ONLY,
    BSD_3,
    APACHE_2_0,
    MPL_2_0
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::License> : public glib::Value_Enum<gtk::License>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AboutDialog : public Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AboutDialog CppObjectType;
    typedef AboutDialog_Class CppClassType;
    typedef GtkAboutDialog BaseObjectType;
    typedef GtkAboutDialogClass BaseClassType;
#endif

    AboutDialog (AboutDialog&& src) noexcept;
    auto
    operator= (AboutDialog&& src) noexcept -> AboutDialog&;

    AboutDialog (const AboutDialog&) = delete;
    auto
    operator= (const AboutDialog&) -> AboutDialog& = delete;

    ~AboutDialog () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class AboutDialog_Class;
    static CppClassType aboutdialog_class_;

  protected:
    explicit AboutDialog (const glib::ConstructParams& construct_params);
    explicit AboutDialog (GtkAboutDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAboutDialog*
    {
      return reinterpret_cast<GtkAboutDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkAboutDialog*
    {
      return reinterpret_cast<GtkAboutDialog*> (gobject_);
    }

  private:
  public:
    AboutDialog ();

    explicit AboutDialog (bool use_header_bar);

    auto
    get_program_name () const -> glib::ustring;

    auto
    set_program_name (const glib::ustring& name) -> void;

    auto
    get_version () const -> glib::ustring;

    auto
    set_version (const glib::ustring& version) -> void;

    auto
    get_copyright () const -> glib::ustring;

    auto
    set_copyright (const glib::ustring& copyright) -> void;

    auto
    get_comments () const -> glib::ustring;

    auto
    set_comments (const glib::ustring& comments) -> void;

    auto
    get_license () const -> glib::ustring;

    auto
    set_license (const glib::ustring& license) -> void;

    auto
    get_license_type () const -> License;

    auto
    set_license_type (License license_type) -> void;

    auto
    get_system_information () const -> glib::ustring;

    auto
    set_system_information (const glib::ustring& system_information) -> void;

    auto
    get_website () const -> glib::ustring;

    auto
    set_website (const glib::ustring& website) -> void;

    auto
    get_website_label () const -> glib::ustring;

    auto
    set_website_label (const glib::ustring& website_label) -> void;

    auto
    get_authors () const -> std::vector<glib::ustring>;

    auto
    set_authors (const std::vector<glib::ustring>& authors) const -> void;

    auto
    get_documenters () const -> std::vector<glib::ustring>;

    auto
    set_documenters (const std::vector<glib::ustring>& documenters) -> void;

    auto
    get_artists () const -> std::vector<glib::ustring>;

    auto
    set_artists (const std::vector<glib::ustring>& artists) -> void;

    auto
    get_translator_credits () const -> glib::ustring;

    auto
    set_translator_credits (const glib::ustring& translator_credits) -> void;

    auto
    get_logo () -> glib::RefPtr<gdk::Paintable>;

    auto
    get_logo () const -> glib::RefPtr<const gdk::Paintable>;

    auto
    set_logo (const glib::RefPtr<const gdk::Paintable>& logo) -> void;

    auto
    set_logo_default () -> void;

    auto
    get_logo_icon_name () const -> glib::ustring;

    auto
    set_logo_icon_name (const glib::ustring& icon_name) -> void;

    auto
    get_wrap_license () const -> bool;

    auto
    set_wrap_license (bool wrap_license) -> void;

    auto
    add_credit_section (const glib::ustring& section_name,
                        const std::vector<glib::ustring>& people) -> void;

    auto
    property_program_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_program_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_version () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_version () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_copyright () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_copyright () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_comments () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_comments () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_website () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_website () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_website_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_website_label () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_license () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_license () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_license_type () -> glib::PropertyProxy<License>;

    auto
    property_license_type () const -> glib::PropertyProxy_ReadOnly<License>;

    auto
    property_system_information () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_system_information () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_authors () -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_authors () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_documenters () -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_documenters () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_translator_credits ()
        -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_translator_credits () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_artists () -> glib::PropertyProxy<std::vector<glib::ustring>>;

    auto
    property_artists () const
        -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>;

    auto
    property_logo () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_logo () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

    auto
    property_logo_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_logo_icon_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_wrap_license () -> glib::PropertyProxy<bool>;

    auto
    property_wrap_license () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate_link () -> glib::SignalProxy<bool (const std::string&)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAboutDialog* object, bool take_copy = false) -> gtk::AboutDialog*;
} // namespace glib

#endif
