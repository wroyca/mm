// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_LAYOUT_P_H
#define _PANGOMM_LAYOUT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Layout_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Layout;
    using BaseObjectType = PangoLayout;
    using BaseClassType = PangoLayoutClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Layout;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace pango

#endif
