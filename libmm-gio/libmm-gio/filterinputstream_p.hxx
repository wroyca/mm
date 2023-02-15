// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILTERINPUTSTREAM_P_H
#define _GIOMM_FILTERINPUTSTREAM_P_H

#include <libmm-gio/inputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT FilterInputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FilterInputStream;
    using BaseObjectType = GFilterInputStream;
    using BaseClassType = GFilterInputStreamClass;
    using CppClassParent = InputStream_Class;
    using BaseClassParent = GInputStreamClass;

    friend class FilterInputStream;
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
