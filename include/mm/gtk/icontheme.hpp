// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_ICONTHEME_H
#define _GTKMM_ICONTHEME_H


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003 The gtkmm Development Team
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

#include <mm/gdk/paintable.hpp>
#include <mm/gdk/display.hpp>
#include <mm/gtk/enums.hpp>
#include <mm/gtk/iconpaintable.hpp>
#include <mm/gio/icon.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconTheme = struct _GtkIconTheme;
using GtkIconThemeClass = struct _GtkIconThemeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API IconTheme_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 *  @var IconLookupFlags FORCE_REGULAR
 * Try to always load regular icons, even
 * when symbolic icon names are given.
 *
 *  @var IconLookupFlags FORCE_SYMBOLIC
 * Try to always load symbolic icons, even
 * when regular icon names are given.
 *
 *  @var IconLookupFlags PRELOAD
 * Starts loading the texture in the background
 * so it is ready when later needed.
 *
 *  @enum IconLookupFlags
 *
 * Used to specify options for Gtk::IconTheme::lookup_icon().
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>IconLookupFlags operator|(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags operator&(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags operator^(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags operator~(IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags& operator|=(IconLookupFlags&, IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags& operator&=(IconLookupFlags&, IconLookupFlags)</tt><br>
 * <tt>IconLookupFlags& operator^=(IconLookupFlags&, IconLookupFlags)</tt><br>
 */
enum class IconLookupFlags
{
  FORCE_REGULAR = 1 << 0,
  FORCE_SYMBOLIC = 1 << 1,
  PRELOAD = 1 << 2
};

/** @ingroup gtkmmEnums */
inline auto operator|(IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(IconLookupFlags lhs, IconLookupFlags rhs) -> IconLookupFlags
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(IconLookupFlags flags) -> IconLookupFlags
  { return static_cast<IconLookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(IconLookupFlags& lhs, IconLookupFlags rhs) -> IconLookupFlags&
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**  %Exception class for Gtk::IconTheme errors.
 */
class IconThemeError : public Glib::Error
{
public:
  /**  @var Code ICON_THEME_NOT_FOUND
   * The icon specified does not exist in the theme.
   *
   *  @var Code ICON_THEME_FAILED
   * An unspecified error occurred.
   *
   *  @enum Code
   *
   * %Error codes for `Gtk::IconTheme` operations.
   */
  enum Code
  {
    ICON_THEME_NOT_FOUND,
    ICON_THEME_FAILED
  };

  GTKMM_API IconThemeError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit IconThemeError(GError* gobject);
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
class GTKMM_API Value<Gtk::IconThemeError::Code> : public Glib::Value_Enum<Gtk::IconThemeError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Looking up icons by name.
 *
 * %Gtk::IconTheme provides a facility for looking up icons by name
 * and size. The main reason for using a name rather than simply
 * providing a filename is to allow different icons to be used
 * depending on what “icon theme” is selected by the user.
 * The operation of icon themes on Linux and Unix follows the
 * [IconPaintable Theme Specification](http://www.freedesktop.org/Standards/icon-theme-spec).
 * There is a fallback icon theme, named `hicolor`, where applications
 * should install their icons, but additional icon themes can be installed
 * as operating system vendors and users choose.
 *
 * In many cases, named themes are used indirectly, via Gtk::Image
 * rather than directly, but looking up icons
 * directly is also simple. The %Gtk::IconTheme object acts
 * as a database of all the icons in the current theme. You
 * can create new %Gtk::IconTheme objects, but it’s much more
 * efficient to use the standard icon theme for the Gdk::Display
 * so that the icon information is shared with other people
 * looking up icons. Use get_for_display().
 */

class GTKMM_API IconTheme : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = IconTheme;
  using CppClassType = IconTheme_Class;
  using BaseObjectType = GtkIconTheme;
  using BaseClassType = GtkIconThemeClass;

  // noncopyable
  IconTheme(const IconTheme&) = delete;
  auto operator=(const IconTheme&) -> IconTheme& = delete;

private:  friend class IconTheme_Class;
  static CppClassType icontheme_class_;

protected:
  explicit IconTheme(const Glib::ConstructParams& construct_params);
  explicit IconTheme(GtkIconTheme* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  IconTheme(IconTheme&& src) noexcept;
  auto operator=(IconTheme&& src) noexcept -> IconTheme&;

  ~IconTheme() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkIconTheme*       { return reinterpret_cast<GtkIconTheme*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkIconTheme* { return reinterpret_cast<GtkIconTheme*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkIconTheme*;

private:


protected:
  IconTheme();
public:

  static auto create() -> Glib::RefPtr<IconTheme>;


  /** Gets the icon theme object associated with @a display.
   *
   * If this function has not previously been called for the given
   * display, a new icon theme object will be created and associated
   * with the display. Icon theme objects are fairly expensive to create,
   * so using this function is usually a better choice than calling
   * new() and setting the display yourself; by using
   * this function a single icon theme object will be shared between users.
   *
   * @param display A `Gdk::Display`.
   * @return A unique `Gtk::IconTheme` associated with
   * the given display. This icon theme is associated with the display
   * and can be used as long as the display is open. Do not ref or unref it.
   */
  static auto get_for_display(const Glib::RefPtr<Gdk::Display>& display) -> Glib::RefPtr<IconTheme>;


  /** Returns the display that the `Gtk::IconTheme` object was
   * created for.
   *
   * @return The display of @a icon_theme.
   */
  auto get_display() -> Glib::RefPtr<Gdk::Display>;

  /** Returns the display that the `Gtk::IconTheme` object was
   * created for.
   *
   * @return The display of @a icon_theme.
   */
  auto get_display() const -> Glib::RefPtr<const Gdk::Display>;


  /** Sets the search path for the icon theme object.
   *
   * When looking for an icon theme, GTK will search for a subdirectory
   * of one or more of the directories in @a path with the same name
   * as the icon theme containing an index.theme file. (Themes from
   * multiple of the path elements are combined to allow themes to be
   * extended by adding icons in the user’s home directory.)
   *
   * In addition if an icon found isn’t found either in the current
   * icon theme or the default icon theme, and an image file with
   * the right name is found directly in one of the elements of
   *  @a path, then that image will be used for the icon name.
   * (This is legacy feature, and new icons should be put
   * into the fallback icon theme, which is called hicolor,
   * rather than directly on the icon path.)
   *
   * @param path <tt>nullptr</tt>-terminated
   * array of directories that are searched for icon themes.
   */
  void set_search_path(const std::vector<std::string>& path);


  /** Gets the current search path.
   *
   * See set_search_path().
   *
   * @return A list of icon theme path directories.
   */
  auto get_search_path() const -> std::vector<std::string>;

  /** Appends a directory to the search path.
   *
   * See set_search_path().
   *
   * @param path Directory name to append to the icon path.
   */
  void add_search_path(const std::string& path);


  /** Sets the resource paths that will be looked at when
   * looking for icons, similar to search paths.
   *
   * The resources are considered as part of the hicolor icon theme
   * and must be located in subdirectories that are defined in the
   * hicolor icon theme, such as ` @a path/16x16/actions/run.png`
   * or ` @a path/scalable/actions/run.svg`.
   *
   * Icons that are directly placed in the resource path instead
   * of a subdirectory are also considered as ultimate fallback,
   * but they are treated like unthemed icons.
   *
   * @param path <tt>nullptr</tt>-terminated array of resource paths
   * that are searched for icons.
   */
  void set_resource_path(const std::vector<std::string>& path);

  /** Gets the current resource path.
   *
   * See set_resource_path().
   *
   * @return A list of resource paths.
   */
  auto get_resource_path() const -> std::vector<std::string>;

  /** Adds a resource path that will be looked at when looking
   * for icons, similar to search paths.
   *
   * See set_resource_path().
   *
   * This function should be used to make application-specific icons
   * available as part of the icon theme.
   *
   * @param path A resource path.
   */
  void add_resource_path(const std::string& path);


  /** Sets the name of the icon theme that the `Gtk::IconTheme` object uses
   * overriding system configuration.
   *
   * This function cannot be called on the icon theme objects returned
   * from get_for_display().
   *
   * @param theme_name Name of icon theme to use instead of
   * configured theme, or <tt>nullptr</tt> to unset a previously set custom theme.
   */
  void set_theme_name(const Glib::ustring& theme_name);

  /** Gets the current icon theme name.
   *
   * @return The current icon theme name,.
   */
  auto get_theme_name() const -> Glib::ustring;

  /** Checks whether an icon theme includes an icon
   * for a particular name.
   *
   * @param icon_name The name of an icon.
   * @return <tt>true</tt> if @a self includes an
   * icon for @a icon_name.
   */
  auto has_icon(const Glib::ustring& icon_name) const -> bool;

  /** Checks whether an icon theme includes an icon
   * for a particular `Gio::Icon`.
   *
   * @newin{4,2}
   *
   * @param gicon A `Gio::Icon`.
   * @return <tt>true</tt> if @a self includes an icon for @a gicon.
   */
  auto has_gicon(const Glib::RefPtr<const Gio::Icon>& gicon) const -> bool;


  /** Returns an array of integers describing the sizes at which
   * the icon is available without scaling.
   *
   * A size of -1 means that the icon is available in a scalable
   * format. The array is zero-terminated.
   *
   * @param icon_name The name of an icon.
   * @return A newly
   * allocated array describing the sizes at which the icon is
   * available.
   */
  auto get_icon_sizes(const Glib::ustring& icon_name) const -> std::vector<int>;


  /** Looks up a named icon for a desired size and window scale,
   * returning a `Gtk::IconPaintable`.
   *
   * The icon can then be rendered by using it as a `Gdk::Paintable`,
   * or you can get information such as the filename and size.
   *
   * If the available @a icon_name is not available and @a fallbacks are
   * provided, they will be tried in order.
   *
   * If no matching icon is found, then a paintable that renders the
   * "missing icon" icon is returned. If you need to do something else
   * for missing icons you need to use has_icon().
   *
   * Note that you probably want to listen for icon theme changes and
   * update the icon. This is usually done by overriding the
   * GtkWidgetClass.css-changed() function.
   *
   * @param icon_name The name of the icon to lookup.
   * @param size Desired icon size.
   * @param scale The window scale this will be displayed on.
   * @param direction Text direction the icon will be displayed in.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A `Gtk::IconPaintable` object
   * containing the icon.
   */
  auto lookup_icon(const Glib::ustring& icon_name, const std::vector<Glib::ustring>& fallbacks, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) -> Glib::RefPtr<IconPaintable>;

  /// A lookup_icon() convenience overload.
  auto lookup_icon(const Glib::ustring& icon_name, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) -> Glib::RefPtr<IconPaintable>;

  /** Looks up a named icon for a desired size and window scale,
   * returning a `Gtk::IconPaintable`.
   *
   * The icon can then be rendered by using it as a `Gdk::Paintable`,
   * or you can get information such as the filename and size.
   *
   * If the available @a icon_name is not available and @a fallbacks are
   * provided, they will be tried in order.
   *
   * If no matching icon is found, then a paintable that renders the
   * "missing icon" icon is returned. If you need to do something else
   * for missing icons you need to use has_icon().
   *
   * Note that you probably want to listen for icon theme changes and
   * update the icon. This is usually done by overriding the
   * GtkWidgetClass.css-changed() function.
   *
   * @param icon_name The name of the icon to lookup.
   * @param size Desired icon size.
   * @param scale The window scale this will be displayed on.
   * @param direction Text direction the icon will be displayed in.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A `Gtk::IconPaintable` object
   * containing the icon.
   */
  auto lookup_icon(const Glib::ustring& icon_name, const std::vector<Glib::ustring>& fallbacks, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) const -> Glib::RefPtr<const IconPaintable>;

  /// A lookup_icon() convenience overload.
  auto lookup_icon(const Glib::ustring& icon_name, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) const -> Glib::RefPtr<const IconPaintable>;


  /** Looks up a icon for a desired size and window scale.
   *
   * The icon can then be rendered by using it as a `Gdk::Paintable`,
   * or you can get information such as the filename and size.
   *
   * @param icon The `Gio::Icon` to look up.
   * @param size Desired icon size.
   * @param scale The desired scale.
   * @param direction Text direction the icon will be displayed in.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A `Gtk::IconPaintable` containing
   * information about the icon. Unref with Glib::object_unref().
   */
  auto lookup_icon(const Glib::RefPtr<const Gio::Icon>& icon, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) -> Glib::RefPtr<IconPaintable>;

  /** Looks up a icon for a desired size and window scale.
   *
   * The icon can then be rendered by using it as a `Gdk::Paintable`,
   * or you can get information such as the filename and size.
   *
   * @param icon The `Gio::Icon` to look up.
   * @param size Desired icon size.
   * @param scale The desired scale.
   * @param direction Text direction the icon will be displayed in.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A `Gtk::IconPaintable` containing
   * information about the icon. Unref with Glib::object_unref().
   */
  auto lookup_icon(const Glib::RefPtr<const Gio::Icon>& icon, int size, int scale =  1, TextDirection direction =  TextDirection::NONE, IconLookupFlags flags =  (IconLookupFlags)0) const -> Glib::RefPtr<const IconPaintable>;


  /** Lists the names of icons in the current icon theme.
   *
   * @return A vector holding the names of all the icons in the theme.
   */
  auto get_icon_names() const -> std::vector<Glib::ustring>;

  // no_default_handler because GtkIconThemeClass is private.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the icon theme changes.
   *
   * This can happen becuase current icon theme is switched or
   * because GTK detects that a change has occurred in the
   * contents of the current icon theme.
   */

  auto signal_changed() -> Glib::SignalProxy<void()>;


  /** The display that this icon theme object is attached to.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Display> > ;

/** The display that this icon theme object is attached to.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Display> >;

  /** The icon names that are supported by the icon theme.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_icon_names() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >;


  /** The search path for this icon theme.
   *
   * When looking for icons, GTK will search for a subdirectory of
   * one or more of the directories in the search path with the same
   * name as the icon theme containing an index.theme file. (Themes
   * from multiple of the path elements are combined to allow themes
   * to be extended by adding icons in the user’s home directory.)
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_path() -> Glib::PropertyProxy< std::vector<std::string> > ;

/** The search path for this icon theme.
   *
   * When looking for icons, GTK will search for a subdirectory of
   * one or more of the directories in the search path with the same
   * name as the icon theme containing an index.theme file. (Themes
   * from multiple of the path elements are combined to allow themes
   * to be extended by adding icons in the user’s home directory.)
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_search_path() const -> Glib::PropertyProxy_ReadOnly< std::vector<std::string> >;

  /** Resource paths that will be looked at when looking for icons,
   * similar to search paths.
   *
   * The resources are considered as part of the hicolor icon theme
   * and must be located in subdirectories that are defined in the
   * hicolor icon theme, such as ` @a path/16x16/actions/run.png`.
   * Icons that are directly placed in the resource path instead
   * of a subdirectory are also considered as ultimate fallback.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource_path() -> Glib::PropertyProxy< std::vector<std::string> > ;

/** Resource paths that will be looked at when looking for icons,
   * similar to search paths.
   *
   * The resources are considered as part of the hicolor icon theme
   * and must be located in subdirectories that are defined in the
   * hicolor icon theme, such as ` @a path/16x16/actions/run.png`.
   * Icons that are directly placed in the resource path instead
   * of a subdirectory are also considered as ultimate fallback.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_resource_path() const -> Glib::PropertyProxy_ReadOnly< std::vector<std::string> >;

  /** The name of the icon theme that is being used.
   *
   * Unless set to a different value, this will be the value of
   * the `GtkSettings:gtk-icon-theme-name` property of the `Gtk::Settings`
   * object associated to the display of the icontheme object.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_theme_name() -> Glib::PropertyProxy< Glib::ustring > ;

/** The name of the icon theme that is being used.
   *
   * Unless set to a different value, this will be the value of
   * the `GtkSettings:gtk-icon-theme-name` property of the `Gtk::Settings`
   * object associated to the display of the icontheme object.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_theme_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


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
   * @relates Gtk::IconTheme
   */
  GTKMM_API
  auto wrap(GtkIconTheme* object, bool take_copy = false) -> Glib::RefPtr<Gtk::IconTheme>;
}


#endif /* _GTKMM_ICONTHEME_H */
