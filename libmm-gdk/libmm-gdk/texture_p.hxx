// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TEXTURE_P_H
#define _GDKMM_TEXTURE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gdk
{

  class GDKMM_API Texture_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Texture;
    using BaseObjectType = GdkTexture;
    using BaseClassType = GdkTextureClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Texture;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
