
#ifndef _GTKMM_SHORTCUTTRIGGER_H
#define _GTKMM_SHORTCUTTRIGGER_H

#include <libmm-gtk/mm-gtkconfig.hpp>


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


#include <libmm-glib/object.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/event.hpp>
#include <libmm-gdk/enums.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutTrigger = struct _GtkShortcutTrigger;
using GtkShortcutTriggerClass = struct _GtkShortcutTriggerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutTrigger_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNeverTrigger = struct _GtkNeverTrigger;
using GtkNeverTriggerClass = struct _GtkNeverTriggerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NeverTrigger_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkKeyvalTrigger = struct _GtkKeyvalTrigger;
using GtkKeyvalTriggerClass = struct _GtkKeyvalTriggerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API KeyvalTrigger_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMnemonicTrigger = struct _GtkMnemonicTrigger;
using GtkMnemonicTriggerClass = struct _GtkMnemonicTriggerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MnemonicTrigger_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAlternativeTrigger = struct _GtkAlternativeTrigger;
using GtkAlternativeTriggerClass = struct _GtkAlternativeTriggerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API AlternativeTrigger_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
/** Triggers to track if shortcuts should be activated.
 *
 * %Gtk::ShortcutTrigger is the object used to track if a Gtk::Shortcut should be
 * activated. For this purpose, trigger() can be called on a Gdk::Event.
 *
 * ShortcutTriggers contain methods that allow easy presentation to end
 * users as well as being printed for debugging.
 *
 * All ShortcutTriggers are immutable, you can only specify their properties
 * during construction. If you want to change a trigger, you have to replace it
 * with a new one.
 *
 * @see Gtk::Shortcut
 * @ingroup Gestures
 * @newin{3,98}
 */

class GTKMM_API ShortcutTrigger : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ShortcutTrigger;
  using CppClassType = ShortcutTrigger_Class;
  using BaseObjectType = GtkShortcutTrigger;
  using BaseClassType = GtkShortcutTriggerClass;

  // noncopyable
  ShortcutTrigger(const ShortcutTrigger&) = delete;
  auto operator=(const ShortcutTrigger&) -> ShortcutTrigger& = delete;

private:  friend class ShortcutTrigger_Class;
  static CppClassType shortcuttrigger_class_;

protected:
  explicit ShortcutTrigger(const Glib::ConstructParams& construct_params);
  explicit ShortcutTrigger(GtkShortcutTrigger* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ShortcutTrigger(ShortcutTrigger&& src) noexcept;
  auto operator=(ShortcutTrigger&& src) noexcept -> ShortcutTrigger&;

  ~ShortcutTrigger() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutTrigger*       { return reinterpret_cast<GtkShortcutTrigger*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutTrigger* { return reinterpret_cast<GtkShortcutTrigger*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkShortcutTrigger*;

private:

      protected:
  ShortcutTrigger();

public:

  /** Tries to parse the given string into a trigger.
   *
   * On success, the parsed trigger is returned.
   * When parsing failed, <tt>nullptr</tt> is returned.
   *
   * The accepted strings are:
   *
   * - `never`, for `Gtk::NeverTrigger`
   * - a string parsed by gtk_accelerator_parse(), for a `Gtk::KeyvalTrigger`, e.g. `<Control>C`
   * - underscore, followed by a single character, for `Gtk::MnemonicTrigger`, e.g. `_l`
   * - two valid trigger strings, separated by a `|` character, for a
   * `Gtk::AlternativeTrigger`: `<Control>q|<Control>w`
   *
   * Note that you will have to escape the `<` and `>` characters when specifying
   * triggers in XML files, such as GtkBuilder ui files. Use `<` instead of
   * `<` and `>` instead of `>`.
   *
   * @param string The string to parse.
   * @return A new `Gtk::ShortcutTrigger`.
   */
  static auto parse_string(const Glib::ustring& string) -> Glib::RefPtr<ShortcutTrigger>;


  /** Prints the given trigger into a human-readable string.
   *
   * This is meant for debugging and logging.
   * The form of the representation may change at any time and is
   * not guaranteed to stay identical.
   *
   * @return A new string.
   */
  auto to_string() const -> Glib::ustring;


  /** Gets textual representation for the given trigger.
   *
   * This function is returning a translated string for
   * presentation to end users for example in menu items
   * or in help texts.
   *
   * The @a display in use may influence the resulting string in
   * various forms, such as resolving hardware keycodes or by
   * causing display-specific modifier names.
   *
   * The form of the representation may change at any time and is
   * not guaranteed to stay identical.
   *
   * @param display `Gdk::Display` to print for.
   * @return A new string.
   */
  auto to_label(const Glib::RefPtr<const Gdk::Display>& display) const -> Glib::ustring;


  // Is this useful? _WRAP_METHOD(guint hash() const, gtk_shortcut_trigger_hash)


  /** Checks if @a trigger1 and @a trigger2 trigger under the same conditions.
   *
   * The types of @a one and @a two are `gconstpointer` only to allow use of this
   * function with `HashTable`. They must each be a `Gtk::ShortcutTrigger`.
   *
   * @param trigger2 A `Gtk::ShortcutTrigger`.
   * @return <tt>true</tt> if @a trigger1 and @a trigger2 are equal.
   */
  auto equal(const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> bool;

  /** The types of @a trigger1 and @a trigger2 are `gconstpointer` only to allow
   * use of this function as a `CompareFunc`.
   *
   * They must each be a `Gtk::ShortcutTrigger`.
   *
   * @param trigger2 A `Gtk::ShortcutTrigger`.
   * @return An integer less than, equal to, or greater than zero if
   *  @a trigger1 is found, respectively, to be less than, to match,
   * or be greater than @a trigger2.
   */
  auto compare(const Glib::RefPtr<const ShortcutTrigger>& trigger2) const -> int;


  /** Checks if the given @a event triggers @a self.
   *
   * @param event The event to check.
   * @param enable_mnemonics <tt>true</tt> if mnemonics should trigger. Usually the
   * value of this property is determined by checking that the passed
   * in @a event is a Key event and has the right modifiers set.
   * @return Whether the event triggered the shortcut.
   */
  auto trigger(const Glib::RefPtr<const Gdk::Event>& event, bool enable_mnemonics) const -> Gdk::KeyMatch;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};


/** A Gtk::ShortcutTrigger that never triggers.
 */

class GTKMM_API NeverTrigger : public ShortcutTrigger
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NeverTrigger;
  using CppClassType = NeverTrigger_Class;
  using BaseObjectType = GtkNeverTrigger;
  using BaseClassType = GtkNeverTriggerClass;

  // noncopyable
  NeverTrigger(const NeverTrigger&) = delete;
  auto operator=(const NeverTrigger&) -> NeverTrigger& = delete;

private:  friend class NeverTrigger_Class;
  static CppClassType nevertrigger_class_;

protected:
  explicit NeverTrigger(const Glib::ConstructParams& construct_params);
  explicit NeverTrigger(GtkNeverTrigger* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NeverTrigger(NeverTrigger&& src) noexcept;
  auto operator=(NeverTrigger&& src) noexcept -> NeverTrigger&;

  ~NeverTrigger() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNeverTrigger*       { return reinterpret_cast<GtkNeverTrigger*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNeverTrigger* { return reinterpret_cast<GtkNeverTrigger*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkNeverTrigger*;

private:

      protected:
  NeverTrigger();

public:

  /** Gets the never trigger.
   *
   * This is a singleton for a trigger that never triggers.
   * Use this trigger instead of <tt>nullptr</tt> because it implements
   * all virtual functions.
   *
   * @return The never trigger.
   */
  static auto get() -> Glib::RefPtr<NeverTrigger>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutTrigger that triggers when a specific keyval
 * and (optionally) modifiers are pressed.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 */

class GTKMM_API KeyvalTrigger : public ShortcutTrigger
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = KeyvalTrigger;
  using CppClassType = KeyvalTrigger_Class;
  using BaseObjectType = GtkKeyvalTrigger;
  using BaseClassType = GtkKeyvalTriggerClass;

  // noncopyable
  KeyvalTrigger(const KeyvalTrigger&) = delete;
  auto operator=(const KeyvalTrigger&) -> KeyvalTrigger& = delete;

private:  friend class KeyvalTrigger_Class;
  static CppClassType keyvaltrigger_class_;

protected:
  explicit KeyvalTrigger(const Glib::ConstructParams& construct_params);
  explicit KeyvalTrigger(GtkKeyvalTrigger* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  KeyvalTrigger(KeyvalTrigger&& src) noexcept;
  auto operator=(KeyvalTrigger&& src) noexcept -> KeyvalTrigger&;

  ~KeyvalTrigger() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkKeyvalTrigger*       { return reinterpret_cast<GtkKeyvalTrigger*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkKeyvalTrigger* { return reinterpret_cast<GtkKeyvalTrigger*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkKeyvalTrigger*;

private:

      protected:
    explicit KeyvalTrigger(guint keyval, Gdk::ModifierType modifiers);


public:

  static auto create(guint keyval, Gdk::ModifierType modifiers =  static_cast<Gdk::ModifierType>(0)) -> Glib::RefPtr<KeyvalTrigger>;


  /** Gets the keyval that must be pressed to succeed
   * triggering @a self.
   *
   * @return The keyval.
   */
  auto get_keyval() const -> guint;

  /** Gets the modifiers that must be present to succeed
   * triggering @a self.
   *
   * @return The modifiers.
   */
  auto get_modifiers() const -> Gdk::ModifierType;

  /** The key value for the trigger.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keyval() const -> Glib::PropertyProxy_ReadOnly< guint >;


  /** The key modifiers for the trigger.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_modifiers() const -> Glib::PropertyProxy_ReadOnly< Gdk::ModifierType >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutTrigger that triggers when a specific mnemonic is pressed.
 *
 * Key values are the codes which are sent whenever a key is pressed or released.
 * The complete list of key values can be found in the
 * <a href="https://gitlab.gnome.org/GNOME/gtk/tree/main/gdk/gdkkeysyms.h">gdk/gdkkeysyms.h</a>
 * header file. They are prefixed with <tt>GDK_KEY_</tt>.
 */

class GTKMM_API MnemonicTrigger : public ShortcutTrigger
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MnemonicTrigger;
  using CppClassType = MnemonicTrigger_Class;
  using BaseObjectType = GtkMnemonicTrigger;
  using BaseClassType = GtkMnemonicTriggerClass;

  // noncopyable
  MnemonicTrigger(const MnemonicTrigger&) = delete;
  auto operator=(const MnemonicTrigger&) -> MnemonicTrigger& = delete;

private:  friend class MnemonicTrigger_Class;
  static CppClassType mnemonictrigger_class_;

protected:
  explicit MnemonicTrigger(const Glib::ConstructParams& construct_params);
  explicit MnemonicTrigger(GtkMnemonicTrigger* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MnemonicTrigger(MnemonicTrigger&& src) noexcept;
  auto operator=(MnemonicTrigger&& src) noexcept -> MnemonicTrigger&;

  ~MnemonicTrigger() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMnemonicTrigger*       { return reinterpret_cast<GtkMnemonicTrigger*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMnemonicTrigger* { return reinterpret_cast<GtkMnemonicTrigger*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMnemonicTrigger*;

private:

      protected:
    explicit MnemonicTrigger(guint keyval);


public:

  static auto create(guint keyval) -> Glib::RefPtr<MnemonicTrigger>;


  /** Gets the keyval that must be pressed to succeed triggering @a self.
   *
   * @return The keyval.
   */
  auto get_keyval() const -> guint;

  /** The key value for the trigger.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_keyval() const -> Glib::PropertyProxy_ReadOnly< guint >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutTrigger that triggers when either of two ShortcutTriggers trigger.
 */

class GTKMM_API AlternativeTrigger : public ShortcutTrigger
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = AlternativeTrigger;
  using CppClassType = AlternativeTrigger_Class;
  using BaseObjectType = GtkAlternativeTrigger;
  using BaseClassType = GtkAlternativeTriggerClass;

  // noncopyable
  AlternativeTrigger(const AlternativeTrigger&) = delete;
  auto operator=(const AlternativeTrigger&) -> AlternativeTrigger& = delete;

private:  friend class AlternativeTrigger_Class;
  static CppClassType alternativetrigger_class_;

protected:
  explicit AlternativeTrigger(const Glib::ConstructParams& construct_params);
  explicit AlternativeTrigger(GtkAlternativeTrigger* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  AlternativeTrigger(AlternativeTrigger&& src) noexcept;
  auto operator=(AlternativeTrigger&& src) noexcept -> AlternativeTrigger&;

  ~AlternativeTrigger() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkAlternativeTrigger*       { return reinterpret_cast<GtkAlternativeTrigger*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkAlternativeTrigger* { return reinterpret_cast<GtkAlternativeTrigger*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkAlternativeTrigger*;

private:

      protected:
    explicit AlternativeTrigger(const Glib::RefPtr<const ShortcutTrigger>& first, const Glib::RefPtr<const ShortcutTrigger>& second);


public:

  static auto create(const Glib::RefPtr<const ShortcutTrigger>& first, const Glib::RefPtr<const ShortcutTrigger>& second) -> Glib::RefPtr<AlternativeTrigger>;


  /** Gets the first of the two alternative triggers that may
   * trigger @a self.
   *
   * get_second() will return
   * the other one.
   *
   * @return The first alternative trigger.
   */
  auto get_first() const -> Glib::RefPtr<const ShortcutTrigger>;

  /** Gets the second of the two alternative triggers that may
   * trigger @a self.
   *
   * get_first() will return
   * the other one.
   *
   * @return The second alternative trigger.
   */
  auto get_second() const -> Glib::RefPtr<const ShortcutTrigger>;

  /** The first `Gtk::ShortcutTrigger` to check.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_first() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<const ShortcutTrigger> >;


  /** The second `Gtk::ShortcutTrigger` to check.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_second() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<const ShortcutTrigger> >;


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
   * @relates Gtk::ShortcutTrigger
   */
  GTKMM_API
  auto wrap(GtkShortcutTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutTrigger>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::NeverTrigger
   */
  GTKMM_API
  auto wrap(GtkNeverTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NeverTrigger>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::KeyvalTrigger
   */
  GTKMM_API
  auto wrap(GtkKeyvalTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::KeyvalTrigger>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MnemonicTrigger
   */
  GTKMM_API
  auto wrap(GtkMnemonicTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MnemonicTrigger>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::AlternativeTrigger
   */
  GTKMM_API
  auto wrap(GtkAlternativeTrigger* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AlternativeTrigger>;
}


#endif /* _GTKMM_SHORTCUTTRIGGER_H */

