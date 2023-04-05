// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CAIROCONTEXT_P_H
#define _GDKMM_CAIROCONTEXT_P_H

#include <libmm/gdk/drawcontext_p.hxx>

#include <libmm/glib/class.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT CairoContext_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CairoContext;
    using BaseObjectType = GdkCairoContext;
    using BaseClassType = GdkCairoContextClass;
    using CppClassParent = gdk::DrawContext_Class;
    using BaseClassParent = GdkDrawContextClass;

    friend class CairoContext;
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
