// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_WINDOW_P_H
#define _LIBADWAITAMM_WINDOW_P_H

#include <libmm/gtk/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Window_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Window;
    using BaseObjectType = AdwWindow;
    using BaseClassType = AdwWindowClass;
    using CppClassParent = gtk::Window_Class;
    using BaseClassParent = GtkWindowClass;

    friend class Window;
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
