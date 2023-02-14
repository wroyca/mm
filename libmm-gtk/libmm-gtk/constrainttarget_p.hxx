
#ifndef _GTKMM_CONSTRAINTTARGET_P_H
#define _GTKMM_CONSTRAINTTARGET_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API ConstraintTarget_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = ConstraintTarget;
    using BaseObjectType = GtkConstraintTarget;
    using BaseClassType = GtkConstraintTargetInterface;
    using CppClassParent = Interface_Class;

    friend class ConstraintTarget;

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
