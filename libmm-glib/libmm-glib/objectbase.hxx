#ifndef _GLIBMM_OBJECTBASE_H
#define _GLIBMM_OBJECTBASE_H

#include <libmm-glib/class.hxx>
#include <libmm-glib/debug.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/propertyproxy.hxx>
#include <libmm-glib/quark.hxx>
#include <libmm-glib/signalproxy.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/value.hxx>
#include <memory>
#include <sigc++/trackable.h>
#include <typeinfo>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  using GObject = struct _GObject;
}
#endif

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class GLIBMM_API GSigConnectionNode;
  class GLIBMM_API Interface_Class;
#endif

  class GLIBMM_API ObjectBase : virtual public sigc::trackable
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

    void
    initialize (GObject* castitem);

    void
    initialize_move (GObject* castitem, Glib::ObjectBase* previous_wrapper);

  public:
    void
    set_property_value (const Glib::ustring& property_name,
                        const Glib::ValueBase& value);

    void
    get_property_value (const Glib::ustring& property_name,
                        Glib::ValueBase& value) const;

    template <class PropertyType>
    void
    set_property (const Glib::ustring& property_name,
                  const PropertyType& value);

    template <class PropertyType>
    void
    get_property (const Glib::ustring& property_name,
                  PropertyType& value) const;

    template <class PropertyType>
    auto
    get_property (const Glib::ustring& property_name) const -> PropertyType;

    auto
    connect_property_changed (const Glib::ustring& property_name,
                              const sigc::slot<void ()>& slot)
        -> sigc::connection;

    auto
    connect_property_changed (const Glib::ustring& property_name,
                              sigc::slot<void ()>&& slot) -> sigc::connection;

    void
    freeze_notify ();

    void
    thaw_notify ();

    virtual void
    reference () const;

    virtual void
    unreference () const;

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

    void
    add_custom_interface_class (const Interface_Class* iface_class);
    void
    add_custom_class_init_function (GClassInitFunc class_init_func,
                                    void* class_data = nullptr);
    void
    set_custom_instance_init_function (GInstanceInitFunc instance_init_func);
    auto
    get_custom_interface_classes () const
        -> const Class::interface_classes_type*;
    auto
    get_custom_class_init_functions () const
        -> const Class::class_init_funcs_type*;
    GInstanceInitFunc
    get_custom_instance_init_function () const;
    void
    custom_class_init_finished ();

  public:
    auto
    is_derived_ () const -> bool;

  protected:
    static void
    destroy_notify_callback_ (void* data);
    virtual void
    destroy_notify_ ();

    void
    _set_current_wrapper (GObject* object);

    void
    _move_current_wrapper (GObject* object,
                           Glib::ObjectBase* previous_wrapper) noexcept;
#endif

  private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    struct PrivImpl;
    std::unique_ptr<PrivImpl> priv_pimpl_;

    virtual void
    set_manage ();

    friend class Glib::GSigConnectionNode;
#endif
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class PropertyType>
  inline void
  ObjectBase::set_property (const Glib::ustring& property_name,
                            const PropertyType& value)
  {
    Glib::Value<PropertyType> property_value;
    property_value.init (Glib::Value<PropertyType>::value_type ());

    property_value.set (value);
    this->set_property_value (property_name, property_value);
  }

  template <class PropertyType>
  inline void
  ObjectBase::get_property (const Glib::ustring& property_name,
                            PropertyType& value) const
  {
    Glib::Value<PropertyType> property_value;
    property_value.init (Glib::Value<PropertyType>::value_type ());

    this->get_property_value (property_name, property_value);

    value = property_value.get ();
  }

  template <class PropertyType>
  inline auto
  ObjectBase::get_property (const Glib::ustring& property_name) const -> PropertyType
  {
    PropertyType value;
    get_property (property_name, value);

    return value;
  }

#endif

  GLIBMM_API
  auto
  _gobject_cppinstance_already_deleted (GObject* gobject) -> bool;

} // namespace Glib

#endif
