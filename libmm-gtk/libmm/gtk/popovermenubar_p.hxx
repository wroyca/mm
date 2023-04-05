// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVERMENUBAR_P_H
#define _GTKMM_POPOVERMENUBAR_P_H

#include <libmm/gtk/widget_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PopoverMenuBar_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PopoverMenuBar;
    using BaseObjectType = GtkPopoverMenuBar;
    using BaseClassType = GtkPopoverMenuBarClass;
    using CppClassParent = gtk::Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class PopoverMenuBar;
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
