// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PADCONTROLLER_P_H
#define _GTKMM_PADCONTROLLER_P_H

#include <libmm/gtk/eventcontroller_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PadController_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PadController;
    using BaseObjectType = GtkPadController;
    using BaseClassType = GtkPadControllerClass;
    using CppClassParent = EventController_Class;
    using BaseClassParent = GtkEventControllerClass;

    friend class PadController;
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
