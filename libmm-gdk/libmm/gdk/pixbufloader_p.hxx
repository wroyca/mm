// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFLOADER_P_H
#define _GDKMM_PIXBUFLOADER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufLoader_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PixbufLoader;
    using BaseObjectType = GdkPixbufLoader;
    using BaseClassType = GdkPixbufLoaderClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class PixbufLoader;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    area_prepared_callback (GdkPixbufLoader* self) -> void;
    static auto
    area_updated_callback (GdkPixbufLoader* self,
                           gint p0,
                           gint p1,
                           gint p2,
                           gint p3) -> void;
    static auto
    closed_callback (GdkPixbufLoader* self) -> void;
    static auto
    size_prepared_callback (GdkPixbufLoader* self, gint p0, gint p1) -> void;
  };

} // namespace Gdk

#endif
