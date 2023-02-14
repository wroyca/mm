
#ifndef _GLIBMM_BINDING_P_H
#define _GLIBMM_BINDING_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Glib
{

  class GLIBMM_API Binding_Class : public Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Binding;
    using BaseObjectType = GBinding;
    using BaseClassType = GBindingClass;
    using CppClassParent = Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Binding;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> ObjectBase*;

  protected:
  };

} // namespace Glib

#endif
