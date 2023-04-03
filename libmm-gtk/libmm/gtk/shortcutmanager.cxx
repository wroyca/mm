// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutmanager.hxx>
#include <libmm/gtk/shortcutmanager_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/shortcutcontroller.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutManager* object, bool take_copy) -> Glib::RefPtr<Gtk::ShortcutManager>
  {
    return Glib::make_refptr_for_instance<Gtk::ShortcutManager> (
        dynamic_cast<Gtk::ShortcutManager*> (
            Glib::wrap_auto_interface<Gtk::ShortcutManager> (
                (GObject*) (object),
                take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutManager_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutManager_Class::iface_init_function;

      gtype_ = gtk_shortcut_manager_get_type ();
    }

    return *this;
  }

  auto
  ShortcutManager_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->add_controller = &add_controller_vfunc_callback;
    klass->remove_controller = &remove_controller_vfunc_callback;
  }

  auto
  ShortcutManager_Class::add_controller_vfunc_callback (
      GtkShortcutManager* self,
      GtkShortcutController* controller) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->add_controller_vfunc (Glib::wrap (controller, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->add_controller)
      (*base->add_controller) (self, controller);
  }

  auto
  ShortcutManager_Class::remove_controller_vfunc_callback (
      GtkShortcutManager* self,
      GtkShortcutController* controller) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->remove_controller_vfunc (Glib::wrap (controller, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->remove_controller)
      (*base->remove_controller) (self, controller);
  }

  auto
  ShortcutManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ShortcutManager ((GtkShortcutManager*) (object));
  }

  ShortcutManager::ShortcutManager ()
    : Glib::Interface (shortcutmanager_class_.init ())
  {
  }

  ShortcutManager::ShortcutManager (GtkShortcutManager* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  ShortcutManager::ShortcutManager (
      const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  ShortcutManager::ShortcutManager (ShortcutManager&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  ShortcutManager::operator= (ShortcutManager&& src) noexcept -> ShortcutManager&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  ShortcutManager::~ShortcutManager () noexcept {}

  auto
  ShortcutManager::add_interface (GType gtype_implementer) -> void
  {
    shortcutmanager_class_.init ().add_interface (gtype_implementer);
  }

  ShortcutManager::CppClassType ShortcutManager::shortcutmanager_class_;

  auto
  ShortcutManager::get_type () -> GType
  {
    return shortcutmanager_class_.init ().get_type ();
  }

  auto
  ShortcutManager::get_base_type () -> GType
  {
    return gtk_shortcut_manager_get_type ();
  }

  auto
  Gtk::ShortcutManager::add_controller_vfunc (
      const Glib::RefPtr<ShortcutController>& controller) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->add_controller)
    {
      (*base->add_controller) (gobj (), Glib::unwrap (controller));
    }
  }

  auto
  Gtk::ShortcutManager::remove_controller_vfunc (
      const Glib::RefPtr<ShortcutController>& controller) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->remove_controller)
    {
      (*base->remove_controller) (gobj (), Glib::unwrap (controller));
    }
  }

} // namespace Gtk
