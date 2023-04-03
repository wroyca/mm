// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_PROPERTYPROXY_BASE_H
#define _GLIBMM_PROPERTYPROXY_BASE_H

#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/signalproxy.hxx>
#include <libmm/glib/value.hxx>

namespace Glib
{

  class LIBMM_GLIB_SYMEXPORT ObjectBase;

  class LIBMM_GLIB_SYMEXPORT SignalProxyProperty : public SignalProxyBase
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

  class LIBMM_GLIB_SYMEXPORT PropertyProxy_Base
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
    auto
    set_property_ (const Glib::ValueBase& value) -> void;
    auto
    get_property_ (Glib::ValueBase& value) const -> void;
    auto
    reset_property_ () -> void;

    ObjectBase* obj_;

    const char* property_name_;

  private:
    auto
    operator= (const PropertyProxy_Base&) -> PropertyProxy_Base&;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class LIBMM_GLIB_SYMEXPORT SignalProxyProperty;

  class LIBMM_GLIB_SYMEXPORT PropertyProxyConnectionNode
    : public SignalProxyConnectionNode
  {
  public:
    friend class SignalProxyProperty;

    PropertyProxyConnectionNode (const sigc::slot_base& slot, GObject* gobject);

    PropertyProxyConnectionNode (sigc::slot_base&& slot, GObject* gobject);

    auto
    connect_changed (const Glib::ustring& property_name) -> sigc::connection;

    static auto
    callback (GObject* object, GParamSpec* pspec, gpointer data) -> void;
  };

#endif

} // namespace Glib

#endif
