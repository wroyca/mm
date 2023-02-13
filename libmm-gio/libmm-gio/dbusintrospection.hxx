
#ifndef _GIOMM_DBUSINTROSPECTION_H
#define _GIOMM_DBUSINTROSPECTION_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/refptr.hxx>
#include <libmm-glib/value.hxx>
#include <gio/gio.h>
#include <vector>


namespace Gio::DBus
{

/** @addtogroup giommEnums giomm Enums and Flags */

/**
 *  @var PropertyInfoFlags NONE
 * No flags set.
 *
 *  @var PropertyInfoFlags READABLE
 * Property is readable.
 *
 *  @var PropertyInfoFlags WRITABLE
 * Property is writable.
 *
 *  @enum PropertyInfoFlags
 *
 * Flags describing the access control of a D-Bus property.
 *
 * @newin{2,26}
 *
 * @ingroup giommEnums
 * @par Bitwise operators:
 * <tt>PropertyInfoFlags operator|(PropertyInfoFlags, PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags operator&(PropertyInfoFlags, PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags operator^(PropertyInfoFlags, PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags operator~(PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags& operator|=(PropertyInfoFlags&, PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags& operator&=(PropertyInfoFlags&, PropertyInfoFlags)</tt><br>
 * <tt>PropertyInfoFlags& operator^=(PropertyInfoFlags&, PropertyInfoFlags)</tt><br>
 */
enum class PropertyInfoFlags
{
  NONE = 0x0,
  READABLE = (1<<0),
  WRITABLE = (1<<1)
};

/** @ingroup giommEnums */
inline auto operator|(PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  { return static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  { return static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(PropertyInfoFlags lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags
  { return static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(PropertyInfoFlags flags) -> PropertyInfoFlags
  { return static_cast<PropertyInfoFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  { return (lhs = static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  { return (lhs = static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(PropertyInfoFlags& lhs, PropertyInfoFlags rhs) -> PropertyInfoFlags&
  { return (lhs = static_cast<PropertyInfoFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/** Stores information about an annotation.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API AnnotationInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = AnnotationInfo;
  using BaseObjectType = GDBusAnnotationInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusAnnotationInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusAnnotationInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusAnnotationInfo*;

  AnnotationInfo() = delete;

  // noncopyable
  AnnotationInfo(const AnnotationInfo&) = delete;
  auto operator=(const AnnotationInfo&) -> AnnotationInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::AnnotationInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


  /** Looks up the value of an annotation.
   *
   * The cost of this function is O(n) in number of annotations.
   *
   * @newin{2,26}
   *
   * @param annotations A <tt>nullptr</tt>-terminated array of annotations or <tt>nullptr</tt>.
   * @param name The name of the annotation to look up.
   * @return The value or <tt>nullptr</tt> if not found. Do not free, it is owned by @a annotations.
   */
  static auto info_lookup(const std::vector<Glib::RefPtr<AnnotationInfo>>& annotations, const Glib::ustring& name) -> Glib::ustring;


};

/** ArgInfo - Stores information about an argument for a method or a
 * signal.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API ArgInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ArgInfo;
  using BaseObjectType = GDBusArgInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusArgInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusArgInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusArgInfo*;

  ArgInfo() = delete;

  // noncopyable
  ArgInfo(const ArgInfo&) = delete;
  auto operator=(const ArgInfo&) -> ArgInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::ArgInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


};

/** Stores information about a method on an D-Bus interface.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API MethodInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = MethodInfo;
  using BaseObjectType = GDBusMethodInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusMethodInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusMethodInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusMethodInfo*;

  MethodInfo() = delete;

  // noncopyable
  MethodInfo(const MethodInfo&) = delete;
  auto operator=(const MethodInfo&) -> MethodInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::MethodInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


};

/** Stores information about a signal on a D-Bus interface.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API SignalInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SignalInfo;
  using BaseObjectType = GDBusSignalInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusSignalInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusSignalInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusSignalInfo*;

  SignalInfo() = delete;

  // noncopyable
  SignalInfo(const SignalInfo&) = delete;
  auto operator=(const SignalInfo&) -> SignalInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::SignalInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


};

/** Stores information about a property on a D-Bus interface.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API PropertyInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = PropertyInfo;
  using BaseObjectType = GDBusPropertyInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusPropertyInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusPropertyInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusPropertyInfo*;

  PropertyInfo() = delete;

  // noncopyable
  PropertyInfo(const PropertyInfo&) = delete;
  auto operator=(const PropertyInfo&) -> PropertyInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::PropertyInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:


};

/** Stores information about a D-Bus interface.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API InterfaceInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = InterfaceInfo;
  using BaseObjectType = GDBusInterfaceInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusInterfaceInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusInterfaceInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusInterfaceInfo*;

  InterfaceInfo() = delete;

  // noncopyable
  InterfaceInfo(const InterfaceInfo&) = delete;
  auto operator=(const InterfaceInfo&) -> InterfaceInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::InterfaceInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Looks up information about a method.
   *
   * The cost of this function is O(n) in number of methods unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus method name (typically in CamelCase).
   * @return A DBusMethodInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_method(const Glib::ustring& name) -> Glib::RefPtr<MethodInfo>;

  /** Looks up information about a method.
   *
   * The cost of this function is O(n) in number of methods unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus method name (typically in CamelCase).
   * @return A DBusMethodInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_method(const Glib::ustring& name) const -> Glib::RefPtr<const MethodInfo>;


  /** Looks up information about a signal.
   *
   * The cost of this function is O(n) in number of signals unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus signal name (typically in CamelCase).
   * @return A DBusSignalInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_signal(const Glib::ustring& name) -> Glib::RefPtr<SignalInfo>;

  /** Looks up information about a signal.
   *
   * The cost of this function is O(n) in number of signals unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus signal name (typically in CamelCase).
   * @return A DBusSignalInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_signal(const Glib::ustring& name) const -> Glib::RefPtr<const SignalInfo>;


  /** Looks up information about a property.
   *
   * The cost of this function is O(n) in number of properties unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus property name (typically in CamelCase).
   * @return A DBusPropertyInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_property(const Glib::ustring& name) -> Glib::RefPtr<PropertyInfo>;

  /** Looks up information about a property.
   *
   * The cost of this function is O(n) in number of properties unless
   * g_dbus_interface_info_cache_build() has been used on @a info.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus property name (typically in CamelCase).
   * @return A DBusPropertyInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_property(const Glib::ustring& name) const -> Glib::RefPtr<const PropertyInfo>;


  /** Builds a lookup-cache to speed up
   * g_dbus_interface_info_lookup_method(),
   * g_dbus_interface_info_lookup_signal() and
   * g_dbus_interface_info_lookup_property().
   *
   * If this has already been called with @a info, the existing cache is
   * used and its use count is increased.
   *
   * Note that @a info cannot be modified until
   * g_dbus_interface_info_cache_release() is called.
   *
   * @newin{2,44}
   */
  void cache_build();

  /** Decrements the usage count for the cache for @a info built by
   * g_dbus_interface_info_cache_build() (if any) and frees the
   * resources used by the cache if the usage count drops to zero.
   *
   * @newin{2,44}
   */
  void cache_release();

  //TODO: _WRAP_METHOD(void generate_xml(guint indent, GString* string_builder), g_dbus_interface_info_generate_xml)


};

/** NodeInfo - Stores information about nodes in a remote object
 * hierarchy.
 *
 * @newin{2,28}
 * @ingroup DBus
 */
class GIOMM_API NodeInfo final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = NodeInfo;
  using BaseObjectType = GDBusNodeInfo;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GDBusNodeInfo*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GDBusNodeInfo*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GDBusNodeInfo*;

  NodeInfo() = delete;

  // noncopyable
  NodeInfo(const NodeInfo&) = delete;
  auto operator=(const NodeInfo&) -> NodeInfo& = delete;

protected:
  // Do not derive this.  Gio::DBus::NodeInfo can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Parses @a xml_data and returns a DBusNodeInfo representing the data.
   *
   * The introspection XML must contain exactly one top-level
   * <node> element.
   *
   * Note that this routine is using a
   * [GMarkup][glib-Simple-XML-Subset-Parser.description]-based
   * parser that only accepts a subset of valid XML documents.
   *
   * @newin{2,26}
   *
   * @param xml_data Valid D-Bus introspection XML.
   * @return A DBusNodeInfo structure or <tt>nullptr</tt> if @a error is set. Free
   * with g_dbus_node_info_unref().
   *
   * @throws Glib::MarkupError
   */
  static auto create_for_xml(const Glib::ustring& xml_data) -> Glib::RefPtr<NodeInfo>;


  /** Looks up information about an interface.
   *
   * The cost of this function is O(n) in number of interfaces.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus interface name.
   * @return A Gio::DBus::InterfaceInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_interface(const Glib::ustring& name) -> Glib::RefPtr<InterfaceInfo>;

  /** Looks up information about an interface.
   *
   * The cost of this function is O(n) in number of interfaces.
   *
   * @newin{2,26}
   *
   * @param name A D-Bus interface name.
   * @return A Gio::DBus::InterfaceInfo or <tt>nullptr</tt> if not found. Do not free, it is owned by @a info.
   */
  auto lookup_interface(const Glib::ustring& name) const -> Glib::RefPtr<const InterfaceInfo>;

  /** Looks up information about the first interface.
   */
  auto lookup_interface() -> Glib::RefPtr<InterfaceInfo>;

  /** Looks up information about the first interface.
   */
  auto lookup_interface() const -> Glib::RefPtr<const InterfaceInfo>;

  //TODO: _WRAP_METHOD(void generate_xml(guint indent, GString* string_builder), g_dbus_node_info_generate_xml)


};

} // namespace Gio


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::AnnotationInfo
 */
GIOMM_API
auto wrap(GDBusAnnotationInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::AnnotationInfo>;

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::ArgInfo
 */
GIOMM_API
auto wrap(GDBusArgInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::ArgInfo>;

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::MethodInfo
 */
GIOMM_API
auto wrap(GDBusMethodInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::MethodInfo>;

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::SignalInfo
 */
GIOMM_API
auto wrap(GDBusSignalInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::SignalInfo>;

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::PropertyInfo
 */
GIOMM_API
auto wrap(GDBusPropertyInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::PropertyInfo>;

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::InterfaceInfo
 */
GIOMM_API
auto wrap(GDBusInterfaceInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::InterfaceInfo>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GIOMM_API Value<Glib::RefPtr<Gio::DBus::InterfaceInfo>> : public Glib::Value_RefPtrBoxed<Gio::DBus::InterfaceInfo>
{
public:
  auto get() const -> CppType { return Glib::wrap(static_cast<GDBusInterfaceInfo*>(get_boxed()), true); }
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::DBus::NodeInfo
 */
GIOMM_API
auto wrap(GDBusNodeInfo* object, bool take_copy = false) -> Glib::RefPtr<Gio::DBus::NodeInfo>;

} // namespace Glib


#endif /* _GIOMM_DBUSINTROSPECTION_H */

