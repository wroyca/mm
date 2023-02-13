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

#include <libmm-glib/mm-glib.hpp>

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
#include <libmm-gio/contenttype.hpp>
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
#endif
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
#endif
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
#include <libmm-gio/init.hpp>
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
#include <libmm-gio/socketsource.hpp>
#include <libmm-gio/srvtarget.hpp>
#include <libmm-gio/tcpconnection.hpp>
#include <libmm-gio/tcpwrapperconnection.hpp>
#include <libmm-gio/themedicon.hpp>
#include <libmm-gio/threadedsocketservice.hpp>
#include <libmm-gio/tlscertificate.hpp>
#include <libmm-gio/tlsclientconnection.hpp>
#include <libmm-gio/tlsclientconnectionimpl.hpp>
#include <libmm-gio/tlsconnection.hpp>
#include <libmm-gio/tlsdatabase.hpp>
#include <libmm-gio/tlsinteraction.hpp>
#include <libmm-gio/tlspassword.hpp>
#include <libmm-gio/tlsserverconnection.hpp>
#include <libmm-gio/tlsserverconnectionimpl.hpp>
#ifndef G_OS_WIN32
#include <libmm-gio/unixconnection.hpp>
#include <libmm-gio/unixcredentialsmessage.hpp>
#include <libmm-gio/unixfdlist.hpp>
#include <libmm-gio/unixfdmessage.hpp>
#include <libmm-gio/unixinputstream.hpp>
#include <libmm-gio/unixoutputstream.hpp>
#include <libmm-gio/unixsocketaddress.hpp>
#endif
#include <libmm-gio/volume.hpp>
#include <libmm-gio/volumemonitor.hpp>
#include <libmm-gio/zlibcompressor.hpp>
#include <libmm-gio/zlibdecompressor.hpp>

#endif /* #ifndef _GIOMM_H */
