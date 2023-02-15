// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_POPUP_P_H
#define _GDKMM_POPUP_P_H

#include <gdk/gdk.h>
#include <libmm-glib/interface_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Gdk
{

  class GDKMM_API Popup_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Popup;
    using BaseObjectType = GdkPopup;
    using BaseClassType = GdkPopupInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class Popup;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gdk

#endif
