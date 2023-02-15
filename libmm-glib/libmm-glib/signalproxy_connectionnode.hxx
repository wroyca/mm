// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_SIGNALPROXY_CONNECTIONNODE_H
#define _GLIBMM_SIGNALPROXY_CONNECTIONNODE_H

#include <libmm-glib/mm-glibconfig.hxx>

#include <glib.h>
#include <sigc++/sigc++.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GObject = struct _GObject;
using GClosure = struct _GClosure;
#endif

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class GLIBMM_API SignalProxyConnectionNode : public sigc::notifiable
  {
  public:
    SignalProxyConnectionNode (const sigc::slot_base& slot, GObject* gobject);

    SignalProxyConnectionNode (sigc::slot_base&& slot, GObject* gobject);

    static auto
    notify (sigc::notifiable* data) -> void;

    static auto
    destroy_notify_handler (gpointer data, GClosure* closure) -> void;

    gulong connection_id_;
    sigc::slot_base slot_;

  protected:
    GObject* object_;
  };

#endif

} // namespace Glib

#endif
