// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTFACE_P_H
#define _PANGOMM_FONTFACE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT FontFace_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontFace;
    using BaseObjectType = PangoFontFace;
    using BaseClassType = PangoFontFaceClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FontFace;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Pango

#endif
