// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_PROPERTYPROXY_BASE_H
#define _GLIBMM_PROPERTYPROXY_BASE_H

#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/signalproxy.hxx>
#include <libmm-glib/value.hxx>

namespace Glib
{

  class GLIBMM_API ObjectBase;

  class GLIBMM_API SignalProxyProperty : public SignalProxyBase
  {
  public:
    friend class PropertyProxy_Base;

    SignalProxyProperty (Glib::ObjectBase* obj, const gchar* property_name);
    ~SignalProxyProperty () noexcept;

    using SlotType = sigc::slot<void ()>;
    auto
    connect (const SlotType& slot) -> sigc::connection;

    auto
    connect (SlotType&& slot) -> sigc::connection;

  protected:
    const char* property_name_;

  private:
    auto
    operator= (const SignalProxyProperty&) -> SignalProxyProperty&;
  };

  class GLIBMM_API PropertyProxy_Base
  {
  public:
    PropertyProxy_Base (ObjectBase* obj, const char* property_name);
    PropertyProxy_Base (const PropertyProxy_Base& other);

    auto
    signal_changed () -> SignalProxyProperty;

    auto
    get_object () const -> ObjectBase*
    {
      return obj_;
    }

    auto
    get_name () const -> const char*
    {
      return property_name_;
    }

  protected:
    void
    set_property_ (const Glib::ValueBase& value);
    void
    get_property_ (Glib::ValueBase& value) const;
    void
    reset_property_ ();

    ObjectBase* obj_;

    const char* property_name_;

  private:
    auto
    operator= (const PropertyProxy_Base&) -> PropertyProxy_Base&;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class GLIBMM_API SignalProxyProperty;

  class GLIBMM_API PropertyProxyConnectionNode
    : public SignalProxyConnectionNode
  {
  public:
    friend class SignalProxyProperty;

    PropertyProxyConnectionNode (const sigc::slot_base& slot, GObject* gobject);

    PropertyProxyConnectionNode (sigc::slot_base&& slot, GObject* gobject);

    auto
    connect_changed (const Glib::ustring& property_name) -> sigc::connection;

    static void
    callback (GObject* object, GParamSpec* pspec, gpointer data);
  };

#endif

} // namespace Glib

#endif
