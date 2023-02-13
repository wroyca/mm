
#ifndef _GTKMM_ABOUTDIALOG_H
#define _GTKMM_ABOUTDIALOG_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2004 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#include <vector>

#include <libmm-gtk/window.hxx>
#include <libmm-gdk/paintable.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAboutDialog = struct _GtkAboutDialog;
using GtkAboutDialogClass = struct _GtkAboutDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AboutDialog_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var License UNKNOWN
 * No license specified.
 *
 *  @var License CUSTOM
 * A license text is going to be specified by the
 * developer.
 *
 *  @var License GPL_2_0
 * The GNU General Public License, version 2.0 or later.
 *
 *  @var License GPL_3_0
 * The GNU General Public License, version 3.0 or later.
 *
 *  @var License LGPL_2_1
 * The GNU Lesser General Public License, version 2.1 or later.
 *
 *  @var License LGPL_3_0
 * The GNU Lesser General Public License, version 3.0 or later.
 *
 *  @var License BSD
 * The BSD standard license.
 *
 *  @var License MIT_X11
 * The MIT/X11 standard license.
 *
 *  @var License ARTISTIC
 * The Artistic License, version 2.0.
 *
 *  @var License GPL_2_0_ONLY
 * The GNU General Public License, version 2.0 only.
 *
 *  @var License GPL_3_0_ONLY
 * The GNU General Public License, version 3.0 only.
 *
 *  @var License LGPL_2_1_ONLY
 * The GNU Lesser General Public License, version 2.1 only.
 *
 *  @var License LGPL_3_0_ONLY
 * The GNU Lesser General Public License, version 3.0 only.
 *
 *  @var License AGPL_3_0
 * The GNU Affero General Public License, version 3.0 or later.
 *
 *  @var License AGPL_3_0_ONLY
 * The GNU Affero General Public License, version 3.0 only.
 *
 *  @var License BSD_3
 * The 3-clause BSD licence.
 *
 *  @var License APACHE_2_0
 * The Apache License, version 2.0.
 *
 *  @var License MPL_2_0
 * The Mozilla Public License, version 2.0.
 *
 *  @enum License
 *
 * The type of license for an application.
 *
 * This enumeration can be expanded at later date.
 *
 * @ingroup gtkmmEnums
 */
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
class GTKMM_API Value<Gtk::License> : public Glib::Value_Enum<Gtk::License>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** The AboutDialog offers a simple way to display information about a program like its logo, name, copyright,
 * website and license. It is also possible to give credits to the authors, documenters, translators and artists
 * who have worked on the program. An about dialog is typically opened when the user selects the About option
 * from the Help menu. All parts of the dialog are optional.
 *
 * About dialogs often contain links and email addresses. Gtk::AboutDialog displays these as clickable links.
 * By default, it calls gtk_show_uri() when a user clicks one. The behaviour can be overridden with the activate_link signal.
 * Email addresses in the authors, documenters and artists properties are recognized by looking
 * for \<user\@host\>, URLs are recognized by looking for http://url, with the URL extending to the next space,
 * tab or line break.
 *
 * An AboutDialog looks like this:
 * @image html aboutdialog1.png
 *
 * @ingroup Dialogs
 */

class GTKMM_API AboutDialog : public Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef AboutDialog CppObjectType;
  typedef AboutDialog_Class CppClassType;
  typedef GtkAboutDialog BaseObjectType;
  typedef GtkAboutDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  AboutDialog(AboutDialog&& src) noexcept;
  auto operator=(AboutDialog&& src) noexcept -> AboutDialog&;

  // noncopyable
  AboutDialog(const AboutDialog&) = delete;
  auto operator=(const AboutDialog&) -> AboutDialog& = delete;

  ~AboutDialog() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class AboutDialog_Class;
  static CppClassType aboutdialog_class_;

protected:
  explicit AboutDialog(const Glib::ConstructParams& construct_params);
  explicit AboutDialog(GtkAboutDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkAboutDialog*       { return reinterpret_cast<GtkAboutDialog*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAboutDialog* { return reinterpret_cast<GtkAboutDialog*>(gobject_); }

private:


public:
  AboutDialog();

  /** Constructor.
   *
   * @param use_header_bar <tt>true</tt> if the dialog shall use a HeaderBar
   *        for action buttons instead of the action-area.
   *
   * @newin{3,24}
   */
  explicit AboutDialog(bool use_header_bar);


  /** Returns the program name displayed in the about dialog.
   *
   * @return The program name.
   */
  auto get_program_name() const -> Glib::ustring;

  /** Sets the name to display in the about dialog.
   *
   * If `name` is not set, the string returned
   * by `Glib::get_application_name()` is used.
   *
   * @param name The program name.
   */
  void set_program_name(const Glib::ustring& name);


  /** Returns the version string.
   *
   * @return The version string.
   */
  auto get_version() const -> Glib::ustring;

  /** Sets the version string to display in the about dialog.
   *
   * @param version The version string.
   */
  void set_version(const Glib::ustring& version);

  /** Returns the copyright string.
   *
   * @return The copyright string.
   */
  auto get_copyright() const -> Glib::ustring;

  /** Sets the copyright string to display in the about dialog.
   *
   * This should be a short string of one or two lines.
   *
   * @param copyright The copyright string.
   */
  void set_copyright(const Glib::ustring& copyright);

  /** Returns the comments string.
   *
   * @return The comments.
   */
  auto get_comments() const -> Glib::ustring;

  /** Sets the comments string to display in the about dialog.
   *
   * This should be a short string of one or two lines.
   *
   * @param comments A comments string.
   */
  void set_comments(const Glib::ustring& comments);

  /** Returns the license information.
   *
   * @return The license information.
   */
  auto get_license() const -> Glib::ustring;

  /** Sets the license information to be displayed in the secondary license dialog.
   * If @a license is an empty string, the license button is hidden.
   *
   * @newin{2,6}
   *
   * @param license The license information.
   */
  void set_license(const Glib::ustring& license);

  /** Retrieves the license type.
   *
   * @return A Gtk::License value.
   */
  auto get_license_type() const -> License;

  /** Sets the license of the application showing the about dialog from a
   * list of known licenses.
   *
   * This function overrides the license set using
   * set_license().
   *
   * @param license_type The type of license.
   */
  void set_license_type(License license_type);

  /** Returns the system information that is shown in the about dialog.
   *
   * @return The system information.
   */
  auto get_system_information() const -> Glib::ustring;

  /** Sets the system information to be displayed in the about dialog.
   * If @a system_information is an empty string, the system information tab is hidden.
   *
   * See Gtk::Aboutdialog::property_system_information().
   *
   * @newin{3,92}
   *
   * @param system_information System information.
   */
  void set_system_information(const Glib::ustring& system_information);

  /** Returns the website URL.
   *
   * @return The website URL.
   */
  auto get_website() const -> Glib::ustring;

  /** Sets the URL to use for the website link.
   *
   * @param website A URL string starting with `http://`.
   */
  void set_website(const Glib::ustring& website);

  /** Returns the label used for the website link.
   *
   * @return The label used for the website link.
   */
  auto get_website_label() const -> Glib::ustring;

  /** Sets the label to be used for the website link.
   *
   * @param website_label The label used for the website link.
   */
  void set_website_label(const Glib::ustring& website_label);


  /** Returns the names of the authors which are displayed
   * in the credits page.
   *
   * @return A
   * <tt>nullptr</tt>-terminated string array containing the authors.
   */
  auto get_authors() const -> std::vector<Glib::ustring>;


  /** Sets the names of the authors which are displayed
   * in the "Credits" page of the about dialog.
   *
   * @param authors The authors of the application.
   */
  void set_authors(const std::vector<Glib::ustring>& authors) const;


  /** Returns the name of the documenters which are displayed
   * in the credits page.
   *
   * @return A
   * <tt>nullptr</tt>-terminated string array containing the documenters.
   */
  auto get_documenters() const -> std::vector<Glib::ustring>;


  /** Sets the names of the documenters which are displayed
   * in the "Credits" page.
   *
   * @param documenters The authors of the documentation
   * of the application.
   */
  void set_documenters(const std::vector<Glib::ustring>& documenters);

  /** Returns the names of the artists which are displayed
   * in the credits page.
   *
   * @return A
   * <tt>nullptr</tt>-terminated string array containing the artists.
   */
  auto get_artists() const -> std::vector<Glib::ustring>;

  /** Sets the names of the artists to be displayed
   * in the "Credits" page.
   *
   * @param artists The authors of the artwork
   * of the application.
   */
  void set_artists(const std::vector<Glib::ustring>& artists);

  /** Returns the translator credits string which is displayed
   * in the credits page.
   *
   * @return The translator credits string.
   */
  auto get_translator_credits() const -> Glib::ustring;

  /** Sets the translator credits string which is displayed in
   * the credits page.
   *
   * The intended use for this string is to display the translator
   * of the language which is currently used in the user interface.
   * Using `gettext()`, a simple way to achieve that is to mark the
   * string for translation:
   *
   *
   * [C example ellipted]
   *
   * It is a good idea to use the customary `msgid` “translator-credits”
   * for this purpose, since translators will already know the purpose of
   * that `msgid`, and since `Gtk::AboutDialog` will detect if “translator-credits”
   * is untranslated and omit translator credits.
   *
   * @param translator_credits The translator credits.
   */
  void set_translator_credits(const Glib::ustring& translator_credits);


  /** Returns the paintable displayed as logo in the about dialog.
   *
   * @return The paintable displayed as
   * logo or <tt>nullptr</tt> if the logo is unset or has been set via
   * set_logo_icon_name().
   */
  auto get_logo() -> Glib::RefPtr<Gdk::Paintable>;

  /** Returns the paintable displayed as logo in the about dialog.
   *
   * @return The paintable displayed as
   * logo or <tt>nullptr</tt> if the logo is unset or has been set via
   * set_logo_icon_name().
   */
  auto get_logo() const -> Glib::RefPtr<const Gdk::Paintable>;

  /** Sets the logo in the about dialog.
   *
   * @param logo A `Gdk::Paintable`.
   */
  void set_logo(const Glib::RefPtr<const Gdk::Paintable>& logo);

  /** Sets the surface to be displayed as logo in the about dialog.
   * The logo is set to the default window icon set with
   * Gtk::Window::set_default_icon() or Gtk::Window::set_default_icon_list().
   *
   * @newin{3,4}
   */
  void set_logo_default();


  /** Returns the icon name displayed as logo in the about dialog.
   *
   * @return The icon name displayed as logo,
   * or <tt>nullptr</tt> if the logo has been set via set_logo().
   */
  auto get_logo_icon_name() const -> Glib::ustring;

  /** Sets the icon name to be displayed as logo in the about dialog.
   *
   * @param icon_name An icon name.
   */
  void set_logo_icon_name(const Glib::ustring& icon_name);


  /** Returns whether the license text in the about dialog is
   * automatically wrapped.
   *
   * @return <tt>true</tt> if the license text is wrapped.
   */
  auto get_wrap_license() const -> bool;

  /** Sets whether the license text in the about dialog should be
   * automatically wrapped.
   *
   * @param wrap_license Whether to wrap the license.
   */
  void set_wrap_license(bool wrap_license);


  /** Creates a new section in the "Credits" page.
   *
   * @param section_name The name of the section.
   * @param people The people who belong to that section.
   */
  void add_credit_section(const Glib::ustring& section_name, const std::vector<Glib::ustring>& people);

  /** The name of the program.
   *
   * If this is not set, it defaults to the value returned by
   * `Glib::get_application_name()`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_program_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the program.
   *
   * If this is not set, it defaults to the value returned by
   * `Glib::get_application_name()`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_program_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The version of the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_version() -> Glib::PropertyProxy< Glib::ustring > ;

/** The version of the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_version() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Copyright information for the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_copyright() -> Glib::PropertyProxy< Glib::ustring > ;

/** Copyright information for the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_copyright() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Comments about the program.
   *
   * This string is displayed in a label in the main dialog, thus it
   * should be a short explanation of the main purpose of the program,
   * not a detailed list of features.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_comments() -> Glib::PropertyProxy< Glib::ustring > ;

/** Comments about the program.
   *
   * This string is displayed in a label in the main dialog, thus it
   * should be a short explanation of the main purpose of the program,
   * not a detailed list of features.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_comments() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The URL for the link to the website of the program.
   *
   * This should be a string starting with `http://` or `https://`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_website() -> Glib::PropertyProxy< Glib::ustring > ;

/** The URL for the link to the website of the program.
   *
   * This should be a string starting with `http://` or `https://`.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_website() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The label for the link to the website of the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_website_label() -> Glib::PropertyProxy< Glib::ustring > ;

/** The label for the link to the website of the program.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_website_label() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The license of the program, as free-form text.
   *
   * This string is displayed in a text view in a secondary dialog, therefore
   * it is fine to use a long multi-paragraph text. Note that the text is only
   * wrapped in the text view if the "wrap-license" property is set to <tt>true</tt>;
   * otherwise the text itself must contain the intended linebreaks.
   *
   * When setting this property to a non-<tt>nullptr</tt> value, the
   * property_license_type() property is set to
   * `Gtk::License::CUSTOM` as a side effect.
   *
   * The text may contain links in this format `<http://www.some.place/>`
   * and email references in the form `<mail-to @a some.body>`, and these will
   * be converted into clickable links.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_license() -> Glib::PropertyProxy< Glib::ustring > ;

/** The license of the program, as free-form text.
   *
   * This string is displayed in a text view in a secondary dialog, therefore
   * it is fine to use a long multi-paragraph text. Note that the text is only
   * wrapped in the text view if the "wrap-license" property is set to <tt>true</tt>;
   * otherwise the text itself must contain the intended linebreaks.
   *
   * When setting this property to a non-<tt>nullptr</tt> value, the
   * property_license_type() property is set to
   * `Gtk::License::CUSTOM` as a side effect.
   *
   * The text may contain links in this format `<http://www.some.place/>`
   * and email references in the form `<mail-to @a some.body>`, and these will
   * be converted into clickable links.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_license() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The license of the program.
   *
   * The `Gtk::AboutDialog` will automatically fill out a standard disclaimer
   * and link the user to the appropriate online resource for the license
   * text.
   *
   * If `Gtk::License::UNKNOWN` is used, the link used will be the same
   * specified in the property_website() property.
   *
   * If `Gtk::License::CUSTOM` is used, the current contents of the
   * property_license() property are used.
   *
   * For any other Gtk::License value, the contents of the
   * property_license() property are also set by this property as
   * a side effect.
   *
   * Default value: Gtk::License::UNKNOWN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_license_type() -> Glib::PropertyProxy< License > ;

/** The license of the program.
   *
   * The `Gtk::AboutDialog` will automatically fill out a standard disclaimer
   * and link the user to the appropriate online resource for the license
   * text.
   *
   * If `Gtk::License::UNKNOWN` is used, the link used will be the same
   * specified in the property_website() property.
   *
   * If `Gtk::License::CUSTOM` is used, the current contents of the
   * property_license() property are used.
   *
   * For any other Gtk::License value, the contents of the
   * property_license() property are also set by this property as
   * a side effect.
   *
   * Default value: Gtk::License::UNKNOWN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_license_type() const -> Glib::PropertyProxy_ReadOnly< License >;

  /** Information about the system on which the program is running.
   *
   * This information is displayed in a separate page, therefore it is fine
   * to use a long multi-paragraph text. Note that the text should contain
   * the intended linebreaks.
   *
   * The text may contain links in this format `<http://www.some.place/>`
   * and email references in the form `<mail-to @a some.body>`, and these will
   * be converted into clickable links.
   *
   * @newin{3,92}
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_system_information() -> Glib::PropertyProxy< Glib::ustring > ;

/** Information about the system on which the program is running.
   *
   * This information is displayed in a separate page, therefore it is fine
   * to use a long multi-paragraph text. Note that the text should contain
   * the intended linebreaks.
   *
   * The text may contain links in this format `<http://www.some.place/>`
   * and email references in the form `<mail-to @a some.body>`, and these will
   * be converted into clickable links.
   *
   * @newin{3,92}
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_system_information() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The authors of the program, as a <tt>nullptr</tt>-terminated array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_authors() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** The authors of the program, as a <tt>nullptr</tt>-terminated array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_authors() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;

  /** The people documenting the program, as a <tt>nullptr</tt>-terminated array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_documenters() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** The people documenting the program, as a <tt>nullptr</tt>-terminated array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_documenters() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;

  /** Credits to the translators.
   *
   * This string should be marked as translatable.
   *
   * The string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_translator_credits() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** Credits to the translators.
   *
   * This string should be marked as translatable.
   *
   * The string may contain email addresses and URLs, which will be displayed
   * as links, see the introduction for more details.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_translator_credits() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;

  /** The people who contributed artwork to the program, as a <tt>nullptr</tt>-terminated
   * array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_artists() -> Glib::PropertyProxy< std::vector<Glib::ustring> > ;

/** The people who contributed artwork to the program, as a <tt>nullptr</tt>-terminated
   * array of strings.
   *
   * Each string may contain email addresses and URLs, which will be displayed
   * as links.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_artists() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;

  /** A logo for the about box.
   *
   * If it is <tt>nullptr</tt>, the default window icon set with
   * Gtk::Window::set_default_icon_name() will be used.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_logo() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> > ;

/** A logo for the about box.
   *
   * If it is <tt>nullptr</tt>, the default window icon set with
   * Gtk::Window::set_default_icon_name() will be used.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_logo() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >;

  /** A named icon to use as the logo for the about box.
   *
   * This property overrides the property_logo() property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_logo_icon_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** A named icon to use as the logo for the about box.
   *
   * This property overrides the property_logo() property.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_logo_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to wrap the text in the license dialog.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_license() -> Glib::PropertyProxy< bool > ;

/** Whether to wrap the text in the license dialog.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_wrap_license() const -> Glib::PropertyProxy_ReadOnly< bool >;


  // no_default_handler because GtkAboutDialogClass is private.

  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%activate_link(const std::string& uri)</tt>
   *
   * Flags: Run Last
   *
   * Emitted every time a URL is activated.
   *
   * Applications may connect to it to override the default behaviour,
   * which is to call gtk_show_uri().
   *
   * @param uri The URI that is activated.
   * @return <tt>true</tt> if the link has been activated.
   */

  auto signal_activate_link() -> Glib::SignalProxy<bool(const std::string&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::AboutDialog
   */
  GTKMM_API
  auto wrap(GtkAboutDialog* object, bool take_copy = false) -> Gtk::AboutDialog*;
} //namespace Glib


#endif /* _GTKMM_ABOUTDIALOG_H */
