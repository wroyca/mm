
#ifndef _GDKMM_POPUP_P_H
#define _GDKMM_POPUP_P_H


#include <libmm-glib/interface_p.hpp>
#include <gdk/gdk.h>

#include <libmm-glib/interface_p.hpp>

namespace Gdk
{

class GDKMM_API Popup_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Popup;
  using BaseObjectType = GdkPopup;
  using BaseClassType = GdkPopupInterface;
  using CppClassParent = Interface_Class;

  friend class Popup;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gdk


#endif /* _GDKMM_POPUP_P_H */

