
#ifndef _PANGOMM_CAIROFONTMAP_P_H
#define _PANGOMM_CAIROFONTMAP_P_H


#include <libmm-glib/interface_p.hpp>

#include <libmm-glib/interface_p.hpp>

namespace Pango
{

class PANGOMM_API CairoFontMap_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = CairoFontMap;
  using BaseObjectType = PangoCairoFontMap;
  using BaseClassType = PangoCairoFontMapIface;
  using CppClassParent = Interface_Class;

  friend class CairoFontMap;

  auto init () -> const Interface_Class&;

  static auto iface_init_function (void *g_iface, void *iface_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Pango


#endif /* _PANGOMM_CAIROFONTMAP_P_H */

