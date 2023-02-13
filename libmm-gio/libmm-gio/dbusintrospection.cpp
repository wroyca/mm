


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/dbusintrospection.hpp>
#include <mm/gio/private/dbusintrospection_p.hpp>


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

#include <mm/glib/error.hpp>
#include <mm/glib/utility.hpp>

namespace Gio::DBus
{

// We hand-code this because g_dbus_node_info_lookup_interface() doesn't
// do this when it takes a nullptr.
// See bug https://bugzilla.gnome.org/show_bug.cgi?id=646417
auto
NodeInfo::lookup_interface() -> Glib::RefPtr<InterfaceInfo>
{
  Glib::RefPtr<InterfaceInfo> retvalue;

  if (!gobj() || !gobj()->interfaces)
    return retvalue;

  retvalue = Glib::wrap(gobj()->interfaces[0]);

  if (retvalue)
    retvalue->reference(); // The function does not do a ref for us.

  return retvalue;
}

auto
NodeInfo::lookup_interface() const -> Glib::RefPtr<const InterfaceInfo>
{
  return const_cast<NodeInfo*>(this)->lookup_interface();
}

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<AnnotationInfo*>(gobject) is needed:
 *
 * A AnnotationInfo instance is in fact always a GDBusAnnotationInfo instance.
 * Unfortunately, GDBusAnnotationInfo cannot be a member of AnnotationInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because AnnotationInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusAnnotationInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::AnnotationInfo>
{
  if(take_copy && object)
    g_dbus_annotation_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::AnnotationInfo>(reinterpret_cast<Gio::DBus::AnnotationInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto AnnotationInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_annotation_info_ref(reinterpret_cast<GDBusAnnotationInfo*>(const_cast<AnnotationInfo*>(this)));
}

auto AnnotationInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_annotation_info_unref(reinterpret_cast<GDBusAnnotationInfo*>(const_cast<AnnotationInfo*>(this)));
}

auto AnnotationInfo::gobj() -> GDBusAnnotationInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusAnnotationInfo*>(this);
}

auto AnnotationInfo::gobj() const -> const GDBusAnnotationInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusAnnotationInfo*>(this);
}

auto AnnotationInfo::gobj_copy() const -> GDBusAnnotationInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusAnnotationInfo*>(const_cast<AnnotationInfo*>(this));
  g_dbus_annotation_info_ref(gobject);
  return gobject;
}


auto AnnotationInfo::info_lookup(const std::vector<Glib::RefPtr<AnnotationInfo>>& annotations, const Glib::ustring& name) -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_dbus_annotation_info_lookup(Glib::ArrayHandler<Glib::RefPtr<AnnotationInfo>>::vector_to_array(annotations).data(), name.c_str()));
}


} // namespace Gio


/* Why reinterpret_cast<ArgInfo*>(gobject) is needed:
 *
 * A ArgInfo instance is in fact always a GDBusArgInfo instance.
 * Unfortunately, GDBusArgInfo cannot be a member of ArgInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ArgInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusArgInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::ArgInfo>
{
  if(take_copy && object)
    g_dbus_arg_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::ArgInfo>(reinterpret_cast<Gio::DBus::ArgInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto ArgInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_arg_info_ref(reinterpret_cast<GDBusArgInfo*>(const_cast<ArgInfo*>(this)));
}

auto ArgInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_arg_info_unref(reinterpret_cast<GDBusArgInfo*>(const_cast<ArgInfo*>(this)));
}

auto ArgInfo::gobj() -> GDBusArgInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusArgInfo*>(this);
}

auto ArgInfo::gobj() const -> const GDBusArgInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusArgInfo*>(this);
}

auto ArgInfo::gobj_copy() const -> GDBusArgInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusArgInfo*>(const_cast<ArgInfo*>(this));
  g_dbus_arg_info_ref(gobject);
  return gobject;
}


} // namespace Gio


/* Why reinterpret_cast<MethodInfo*>(gobject) is needed:
 *
 * A MethodInfo instance is in fact always a GDBusMethodInfo instance.
 * Unfortunately, GDBusMethodInfo cannot be a member of MethodInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because MethodInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusMethodInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::MethodInfo>
{
  if(take_copy && object)
    g_dbus_method_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::MethodInfo>(reinterpret_cast<Gio::DBus::MethodInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto MethodInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_method_info_ref(reinterpret_cast<GDBusMethodInfo*>(const_cast<MethodInfo*>(this)));
}

auto MethodInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_method_info_unref(reinterpret_cast<GDBusMethodInfo*>(const_cast<MethodInfo*>(this)));
}

auto MethodInfo::gobj() -> GDBusMethodInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusMethodInfo*>(this);
}

auto MethodInfo::gobj() const -> const GDBusMethodInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusMethodInfo*>(this);
}

auto MethodInfo::gobj_copy() const -> GDBusMethodInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusMethodInfo*>(const_cast<MethodInfo*>(this));
  g_dbus_method_info_ref(gobject);
  return gobject;
}


} // namespace Gio


/* Why reinterpret_cast<SignalInfo*>(gobject) is needed:
 *
 * A SignalInfo instance is in fact always a GDBusSignalInfo instance.
 * Unfortunately, GDBusSignalInfo cannot be a member of SignalInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because SignalInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusSignalInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::SignalInfo>
{
  if(take_copy && object)
    g_dbus_signal_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::SignalInfo>(reinterpret_cast<Gio::DBus::SignalInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto SignalInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_signal_info_ref(reinterpret_cast<GDBusSignalInfo*>(const_cast<SignalInfo*>(this)));
}

auto SignalInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_signal_info_unref(reinterpret_cast<GDBusSignalInfo*>(const_cast<SignalInfo*>(this)));
}

auto SignalInfo::gobj() -> GDBusSignalInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusSignalInfo*>(this);
}

auto SignalInfo::gobj() const -> const GDBusSignalInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusSignalInfo*>(this);
}

auto SignalInfo::gobj_copy() const -> GDBusSignalInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusSignalInfo*>(const_cast<SignalInfo*>(this));
  g_dbus_signal_info_ref(gobject);
  return gobject;
}


} // namespace Gio


/* Why reinterpret_cast<PropertyInfo*>(gobject) is needed:
 *
 * A PropertyInfo instance is in fact always a GDBusPropertyInfo instance.
 * Unfortunately, GDBusPropertyInfo cannot be a member of PropertyInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because PropertyInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusPropertyInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::PropertyInfo>
{
  if(take_copy && object)
    g_dbus_property_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::PropertyInfo>(reinterpret_cast<Gio::DBus::PropertyInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto PropertyInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_property_info_ref(reinterpret_cast<GDBusPropertyInfo*>(const_cast<PropertyInfo*>(this)));
}

auto PropertyInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_property_info_unref(reinterpret_cast<GDBusPropertyInfo*>(const_cast<PropertyInfo*>(this)));
}

auto PropertyInfo::gobj() -> GDBusPropertyInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusPropertyInfo*>(this);
}

auto PropertyInfo::gobj() const -> const GDBusPropertyInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusPropertyInfo*>(this);
}

auto PropertyInfo::gobj_copy() const -> GDBusPropertyInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusPropertyInfo*>(const_cast<PropertyInfo*>(this));
  g_dbus_property_info_ref(gobject);
  return gobject;
}


} // namespace Gio


/* Why reinterpret_cast<InterfaceInfo*>(gobject) is needed:
 *
 * A InterfaceInfo instance is in fact always a GDBusInterfaceInfo instance.
 * Unfortunately, GDBusInterfaceInfo cannot be a member of InterfaceInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because InterfaceInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusInterfaceInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::InterfaceInfo>
{
  if(take_copy && object)
    g_dbus_interface_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::InterfaceInfo>(reinterpret_cast<Gio::DBus::InterfaceInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

// static
auto InterfaceInfo::get_type() -> GType
{
  return g_dbus_interface_info_get_type();
}

auto InterfaceInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_interface_info_ref(reinterpret_cast<GDBusInterfaceInfo*>(const_cast<InterfaceInfo*>(this)));
}

auto InterfaceInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_interface_info_unref(reinterpret_cast<GDBusInterfaceInfo*>(const_cast<InterfaceInfo*>(this)));
}

auto InterfaceInfo::gobj() -> GDBusInterfaceInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusInterfaceInfo*>(this);
}

auto InterfaceInfo::gobj() const -> const GDBusInterfaceInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusInterfaceInfo*>(this);
}

auto InterfaceInfo::gobj_copy() const -> GDBusInterfaceInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusInterfaceInfo*>(const_cast<InterfaceInfo*>(this));
  g_dbus_interface_info_ref(gobject);
  return gobject;
}

auto InterfaceInfo::lookup_method(const Glib::ustring& name) -> Glib::RefPtr<MethodInfo>
{
  auto retvalue = Glib::wrap(g_dbus_interface_info_lookup_method(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto InterfaceInfo::lookup_method(const Glib::ustring& name) const -> Glib::RefPtr<const MethodInfo>
{
  return const_cast<InterfaceInfo*>(this)->lookup_method(name);
}

auto InterfaceInfo::lookup_signal(const Glib::ustring& name) -> Glib::RefPtr<SignalInfo>
{
  auto retvalue = Glib::wrap(g_dbus_interface_info_lookup_signal(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto InterfaceInfo::lookup_signal(const Glib::ustring& name) const -> Glib::RefPtr<const SignalInfo>
{
  return const_cast<InterfaceInfo*>(this)->lookup_signal(name);
}

auto InterfaceInfo::lookup_property(const Glib::ustring& name) -> Glib::RefPtr<PropertyInfo>
{
  auto retvalue = Glib::wrap(g_dbus_interface_info_lookup_property(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto InterfaceInfo::lookup_property(const Glib::ustring& name) const -> Glib::RefPtr<const PropertyInfo>
{
  return const_cast<InterfaceInfo*>(this)->lookup_property(name);
}

auto InterfaceInfo::cache_build () -> void
{
  g_dbus_interface_info_cache_build(gobj());
}

auto InterfaceInfo::cache_release () -> void
{
  g_dbus_interface_info_cache_release(gobj());
}


} // namespace Gio


/* Why reinterpret_cast<NodeInfo*>(gobject) is needed:
 *
 * A NodeInfo instance is in fact always a GDBusNodeInfo instance.
 * Unfortunately, GDBusNodeInfo cannot be a member of NodeInfo,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because NodeInfo does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GDBusNodeInfo* object, const bool take_copy) -> RefPtr<Gio::DBus::NodeInfo>
{
  if(take_copy && object)
    g_dbus_node_info_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gio::DBus::NodeInfo>(reinterpret_cast<Gio::DBus::NodeInfo*>(object));
}

} // namespace Glib


namespace Gio::DBus
{

auto NodeInfo::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_node_info_ref(reinterpret_cast<GDBusNodeInfo*>(const_cast<NodeInfo*>(this)));
}

auto NodeInfo::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_dbus_node_info_unref(reinterpret_cast<GDBusNodeInfo*>(const_cast<NodeInfo*>(this)));
}

auto NodeInfo::gobj() -> GDBusNodeInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GDBusNodeInfo*>(this);
}

auto NodeInfo::gobj() const -> const GDBusNodeInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GDBusNodeInfo*>(this);
}

auto NodeInfo::gobj_copy() const -> GDBusNodeInfo*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GDBusNodeInfo*>(const_cast<NodeInfo*>(this));
  g_dbus_node_info_ref(gobject);
  return gobject;
}

auto NodeInfo::create_for_xml(const Glib::ustring& xml_data) -> Glib::RefPtr<NodeInfo>
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_dbus_node_info_new_for_xml(xml_data.c_str(), &gerror));
  if(gerror)
    Glib::Error::throw_exception(gerror);
  return retvalue;
}

auto NodeInfo::lookup_interface(const Glib::ustring& name) -> Glib::RefPtr<InterfaceInfo>
{
  auto retvalue = Glib::wrap(g_dbus_node_info_lookup_interface(gobj(), name.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto NodeInfo::lookup_interface(const Glib::ustring& name) const -> Glib::RefPtr<const InterfaceInfo>
{
  return const_cast<NodeInfo*>(this)->lookup_interface(name);
}


} // namespace Gio


