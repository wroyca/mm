// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEINPUTSTREAM_P_H
#define _GIOMM_FILEINPUTSTREAM_P_H

#include <libmm/gio/inputstream_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileInputStream_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileInputStream;
    using BaseObjectType = GFileInputStream;
    using BaseClassType = GFileInputStreamClass;
    using CppClassParent = InputStream_Class;
    using BaseClassParent = GInputStreamClass;

    friend class FileInputStream;
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
