
#ifndef _GIOMM_POLLABLEINPUTSTREAM_P_H
#define _GIOMM_POLLABLEINPUTSTREAM_P_H


#include <libmm-glib/interface_p.hxx>
#include <gio/gio.h>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

class GIOMM_API PollableInputStream_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = PollableInputStream;
  using BaseObjectType = GPollableInputStream;
  using BaseClassType = GPollableInputStreamInterface;
  using CppClassParent = Interface_Class;

  friend class PollableInputStream;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto can_poll_vfunc_callback (GPollableInputStream *self) -> gboolean;
  static auto is_readable_vfunc_callback (GPollableInputStream *self) -> gboolean;
  static auto read_nonblocking_vfunc_callback (
    GPollableInputStream *self, void *buffer, gsize count, GError **error) -> gssize;
};


} // namespace Gio


#endif /* _GIOMM_POLLABLEINPUTSTREAM_P_H */

