// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTPROXY_H
#define _GIOMM_DBUSOBJECTPROXY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbusobject.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectProxy = struct _GDBusObjectProxy;
using GDBusObjectProxyClass = struct _GDBusObjectProxyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectProxy_Class;
}
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectProxy : public Glib::Object,
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
    explicit ObjectProxy (const Glib::ConstructParams& construct_params);
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
    explicit ObjectProxy (const Glib::RefPtr<Connection>& connection,
                          const Glib::ustring& object_path);

  public:
    static auto
    create (const Glib::RefPtr<Connection>& connection,
            const Glib::ustring& object_path) -> Glib::RefPtr<ObjectProxy>;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    property_g_connection () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Connection>>;

    auto
    property_g_object_path () const
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
  wrap (GDBusObjectProxy* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectProxy>;
} // namespace Glib

#endif
