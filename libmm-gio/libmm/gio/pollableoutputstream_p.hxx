// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_POLLABLEOUTPUTSTREAM_P_H
#define _GIOMM_POLLABLEOUTPUTSTREAM_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT PollableOutputStream_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = PollableOutputStream;
    using BaseObjectType = GPollableOutputStream;
    using BaseClassType = GPollableOutputStreamInterface;
    using CppClassParent = Interface_Class;

    friend class PollableOutputStream;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    can_poll_vfunc_callback (GPollableOutputStream* self) -> gboolean;
    static auto
    is_writable_vfunc_callback (GPollableOutputStream* self) -> gboolean;
    static auto
    write_nonblocking_vfunc_callback (GPollableOutputStream* self,
                                      const void* buffer,
                                      gsize count,
                                      GError** error) -> gssize;
  };

} // namespace gio

#endif
