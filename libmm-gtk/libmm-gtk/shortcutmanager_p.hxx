
#ifndef _GTKMM_SHORTCUTMANAGER_P_H
#define _GTKMM_SHORTCUTMANAGER_P_H

#include <gtk/gtk.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API ShortcutManager_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = ShortcutManager;
    using BaseObjectType = GtkShortcutManager;
    using BaseClassType = GtkShortcutManagerInterface;
    using CppClassParent = Interface_Class;

    friend class ShortcutManager;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    add_controller_vfunc_callback (GtkShortcutManager* self,
                                   GtkShortcutController* controller) -> void;
    static auto
    remove_controller_vfunc_callback (GtkShortcutManager* self,
                                      GtkShortcutController* controller)
        -> void;
  };

} // namespace Gtk

#endif
