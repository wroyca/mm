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
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AboutDialog_Class;
}
#endif

namespace Gtk
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

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::License> : public Glib::Value_Enum<Gtk::License>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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
    explicit AboutDialog (const Glib::ConstructParams& construct_params);
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
    get_program_name () const -> Glib::ustring;

    auto
    set_program_name (const Glib::ustring& name) -> void;

    auto
    get_version () const -> Glib::ustring;

    auto
    set_version (const Glib::ustring& version) -> void;

    auto
    get_copyright () const -> Glib::ustring;

    auto
    set_copyright (const Glib::ustring& copyright) -> void;

    auto
    get_comments () const -> Glib::ustring;

    auto
    set_comments (const Glib::ustring& comments) -> void;

    auto
    get_license () const -> Glib::ustring;

    auto
    set_license (const Glib::ustring& license) -> void;

    auto
    get_license_type () const -> License;

    auto
    set_license_type (License license_type) -> void;

    auto
    get_system_information () const -> Glib::ustring;

    auto
    set_system_information (const Glib::ustring& system_information) -> void;

    auto
    get_website () const -> Glib::ustring;

    auto
    set_website (const Glib::ustring& website) -> void;

    auto
    get_website_label () const -> Glib::ustring;

    auto
    set_website_label (const Glib::ustring& website_label) -> void;

    auto
    get_authors () const -> std::vector<Glib::ustring>;

    auto
    set_authors (const std::vector<Glib::ustring>& authors) const -> void;

    auto
    get_documenters () const -> std::vector<Glib::ustring>;

    auto
    set_documenters (const std::vector<Glib::ustring>& documenters) -> void;

    auto
    get_artists () const -> std::vector<Glib::ustring>;

    auto
    set_artists (const std::vector<Glib::ustring>& artists) -> void;

    auto
    get_translator_credits () const -> Glib::ustring;

    auto
    set_translator_credits (const Glib::ustring& translator_credits) -> void;

    auto
    get_logo () -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_logo () const -> Glib::RefPtr<const Gdk::Paintable>;

    auto
    set_logo (const Glib::RefPtr<const Gdk::Paintable>& logo) -> void;

    auto
    set_logo_default () -> void;

    auto
    get_logo_icon_name () const -> Glib::ustring;

    auto
    set_logo_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    get_wrap_license () const -> bool;

    auto
    set_wrap_license (bool wrap_license) -> void;

    auto
    add_credit_section (const Glib::ustring& section_name,
                        const std::vector<Glib::ustring>& people) -> void;

    auto
    property_program_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_program_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_version () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_version () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_copyright () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_copyright () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_comments () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_comments () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_website () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_website () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_website_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_website_label () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_license () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_license () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_license_type () -> Glib::PropertyProxy<License>;

    auto
    property_license_type () const -> Glib::PropertyProxy_ReadOnly<License>;

    auto
    property_system_information () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_system_information () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_authors () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_authors () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_documenters () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_documenters () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_translator_credits ()
        -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_translator_credits () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_artists () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_artists () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_logo () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_logo () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_logo_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_logo_icon_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_wrap_license () -> Glib::PropertyProxy<bool>;

    auto
    property_wrap_license () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate_link () -> Glib::SignalProxy<bool (const std::string&)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAboutDialog* object, bool take_copy = false) -> Gtk::AboutDialog*;
} // namespace Glib

#endif
