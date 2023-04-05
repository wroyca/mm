// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusactiongroup.hxx>
#include <libmm/gio/dbusactiongroup_p.hxx>

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
  wrap (GDBusActionGroup* object, const bool take_copy) -> RefPtr<gio::DBus::ActionGroup>
  {
    return glib::make_refptr_for_instance<gio::DBus::ActionGroup> (
        dynamic_cast<gio::DBus::ActionGroup*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  ActionGroup_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionGroup_Class::class_init_function;

      register_derived_type (g_dbus_action_group_get_type ());

      gio::ActionGroup::add_interface (get_type ());
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
  ActionGroup_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ActionGroup ((GDBusActionGroup*) object);
  }

  auto
  ActionGroup::gobj_copy () -> GDBusActionGroup*
  {
    reference ();
    return gobj ();
  }

  ActionGroup::ActionGroup (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ActionGroup::ActionGroup (GDBusActionGroup* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ActionGroup::ActionGroup (ActionGroup&& src) noexcept
    : Object (std::move (src)),
      gio::ActionGroup (std::move (src)),
      RemoteActionGroup (std::move (src))
  {
  }

  auto
  ActionGroup::operator= (ActionGroup&& src) noexcept -> ActionGroup&
  {
    Object::operator= (std::move (src));
    gio::ActionGroup::operator= (std::move (src));
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
      Object (glib::ConstructParams (actiongroup_class_.init ()))
  {
  }

  auto
  ActionGroup::get (const glib::RefPtr<Connection>& connection,
                    const glib::ustring& bus_name,
                    const glib::ustring& object_path) -> glib::RefPtr<ActionGroup>
  {
    return glib::wrap (g_dbus_action_group_get (glib::unwrap (connection),
                                                bus_name.c_str (),
                                                object_path.c_str ()));
  }

} // namespace gio::DBus
