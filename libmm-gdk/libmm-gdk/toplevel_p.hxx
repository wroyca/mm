
#ifndef _GDKMM_TOPLEVEL_P_H
#define _GDKMM_TOPLEVEL_P_H

#include <gdk/gdk.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gdk
{

  class GDKMM_API Toplevel_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Toplevel;
    using BaseObjectType = GdkToplevel;
    using BaseClassType = GdkToplevelInterface;
    using CppClassParent = Interface_Class;

    friend class Toplevel;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
