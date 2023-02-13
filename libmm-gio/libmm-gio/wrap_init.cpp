

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <mm/glib/mm-glib.hpp>
#include <mm/gio/wrap_init.hpp>
#include <mm/glib/error.hpp>
#include <mm/glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <mm/gio/action.hpp>
#include <mm/gio/actiongroup.hpp>
#include <mm/gio/actionmap.hpp>
#include <mm/gio/appinfo.hpp>
#include <mm/gio/appinfomonitor.hpp>
#include <mm/gio/applaunchcontext.hpp>
#include <mm/gio/application.hpp>
#include <mm/gio/applicationcommandline.hpp>
#include <mm/gio/asyncinitable.hpp>
#include <mm/gio/asyncresult.hpp>
#include <mm/gio/bufferedinputstream.hpp>
#include <mm/gio/bufferedoutputstream.hpp>
#include <mm/gio/cancellable.hpp>
#include <mm/gio/charsetconverter.hpp>
#include <mm/gio/converter.hpp>
#include <mm/gio/converterinputstream.hpp>
#include <mm/gio/converteroutputstream.hpp>
#include <mm/gio/credentials.hpp>
#include <mm/gio/datainputstream.hpp>
#include <mm/gio/dataoutputstream.hpp>
#include <mm/gio/dbusactiongroup.hpp>
#include <mm/gio/dbusaddress.hpp>
#include <mm/gio/dbusauthobserver.hpp>
#include <mm/gio/dbusconnection.hpp>
#include <mm/gio/dbuserror.hpp>
#include <mm/gio/dbuserrorutils.hpp>
#include <mm/gio/dbusinterface.hpp>
#include <mm/gio/dbusinterfaceskeleton.hpp>
#include <mm/gio/dbusinterfacevtable.hpp>
#include <mm/gio/dbusintrospection.hpp>
#include <mm/gio/dbusmenumodel.hpp>
#include <mm/gio/dbusmessage.hpp>
#include <mm/gio/dbusmethodinvocation.hpp>
#include <mm/gio/dbusobject.hpp>
#include <mm/gio/dbusobjectmanager.hpp>
#include <mm/gio/dbusobjectmanagerclient.hpp>
#include <mm/gio/dbusobjectmanagerserver.hpp>
#include <mm/gio/dbusobjectproxy.hpp>
#include <mm/gio/dbusobjectskeleton.hpp>
#include <mm/gio/dbusownname.hpp>
#include <mm/gio/dbusproxy.hpp>
#include <mm/gio/dbusserver.hpp>
#include <mm/gio/dbussubtreevtable.hpp>
#include <mm/gio/dbusutils.hpp>
#include <mm/gio/dbuswatchname.hpp>
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <mm/gio/desktopappinfo.hpp>
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <mm/gio/drive.hpp>
#include <mm/gio/emblem.hpp>
#include <mm/gio/emblemedicon.hpp>
#include <mm/gio/enums.hpp>
#include <mm/gio/error.hpp>
#include <mm/gio/file.hpp>
#include <mm/gio/fileattributeinfo.hpp>
#include <mm/gio/fileattributeinfolist.hpp>
#ifndef G_OS_WIN32
#include <mm/gio/filedescriptorbased.hpp>
#endif // ifndef G_OS_WIN32
#include <mm/gio/fileenumerator.hpp>
#include <mm/gio/fileicon.hpp>
#include <mm/gio/fileinfo.hpp>
#include <mm/gio/fileinputstream.hpp>
#include <mm/gio/fileiostream.hpp>
#include <mm/gio/filemonitor.hpp>
#include <mm/gio/filenamecompleter.hpp>
#include <mm/gio/fileoutputstream.hpp>
#include <mm/gio/filterinputstream.hpp>
#include <mm/gio/filteroutputstream.hpp>
#include <mm/gio/icon.hpp>
#include <mm/gio/inetaddress.hpp>
#include <mm/gio/inetsocketaddress.hpp>
#include <mm/gio/initable.hpp>
#include <mm/gio/inputstream.hpp>
#include <mm/gio/iostream.hpp>
#include <mm/gio/listmodel.hpp>
#include <mm/gio/liststore.hpp>
#include <mm/gio/loadableicon.hpp>
#include <mm/gio/memoryinputstream.hpp>
#include <mm/gio/memoryoutputstream.hpp>
#include <mm/gio/menu.hpp>
#include <mm/gio/menuattributeiter.hpp>
#include <mm/gio/menuitem.hpp>
#include <mm/gio/menulinkiter.hpp>
#include <mm/gio/menumodel.hpp>
#include <mm/gio/mount.hpp>
#include <mm/gio/mountoperation.hpp>
#include <mm/gio/networkaddress.hpp>
#include <mm/gio/networkmonitor.hpp>
#include <mm/gio/networkservice.hpp>
#include <mm/gio/notification.hpp>
#include <mm/gio/outputstream.hpp>
#include <mm/gio/permission.hpp>
#include <mm/gio/pollableinputstream.hpp>
#include <mm/gio/pollableoutputstream.hpp>
#include <mm/gio/propertyaction.hpp>
#include <mm/gio/proxy.hpp>
#include <mm/gio/proxyaddress.hpp>
#include <mm/gio/proxyresolver.hpp>
#include <mm/gio/remoteactiongroup.hpp>
#include <mm/gio/resolver.hpp>
#include <mm/gio/resource.hpp>
#include <mm/gio/seekable.hpp>
#include <mm/gio/settings.hpp>
#include <mm/gio/settingsschema.hpp>
#include <mm/gio/settingsschemakey.hpp>
#include <mm/gio/settingsschemasource.hpp>
#include <mm/gio/simpleaction.hpp>
#include <mm/gio/simpleactiongroup.hpp>
#include <mm/gio/simpleiostream.hpp>
#include <mm/gio/simplepermission.hpp>
#include <mm/gio/socket.hpp>
#include <mm/gio/socketaddress.hpp>
#include <mm/gio/socketaddressenumerator.hpp>
#include <mm/gio/socketclient.hpp>
#include <mm/gio/socketconnectable.hpp>
#include <mm/gio/socketconnection.hpp>
#include <mm/gio/socketcontrolmessage.hpp>
#include <mm/gio/socketlistener.hpp>
#include <mm/gio/socketservice.hpp>
#include <mm/gio/srvtarget.hpp>
#include <mm/gio/tcpconnection.hpp>
#include <mm/gio/tcpwrapperconnection.hpp>
#include <mm/gio/themedicon.hpp>
#include <mm/gio/threadedsocketservice.hpp>
#include <mm/gio/tlscertificate.hpp>
#include <mm/gio/tlsclientconnection.hpp>
#include <mm/gio/tlsconnection.hpp>
#include <mm/gio/tlsdatabase.hpp>
#include <mm/gio/tlsinteraction.hpp>
#include <mm/gio/tlspassword.hpp>
#include <mm/gio/tlsserverconnection.hpp>
#ifndef G_OS_WIN32
#include <mm/gio/unixconnection.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixcredentialsmessage.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixfdlist.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixfdmessage.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixinputstream.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixoutputstream.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <mm/gio/unixsocketaddress.hpp>
#endif // ifndef G_OS_WIN32
#include <mm/gio/volume.hpp>
#include <mm/gio/volumemonitor.hpp>
#include <mm/gio/zlibcompressor.hpp>
#include <mm/gio/zlibdecompressor.hpp>

#ifndef G_OS_WIN32

extern "C"
{

//Declarations of the *_get_type() functions:

auto g_app_info_monitor_get_type(void) -> GType;
auto g_app_launch_context_get_type(void) -> GType;
auto g_application_get_type(void) -> GType;
auto g_application_command_line_get_type(void) -> GType;
auto g_buffered_input_stream_get_type(void) -> GType;
auto g_buffered_output_stream_get_type(void) -> GType;
auto g_cancellable_get_type(void) -> GType;
auto g_charset_converter_get_type(void) -> GType;
auto g_converter_input_stream_get_type(void) -> GType;
auto g_converter_output_stream_get_type(void) -> GType;
auto g_credentials_get_type(void) -> GType;
auto g_data_input_stream_get_type(void) -> GType;
auto g_data_output_stream_get_type(void) -> GType;
auto g_dbus_action_group_get_type(void) -> GType;
auto g_dbus_auth_observer_get_type(void) -> GType;
auto g_dbus_connection_get_type(void) -> GType;
auto g_dbus_interface_skeleton_get_type(void) -> GType;
auto g_dbus_menu_model_get_type(void) -> GType;
auto g_dbus_message_get_type(void) -> GType;
auto g_dbus_method_invocation_get_type(void) -> GType;
auto g_dbus_object_manager_client_get_type(void) -> GType;
auto g_dbus_object_manager_server_get_type(void) -> GType;
auto g_dbus_object_proxy_get_type(void) -> GType;
auto g_dbus_object_skeleton_get_type(void) -> GType;
auto g_dbus_proxy_get_type(void) -> GType;
auto g_dbus_server_get_type(void) -> GType;
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
auto g_desktop_app_info_get_type(void) -> GType;
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
auto g_emblem_get_type(void) -> GType;
auto g_emblemed_icon_get_type(void) -> GType;
auto g_file_enumerator_get_type(void) -> GType;
auto g_file_icon_get_type(void) -> GType;
auto g_file_info_get_type(void) -> GType;
auto g_file_input_stream_get_type(void) -> GType;
auto g_file_io_stream_get_type(void) -> GType;
auto g_file_monitor_get_type(void) -> GType;
auto g_filename_completer_get_type(void) -> GType;
auto g_file_output_stream_get_type(void) -> GType;
auto g_filter_input_stream_get_type(void) -> GType;
auto g_filter_output_stream_get_type(void) -> GType;
auto g_inet_address_get_type(void) -> GType;
auto g_inet_socket_address_get_type(void) -> GType;
auto g_input_stream_get_type(void) -> GType;
auto g_io_stream_get_type(void) -> GType;
auto g_list_store_get_type(void) -> GType;
auto g_memory_input_stream_get_type(void) -> GType;
auto g_memory_output_stream_get_type(void) -> GType;
auto g_menu_get_type(void) -> GType;
auto g_menu_attribute_iter_get_type(void) -> GType;
auto g_menu_item_get_type(void) -> GType;
auto g_menu_link_iter_get_type(void) -> GType;
auto g_menu_model_get_type(void) -> GType;
auto g_mount_operation_get_type(void) -> GType;
auto g_network_address_get_type(void) -> GType;
auto g_network_service_get_type(void) -> GType;
auto g_notification_get_type(void) -> GType;
auto g_output_stream_get_type(void) -> GType;
auto g_permission_get_type(void) -> GType;
auto g_property_action_get_type(void) -> GType;
auto g_proxy_address_get_type(void) -> GType;
auto g_resolver_get_type(void) -> GType;
auto g_settings_get_type(void) -> GType;
auto g_simple_action_get_type(void) -> GType;
auto g_simple_action_group_get_type(void) -> GType;
auto g_simple_io_stream_get_type(void) -> GType;
auto g_simple_permission_get_type(void) -> GType;
auto g_socket_get_type(void) -> GType;
auto g_socket_address_get_type(void) -> GType;
auto g_socket_address_enumerator_get_type(void) -> GType;
auto g_socket_client_get_type(void) -> GType;
auto g_socket_connection_get_type(void) -> GType;
auto g_socket_control_message_get_type(void) -> GType;
auto g_socket_listener_get_type(void) -> GType;
auto g_socket_service_get_type(void) -> GType;
auto g_tcp_connection_get_type(void) -> GType;
auto g_tcp_wrapper_connection_get_type(void) -> GType;
auto g_themed_icon_get_type(void) -> GType;
auto g_threaded_socket_service_get_type(void) -> GType;
auto g_tls_certificate_get_type(void) -> GType;
auto g_tls_connection_get_type(void) -> GType;
auto g_tls_database_get_type(void) -> GType;
auto g_tls_interaction_get_type(void) -> GType;
auto g_tls_password_get_type(void) -> GType;
#ifndef G_OS_WIN32
auto g_unix_connection_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_credentials_message_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_fd_list_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_fd_message_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_input_stream_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_output_stream_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
auto g_unix_socket_address_get_type(void) -> GType;
#endif // ifndef G_OS_WIN32
auto g_volume_monitor_get_type(void) -> GType;
auto g_zlib_compressor_get_type(void) -> GType;
auto g_zlib_decompressor_get_type(void) -> GType;

//Declarations of the *_error_quark() functions:

auto g_dbus_error_quark(void) -> GQuark;
auto g_io_error_quark(void) -> GQuark;
auto g_resolver_error_quark(void) -> GQuark;
auto g_tls_error_quark(void) -> GQuark;
auto g_resource_error_quark(void) -> GQuark;

} // extern "C"

#endif // G_OS_WIN32

namespace Gio {

//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

class AppInfoMonitor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class AppLaunchContext_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Application_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ApplicationCommandLine_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BufferedInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class BufferedOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Cancellable_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class CharsetConverter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ConverterInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ConverterOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Credentials_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DataInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class DataOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
namespace DBus { class ActionGroup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class AuthObserver_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class Connection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class InterfaceSkeleton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class MenuModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class Message_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class MethodInvocation_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class ObjectManagerClient_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class ObjectManagerServer_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class ObjectProxy_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class ObjectSkeleton_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class Proxy_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
namespace DBus { class Server_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; }; }
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
class DesktopAppInfo_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
class Emblem_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class EmblemedIcon_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileEnumerator_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileIcon_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileInfo_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileIOStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileMonitor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FilenameCompleter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FileOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FilterInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class FilterOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class InetAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class InetSocketAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class InputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class IOStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ListStoreBase_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MemoryInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MemoryOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Menu_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MenuAttributeIter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MenuItem_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MenuLinkIter_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MenuModel_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class MountOperation_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NetworkAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class NetworkService_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Notification_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class OutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Permission_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class PropertyAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ProxyAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Resolver_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Settings_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SimpleAction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SimpleActionGroup_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SimpleIOStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SimplePermission_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class Socket_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketAddressEnumerator_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketClient_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketConnection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketControlMessage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketListener_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class SocketService_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TcpConnection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TcpWrapperConnection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ThemedIcon_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ThreadedSocketService_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TlsCertificate_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TlsConnection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TlsDatabase_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TlsInteraction_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class TlsPassword_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#ifndef G_OS_WIN32
class UnixConnection_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixCredentialsMessage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixFDList_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixFDMessage_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixInputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixOutputStream_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
class UnixSocketAddress_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
#endif // ifndef G_OS_WIN32
class VolumeMonitor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ZlibCompressor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };
class ZlibDecompressor_Class { public: static auto wrap_new(GObject*) -> Glib::ObjectBase*; };

// Register Error domains in sub-namespaces:

namespace DBus {

auto wrap_init () -> void
{
  Glib::Error::register_domain(g_dbus_error_quark(), &Error::throw_func);

} // wrap_init()

} // DBus

auto wrap_init () -> void
{
  // Register Error domains in the main namespace:
  Glib::Error::register_domain(g_io_error_quark(), &Error::throw_func);
  Glib::Error::register_domain(g_resolver_error_quark(), &ResolverError::throw_func);
  Glib::Error::register_domain(g_tls_error_quark(), &TlsError::throw_func);
  Glib::Error::register_domain(g_resource_error_quark(), &ResourceError::throw_func);

  // Call the wrap_init() functions in sub-namespaces:
  DBus::wrap_init();

  // Map gtypes to gtkmm wrapper-creation functions:
  wrap_register(g_app_info_monitor_get_type(), &AppInfoMonitor_Class::wrap_new);
  wrap_register(g_app_launch_context_get_type(), &AppLaunchContext_Class::wrap_new);
  wrap_register(g_application_get_type(), &Application_Class::wrap_new);
  wrap_register(g_application_command_line_get_type(), &ApplicationCommandLine_Class::wrap_new);
  wrap_register(g_buffered_input_stream_get_type(), &BufferedInputStream_Class::wrap_new);
  wrap_register(g_buffered_output_stream_get_type(), &BufferedOutputStream_Class::wrap_new);
  wrap_register(g_cancellable_get_type(), &Cancellable_Class::wrap_new);
  wrap_register(g_charset_converter_get_type(), &CharsetConverter_Class::wrap_new);
  wrap_register(g_converter_input_stream_get_type(), &ConverterInputStream_Class::wrap_new);
  wrap_register(g_converter_output_stream_get_type(), &ConverterOutputStream_Class::wrap_new);
  wrap_register(g_credentials_get_type(), &Credentials_Class::wrap_new);
  wrap_register(g_data_input_stream_get_type(), &DataInputStream_Class::wrap_new);
  wrap_register(g_data_output_stream_get_type(), &DataOutputStream_Class::wrap_new);
  wrap_register(g_dbus_action_group_get_type(), &DBus::ActionGroup_Class::wrap_new);
  wrap_register(g_dbus_auth_observer_get_type(), &DBus::AuthObserver_Class::wrap_new);
  wrap_register(g_dbus_connection_get_type(), &DBus::Connection_Class::wrap_new);
  wrap_register(g_dbus_interface_skeleton_get_type(), &DBus::InterfaceSkeleton_Class::wrap_new);
  wrap_register(g_dbus_menu_model_get_type(), &DBus::MenuModel_Class::wrap_new);
  wrap_register(g_dbus_message_get_type(), &DBus::Message_Class::wrap_new);
  wrap_register(g_dbus_method_invocation_get_type(), &DBus::MethodInvocation_Class::wrap_new);
  wrap_register(g_dbus_object_manager_client_get_type(), &DBus::ObjectManagerClient_Class::wrap_new);
  wrap_register(g_dbus_object_manager_server_get_type(), &DBus::ObjectManagerServer_Class::wrap_new);
  wrap_register(g_dbus_object_proxy_get_type(), &DBus::ObjectProxy_Class::wrap_new);
  wrap_register(g_dbus_object_skeleton_get_type(), &DBus::ObjectSkeleton_Class::wrap_new);
  wrap_register(g_dbus_proxy_get_type(), &DBus::Proxy_Class::wrap_new);
  wrap_register(g_dbus_server_get_type(), &DBus::Server_Class::wrap_new);
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  Glib::wrap_register(g_desktop_app_info_get_type(), &DesktopAppInfo_Class::wrap_new);
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  wrap_register(g_emblem_get_type(), &Emblem_Class::wrap_new);
  wrap_register(g_emblemed_icon_get_type(), &EmblemedIcon_Class::wrap_new);
  wrap_register(g_file_enumerator_get_type(), &FileEnumerator_Class::wrap_new);
  wrap_register(g_file_icon_get_type(), &FileIcon_Class::wrap_new);
  wrap_register(g_file_info_get_type(), &FileInfo_Class::wrap_new);
  wrap_register(g_file_input_stream_get_type(), &FileInputStream_Class::wrap_new);
  wrap_register(g_file_io_stream_get_type(), &FileIOStream_Class::wrap_new);
  wrap_register(g_file_monitor_get_type(), &FileMonitor_Class::wrap_new);
  wrap_register(g_filename_completer_get_type(), &FilenameCompleter_Class::wrap_new);
  wrap_register(g_file_output_stream_get_type(), &FileOutputStream_Class::wrap_new);
  wrap_register(g_filter_input_stream_get_type(), &FilterInputStream_Class::wrap_new);
  wrap_register(g_filter_output_stream_get_type(), &FilterOutputStream_Class::wrap_new);
  wrap_register(g_inet_address_get_type(), &InetAddress_Class::wrap_new);
  wrap_register(g_inet_socket_address_get_type(), &InetSocketAddress_Class::wrap_new);
  wrap_register(g_input_stream_get_type(), &InputStream_Class::wrap_new);
  wrap_register(g_io_stream_get_type(), &IOStream_Class::wrap_new);
  wrap_register(g_list_store_get_type(), &ListStoreBase_Class::wrap_new);
  wrap_register(g_memory_input_stream_get_type(), &MemoryInputStream_Class::wrap_new);
  wrap_register(g_memory_output_stream_get_type(), &MemoryOutputStream_Class::wrap_new);
  wrap_register(g_menu_get_type(), &Menu_Class::wrap_new);
  wrap_register(g_menu_attribute_iter_get_type(), &MenuAttributeIter_Class::wrap_new);
  wrap_register(g_menu_item_get_type(), &MenuItem_Class::wrap_new);
  wrap_register(g_menu_link_iter_get_type(), &MenuLinkIter_Class::wrap_new);
  wrap_register(g_menu_model_get_type(), &MenuModel_Class::wrap_new);
  wrap_register(g_mount_operation_get_type(), &MountOperation_Class::wrap_new);
  wrap_register(g_network_address_get_type(), &NetworkAddress_Class::wrap_new);
  wrap_register(g_network_service_get_type(), &NetworkService_Class::wrap_new);
  wrap_register(g_notification_get_type(), &Notification_Class::wrap_new);
  wrap_register(g_output_stream_get_type(), &OutputStream_Class::wrap_new);
  wrap_register(g_permission_get_type(), &Permission_Class::wrap_new);
  wrap_register(g_property_action_get_type(), &PropertyAction_Class::wrap_new);
  wrap_register(g_proxy_address_get_type(), &ProxyAddress_Class::wrap_new);
  wrap_register(g_resolver_get_type(), &Resolver_Class::wrap_new);
  wrap_register(g_settings_get_type(), &Settings_Class::wrap_new);
  wrap_register(g_simple_action_get_type(), &SimpleAction_Class::wrap_new);
  wrap_register(g_simple_action_group_get_type(), &SimpleActionGroup_Class::wrap_new);
  wrap_register(g_simple_io_stream_get_type(), &SimpleIOStream_Class::wrap_new);
  wrap_register(g_simple_permission_get_type(), &SimplePermission_Class::wrap_new);
  wrap_register(g_socket_get_type(), &Socket_Class::wrap_new);
  wrap_register(g_socket_address_get_type(), &SocketAddress_Class::wrap_new);
  wrap_register(g_socket_address_enumerator_get_type(), &SocketAddressEnumerator_Class::wrap_new);
  wrap_register(g_socket_client_get_type(), &SocketClient_Class::wrap_new);
  wrap_register(g_socket_connection_get_type(), &SocketConnection_Class::wrap_new);
  wrap_register(g_socket_control_message_get_type(), &SocketControlMessage_Class::wrap_new);
  wrap_register(g_socket_listener_get_type(), &SocketListener_Class::wrap_new);
  wrap_register(g_socket_service_get_type(), &SocketService_Class::wrap_new);
  wrap_register(g_tcp_connection_get_type(), &TcpConnection_Class::wrap_new);
  wrap_register(g_tcp_wrapper_connection_get_type(), &TcpWrapperConnection_Class::wrap_new);
  wrap_register(g_themed_icon_get_type(), &ThemedIcon_Class::wrap_new);
  wrap_register(g_threaded_socket_service_get_type(), &ThreadedSocketService_Class::wrap_new);
  wrap_register(g_tls_certificate_get_type(), &TlsCertificate_Class::wrap_new);
  wrap_register(g_tls_connection_get_type(), &TlsConnection_Class::wrap_new);
  wrap_register(g_tls_database_get_type(), &TlsDatabase_Class::wrap_new);
  wrap_register(g_tls_interaction_get_type(), &TlsInteraction_Class::wrap_new);
  wrap_register(g_tls_password_get_type(), &TlsPassword_Class::wrap_new);
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_connection_get_type(), &UnixConnection_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_credentials_message_get_type(), &UnixCredentialsMessage_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_fd_list_get_type(), &UnixFDList_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_fd_message_get_type(), &UnixFDMessage_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_input_stream_get_type(), &UnixInputStream_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_output_stream_get_type(), &UnixOutputStream_Class::wrap_new);
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  Glib::wrap_register(g_unix_socket_address_get_type(), &UnixSocketAddress_Class::wrap_new);
#endif // ifndef G_OS_WIN32
  wrap_register(g_volume_monitor_get_type(), &VolumeMonitor_Class::wrap_new);
  wrap_register(g_zlib_compressor_get_type(), &ZlibCompressor_Class::wrap_new);
  wrap_register(g_zlib_decompressor_get_type(), &ZlibDecompressor_Class::wrap_new);

  // Register the gtkmm gtypes:
  g_type_ensure(AppInfoMonitor::get_type());
  g_type_ensure(AppLaunchContext::get_type());
  g_type_ensure(Application::get_type());
  g_type_ensure(ApplicationCommandLine::get_type());
  g_type_ensure(BufferedInputStream::get_type());
  g_type_ensure(BufferedOutputStream::get_type());
  g_type_ensure(Cancellable::get_type());
  g_type_ensure(CharsetConverter::get_type());
  g_type_ensure(ConverterInputStream::get_type());
  g_type_ensure(ConverterOutputStream::get_type());
  g_type_ensure(Credentials::get_type());
  g_type_ensure(DataInputStream::get_type());
  g_type_ensure(DataOutputStream::get_type());
  g_type_ensure(DBus::ActionGroup::get_type());
  g_type_ensure(DBus::AuthObserver::get_type());
  g_type_ensure(DBus::Connection::get_type());
  g_type_ensure(DBus::InterfaceSkeleton::get_type());
  g_type_ensure(DBus::MenuModel::get_type());
  g_type_ensure(DBus::Message::get_type());
  g_type_ensure(DBus::MethodInvocation::get_type());
  g_type_ensure(DBus::ObjectManagerClient::get_type());
  g_type_ensure(DBus::ObjectManagerServer::get_type());
  g_type_ensure(DBus::ObjectProxy::get_type());
  g_type_ensure(DBus::ObjectSkeleton::get_type());
  g_type_ensure(DBus::Proxy::get_type());
  g_type_ensure(DBus::Server::get_type());
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  g_type_ensure(DesktopAppInfo::get_type());
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
  g_type_ensure(Emblem::get_type());
  g_type_ensure(EmblemedIcon::get_type());
  g_type_ensure(FileEnumerator::get_type());
  g_type_ensure(FileIcon::get_type());
  g_type_ensure(FileInfo::get_type());
  g_type_ensure(FileInputStream::get_type());
  g_type_ensure(FileIOStream::get_type());
  g_type_ensure(FileMonitor::get_type());
  g_type_ensure(FilenameCompleter::get_type());
  g_type_ensure(FileOutputStream::get_type());
  g_type_ensure(FilterInputStream::get_type());
  g_type_ensure(FilterOutputStream::get_type());
  g_type_ensure(InetAddress::get_type());
  g_type_ensure(InetSocketAddress::get_type());
  g_type_ensure(InputStream::get_type());
  g_type_ensure(IOStream::get_type());
  g_type_ensure(ListStoreBase::get_type());
  g_type_ensure(MemoryInputStream::get_type());
  g_type_ensure(MemoryOutputStream::get_type());
  g_type_ensure(Menu::get_type());
  g_type_ensure(MenuAttributeIter::get_type());
  g_type_ensure(MenuItem::get_type());
  g_type_ensure(MenuLinkIter::get_type());
  g_type_ensure(MenuModel::get_type());
  g_type_ensure(MountOperation::get_type());
  g_type_ensure(NetworkAddress::get_type());
  g_type_ensure(NetworkService::get_type());
  g_type_ensure(Notification::get_type());
  g_type_ensure(OutputStream::get_type());
  g_type_ensure(Permission::get_type());
  g_type_ensure(PropertyAction::get_type());
  g_type_ensure(ProxyAddress::get_type());
  g_type_ensure(Resolver::get_type());
  g_type_ensure(Settings::get_type());
  g_type_ensure(SimpleAction::get_type());
  g_type_ensure(SimpleActionGroup::get_type());
  g_type_ensure(SimpleIOStream::get_type());
  g_type_ensure(SimplePermission::get_type());
  g_type_ensure(Socket::get_type());
  g_type_ensure(SocketAddress::get_type());
  g_type_ensure(SocketAddressEnumerator::get_type());
  g_type_ensure(SocketClient::get_type());
  g_type_ensure(SocketConnection::get_type());
  g_type_ensure(SocketControlMessage::get_type());
  g_type_ensure(SocketListener::get_type());
  g_type_ensure(SocketService::get_type());
  g_type_ensure(TcpConnection::get_type());
  g_type_ensure(TcpWrapperConnection::get_type());
  g_type_ensure(ThemedIcon::get_type());
  g_type_ensure(ThreadedSocketService::get_type());
  g_type_ensure(TlsCertificate::get_type());
  g_type_ensure(TlsConnection::get_type());
  g_type_ensure(TlsDatabase::get_type());
  g_type_ensure(TlsInteraction::get_type());
  g_type_ensure(TlsPassword::get_type());
#ifndef G_OS_WIN32
  g_type_ensure(UnixConnection::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixCredentialsMessage::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixFDList::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixFDMessage::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixInputStream::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixOutputStream::get_type());
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
  g_type_ensure(UnixSocketAddress::get_type());
#endif // ifndef G_OS_WIN32
  g_type_ensure(VolumeMonitor::get_type());
  g_type_ensure(ZlibCompressor::get_type());
  g_type_ensure(ZlibDecompressor::get_type());

} // wrap_init()

} // Gio

