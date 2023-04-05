#ifndef _GIOMM_BYTESICON_P_H
#define _GIOMM_BYTESICON_P_H


#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT BytesIcon_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BytesIcon;
    using BaseObjectType = GBytesIcon;
    using BaseClassType = GBytesIconClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class BytesIcon;
  #endif

    const glib::Class&
    init ();

    static void
    class_init_function (void* g_class, void* class_data);

    static glib::ObjectBase*
    wrap_new (GObject*);

  protected:
  };

} // namespace gio


#endif

