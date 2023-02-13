
#ifndef _GTKMM_CSSPROVIDER_H
#define _GTKMM_CSSPROVIDER_H


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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

#include <libmm-gtk/styleprovider.hxx>
#include <libmm-gtk/csssection.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gio/file.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCssProvider = struct _GtkCssProvider;
using GtkCssProviderClass = struct _GtkCssProviderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CssProvider_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/**  @newin{3,96}
 */
class CssParserError : public Glib::Error
{
public:
  /**  @var Code FAILED
   * Unknown failure.
   *
   *  @var Code SYNTAX
   * The given text does not form valid syntax.
   *
   *  @var Code IMPORT
   * Failed to import a resource.
   *
   *  @var Code NAME
   * The given name has not been defined.
   *
   *  @var Code UNKNOWN_VALUE
   * The given value is not correct.
   *
   *  @enum Code
   *
   * Errors that can occur while parsing CSS.
   *
   * These errors are unexpected and will cause parts of the given CSS
   * to be ignored.
   *
   * @newin{3,96}
   */
  enum Code
  {
    FAILED,
    SYNTAX,
    IMPORT,
    NAME,
    UNKNOWN_VALUE
  };

  GTKMM_API CssParserError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit CssParserError(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CssParserError::Code> : public Glib::Value_Enum<Gtk::CssParserError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/**  @newin{3,96}
 */
class CssParserWarning : public Glib::Error
{
public:
  /**  @var Code DEPRECATED
   * The given construct is
   * deprecated and will be removed in a future version.
   *
   *  @var Code SYNTAX
   * A syntax construct was used
   * that should be avoided.
   *
   *  @var Code UNIMPLEMENTED
   * A feature is not implemented.
   *
   *  @enum Code
   *
   * Warnings that can occur while parsing CSS.
   *
   * Unlike `Gtk::CssParserError`s, warnings do not cause the parser to
   * skip any input, but they indicate issues that should be fixed.
   *
   * @newin{3,96}
   */
  enum Code
  {
    DEPRECATED,
    SYNTAX,
    UNIMPLEMENTED
  };

  GTKMM_API CssParserWarning(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit CssParserWarning(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CssParserWarning::Code> : public Glib::Value_Enum<Gtk::CssParserWarning::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** CSS-like styling for widgets, implementing the StyleProvider base class.
 *
 * It is able to parse <a href="http://www.w3.org/TR/CSS2">CSS</a>-like
 * input in order to style widgets.
 *
 * An application can cause GTK+ to parse a specific CSS style sheet by
 * calling load_from_file() and adding the provider with
 * StyleContext::add_provider() or StyleContext::add_provider_for_screen().
 * In addition, certain files will be read when GTK+ is initialized.
 * See the <a href="http://library.gnome.org/devel/gtk3/unstable/GtkCssProvider.html#GtkCssProvider.description">GtkCssProvider documentation</a> for details of these default files and details of the stylesheets.
 *
 * @newin{3,0}
 */

class GTKMM_API CssProvider
  : public Glib::Object,
    public StyleProvider
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CssProvider;
  using CppClassType = CssProvider_Class;
  using BaseObjectType = GtkCssProvider;
  using BaseClassType = GtkCssProviderClass;

  // noncopyable
  CssProvider(const CssProvider&) = delete;
  auto operator=(const CssProvider&) -> CssProvider& = delete;

private:  friend class CssProvider_Class;
  static CppClassType cssprovider_class_;

protected:
  explicit CssProvider(const Glib::ConstructParams& construct_params);
  explicit CssProvider(GtkCssProvider* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CssProvider(CssProvider&& src) noexcept;
  auto operator=(CssProvider&& src) noexcept -> CssProvider&;

  ~CssProvider() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCssProvider*       { return reinterpret_cast<GtkCssProvider*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCssProvider* { return reinterpret_cast<GtkCssProvider*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkCssProvider*;

private:


protected:
  CssProvider();


public:

  static auto create() -> Glib::RefPtr<CssProvider>;


  /** Converts the @a provider into a string representation in CSS
   * format.
   *
   * Using load_from_data() with the return
   * value from this function on a new provider created with
   * new() will basically create a duplicate
   * of this @a provider.
   *
   * @return A new string representing the @a provider.
   */
  auto to_string() const -> Glib::ustring;

  /** Loads @a data into this css provider, making it clear any previously loaded information.
   *
   * @param data CSS data loaded in memory.
   */
  void load_from_data(const std::string& data);


  /** Loads the data contained in @a file into @a css_provider.
   *
   * This clears any previously loaded information.
   *
   * @param file `Gio::File` pointing to a file to load.
   */
  void load_from_file(const Glib::RefPtr<const Gio::File>& file);

  /** Loads the data contained in @a path into @a css_provider.
   *
   * This clears any previously loaded information.
   *
   * @param path The path of a filename to load, in the GLib filename encoding.
   */
  void load_from_path(const std::string& path);

  /** Loads the data contained in the resource at @a resource_path into
   * the @a css_provider.
   *
   * This clears any previously loaded information.
   *
   * @param resource_path A `Gio::Resource` resource path.
   */
  void load_from_resource(const std::string& resource_path);


  /** Loads a theme from the usual theme paths.
   *
   * The actual process of finding the theme might change between
   * releases, but it is guaranteed that this function uses the same
   * mechanism to load the theme that GTK uses for loading its own theme.
   *
   * @param name A theme name.
   * @param variant Variant to load, for example, "dark", or
   * <tt>nullptr</tt> for the default.
   */
  void load_named(const Glib::ustring& name, const Glib::ustring& variant);


  // no_default_handler because GtkCssProviderClass is private.

  /** @param error The parsing error. The referenced object may belong to a subclass of Glib::Error, such as Gtk::CssParserError.
   *
   * @par Slot Prototype:
   * <tt>void on_my_%parsing_error(const Glib::RefPtr<const CssSection>& section, const Glib::Error& error)</tt>
   *
   * Flags: Run Last
   *
   * Signals that a parsing error occurred.
   *
   * The @a path, @a line and @a position describe the actual location of
   * the error as accurately as possible.
   *
   * Parsing errors are never fatal, so the parsing will resume after
   * the error. Errors may however cause parts of the given data or
   * even all of it to not be parsed at all. So it is a useful idea
   * to check that the parsing succeeds by connecting to this signal.
   *
   * Note that this signal may be emitted at any time as the css provider
   * may opt to defer parsing parts or all of the input to a later time
   * than when a loading function was called.
   *
   * @param section Section the error happened in.
   * @param error The parsing error.
   */

  auto signal_parsing_error() -> Glib::SignalProxy<void(const Glib::RefPtr<const CssSection>&, const Glib::Error&)>;


  //There are no properties.


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
   * @relates Gtk::CssProvider
   */
  GTKMM_API
  auto wrap(GtkCssProvider* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CssProvider>;
}


#endif /* _GTKMM_CSSPROVIDER_H */

