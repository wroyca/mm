
#ifndef _GIOMM_SOCKETCONTROLMESSAGE_P_H
#define _GIOMM_SOCKETCONTROLMESSAGE_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API SocketControlMessage_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SocketControlMessage;
  using BaseObjectType = GSocketControlMessage;
  using BaseClassType = GSocketControlMessageClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class SocketControlMessage;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto deserialize_vfunc_callback (
    int level, int type, gsize size, gpointer data) -> GSocketControlMessage*;
    static auto get_size_vfunc_callback (GSocketControlMessage *self) -> gsize;
  static auto get_level_vfunc_callback (GSocketControlMessage *self) -> int;
  static auto get_type_vfunc_callback (GSocketControlMessage *self) -> int;
  static auto serialize_vfunc_callback (GSocketControlMessage *self, gpointer data) -> void;
};


} // namespace Gio


#endif /* _GIOMM_SOCKETCONTROLMESSAGE_P_H */

