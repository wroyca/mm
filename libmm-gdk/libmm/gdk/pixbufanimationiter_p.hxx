// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFANIMATIONITER_P_H
#define _GDKMM_PIXBUFANIMATIONITER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufAnimationIter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PixbufAnimationIter;
    using BaseObjectType = GdkPixbufAnimationIter;
    using BaseClassType = GdkPixbufAnimationIterClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class PixbufAnimationIter;
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