
#ifndef _GIOMM_CONVERTERINPUTSTREAM_P_H
#define _GIOMM_CONVERTERINPUTSTREAM_P_H

#include <libmm-gio/filterinputstream_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API ConverterInputStream_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ConverterInputStream;
    using BaseObjectType = GConverterInputStream;
    using BaseClassType = GConverterInputStreamClass;
    using CppClassParent = FilterInputStream_Class;
    using BaseClassParent = GFilterInputStreamClass;

    friend class ConverterInputStream;
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
