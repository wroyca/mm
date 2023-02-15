// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVERMENU_P_H
#define _GTKMM_POPOVERMENU_P_H

#include <libmm-gtk/popover_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API PopoverMenu_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PopoverMenu;
    using BaseObjectType = GtkPopoverMenu;
    using BaseClassType = GtkPopoverMenuClass;
    using CppClassParent = Gtk::Popover_Class;
    using BaseClassParent = GtkPopoverClass;

    friend class PopoverMenu;
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
