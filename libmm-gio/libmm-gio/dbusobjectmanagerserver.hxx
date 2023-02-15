// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGERSERVER_H
#define _GIOMM_DBUSOBJECTMANAGERSERVER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusobjectmanager.hxx>
#include <libmm-gio/dbusobjectskeleton.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerServer = struct _GDBusObjectManagerServer;
using GDBusObjectManagerServerClass = struct _GDBusObjectManagerServerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectManagerServer_Class;
}
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectManagerServer : public Glib::Object,
                                        public ObjectManager
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ObjectManagerServer;
    using CppClassType = ObjectManagerServer_Class;
    using BaseObjectType = GDBusObjectManagerServer;
    using BaseClassType = GDBusObjectManagerServerClass;

    ObjectManagerServer (const ObjectManagerServer&) = delete;
    auto
    operator= (const ObjectManagerServer&) -> ObjectManagerServer& = delete;

  private:
    friend class ObjectManagerServer_Class;
    static CppClassType objectmanagerserver_class_;

  protected:
    explicit ObjectManagerServer (
        const Glib::ConstructParams& construct_params);
    explicit ObjectManagerServer (GDBusObjectManagerServer* castitem);

#endif

  public:
    ObjectManagerServer (ObjectManagerServer&& src) noexcept;
    auto
    operator= (ObjectManagerServer&& src) noexcept -> ObjectManagerServer&;

    ~ObjectManagerServer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObjectManagerServer*
    {
      return reinterpret_cast<GDBusObjectManagerServer*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObjectManagerServer*
    {
      return reinterpret_cast<GDBusObjectManagerServer*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusObjectManagerServer*;

  private:
  protected:
    explicit ObjectManagerServer (const Glib::ustring& object_path);

  public:
    static auto
    create (const Glib::ustring& object_path)
        -> Glib::RefPtr<ObjectManagerServer>;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    set_connection (const Glib::RefPtr<Connection>& connection) -> void;

    auto
    export_object (const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object)
        -> void;

    auto
    export_uniquely (const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object)
        -> void;

    auto
    is_exported (const Glib::RefPtr<Gio::DBus::ObjectSkeleton>& object) const
        -> bool;

    auto
    unexport (const Glib::ustring& object_path) -> bool;

    auto
    property_connection () -> Glib::PropertyProxy<Glib::RefPtr<Connection>>;

    auto
    property_connection () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>;

    auto
    property_object_path () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gio::DBus

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectManagerServer* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectManagerServer>;
} // namespace Glib

#endif
