// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENULINKITER_P_H
#define _GIOMM_MENULINKITER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT MenuLinkIter_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MenuLinkIter;
    using BaseObjectType = GMenuLinkIter;
    using BaseClassType = GMenuLinkIterClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class MenuLinkIter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gio

#endif
