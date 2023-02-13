
#ifndef _GTKMM_SHORTCUTTRIGGER_P_H
#define _GTKMM_SHORTCUTTRIGGER_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gtk
{

class GTKMM_API ShortcutTrigger_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ShortcutTrigger;
  using BaseObjectType = GtkShortcutTrigger;
  using BaseClassType = GtkShortcutTriggerClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class ShortcutTrigger;
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

class GTKMM_API NeverTrigger_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = NeverTrigger;
  using BaseObjectType = GtkNeverTrigger;
  using BaseClassType = GtkNeverTriggerClass;
  using CppClassParent = ShortcutTrigger_Class;
  using BaseClassParent = GtkShortcutTriggerClass;

  friend class NeverTrigger;
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

class GTKMM_API KeyvalTrigger_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = KeyvalTrigger;
  using BaseObjectType = GtkKeyvalTrigger;
  using BaseClassType = GtkKeyvalTriggerClass;
  using CppClassParent = ShortcutTrigger_Class;
  using BaseClassParent = GtkShortcutTriggerClass;

  friend class KeyvalTrigger;
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

class GTKMM_API MnemonicTrigger_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MnemonicTrigger;
  using BaseObjectType = GtkMnemonicTrigger;
  using BaseClassType = GtkMnemonicTriggerClass;
  using CppClassParent = ShortcutTrigger_Class;
  using BaseClassParent = GtkShortcutTriggerClass;

  friend class MnemonicTrigger;
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

class GTKMM_API AlternativeTrigger_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AlternativeTrigger;
  using BaseObjectType = GtkAlternativeTrigger;
  using BaseClassType = GtkAlternativeTriggerClass;
  using CppClassParent = ShortcutTrigger_Class;
  using BaseClassParent = GtkShortcutTriggerClass;

  friend class AlternativeTrigger;
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


#endif /* _GTKMM_SHORTCUTTRIGGER_P_H */

