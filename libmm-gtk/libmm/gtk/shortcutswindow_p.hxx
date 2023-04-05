// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSWINDOW_P_H
#define _GTKMM_SHORTCUTSWINDOW_P_H

#include <libmm/gtk/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsWindow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ShortcutsWindow;
    using BaseObjectType = GtkShortcutsWindow;
    using BaseClassType = GtkShortcutsWindowClass;
    using CppClassParent = Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class ShortcutsWindow;
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
