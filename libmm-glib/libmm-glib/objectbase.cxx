

#include <glib-object.h>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/interface_p.hxx>
#include <libmm-glib/objectbase.hxx>
#include <libmm-glib/propertyproxy_base.hxx>
#include <libmm-glib/quark.hxx>
#include <utility>

namespace
{

  const char anonymous_custom_type_name[] = "gtkmm__anonymous_custom_type";

}

namespace Glib
{

  struct ObjectBase::PrivImpl
  {
    Class::interface_classes_type custom_interface_classes;

    Class::class_init_funcs_type custom_class_init_functions;

    GInstanceInitFunc custom_instance_init_function = nullptr;
  };

  ObjectBase::ObjectBase ()
    : gobject_ (nullptr),
      custom_type_name_ (anonymous_custom_type_name),
      cpp_destruction_in_progress_ (false)
  {
  }

  ObjectBase::ObjectBase (const char* custom_type_name)
    : gobject_ (nullptr),
      custom_type_name_ (custom_type_name),
      cpp_destruction_in_progress_ (false)
  {
  }

  ObjectBase::ObjectBase (const std::type_info& custom_type_info)
    : gobject_ (nullptr),
      custom_type_name_ (custom_type_info.name ()),
      cpp_destruction_in_progress_ (false)
  {
  }

  auto
  ObjectBase::initialize (GObject* castitem) -> void
  {
    if (gobject_)
    {
      g_assert (gobject_ == castitem);

      g_printerr (
          "ObjectBase::initialize() called twice for the same GObject\n");

      return;
    }

    gobject_ = castitem;
    _set_current_wrapper (castitem);
  }

  auto
  ObjectBase::initialize_move (GObject* castitem, ObjectBase* previous_wrapper) -> void
  {
    if (gobject_)
    {
      g_assert (gobject_ == castitem);

      g_printerr (
          "ObjectBase::initialize_move() called twice for the same GObject\n");

      return;
    }

    gobject_ = castitem;
    _move_current_wrapper (castitem, previous_wrapper);
    custom_type_name_ = previous_wrapper->custom_type_name_;
    cpp_destruction_in_progress_ =
        previous_wrapper->cpp_destruction_in_progress_;

    previous_wrapper->custom_type_name_ = nullptr;
    previous_wrapper->cpp_destruction_in_progress_ = false;
  }

  ObjectBase::ObjectBase (ObjectBase&& src) noexcept
    : trackable (std::move (src)),
      gobject_ (nullptr),
      custom_type_name_ (src.custom_type_name_),
      cpp_destruction_in_progress_ (src.cpp_destruction_in_progress_)
  {
  }

  auto
  ObjectBase::operator= (ObjectBase&& src) noexcept -> ObjectBase&
  {
    if (this == &src)
      return *this;

    trackable::operator= (std::move (src));

    if (gobject_)
    {
      g_object_steal_qdata (gobject_, quark_);

      unreference ();
      gobject_ = nullptr;
    }
    initialize_move (src.gobject_, &src);

    return *this;
  }

  ObjectBase::~ObjectBase () noexcept
  {
    if (GObject* const gobject = gobject_)
    {
#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("(Glib::ObjectBase::~ObjectBase): gobject_ = %p",
                 (void*) gobject_);
#endif

      gobject_ = nullptr;

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning (
          "(Glib::ObjectBase::~ObjectBase): before g_object_steal_qdata()");
#endif

      g_object_steal_qdata (gobject, quark_);

#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("(Glib::ObjectBase::~ObjectBase): calling g_object_unref()");
#endif

      g_object_unref (gobject);
    }
  }

  auto
  ObjectBase::reference () const -> void
  {
    GLIBMM_DEBUG_REFERENCE (this, gobject_);
    g_object_ref (gobject_);
  }

  auto
  ObjectBase::unreference () const -> void
  {
    GLIBMM_DEBUG_UNREFERENCE (this, gobject_);
    g_object_unref (gobject_);
  }

  auto
  ObjectBase::gobj_copy () const -> GObject*
  {
    reference ();
    return gobject_;
  }

  auto
  ObjectBase::_set_current_wrapper (GObject* object) -> void
  {
    if (object)
    {
      if (!g_object_get_qdata (object, quark_))
      {
        g_object_set_qdata_full (object,
                                 quark_,
                                 this,
                                 &destroy_notify_callback_);
      }
      else
      {
        g_warning ("This object, of type %s, already has a wrapper.\n"
                   "You should use wrap() instead of a constructor.",
                   G_OBJECT_TYPE_NAME (object));
      }
    }
  }

  auto
  ObjectBase::_move_current_wrapper (GObject* object,
                                     ObjectBase* previous_wrapper) noexcept -> void
  {
    ObjectBase* current_wrapper = _get_current_wrapper (object);
    if (current_wrapper != previous_wrapper)
    {
      g_warning ("%s: Unexpected previous wrapper, for object of type %s.\n"
                 "previous_wrapper=%p, current_wrapper=%p",
                 G_STRFUNC,
                 G_OBJECT_TYPE_NAME (object),
                 static_cast<void*> (previous_wrapper),
                 static_cast<void*> (current_wrapper));
    }

    g_object_steal_qdata (object, quark_);

    g_object_set_qdata_full (object, quark_, this, &destroy_notify_callback_);

    previous_wrapper->gobject_ = nullptr;
  }

  auto
  ObjectBase::_get_current_wrapper (GObject* object) -> ObjectBase*
  {
    if (object)
      return static_cast<ObjectBase*> (g_object_get_qdata (object, quark_));
    else
      return nullptr;
  }

  auto
  ObjectBase::destroy_notify_callback_ (void* data) -> void
  {
    ObjectBase* cppObject = static_cast<ObjectBase*> (data);

#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("ObjectBase::destroy_notify_callback_: cppObject = %p, gobject_ "
               "= %p, gtypename = %s\n",
               (void*) cppObject,
               (void*) cppObject->gobject_,
               G_OBJECT_TYPE_NAME (cppObject->gobject_));
#endif

    if (cppObject)
    {
      cppObject->destroy_notify_ ();
    }
  }

  auto
  ObjectBase::destroy_notify_ () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Glib::ObjectBase::destroy_notify_: gobject_ = %p",
               (void*) gobject_);
#endif

    gobject_ = nullptr;

    delete this;
  }

  auto
  ObjectBase::is_anonymous_custom_ () const -> bool
  {
    return custom_type_name_ == anonymous_custom_type_name;
  }

  auto
  ObjectBase::is_derived_ () const -> bool
  {
    return custom_type_name_ != nullptr;
  }

  auto
  ObjectBase::set_manage () -> void
  {
    g_error ("Glib::ObjectBase::set_manage(): "
             "only Gtk::Object instances can be managed");
  }

  auto
  ObjectBase::_cpp_destruction_is_in_progress () const -> bool
  {
    return cpp_destruction_in_progress_;
  }

  auto
  ObjectBase::set_property_value (const ustring& property_name,
                                  const ValueBase& value) -> void
  {
    g_object_set_property (gobj (), property_name.c_str (), value.gobj ());
  }

  auto
  ObjectBase::get_property_value (const ustring& property_name,
                                  ValueBase& value) const -> void
  {
    g_object_get_property (const_cast<GObject*> (gobj ()),
                           property_name.c_str (),
                           value.gobj ());
  }

  auto
  ObjectBase::connect_property_changed (const ustring& property_name,
                                        const sigc::slot<void ()>& slot) -> sigc::connection
  {
    const auto pConnectionNode = new PropertyProxyConnectionNode (slot,
                                                                  gobj ());

    return pConnectionNode->connect_changed (property_name);
  }

  auto
  ObjectBase::connect_property_changed (const ustring& property_name,
                                        sigc::slot<void ()>&& slot) -> sigc::connection
  {
    const auto pConnectionNode =
        new PropertyProxyConnectionNode (std::move (slot), gobj ());

    return pConnectionNode->connect_changed (property_name);
  }

  auto
  ObjectBase::freeze_notify () -> void
  {
    g_object_freeze_notify (gobj ());
  }

  auto
  ObjectBase::thaw_notify () -> void
  {
    g_object_thaw_notify (gobj ());
  }

  auto
  ObjectBase::get_base_type () -> GType
  {
    return G_TYPE_OBJECT;
  }

  auto
  ObjectBase::add_custom_interface_class (const Interface_Class* iface_class) -> void
  {
    if (!priv_pimpl_)
      priv_pimpl_ = std::make_unique<PrivImpl> ();
    priv_pimpl_->custom_interface_classes.emplace_back (iface_class);
  }

  auto
  ObjectBase::add_custom_class_init_function (GClassInitFunc class_init_func,
                                              void* class_data) -> void
  {
    if (!priv_pimpl_)
      priv_pimpl_ = std::make_unique<PrivImpl> ();
    priv_pimpl_->custom_class_init_functions.emplace_back (
        std::make_tuple (class_init_func, class_data));
  }

  auto
  ObjectBase::set_custom_instance_init_function (
      const GInstanceInitFunc instance_init_func) -> void
  {
    if (!priv_pimpl_)
      priv_pimpl_ = std::make_unique<PrivImpl> ();
    priv_pimpl_->custom_instance_init_function = instance_init_func;
  }

  auto
  ObjectBase::get_custom_interface_classes () const -> const Class::interface_classes_type*
  {
    return priv_pimpl_ ? &priv_pimpl_->custom_interface_classes : nullptr;
  }

  auto
  ObjectBase::get_custom_class_init_functions () const -> const Class::class_init_funcs_type*
  {
    return priv_pimpl_ ? &priv_pimpl_->custom_class_init_functions : nullptr;
  }

  auto
  ObjectBase::get_custom_instance_init_function () const -> GInstanceInitFunc
  {
    return priv_pimpl_ ? priv_pimpl_->custom_instance_init_function : nullptr;
  }

  auto
  ObjectBase::custom_class_init_finished () -> void
  {
    priv_pimpl_.reset ();
  }

  auto
  _gobject_cppinstance_already_deleted (GObject* gobject) -> bool
  {
    if (gobject)
      return (bool) g_object_get_qdata (gobject, quark_cpp_wrapper_deleted_);
    else
      return false;
  }

} // namespace Glib
