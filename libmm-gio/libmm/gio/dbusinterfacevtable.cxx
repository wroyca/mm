// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusinterfacevtable.hxx>
#include <libmm/gio/dbusinterfacevtable_p.hxx>

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
    DBusInterfaceVTable_MethodCall_giomm_callback (
        GDBusConnection* connection,
        const char* sender,
        const char* object_path,
        const char* interface_name,
        const char* method_name,
        GVariant* parameters,
        GDBusMethodInvocation* invocation,
        void* user_data) -> void
    {
      const gio::DBus::InterfaceVTable* vtable =
          static_cast<gio::DBus::InterfaceVTable*> (user_data);

      const gio::DBus::InterfaceVTable::SlotInterfaceMethodCall* the_slot =
          vtable->get_slot_method_call ();

      try
      {
        (*the_slot) (glib::wrap (connection, true),
                     sender ? sender : "",
                     object_path,
                     interface_name,
                     method_name,
                     glib::VariantContainerBase (parameters, true),
                     glib::wrap (invocation, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    static auto
    DBusInterfaceVTable_GetProperty_giomm_callback (GDBusConnection* connection,
                                                    const char* sender,
                                                    const char* object_path,
                                                    const char* interface_name,
                                                    const char* property_name,
                                                    GError** error,
                                                    void* user_data)
        -> GVariant*
    {
      const gio::DBus::InterfaceVTable* vtable =
          static_cast<gio::DBus::InterfaceVTable*> (user_data);

      const gio::DBus::InterfaceVTable::SlotInterfaceGetProperty* the_slot =
          vtable->get_slot_get_property ();

      try
      {
        glib::VariantBase result;

        (*the_slot) (result,
                     glib::wrap (connection, true),
                     sender,
                     object_path,
                     interface_name,
                     property_name);
        return result.gobj_copy ();
      }
      catch (const glib::Error& ex)
      {
        if (error)
          *error = g_error_copy (ex.gobj ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return nullptr;
    }

    static auto
    DBusInterfaceVTable_SetProperty_giomm_callback (GDBusConnection* connection,
                                                    const char* sender,
                                                    const char* object_path,
                                                    const char* interface_name,
                                                    const char* property_name,
                                                    GVariant* value,
                                                    GError** error,
                                                    void* user_data) -> gboolean
    {
      const gio::DBus::InterfaceVTable* vtable =
          static_cast<gio::DBus::InterfaceVTable*> (user_data);

      const gio::DBus::InterfaceVTable::SlotInterfaceSetProperty* the_slot =
          vtable->get_slot_set_property ();

      try
      {
        return (*the_slot) (glib::wrap (connection, true),
                            sender,
                            object_path,
                            interface_name,
                            property_name,
                            glib::VariantBase (value, true));
      }
      catch (const glib::Error& ex)
      {
        if (error)
          *error = g_error_copy (ex.gobj ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }

      return false;
    }
  }
} // namespace

namespace gio::DBus
{

  InterfaceVTable::InterfaceVTable (
      const SlotInterfaceMethodCall& slot_method_call,
      const SlotInterfaceGetProperty& slot_get_property,
      const SlotInterfaceSetProperty& slot_set_property)
    : slot_method_call_ (new SlotInterfaceMethodCall (slot_method_call)),
      slot_get_property_ (new SlotInterfaceGetProperty (slot_get_property)),
      slot_set_property_ (new SlotInterfaceSetProperty (slot_set_property))
  {
    gobject_.method_call = &DBusInterfaceVTable_MethodCall_giomm_callback;
    gobject_.get_property = &DBusInterfaceVTable_GetProperty_giomm_callback;
    gobject_.set_property = &DBusInterfaceVTable_SetProperty_giomm_callback;
  }

  InterfaceVTable::InterfaceVTable (InterfaceVTable&& other) noexcept
    : gobject_ (std::move (other.gobject_)),
      slot_method_call_ (std::move (other.slot_method_call_)),
      slot_get_property_ (std::move (other.slot_get_property_)),
      slot_set_property_ (std::move (other.slot_set_property_))
  {
    other.slot_method_call_ = nullptr;
    other.slot_get_property_ = nullptr;
    other.slot_set_property_ = nullptr;
  }

  auto
  InterfaceVTable::operator= (InterfaceVTable&& other) noexcept -> InterfaceVTable&
  {
    delete slot_method_call_;
    delete slot_get_property_;
    delete slot_set_property_;

    gobject_ = std::move (other.gobject_);
    slot_method_call_ = std::move (other.slot_method_call_);
    slot_get_property_ = std::move (other.slot_get_property_);
    slot_set_property_ = std::move (other.slot_set_property_);

    other.slot_method_call_ = nullptr;
    other.slot_get_property_ = nullptr;
    other.slot_set_property_ = nullptr;

    return *this;
  }

  InterfaceVTable::~InterfaceVTable ()
  {
    delete slot_method_call_;
    delete slot_get_property_;
    delete slot_set_property_;
  }

  auto
  InterfaceVTable::get_slot_method_call () const -> SlotInterfaceMethodCall*
  {
    return slot_method_call_;
  }

  auto
  InterfaceVTable::get_slot_get_property () const -> SlotInterfaceGetProperty*
  {
    return slot_get_property_;
  }

  auto
  InterfaceVTable::get_slot_set_property () const -> SlotInterfaceSetProperty*
  {
    return slot_set_property_;
  }

} // namespace gio::DBus

namespace
{
}

namespace gio::DBus
{

}
