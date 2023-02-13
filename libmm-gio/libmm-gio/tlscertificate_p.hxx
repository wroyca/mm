
#ifndef _GIOMM_TLSCERTIFICATE_P_H
#define _GIOMM_TLSCERTIFICATE_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

class GIOMM_API TlsCertificate_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TlsCertificate;
  using BaseObjectType = GTlsCertificate;
  using BaseClassType = GTlsCertificateClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TlsCertificate;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static auto verify_vfunc_callback (
    GTlsCertificate *self, GSocketConnectable *identity,
    GTlsCertificate *trusted_ca) -> GTlsCertificateFlags;
};


} // namespace Gio


#endif /* _GIOMM_TLSCERTIFICATE_P_H */

