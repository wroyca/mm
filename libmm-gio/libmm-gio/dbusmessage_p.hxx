
#ifndef _GIOMM_DBUSMESSAGE_P_H
#define _GIOMM_DBUSMESSAGE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  namespace DBus
  {

    class GIOMM_API Message_Class : public Glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = Message;
      using BaseObjectType = GDBusMessage;
      using BaseClassType = GDBusMessageClass;
      using CppClassParent = Glib::Object_Class;
      using BaseClassParent = GObjectClass;

      friend class Message;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
    };

  } // namespace DBus

} // namespace Gio

#endif
