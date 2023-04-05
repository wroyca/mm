// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/object.hxx>
#include <libmm/glib/signalproxy_connectionnode.hxx>
#include <utility>

namespace glib
{

  SignalProxyConnectionNode::SignalProxyConnectionNode (
      const sigc::slot_base& slot,
      GObject* gobject)
    : connection_id_ (0),
      slot_ (slot),
      object_ (gobject)
  {
    slot_.set_parent (this, &SignalProxyConnectionNode::notify);
  }

  SignalProxyConnectionNode::SignalProxyConnectionNode (sigc::slot_base&& slot,
                                                        GObject* gobject)
    : connection_id_ (0),
      slot_ (std::move (slot)),
      object_ (gobject)
  {
    slot_.set_parent (this, &SignalProxyConnectionNode::notify);
  }

  auto
  SignalProxyConnectionNode::notify (notifiable* data) -> void
  {
    SignalProxyConnectionNode* conn =
        static_cast<SignalProxyConnectionNode*> (data);

    if (conn && conn->object_)
    {
      GObject* o = conn->object_;
      conn->object_ = nullptr;

      if (g_signal_handler_is_connected (o, conn->connection_id_))
      {
        const gulong connection_id = conn->connection_id_;
        conn->connection_id_ = 0;

        g_signal_handler_disconnect (o, connection_id);
      }
    }
  }

  auto
  SignalProxyConnectionNode::destroy_notify_handler (const gpointer data,
                                                     GClosure*) -> void
  {
    SignalProxyConnectionNode* conn =
        static_cast<SignalProxyConnectionNode*> (data);

    if (conn)
    {
      conn->object_ = nullptr;

      delete conn;
    }
  }

} // namespace glib
