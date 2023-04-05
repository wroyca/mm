// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEIOSTREAM_P_H
#define _GIOMM_SIMPLEIOSTREAM_P_H

#include <libmm/gio/iostream_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SimpleIOStream_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SimpleIOStream;
    using BaseObjectType = GSimpleIOStream;
    using BaseClassType = GSimpleIOStreamClass;
    using CppClassParent = IOStream_Class;
    using BaseClassParent = GIOStreamClass;

    friend class SimpleIOStream;
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
