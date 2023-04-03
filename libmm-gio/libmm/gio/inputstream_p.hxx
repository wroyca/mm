// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INPUTSTREAM_P_H
#define _GIOMM_INPUTSTREAM_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT InputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = InputStream;
    using BaseObjectType = GInputStream;
    using BaseClassType = GInputStreamClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class InputStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    read_fn_vfunc_callback (GInputStream* self,
                            void* buffer,
                            gsize count,
                            GCancellable* cancellable,
                            GError** error) -> gssize;
    static auto
    skip_vfunc_callback (GInputStream* self,
                         gsize count,
                         GCancellable* cancellable,
                         GError** error) -> gssize;
    static auto
    close_fn_vfunc_callback (GInputStream* self,
                             GCancellable* cancellable,
                             GError** error) -> gboolean;
  };

} // namespace Gio

#endif
