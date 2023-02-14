
#ifndef _GTKMM_ROOT_P_H
#define _GTKMM_ROOT_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API Root_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Root;
    using BaseObjectType = GtkRoot;
    using BaseClassType = GtkRootInterface;
    using CppClassParent = Interface_Class;

    friend class Root;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
