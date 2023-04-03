// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_DBUSINTROSPECTION_H
#define _GIOMM_DBUSINTROSPECTION_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/value.hxx>
#include <vector>

namespace Gio::DBus
{

  enum class PropertyInfoFlags
  {
    NONE = 0x0,
    READABLE = (1 << 0),
    WRITABLE = (1 << 1)
  };

  inline auto
  operator| (PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  {
    return static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  {
    return static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  {
    return static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(PropertyInfoFlags flags) -> PropertyInfoFlags
  {
    return static_cast<PropertyInfoFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  {
    return (lhs = static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  {
    return (lhs = static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  {
    return (lhs = static_cast<PropertyInfoFlags> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }

  class LIBMM_GIO_SYMEXPORT AnnotationInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AnnotationInfo;
    using BaseObjectType = GDBusAnnotationInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusAnnotationInfo*;

    auto
    gobj () const -> const GDBusAnnotationInfo*;

    auto
    gobj_copy () const -> GDBusAnnotationInfo*;

    AnnotationInfo () = delete;

    AnnotationInfo (const AnnotationInfo&) = delete;
    auto
    operator= (const AnnotationInfo&) -> AnnotationInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    info_lookup (const std::vector<Glib::RefPtr<AnnotationInfo>>& annotations,
                 const Glib::ustring& name) -> Glib::ustring;
  };

  class LIBMM_GIO_SYMEXPORT ArgInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ArgInfo;
    using BaseObjectType = GDBusArgInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusArgInfo*;

    auto
    gobj () const -> const GDBusArgInfo*;

    auto
    gobj_copy () const -> GDBusArgInfo*;

    ArgInfo () = delete;

    ArgInfo (const ArgInfo&) = delete;
    auto
    operator= (const ArgInfo&) -> ArgInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
  };

  class LIBMM_GIO_SYMEXPORT MethodInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MethodInfo;
    using BaseObjectType = GDBusMethodInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusMethodInfo*;

    auto
    gobj () const -> const GDBusMethodInfo*;

    auto
    gobj_copy () const -> GDBusMethodInfo*;

    MethodInfo () = delete;

    MethodInfo (const MethodInfo&) = delete;
    auto
    operator= (const MethodInfo&) -> MethodInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
  };

  class LIBMM_GIO_SYMEXPORT SignalInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SignalInfo;
    using BaseObjectType = GDBusSignalInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusSignalInfo*;

    auto
    gobj () const -> const GDBusSignalInfo*;

    auto
    gobj_copy () const -> GDBusSignalInfo*;

    SignalInfo () = delete;

    SignalInfo (const SignalInfo&) = delete;
    auto
    operator= (const SignalInfo&) -> SignalInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
  };

  class LIBMM_GIO_SYMEXPORT PropertyInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PropertyInfo;
    using BaseObjectType = GDBusPropertyInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusPropertyInfo*;

    auto
    gobj () const -> const GDBusPropertyInfo*;

    auto
    gobj_copy () const -> GDBusPropertyInfo*;

    PropertyInfo () = delete;

    PropertyInfo (const PropertyInfo&) = delete;
    auto
    operator= (const PropertyInfo&) -> PropertyInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
  };

  class LIBMM_GIO_SYMEXPORT InterfaceInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = InterfaceInfo;
    using BaseObjectType = GDBusInterfaceInfo;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusInterfaceInfo*;

    auto
    gobj () const -> const GDBusInterfaceInfo*;

    auto
    gobj_copy () const -> GDBusInterfaceInfo*;

    InterfaceInfo () = delete;

    InterfaceInfo (const InterfaceInfo&) = delete;
    auto
    operator= (const InterfaceInfo&) -> InterfaceInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    auto
    lookup_method (const Glib::ustring& name) -> Glib::RefPtr<MethodInfo>;

    auto
    lookup_method (const Glib::ustring& name) const
        -> Glib::RefPtr<const MethodInfo>;

    auto
    lookup_signal (const Glib::ustring& name) -> Glib::RefPtr<SignalInfo>;

    auto
    lookup_signal (const Glib::ustring& name) const
        -> Glib::RefPtr<const SignalInfo>;

    auto
    lookup_property (const Glib::ustring& name) -> Glib::RefPtr<PropertyInfo>;

    auto
    lookup_property (const Glib::ustring& name) const
        -> Glib::RefPtr<const PropertyInfo>;

    auto
    cache_build () -> void;

    auto
    cache_release () -> void;
  };

  class LIBMM_GIO_SYMEXPORT NodeInfo final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NodeInfo;
    using BaseObjectType = GDBusNodeInfo;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GDBusNodeInfo*;

    auto
    gobj () const -> const GDBusNodeInfo*;

    auto
    gobj_copy () const -> GDBusNodeInfo*;

    NodeInfo () = delete;

    NodeInfo (const NodeInfo&) = delete;
    auto
    operator= (const NodeInfo&) -> NodeInfo& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create_for_xml (const Glib::ustring& xml_data) -> Glib::RefPtr<NodeInfo>;

    auto
    lookup_interface (const Glib::ustring& name) -> Glib::RefPtr<InterfaceInfo>;

    auto
    lookup_interface (const Glib::ustring& name) const
        -> Glib::RefPtr<const InterfaceInfo>;

    auto
    lookup_interface () -> Glib::RefPtr<InterfaceInfo>;

    auto
    lookup_interface () const -> Glib::RefPtr<const InterfaceInfo>;
  };

} // namespace Gio::DBus

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusAnnotationInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::AnnotationInfo>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusArgInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ArgInfo>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusMethodInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::MethodInfo>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusSignalInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::SignalInfo>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusPropertyInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::PropertyInfo>;

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusInterfaceInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::InterfaceInfo>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GIO_SYMEXPORT Value<Glib::RefPtr<Gio::DBus::InterfaceInfo>>
    : public Glib::Value_RefPtrBoxed<Gio::DBus::InterfaceInfo>
  {
  public:
    auto
    get () const -> CppType
    {
      return Glib::wrap (static_cast<GDBusInterfaceInfo*> (get_boxed ()), true);
    }
  };
#endif

} // namespace Glib

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GDBusNodeInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::NodeInfo>;

} // namespace Glib

#endif
