// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEENUMERATOR_P_H
#define _GIOMM_FILEENUMERATOR_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FileEnumerator_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileEnumerator;
    using BaseObjectType = GFileEnumerator;
    using BaseClassType = GFileEnumeratorClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class FileEnumerator;
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
