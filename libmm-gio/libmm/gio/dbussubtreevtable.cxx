// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbussubtreevtable.hxx>
#include <libmm/gio/dbussubtreevtable_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbuserror.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace
{

  extern "C"
  {
    static auto
    DBusSubtreeVTable_Enumerate_giomm_callback (GDBusConnection* connection,
                                                const char* sender,
                                                const char* object_path,
                                                void* user_data) -> char**
    {
      const gio::DBus::SubtreeVTable* vtable =
          static_cast<gio::DBus::SubtreeVTable*> (user_data);

      const gio::DBus::SubtreeVTable::SlotSubtreeEnumerate* the_slot =
          vtable->get_slot_enumerate ();

      try
      {
        const auto result =
            (*the_slot) (glib::wrap (connection, true), sender, object_path);

        char** ret = g_new (char*, result.size ());

        for (std::vector<glib::ustring>::size_type i = 0; i < result.size ();
             i++)
        {
          ret[i] = g_strdup (result[i].c_str ());
        }

        return ret;
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return nullptr;
    }

    static auto
    DBusSubtreeVTable_Introspect_giomm_callback (GDBusConnection* connection,
                                                 const char* sender,
                                                 const char* object_path,
                                                 const char* node,
                                                 void* user_data)
        -> GDBusInterfaceInfo**
    {
      const gio::DBus::SubtreeVTable* vtable =
          static_cast<gio::DBus::SubtreeVTable*> (user_data);

      const gio::DBus::SubtreeVTable::SlotSubtreeIntrospect* the_slot =
          vtable->get_slot_introspect ();

      try
      {
        const auto result = (*the_slot) (glib::wrap (connection, true),
                                         sender,
                                         object_path,
                                         node);

        GDBusInterfaceInfo** info = g_new (GDBusInterfaceInfo*, result.size ());

        for (std::vector<glib::RefPtr<gio::DBus::InterfaceInfo>>::size_type i =
                 0;
             i < result.size ();
             i++)
        {
          info[i] = g_object_ref (result[i]->gobj ());
        }

        return info;
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return nullptr;
    }

    static auto
    DBusSubtreeVTable_Dispatch_giomm_callback (GDBusConnection* connection,
                                               const char* sender,
                                               const char* object_path,
                                               const char* interface_name,
                                               const char* node,
                                               void** out_user_data,
                                               void* user_data)
        -> const GDBusInterfaceVTable*
    {
      const gio::DBus::SubtreeVTable* vtable_subtree =
          static_cast<gio::DBus::SubtreeVTable*> (user_data);

      const gio::DBus::SubtreeVTable::SlotSubtreeDispatch* the_slot =
          vtable_subtree->get_slot_dispatch ();

      try
      {
        const gio::DBus::InterfaceVTable* vtable_iface = (*the_slot) (
            glib::wrap (connection, true),
            sender,
            object_path,
            interface_name,
            node ? node : "");

        *out_user_data = const_cast<gio::DBus::InterfaceVTable*> (vtable_iface);

        return vtable_iface->gobj ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return nullptr;
    }
  }
} // namespace

namespace gio::DBus
{

  SubtreeVTable::SubtreeVTable (const SlotSubtreeEnumerate& slot_enumerate,
                                const SlotSubtreeIntrospect& slot_introspect,
                                const SlotSubtreeDispatch& slot_dispatch)
    : slot_enumerate_ (new SlotSubtreeEnumerate (slot_enumerate)),
      slot_introspect_ (new SlotSubtreeIntrospect (slot_introspect)),
      slot_dispatch_ (new SlotSubtreeDispatch (slot_dispatch))
  {
    gobject_.enumerate = &DBusSubtreeVTable_Enumerate_giomm_callback;
    gobject_.introspect = &DBusSubtreeVTable_Introspect_giomm_callback;
    gobject_.dispatch = &DBusSubtreeVTable_Dispatch_giomm_callback;
  }

  SubtreeVTable::SubtreeVTable (SubtreeVTable&& other) noexcept
    : gobject_ (std::move (other.gobject_)),
      slot_enumerate_ (std::move (other.slot_enumerate_)),
      slot_introspect_ (std::move (other.slot_introspect_)),
      slot_dispatch_ (std::move (other.slot_dispatch_))
  {
    other.slot_enumerate_ = nullptr;
    other.slot_introspect_ = nullptr;
    other.slot_dispatch_ = nullptr;
  }

  auto
  SubtreeVTable::operator= (SubtreeVTable&& other) noexcept -> SubtreeVTable&
  {
    delete slot_enumerate_;
    delete slot_introspect_;
    delete slot_dispatch_;

    gobject_ = std::move (other.gobject_);
    slot_enumerate_ = std::move (other.slot_enumerate_);
    slot_introspect_ = std::move (other.slot_introspect_);
    slot_dispatch_ = std::move (other.slot_dispatch_);

    other.slot_enumerate_ = nullptr;
    other.slot_introspect_ = nullptr;
    other.slot_dispatch_ = nullptr;

    return *this;
  }

  SubtreeVTable::~SubtreeVTable ()
  {
    delete slot_enumerate_;
    delete slot_introspect_;
    delete slot_dispatch_;
  }

  auto
  SubtreeVTable::get_slot_enumerate () const -> SlotSubtreeEnumerate*
  {
    return slot_enumerate_;
  }

  auto
  SubtreeVTable::get_slot_introspect () const -> SlotSubtreeIntrospect*
  {
    return slot_introspect_;
  }

  auto
  SubtreeVTable::get_slot_dispatch () const -> SlotSubtreeDispatch*
  {
    return slot_dispatch_;
  }

} // namespace gio::DBus

namespace
{
}

namespace gio::DBus
{

}
