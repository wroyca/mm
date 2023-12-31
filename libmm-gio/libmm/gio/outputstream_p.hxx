// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_OUTPUTSTREAM_P_H
#define _GIOMM_OUTPUTSTREAM_P_H

#include <gio/gio.h>
#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT OutputStream_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = OutputStream;
    using BaseObjectType = GOutputStream;
    using BaseClassType = GOutputStreamClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class OutputStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    write_fn_vfunc_callback (GOutputStream* self,
                             const void* buffer,
                             gsize count,
                             GCancellable* cancellable,
                             GError** error) -> gssize;
    static auto
    splice_vfunc_callback (GOutputStream* self,
                           GInputStream* source,
                           GOutputStreamSpliceFlags flags,
                           GCancellable* cancellable,
                           GError** error) -> gssize;
    static auto
    flush_vfunc_callback (GOutputStream* self,
                          GCancellable* cancellable,
                          GError** error) -> gboolean;
    static auto
    close_fn_vfunc_callback (GOutputStream* self,
                             GCancellable* cancellable,
                             GError** error) -> gboolean;
  };

} // namespace gio

#endif
