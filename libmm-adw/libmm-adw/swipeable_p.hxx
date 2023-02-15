// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPEABLE_P_H
#define _LIBADWAITAMM_SWIPEABLE_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/interface_p.hxx>

namespace Adw
{

  class Swipeable_Class : public Glib::Interface_Class
  {
  public:
    using CppObjectType = Swipeable;
    using BaseObjectType = AdwSwipeable;
    using BaseClassType = AdwSwipeableInterface;
    using CppClassParent = Glib::Interface_Class;

    friend class Swipeable;

    auto
    init () -> const Glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
