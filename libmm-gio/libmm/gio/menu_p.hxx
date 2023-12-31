// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENU_P_H
#define _GIOMM_MENU_P_H

#include <libmm/gio/menumodel_p.hxx>

#include <libmm/glib/class.hxx>

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Menu_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Menu;
    using BaseObjectType = GMenu;
    using BaseClassType = GMenuClass;
    using CppClassParent = MenuModel_Class;
    using BaseClassParent = GMenuModelClass;

    friend class Menu;
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
