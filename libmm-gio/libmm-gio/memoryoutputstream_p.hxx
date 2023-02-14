
#ifndef _GIOMM_MEMORYOUTPUTSTREAM_P_H
#define _GIOMM_MEMORYOUTPUTSTREAM_P_H

#include <libmm-gio/outputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API MemoryOutputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MemoryOutputStream;
    using BaseObjectType = GMemoryOutputStream;
    using BaseClassType = GMemoryOutputStreamClass;
    using CppClassParent = OutputStream_Class;
    using BaseClassParent = GOutputStreamClass;

    friend class MemoryOutputStream;
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
