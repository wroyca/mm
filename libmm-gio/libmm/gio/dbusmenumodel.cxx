// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusmenumodel.hxx>
#include <libmm/gio/dbusmenumodel_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/dbusconnection.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GDBusMenuModel* object, const bool take_copy) -> RefPtr<gio::DBus::MenuModel>
  {
    return glib::make_refptr_for_instance<gio::DBus::MenuModel> (
        dynamic_cast<gio::DBus::MenuModel*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
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
  MenuModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MenuModel ((GDBusMenuModel*) object);
  }

  auto
  MenuModel::gobj_copy () -> GDBusMenuModel*
  {
    reference ();
    return gobj ();
  }

  MenuModel::MenuModel (const glib::ConstructParams& construct_params)
    : gio::MenuModel (construct_params)
  {
  }

  MenuModel::MenuModel (GDBusMenuModel* castitem)
    : gio::MenuModel ((GMenuModel*) castitem)
  {
  }

  MenuModel::MenuModel (MenuModel&& src) noexcept
    : gio::MenuModel (std::move (src))
  {
  }

  auto
  MenuModel::operator= (MenuModel&& src) noexcept -> MenuModel&
  {
    gio::MenuModel::operator= (std::move (src));
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
      gio::MenuModel (glib::ConstructParams (menumodel_class_.init ()))
  {
  }

  auto
  MenuModel::get (const glib::RefPtr<Connection>& connection,
                  const glib::ustring& bus_name,
                  const glib::ustring& object_path) -> glib::RefPtr<MenuModel>
  {
    return glib::wrap (g_dbus_menu_model_get (glib::unwrap (connection),
                                              bus_name.c_str (),
                                              object_path.c_str ()));
  }

} // namespace gio::DBus
