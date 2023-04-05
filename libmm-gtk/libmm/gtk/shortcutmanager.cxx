// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutmanager.hxx>
#include <libmm/gtk/shortcutmanager_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/shortcutcontroller.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcutManager* object, bool take_copy) -> glib::RefPtr<gtk::ShortcutManager>
  {
    return glib::make_refptr_for_instance<gtk::ShortcutManager> (
        dynamic_cast<gtk::ShortcutManager*> (
            glib::wrap_auto_interface<gtk::ShortcutManager> (
                (GObject*) (object),
                take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutManager_Class::init () -> const glib::Interface_Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->add_controller_vfunc (glib::wrap (controller, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->remove_controller_vfunc (glib::wrap (controller, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
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
  ShortcutManager_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ShortcutManager ((GtkShortcutManager*) (object));
  }

  ShortcutManager::ShortcutManager ()
    : glib::Interface (shortcutmanager_class_.init ())
  {
  }

  ShortcutManager::ShortcutManager (GtkShortcutManager* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  ShortcutManager::ShortcutManager (
      const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  ShortcutManager::ShortcutManager (ShortcutManager&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  ShortcutManager::operator= (ShortcutManager&& src) noexcept -> ShortcutManager&
  {
    glib::Interface::operator= (std::move (src));
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
  gtk::ShortcutManager::add_controller_vfunc (
      const glib::RefPtr<ShortcutController>& controller) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->add_controller)
    {
      (*base->add_controller) (gobj (), glib::unwrap (controller));
    }
  }

  auto
  gtk::ShortcutManager::remove_controller_vfunc (
      const glib::RefPtr<ShortcutController>& controller) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->remove_controller)
    {
      (*base->remove_controller) (gobj (), glib::unwrap (controller));
    }
  }

} // namespace gtk
