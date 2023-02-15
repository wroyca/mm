// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_MEMORYTEXTURE_P_H
#define _GDKMM_MEMORYTEXTURE_P_H

#include <libmm-gdk/texture_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API MemoryTexture_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MemoryTexture;
    using BaseObjectType = GdkMemoryTexture;
    using BaseClassType = GdkMemoryTextureClass;
    using CppClassParent = Gdk::Texture_Class;
    using BaseClassParent = GdkTextureClass;

    friend class MemoryTexture;
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
