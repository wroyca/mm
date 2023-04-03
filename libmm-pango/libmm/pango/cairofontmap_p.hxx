// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_CAIROFONTMAP_P_H
#define _PANGOMM_CAIROFONTMAP_P_H

#include <libmm/glib/interface_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT CairoFontMap_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = CairoFontMap;
    using BaseObjectType = PangoCairoFontMap;
    using BaseClassType = PangoCairoFontMapIface;
    using CppClassParent = Interface_Class;

    friend class CairoFontMap;

    auto
    init () -> const Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Pango

#endif