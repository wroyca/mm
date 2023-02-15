#ifndef _GIOMM_H
#define _GIOMM_H

/*
 * Copyright (C) 2007 The giomm Development Team
 *
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

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/action.hxx>
#include <libmm-gio/actiongroup.hxx>
#include <libmm-gio/actionmap.hxx>
#include <libmm-gio/appinfo.hxx>
#include <libmm-gio/appinfomonitor.hxx>
#include <libmm-gio/applaunchcontext.hxx>
#include <libmm-gio/application.hxx>
#include <libmm-gio/applicationcommandline.hxx>
#include <libmm-gio/asyncinitable.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/bufferedinputstream.hxx>
#include <libmm-gio/bufferedoutputstream.hxx>
#include <libmm-gio/bytesicon.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-gio/charsetconverter.hxx>
#include <libmm-gio/contenttype.hxx>
#include <libmm-gio/converter.hxx>
#include <libmm-gio/converterinputstream.hxx>
#include <libmm-gio/converteroutputstream.hxx>
#include <libmm-gio/credentials.hxx>
#include <libmm-gio/datainputstream.hxx>
#include <libmm-gio/dataoutputstream.hxx>
#include <libmm-gio/dbusactiongroup.hxx>
#include <libmm-gio/dbusaddress.hxx>
#include <libmm-gio/dbusauthobserver.hxx>
#include <libmm-gio/dbusconnection.hxx>
#include <libmm-gio/dbuserror.hxx>
#include <libmm-gio/dbuserrorutils.hxx>
#include <libmm-gio/dbusinterface.hxx>
#include <libmm-gio/dbusinterfaceskeleton.hxx>
#include <libmm-gio/dbusinterfacevtable.hxx>
#include <libmm-gio/dbusintrospection.hxx>
#include <libmm-gio/dbusmenumodel.hxx>
#include <libmm-gio/dbusmessage.hxx>
#include <libmm-gio/dbusmethodinvocation.hxx>
#include <libmm-gio/dbusobject.hxx>
#include <libmm-gio/dbusobjectmanager.hxx>
#include <libmm-gio/dbusobjectmanagerclient.hxx>
#include <libmm-gio/dbusobjectmanagerserver.hxx>
#include <libmm-gio/dbusobjectproxy.hxx>
#include <libmm-gio/dbusobjectskeleton.hxx>
#include <libmm-gio/dbusownname.hxx>
#include <libmm-gio/dbusproxy.hxx>
#include <libmm-gio/dbusserver.hxx>
#include <libmm-gio/dbussubtreevtable.hxx>
#include <libmm-gio/dbusutils.hxx>
#include <libmm-gio/dbuswatchname.hxx>
// #if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
// #include <libmm-gio/desktopappinfo.hxx>
// #endif
#include <libmm-gio/drive.hxx>
#include <libmm-gio/emblem.hxx>
#include <libmm-gio/emblemedicon.hxx>
#include <libmm-gio/enums.hxx>
#include <libmm-gio/error.hxx>
#include <libmm-gio/file.hxx>
#include <libmm-gio/fileattributeinfo.hxx>
#include <libmm-gio/fileattributeinfolist.hxx>
#ifndef G_OS_WIN32
#include <libmm-gio/filedescriptorbased.hxx>
#endif
#include <libmm-gio/fileenumerator.hxx>
#include <libmm-gio/fileicon.hxx>
#include <libmm-gio/fileinfo.hxx>
#include <libmm-gio/fileinputstream.hxx>
#include <libmm-gio/fileiostream.hxx>
#include <libmm-gio/filemonitor.hxx>
#include <libmm-gio/filenamecompleter.hxx>
#include <libmm-gio/fileoutputstream.hxx>
#include <libmm-gio/filterinputstream.hxx>
#include <libmm-gio/filteroutputstream.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/inetaddress.hxx>
#include <libmm-gio/inetsocketaddress.hxx>
#include <libmm-gio/init.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/iostream.hxx>
#include <libmm-gio/listmodel.hxx>
#include <libmm-gio/liststore.hxx>
#include <libmm-gio/loadableicon.hxx>
#include <libmm-gio/memoryinputstream.hxx>
#include <libmm-gio/memoryoutputstream.hxx>
#include <libmm-gio/menu.hxx>
#include <libmm-gio/menuattributeiter.hxx>
#include <libmm-gio/menuitem.hxx>
#include <libmm-gio/menulinkiter.hxx>
#include <libmm-gio/menumodel.hxx>
#include <libmm-gio/mount.hxx>
#include <libmm-gio/mountoperation.hxx>
#include <libmm-gio/networkaddress.hxx>
#include <libmm-gio/networkmonitor.hxx>
#include <libmm-gio/networkservice.hxx>
#include <libmm-gio/notification.hxx>
#include <libmm-gio/outputstream.hxx>
#include <libmm-gio/permission.hxx>
#include <libmm-gio/pollableinputstream.hxx>
#include <libmm-gio/pollableoutputstream.hxx>
#include <libmm-gio/propertyaction.hxx>
#include <libmm-gio/proxy.hxx>
#include <libmm-gio/proxyaddress.hxx>
#include <libmm-gio/proxyresolver.hxx>
#include <libmm-gio/remoteactiongroup.hxx>
#include <libmm-gio/resolver.hxx>
#include <libmm-gio/resource.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-gio/settings.hxx>
#include <libmm-gio/settingsschema.hxx>
#include <libmm-gio/settingsschemakey.hxx>
#include <libmm-gio/settingsschemasource.hxx>
#include <libmm-gio/simpleaction.hxx>
#include <libmm-gio/simpleactiongroup.hxx>
#include <libmm-gio/simpleiostream.hxx>
#include <libmm-gio/simplepermission.hxx>
#include <libmm-gio/socket.hxx>
#include <libmm-gio/socketaddress.hxx>
#include <libmm-gio/socketaddressenumerator.hxx>
#include <libmm-gio/socketclient.hxx>
#include <libmm-gio/socketconnectable.hxx>
#include <libmm-gio/socketconnection.hxx>
#include <libmm-gio/socketcontrolmessage.hxx>
#include <libmm-gio/socketlistener.hxx>
#include <libmm-gio/socketservice.hxx>
#include <libmm-gio/socketsource.hxx>
#include <libmm-gio/srvtarget.hxx>
#include <libmm-gio/tcpconnection.hxx>
#include <libmm-gio/tcpwrapperconnection.hxx>
#include <libmm-gio/themedicon.hxx>
#include <libmm-gio/threadedsocketservice.hxx>
#include <libmm-gio/tlscertificate.hxx>
#include <libmm-gio/tlsclientconnection.hxx>
#include <libmm-gio/tlsclientconnectionimpl.hxx>
#include <libmm-gio/tlsconnection.hxx>
#include <libmm-gio/tlsdatabase.hxx>
#include <libmm-gio/tlsinteraction.hxx>
#include <libmm-gio/tlspassword.hxx>
#include <libmm-gio/tlsserverconnection.hxx>
#include <libmm-gio/tlsserverconnectionimpl.hxx>
#ifndef G_OS_WIN32
// #include <libmm-gio/unixconnection.hxx>
// #include <libmm-gio/unixcredentialsmessage.hxx>
// #include <libmm-gio/unixfdlist.hxx>
// #include <libmm-gio/unixfdmessage.hxx>
// #include <libmm-gio/unixinputstream.hxx>
// #include <libmm-gio/unixoutputstream.hxx>
// #include <libmm-gio/unixsocketaddress.hxx>
#endif
#include <libmm-gio/volume.hxx>
#include <libmm-gio/volumemonitor.hxx>
#include <libmm-gio/zlibcompressor.hxx>
#include <libmm-gio/zlibdecompressor.hxx>

#endif /* #ifndef _GIOMM_H */
