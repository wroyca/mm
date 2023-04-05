// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEACTION_P_H
#define _GIOMM_SIMPLEACTION_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SimpleAction_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SimpleAction;
    using BaseObjectType = GSimpleAction;
    using BaseClassType = GSimpleActionClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SimpleAction;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gio

#endif
