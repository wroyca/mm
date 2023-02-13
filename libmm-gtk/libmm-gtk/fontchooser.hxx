
#ifndef _GTKMM_FONTCHOOSER_H
#define _GTKMM_FONTCHOOSER_H

#include <libmm-gtk/mm-gtkconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2011 The gtkmm Development Team
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


#include <libmm-glib/interface.hxx>
#include <libmm-pango/fontface.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/fontfamily.hxx>
#include <libmm-pango/fontmap.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkFontChooserIface GtkFontChooserIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFontChooser = struct _GtkFontChooser;
using GtkFontChooserClass = struct _GtkFontChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API FontChooser_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** An interface implemented by widgets displaying fonts.
 *
 * FontChooser widgets list the available fonts, styles and
 * sizes, allowing the user to select a font.
 *
 * To set the font which is initially selected, use set_font_name().
 *
 * To get the selected font use get_font_name().
 *
 * To change the text which is shown in the preview area, use set_preview_text().
 *
 * @ingroup FontChooser
 * @newin{3,2}
 */

class GTKMM_API FontChooser : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = FontChooser;
  using CppClassType = FontChooser_Class;
  using BaseObjectType = GtkFontChooser;
  using BaseClassType = GtkFontChooserIface;

  // noncopyable
  FontChooser(const FontChooser&) = delete;
  auto operator=(const FontChooser&) -> FontChooser& = delete;

private:
  friend class FontChooser_Class;
  static CppClassType fontchooser_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  FontChooser();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit FontChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit FontChooser(GtkFontChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  FontChooser(FontChooser&& src) noexcept;
  auto operator=(FontChooser&& src) noexcept -> FontChooser&;

  ~FontChooser() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkFontChooser*       { return reinterpret_cast<GtkFontChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkFontChooser* { return reinterpret_cast<GtkFontChooser*>(gobject_); }

private:

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Level FAMILY
   * Allow selecting a font family.
   *
   *  @var Level STYLE
   * Allow selecting a specific font face.
   *
   *  @var Level SIZE
   * Allow selecting a specific font size.
   *
   *  @var Level VARIATIONS
   * Allow changing OpenType font variation axes.
   *
   *  @var Level FEATURES
   * Allow selecting specific OpenType font features.
   *
   *  @enum Level
   *
   * Specifies the granularity of font selection
   * that is desired in a `Gtk::FontChooser`.
   *
   * This enumeration may be extended in the future; applications should
   * ignore unknown values.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>FontChooser::Level operator|(FontChooser::Level, FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level operator&(FontChooser::Level, FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level operator^(FontChooser::Level, FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level operator~(FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level& operator|=(FontChooser::Level&, FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level& operator&=(FontChooser::Level&, FontChooser::Level)</tt><br>
   * <tt>FontChooser::Level& operator^=(FontChooser::Level&, FontChooser::Level)</tt><br>
   */
  enum class Level
  {
    FAMILY = 0x0,
    STYLE = 1 << 0,
    SIZE = 1 << 1,
    VARIATIONS = 1 << 2,
    FEATURES = 1 << 3
  };


  /** Gets the `Pango::FontFamily` representing the selected font family.
   *
   * Font families are a collection of font faces.
   *
   * If the selected font is not installed, returns <tt>nullptr</tt>.
   *
   * @return A `Pango::FontFamily` representing the
   * selected font family.
   */
  auto get_font_family() -> Glib::RefPtr<Pango::FontFamily>;

  /** Gets the `Pango::FontFamily` representing the selected font family.
   *
   * Font families are a collection of font faces.
   *
   * If the selected font is not installed, returns <tt>nullptr</tt>.
   *
   * @return A `Pango::FontFamily` representing the
   * selected font family.
   */
  auto get_font_family() const -> Glib::RefPtr<const Pango::FontFamily>;


  /** Gets the `Pango::FontFace` representing the selected font group
   * details (i.e.\ family, slant, weight, width, etc).
   *
   * If the selected font is not installed, returns <tt>nullptr</tt>.
   *
   * @return A `Pango::FontFace` representing the
   * selected font group details.
   */
  auto get_font_face() -> Glib::RefPtr<Pango::FontFace>;

  /** Gets the `Pango::FontFace` representing the selected font group
   * details (i.e.\ family, slant, weight, width, etc).
   *
   * If the selected font is not installed, returns <tt>nullptr</tt>.
   *
   * @return A `Pango::FontFace` representing the
   * selected font group details.
   */
  auto get_font_face() const -> Glib::RefPtr<const Pango::FontFace>;


  /** The selected font size.
   *
   * @return A n integer representing the selected font size,
   * or -1 if no font size is selected.
   */
  auto get_font_size() const -> int;


  /** Gets the currently-selected font.
   *
   * Note that this can be a different string than what you set with
   * set_font(), as the font chooser widget may
   * normalize font names and thus return a string with a different
   * structure. For example, “Helvetica Italic Bold 12” could be
   * normalized to “Helvetica Bold Italic 12”.
   *
   * Use Pango::FontDescription::equal() if you want to compare two
   * font descriptions.
   *
   * @return A `Pango::FontDescription` for the
   * current font.
   */
  auto get_font_desc() const -> Pango::FontDescription;

  /** Sets the currently-selected font from @a font_desc.
   *
   * @param font_desc A `Pango::FontDescription`.
   */
  void set_font_desc(const Pango::FontDescription& font_desc);


  /** Gets the currently-selected font name.
   *
   * Note that this can be a different string than what you set with
   * set_font(), as the font chooser widget may
   * normalize font names and thus return a string with a different
   * structure. For example, “Helvetica Italic Bold 12” could be
   * normalized to “Helvetica Bold Italic 12”.
   *
   * Use Pango::FontDescription::equal() if you want to compare two
   * font descriptions.
   *
   * @return A string with the name
   * of the current font.
   */
  auto get_font() const -> Glib::ustring;

  /** Sets the currently-selected font.
   *
   * @param fontname A font name like “Helvetica 12” or “Times Bold 18”.
   */
  void set_font(const Glib::ustring& fontname);

  /** Gets the text displayed in the preview area.
   *
   * @return The text displayed in the preview area.
   */
  auto get_preview_text() const -> Glib::ustring;

  /** Sets the text displayed in the preview area.
   *
   * The @a text is used to show how the selected font looks.
   *
   * @param text The text to display in the preview area.
   */
  void set_preview_text(const Glib::ustring& text);


  /** Returns whether the preview entry is shown or not.
   *
   * @return <tt>true</tt> if the preview entry is shown or <tt>false</tt> if it is hidden.
   */
  auto get_show_preview_entry() const -> bool;

  /** Shows or hides the editable preview entry.
   *
   * @param show_preview_entry Whether to show the editable preview entry or not.
   */
  void set_show_preview_entry(bool show_preview_entry =  true);

  /** Font filter callback.
   * For instance,
   * @code
   * bool on_font_fitler(const Glib::RefPtr<const Pango::FontFamily>& font_family, const Glib::RefPtr<const Pango::FontFace>& font_face);
   * @endcode
   *
   * @param font_family A Pango FontFamily.
   * @param font_face A Font Face belonging to the @a font_family.
   * @result true if the font should be displayed.
   *
   * This is used for deciding what fonts should be shown in a FontChooser.
   * See set_filter_func().
   *
   * @newin{3,4}
   */
  typedef sigc::slot<bool(const Glib::RefPtr<const Pango::FontFamily>&, const Glib::RefPtr<const Pango::FontFace>&)> SlotFontFilter;

  /** Adds a filter function that decides which fonts to display in the font chooser.
   *
   * @param slot A callback, to be called for each font.
   *
   * @newin{3,4}
   */
  void set_filter_func(const SlotFontFilter& slot);


  /** Sets a custom font map to use for this font chooser widget.
   *
   * A custom font map can be used to present application-specific
   * fonts instead of or in addition to the normal system fonts.
   *
   *
   * [C example ellipted]
   *
   * Note that other GTK widgets will only be able to use the
   * application-specific font if it is present in the font map they use:
   *
   *
   * [C example ellipted]
   *
   * @param fontmap A `Pango::FontMap`.
   */
  void set_font_map(const Glib::RefPtr<Pango::FontMap>& fontmap);


  /** Gets the custom font map of this font chooser widget,
   * or <tt>nullptr</tt> if it does not have one.
   *
   * @return A `Pango::FontMap`.
   */
  auto get_font_map() -> Glib::RefPtr<Pango::FontMap>;

  /** Gets the custom font map of this font chooser widget,
   * or <tt>nullptr</tt> if it does not have one.
   *
   * @return A `Pango::FontMap`.
   */
  auto get_font_map() const -> Glib::RefPtr<const Pango::FontMap>;


  /** Sets the desired level of granularity for selecting fonts.
   *
   * @param level The desired level of granularity.
   */
  void set_level(Level level);

  /** Returns the current level of granularity for selecting fonts.
   *
   * @return The current granularity level.
   */
  auto get_level() const -> Level;

  /** Gets the currently-selected font features.
   *
   * @return The currently selected font features.
   */
  auto get_font_features() const -> Glib::ustring;

  /** Gets the language that is used for font features.
   *
   * @return The currently selected language.
   */
  auto get_language() const -> Glib::ustring;

  /** Sets the language to use for font features.
   *
   * @param language A language.
   */
  void set_language(const Glib::ustring& language);


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%font_activated(const Glib::ustring& fontname)</tt>
   *
   * Flags: Run First
   *
   * Emitted when a font is activated.
   *
   * This usually happens when the user double clicks an item,
   * or an item is selected and the user presses one of the keys
   * Space, Shift+Space, Return or Enter.
   *
   * @param fontname The font name.
   */

  auto signal_font_activated() -> Glib::SignalProxy<void(const Glib::ustring&)>;


  /** The font description as a string, e.g.\ "Sans Italic 12".
   *
   * Default value: "Sans 10"
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() -> Glib::PropertyProxy< Glib::ustring > ;

/** The font description as a string, e.g.\ "Sans Italic 12".
   *
   * Default value: "Sans 10"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** The font description as a `Pango::FontDescription`.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription > ;

/** The font description as a `Pango::FontDescription`.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >;

  /** The string with which to preview the font.
   *
   * Default value: "The quick brown fox jumps over the lazy dog."
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_preview_text() -> Glib::PropertyProxy< Glib::ustring > ;

/** The string with which to preview the font.
   *
   * Default value: "The quick brown fox jumps over the lazy dog."
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_preview_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;

  /** Whether to show an entry to change the preview text.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_preview_entry() -> Glib::PropertyProxy< bool > ;

/** Whether to show an entry to change the preview text.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_show_preview_entry() const -> Glib::PropertyProxy_ReadOnly< bool >;

  /** The level of granularity to offer for selecting fonts.
   *
   * Default value: Gtk::FontChooser::Level::STYLE | Gtk::FontChooser::Level::SIZE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_level() -> Glib::PropertyProxy< Level > ;

/** The level of granularity to offer for selecting fonts.
   *
   * Default value: Gtk::FontChooser::Level::STYLE | Gtk::FontChooser::Level::SIZE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_level() const -> Glib::PropertyProxy_ReadOnly< Level >;

  /** The selected font features.
   *
   * The format of the string is compatible with
   * CSS and with Pango attributes.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_font_features() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The language for which the font features were selected.
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() -> Glib::PropertyProxy< Glib::ustring > ;

/** The language for which the font features were selected.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_font_activated().
  virtual void on_font_activated(const Glib::ustring& fontname);


};

} // namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  { return static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  { return static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(FontChooser::Level lhs, FontChooser::Level rhs) -> FontChooser::Level
  { return static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(FontChooser::Level flags) -> FontChooser::Level
  { return static_cast<FontChooser::Level>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  { return (lhs = static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  { return (lhs = static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(FontChooser::Level& lhs, FontChooser::Level rhs) -> FontChooser::Level&
  { return (lhs = static_cast<FontChooser::Level>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::FontChooser::Level> : public Glib::Value_Flags<Gtk::FontChooser::Level>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::FontChooser
   */
  GTKMM_API
  auto wrap(GtkFontChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FontChooser>;

} // namespace Glib


#endif /* _GTKMM_FONTCHOOSER_H */

