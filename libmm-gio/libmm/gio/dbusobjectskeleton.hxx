// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSOBJECTSKELETON_H
#define _GIOMM_DBUSOBJECTSKELETON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusinterfaceskeleton.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>
#include <libmm/gio/dbusobject.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectSkeleton = struct _GDBusObjectSkeleton;
using GDBusObjectSkeletonClass = struct _GDBusObjectSkeletonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT ObjectSkeleton_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT ObjectSkeleton : public glib::Object,
                                   public Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ObjectSkeleton;
    using CppClassType = ObjectSkeleton_Class;
    using BaseObjectType = GDBusObjectSkeleton;
    using BaseClassType = GDBusObjectSkeletonClass;

    ObjectSkeleton (const ObjectSkeleton&) = delete;
    auto
    operator= (const ObjectSkeleton&) -> ObjectSkeleton& = delete;

  private:
    friend class ObjectSkeleton_Class;
    static CppClassType objectskeleton_class_;

  protected:
    explicit ObjectSkeleton (const glib::ConstructParams& construct_params);
    explicit ObjectSkeleton (GDBusObjectSkeleton* castitem);

#endif

  public:
    ObjectSkeleton (ObjectSkeleton&& src) noexcept;
    auto
    operator= (ObjectSkeleton&& src) noexcept -> ObjectSkeleton&;

    ~ObjectSkeleton () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusObjectSkeleton*
    {
      return reinterpret_cast<GDBusObjectSkeleton*> (gobject_);
    }

    auto
    gobj () const -> const GDBusObjectSkeleton*
    {
      return reinterpret_cast<GDBusObjectSkeleton*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusObjectSkeleton*;

  private:
  protected:
    explicit ObjectSkeleton (const glib::ustring& object_path);

  public:
    static auto
    create (const glib::ustring& object_path) -> glib::RefPtr<ObjectSkeleton>;

    auto
    flush () -> void;

    auto
    add_interface (const glib::RefPtr<gio::DBus::InterfaceSkeleton>& iface)
        -> void;

    auto
    remove_interface (const glib::RefPtr<gio::DBus::InterfaceSkeleton>& iface)
        -> void;

    auto
    remove_interface (const glib::ustring& interface_name) -> void;

    auto
    set_object_path (const glib::ustring& object_path) -> void;

    auto
    property_g_object_path () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_g_object_path () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    signal_authorize_method () -> glib::SignalProxy<
        bool (const glib::RefPtr<gio::DBus::InterfaceSkeleton>&,
              const glib::RefPtr<gio::DBus::MethodInvocation>&)>;

  public:
  public:
  protected:
    virtual auto
    on_authorize_method (
        const glib::RefPtr<gio::DBus::InterfaceSkeleton>& iface,
        const glib::RefPtr<gio::DBus::MethodInvocation>& invocation) -> bool;
  };

} // namespace gio::DBus

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusObjectSkeleton* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::ObjectSkeleton>;
} // namespace glib

#endif
