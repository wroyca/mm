// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVER_P_H
#define _GTKMM_POPOVER_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Popover_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Popover;
    using BaseObjectType = GtkPopover;
    using BaseClassType = GtkPopoverClass;
    using CppClassParent = Gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Popover;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    closed_callback (GtkPopover* self) -> void;
  };

} // namespace Gtk

#endif
