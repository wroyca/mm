// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DRAWCONTEXT_P_H
#define _GDKMM_DRAWCONTEXT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DrawContext_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DrawContext;
    using BaseObjectType = GdkDrawContext;
    using BaseClassType = GdkDrawContextClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class DrawContext;
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
