// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACEVTABLE_H
#define _GIOMM_DBUSINTERFACEVTABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/gio/dbusmethodinvocation.hxx>

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT InterfaceVTable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = InterfaceVTable;
    using BaseObjectType = GDBusInterfaceVTable;
#endif

  private:
  public:
    using SlotInterfaceMethodCall =
        sigc::slot<void (const glib::RefPtr<Connection>&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::VariantContainerBase&,
                         const glib::RefPtr<MethodInvocation>&)>;

    using SlotInterfaceGetProperty =
        sigc::slot<void (glib::VariantBase&,
                         const glib::RefPtr<Connection>&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&)>;

    using SlotInterfaceSetProperty =
        sigc::slot<bool (const glib::RefPtr<Connection>&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::ustring&,
                         const glib::VariantBase&)>;

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

} // namespace gio::DBus

#endif
