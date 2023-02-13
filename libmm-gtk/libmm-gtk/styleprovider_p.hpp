
#ifndef _GTKMM_STYLEPROVIDER_P_H
#define _GTKMM_STYLEPROVIDER_P_H


#include <libmm-glib/interface_p.hpp>

#include <libmm-glib/interface_p.hpp>

namespace Gtk
{

class GTKMM_API StyleProvider_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = StyleProvider;
  using BaseObjectType = GtkStyleProvider;
  using BaseClassType = GtkStyleProviderIface;
  using CppClassParent = Interface_Class;

  friend class StyleProvider;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_STYLEPROVIDER_P_H */

