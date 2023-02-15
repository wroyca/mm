// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_IOSTREAM_P_H
#define _GIOMM_IOSTREAM_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT IOStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = IOStream;
    using BaseObjectType = GIOStream;
    using BaseClassType = GIOStreamClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class IOStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
