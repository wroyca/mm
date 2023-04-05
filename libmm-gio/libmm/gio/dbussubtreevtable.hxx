// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSSUBTREEVTABLE_H
#define _GIOMM_DBUSSUBTREEVTABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/gio/dbusinterfacevtable.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT SubtreeVTable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SubtreeVTable;
    using BaseObjectType = GDBusSubtreeVTable;
#endif

  private:
  public:
    using SlotSubtreeEnumerate =
        sigc::slot<std::vector<glib::ustring> (const glib::RefPtr<Connection>&,
                                               const glib::ustring&,
                                               const glib::ustring&)>;

    using SlotSubtreeIntrospect =
        sigc::slot<std::vector<glib::RefPtr<gio::DBus::InterfaceInfo>> (
            const glib::RefPtr<Connection>&,
            const glib::ustring&,
            const glib::ustring&,
            const glib::ustring&)>;

    using SlotSubtreeDispatch =
        sigc::slot<const InterfaceVTable*(const glib::RefPtr<Connection>&,
                                          const glib::ustring&,
                                          const glib::ustring&,
                                          const glib::ustring&,
                                          const glib::ustring&)>;

    explicit SubtreeVTable (const SlotSubtreeEnumerate& slot_enumerate,
                            const SlotSubtreeIntrospect& slot_introspect = {},
                            const SlotSubtreeDispatch& slot_dispatch = {});

    SubtreeVTable (const SubtreeVTable& other) = delete;
    auto
    operator= (const SubtreeVTable& other) -> SubtreeVTable& = delete;

    SubtreeVTable (SubtreeVTable&& other) noexcept;
    auto
    operator= (SubtreeVTable&& other) noexcept -> SubtreeVTable&;

    virtual ~SubtreeVTable ();

    auto
    gobj () -> GDBusSubtreeVTable*
    {
      return reinterpret_cast<GDBusSubtreeVTable*> (&gobject_);
    }

    auto
    gobj () const -> const GDBusSubtreeVTable*
    {
      return reinterpret_cast<const GDBusSubtreeVTable*> (&gobject_);
    }

  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    get_slot_enumerate () const -> SlotSubtreeEnumerate*;
    auto
    get_slot_introspect () const -> SlotSubtreeIntrospect*;
    auto
    get_slot_dispatch () const -> SlotSubtreeDispatch*;
#endif

  protected:
    GDBusSubtreeVTable gobject_;

    SlotSubtreeEnumerate* slot_enumerate_;
    SlotSubtreeIntrospect* slot_introspect_;
    SlotSubtreeDispatch* slot_dispatch_;
  };

} // namespace gio::DBus

#endif
