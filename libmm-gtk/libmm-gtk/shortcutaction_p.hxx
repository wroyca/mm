// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTACTION_P_H
#define _GTKMM_SHORTCUTACTION_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

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
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
