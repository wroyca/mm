// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTMANAGERSERVER_H
#define _GIOMM_DBUSOBJECTMANAGERSERVER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusobjectmanager.hxx>
#include <libmm/gio/dbusobjectskeleton.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectManagerServer = struct _GDBusObjectManagerServer;
using GDBusObjectManagerServerClass = struct _GDBusObjectManagerServerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectManagerServer_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectManagerServer : public glib::Object,
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
        const glib::ConstructParams& construct_params);
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
    explicit ObjectManagerServer (const glib::ustring& object_path);

  public:
    static auto
    create (const glib::ustring& object_path)
        -> glib::RefPtr<ObjectManagerServer>;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    set_connection (const glib::RefPtr<Connection>& connection) -> void;

    auto
    export_object (const glib::RefPtr<gio::DBus::ObjectSkeleton>& object)
        -> void;

    auto
    export_uniquely (const glib::RefPtr<gio::DBus::ObjectSkeleton>& object)
        -> void;

    auto
    is_exported (const glib::RefPtr<gio::DBus::ObjectSkeleton>& object) const
        -> bool;

    auto
    unexport (const glib::ustring& object_path) -> bool;

    auto
    property_connection () -> glib::PropertyProxy<glib::RefPtr<Connection>>;

    auto
    property_connection () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>;

    auto
    property_object_path () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectManagerServer* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ObjectManagerServer>;
} // namespace glib

#endif
