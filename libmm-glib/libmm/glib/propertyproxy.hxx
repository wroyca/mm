// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_PROPERTYPROXY_H
#define _GLIBMM_PROPERTYPROXY_H

#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/propertyproxy_base.hxx>

namespace glib
{

  template <class T>
  class PropertyProxy : public PropertyProxy_Base
  {
  public:
    using PropertyType = T;

    PropertyProxy (ObjectBase* obj, const char* name)
      : PropertyProxy_Base (obj, name)
    {
    }

    auto
    set_value (const PropertyType& data) -> void;

    auto
    get_value () const -> PropertyType;

    auto
    reset_value () -> void
    {
      reset_property_ ();
    }

    auto
    operator= (const PropertyType& data) -> PropertyProxy<T>&
    {
      this->set_value (data);
      return *this;
    }

    operator PropertyType () const
    {
      return this->get_value ();
    }
  };

  template <class T>
  class PropertyProxy_WriteOnly : public PropertyProxy_Base
  {
  public:
    using PropertyType = T;

    PropertyProxy_WriteOnly (ObjectBase* obj, const char* name)
      : PropertyProxy_Base (obj, name)
    {
    }

    auto
    set_value (const PropertyType& data) -> void;

    auto
    reset_value () -> void
    {
      reset_property_ ();
    }

    auto
    operator= (const PropertyType& data) -> PropertyProxy_WriteOnly<T>&
    {
      this->set_value (data);
      return *this;
    }
  };

  template <class T>
  class PropertyProxy_ReadOnly : public PropertyProxy_Base
  {
  public:
    using PropertyType = T;

    PropertyProxy_ReadOnly (const ObjectBase* obj, const char* name)
      : PropertyProxy_Base (const_cast<ObjectBase*> (obj), name)
    {
    }

    auto
    get_value () const -> PropertyType;

    operator PropertyType () const
    {
      return this->get_value ();
    }
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T>
  auto
  PropertyProxy<T>::set_value (const T& data) -> void
  {
    glib::Value<T> value;
    value.init (glib::Value<T>::value_type ());

    value.set (data);
    set_property_ (value);
  }

  template <class T>
  auto
  PropertyProxy<T>::get_value () const -> T
  {
    glib::Value<T> value;
    value.init (glib::Value<T>::value_type ());

    get_property_ (value);
    return value.get ();
  }

  template <class T>
  auto
  PropertyProxy_WriteOnly<T>::set_value (const T& data) -> void
  {
    glib::Value<T> value;
    value.init (glib::Value<T>::value_type ());

    value.set (data);
    set_property_ (value);
  }

  template <class T>
  auto
  PropertyProxy_ReadOnly<T>::get_value () const -> T
  {
    glib::Value<T> value;
    value.init (glib::Value<T>::value_type ());

    get_property_ (value);
    return value.get ();
  }

#endif

} // namespace glib

#endif
