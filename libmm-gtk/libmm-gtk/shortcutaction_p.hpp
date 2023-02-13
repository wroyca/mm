
#ifndef _GTKMM_SHORTCUTACTION_P_H
#define _GTKMM_SHORTCUTACTION_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API ShortcutAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ShortcutAction;
  using BaseObjectType = GtkShortcutAction;
  using BaseClassType = GtkShortcutActionClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class ShortcutAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API NothingAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = NothingAction;
  using BaseObjectType = GtkNothingAction;
  using BaseClassType = GtkNothingActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class NothingAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API CallbackAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = CallbackAction;
  using BaseObjectType = GtkCallbackAction;
  using BaseClassType = GtkCallbackActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class CallbackAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API MnemonicAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MnemonicAction;
  using BaseObjectType = GtkMnemonicAction;
  using BaseClassType = GtkMnemonicActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class MnemonicAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API ActivateAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ActivateAction;
  using BaseObjectType = GtkActivateAction;
  using BaseClassType = GtkActivateActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class ActivateAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API SignalAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SignalAction;
  using BaseObjectType = GtkSignalAction;
  using BaseClassType = GtkSignalActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class SignalAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API NamedAction_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = NamedAction;
  using BaseObjectType = GtkNamedAction;
  using BaseClassType = GtkNamedActionClass;
  using CppClassParent = ShortcutAction_Class;
  using BaseClassParent = GtkShortcutActionClass;

  friend class NamedAction;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_SHORTCUTACTION_P_H */

