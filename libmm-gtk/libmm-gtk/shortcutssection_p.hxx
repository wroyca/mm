// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSSECTION_P_H
#define _GTKMM_SHORTCUTSSECTION_P_H

#include <libmm-gtk/box_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsSection_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ShortcutsSection;
    using BaseObjectType = GtkShortcutsSection;
    using BaseClassType = GtkShortcutsSectionClass;
    using CppClassParent = Box_Class;
    using BaseClassParent = GtkBoxClass;

    friend class ShortcutsSection;
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
