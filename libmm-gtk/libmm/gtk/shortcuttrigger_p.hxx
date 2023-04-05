// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTTRIGGER_P_H
#define _GTKMM_SHORTCUTTRIGGER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutTrigger_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ShortcutTrigger;
    using BaseObjectType = GtkShortcutTrigger;
    using BaseClassType = GtkShortcutTriggerClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class ShortcutTrigger;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT NeverTrigger_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NeverTrigger;
    using BaseObjectType = GtkNeverTrigger;
    using BaseClassType = GtkNeverTriggerClass;
    using CppClassParent = ShortcutTrigger_Class;
    using BaseClassParent = GtkShortcutTriggerClass;

    friend class NeverTrigger;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT KeyvalTrigger_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = KeyvalTrigger;
    using BaseObjectType = GtkKeyvalTrigger;
    using BaseClassType = GtkKeyvalTriggerClass;
    using CppClassParent = ShortcutTrigger_Class;
    using BaseClassParent = GtkShortcutTriggerClass;

    friend class KeyvalTrigger;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MnemonicTrigger_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MnemonicTrigger;
    using BaseObjectType = GtkMnemonicTrigger;
    using BaseClassType = GtkMnemonicTriggerClass;
    using CppClassParent = ShortcutTrigger_Class;
    using BaseClassParent = GtkShortcutTriggerClass;

    friend class MnemonicTrigger;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AlternativeTrigger_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AlternativeTrigger;
    using BaseObjectType = GtkAlternativeTrigger;
    using BaseClassType = GtkAlternativeTriggerClass;
    using CppClassParent = ShortcutTrigger_Class;
    using BaseClassParent = GtkShortcutTriggerClass;

    friend class AlternativeTrigger;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
