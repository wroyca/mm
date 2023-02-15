#ifndef _GIOMM_BYTESICON_P_H
#define _GIOMM_BYTESICON_P_H


#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT BytesIcon_Class : public Glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BytesIcon;
    using BaseObjectType = GBytesIcon;
    using BaseClassType = GBytesIconClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class BytesIcon;
  #endif

    const Glib::Class&
    init ();

    static void
    class_init_function (void* g_class, void* class_data);

    static Glib::ObjectBase*
    wrap_new (GObject*);

  protected:
  };

} // namespace Gio


#endif

