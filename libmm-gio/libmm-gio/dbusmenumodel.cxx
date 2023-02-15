// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusmenumodel.hxx>
#include <libmm-gio/dbusmenumodel_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/dbusconnection.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GDBusMenuModel* object, const bool take_copy) -> RefPtr<Gio::DBus::MenuModel>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::MenuModel> (
        dynamic_cast<Gio::DBus::MenuModel*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio::DBus
{

  auto
  MenuModel_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuModel_Class::class_init_function;

      register_derived_type (g_dbus_menu_model_get_type ());
    }

    return *this;
  }

  auto
  MenuModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MenuModel ((GDBusMenuModel*) object);
  }

  auto
  MenuModel::gobj_copy () -> GDBusMenuModel*
  {
    reference ();
    return gobj ();
  }

  MenuModel::MenuModel (const Glib::ConstructParams& construct_params)
    : Gio::MenuModel (construct_params)
  {
  }

  MenuModel::MenuModel (GDBusMenuModel* castitem)
    : Gio::MenuModel ((GMenuModel*) castitem)
  {
  }

  MenuModel::MenuModel (MenuModel&& src) noexcept
    : Gio::MenuModel (std::move (src))
  {
  }

  auto
  MenuModel::operator= (MenuModel&& src) noexcept -> MenuModel&
  {
    Gio::MenuModel::operator= (std::move (src));
    return *this;
  }

  MenuModel::~MenuModel () noexcept = default;

  MenuModel::CppClassType MenuModel::menumodel_class_;

  auto
  MenuModel::get_type () -> GType
  {
    return menumodel_class_.init ().get_type ();
  }

  auto
  MenuModel::get_base_type () -> GType
  {
    return g_dbus_menu_model_get_type ();
  }

  MenuModel::MenuModel ()
    : ObjectBase (nullptr),
      Gio::MenuModel (Glib::ConstructParams (menumodel_class_.init ()))
  {
  }

  auto
  MenuModel::get (const Glib::RefPtr<Connection>& connection,
                  const Glib::ustring& bus_name,
                  const Glib::ustring& object_path) -> Glib::RefPtr<MenuModel>
  {
    return Glib::wrap (g_dbus_menu_model_get (Glib::unwrap (connection),
                                              bus_name.c_str (),
                                              object_path.c_str ()));
  }

} // namespace Gio::DBus
