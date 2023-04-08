// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATION_P_H
#define _LIBADWAITAMM_APPLICATION_P_H

#include <libmm/gtk/application_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT application_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = application;
    using BaseObjectType = AdwApplication;
    using BaseClassType = AdwApplicationClass;
    using CppClassParent = gtk::Application_Class;
    using BaseClassParent = GtkApplicationClass;

    friend class application;
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
