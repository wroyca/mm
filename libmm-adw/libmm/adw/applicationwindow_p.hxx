// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATIONWINDOW_P_H
#define _LIBADWAITAMM_APPLICATIONWINDOW_P_H

#include <libmm/gtk/applicationwindow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT application_window_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = application_window;
    using BaseObjectType = AdwApplicationWindow;
    using BaseClassType = AdwApplicationWindowClass;
    using CppClassParent = gtk::ApplicationWindow_Class;
    using BaseClassParent = GtkApplicationWindowClass;

    friend class application_window;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
