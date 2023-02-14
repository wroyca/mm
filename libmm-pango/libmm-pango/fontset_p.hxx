// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTSET_P_H
#define _PANGOMM_FONTSET_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Pango
{

  class PANGOMM_API Fontset_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Fontset;
    using BaseObjectType = PangoFontset;
    using BaseClassType = PangoFontsetClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Fontset;
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
