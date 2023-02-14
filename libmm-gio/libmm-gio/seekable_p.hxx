
#ifndef _GIOMM_SEEKABLE_P_H
#define _GIOMM_SEEKABLE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gio
{

  class GIOMM_API Seekable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Seekable;
    using BaseObjectType = GSeekable;
    using BaseClassType = GSeekableIface;
    using CppClassParent = Interface_Class;

    friend class Seekable;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gio

#endif
