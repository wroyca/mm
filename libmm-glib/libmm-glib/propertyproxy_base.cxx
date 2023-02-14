// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/propertyproxy_base.hxx>

#include <libmm-glib/object.hxx>
#include <libmm-glib/object_p.hxx>
#include <libmm-glib/signalproxy_connectionnode.hxx>
#include <utility>

namespace Glib
{

  PropertyProxyConnectionNode::PropertyProxyConnectionNode (
      const sigc::slot_base& slot,
      GObject* gobject)
    : SignalProxyConnectionNode (slot, gobject)
  {
  }

  PropertyProxyConnectionNode::PropertyProxyConnectionNode (
      sigc::slot_base&& slot,
      GObject* gobject)
    : SignalProxyConnectionNode (std::move (slot), gobject)
  {
  }

  static auto
  get_detailed_signal_name (const ustring& signal_name, const ustring& detail) -> ustring
  {
    if (detail.empty ())
      return signal_name;

    return signal_name + "::" + detail;
  }

  auto
  PropertyProxyConnectionNode::connect_changed (const ustring& property_name) -> sigc::connection
  {
    const ustring notify_signal_name = get_detailed_signal_name ("notify",
                                                                 property_name);
    connection_id_ = g_signal_connect_data (
        object_,
        notify_signal_name.c_str (),
        (GCallback) &PropertyProxyConnectionNode::callback,
        this,
        &PropertyProxyConnectionNode::destroy_notify_handler,
        G_CONNECT_AFTER);

    return sigc::connection (slot_);
  }

  auto
  PropertyProxyConnectionNode::callback (GObject*,
                                         GParamSpec* pspec,
                                         const gpointer data) -> void
  {
    if (pspec && data)
    {
      if (sigc::slot_base* const slot = SignalProxyBase::data_to_slot (data))
        (*static_cast<sigc::slot<void ()>*> (slot)) ();
    }
  }

  SignalProxyProperty::SignalProxyProperty (ObjectBase* obj,
                                            const gchar* property_name)
    : SignalProxyBase (obj),
      property_name_ (property_name)
  {
  }

  SignalProxyProperty::~SignalProxyProperty () noexcept = default;

  auto
  SignalProxyProperty::connect (const SlotType& slot) -> sigc::connection
  {
    const auto pConnectionNode =
        new PropertyProxyConnectionNode (slot, obj_->gobj ());

    return pConnectionNode->connect_changed (property_name_);
  }

  auto
  SignalProxyProperty::connect (SlotType&& slot) -> sigc::connection
  {
    const auto pConnectionNode =
        new PropertyProxyConnectionNode (std::move (slot), obj_->gobj ());

    return pConnectionNode->connect_changed (property_name_);
  }

  PropertyProxy_Base::PropertyProxy_Base (ObjectBase* obj,
                                          const char* property_name)
    : obj_ (obj),
      property_name_ (property_name)
  {
  }

  PropertyProxy_Base::PropertyProxy_Base (const PropertyProxy_Base& other) =
      default;

  auto
  PropertyProxy_Base::signal_changed () -> SignalProxyProperty
  {
    return {obj_, property_name_};
  }

  auto
  PropertyProxy_Base::set_property_ (const ValueBase& value) -> void
  {
    g_object_set_property (obj_->gobj (), property_name_, value.gobj ());
  }

  auto
  PropertyProxy_Base::get_property_ (ValueBase& value) const -> void
  {
    g_object_get_property (obj_->gobj (), property_name_, value.gobj ());
  }

  auto
  PropertyProxy_Base::reset_property_ () -> void
  {
    const GParamSpec* const pParamSpec = g_object_class_find_property (
        G_OBJECT_GET_CLASS (obj_->gobj ()),
        property_name_);

    g_return_if_fail (pParamSpec != nullptr);

    ValueBase value;
    value.init (G_PARAM_SPEC_VALUE_TYPE (pParamSpec));

    g_object_set_property (obj_->gobj (), property_name_, value.gobj ());
  }

} // namespace Glib
