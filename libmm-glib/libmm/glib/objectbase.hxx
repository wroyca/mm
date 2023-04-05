// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_OBJECTBASE_H
#define _GLIBMM_OBJECTBASE_H

#include <libmm/glib/class.hxx>
#include <libmm/glib/debug.hxx>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/propertyproxy.hxx>
#include <libmm/glib/quark.hxx>
#include <libmm/glib/signalproxy.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/value.hxx>
#include <memory>
#include <sigc++/trackable.h>
#include <typeinfo>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  using GObject = struct _GObject;
}
#endif

namespace glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class LIBMM_GLIB_SYMEXPORT GSigConnectionNode;
  class LIBMM_GLIB_SYMEXPORT Interface_Class;
#endif

  class LIBMM_GLIB_SYMEXPORT ObjectBase : virtual public sigc::trackable
  {
  public:
    ObjectBase (const ObjectBase&) = delete;
    auto
    operator= (const ObjectBase&) -> ObjectBase& = delete;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

  protected:
    ObjectBase ();

    explicit ObjectBase (const char* custom_type_name);

    explicit ObjectBase (const std::type_info& custom_type_info);

    ObjectBase (ObjectBase&& src) noexcept;
    auto
    operator= (ObjectBase&& src) noexcept -> ObjectBase&;

    virtual ~ObjectBase () noexcept = 0;

    auto
    initialize (GObject* castitem) -> void;

    auto
    initialize_move (GObject* castitem, glib::ObjectBase* previous_wrapper)
        -> void;

  public:
    auto
    set_property_value (const glib::ustring& property_name,
                        const glib::ValueBase& value) -> void;

    auto
    get_property_value (const glib::ustring& property_name,
                        glib::ValueBase& value) const -> void;

    template <class PropertyType>
    auto
    set_property (const glib::ustring& property_name, const PropertyType& value)
        -> void;

    template <class PropertyType>
    auto
    get_property (const glib::ustring& property_name, PropertyType& value) const
        -> void;

    template <class PropertyType>
    auto
    get_property (const glib::ustring& property_name) const -> PropertyType;

    auto
    connect_property_changed (const glib::ustring& property_name,
                              const sigc::slot<void ()>& slot)
        -> sigc::connection;

    auto
    connect_property_changed (const glib::ustring& property_name,
                              sigc::slot<void ()>&& slot) -> sigc::connection;

    auto
    freeze_notify () -> void;

    auto
    thaw_notify () -> void;

    virtual auto
    reference () const -> void;

    virtual auto
    unreference () const -> void;

    inline auto
    gobj () -> GObject*
    {
      return gobject_;
    }

    inline auto
    gobj () const -> const GObject*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GObject*;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    _get_current_wrapper (GObject* object) -> ObjectBase*;

    auto
    _cpp_destruction_is_in_progress () const -> bool;
#endif

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    GObject* gobject_;
    const char* custom_type_name_;
    bool cpp_destruction_in_progress_;

    auto
    is_anonymous_custom_ () const -> bool;

    auto
    add_custom_interface_class (const Interface_Class* iface_class) -> void;
    auto
    add_custom_class_init_function (GClassInitFunc class_init_func,
                                    void* class_data = nullptr) -> void;
    auto
    set_custom_instance_init_function (GInstanceInitFunc instance_init_func)
        -> void;
    auto
    get_custom_interface_classes () const
        -> const Class::interface_classes_type*;
    auto
    get_custom_class_init_functions () const
        -> const Class::class_init_funcs_type*;
    auto
    get_custom_instance_init_function () const -> GInstanceInitFunc;
    auto
    custom_class_init_finished () -> void;

  public:
    auto
    is_derived_ () const -> bool;

  protected:
    static auto
    destroy_notify_callback_ (void* data) -> void;
    virtual auto
    destroy_notify_ () -> void;

    auto
    _set_current_wrapper (GObject* object) -> void;

    auto
    _move_current_wrapper (GObject* object,
                           glib::ObjectBase* previous_wrapper) noexcept -> void;
#endif

  private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    struct PrivImpl;
    std::unique_ptr<PrivImpl> priv_pimpl_;

    virtual auto
    set_manage () -> void;

    friend class glib::GSigConnectionNode;
#endif
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class PropertyType>
  inline auto
  ObjectBase::set_property (const glib::ustring& property_name,
                            const PropertyType& value) -> void
  {
    glib::Value<PropertyType> property_value;
    property_value.init (glib::Value<PropertyType>::value_type ());

    property_value.set (value);
    this->set_property_value (property_name, property_value);
  }

  template <class PropertyType>
  inline auto
  ObjectBase::get_property (const glib::ustring& property_name,
                            PropertyType& value) const -> void
  {
    glib::Value<PropertyType> property_value;
    property_value.init (glib::Value<PropertyType>::value_type ());

    this->get_property_value (property_name, property_value);

    value = property_value.get ();
  }

  template <class PropertyType>
  inline auto
  ObjectBase::get_property (const glib::ustring& property_name) const -> PropertyType
  {
    PropertyType value;
    get_property (property_name, value);

    return value;
  }

#endif

  LIBMM_GLIB_SYMEXPORT
  auto
  _gobject_cppinstance_already_deleted (GObject* gobject) -> bool;

} // namespace glib

#endif
