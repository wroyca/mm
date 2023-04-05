// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTERFACESKELETON_H
#define _GIOMM_DBUSINTERFACESKELETON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/dbusinterface.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDBusInterfaceSkeleton = struct _GDBusInterfaceSkeleton;
using GDBusInterfaceSkeletonClass = struct _GDBusInterfaceSkeletonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio::DBus
{
  class LIBMM_GIO_SYMEXPORT InterfaceSkeleton_Class;
}
#endif

namespace gio::DBus
{

  class LIBMM_GIO_SYMEXPORT InterfaceInfo;
  class LIBMM_GIO_SYMEXPORT Connection;
  class LIBMM_GIO_SYMEXPORT MethodInvocation;

  class LIBMM_GIO_SYMEXPORT InterfaceSkeleton : public glib::Object,
                                      public Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = InterfaceSkeleton;
    using CppClassType = InterfaceSkeleton_Class;
    using BaseObjectType = GDBusInterfaceSkeleton;
    using BaseClassType = GDBusInterfaceSkeletonClass;

    InterfaceSkeleton (const InterfaceSkeleton&) = delete;
    auto
    operator= (const InterfaceSkeleton&) -> InterfaceSkeleton& = delete;

  private:
    friend class InterfaceSkeleton_Class;
    static CppClassType interfaceskeleton_class_;

  protected:
    explicit InterfaceSkeleton (const glib::ConstructParams& construct_params);
    explicit InterfaceSkeleton (GDBusInterfaceSkeleton* castitem);

#endif

  public:
    InterfaceSkeleton (InterfaceSkeleton&& src) noexcept;
    auto
    operator= (InterfaceSkeleton&& src) noexcept -> InterfaceSkeleton&;

    ~InterfaceSkeleton () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GDBusInterfaceSkeleton*
    {
      return reinterpret_cast<GDBusInterfaceSkeleton*> (gobject_);
    }

    auto
    gobj () const -> const GDBusInterfaceSkeleton*
    {
      return reinterpret_cast<GDBusInterfaceSkeleton*> (gobject_);
    }

    auto
    gobj_copy () -> GDBusInterfaceSkeleton*;

  private:
  public:
    enum class Flags
    {
      NONE = 0x0,
      HANDLE_METHOD_INVOCATIONS_IN_THREAD = (1 << 0)
    };

    auto
    flush () -> void;

    auto
    get_info () -> glib::RefPtr<InterfaceInfo>;

    auto
    get_info () const -> glib::RefPtr<const InterfaceInfo>;

    auto
    get_properties () const -> glib::VariantBase;

    auto
    export_interface_skeleton (const glib::RefPtr<Connection>& connection,
                               const glib::ustring& object_path) -> void;

    auto
    unexport () -> void;

    auto
    unexport_from_connection (const glib::RefPtr<Connection>& connection)
        -> void;

    auto
    get_connection () -> glib::RefPtr<Connection>;

    auto
    get_connection () const -> glib::RefPtr<const Connection>;

    auto
    get_connections () -> std::vector<glib::RefPtr<Connection>>;

    auto
    get_connections () const -> std::vector<glib::RefPtr<const Connection>>;

    auto
    has_connection (const glib::RefPtr<const Connection>& connection) const
        -> bool;

    auto
    get_object_path () const -> glib::ustring;

    auto
    get_flags () const -> Flags;

    auto
    set_flags (Flags flags) -> void;

    auto
    property_g_flags () -> glib::PropertyProxy<Flags>;

    auto
    property_g_flags () const -> glib::PropertyProxy_ReadOnly<Flags>;

    auto
    signal_authorize_method ()
        -> glib::SignalProxy<bool (const glib::RefPtr<MethodInvocation>&)>;

  public:
  public:
  protected:
    virtual auto
    on_authorize_method (const glib::RefPtr<MethodInvocation>& invocation)
        -> bool;
  };

} // namespace gio::DBus

namespace gio::DBus
{

  inline auto
  operator| (InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  {
    return static_cast<InterfaceSkeleton::Flags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  {
    return static_cast<InterfaceSkeleton::Flags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (InterfaceSkeleton::Flags lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags
  {
    return static_cast<InterfaceSkeleton::Flags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(InterfaceSkeleton::Flags flags) -> InterfaceSkeleton::Flags
  {
    return static_cast<InterfaceSkeleton::Flags> (
        ~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  {
    return (lhs = static_cast<InterfaceSkeleton::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  {
    return (lhs = static_cast<InterfaceSkeleton::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (InterfaceSkeleton::Flags& lhs, InterfaceSkeleton::Flags rhs) -> InterfaceSkeleton::Flags&
  {
    return (lhs = static_cast<InterfaceSkeleton::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<gio::DBus::InterfaceSkeleton::Flags>
    : public glib::Value_Flags<gio::DBus::InterfaceSkeleton::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusInterfaceSkeleton* object, bool take_copy = false) -> glib::RefPtr<gio::DBus::InterfaceSkeleton>;
} // namespace glib

#endif
