// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_BUFFEREDINPUTSTREAM_P_H
#define _GIOMM_BUFFEREDINPUTSTREAM_P_H

#include <libmm-gio/filterinputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API BufferedInputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BufferedInputStream;
    using BaseObjectType = GBufferedInputStream;
    using BaseClassType = GBufferedInputStreamClass;
    using CppClassParent = FilterInputStream_Class;
    using BaseClassParent = GFilterInputStreamClass;

    friend class BufferedInputStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    fill_vfunc_callback (GBufferedInputStream* self,
                         gssize count,
                         GCancellable* cancellable,
                         GError** error) -> gssize;
  };

} // namespace Gio

#endif
