// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATIONWINDOW_P_H
#define _LIBADWAITAMM_APPLICATIONWINDOW_P_H

#include <libmm-gtk/applicationwindow_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class ApplicationWindow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ApplicationWindow;
    using BaseObjectType = AdwApplicationWindow;
    using BaseClassType = AdwApplicationWindowClass;
    using CppClassParent = Gtk::ApplicationWindow_Class;
    using BaseClassParent = GtkApplicationWindowClass;

    friend class ApplicationWindow;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
