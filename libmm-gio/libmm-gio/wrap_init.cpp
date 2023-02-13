

#define GLIBMM_INCLUDED_FROM_WRAP_INIT_CC
#include <libmm-glib/mm-glib.hpp>
#include <libmm-gio/wrap_init.hpp>
#include <libmm-glib/error.hpp>
#include <libmm-glib/object.hpp>

// #include the widget headers so that we can call the get_type() static methods:
#include <libmm-gio/action.hpp>
#include <libmm-gio/actiongroup.hpp>
#include <libmm-gio/actionmap.hpp>
#include <libmm-gio/appinfo.hpp>
#include <libmm-gio/appinfomonitor.hpp>
#include <libmm-gio/applaunchcontext.hpp>
#include <libmm-gio/application.hpp>
#include <libmm-gio/applicationcommandline.hpp>
#include <libmm-gio/asyncinitable.hpp>
#include <libmm-gio/asyncresult.hpp>
#include <libmm-gio/bufferedinputstream.hpp>
#include <libmm-gio/bufferedoutputstream.hpp>
#include <libmm-gio/cancellable.hpp>
#include <libmm-gio/charsetconverter.hpp>
#include <libmm-gio/converter.hpp>
#include <libmm-gio/converterinputstream.hpp>
#include <libmm-gio/converteroutputstream.hpp>
#include <libmm-gio/credentials.hpp>
#include <libmm-gio/datainputstream.hpp>
#include <libmm-gio/dataoutputstream.hpp>
#include <libmm-gio/dbusactiongroup.hpp>
#include <libmm-gio/dbusaddress.hpp>
#include <libmm-gio/dbusauthobserver.hpp>
#include <libmm-gio/dbusconnection.hpp>
#include <libmm-gio/dbuserror.hpp>
#include <libmm-gio/dbuserrorutils.hpp>
#include <libmm-gio/dbusinterface.hpp>
#include <libmm-gio/dbusinterfaceskeleton.hpp>
#include <libmm-gio/dbusinterfacevtable.hpp>
#include <libmm-gio/dbusintrospection.hpp>
#include <libmm-gio/dbusmenumodel.hpp>
#include <libmm-gio/dbusmessage.hpp>
#include <libmm-gio/dbusmethodinvocation.hpp>
#include <libmm-gio/dbusobject.hpp>
#include <libmm-gio/dbusobjectmanager.hpp>
#include <libmm-gio/dbusobjectmanagerclient.hpp>
#include <libmm-gio/dbusobjectmanagerserver.hpp>
#include <libmm-gio/dbusobjectproxy.hpp>
#include <libmm-gio/dbusobjectskeleton.hpp>
#include <libmm-gio/dbusownname.hpp>
#include <libmm-gio/dbusproxy.hpp>
#include <libmm-gio/dbusserver.hpp>
#include <libmm-gio/dbussubtreevtable.hpp>
#include <libmm-gio/dbusutils.hpp>
#include <libmm-gio/dbuswatchname.hpp>
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <libmm-gio/desktopappinfo.hpp>
#endif // if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <libmm-gio/drive.hpp>
#include <libmm-gio/emblem.hpp>
#include <libmm-gio/emblemedicon.hpp>
#include <libmm-gio/enums.hpp>
#include <libmm-gio/error.hpp>
#include <libmm-gio/file.hpp>
#include <libmm-gio/fileattributeinfo.hpp>
#include <libmm-gio/fileattributeinfolist.hpp>
#ifndef G_OS_WIN32
#include <libmm-gio/filedescriptorbased.hpp>
#endif // ifndef G_OS_WIN32
#include <libmm-gio/fileenumerator.hpp>
#include <libmm-gio/fileicon.hpp>
#include <libmm-gio/fileinfo.hpp>
#include <libmm-gio/fileinputstream.hpp>
#include <libmm-gio/fileiostream.hpp>
#include <libmm-gio/filemonitor.hpp>
#include <libmm-gio/filenamecompleter.hpp>
#include <libmm-gio/fileoutputstream.hpp>
#include <libmm-gio/filterinputstream.hpp>
#include <libmm-gio/filteroutputstream.hpp>
#include <libmm-gio/icon.hpp>
#include <libmm-gio/inetaddress.hpp>
#include <libmm-gio/inetsocketaddress.hpp>
#include <libmm-gio/initable.hpp>
#include <libmm-gio/inputstream.hpp>
#include <libmm-gio/iostream.hpp>
#include <libmm-gio/listmodel.hpp>
#include <libmm-gio/liststore.hpp>
#include <libmm-gio/loadableicon.hpp>
#include <libmm-gio/memoryinputstream.hpp>
#include <libmm-gio/memoryoutputstream.hpp>
#include <libmm-gio/menu.hpp>
#include <libmm-gio/menuattributeiter.hpp>
#include <libmm-gio/menuitem.hpp>
#include <libmm-gio/menulinkiter.hpp>
#include <libmm-gio/menumodel.hpp>
#include <libmm-gio/mount.hpp>
#include <libmm-gio/mountoperation.hpp>
#include <libmm-gio/networkaddress.hpp>
#include <libmm-gio/networkmonitor.hpp>
#include <libmm-gio/networkservice.hpp>
#include <libmm-gio/notification.hpp>
#include <libmm-gio/outputstream.hpp>
#include <libmm-gio/permission.hpp>
#include <libmm-gio/pollableinputstream.hpp>
#include <libmm-gio/pollableoutputstream.hpp>
#include <libmm-gio/propertyaction.hpp>
#include <libmm-gio/proxy.hpp>
#include <libmm-gio/proxyaddress.hpp>
#include <libmm-gio/proxyresolver.hpp>
#include <libmm-gio/remoteactiongroup.hpp>
#include <libmm-gio/resolver.hpp>
#include <libmm-gio/resource.hpp>
#include <libmm-gio/seekable.hpp>
#include <libmm-gio/settings.hpp>
#include <libmm-gio/settingsschema.hpp>
#include <libmm-gio/settingsschemakey.hpp>
#include <libmm-gio/settingsschemasource.hpp>
#include <libmm-gio/simpleaction.hpp>
#include <libmm-gio/simpleactiongroup.hpp>
#include <libmm-gio/simpleiostream.hpp>
#include <libmm-gio/simplepermission.hpp>
#include <libmm-gio/socket.hpp>
#include <libmm-gio/socketaddress.hpp>
#include <libmm-gio/socketaddressenumerator.hpp>
#include <libmm-gio/socketclient.hpp>
#include <libmm-gio/socketconnectable.hpp>
#include <libmm-gio/socketconnection.hpp>
#include <libmm-gio/socketcontrolmessage.hpp>
#include <libmm-gio/socketlistener.hpp>
#include <libmm-gio/socketservice.hpp>
#include <libmm-gio/srvtarget.hpp>
#include <libmm-gio/tcpconnection.hpp>
#include <libmm-gio/tcpwrapperconnection.hpp>
#include <libmm-gio/themedicon.hpp>
#include <libmm-gio/threadedsocketservice.hpp>
#include <libmm-gio/tlscertificate.hpp>
#include <libmm-gio/tlsclientconnection.hpp>
#include <libmm-gio/tlsconnection.hpp>
#include <libmm-gio/tlsdatabase.hpp>
#include <libmm-gio/tlsinteraction.hpp>
#include <libmm-gio/tlspassword.hpp>
#include <libmm-gio/tlsserverconnection.hpp>
#ifndef G_OS_WIN32
#include <libmm-gio/unixconnection.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixcredentialsmessage.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixfdlist.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixfdmessage.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixinputstream.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixoutputstream.hpp>
#endif // ifndef G_OS_WIN32
#ifndef G_OS_WIN32
#include <libmm-gio/unixsocketaddress.hpp>
#endif // ifndef G_OS_WIN32
#include <libmm-gio/volume.hpp>
#include <libmm-gio/volumemonitor.hpp>
#include <libmm-gio/zlibcompressor.hpp>
#include <libmm-gio/zlibdecompressor.hpp>

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

