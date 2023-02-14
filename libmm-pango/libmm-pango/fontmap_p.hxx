// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTMAP_P_H
#define _PANGOMM_FONTMAP_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Pango
{

  class PANGOMM_API FontMap_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FontMap;
    using BaseObjectType = PangoFontMap;
    using BaseClassType = PangoFontMapClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FontMap;
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
