// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_PROPERTY_H
#define _GLIBMM_PROPERTY_H

#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/propertyproxy.hxx>
#include <libmm/glib/value.hxx>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  #ifdef GLIBMM_CXX_CAN_USE_NAMESPACES_INSIDE_EXTERNC

  extern "C"
  {
  #endif

    LIBMM_GLIB_SYMEXPORT auto
    custom_get_property_callback (GObject* object,
                                  unsigned int property_id,
                                  GValue* value,
                                  GParamSpec* param_spec) -> void;

    LIBMM_GLIB_SYMEXPORT auto
    custom_set_property_callback (GObject* object,
                                  unsigned int property_id,
                                  const GValue* value,
                                  GParamSpec* param_spec) -> void;

  #ifdef GLIBMM_CXX_CAN_USE_NAMESPACES_INSIDE_EXTERNC
  }
  #endif

#endif

  class LIBMM_GLIB_SYMEXPORT PropertyBase
  {
  public:
    PropertyBase (const PropertyBase&) = delete;
    auto
    operator= (const PropertyBase&) -> PropertyBase& = delete;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_nick () const -> Glib::ustring;

    auto
    get_blurb () const -> Glib::ustring;

    auto
    notify () -> void;

  protected:
    Glib::Object* object_;
    Glib::ValueBase value_;
    GParamSpec* param_spec_;

    PropertyBase (Glib::Object& object, GType value_type);
    ~PropertyBase () noexcept;

    auto
    lookup_property (const Glib::ustring& name) -> bool;

    auto
    install_property (GParamSpec* param_spec) -> void;

    auto
    get_name_internal () const -> const char*;

  private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    friend auto
    Glib::custom_get_property_callback (GObject* object,
                                        unsigned int property_id,
                                        GValue* value,
                                        GParamSpec* param_spec) -> void;

    friend auto
    Glib::custom_set_property_callback (GObject* object,
                                        unsigned int property_id,
                                        const GValue* value,
                                        GParamSpec* param_spec) -> void;

#endif
  };

  template <class T>
  class Property : public PropertyBase
  {
  public:
    using PropertyType = T;
    using ValueType = Glib::Value<T>;

    Property (Glib::Object& object, const Glib::ustring& name);

    Property (Glib::Object& object,
              const Glib::ustring& name,
              const PropertyType& default_value);

    Property (Glib::Object& object,
              const Glib::ustring& name,
              const Glib::ustring& nick,
              const Glib::ustring& blurb,
              Glib::ParamFlags flags);

    Property (Glib::Object& object,
              const Glib::ustring& name,
              const PropertyType& default_value,
              const Glib::ustring& nick,
              const Glib::ustring& blurb,
              Glib::ParamFlags flags);

    inline auto
    set_value (const PropertyType& data) -> void;

    inline auto
    get_value () const -> PropertyType;

    inline auto
    operator= (const PropertyType& data) -> Property<T>&;

    inline operator PropertyType () const;

    inline auto
    get_proxy () -> Glib::PropertyProxy<T>;

    inline auto
    get_proxy () const -> Glib::PropertyProxy_ReadOnly<T>;
  };

  template <class T>
  class Property_ReadOnly : public PropertyBase
  {
  public:
    typedef T PropertyType;
    typedef Glib::Value<T> ValueType;

    Property_ReadOnly (Glib::Object& object, const Glib::ustring& name);

    Property_ReadOnly (Glib::Object& object,
                       const Glib::ustring& name,
                       const PropertyType& default_value);

    Property_ReadOnly (Glib::Object& object,
                       const Glib::ustring& name,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags);

    Property_ReadOnly (Glib::Object& object,
                       const Glib::ustring& name,
                       const PropertyType& default_value,
                       const Glib::ustring& nick,
                       const Glib::ustring& blurb,
                       Glib::ParamFlags flags);

    inline auto
    get_value () const -> PropertyType;

    inline operator PropertyType () const;

    inline auto
    get_proxy () const -> Glib::PropertyProxy_ReadOnly<T>;
  };

  template <class T>
  class Property_WriteOnly : public PropertyBase
  {
  public:
    typedef T PropertyType;
    typedef Glib::Value<T> ValueType;

    Property_WriteOnly (Glib::Object& object, const Glib::ustring& name);

    Property_WriteOnly (Glib::Object& object,
                        const Glib::ustring& name,
                        const PropertyType& default_value);

    Property_WriteOnly (Glib::Object& object,
                        const Glib::ustring& name,
                        const Glib::ustring& nick,
                        const Glib::ustring& blurb,
                        Glib::ParamFlags flags);

    Property_WriteOnly (Glib::Object& object,
                        const Glib::ustring& name,
                        const PropertyType& default_value,
                        const Glib::ustring& nick,
                        const Glib::ustring& blurb,
                        Glib::ParamFlags flags);

    inline auto
    set_value (const PropertyType& data) -> void;

    inline auto
    operator= (const PropertyType& data) -> Property_WriteOnly<T>&;

    inline auto
    get_proxy () -> Glib::PropertyProxy_WriteOnly<T>;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T>
  Property<T>::Property (Glib::Object& object, const Glib::ustring& name)
    : Property (object,
                name,
                Glib::ustring (),
                Glib::ustring (),
                Glib::ParamFlags::READWRITE)
  {
  }

  template <class T>
  Property<T>::Property (
      Glib::Object& object,
      const Glib::ustring& name,
      const typename Property<T>::PropertyType& default_value)
    : Property (object,
                name,
                default_value,
                Glib::ustring (),
                Glib::ustring (),
                Glib::ParamFlags::READWRITE)
  {
  }

  template <class T>
  Property<T>::Property (Glib::Object& object,
                         const Glib::ustring& name,
                         const Glib::ustring& nick,
                         const Glib::ustring& blurb,
                         Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::READWRITE;

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  Property<T>::Property (Glib::Object& object,
                         const Glib::ustring& name,
                         const PropertyType& default_value,
                         const Glib::ustring& nick,
                         const Glib::ustring& blurb,
                         Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::READWRITE;

    static_cast<ValueType&> (value_).set (default_value);

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  inline auto
  Property<T>::set_value (const typename Property<T>::PropertyType& data) -> void
  {
    static_cast<ValueType&> (value_).set (data);
    this->notify ();
  }

  template <class T>
  inline auto
  Property<T>::get_value () const -> typename Property<T>::PropertyType
  {
    return static_cast<const ValueType&> (value_).get ();
  }

  template <class T>
  inline auto
  Property<T>::operator= (const typename Property<T>::PropertyType& data) -> Property<T>&
  {
    static_cast<ValueType&> (value_).set (data);
    this->notify ();
    return *this;
  }

  template <class T>
  inline Property<T>::operator T () const
  {
    return static_cast<const ValueType&> (value_).get ();
  }

  template <class T>
  inline auto
  Property<T>::get_proxy () -> Glib::PropertyProxy<T>
  {
    return Glib::PropertyProxy<T> (object_, get_name_internal ());
  }

  template <class T>
  inline auto
  Property<T>::get_proxy () const -> Glib::PropertyProxy_ReadOnly<T>
  {
    return Glib::PropertyProxy_ReadOnly<T> (object_, get_name_internal ());
  }

  template <class T>
  Property_ReadOnly<T>::Property_ReadOnly (Glib::Object& object,
                                           const Glib::ustring& name)
    : Property_ReadOnly (object,
                         name,
                         Glib::ustring (),
                         Glib::ustring (),
                         Glib::ParamFlags::READABLE)
  {
  }

  template <class T>
  Property_ReadOnly<T>::Property_ReadOnly (
      Glib::Object& object,
      const Glib::ustring& name,
      const typename Property_ReadOnly<T>::PropertyType& default_value)
    : Property_ReadOnly (object,
                         name,
                         default_value,
                         Glib::ustring (),
                         Glib::ustring (),
                         Glib::ParamFlags::READABLE)
  {
  }

  template <class T>
  Property_ReadOnly<T>::Property_ReadOnly (Glib::Object& object,
                                           const Glib::ustring& name,
                                           const Glib::ustring& nick,
                                           const Glib::ustring& blurb,
                                           Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::READABLE;
    flags &= ~Glib::ParamFlags::WRITABLE;

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  Property_ReadOnly<T>::Property_ReadOnly (Glib::Object& object,
                                           const Glib::ustring& name,
                                           const PropertyType& default_value,
                                           const Glib::ustring& nick,
                                           const Glib::ustring& blurb,
                                           Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::READABLE;
    flags &= ~Glib::ParamFlags::WRITABLE;

    static_cast<ValueType&> (value_).set (default_value);

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  inline auto
  Property_ReadOnly<T>::get_value () const ->
      typename Property_ReadOnly<T>::PropertyType
  {
    return static_cast<const ValueType&> (value_).get ();
  }

  template <class T>
  inline Property_ReadOnly<T>::operator T () const
  {
    return static_cast<const ValueType&> (value_).get ();
  }

  template <class T>
  inline auto
  Property_ReadOnly<T>::get_proxy () const -> Glib::PropertyProxy_ReadOnly<T>
  {
    return Glib::PropertyProxy_ReadOnly<T> (object_, get_name_internal ());
  }

  template <class T>
  Property_WriteOnly<T>::Property_WriteOnly (Glib::Object& object,
                                             const Glib::ustring& name)
    : Property_WriteOnly (object,
                          name,
                          Glib::ustring (),
                          Glib::ustring (),
                          Glib::ParamFlags::WRITABLE)
  {
  }

  template <class T>
  Property_WriteOnly<T>::Property_WriteOnly (
      Glib::Object& object,
      const Glib::ustring& name,
      const typename Property_WriteOnly<T>::PropertyType& default_value)
    : Property_WriteOnly (object,
                          name,
                          default_value,
                          Glib::ustring (),
                          Glib::ustring (),
                          Glib::ParamFlags::WRITABLE)
  {
  }

  template <class T>
  Property_WriteOnly<T>::Property_WriteOnly (Glib::Object& object,
                                             const Glib::ustring& name,
                                             const Glib::ustring& nick,
                                             const Glib::ustring& blurb,
                                             Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::WRITABLE;
    flags &= ~Glib::ParamFlags::READABLE;

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  Property_WriteOnly<T>::Property_WriteOnly (Glib::Object& object,
                                             const Glib::ustring& name,
                                             const PropertyType& default_value,
                                             const Glib::ustring& nick,
                                             const Glib::ustring& blurb,
                                             Glib::ParamFlags flags)
    : PropertyBase (object, ValueType::value_type ())
  {
    flags |= Glib::ParamFlags::WRITABLE;
    flags &= ~Glib::ParamFlags::READABLE;

    static_cast<ValueType&> (value_).set (default_value);

    if (!lookup_property (name))
      install_property (static_cast<ValueType&> (value_)
                            .create_param_spec (name, nick, blurb, flags));
  }

  template <class T>
  inline auto
  Property_WriteOnly<T>::set_value (
      const typename Property_WriteOnly<T>::PropertyType& data) -> void
  {
    static_cast<ValueType&> (value_).set (data);
    this->notify ();
  }

  template <class T>
  inline auto
  Property_WriteOnly<T>::operator= (
      const typename Property_WriteOnly<T>::PropertyType& data) -> Property_WriteOnly<T>&
  {
    static_cast<ValueType&> (value_).set (data);
    this->notify ();
    return *this;
  }

  template <class T>
  inline auto
  Property_WriteOnly<T>::get_proxy () -> Glib::PropertyProxy_WriteOnly<T>
  {
    return Glib::PropertyProxy_WriteOnly<T> (object_, get_name_internal ());
  }
#endif

} // namespace Glib

#endif
