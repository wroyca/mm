


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/settings.hpp>
#include <libmm-gio/settings_p.hpp>


/* Copyright (C) 2010 The giomm Development Team
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

#include <gio/gio.h>
#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-glib/vectorutils.hpp>
#include <libmm-gio/settingsschema.hpp>

namespace Gio
{

auto Settings::get_value (const Glib::ustring &key, Glib::VariantBase &value) const -> void
{
  const auto g_value = g_settings_get_value(const_cast<GSettings*>(gobj()), key.c_str());
  if (!g_value)
    return;

  value.init(g_value, false /* don't take a reference */);
}

auto
Settings::get_user_value(const Glib::ustring& key, Glib::VariantBase& value) const -> bool
{
  const auto g_value = g_settings_get_user_value(const_cast<GSettings*>(gobj()), key.c_str());
  if (!g_value)
    return false;

  value.init(g_value, false /* don't take a reference */);
  return true;
}

auto Settings::get_default_value (const Glib::ustring &key, Glib::VariantBase &value) const -> void
{
  const auto g_value = g_settings_get_default_value(const_cast<GSettings*>(gobj()), key.c_str());
  if (!g_value)
    return;

  value.init(g_value, false /* don't take a reference */);
}
auto Settings::bind (
  const Glib::ustring &key, const Glib::PropertyProxy_Base &property_proxy, const BindFlags flags) -> void
{
  bind(key, property_proxy.get_object(), property_proxy.get_name(), flags);
}

auto Settings::bind_writable (
  const Glib::ustring &key, const Glib::PropertyProxy_Base &property_proxy, const bool inverted) -> void
{
  bind_writable(key, property_proxy.get_object(), property_proxy.get_name(), inverted);
}

}

namespace
{


auto Settings_signal_changed_callback (GSettings *self, const gchar *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<Settings*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Settings_signal_changed_info =
{
  "changed",
  (GCallback) &Settings_signal_changed_callback,
  (GCallback) &Settings_signal_changed_callback
};


auto Settings_signal_writable_change_event_callback(GSettings* self, const GQuark p0,void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<bool(GQuark)>;

  const auto obj = dynamic_cast<Settings*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(p0);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto Settings_signal_writable_change_event_notify_callback(GSettings* self, const GQuark p0, void* data) -> gboolean
{
  using namespace Gio;
  using SlotType = sigc::slot<void(GQuark)>;

  const auto obj = dynamic_cast<Settings*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo Settings_signal_writable_change_event_info =
{
  "writable-change-event",
  (GCallback) &Settings_signal_writable_change_event_callback,
  (GCallback) &Settings_signal_writable_change_event_notify_callback
};


auto Settings_signal_writable_changed_callback (
  GSettings *self, const gchar *p0, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<Settings*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Settings_signal_writable_changed_info =
{
  "writable_changed",
  (GCallback) &Settings_signal_writable_changed_callback,
  (GCallback) &Settings_signal_writable_changed_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gio::Settings::BindFlags>::value_type() -> GType
{
  return g_settings_bind_flags_get_type();
}


namespace Glib
{

auto wrap(GSettings* object, const bool take_copy) -> RefPtr<Gio::Settings>
{
  return Glib::make_refptr_for_instance<Gio::Settings>( dynamic_cast<Gio::Settings*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Settings_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Settings_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_settings_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Settings_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->changed = &changed_callback;
  klass->writable_change_event = &writable_change_event_callback;
  klass->writable_changed = &writable_changed_callback;
}


auto Settings_Class::changed_callback (GSettings *self, const gchar *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_changed(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self, p0);
}
auto Settings_Class::writable_change_event_callback(GSettings* self, const GQuark p0) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->on_writable_change_event(p0);
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->writable_change_event)
    return (*base->writable_change_event)(self, p0);

  using RType = gboolean;
  return RType();
}
auto Settings_Class::writable_changed_callback (GSettings *self, const gchar *p0) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_writable_changed(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->writable_changed)
    (*base->writable_changed)(self, p0);
}


auto Settings_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Settings((GSettings*)object);
}


/* The implementation: */

auto Settings::gobj_copy() -> GSettings*
{
  reference();
  return gobj();
}

Settings::Settings(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Settings::Settings(GSettings* castitem)
: Object((GObject*)castitem)
{}


Settings::Settings(Settings&& src) noexcept
: Object(std::move(src))
{}

auto Settings::operator=(Settings&& src) noexcept -> Settings&
{
  Object::operator=(std::move(src));
  return *this;
}


Settings::~Settings() noexcept = default;

Settings::CppClassType Settings::settings_class_; // initialize static member

auto Settings::get_type() -> GType
{
  return settings_class_.init().get_type();
}


auto Settings::get_base_type() -> GType
{
  return g_settings_get_type();
}


Settings::Settings(const Glib::ustring& schema_id)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(settings_class_.init(), "schema_id", schema_id.c_str(), nullptr))
{


}

Settings::Settings(const Glib::ustring& schema_id, const Glib::ustring& path)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(settings_class_.init(), "schema_id", schema_id.c_str(), "path", path.c_str(), nullptr))
{


}

auto Settings::create(const Glib::ustring& schema_id) -> Glib::RefPtr<Settings>
{
  return Glib::make_refptr_for_instance<Settings>( new Settings(schema_id) );
}

auto Settings::create(const Glib::ustring& schema_id, const Glib::ustring& path) -> Glib::RefPtr<Settings>
{
  return Glib::make_refptr_for_instance<Settings>( new Settings(schema_id, path) );
}

auto Settings::set_value(const Glib::ustring& key, const Glib::VariantBase& value) -> bool
{
  return g_settings_set_value(gobj(), key.c_str(), const_cast<GVariant*>(value.gobj()));
}

auto Settings::get_int(const Glib::ustring& key) const -> int
{
  return g_settings_get_int(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_int(const Glib::ustring& key, const int value) -> bool
{
  return g_settings_set_int(gobj(), key.c_str(), value);
}

auto Settings::get_int64(const Glib::ustring& key) const -> gint64
{
  return g_settings_get_int64(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_int64(const Glib::ustring& key, const gint64 value) -> bool
{
  return g_settings_set_int64(gobj(), key.c_str(), value);
}

auto Settings::get_uint(const Glib::ustring& key) const -> guint
{
  return g_settings_get_uint(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_uint(const Glib::ustring& key, const guint value) -> bool
{
  return g_settings_set_uint(gobj(), key.c_str(), value);
}

auto Settings::get_uint64(const Glib::ustring& key) const -> guint64
{
  return g_settings_get_uint64(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_uint64(const Glib::ustring& key, const guint64 value) -> bool
{
  return g_settings_set_uint64(gobj(), key.c_str(), value);
}

auto Settings::get_boolean(const Glib::ustring& key) const -> bool
{
  return g_settings_get_boolean(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_boolean(const Glib::ustring& key, const bool value) -> bool
{
  return g_settings_set_boolean(gobj(), key.c_str(), value);
}

auto Settings::get_string(const Glib::ustring& key) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_settings_get_string(const_cast<GSettings*>(gobj()), key.c_str()));
}

auto Settings::set_string(const Glib::ustring& key, const Glib::ustring& value) -> bool
{
  return g_settings_set_string(gobj(), key.c_str(), value.c_str());
}

auto Settings::get_double(const Glib::ustring& key) const -> double
{
  return g_settings_get_double(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_double(const Glib::ustring& key, const double value) -> bool
{
  return g_settings_set_double(gobj(), key.c_str(), value);
}

auto Settings::get_string_array(const Glib::ustring& key) const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_settings_get_strv(const_cast<GSettings*>(gobj()), key.c_str()), Glib::OWNERSHIP_DEEP);
}

auto Settings::set_string_array(const Glib::ustring& key, const std::vector<Glib::ustring>& value) -> bool
{
  return g_settings_set_strv(gobj(), key.c_str(), Glib::ArrayHandler<Glib::ustring>::vector_to_array(value).data());
}

auto Settings::get_enum(const Glib::ustring& key) const -> int
{
  return g_settings_get_enum(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_enum(const Glib::ustring& key, const int value) -> bool
{
  return g_settings_set_enum(gobj(), key.c_str(), value);
}

auto Settings::get_flags(const Glib::ustring& key) const -> guint
{
  return g_settings_get_flags(const_cast<GSettings*>(gobj()), key.c_str());
}

auto Settings::set_flags(const Glib::ustring& key, const guint value) -> bool
{
  return g_settings_set_flags(gobj(), key.c_str(), value);
}

auto Settings::get_child(const Glib::ustring& name) -> Glib::RefPtr<Settings>
{
  return Glib::wrap(g_settings_get_child(gobj(), name.c_str()));
}

auto Settings::get_child(const Glib::ustring& name) const -> Glib::RefPtr<const Settings>
{
  return const_cast<Settings*>(this)->get_child(name);
}

auto Settings::is_writable(const Glib::ustring& name) const -> bool
{
  return g_settings_is_writable(const_cast<GSettings*>(gobj()), name.c_str());
}

auto Settings::delay () -> void
{
  g_settings_delay(gobj());
}

auto Settings::apply () -> void
{
  g_settings_apply(gobj());
}

auto Settings::revert () -> void
{
  g_settings_revert(gobj());
}

auto Settings::get_has_unapplied() const -> bool
{
  return g_settings_get_has_unapplied(const_cast<GSettings*>(gobj()));
}

auto Settings::reset (const Glib::ustring &key) -> void
{
  g_settings_reset(gobj(), key.c_str());
}

auto Settings::list_children() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_settings_list_children(const_cast<GSettings*>(gobj())), Glib::OWNERSHIP_DEEP);
}

auto Settings::bind (
  const Glib::ustring &key, ObjectBase *object, const Glib::ustring &property,
  BindFlags flags) -> void
{
  g_settings_bind(gobj(), key.c_str(), object->gobj(), property.c_str(), static_cast<GSettingsBindFlags>(flags));
}

auto Settings::bind_writable (
  const Glib::ustring &key, ObjectBase *object, const Glib::ustring &property, const bool inverted) -> void
{
  g_settings_bind_writable(gobj(), key.c_str(), object->gobj(), property.c_str(), inverted);
}

auto Settings::create_action(const Glib::ustring& key) -> Glib::RefPtr<Action>
{
  return Glib::wrap(g_settings_create_action(gobj(), key.c_str()));
}


auto Settings::signal_changed(const Glib::ustring& key) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>
{
  return Glib::SignalProxyDetailed<void(const Glib::ustring&)>(this, &Settings_signal_changed_info, key);
}


auto Settings::signal_writable_change_event() -> Glib::SignalProxy<bool(GQuark)>
{
  return {this, &Settings_signal_writable_change_event_info};
}


auto Settings::signal_writable_changed(const Glib::ustring& key) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>
{
  return Glib::SignalProxyDetailed<void(const Glib::ustring&)>(this, &Settings_signal_writable_changed_info, key);
}


auto Settings::property_delay_apply() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "delay-apply"};
}

auto Settings::property_has_unapplied() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-unapplied"};
}

auto Settings::property_path() const -> Glib::PropertyProxy_ReadOnly< std::string >
{
  return {this, "path"};
}

auto Settings::property_schema_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "schema-id"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SettingsSchema>>::value,
  "Type Glib::RefPtr<SettingsSchema> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Settings::property_settings_schema() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SettingsSchema> >
{
  return {this, "settings-schema"};
}


auto Settings::on_changed (const Glib::ustring &key) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->changed)
    (*base->changed)(gobj(),key.c_str());
}
auto Settings::on_writable_change_event(
  const GQuark key) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->writable_change_event)
    return (*base->writable_change_event)(gobj(),key);

  using RType = bool;
  return RType();
}
auto Settings::on_writable_changed (const Glib::ustring &key) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->writable_changed)
    (*base->writable_changed)(gobj(),key.c_str());
}


} // namespace Gio


