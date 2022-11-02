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

#include <mm/glib/mm-glib.hpp>

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
#include <mm/gio/contenttype.hpp>
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
#endif
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
#endif
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
#include <mm/gio/init.hpp>
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
#include <mm/gio/socketsource.hpp>
#include <mm/gio/srvtarget.hpp>
#include <mm/gio/tcpconnection.hpp>
#include <mm/gio/tcpwrapperconnection.hpp>
#include <mm/gio/themedicon.hpp>
#include <mm/gio/threadedsocketservice.hpp>
#include <mm/gio/tlscertificate.hpp>
#include <mm/gio/tlsclientconnection.hpp>
#include <mm/gio/tlsclientconnectionimpl.hpp>
#include <mm/gio/tlsconnection.hpp>
#include <mm/gio/tlsdatabase.hpp>
#include <mm/gio/tlsinteraction.hpp>
#include <mm/gio/tlspassword.hpp>
#include <mm/gio/tlsserverconnection.hpp>
#include <mm/gio/tlsserverconnectionimpl.hpp>
#ifndef G_OS_WIN32
#include <mm/gio/unixconnection.hpp>
#include <mm/gio/unixcredentialsmessage.hpp>
#include <mm/gio/unixfdlist.hpp>
#include <mm/gio/unixfdmessage.hpp>
#include <mm/gio/unixinputstream.hpp>
#include <mm/gio/unixoutputstream.hpp>
#include <mm/gio/unixsocketaddress.hpp>
#endif
#include <mm/gio/volume.hpp>
#include <mm/gio/volumemonitor.hpp>
#include <mm/gio/zlibcompressor.hpp>
#include <mm/gio/zlibdecompressor.hpp>

#endif /* #ifndef _GIOMM_H */
