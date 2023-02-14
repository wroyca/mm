
#ifndef _GIOMM_BUFFEREDOUTPUTSTREAM_P_H
#define _GIOMM_BUFFEREDOUTPUTSTREAM_P_H

#include <libmm-gio/filteroutputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API BufferedOutputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BufferedOutputStream;
    using BaseObjectType = GBufferedOutputStream;
    using BaseClassType = GBufferedOutputStreamClass;
    using CppClassParent = FilterOutputStream_Class;
    using BaseClassParent = GFilterOutputStreamClass;

    friend class BufferedOutputStream;
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
