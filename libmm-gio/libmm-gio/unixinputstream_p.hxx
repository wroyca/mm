// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXINPUTSTREAM_P_H
#define _GIOMM_UNIXINPUTSTREAM_P_H

#include <libmm-gio/inputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API UnixInputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = UnixInputStream;
    using BaseObjectType = GUnixInputStream;
    using BaseClassType = GUnixInputStreamClass;
    using CppClassParent = InputStream_Class;
    using BaseClassParent = GInputStreamClass;

    friend class UnixInputStream;
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
