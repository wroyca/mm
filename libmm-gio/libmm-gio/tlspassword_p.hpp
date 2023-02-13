
#ifndef _GIOMM_TLSPASSWORD_P_H
#define _GIOMM_TLSPASSWORD_P_H


#include <mm/glib/private/object_p.hpp>

#include <mm/glib/class.hpp>

namespace Gio
{

class GIOMM_API TlsPassword_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TlsPassword;
  using BaseObjectType = GTlsPassword;
  using BaseClassType = GTlsPasswordClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TlsPassword;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto get_value_vfunc_callback (GTlsPassword *self, gsize *length) -> const guchar*;
  static auto get_default_warning_vfunc_callback (GTlsPassword *self) -> const gchar*;
};


} // namespace Gio


#endif /* _GIOMM_TLSPASSWORD_P_H */

