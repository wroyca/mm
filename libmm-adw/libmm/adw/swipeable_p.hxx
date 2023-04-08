// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPEABLE_P_H
#define _LIBADWAITAMM_SWIPEABLE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/interface_p.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT swipeable_class : public glib::Interface_Class
  {
  public:
    using CppObjectType = swipeable;
    using BaseObjectType = AdwSwipeable;
    using BaseClassType = AdwSwipeableInterface;
    using CppClassParent = glib::Interface_Class;

    friend class swipeable;

    auto
    init () -> const glib::Interface_Class&;

    static auto
    iface_init_function (void* g_iface, void* iface_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
