// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACEVTABLE_H
#define _GIOMM_DBUSINTERFACEVTABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-gio/dbusmethodinvocation.hxx>

namespace Gio::DBus
{

  class GIOMM_API InterfaceVTable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = InterfaceVTable;
    using BaseObjectType = GDBusInterfaceVTable;
#endif

  private:
  public:
    using SlotInterfaceMethodCall =
        sigc::slot<void (const Glib::RefPtr<Connection>&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::VariantContainerBase&,
                         const Glib::RefPtr<MethodInvocation>&)>;

    using SlotInterfaceGetProperty =
        sigc::slot<void (Glib::VariantBase&,
                         const Glib::RefPtr<Connection>&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&)>;

    using SlotInterfaceSetProperty =
        sigc::slot<bool (const Glib::RefPtr<Connection>&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::ustring&,
                         const Glib::VariantBase&)>;

    explicit InterfaceVTable (
        const SlotInterfaceMethodCall& slot_method_call,
        const SlotInterfaceGetProperty& slot_get_property = {},
        const SlotInterfaceSetProperty& slot_set_property = {});

    InterfaceVTable (const InterfaceVTable& other) = delete;
    auto
    operator= (const InterfaceVTable& other) -> InterfaceVTable& = delete;

    InterfaceVTable (InterfaceVTable&& other) noexcept;
    auto
    operator= (InterfaceVTable&& other) noexcept -> InterfaceVTable&;

    virtual ~InterfaceVTable ();

    auto
    gobj () -> GDBusInterfaceVTable*
    {
      return reinterpret_cast<GDBusInterfaceVTable*> (&gobject_);
    }

    auto
    gobj () const -> const GDBusInterfaceVTable*
    {
      return reinterpret_cast<const GDBusInterfaceVTable*> (&gobject_);
    }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    get_slot_method_call () const -> SlotInterfaceMethodCall*;
    auto
    get_slot_get_property () const -> SlotInterfaceGetProperty*;
    auto
    get_slot_set_property () const -> SlotInterfaceSetProperty*;
#endif

  protected:
    GDBusInterfaceVTable gobject_;

    SlotInterfaceMethodCall* slot_method_call_;
    SlotInterfaceGetProperty* slot_get_property_;
    SlotInterfaceSetProperty* slot_set_property_;
  };

} // namespace Gio::DBus

#endif
