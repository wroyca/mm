// SPDX-License-Identifier: LGPL-2.1-or-later

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm/gio/wrap_init.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/glib/object.hxx>

#include <libmm/gio/action.hxx>
#include <libmm/gio/actiongroup.hxx>
#include <libmm/gio/actionmap.hxx>
#include <libmm/gio/appinfo.hxx>
#include <libmm/gio/appinfomonitor.hxx>
#include <libmm/gio/applaunchcontext.hxx>
#include <libmm/gio/application.hxx>
#include <libmm/gio/applicationcommandline.hxx>
#include <libmm/gio/asyncinitable.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/bufferedinputstream.hxx>
#include <libmm/gio/bufferedoutputstream.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/gio/charsetconverter.hxx>
#include <libmm/gio/converter.hxx>
#include <libmm/gio/converterinputstream.hxx>
#include <libmm/gio/converteroutputstream.hxx>
#include <libmm/gio/credentials.hxx>
#include <libmm/gio/datainputstream.hxx>
#include <libmm/gio/dataoutputstream.hxx>
#include <libmm/gio/dbusactiongroup.hxx>
#include <libmm/gio/dbusaddress.hxx>
#include <libmm/gio/dbusauthobserver.hxx>
#include <libmm/gio/dbusconnection.hxx>
#include <libmm/gio/dbuserror.hxx>
#include <libmm/gio/dbuserrorutils.hxx>
#include <libmm/gio/dbusinterface.hxx>
#include <libmm/gio/dbusinterfaceskeleton.hxx>
#include <libmm/gio/dbusinterfacevtable.hxx>
#include <libmm/gio/dbusintrospection.hxx>
#include <libmm/gio/dbusmenumodel.hxx>
#include <libmm/gio/dbusmessage.hxx>
#include <libmm/gio/dbusmethodinvocation.hxx>
#include <libmm/gio/dbusobject.hxx>
#include <libmm/gio/dbusobjectmanager.hxx>
#include <libmm/gio/dbusobjectmanagerclient.hxx>
#include <libmm/gio/dbusobjectmanagerserver.hxx>
#include <libmm/gio/dbusobjectproxy.hxx>
#include <libmm/gio/dbusobjectskeleton.hxx>
#include <libmm/gio/dbusownname.hxx>
#include <libmm/gio/dbusproxy.hxx>
#include <libmm/gio/dbusserver.hxx>
#include <libmm/gio/dbussubtreevtable.hxx>
#include <libmm/gio/dbusutils.hxx>
#include <libmm/gio/dbuswatchname.hxx>
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <libmm/gio/desktopappinfo.hxx>
#endif
#include <libmm/gio/drive.hxx>
#include <libmm/gio/emblem.hxx>
#include <libmm/gio/emblemedicon.hxx>
#include <libmm/gio/enums.hxx>
#include <libmm/gio/error.hxx>
#include <libmm/gio/file.hxx>
#include <libmm/gio/fileattributeinfo.hxx>
#include <libmm/gio/fileattributeinfolist.hxx>
#ifndef G_OS_WIN32
  #include <libmm/gio/filedescriptorbased.hxx>
#endif
#include <libmm/gio/fileenumerator.hxx>
#include <libmm/gio/fileicon.hxx>
#include <libmm/gio/fileinfo.hxx>
#include <libmm/gio/fileinputstream.hxx>
#include <libmm/gio/fileiostream.hxx>
#include <libmm/gio/filemonitor.hxx>
#include <libmm/gio/filenamecompleter.hxx>
#include <libmm/gio/fileoutputstream.hxx>
#include <libmm/gio/filterinputstream.hxx>
#include <libmm/gio/filteroutputstream.hxx>
#include <libmm/gio/icon.hxx>
#include <libmm/gio/inetaddress.hxx>
#include <libmm/gio/inetsocketaddress.hxx>
#include <libmm/gio/initable.hxx>
#include <libmm/gio/inputstream.hxx>
#include <libmm/gio/iostream.hxx>
#include <libmm/gio/listmodel.hxx>
#include <libmm/gio/liststore.hxx>
#include <libmm/gio/loadableicon.hxx>
#include <libmm/gio/memoryinputstream.hxx>
#include <libmm/gio/memoryoutputstream.hxx>
#include <libmm/gio/menu.hxx>
#include <libmm/gio/menuattributeiter.hxx>
#include <libmm/gio/menuitem.hxx>
#include <libmm/gio/menulinkiter.hxx>
#include <libmm/gio/menumodel.hxx>
#include <libmm/gio/mount.hxx>
#include <libmm/gio/mountoperation.hxx>
#include <libmm/gio/networkaddress.hxx>
#include <libmm/gio/networkmonitor.hxx>
#include <libmm/gio/networkservice.hxx>
#include <libmm/gio/notification.hxx>
#include <libmm/gio/outputstream.hxx>
#include <libmm/gio/permission.hxx>
#include <libmm/gio/pollableinputstream.hxx>
#include <libmm/gio/pollableoutputstream.hxx>
#include <libmm/gio/propertyaction.hxx>
#include <libmm/gio/proxy.hxx>
#include <libmm/gio/proxyaddress.hxx>
#include <libmm/gio/proxyresolver.hxx>
#include <libmm/gio/remoteactiongroup.hxx>
#include <libmm/gio/resolver.hxx>
#include <libmm/gio/resource.hxx>
#include <libmm/gio/seekable.hxx>
#include <libmm/gio/settings.hxx>
#include <libmm/gio/settingsschema.hxx>
#include <libmm/gio/settingsschemakey.hxx>
#include <libmm/gio/settingsschemasource.hxx>
#include <libmm/gio/simpleaction.hxx>
#include <libmm/gio/simpleactiongroup.hxx>
#include <libmm/gio/simpleiostream.hxx>
#include <libmm/gio/simplepermission.hxx>
#include <libmm/gio/socket.hxx>
#include <libmm/gio/socketaddress.hxx>
#include <libmm/gio/socketaddressenumerator.hxx>
#include <libmm/gio/socketclient.hxx>
#include <libmm/gio/socketconnectable.hxx>
#include <libmm/gio/socketconnection.hxx>
#include <libmm/gio/socketcontrolmessage.hxx>
#include <libmm/gio/socketlistener.hxx>
#include <libmm/gio/socketservice.hxx>
#include <libmm/gio/srvtarget.hxx>
#include <libmm/gio/tcpconnection.hxx>
#include <libmm/gio/tcpwrapperconnection.hxx>
#include <libmm/gio/themedicon.hxx>
#include <libmm/gio/threadedsocketservice.hxx>
#include <libmm/gio/tlscertificate.hxx>
#include <libmm/gio/tlsclientconnection.hxx>
#include <libmm/gio/tlsconnection.hxx>
#include <libmm/gio/tlsdatabase.hxx>
#include <libmm/gio/tlsinteraction.hxx>
#include <libmm/gio/tlspassword.hxx>
#include <libmm/gio/tlsserverconnection.hxx>
#ifndef G_OS_WIN32
  #include <libmm/gio/unixconnection.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixcredentialsmessage.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixfdlist.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixfdmessage.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixinputstream.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixoutputstream.hxx>
#endif
#ifndef G_OS_WIN32
  #include <libmm/gio/unixsocketaddress.hxx>
#endif
#include <libmm/gio/volume.hxx>
#include <libmm/gio/volumemonitor.hxx>
#include <libmm/gio/zlibcompressor.hxx>
#include <libmm/gio/zlibdecompressor.hxx>

#ifndef G_OS_WIN32

extern "C"
{
  auto
  g_app_info_monitor_get_type (void) -> GType;
  auto
  g_app_launch_context_get_type (void) -> GType;
  auto
  g_application_get_type (void) -> GType;
  auto
  g_application_command_line_get_type (void) -> GType;
  auto
  g_buffered_input_stream_get_type (void) -> GType;
  auto
  g_buffered_output_stream_get_type (void) -> GType;
  auto
  g_cancellable_get_type (void) -> GType;
  auto
  g_charset_converter_get_type (void) -> GType;
  auto
  g_converter_input_stream_get_type (void) -> GType;
  auto
  g_converter_output_stream_get_type (void) -> GType;
  auto
  g_credentials_get_type (void) -> GType;
  auto
  g_data_input_stream_get_type (void) -> GType;
  auto
  g_data_output_stream_get_type (void) -> GType;
  auto
  g_dbus_action_group_get_type (void) -> GType;
  auto
  g_dbus_auth_observer_get_type (void) -> GType;
  auto
  g_dbus_connection_get_type (void) -> GType;
  auto
  g_dbus_interface_skeleton_get_type (void) -> GType;
  auto
  g_dbus_menu_model_get_type (void) -> GType;
  auto
  g_dbus_message_get_type (void) -> GType;
  auto
  g_dbus_method_invocation_get_type (void) -> GType;
  auto
  g_dbus_object_manager_client_get_type (void) -> GType;
  auto
  g_dbus_object_manager_server_get_type (void) -> GType;
  auto
  g_dbus_object_proxy_get_type (void) -> GType;
  auto
  g_dbus_object_skeleton_get_type (void) -> GType;
  auto
  g_dbus_proxy_get_type (void) -> GType;
  auto
  g_dbus_server_get_type (void) -> GType;
  #if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  auto
  g_desktop_app_info_get_type (void) -> GType;
  #endif
  auto
  g_emblem_get_type (void) -> GType;
  auto
  g_emblemed_icon_get_type (void) -> GType;
  auto
  g_file_enumerator_get_type (void) -> GType;
  auto
  g_file_icon_get_type (void) -> GType;
  auto
  g_file_info_get_type (void) -> GType;
  auto
  g_file_input_stream_get_type (void) -> GType;
  auto
  g_file_io_stream_get_type (void) -> GType;
  auto
  g_file_monitor_get_type (void) -> GType;
  auto
  g_filename_completer_get_type (void) -> GType;
  auto
  g_file_output_stream_get_type (void) -> GType;
  auto
  g_filter_input_stream_get_type (void) -> GType;
  auto
  g_filter_output_stream_get_type (void) -> GType;
  auto
  g_inet_address_get_type (void) -> GType;
  auto
  g_inet_socket_address_get_type (void) -> GType;
  auto
  g_input_stream_get_type (void) -> GType;
  auto
  g_io_stream_get_type (void) -> GType;
  auto
  g_list_store_get_type (void) -> GType;
  auto
  g_memory_input_stream_get_type (void) -> GType;
  auto
  g_memory_output_stream_get_type (void) -> GType;
  auto
  g_menu_get_type (void) -> GType;
  auto
  g_menu_attribute_iter_get_type (void) -> GType;
  auto
  g_menu_item_get_type (void) -> GType;
  auto
  g_menu_link_iter_get_type (void) -> GType;
  auto
  g_menu_model_get_type (void) -> GType;
  auto
  g_mount_operation_get_type (void) -> GType;
  auto
  g_network_address_get_type (void) -> GType;
  auto
  g_network_service_get_type (void) -> GType;
  auto
  g_notification_get_type (void) -> GType;
  auto
  g_output_stream_get_type (void) -> GType;
  auto
  g_permission_get_type (void) -> GType;
  auto
  g_property_action_get_type (void) -> GType;
  auto
  g_proxy_address_get_type (void) -> GType;
  auto
  g_resolver_get_type (void) -> GType;
  auto
  g_settings_get_type (void) -> GType;
  auto
  g_simple_action_get_type (void) -> GType;
  auto
  g_simple_action_group_get_type (void) -> GType;
  auto
  g_simple_io_stream_get_type (void) -> GType;
  auto
  g_simple_permission_get_type (void) -> GType;
  auto
  g_socket_get_type (void) -> GType;
  auto
  g_socket_address_get_type (void) -> GType;
  auto
  g_socket_address_enumerator_get_type (void) -> GType;
  auto
  g_socket_client_get_type (void) -> GType;
  auto
  g_socket_connection_get_type (void) -> GType;
  auto
  g_socket_control_message_get_type (void) -> GType;
  auto
  g_socket_listener_get_type (void) -> GType;
  auto
  g_socket_service_get_type (void) -> GType;
  auto
  g_tcp_connection_get_type (void) -> GType;
  auto
  g_tcp_wrapper_connection_get_type (void) -> GType;
  auto
  g_themed_icon_get_type (void) -> GType;
  auto
  g_threaded_socket_service_get_type (void) -> GType;
  auto
  g_tls_certificate_get_type (void) -> GType;
  auto
  g_tls_connection_get_type (void) -> GType;
  auto
  g_tls_database_get_type (void) -> GType;
  auto
  g_tls_interaction_get_type (void) -> GType;
  auto
  g_tls_password_get_type (void) -> GType;
  #ifndef G_OS_WIN32
  auto
  g_unix_connection_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_credentials_message_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_fd_list_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_fd_message_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_input_stream_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_output_stream_get_type (void) -> GType;
  #endif
  #ifndef G_OS_WIN32
  auto
  g_unix_socket_address_get_type (void) -> GType;
  #endif
  auto
  g_volume_monitor_get_type (void) -> GType;
  auto
  g_zlib_compressor_get_type (void) -> GType;
  auto
  g_zlib_decompressor_get_type (void) -> GType;

  auto
  g_dbus_error_quark (void) -> GQuark;
  auto
  g_io_error_quark (void) -> GQuark;
  auto
  g_resolver_error_quark (void) -> GQuark;
  auto
  g_tls_error_quark (void) -> GQuark;
  auto
  g_resource_error_quark (void) -> GQuark;
}

#endif

namespace gio
{

  class AppInfoMonitor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class AppLaunchContext_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Application_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ApplicationCommandLine_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BufferedInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class BufferedOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Cancellable_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class CharsetConverter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ConverterInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ConverterOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Credentials_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DataInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class DataOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  namespace DBus
  {
    class ActionGroup_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class AuthObserver_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class Connection_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class InterfaceSkeleton_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class MenuModel_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class Message_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class MethodInvocation_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class ObjectManagerClient_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class ObjectManagerServer_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class ObjectProxy_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class ObjectSkeleton_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class Proxy_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

  namespace DBus
  {
    class Server_Class
    {
    public:
      static auto
      wrap_new (GObject*) -> glib::ObjectBase*;
    };
  } // namespace DBus

#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  class DesktopAppInfo_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif

  class Emblem_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class EmblemedIcon_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileEnumerator_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileIcon_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileInfo_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileIOStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileMonitor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FilenameCompleter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FileOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FilterInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class FilterOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class InetAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class InetSocketAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class InputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class IOStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ListStoreBase_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MemoryInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MemoryOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Menu_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MenuAttributeIter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MenuItem_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MenuLinkIter_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MenuModel_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class MountOperation_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NetworkAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class NetworkService_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Notification_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class OutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Permission_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class PropertyAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ProxyAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Resolver_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Settings_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SimpleAction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SimpleActionGroup_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SimpleIOStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SimplePermission_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class Socket_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketAddressEnumerator_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketClient_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketConnection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketControlMessage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketListener_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class SocketService_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TcpConnection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TcpWrapperConnection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ThemedIcon_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ThreadedSocketService_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TlsCertificate_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TlsConnection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TlsDatabase_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TlsInteraction_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class TlsPassword_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#ifndef G_OS_WIN32
  class UnixConnection_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixCredentialsMessage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixFDList_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixFDMessage_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixInputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixOutputStream_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
#ifndef G_OS_WIN32
  class UnixSocketAddress_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };
#endif
  class VolumeMonitor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ZlibCompressor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  class ZlibDecompressor_Class
  {
  public:
    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;
  };

  namespace DBus
  {

    auto
    wrap_init () -> void
    {
      glib::Error::register_domain (g_dbus_error_quark (), &Error::throw_func);
    }

  } // namespace DBus

  auto
  wrap_init () -> void
  {
    glib::Error::register_domain (g_io_error_quark (), &Error::throw_func);
    glib::Error::register_domain (g_resolver_error_quark (),
                                  &ResolverError::throw_func);
    glib::Error::register_domain (g_tls_error_quark (), &TlsError::throw_func);
    glib::Error::register_domain (g_resource_error_quark (),
                                  &ResourceError::throw_func);

    DBus::wrap_init ();

    wrap_register (g_app_info_monitor_get_type (),
                   &AppInfoMonitor_Class::wrap_new);
    wrap_register (g_app_launch_context_get_type (),
                   &AppLaunchContext_Class::wrap_new);
    wrap_register (g_application_get_type (), &Application_Class::wrap_new);
    wrap_register (g_application_command_line_get_type (),
                   &ApplicationCommandLine_Class::wrap_new);
    wrap_register (g_buffered_input_stream_get_type (),
                   &BufferedInputStream_Class::wrap_new);
    wrap_register (g_buffered_output_stream_get_type (),
                   &BufferedOutputStream_Class::wrap_new);
    wrap_register (g_cancellable_get_type (), &Cancellable_Class::wrap_new);
    wrap_register (g_charset_converter_get_type (),
                   &CharsetConverter_Class::wrap_new);
    wrap_register (g_converter_input_stream_get_type (),
                   &ConverterInputStream_Class::wrap_new);
    wrap_register (g_converter_output_stream_get_type (),
                   &ConverterOutputStream_Class::wrap_new);
    wrap_register (g_credentials_get_type (), &Credentials_Class::wrap_new);
    wrap_register (g_data_input_stream_get_type (),
                   &DataInputStream_Class::wrap_new);
    wrap_register (g_data_output_stream_get_type (),
                   &DataOutputStream_Class::wrap_new);
    wrap_register (g_dbus_action_group_get_type (),
                   &DBus::ActionGroup_Class::wrap_new);
    wrap_register (g_dbus_auth_observer_get_type (),
                   &DBus::AuthObserver_Class::wrap_new);
    wrap_register (g_dbus_connection_get_type (),
                   &DBus::Connection_Class::wrap_new);
    wrap_register (g_dbus_interface_skeleton_get_type (),
                   &DBus::InterfaceSkeleton_Class::wrap_new);
    wrap_register (g_dbus_menu_model_get_type (),
                   &DBus::MenuModel_Class::wrap_new);
    wrap_register (g_dbus_message_get_type (), &DBus::Message_Class::wrap_new);
    wrap_register (g_dbus_method_invocation_get_type (),
                   &DBus::MethodInvocation_Class::wrap_new);
    wrap_register (g_dbus_object_manager_client_get_type (),
                   &DBus::ObjectManagerClient_Class::wrap_new);
    wrap_register (g_dbus_object_manager_server_get_type (),
                   &DBus::ObjectManagerServer_Class::wrap_new);
    wrap_register (g_dbus_object_proxy_get_type (),
                   &DBus::ObjectProxy_Class::wrap_new);
    wrap_register (g_dbus_object_skeleton_get_type (),
                   &DBus::ObjectSkeleton_Class::wrap_new);
    wrap_register (g_dbus_proxy_get_type (), &DBus::Proxy_Class::wrap_new);
    wrap_register (g_dbus_server_get_type (), &DBus::Server_Class::wrap_new);
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
    glib::wrap_register (g_desktop_app_info_get_type (),
                         &DesktopAppInfo_Class::wrap_new);
#endif
    wrap_register (g_emblem_get_type (), &Emblem_Class::wrap_new);
    wrap_register (g_emblemed_icon_get_type (), &EmblemedIcon_Class::wrap_new);
    wrap_register (g_file_enumerator_get_type (),
                   &FileEnumerator_Class::wrap_new);
    wrap_register (g_file_icon_get_type (), &FileIcon_Class::wrap_new);
    wrap_register (g_file_info_get_type (), &FileInfo_Class::wrap_new);
    wrap_register (g_file_input_stream_get_type (),
                   &FileInputStream_Class::wrap_new);
    wrap_register (g_file_io_stream_get_type (), &FileIOStream_Class::wrap_new);
    wrap_register (g_file_monitor_get_type (), &FileMonitor_Class::wrap_new);
    wrap_register (g_filename_completer_get_type (),
                   &FilenameCompleter_Class::wrap_new);
    wrap_register (g_file_output_stream_get_type (),
                   &FileOutputStream_Class::wrap_new);
    wrap_register (g_filter_input_stream_get_type (),
                   &FilterInputStream_Class::wrap_new);
    wrap_register (g_filter_output_stream_get_type (),
                   &FilterOutputStream_Class::wrap_new);
    wrap_register (g_inet_address_get_type (), &InetAddress_Class::wrap_new);
    wrap_register (g_inet_socket_address_get_type (),
                   &InetSocketAddress_Class::wrap_new);
    wrap_register (g_input_stream_get_type (), &InputStream_Class::wrap_new);
    wrap_register (g_io_stream_get_type (), &IOStream_Class::wrap_new);
    wrap_register (g_list_store_get_type (), &ListStoreBase_Class::wrap_new);
    wrap_register (g_memory_input_stream_get_type (),
                   &MemoryInputStream_Class::wrap_new);
    wrap_register (g_memory_output_stream_get_type (),
                   &MemoryOutputStream_Class::wrap_new);
    wrap_register (g_menu_get_type (), &Menu_Class::wrap_new);
    wrap_register (g_menu_attribute_iter_get_type (),
                   &MenuAttributeIter_Class::wrap_new);
    wrap_register (g_menu_item_get_type (), &MenuItem_Class::wrap_new);
    wrap_register (g_menu_link_iter_get_type (), &MenuLinkIter_Class::wrap_new);
    wrap_register (g_menu_model_get_type (), &MenuModel_Class::wrap_new);
    wrap_register (g_mount_operation_get_type (),
                   &MountOperation_Class::wrap_new);
    wrap_register (g_network_address_get_type (),
                   &NetworkAddress_Class::wrap_new);
    wrap_register (g_network_service_get_type (),
                   &NetworkService_Class::wrap_new);
    wrap_register (g_notification_get_type (), &Notification_Class::wrap_new);
    wrap_register (g_output_stream_get_type (), &OutputStream_Class::wrap_new);
    wrap_register (g_permission_get_type (), &Permission_Class::wrap_new);
    wrap_register (g_property_action_get_type (),
                   &PropertyAction_Class::wrap_new);
    wrap_register (g_proxy_address_get_type (), &ProxyAddress_Class::wrap_new);
    wrap_register (g_resolver_get_type (), &Resolver_Class::wrap_new);
    wrap_register (g_settings_get_type (), &Settings_Class::wrap_new);
    wrap_register (g_simple_action_get_type (), &SimpleAction_Class::wrap_new);
    wrap_register (g_simple_action_group_get_type (),
                   &SimpleActionGroup_Class::wrap_new);
    wrap_register (g_simple_io_stream_get_type (),
                   &SimpleIOStream_Class::wrap_new);
    wrap_register (g_simple_permission_get_type (),
                   &SimplePermission_Class::wrap_new);
    wrap_register (g_socket_get_type (), &Socket_Class::wrap_new);
    wrap_register (g_socket_address_get_type (),
                   &SocketAddress_Class::wrap_new);
    wrap_register (g_socket_address_enumerator_get_type (),
                   &SocketAddressEnumerator_Class::wrap_new);
    wrap_register (g_socket_client_get_type (), &SocketClient_Class::wrap_new);
    wrap_register (g_socket_connection_get_type (),
                   &SocketConnection_Class::wrap_new);
    wrap_register (g_socket_control_message_get_type (),
                   &SocketControlMessage_Class::wrap_new);
    wrap_register (g_socket_listener_get_type (),
                   &SocketListener_Class::wrap_new);
    wrap_register (g_socket_service_get_type (),
                   &SocketService_Class::wrap_new);
    wrap_register (g_tcp_connection_get_type (),
                   &TcpConnection_Class::wrap_new);
    wrap_register (g_tcp_wrapper_connection_get_type (),
                   &TcpWrapperConnection_Class::wrap_new);
    wrap_register (g_themed_icon_get_type (), &ThemedIcon_Class::wrap_new);
    wrap_register (g_threaded_socket_service_get_type (),
                   &ThreadedSocketService_Class::wrap_new);
    wrap_register (g_tls_certificate_get_type (),
                   &TlsCertificate_Class::wrap_new);
    wrap_register (g_tls_connection_get_type (),
                   &TlsConnection_Class::wrap_new);
    wrap_register (g_tls_database_get_type (), &TlsDatabase_Class::wrap_new);
    wrap_register (g_tls_interaction_get_type (),
                   &TlsInteraction_Class::wrap_new);
    wrap_register (g_tls_password_get_type (), &TlsPassword_Class::wrap_new);
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_connection_get_type (),
                         &UnixConnection_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_credentials_message_get_type (),
                         &UnixCredentialsMessage_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_fd_list_get_type (),
                         &UnixFDList_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_fd_message_get_type (),
                         &UnixFDMessage_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_input_stream_get_type (),
                         &UnixInputStream_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_output_stream_get_type (),
                         &UnixOutputStream_Class::wrap_new);
#endif
#ifndef G_OS_WIN32
    glib::wrap_register (g_unix_socket_address_get_type (),
                         &UnixSocketAddress_Class::wrap_new);
#endif
    wrap_register (g_volume_monitor_get_type (),
                   &VolumeMonitor_Class::wrap_new);
    wrap_register (g_zlib_compressor_get_type (),
                   &ZlibCompressor_Class::wrap_new);
    wrap_register (g_zlib_decompressor_get_type (),
                   &ZlibDecompressor_Class::wrap_new);

    g_type_ensure (AppInfoMonitor::get_type ());
    g_type_ensure (AppLaunchContext::get_type ());
    g_type_ensure (Application::get_type ());
    g_type_ensure (ApplicationCommandLine::get_type ());
    g_type_ensure (BufferedInputStream::get_type ());
    g_type_ensure (BufferedOutputStream::get_type ());
    g_type_ensure (Cancellable::get_type ());
    g_type_ensure (CharsetConverter::get_type ());
    g_type_ensure (ConverterInputStream::get_type ());
    g_type_ensure (ConverterOutputStream::get_type ());
    g_type_ensure (Credentials::get_type ());
    g_type_ensure (DataInputStream::get_type ());
    g_type_ensure (DataOutputStream::get_type ());
    g_type_ensure (DBus::ActionGroup::get_type ());
    g_type_ensure (DBus::AuthObserver::get_type ());
    g_type_ensure (DBus::Connection::get_type ());
    g_type_ensure (DBus::InterfaceSkeleton::get_type ());
    g_type_ensure (DBus::MenuModel::get_type ());
    g_type_ensure (DBus::Message::get_type ());
    g_type_ensure (DBus::MethodInvocation::get_type ());
    g_type_ensure (DBus::ObjectManagerClient::get_type ());
    g_type_ensure (DBus::ObjectManagerServer::get_type ());
    g_type_ensure (DBus::ObjectProxy::get_type ());
    g_type_ensure (DBus::ObjectSkeleton::get_type ());
    g_type_ensure (DBus::Proxy::get_type ());
    g_type_ensure (DBus::Server::get_type ());
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
    g_type_ensure (DesktopAppInfo::get_type ());
#endif
    g_type_ensure (Emblem::get_type ());
    g_type_ensure (EmblemedIcon::get_type ());
    g_type_ensure (FileEnumerator::get_type ());
    g_type_ensure (FileIcon::get_type ());
    g_type_ensure (FileInfo::get_type ());
    g_type_ensure (FileInputStream::get_type ());
    g_type_ensure (FileIOStream::get_type ());
    g_type_ensure (FileMonitor::get_type ());
    g_type_ensure (FilenameCompleter::get_type ());
    g_type_ensure (FileOutputStream::get_type ());
    g_type_ensure (FilterInputStream::get_type ());
    g_type_ensure (FilterOutputStream::get_type ());
    g_type_ensure (InetAddress::get_type ());
    g_type_ensure (InetSocketAddress::get_type ());
    g_type_ensure (InputStream::get_type ());
    g_type_ensure (IOStream::get_type ());
    g_type_ensure (ListStoreBase::get_type ());
    g_type_ensure (MemoryInputStream::get_type ());
    g_type_ensure (MemoryOutputStream::get_type ());
    g_type_ensure (Menu::get_type ());
    g_type_ensure (MenuAttributeIter::get_type ());
    g_type_ensure (MenuItem::get_type ());
    g_type_ensure (MenuLinkIter::get_type ());
    g_type_ensure (MenuModel::get_type ());
    g_type_ensure (MountOperation::get_type ());
    g_type_ensure (NetworkAddress::get_type ());
    g_type_ensure (NetworkService::get_type ());
    g_type_ensure (Notification::get_type ());
    g_type_ensure (OutputStream::get_type ());
    g_type_ensure (Permission::get_type ());
    g_type_ensure (PropertyAction::get_type ());
    g_type_ensure (ProxyAddress::get_type ());
    g_type_ensure (Resolver::get_type ());
    g_type_ensure (Settings::get_type ());
    g_type_ensure (SimpleAction::get_type ());
    g_type_ensure (SimpleActionGroup::get_type ());
    g_type_ensure (SimpleIOStream::get_type ());
    g_type_ensure (SimplePermission::get_type ());
    g_type_ensure (Socket::get_type ());
    g_type_ensure (SocketAddress::get_type ());
    g_type_ensure (SocketAddressEnumerator::get_type ());
    g_type_ensure (SocketClient::get_type ());
    g_type_ensure (SocketConnection::get_type ());
    g_type_ensure (SocketControlMessage::get_type ());
    g_type_ensure (SocketListener::get_type ());
    g_type_ensure (SocketService::get_type ());
    g_type_ensure (TcpConnection::get_type ());
    g_type_ensure (TcpWrapperConnection::get_type ());
    g_type_ensure (ThemedIcon::get_type ());
    g_type_ensure (ThreadedSocketService::get_type ());
    g_type_ensure (TlsCertificate::get_type ());
    g_type_ensure (TlsConnection::get_type ());
    g_type_ensure (TlsDatabase::get_type ());
    g_type_ensure (TlsInteraction::get_type ());
    g_type_ensure (TlsPassword::get_type ());
#ifndef G_OS_WIN32
    g_type_ensure (UnixConnection::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixCredentialsMessage::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixFDList::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixFDMessage::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixInputStream::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixOutputStream::get_type ());
#endif
#ifndef G_OS_WIN32
    g_type_ensure (UnixSocketAddress::get_type ());
#endif
    g_type_ensure (VolumeMonitor::get_type ());
    g_type_ensure (ZlibCompressor::get_type ());
    g_type_ensure (ZlibDecompressor::get_type ());
  }

} // namespace gio
