// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MEMORYOUTPUTSTREAM_P_H
#define _GIOMM_MEMORYOUTPUTSTREAM_P_H

#include <libmm/gio/outputstream_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MemoryOutputStream_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MemoryOutputStream;
    using BaseObjectType = GMemoryOutputStream;
    using BaseClassType = GMemoryOutputStreamClass;
    using CppClassParent = OutputStream_Class;
    using BaseClassParent = GOutputStreamClass;

    friend class MemoryOutputStream;
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
