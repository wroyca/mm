
#ifndef _GIOMM_DBUSOBJECTSKELETON_H
#define _GIOMM_DBUSOBJECTSKELETON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/dbusinterfaceskeleton.hxx>
#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/dbusobject.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusObjectSkeleton = struct _GDBusObjectSkeleton;
using GDBusObjectSkeletonClass = struct _GDBusObjectSkeletonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio::DBus
{
  class GIOMM_API ObjectSkeleton_Class;
}
#endif

namespace Gio::DBus
{

  class GIOMM_API ObjectSkeleton : public Glib::Object,
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
    explicit ObjectSkeleton (const Glib::ConstructParams& construct_params);
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
    explicit ObjectSkeleton (const Glib::ustring& object_path);

  public:
    static auto
    create (const Glib::ustring& object_path) -> Glib::RefPtr<ObjectSkeleton>;

    void
    flush ();

    void
    add_interface (const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface);

    void
    remove_interface (const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface);

    void
    remove_interface (const Glib::ustring& interface_name);

    void
    set_object_path (const Glib::ustring& object_path);

    auto
    property_g_object_path () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_g_object_path () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    signal_authorize_method () -> Glib::SignalProxy<
        bool (const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>&,
              const Glib::RefPtr<Gio::DBus::MethodInvocation>&)>;

  public:
  public:
  protected:
    virtual auto
    on_authorize_method (
        const Glib::RefPtr<Gio::DBus::InterfaceSkeleton>& iface,
        const Glib::RefPtr<Gio::DBus::MethodInvocation>& invocation) -> bool;
  };

} // namespace Gio::DBus

namespace Glib
{

  GIOMM_API
  auto
  wrap (GDBusObjectSkeleton* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ObjectSkeleton>;
} // namespace Glib

#endif
