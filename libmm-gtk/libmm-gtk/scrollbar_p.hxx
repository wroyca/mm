// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLBAR_P_H
#define _GTKMM_SCROLLBAR_P_H

#include <libmm-gtk/widget_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API Scrollbar_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Scrollbar;
    using BaseObjectType = GtkScrollbar;
    using BaseClassType = GtkScrollbarClass;
    using CppClassParent = Widget_Class;
    using BaseClassParent = GtkWidgetClass;

    friend class Scrollbar;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
