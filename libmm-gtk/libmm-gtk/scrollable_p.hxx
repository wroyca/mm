
#ifndef _GTKMM_SCROLLABLE_P_H
#define _GTKMM_SCROLLABLE_P_H

#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gtk
{

  class GTKMM_API Scrollable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Scrollable;
    using BaseObjectType = GtkScrollable;
    using BaseClassType = GtkScrollableInterface;
    using CppClassParent = Interface_Class;

    friend class Scrollable;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
    static auto
    get_border_vfunc_callback (GtkScrollable* self, GtkBorder* border)
        -> gboolean;
  };

} // namespace Gtk

#endif
