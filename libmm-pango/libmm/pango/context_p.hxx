// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_CONTEXT_P_H
#define _PANGOMM_CONTEXT_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Context_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Context;
    using BaseObjectType = PangoContext;
    using BaseClassType = PangoContextClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Context;
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
