// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCONTROLMESSAGE_P_H
#define _GIOMM_SOCKETCONTROLMESSAGE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT SocketControlMessage_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SocketControlMessage;
    using BaseObjectType = GSocketControlMessage;
    using BaseClassType = GSocketControlMessageClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SocketControlMessage;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    deserialize_vfunc_callback (int level, int type, gsize size, gpointer data)
        -> GSocketControlMessage*;
    static auto
    get_size_vfunc_callback (GSocketControlMessage* self) -> gsize;
    static auto
    get_level_vfunc_callback (GSocketControlMessage* self) -> int;
    static auto
    get_type_vfunc_callback (GSocketControlMessage* self) -> int;
    static auto
    serialize_vfunc_callback (GSocketControlMessage* self, gpointer data)
        -> void;
  };

} // namespace Gio

#endif
