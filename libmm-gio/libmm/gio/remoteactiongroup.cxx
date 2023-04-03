// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/remoteactiongroup.hxx>
#include <libmm/gio/remoteactiongroup_p.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GRemoteActionGroup* object, const bool take_copy) -> RefPtr<Gio::RemoteActionGroup>
  {
    return Glib::make_refptr_for_instance<Gio::RemoteActionGroup> (
        Glib::wrap_auto_interface<Gio::RemoteActionGroup> ((GObject*) object,
                                                           take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  RemoteActionGroup_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &RemoteActionGroup_Class::iface_init_function;

      gtype_ = g_remote_action_group_get_type ();
    }

    return *this;
  }

  auto
  RemoteActionGroup_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->activate_action_full = &activate_action_full_vfunc_callback;
    klass->change_action_state_full = &change_action_state_full_vfunc_callback;
  }

  auto
  RemoteActionGroup_Class::activate_action_full_vfunc_callback (
      GRemoteActionGroup* self,
      const gchar* action_name,
      GVariant* parameter,
      GVariant* platform_data) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->activate_action_full_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name),
              Glib::wrap (parameter, true),
              Glib::wrap (platform_data, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->activate_action_full)
      (*base->activate_action_full) (self,
                                     action_name,
                                     parameter,
                                     platform_data);
  }

  auto
  RemoteActionGroup_Class::change_action_state_full_vfunc_callback (
      GRemoteActionGroup* self,
      const gchar* action_name,
      GVariant* value,
      GVariant* platform_data) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->change_action_state_full_vfunc (
              Glib::convert_const_gchar_ptr_to_ustring (action_name),
              Glib::wrap (value, true),
              Glib::wrap (platform_data, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->change_action_state_full)
      (*base->change_action_state_full) (self,
                                         action_name,
                                         value,
                                         platform_data);
  }

  auto
  RemoteActionGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new RemoteActionGroup ((GRemoteActionGroup*) object);
  }

  RemoteActionGroup::RemoteActionGroup ()
    : Interface (remoteactiongroup_class_.init ())
  {
  }

  RemoteActionGroup::RemoteActionGroup (GRemoteActionGroup* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  RemoteActionGroup::RemoteActionGroup (
      const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  RemoteActionGroup::RemoteActionGroup (RemoteActionGroup&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  RemoteActionGroup::operator= (RemoteActionGroup&& src) noexcept -> RemoteActionGroup&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  RemoteActionGroup::~RemoteActionGroup () noexcept = default;

  auto
  RemoteActionGroup::add_interface (const GType gtype_implementer) -> void
  {
    remoteactiongroup_class_.init ().add_interface (gtype_implementer);
  }

  RemoteActionGroup::CppClassType RemoteActionGroup::remoteactiongroup_class_;

  auto
  RemoteActionGroup::get_type () -> GType
  {
    return remoteactiongroup_class_.init ().get_type ();
  }

  auto
  RemoteActionGroup::get_base_type () -> GType
  {
    return g_remote_action_group_get_type ();
  }

  auto
  RemoteActionGroup::activate_action (const Glib::ustring& action_name,
                                      const Glib::VariantBase& parameter,
                                      const Glib::VariantBase& platform_data) -> void
  {
    g_remote_action_group_activate_action_full (
        gobj (),
        action_name.c_str (),
        const_cast<GVariant*> (parameter.gobj ()),
        const_cast<GVariant*> (platform_data.gobj ()));
  }

  auto
  RemoteActionGroup::change_action_state (
      const Glib::ustring& action_name,
      const Glib::VariantBase& value,
      const Glib::VariantBase& platform_data) -> void
  {
    g_remote_action_group_change_action_state_full (
        gobj (),
        action_name.c_str (),
        const_cast<GVariant*> (value.gobj ()),
        const_cast<GVariant*> (platform_data.gobj ()));
  }

  auto
  RemoteActionGroup::activate_action_full_vfunc (
      const Glib::ustring& action_name,
      const Glib::VariantBase& parameter,
      const Glib::VariantBase& platform_data) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->activate_action_full)
    {
      (*base->activate_action_full) (
          gobj (),
          action_name.c_str (),
          const_cast<GVariant*> (parameter.gobj ()),
          const_cast<GVariant*> (platform_data.gobj ()));
    }
  }

  auto
  RemoteActionGroup::change_action_state_full_vfunc (
      const Glib::ustring& action_name,
      const Glib::VariantBase& value,
      const Glib::VariantBase& platform_data) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->change_action_state_full)
    {
      (*base->change_action_state_full) (
          gobj (),
          action_name.c_str (),
          const_cast<GVariant*> (value.gobj ()),
          const_cast<GVariant*> (platform_data.gobj ()));
    }
  }

} // namespace Gio
