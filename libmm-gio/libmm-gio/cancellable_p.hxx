
#ifndef _GIOMM_CANCELLABLE_P_H
#define _GIOMM_CANCELLABLE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API Cancellable_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Cancellable;
    using BaseObjectType = GCancellable;
    using BaseClassType = GCancellableClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class Cancellable;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    cancelled_callback (GCancellable* self) -> void;
  };

} // namespace Gio

#endif
