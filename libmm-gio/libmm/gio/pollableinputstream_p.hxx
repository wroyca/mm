// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_POLLABLEINPUTSTREAM_P_H
#define _GIOMM_POLLABLEINPUTSTREAM_P_H

#include <gio/gio.h>
#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT PollableInputStream_Class : public glib::Interface_Class
  {
  public:
    using CppObjectType = PollableInputStream;
    using BaseObjectType = GPollableInputStream;
    using BaseClassType = GPollableInputStreamInterface;
    using CppClassParent = Interface_Class;

    friend class PollableInputStream;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    can_poll_vfunc_callback (GPollableInputStream* self) -> gboolean;
    static auto
    is_readable_vfunc_callback (GPollableInputStream* self) -> gboolean;
    static auto
    read_nonblocking_vfunc_callback (GPollableInputStream* self,
                                     void* buffer,
                                     gsize count,
                                     GError** error) -> gssize;
  };

} // namespace gio

#endif
