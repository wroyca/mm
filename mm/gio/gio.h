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

#include <mm/glib/mm-glib.h>

#include <mm/gio/action.h>
#include <mm/gio/actiongroup.h>
#include <mm/gio/actionmap.h>
#include <mm/gio/appinfo.h>
#include <mm/gio/appinfomonitor.h>
#include <mm/gio/applaunchcontext.h>
#include <mm/gio/application.h>
#include <mm/gio/applicationcommandline.h>
#include <mm/gio/asyncinitable.h>
#include <mm/gio/asyncresult.h>
#include <mm/gio/bufferedinputstream.h>
#include <mm/gio/bufferedoutputstream.h>
#include <mm/gio/cancellable.h>
#include <mm/gio/charsetconverter.h>
#include <mm/gio/contenttype.h>
#include <mm/gio/converter.h>
#include <mm/gio/converterinputstream.h>
#include <mm/gio/converteroutputstream.h>
#include <mm/gio/credentials.h>
#include <mm/gio/datainputstream.h>
#include <mm/gio/dataoutputstream.h>
#include <mm/gio/dbusactiongroup.h>
#include <mm/gio/dbusaddress.h>
#include <mm/gio/dbusauthobserver.h>
#include <mm/gio/dbusconnection.h>
#include <mm/gio/dbuserror.h>
#include <mm/gio/dbuserrorutils.h>
#include <mm/gio/dbusinterface.h>
#include <mm/gio/dbusinterfaceskeleton.h>
#include <mm/gio/dbusinterfacevtable.h>
#include <mm/gio/dbusintrospection.h>
#include <mm/gio/dbusmenumodel.h>
#include <mm/gio/dbusmessage.h>
#include <mm/gio/dbusmethodinvocation.h>
#include <mm/gio/dbusobject.h>
#include <mm/gio/dbusobjectmanager.h>
#include <mm/gio/dbusobjectmanagerclient.h>
#include <mm/gio/dbusobjectmanagerserver.h>
#include <mm/gio/dbusobjectproxy.h>
#include <mm/gio/dbusobjectskeleton.h>
#include <mm/gio/dbusownname.h>
#include <mm/gio/dbusproxy.h>
#include <mm/gio/dbusserver.h>
#include <mm/gio/dbussubtreevtable.h>
#include <mm/gio/dbusutils.h>
#include <mm/gio/dbuswatchname.h>
#if !defined(G_OS_WIN32) && !defined(GLIBMM_OS_COCOA)
#include <mm/gio/desktopappinfo.h>
#endif
#include <mm/gio/drive.h>
#include <mm/gio/emblem.h>
#include <mm/gio/emblemedicon.h>
#include <mm/gio/enums.h>
#include <mm/gio/error.h>
#include <mm/gio/file.h>
#include <mm/gio/fileattributeinfo.h>
#include <mm/gio/fileattributeinfolist.h>
#ifndef G_OS_WIN32
#include <mm/gio/filedescriptorbased.h>
#endif
#include <mm/gio/fileenumerator.h>
#include <mm/gio/fileicon.h>
#include <mm/gio/fileinfo.h>
#include <mm/gio/fileinputstream.h>
#include <mm/gio/fileiostream.h>
#include <mm/gio/filemonitor.h>
#include <mm/gio/filenamecompleter.h>
#include <mm/gio/fileoutputstream.h>
#include <mm/gio/filterinputstream.h>
#include <mm/gio/filteroutputstream.h>
#include <mm/gio/icon.h>
#include <mm/gio/inetaddress.h>
#include <mm/gio/inetsocketaddress.h>
#include <mm/gio/init.h>
#include <mm/gio/initable.h>
#include <mm/gio/inputstream.h>
#include <mm/gio/iostream.h>
#include <mm/gio/listmodel.h>
#include <mm/gio/liststore.h>
#include <mm/gio/loadableicon.h>
#include <mm/gio/memoryinputstream.h>
#include <mm/gio/memoryoutputstream.h>
#include <mm/gio/menu.h>
#include <mm/gio/menuattributeiter.h>
#include <mm/gio/menuitem.h>
#include <mm/gio/menulinkiter.h>
#include <mm/gio/menumodel.h>
#include <mm/gio/mount.h>
#include <mm/gio/mountoperation.h>
#include <mm/gio/networkaddress.h>
#include <mm/gio/networkmonitor.h>
#include <mm/gio/networkservice.h>
#include <mm/gio/notification.h>
#include <mm/gio/outputstream.h>
#include <mm/gio/permission.h>
#include <mm/gio/pollableinputstream.h>
#include <mm/gio/pollableoutputstream.h>
#include <mm/gio/propertyaction.h>
#include <mm/gio/proxy.h>
#include <mm/gio/proxyaddress.h>
#include <mm/gio/proxyresolver.h>
#include <mm/gio/remoteactiongroup.h>
#include <mm/gio/resolver.h>
#include <mm/gio/resource.h>
#include <mm/gio/seekable.h>
#include <mm/gio/settings.h>
#include <mm/gio/settingsschema.h>
#include <mm/gio/settingsschemakey.h>
#include <mm/gio/settingsschemasource.h>
#include <mm/gio/simpleaction.h>
#include <mm/gio/simpleactiongroup.h>
#include <mm/gio/simpleiostream.h>
#include <mm/gio/simplepermission.h>
#include <mm/gio/socket.h>
#include <mm/gio/socketaddress.h>
#include <mm/gio/socketaddressenumerator.h>
#include <mm/gio/socketclient.h>
#include <mm/gio/socketconnectable.h>
#include <mm/gio/socketconnection.h>
#include <mm/gio/socketcontrolmessage.h>
#include <mm/gio/socketlistener.h>
#include <mm/gio/socketservice.h>
#include <mm/gio/socketsource.h>
#include <mm/gio/srvtarget.h>
#include <mm/gio/tcpconnection.h>
#include <mm/gio/tcpwrapperconnection.h>
#include <mm/gio/themedicon.h>
#include <mm/gio/threadedsocketservice.h>
#include <mm/gio/tlscertificate.h>
#include <mm/gio/tlsclientconnection.h>
#include <mm/gio/tlsclientconnectionimpl.h>
#include <mm/gio/tlsconnection.h>
#include <mm/gio/tlsdatabase.h>
#include <mm/gio/tlsinteraction.h>
#include <mm/gio/tlspassword.h>
#include <mm/gio/tlsserverconnection.h>
#include <mm/gio/tlsserverconnectionimpl.h>
#ifndef G_OS_WIN32
#include <mm/gio/unixconnection.h>
#include <mm/gio/unixcredentialsmessage.h>
#include <mm/gio/unixfdlist.h>
#include <mm/gio/unixfdmessage.h>
#include <mm/gio/unixinputstream.h>
#include <mm/gio/unixoutputstream.h>
#include <mm/gio/unixsocketaddress.h>
#endif
#include <mm/gio/volume.h>
#include <mm/gio/volumemonitor.h>
#include <mm/gio/zlibcompressor.h>
#include <mm/gio/zlibdecompressor.h>

#endif /* #ifndef _GIOMM_H */
