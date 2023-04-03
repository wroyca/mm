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
namespace Gio::DBus
{
  class LIBMM_GIO_SYMEXPORT InterfaceSkeleton_Class;
}
#endif

namespace Gio::DBus
{

  class LIBMM_GIO_SYMEXPORT InterfaceInfo;
  class LIBMM_GIO_SYMEXPORT Connection;
  class LIBMM_GIO_SYMEXPORT MethodInvocation;

  class LIBMM_GIO_SYMEXPORT InterfaceSkeleton : public Glib::Object,
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
    explicit InterfaceSkeleton (const Glib::ConstructParams& construct_params);
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
    get_info () -> Glib::RefPtr<InterfaceInfo>;

    auto
    get_info () const -> Glib::RefPtr<const InterfaceInfo>;

    auto
    get_properties () const -> Glib::VariantBase;

    auto
    export_interface_skeleton (const Glib::RefPtr<Connection>& connection,
                               const Glib::ustring& object_path) -> void;

    auto
    unexport () -> void;

    auto
    unexport_from_connection (const Glib::RefPtr<Connection>& connection)
        -> void;

    auto
    get_connection () -> Glib::RefPtr<Connection>;

    auto
    get_connection () const -> Glib::RefPtr<const Connection>;

    auto
    get_connections () -> std::vector<Glib::RefPtr<Connection>>;

    auto
    get_connections () const -> std::vector<Glib::RefPtr<const Connection>>;

    auto
    has_connection (const Glib::RefPtr<const Connection>& connection) const
        -> bool;

    auto
    get_object_path () const -> Glib::ustring;

    auto
    get_flags () const -> Flags;

    auto
    set_flags (Flags flags) -> void;

    auto
    property_g_flags () -> Glib::PropertyProxy<Flags>;

    auto
    property_g_flags () const -> Glib::PropertyProxy_ReadOnly<Flags>;

    auto
    signal_authorize_method ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<MethodInvocation>&)>;

  public:
  public:
  protected:
    virtual auto
    on_authorize_method (const Glib::RefPtr<MethodInvocation>& invocation)
        -> bool;
  };

} // namespace Gio::DBus

namespace Gio::DBus
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
} // namespace Gio::DBus

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::DBus::InterfaceSkeleton::Flags>
    : public Glib::Value_Flags<Gio::DBus::InterfaceSkeleton::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusInterfaceSkeleton* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::InterfaceSkeleton>;
} // namespace Glib

#endif
