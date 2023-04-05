// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSMESSAGE_P_H
#define _GIOMM_DBUSMESSAGE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT Message_Class : public glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = Message;
      using BaseObjectType = GDBusMessage;
      using BaseClassType = GDBusMessageClass;
      using CppClassParent = glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class Message;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;

    protected:
    };

  } // namespace DBus

} // namespace gio

#endif
