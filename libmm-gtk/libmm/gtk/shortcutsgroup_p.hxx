// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSGROUP_P_H
#define _GTKMM_SHORTCUTSGROUP_P_H

#include <libmm/gtk/box_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsGroup_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ShortcutsGroup;
    using BaseObjectType = GtkShortcutsGroup;
    using BaseClassType = GtkShortcutsGroupClass;
    using CppClassParent = Box_Class;
    using BaseClassParent = GtkBoxClass;

    friend class ShortcutsGroup;
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
