// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GTKMM_SHORTCUTACTION_H
#define _GTKMM_SHORTCUTACTION_H

#include <mm/gtk/mm-gtkconfig.h>


#include <mm/glib/ustring.h>
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


#include <mm/glib/object.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutAction = struct _GtkShortcutAction;
using GtkShortcutActionClass = struct _GtkShortcutActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ShortcutAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNothingAction = struct _GtkNothingAction;
using GtkNothingActionClass = struct _GtkNothingActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NothingAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCallbackAction = struct _GtkCallbackAction;
using GtkCallbackActionClass = struct _GtkCallbackActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CallbackAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMnemonicAction = struct _GtkMnemonicAction;
using GtkMnemonicActionClass = struct _GtkMnemonicActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MnemonicAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActivateAction = struct _GtkActivateAction;
using GtkActivateActionClass = struct _GtkActivateActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API ActivateAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSignalAction = struct _GtkSignalAction;
using GtkSignalActionClass = struct _GtkSignalActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API SignalAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNamedAction = struct _GtkNamedAction;
using GtkNamedActionClass = struct _GtkNamedActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API NamedAction_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Widget;

/** Tracking if shortcuts should be activated.
 *
 * %Gtk::ShortcutAction is the object used to describe what a Gtk::Shortcut should
 * do when triggered. To activate a %ShortcutAction manually, activate() can be called.
 *
 * ShortcutActions contain methods that allow easy presentation to end
 * users as well as being printed for debugging.
 *
 * All ShortcutActions are immutable, you can only specify their properties
 * during construction. If you want to change an action, you have to replace it
 * with a new one. If you need to pass arguments to an action, these are specified
 * by the higher-level Gtk::Shortcut object.
 *
 * GTK provides various actions:
 *
 *  - Gtk::MnemonicAction: a shortcut action that calls Gtk::Widget::mnemonic_activate()
 *  - Gtk::CallbackAction: a shortcut action that invokes a given callback
 *  - Gtk::SignalAction: a shortcut action that emits a given signal
 *  - Gtk::ActivateAction: a shortcut action that calls Gtk::Widget::activate()
 *  - Gtk::NamedAction: a shortcut action that calls Gtk::Widget::activate_action()
 *  - Gtk::NothingAction: a shortcut action that does nothing
 *
 * @see Gtk::Shortcut
 * @ingroup Gestures
 * @newin{3,98}
 */

class GTKMM_API ShortcutAction : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ShortcutAction;
  using CppClassType = ShortcutAction_Class;
  using BaseObjectType = GtkShortcutAction;
  using BaseClassType = GtkShortcutActionClass;

  // noncopyable
  ShortcutAction(const ShortcutAction&) = delete;
  auto operator=(const ShortcutAction&) -> ShortcutAction& = delete;

private:  friend class ShortcutAction_Class;
  static CppClassType shortcutaction_class_;

protected:
  explicit ShortcutAction(const Glib::ConstructParams& construct_params);
  explicit ShortcutAction(GtkShortcutAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ShortcutAction(ShortcutAction&& src) noexcept;
  auto operator=(ShortcutAction&& src) noexcept -> ShortcutAction&;

  ~ShortcutAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkShortcutAction*       { return reinterpret_cast<GtkShortcutAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkShortcutAction* { return reinterpret_cast<GtkShortcutAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkShortcutAction*;

private:

      protected:
  ShortcutAction();

public:
  /** @addtogroup gtkmmEnums gtkmm Enums and Flags */

  /**
   *  @var Flags EXCLUSIVE
   * The action is the only
   * action that can be activated. If this flag is not set,
   * a future activation may select a different action.
   *
   *  @enum Flags
   *
   * List of flags that can be passed to action activation.
   *
   * More flags may be added in the future.
   *
   * @ingroup gtkmmEnums
   * @par Bitwise operators:
   * <tt>ShortcutAction::Flags operator|(ShortcutAction::Flags, ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags operator&(ShortcutAction::Flags, ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags operator^(ShortcutAction::Flags, ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags operator~(ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags& operator|=(ShortcutAction::Flags&, ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags& operator&=(ShortcutAction::Flags&, ShortcutAction::Flags)</tt><br>
   * <tt>ShortcutAction::Flags& operator^=(ShortcutAction::Flags&, ShortcutAction::Flags)</tt><br>
   */
  enum class Flags
  {
    EXCLUSIVE = 1 << 0
  };


  /** Tries to parse the given string into an action.
   *
   * On success, the parsed action is returned. When parsing
   * failed, <tt>nullptr</tt> is returned.
   *
   * The accepted strings are:
   *
   * - `nothing`, for `Gtk::NothingAction`
   * - `activate`, for `Gtk::ActivateAction`
   * - `mnemonic-activate`, for `Gtk::MnemonicAction`
   * - `action(NAME)`, for a `Gtk::NamedAction` for the action named `NAME`
   * - `signal(NAME)`, for a `Gtk::SignalAction` for the signal `NAME`
   *
   * @param string The string to parse.
   * @return A new `Gtk::ShortcutAction`.
   */
  static auto parse_string(const Glib::ustring& string) -> Glib::RefPtr<ShortcutAction>;


  /** Prints the given action into a human-readable string.
   *
   * This is meant for debugging and logging.
   * The form of the representation may change at any time and is
   * not guaranteed to stay identical.
   *
   * @return A new string.
   */
  auto to_string() const -> Glib::ustring;


  /** Activates the action on the @a widget with the given @a args.
   *
   * Note that some actions ignore the passed in @a flags, @a widget or @a args.
   *
   * Activation of an action can fail for various reasons. If the action
   * is not supported by the @a widget, if the @a args don't match the action
   * or if the activation otherwise had no effect, <tt>false</tt> will be returned.
   *
   * @param flags Flags to activate with.
   * @param widget Target of the activation.
   * @param args Arguments to pass.
   * @return <tt>true</tt> if this action was activated successfully.
   */
  auto activate(Widget& widget, Flags flags =  static_cast<Flags>(0), const Glib::VariantBase& args =  {}) -> bool;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};


/** A Gtk::ShortcutAction that does nothing.
 */

class GTKMM_API NothingAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NothingAction;
  using CppClassType = NothingAction_Class;
  using BaseObjectType = GtkNothingAction;
  using BaseClassType = GtkNothingActionClass;

  // noncopyable
  NothingAction(const NothingAction&) = delete;
  auto operator=(const NothingAction&) -> NothingAction& = delete;

private:  friend class NothingAction_Class;
  static CppClassType nothingaction_class_;

protected:
  explicit NothingAction(const Glib::ConstructParams& construct_params);
  explicit NothingAction(GtkNothingAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NothingAction(NothingAction&& src) noexcept;
  auto operator=(NothingAction&& src) noexcept -> NothingAction&;

  ~NothingAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNothingAction*       { return reinterpret_cast<GtkNothingAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNothingAction* { return reinterpret_cast<GtkNothingAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkNothingAction*;

private:

      protected:
  NothingAction();

public:

  /** Gets the nothing action.
   *
   * This is an action that does nothing and where
   * activating it always fails.
   *
   * @return The nothing action.
   */
  static auto get() -> Glib::RefPtr<NothingAction>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutAction that invokes a callback.
 */

class GTKMM_API CallbackAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CallbackAction;
  using CppClassType = CallbackAction_Class;
  using BaseObjectType = GtkCallbackAction;
  using BaseClassType = GtkCallbackActionClass;

  // noncopyable
  CallbackAction(const CallbackAction&) = delete;
  auto operator=(const CallbackAction&) -> CallbackAction& = delete;

private:  friend class CallbackAction_Class;
  static CppClassType callbackaction_class_;

protected:
  explicit CallbackAction(const Glib::ConstructParams& construct_params);
  explicit CallbackAction(GtkCallbackAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CallbackAction(CallbackAction&& src) noexcept;
  auto operator=(CallbackAction&& src) noexcept -> CallbackAction&;

  ~CallbackAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkCallbackAction*       { return reinterpret_cast<GtkCallbackAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkCallbackAction* { return reinterpret_cast<GtkCallbackAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkCallbackAction*;

private:

      public:
  /** Slot for shortcuts based on user callbacks.
   *
   * For instance:
   * @code
   * void on_shortcut(Widget& widget, const Glib::VariantBase& args);
   * @endcode
   *
   * @param widget The widget passed to the activation.
   * @param args The arguments passed to the activation. Can be empty,
   *             if there are no arguments.
   */
  using SlotShortcut = sigc::slot<bool(Widget&, const Glib::VariantBase&)>;


  static auto create(const SlotShortcut& slot) -> Glib::RefPtr<CallbackAction>;


protected:
  explicit CallbackAction(const SlotShortcut& slot);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutAction that calls Gtk::Widget::mnemonic_activate().
 */

class GTKMM_API MnemonicAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = MnemonicAction;
  using CppClassType = MnemonicAction_Class;
  using BaseObjectType = GtkMnemonicAction;
  using BaseClassType = GtkMnemonicActionClass;

  // noncopyable
  MnemonicAction(const MnemonicAction&) = delete;
  auto operator=(const MnemonicAction&) -> MnemonicAction& = delete;

private:  friend class MnemonicAction_Class;
  static CppClassType mnemonicaction_class_;

protected:
  explicit MnemonicAction(const Glib::ConstructParams& construct_params);
  explicit MnemonicAction(GtkMnemonicAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  MnemonicAction(MnemonicAction&& src) noexcept;
  auto operator=(MnemonicAction&& src) noexcept -> MnemonicAction&;

  ~MnemonicAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkMnemonicAction*       { return reinterpret_cast<GtkMnemonicAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkMnemonicAction* { return reinterpret_cast<GtkMnemonicAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkMnemonicAction*;

private:

      protected:
  MnemonicAction();

public:

  /** Gets the mnemonic action.
   *
   * This is an action that calls Gtk::Widget::mnemonic_activate()
   * on the given widget upon activation.
   *
   * @return The mnemonic action.
   */
  static auto get() -> Glib::RefPtr<MnemonicAction>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutAction that calls Gtk::Widget::activate().
 */

class GTKMM_API ActivateAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ActivateAction;
  using CppClassType = ActivateAction_Class;
  using BaseObjectType = GtkActivateAction;
  using BaseClassType = GtkActivateActionClass;

  // noncopyable
  ActivateAction(const ActivateAction&) = delete;
  auto operator=(const ActivateAction&) -> ActivateAction& = delete;

private:  friend class ActivateAction_Class;
  static CppClassType activateaction_class_;

protected:
  explicit ActivateAction(const Glib::ConstructParams& construct_params);
  explicit ActivateAction(GtkActivateAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ActivateAction(ActivateAction&& src) noexcept;
  auto operator=(ActivateAction&& src) noexcept -> ActivateAction&;

  ~ActivateAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkActivateAction*       { return reinterpret_cast<GtkActivateAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkActivateAction* { return reinterpret_cast<GtkActivateAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkActivateAction*;

private:

      protected:
  ActivateAction();

public:

  /** Gets the activate action.
   *
   * This is an action that calls Gtk::Widget::activate()
   * on the given widget upon activation.
   *
   * @return The activate action.
   */
  static auto get() -> Glib::RefPtr<ActivateAction>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutAction that emits a signal.
 */

class GTKMM_API SignalAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = SignalAction;
  using CppClassType = SignalAction_Class;
  using BaseObjectType = GtkSignalAction;
  using BaseClassType = GtkSignalActionClass;

  // noncopyable
  SignalAction(const SignalAction&) = delete;
  auto operator=(const SignalAction&) -> SignalAction& = delete;

private:  friend class SignalAction_Class;
  static CppClassType signalaction_class_;

protected:
  explicit SignalAction(const Glib::ConstructParams& construct_params);
  explicit SignalAction(GtkSignalAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  SignalAction(SignalAction&& src) noexcept;
  auto operator=(SignalAction&& src) noexcept -> SignalAction&;

  ~SignalAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkSignalAction*       { return reinterpret_cast<GtkSignalAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkSignalAction* { return reinterpret_cast<GtkSignalAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkSignalAction*;

private:

      protected:
    explicit SignalAction(const Glib::ustring& signal_name);


public:

  static auto create(const Glib::ustring& signal_name) -> Glib::RefPtr<SignalAction>;


  /** Returns the name of the signal that will be emitted.
   *
   * @return The name of the signal to emit.
   */
  auto get_signal_name() const -> Glib::ustring;

  /** The name of the signal to emit.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_signal_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

/** A Gtk::ShortcutAction that activates an action by name.
 */

class GTKMM_API NamedAction : public ShortcutAction
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NamedAction;
  using CppClassType = NamedAction_Class;
  using BaseObjectType = GtkNamedAction;
  using BaseClassType = GtkNamedActionClass;

  // noncopyable
  NamedAction(const NamedAction&) = delete;
  auto operator=(const NamedAction&) -> NamedAction& = delete;

private:  friend class NamedAction_Class;
  static CppClassType namedaction_class_;

protected:
  explicit NamedAction(const Glib::ConstructParams& construct_params);
  explicit NamedAction(GtkNamedAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NamedAction(NamedAction&& src) noexcept;
  auto operator=(NamedAction&& src) noexcept -> NamedAction&;

  ~NamedAction() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkNamedAction*       { return reinterpret_cast<GtkNamedAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkNamedAction* { return reinterpret_cast<GtkNamedAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkNamedAction*;

private:

      protected:
    explicit NamedAction(const Glib::ustring& action_name);


public:

  static auto create(const Glib::ustring& action_name) -> Glib::RefPtr<NamedAction>;


  /** Returns the name of the action that will be activated.
   *
   * @return The name of the action to activate.
   */
  auto get_action_name() const -> Glib::ustring;

  /** The name of the action to activate.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_action_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk

namespace Gtk
{

/** @ingroup gtkmmEnums */
inline auto operator|(ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  { return static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator&(ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  { return static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator^(ShortcutAction::Flags lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags
  { return static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline auto operator~(ShortcutAction::Flags flags) -> ShortcutAction::Flags
  { return static_cast<ShortcutAction::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline auto operator|=(ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  { return (lhs = static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator&=(ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  { return (lhs = static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline auto operator^=(ShortcutAction::Flags& lhs, ShortcutAction::Flags rhs) -> ShortcutAction::Flags&
  { return (lhs = static_cast<ShortcutAction::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::ShortcutAction::Flags> : public Glib::Value_Flags<Gtk::ShortcutAction::Flags>
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
   * @relates Gtk::ShortcutAction
   */
  GTKMM_API
  auto wrap(GtkShortcutAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::NothingAction
   */
  GTKMM_API
  auto wrap(GtkNothingAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NothingAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::CallbackAction
   */
  GTKMM_API
  auto wrap(GtkCallbackAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CallbackAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MnemonicAction
   */
  GTKMM_API
  auto wrap(GtkMnemonicAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MnemonicAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::ActivateAction
   */
  GTKMM_API
  auto wrap(GtkActivateAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ActivateAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::SignalAction
   */
  GTKMM_API
  auto wrap(GtkSignalAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SignalAction>;
}


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::NamedAction
   */
  GTKMM_API
  auto wrap(GtkNamedAction* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NamedAction>;
}


#endif /* _GTKMM_SHORTCUTACTION_H */

