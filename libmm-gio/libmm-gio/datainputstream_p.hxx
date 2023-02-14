
#ifndef _GIOMM_DATAINPUTSTREAM_P_H
#define _GIOMM_DATAINPUTSTREAM_P_H

#include <libmm-gio/bufferedinputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API DataInputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = DataInputStream;
    using BaseObjectType = GDataInputStream;
    using BaseClassType = GDataInputStreamClass;
    using CppClassParent = BufferedInputStream_Class;
    using BaseClassParent = GBufferedInputStreamClass;

    friend class DataInputStream;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
