// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_APPLAUNCHCONTEXT_P_H
#define _GDKMM_APPLAUNCHCONTEXT_P_H

#include <libmm/gio/applaunchcontext_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT AppLaunchContext_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AppLaunchContext;
    using BaseObjectType = GdkAppLaunchContext;
    using BaseClassType = GdkAppLaunchContextClass;
    using CppClassParent = Gio::AppLaunchContext_Class;
    using BaseClassParent = GAppLaunchContextClass;

    friend class AppLaunchContext;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
