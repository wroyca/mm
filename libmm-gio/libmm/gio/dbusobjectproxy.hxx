// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTPROXY_H
#define _GIOMM_DBUSOBJECTPROXY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbusobject.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectProxy = struct _GDBusObjectProxy;
using GDBusObjectProxyClass = struct _GDBusObjectProxyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectProxy_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectProxy : public glib::Object,
                                public Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ObjectProxy;
    using CppClassType = ObjectProxy_Class;
    using BaseObjectType = GDBusObjectProxy;
    using BaseClassType = GDBusObjectProxyClass;

    ObjectProxy (const ObjectProxy&) = delete;
    auto
    operator= (const ObjectProxy&) -> ObjectProxy& = delete;

  private:
    friend class ObjectProxy_Class;
    static CppClassType objectproxy_class_;

  protected:
    explicit ObjectProxy (const glib::ConstructParams& construct_params);
    explicit ObjectProxy (GDBusObjectProxy* castitem);

#endif

  public:
    ObjectProxy (ObjectProxy&& src) noexcept;
    auto
    operator= (ObjectProxy&& src) noexcept -> ObjectProxy&;

    ~ObjectProxy () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObjectProxy*
    {
      return reinterpret_cast<GDBusObjectProxy*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObjectProxy*
    {
      return reinterpret_cast<GDBusObjectProxy*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusObjectProxy*;

  private:
  protected:
    explicit ObjectProxy (const glib::RefPtr<Connection>& connection,
                          const glib::ustring& object_path);

  public:
    static auto
    create (const glib::RefPtr<Connection>& connection,
            const glib::ustring& object_path) -> glib::RefPtr<ObjectProxy>;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    property_g_connection () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Connection>>;

    auto
    property_g_object_path () const
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
  wrap (GDBusObjectProxy* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ObjectProxy>;
} // namespace glib

#endif
