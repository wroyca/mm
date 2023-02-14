
#ifndef _GIOMM_CONVERTEROUTPUTSTREAM_P_H
#define _GIOMM_CONVERTEROUTPUTSTREAM_P_H

#include <libmm-gio/filteroutputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API ConverterOutputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ConverterOutputStream;
    using BaseObjectType = GConverterOutputStream;
    using BaseClassType = GConverterOutputStreamClass;
    using CppClassParent = FilterOutputStream_Class;
    using BaseClassParent = GFilterOutputStreamClass;

    friend class ConverterOutputStream;
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
