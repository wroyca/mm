// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTCONTROLLER_P_H
#define _GTKMM_SHORTCUTCONTROLLER_P_H

#include <libmm/gtk/eventcontroller_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutController_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ShortcutController;
    using BaseObjectType = GtkShortcutController;
    using BaseClassType = GtkShortcutControllerClass;
    using CppClassParent = EventController_Class;
    using BaseClassParent = GtkEventControllerClass;

    friend class ShortcutController;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
