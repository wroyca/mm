// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEOUTPUTSTREAM_P_H
#define _GIOMM_FILEOUTPUTSTREAM_P_H

#include <libmm/gio/outputstream_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT FileOutputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileOutputStream;
    using BaseObjectType = GFileOutputStream;
    using BaseClassType = GFileOutputStreamClass;
    using CppClassParent = OutputStream_Class;
    using BaseClassParent = GOutputStreamClass;

    friend class FileOutputStream;
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
