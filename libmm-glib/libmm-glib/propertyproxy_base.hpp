#ifndef _GLIBMM_PROPERTYPROXY_BASE_H
#define _GLIBMM_PROPERTYPROXY_BASE_H

/* propertyproxy_base.h
 *
 * Copyright 2002 The gtkmm Development Team
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

#include <libmm-glib/mm-glibconfig.hpp>
#include <libmm-glib/value.hpp>
#include <libmm-glib/signalproxy.hpp>

namespace Glib
{

class GLIBMM_API ObjectBase;

/// Use the connect() method, with sigc::ptr_fun() or sigc::mem_fun() to connect signals to signal
/// handlers.
class GLIBMM_API SignalProxyProperty : public SignalProxyBase
{
public:
  friend class PropertyProxy_Base;

  SignalProxyProperty(Glib::ObjectBase* obj, const gchar* property_name);
  ~SignalProxyProperty() noexcept;

  using SlotType = sigc::slot<void()>;
  auto connect(const SlotType& slot) -> sigc::connection;
  /** @newin{2,48}
   */
  auto connect(SlotType&& slot) -> sigc::connection;

protected:
  const char* property_name_; // Should be a static string literal.

private:
  auto operator=(const SignalProxyProperty&) -> SignalProxyProperty&; // not implemented
};

class GLIBMM_API PropertyProxy_Base
{
public:
  PropertyProxy_Base(ObjectBase* obj, const char* property_name);
  PropertyProxy_Base(const PropertyProxy_Base& other);

  /// This signal will be emitted when the property changes.
  auto signal_changed() -> SignalProxyProperty;

  auto get_object() const -> ObjectBase* { return obj_; }
  auto get_name() const -> const char* { return property_name_; }

protected:
  void set_property_(const Glib::ValueBase& value);
  void get_property_(Glib::ValueBase& value) const;
  void reset_property_();

  ObjectBase* obj_; // The C++ wrapper instance of which this PropertyProxy is a member.

  const char* property_name_; // Should be a static string literal.

private:
  // Declared as private, but not implemented to prevent any automatically generated implementation.
  auto operator=(const PropertyProxy_Base&) -> PropertyProxy_Base&;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class GLIBMM_API SignalProxyProperty;

/** PropertyProxyConnectionNode is a connection node for use with SignalProxyProperty.
  * It's like SignalProxyConnectionNode, but it contains the property name too.
  * This is not public API.
  */
class GLIBMM_API PropertyProxyConnectionNode : public SignalProxyConnectionNode
{
public:
  friend class SignalProxyProperty;

  PropertyProxyConnectionNode(const sigc::slot_base& slot, GObject* gobject);
  /** @newin{2,48}
   */
  PropertyProxyConnectionNode(sigc::slot_base&& slot, GObject* gobject);

  /** Connect callback() to the notify::property_name signal.
   * It invokes the slot, supplied in the constructor.
   *
   * @newin{2,48}
   */
  auto connect_changed(const Glib::ustring& property_name) -> sigc::connection;

  static void callback(GObject* object, GParamSpec* pspec, gpointer data);
};

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib

#endif /* _GLIBMM_PROPERTYPROXY_BASE_H */
