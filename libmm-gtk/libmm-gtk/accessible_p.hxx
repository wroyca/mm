
#ifndef _GTKMM_ACCESSIBLE_P_H
#define _GTKMM_ACCESSIBLE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API Accessible_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Accessible;
    using BaseObjectType = GtkAccessible;
    using BaseClassType = GtkAccessibleInterface;
    using CppClassParent = Interface_Class;

    friend class Accessible;

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
