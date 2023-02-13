
#ifndef _GTKMM_EMOJICHOOSER_H
#define _GTKMM_EMOJICHOOSER_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gtk/popover.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEmojiChooser = struct _GtkEmojiChooser;
using GtkEmojiChooserClass = struct _GtkEmojiChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API EmojiChooser_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A popover to choose an Emoji character.
 *
 * The %Gtk::EmojiChooser popover is used by text widgets such as Gtk::Entry or
 * Gtk::TextView to offer users a convenient way to insert Emoji characters.
 *
 * %Gtk::EmojiChooser emits signal_emoji_picked() when an Emoji is selected.
 *
 * @newin{3,96}
 *
 * @ingroup Widgets
 * @ingroup Containers
 */

class GTKMM_API EmojiChooser : public Popover
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef EmojiChooser CppObjectType;
  typedef EmojiChooser_Class CppClassType;
  typedef GtkEmojiChooser BaseObjectType;
  typedef GtkEmojiChooserClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  EmojiChooser(EmojiChooser&& src) noexcept;
  auto operator=(EmojiChooser&& src) noexcept -> EmojiChooser&;

  // noncopyable
  EmojiChooser(const EmojiChooser&) = delete;
  auto operator=(const EmojiChooser&) -> EmojiChooser& = delete;

  ~EmojiChooser() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend GTKMM_API class EmojiChooser_Class;
  static CppClassType emojichooser_class_;

protected:
  explicit EmojiChooser(const Glib::ConstructParams& construct_params);
  explicit EmojiChooser(GtkEmojiChooser* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  auto       gobj() -> GtkEmojiChooser*       { return reinterpret_cast<GtkEmojiChooser*>(gobject_); }

  /// Provides access to the underlying C GObject.
  auto gobj() const -> const GtkEmojiChooser* { return reinterpret_cast<GtkEmojiChooser*>(gobject_); }

private:


public:

  EmojiChooser();

  // no_default_handler because the wrapped C signal has no default handler.

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%emoji_picked(const Glib::ustring& text)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the user selects an Emoji.
   *
   * @param text The Unicode sequence for the picked Emoji, in UTF-8.
   */

  auto signal_emoji_picked() -> Glib::SignalProxy<void(const Glib::ustring&)>;


  // PopoverMenu has no properties nor vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::EmojiChooser
   */
  GTKMM_API
  auto wrap(GtkEmojiChooser* object, bool take_copy = false) -> Gtk::EmojiChooser*;
} //namespace Glib


#endif /* _GTKMM_EMOJICHOOSER_H */

