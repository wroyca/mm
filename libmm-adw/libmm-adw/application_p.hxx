// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATION_P_H
#define _LIBADWAITAMM_APPLICATION_P_H

#include <libmm-gtk/application_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Application_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Application;
    using BaseObjectType = AdwApplication;
    using BaseClassType = AdwApplicationClass;
    using CppClassParent = Gtk::Application_Class;
    using BaseClassParent = GtkApplicationClass;

    friend class Application;
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
