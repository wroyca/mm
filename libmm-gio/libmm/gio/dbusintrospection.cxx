// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusintrospection_p.hxx>

#include <libmm/glib/error.hxx>
#include <libmm/glib/utility.hxx>

namespace gio::DBus
{

  auto
  NodeInfo::lookup_interface () -> glib::RefPtr<InterfaceInfo>
  {
    glib::RefPtr<InterfaceInfo> retvalue;

    if (!gobj () || !gobj ()->interfaces)
      return retvalue;

    retvalue = glib::wrap (gobj ()->interfaces[0]);

    if (retvalue)
      retvalue->reference ();

    return retvalue;
  }

  auto
  NodeInfo::lookup_interface () const -> glib::RefPtr<const InterfaceInfo>
  {
    return const_cast<NodeInfo*> (this)->lookup_interface ();
  }

} // namespace gio::DBus

namespace
{
}

namespace glib
{

  auto
  wrap (GDBusAnnotationInfo* object, const bool take_copy) -> RefPtr<gio::DBus::AnnotationInfo>
  {
    if (take_copy && object)
      g_dbus_annotation_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::AnnotationInfo> (
        reinterpret_cast<gio::DBus::AnnotationInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  AnnotationInfo::reference () const -> void
  {
    g_dbus_annotation_info_ref (reinterpret_cast<GDBusAnnotationInfo*> (
        const_cast<AnnotationInfo*> (this)));
  }

  auto
  AnnotationInfo::unreference () const -> void
  {
    g_dbus_annotation_info_unref (reinterpret_cast<GDBusAnnotationInfo*> (
        const_cast<AnnotationInfo*> (this)));
  }

  auto
  AnnotationInfo::gobj () -> GDBusAnnotationInfo*
  {
    return reinterpret_cast<GDBusAnnotationInfo*> (this);
  }

  auto
  AnnotationInfo::gobj () const -> const GDBusAnnotationInfo*
  {
    return reinterpret_cast<const GDBusAnnotationInfo*> (this);
  }

  auto
  AnnotationInfo::gobj_copy () const -> GDBusAnnotationInfo*
  {
    const auto gobject = reinterpret_cast<GDBusAnnotationInfo*> (
        const_cast<AnnotationInfo*> (this));
    g_dbus_annotation_info_ref (gobject);
    return gobject;
  }

  auto
  AnnotationInfo::info_lookup (
      const std::vector<glib::RefPtr<AnnotationInfo>>& annotations,
      const glib::ustring& name) -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        g_dbus_annotation_info_lookup (
            glib::ArrayHandler<glib::RefPtr<AnnotationInfo>>::vector_to_array (
                annotations)
                .data (),
            name.c_str ()));
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusArgInfo* object, const bool take_copy) -> RefPtr<gio::DBus::ArgInfo>
  {
    if (take_copy && object)
      g_dbus_arg_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::ArgInfo> (
        reinterpret_cast<gio::DBus::ArgInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  ArgInfo::reference () const -> void
  {
    g_dbus_arg_info_ref (
        reinterpret_cast<GDBusArgInfo*> (const_cast<ArgInfo*> (this)));
  }

  auto
  ArgInfo::unreference () const -> void
  {
    g_dbus_arg_info_unref (
        reinterpret_cast<GDBusArgInfo*> (const_cast<ArgInfo*> (this)));
  }

  auto
  ArgInfo::gobj () -> GDBusArgInfo*
  {
    return reinterpret_cast<GDBusArgInfo*> (this);
  }

  auto
  ArgInfo::gobj () const -> const GDBusArgInfo*
  {
    return reinterpret_cast<const GDBusArgInfo*> (this);
  }

  auto
  ArgInfo::gobj_copy () const -> GDBusArgInfo*
  {
    const auto gobject =
        reinterpret_cast<GDBusArgInfo*> (const_cast<ArgInfo*> (this));
    g_dbus_arg_info_ref (gobject);
    return gobject;
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusMethodInfo* object, const bool take_copy) -> RefPtr<gio::DBus::MethodInfo>
  {
    if (take_copy && object)
      g_dbus_method_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::MethodInfo> (
        reinterpret_cast<gio::DBus::MethodInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  MethodInfo::reference () const -> void
  {
    g_dbus_method_info_ref (
        reinterpret_cast<GDBusMethodInfo*> (const_cast<MethodInfo*> (this)));
  }

  auto
  MethodInfo::unreference () const -> void
  {
    g_dbus_method_info_unref (
        reinterpret_cast<GDBusMethodInfo*> (const_cast<MethodInfo*> (this)));
  }

  auto
  MethodInfo::gobj () -> GDBusMethodInfo*
  {
    return reinterpret_cast<GDBusMethodInfo*> (this);
  }

  auto
  MethodInfo::gobj () const -> const GDBusMethodInfo*
  {
    return reinterpret_cast<const GDBusMethodInfo*> (this);
  }

  auto
  MethodInfo::gobj_copy () const -> GDBusMethodInfo*
  {
    const auto gobject =
        reinterpret_cast<GDBusMethodInfo*> (const_cast<MethodInfo*> (this));
    g_dbus_method_info_ref (gobject);
    return gobject;
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusSignalInfo* object, const bool take_copy) -> RefPtr<gio::DBus::SignalInfo>
  {
    if (take_copy && object)
      g_dbus_signal_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::SignalInfo> (
        reinterpret_cast<gio::DBus::SignalInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  SignalInfo::reference () const -> void
  {
    g_dbus_signal_info_ref (
        reinterpret_cast<GDBusSignalInfo*> (const_cast<SignalInfo*> (this)));
  }

  auto
  SignalInfo::unreference () const -> void
  {
    g_dbus_signal_info_unref (
        reinterpret_cast<GDBusSignalInfo*> (const_cast<SignalInfo*> (this)));
  }

  auto
  SignalInfo::gobj () -> GDBusSignalInfo*
  {
    return reinterpret_cast<GDBusSignalInfo*> (this);
  }

  auto
  SignalInfo::gobj () const -> const GDBusSignalInfo*
  {
    return reinterpret_cast<const GDBusSignalInfo*> (this);
  }

  auto
  SignalInfo::gobj_copy () const -> GDBusSignalInfo*
  {
    const auto gobject =
        reinterpret_cast<GDBusSignalInfo*> (const_cast<SignalInfo*> (this));
    g_dbus_signal_info_ref (gobject);
    return gobject;
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusPropertyInfo* object, const bool take_copy) -> RefPtr<gio::DBus::PropertyInfo>
  {
    if (take_copy && object)
      g_dbus_property_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::PropertyInfo> (
        reinterpret_cast<gio::DBus::PropertyInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  PropertyInfo::reference () const -> void
  {
    g_dbus_property_info_ref (reinterpret_cast<GDBusPropertyInfo*> (
        const_cast<PropertyInfo*> (this)));
  }

  auto
  PropertyInfo::unreference () const -> void
  {
    g_dbus_property_info_unref (reinterpret_cast<GDBusPropertyInfo*> (
        const_cast<PropertyInfo*> (this)));
  }

  auto
  PropertyInfo::gobj () -> GDBusPropertyInfo*
  {
    return reinterpret_cast<GDBusPropertyInfo*> (this);
  }

  auto
  PropertyInfo::gobj () const -> const GDBusPropertyInfo*
  {
    return reinterpret_cast<const GDBusPropertyInfo*> (this);
  }

  auto
  PropertyInfo::gobj_copy () const -> GDBusPropertyInfo*
  {
    const auto gobject =
        reinterpret_cast<GDBusPropertyInfo*> (const_cast<PropertyInfo*> (this));
    g_dbus_property_info_ref (gobject);
    return gobject;
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusInterfaceInfo* object, const bool take_copy) -> RefPtr<gio::DBus::InterfaceInfo>
  {
    if (take_copy && object)
      g_dbus_interface_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::InterfaceInfo> (
        reinterpret_cast<gio::DBus::InterfaceInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  InterfaceInfo::get_type () -> GType
  {
    return g_dbus_interface_info_get_type ();
  }

  auto
  InterfaceInfo::reference () const -> void
  {
    g_dbus_interface_info_ref (reinterpret_cast<GDBusInterfaceInfo*> (
        const_cast<InterfaceInfo*> (this)));
  }

  auto
  InterfaceInfo::unreference () const -> void
  {
    g_dbus_interface_info_unref (reinterpret_cast<GDBusInterfaceInfo*> (
        const_cast<InterfaceInfo*> (this)));
  }

  auto
  InterfaceInfo::gobj () -> GDBusInterfaceInfo*
  {
    return reinterpret_cast<GDBusInterfaceInfo*> (this);
  }

  auto
  InterfaceInfo::gobj () const -> const GDBusInterfaceInfo*
  {
    return reinterpret_cast<const GDBusInterfaceInfo*> (this);
  }

  auto
  InterfaceInfo::gobj_copy () const -> GDBusInterfaceInfo*
  {
    const auto gobject = reinterpret_cast<GDBusInterfaceInfo*> (
        const_cast<InterfaceInfo*> (this));
    g_dbus_interface_info_ref (gobject);
    return gobject;
  }

  auto
  InterfaceInfo::lookup_method (const glib::ustring& name) -> glib::RefPtr<MethodInfo>
  {
    auto retvalue = glib::wrap (
        g_dbus_interface_info_lookup_method (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  InterfaceInfo::lookup_method (const glib::ustring& name) const -> glib::RefPtr<const MethodInfo>
  {
    return const_cast<InterfaceInfo*> (this)->lookup_method (name);
  }

  auto
  InterfaceInfo::lookup_signal (const glib::ustring& name) -> glib::RefPtr<SignalInfo>
  {
    auto retvalue = glib::wrap (
        g_dbus_interface_info_lookup_signal (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  InterfaceInfo::lookup_signal (const glib::ustring& name) const -> glib::RefPtr<const SignalInfo>
  {
    return const_cast<InterfaceInfo*> (this)->lookup_signal (name);
  }

  auto
  InterfaceInfo::lookup_property (const glib::ustring& name) -> glib::RefPtr<PropertyInfo>
  {
    auto retvalue = glib::wrap (
        g_dbus_interface_info_lookup_property (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  InterfaceInfo::lookup_property (const glib::ustring& name) const -> glib::RefPtr<const PropertyInfo>
  {
    return const_cast<InterfaceInfo*> (this)->lookup_property (name);
  }

  auto
  InterfaceInfo::cache_build () -> void
  {
    g_dbus_interface_info_cache_build (gobj ());
  }

  auto
  InterfaceInfo::cache_release () -> void
  {
    g_dbus_interface_info_cache_release (gobj ());
  }

} // namespace gio::DBus

namespace glib
{

  auto
  wrap (GDBusNodeInfo* object, const bool take_copy) -> RefPtr<gio::DBus::NodeInfo>
  {
    if (take_copy && object)
      g_dbus_node_info_ref (object);

    return glib::make_refptr_for_instance<gio::DBus::NodeInfo> (
        reinterpret_cast<gio::DBus::NodeInfo*> (object));
  }

} // namespace glib

namespace gio::DBus
{

  auto
  NodeInfo::reference () const -> void
  {
    g_dbus_node_info_ref (
        reinterpret_cast<GDBusNodeInfo*> (const_cast<NodeInfo*> (this)));
  }

  auto
  NodeInfo::unreference () const -> void
  {
    g_dbus_node_info_unref (
        reinterpret_cast<GDBusNodeInfo*> (const_cast<NodeInfo*> (this)));
  }

  auto
  NodeInfo::gobj () -> GDBusNodeInfo*
  {
    return reinterpret_cast<GDBusNodeInfo*> (this);
  }

  auto
  NodeInfo::gobj () const -> const GDBusNodeInfo*
  {
    return reinterpret_cast<const GDBusNodeInfo*> (this);
  }

  auto
  NodeInfo::gobj_copy () const -> GDBusNodeInfo*
  {
    const auto gobject =
        reinterpret_cast<GDBusNodeInfo*> (const_cast<NodeInfo*> (this));
    g_dbus_node_info_ref (gobject);
    return gobject;
  }

  auto
  NodeInfo::create_for_xml (const glib::ustring& xml_data) -> glib::RefPtr<NodeInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_dbus_node_info_new_for_xml (xml_data.c_str (), &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  NodeInfo::lookup_interface (const glib::ustring& name) -> glib::RefPtr<InterfaceInfo>
  {
    auto retvalue =
        glib::wrap (g_dbus_node_info_lookup_interface (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  NodeInfo::lookup_interface (const glib::ustring& name) const -> glib::RefPtr<const InterfaceInfo>
  {
    return const_cast<NodeInfo*> (this)->lookup_interface (name);
  }

} // namespace gio::DBus
