
#ifndef _GIOMM_NETWORKSERVICE_P_H
#define _GIOMM_NETWORKSERVICE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gio
{

  class GIOMM_API NetworkService_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NetworkService;
    using BaseObjectType = GNetworkService;
    using BaseClassType = GNetworkServiceClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class NetworkService;
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
