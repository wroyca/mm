// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSACTIONGROUP_H
#define _GIOMM_DBUSACTIONGROUP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/actiongroup.hxx>
#include <libmm/gio/remoteactiongroup.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusActionGroup = struct _GDBusActionGroup;
using GDBusActionGroupClass = struct _GDBusActionGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ActionGroup_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT Connection;

  class LIBMM_GIO_SYMEXPORT ActionGroup : public glib::Object,
                                public gio::ActionGroup,
                                public gio::RemoteActionGroup
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ActionGroup;
    using CppClassType = ActionGroup_Class;
    using BaseObjectType = GDBusActionGroup;
    using BaseClassType = GDBusActionGroupClass;

    ActionGroup (const ActionGroup&) = delete;
    auto
    operator= (const ActionGroup&) -> ActionGroup& = delete;

  private:
    friend class ActionGroup_Class;
    static CppClassType actiongroup_class_;

  protected:
    explicit ActionGroup (const glib::ConstructParams& construct_params);
    explicit ActionGroup (GDBusActionGroup* castitem);

#endif

  public:
    ActionGroup (ActionGroup&& src) noexcept;
    auto
    operator= (ActionGroup&& src) noexcept -> ActionGroup&;

    ~ActionGroup () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusActionGroup*
    {
      return reinterpret_cast<GDBusActionGroup*> (gobject_);
    }

    auto
    gobj () const -> const GDBusActionGroup*
    {
      return reinterpret_cast<GDBusActionGroup*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusActionGroup*;

  private:
  protected:
    ActionGroup ();

  public:
    static auto
    get (const glib::RefPtr<Connection>& connection,
         const glib::ustring& bus_name,
         const glib::ustring& object_path) -> glib::RefPtr<ActionGroup>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusActionGroup* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ActionGroup>;
} // namespace glib

#endif
