// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CAIROCONTEXT_P_H
#define _GDKMM_CAIROCONTEXT_P_H

#include <libmm/gdk/drawcontext_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT CairoContext_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CairoContext;
    using BaseObjectType = GdkCairoContext;
    using BaseClassType = GdkCairoContextClass;
    using CppClassParent = Gdk::DrawContext_Class;
    using BaseClassParent = GdkDrawContextClass;

    friend class CairoContext;
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
