// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/dbusactiongroup.hxx>
#include <libmm-gio/dbusactiongroup_p.hxx>

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
  wrap (GDBusActionGroup* object, const bool take_copy) -> RefPtr<Gio::DBus::ActionGroup>
  {
    return Glib::make_refptr_for_instance<Gio::DBus::ActionGroup> (
        dynamic_cast<Gio::DBus::ActionGroup*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio::DBus
{

  auto
  ActionGroup_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionGroup_Class::class_init_function;

      register_derived_type (g_dbus_action_group_get_type ());

      Gio::ActionGroup::add_interface (get_type ());
      RemoteActionGroup::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ActionGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ActionGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ActionGroup ((GDBusActionGroup*) object);
  }

  auto
  ActionGroup::gobj_copy () -> GDBusActionGroup*
  {
    reference ();
    return gobj ();
  }

  ActionGroup::ActionGroup (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ActionGroup::ActionGroup (GDBusActionGroup* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ActionGroup::ActionGroup (ActionGroup&& src) noexcept
    : Object (std::move (src)),
      Gio::ActionGroup (std::move (src)),
      RemoteActionGroup (std::move (src))
  {
  }

  auto
  ActionGroup::operator= (ActionGroup&& src) noexcept -> ActionGroup&
  {
    Object::operator= (std::move (src));
    Gio::ActionGroup::operator= (std::move (src));
    RemoteActionGroup::operator= (std::move (src));
    return *this;
  }

  ActionGroup::~ActionGroup () noexcept = default;

  ActionGroup::CppClassType ActionGroup::actiongroup_class_;

  auto
  ActionGroup::get_type () -> GType
  {
    return actiongroup_class_.init ().get_type ();
  }

  auto
  ActionGroup::get_base_type () -> GType
  {
    return g_dbus_action_group_get_type ();
  }

  ActionGroup::ActionGroup ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (actiongroup_class_.init ()))
  {
  }

  auto
  ActionGroup::get (const Glib::RefPtr<Connection>& connection,
                    const Glib::ustring& bus_name,
                    const Glib::ustring& object_path) -> Glib::RefPtr<ActionGroup>
  {
    return Glib::wrap (g_dbus_action_group_get (Glib::unwrap (connection),
                                                bus_name.c_str (),
                                                object_path.c_str ()));
  }

} // namespace Gio::DBus
