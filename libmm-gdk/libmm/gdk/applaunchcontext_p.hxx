// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_APPLAUNCHCONTEXT_P_H
#define _GDKMM_APPLAUNCHCONTEXT_P_H

#include <libmm/gio/applaunchcontext_p.hxx>

#include <libmm/glib/class.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT AppLaunchContext_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AppLaunchContext;
    using BaseObjectType = GdkAppLaunchContext;
    using BaseClassType = GdkAppLaunchContextClass;
    using CppClassParent = gio::AppLaunchContext_Class;
    using BaseClassParent = GAppLaunchContextClass;

    friend class AppLaunchContext;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gdk

#endif
