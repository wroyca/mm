// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXCREDENTIALSMESSAGE_P_H
#define _GIOMM_UNIXCREDENTIALSMESSAGE_P_H

#include <libmm/gio/socketcontrolmessage_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT UnixCredentialsMessage_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = UnixCredentialsMessage;
    using BaseObjectType = GUnixCredentialsMessage;
    using BaseClassType = GUnixCredentialsMessageClass;
    using CppClassParent = SocketControlMessage_Class;
    using BaseClassParent = GSocketControlMessageClass;

    friend class UnixCredentialsMessage;
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
