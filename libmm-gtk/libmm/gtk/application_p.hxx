// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPLICATION_P_H
#define _GTKMM_APPLICATION_P_H

#include <libmm/gio/application_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Application_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Application;
    using BaseObjectType = GtkApplication;
    using BaseClassType = GtkApplicationClass;
    using CppClassParent = gio::Application_Class;
    using BaseClassParent = GApplicationClass;

    friend class Application;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    window_added_callback (GtkApplication* self, GtkWindow* p0) -> void;
    static auto
    window_removed_callback (GtkApplication* self, GtkWindow* p0) -> void;
  };

} // namespace gtk

#endif
