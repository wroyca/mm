// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSMENUMODEL_P_H
#define _GIOMM_DBUSMENUMODEL_P_H

#include <libmm/gio/menumodel_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gio
{

  namespace DBus
  {

    class LIBMM_GIO_SYMEXPORT MenuModel_Class : public Glib::Class
    {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
      using CppObjectType = MenuModel;
      using BaseObjectType = GDBusMenuModel;
      using BaseClassType = GDBusMenuModelClass;
      using CppClassParent = Gio::MenuModel_Class;
      using BaseClassParent = GMenuModelClass;

      friend class MenuModel;
#endif

      auto
      init () -> const Class&;

      static auto
      class_init_function (void* g_class, void* class_data) -> void;

      static auto
      wrap_new (GObject*) -> Glib::ObjectBase*;

    protected:
    };

  } // namespace DBus

} // namespace Gio

#endif
