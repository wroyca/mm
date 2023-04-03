// SPDX-License-Identifier: LGPL-2.1-or-later

#include <glib-object.h>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/signalproxy.hxx>

namespace Glib
{

  SignalProxyBase::SignalProxyBase (ObjectBase* obj)
    : obj_ (obj)
  {
  }

  SignalProxyNormal::SignalProxyNormal (ObjectBase* obj,
                                        const SignalProxyInfo* info)
    : SignalProxyBase (obj),
      info_ (info)
  {
  }

  SignalProxyNormal::~SignalProxyNormal () noexcept = default;

  auto
  SignalProxyNormal::connect_impl_ (const bool notify,
                                    const sigc::slot_base& slot,
                                    const bool after) -> sigc::slot_base&
  {
    const auto pConnectionNode = new SignalProxyConnectionNode (slot,
                                                                obj_->gobj ());

    pConnectionNode->connection_id_ = g_signal_connect_data (
        obj_->gobj (),
        info_->signal_name,
        notify ? info_->notify_callback : info_->callback,
        pConnectionNode,
        &SignalProxyConnectionNode::destroy_notify_handler,
        static_cast<GConnectFlags> (after ? G_CONNECT_AFTER : 0));

    return pConnectionNode->slot_;
  }

  auto
  SignalProxyNormal::connect_impl_ (const bool notify,
                                    sigc::slot_base&& slot,
                                    const bool after) -> sigc::slot_base&
  {
    const auto pConnectionNode =
        new SignalProxyConnectionNode (std::move (slot), obj_->gobj ());

    pConnectionNode->connection_id_ = g_signal_connect_data (
        obj_->gobj (),
        info_->signal_name,
        notify ? info_->notify_callback : info_->callback,
        pConnectionNode,
        &SignalProxyConnectionNode::destroy_notify_handler,
        static_cast<GConnectFlags> (after ? G_CONNECT_AFTER : 0));

    return pConnectionNode->slot_;
  }

  auto
  SignalProxyNormal::emission_stop () -> void
  {
    g_signal_stop_emission_by_name (obj_->gobj (), info_->signal_name);
  }

  auto
  SignalProxyNormal::slot0_void_callback (GObject* self, void* data) -> void
  {
    if (ObjectBase::_get_current_wrapper (self))
    {
      try
      {
        if (sigc::slot_base* const slot = data_to_slot (data))
          (*static_cast<sigc::slot<void ()>*> (slot)) ();
      }
      catch (...)
      {
        exception_handlers_invoke ();
      }
    }
  }

  SignalProxyDetailedBase::SignalProxyDetailedBase (ObjectBase* obj,
                                                    const SignalProxyInfo* info,
                                                    const ustring& detail_name)
    : SignalProxyBase (obj),
      info_ (info),
      detailed_name_ (ustring (info->signal_name) +
                      (detail_name.empty () ? ustring () : "::" + detail_name))
  {
  }

  SignalProxyDetailedBase::~SignalProxyDetailedBase () noexcept = default;

  auto
  SignalProxyDetailedBase::connect_impl_ (const bool notify,
                                          const sigc::slot_base& slot,
                                          const bool after) -> sigc::slot_base&
  {
    const auto pConnectionNode = new SignalProxyConnectionNode (slot,
                                                                obj_->gobj ());

    pConnectionNode->connection_id_ = g_signal_connect_data (
        obj_->gobj (),
        detailed_name_.c_str (),
        notify ? info_->notify_callback : info_->callback,
        pConnectionNode,
        &SignalProxyConnectionNode::destroy_notify_handler,
        static_cast<GConnectFlags> (after ? G_CONNECT_AFTER : 0));

    return pConnectionNode->slot_;
  }

  auto
  SignalProxyDetailedBase::connect_impl_ (const bool notify,
                                          sigc::slot_base&& slot,
                                          const bool after) -> sigc::slot_base&
  {
    const auto pConnectionNode =
        new SignalProxyConnectionNode (std::move (slot), obj_->gobj ());

    pConnectionNode->connection_id_ = g_signal_connect_data (
        obj_->gobj (),
        detailed_name_.c_str (),
        notify ? info_->notify_callback : info_->callback,
        pConnectionNode,
        &SignalProxyConnectionNode::destroy_notify_handler,
        static_cast<GConnectFlags> (after ? G_CONNECT_AFTER : 0));

    return pConnectionNode->slot_;
  }

  auto
  SignalProxyDetailedBase::emission_stop () -> void
  {
    g_signal_stop_emission_by_name (obj_->gobj (), detailed_name_.c_str ());
  }

} // namespace Glib
