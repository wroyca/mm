// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/settings.hxx>
#include <libmm/gio/settings_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/settingsschema.hxx>
#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/vectorutils.hxx>

namespace gio
{

  auto
  Settings::get_value (const glib::ustring& key, glib::VariantBase& value) const -> void
  {
    const auto g_value = g_settings_get_value (const_cast<GSettings*> (gobj ()),
                                               key.c_str ());
    if (!g_value)
      return;

    value.init (g_value, false);
  }

  auto
  Settings::get_user_value (const glib::ustring& key,
                            glib::VariantBase& value) const -> bool
  {
    const auto g_value = g_settings_get_user_value (
        const_cast<GSettings*> (gobj ()),
        key.c_str ());
    if (!g_value)
      return false;

    value.init (g_value, false);
    return true;
  }

  auto
  Settings::get_default_value (const glib::ustring& key,
                               glib::VariantBase& value) const -> void
  {
    const auto g_value = g_settings_get_default_value (
        const_cast<GSettings*> (gobj ()),
        key.c_str ());
    if (!g_value)
      return;

    value.init (g_value, false);
  }

  auto
  Settings::bind (const glib::ustring& key,
                  const glib::PropertyProxy_Base& property_proxy,
                  const BindFlags flags) -> void
  {
    bind (key, property_proxy.get_object (), property_proxy.get_name (), flags);
  }

  auto
  Settings::bind_writable (const glib::ustring& key,
                           const glib::PropertyProxy_Base& property_proxy,
                           const bool inverted) -> void
  {
    bind_writable (key,
                   property_proxy.get_object (),
                   property_proxy.get_name (),
                   inverted);
  }

} // namespace gio

namespace
{

  auto
  Settings_signal_changed_callback (GSettings* self,
                                    const gchar* p0,
                                    void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    const auto obj = dynamic_cast<Settings*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo Settings_signal_changed_info = {
      "changed",
      (GCallback) &Settings_signal_changed_callback,
      (GCallback) &Settings_signal_changed_callback};

  auto
  Settings_signal_writable_change_event_callback (GSettings* self,
                                                  const GQuark p0,
                                                  void* data) -> gboolean
  {
    using namespace gio;
    using SlotType = sigc::slot<bool (GQuark)>;

    const auto obj = dynamic_cast<Settings*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  auto
  Settings_signal_writable_change_event_notify_callback (GSettings* self,
                                                         const GQuark p0,
                                                         void* data) -> gboolean
  {
    using namespace gio;
    using SlotType = sigc::slot<void (GQuark)>;

    const auto obj = dynamic_cast<Settings*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  const glib::SignalProxyInfo Settings_signal_writable_change_event_info = {
      "writable-change-event",
      (GCallback) &Settings_signal_writable_change_event_callback,
      (GCallback) &Settings_signal_writable_change_event_notify_callback};

  auto
  Settings_signal_writable_changed_callback (GSettings* self,
                                             const gchar* p0,
                                             void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    const auto obj = dynamic_cast<Settings*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo Settings_signal_writable_changed_info = {
      "writable_changed",
      (GCallback) &Settings_signal_writable_changed_callback,
      (GCallback) &Settings_signal_writable_changed_callback};

} // namespace

auto
glib::Value<gio::Settings::BindFlags>::value_type () -> GType
{
  return g_settings_bind_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GSettings* object, const bool take_copy) -> RefPtr<gio::Settings>
  {
    return glib::make_refptr_for_instance<gio::Settings> (
        dynamic_cast<gio::Settings*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  Settings_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Settings_Class::class_init_function;

      register_derived_type (g_settings_get_type ());
    }

    return *this;
  }

  auto
  Settings_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->changed = &changed_callback;
    klass->writable_change_event = &writable_change_event_callback;
    klass->writable_changed = &writable_changed_callback;
  }

  auto
  Settings_Class::changed_callback (GSettings* self, const gchar* p0) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed (glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self, p0);
  }

  auto
  Settings_Class::writable_change_event_callback (GSettings* self,
                                                  const GQuark p0) -> gboolean
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->on_writable_change_event (p0);
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->writable_change_event)
      return (*base->writable_change_event) (self, p0);

    using RType = gboolean;
    return RType ();
  }

  auto
  Settings_Class::writable_changed_callback (GSettings* self, const gchar* p0) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_writable_changed (
              glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->writable_changed)
      (*base->writable_changed) (self, p0);
  }

  auto
  Settings_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Settings ((GSettings*) object);
  }

  auto
  Settings::gobj_copy () -> GSettings*
  {
    reference ();
    return gobj ();
  }

  Settings::Settings (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Settings::Settings (GSettings* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Settings::Settings (Settings&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Settings::operator= (Settings&& src) noexcept -> Settings&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Settings::~Settings () noexcept = default;

  Settings::CppClassType Settings::settings_class_;

  auto
  Settings::get_type () -> GType
  {
    return settings_class_.init ().get_type ();
  }

  auto
  Settings::get_base_type () -> GType
  {
    return g_settings_get_type ();
  }

  Settings::Settings (const glib::ustring& schema_id)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (settings_class_.init (),
                                     "schema_id",
                                     schema_id.c_str (),
                                     nullptr))
  {
  }

  Settings::Settings (const glib::ustring& schema_id, const glib::ustring& path)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (settings_class_.init (),
                                     "schema_id",
                                     schema_id.c_str (),
                                     "path",
                                     path.c_str (),
                                     nullptr))
  {
  }

  auto
  Settings::create (const glib::ustring& schema_id) -> glib::RefPtr<Settings>
  {
    return glib::make_refptr_for_instance<Settings> (new Settings (schema_id));
  }

  auto
  Settings::create (const glib::ustring& schema_id, const glib::ustring& path) -> glib::RefPtr<Settings>
  {
    return glib::make_refptr_for_instance<Settings> (
        new Settings (schema_id, path));
  }

  auto
  Settings::set_value (const glib::ustring& key, const glib::VariantBase& value) -> bool
  {
    return g_settings_set_value (gobj (),
                                 key.c_str (),
                                 const_cast<GVariant*> (value.gobj ()));
  }

  auto
  Settings::get_int (const glib::ustring& key) const -> int
  {
    return g_settings_get_int (const_cast<GSettings*> (gobj ()), key.c_str ());
  }

  auto
  Settings::set_int (const glib::ustring& key, const int value) -> bool
  {
    return g_settings_set_int (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_int64 (const glib::ustring& key) const -> gint64
  {
    return g_settings_get_int64 (const_cast<GSettings*> (gobj ()),
                                 key.c_str ());
  }

  auto
  Settings::set_int64 (const glib::ustring& key, const gint64 value) -> bool
  {
    return g_settings_set_int64 (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_uint (const glib::ustring& key) const -> guint
  {
    return g_settings_get_uint (const_cast<GSettings*> (gobj ()), key.c_str ());
  }

  auto
  Settings::set_uint (const glib::ustring& key, const guint value) -> bool
  {
    return g_settings_set_uint (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_uint64 (const glib::ustring& key) const -> guint64
  {
    return g_settings_get_uint64 (const_cast<GSettings*> (gobj ()),
                                  key.c_str ());
  }

  auto
  Settings::set_uint64 (const glib::ustring& key, const guint64 value) -> bool
  {
    return g_settings_set_uint64 (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_boolean (const glib::ustring& key) const -> bool
  {
    return g_settings_get_boolean (const_cast<GSettings*> (gobj ()),
                                   key.c_str ());
  }

  auto
  Settings::set_boolean (const glib::ustring& key, const bool value) -> bool
  {
    return g_settings_set_boolean (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_string (const glib::ustring& key) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_settings_get_string (const_cast<GSettings*> (gobj ()), key.c_str ()));
  }

  auto
  Settings::set_string (const glib::ustring& key, const glib::ustring& value) -> bool
  {
    return g_settings_set_string (gobj (), key.c_str (), value.c_str ());
  }

  auto
  Settings::get_double (const glib::ustring& key) const -> double
  {
    return g_settings_get_double (const_cast<GSettings*> (gobj ()),
                                  key.c_str ());
  }

  auto
  Settings::set_double (const glib::ustring& key, const double value) -> bool
  {
    return g_settings_set_double (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_string_array (const glib::ustring& key) const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_settings_get_strv (const_cast<GSettings*> (gobj ()), key.c_str ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Settings::set_string_array (const glib::ustring& key,
                              const std::vector<glib::ustring>& value) -> bool
  {
    return g_settings_set_strv (
        gobj (),
        key.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (value).data ());
  }

  auto
  Settings::get_enum (const glib::ustring& key) const -> int
  {
    return g_settings_get_enum (const_cast<GSettings*> (gobj ()), key.c_str ());
  }

  auto
  Settings::set_enum (const glib::ustring& key, const int value) -> bool
  {
    return g_settings_set_enum (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_flags (const glib::ustring& key) const -> guint
  {
    return g_settings_get_flags (const_cast<GSettings*> (gobj ()),
                                 key.c_str ());
  }

  auto
  Settings::set_flags (const glib::ustring& key, const guint value) -> bool
  {
    return g_settings_set_flags (gobj (), key.c_str (), value);
  }

  auto
  Settings::get_child (const glib::ustring& name) -> glib::RefPtr<Settings>
  {
    return glib::wrap (g_settings_get_child (gobj (), name.c_str ()));
  }

  auto
  Settings::get_child (const glib::ustring& name) const -> glib::RefPtr<const Settings>
  {
    return const_cast<Settings*> (this)->get_child (name);
  }

  auto
  Settings::is_writable (const glib::ustring& name) const -> bool
  {
    return g_settings_is_writable (const_cast<GSettings*> (gobj ()),
                                   name.c_str ());
  }

  auto
  Settings::delay () -> void
  {
    g_settings_delay (gobj ());
  }

  auto
  Settings::apply () -> void
  {
    g_settings_apply (gobj ());
  }

  auto
  Settings::revert () -> void
  {
    g_settings_revert (gobj ());
  }

  auto
  Settings::get_has_unapplied () const -> bool
  {
    return g_settings_get_has_unapplied (const_cast<GSettings*> (gobj ()));
  }

  auto
  Settings::reset (const glib::ustring& key) -> void
  {
    g_settings_reset (gobj (), key.c_str ());
  }

  auto
  Settings::list_children () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_settings_list_children (const_cast<GSettings*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Settings::bind (const glib::ustring& key,
                  ObjectBase* object,
                  const glib::ustring& property,
                  BindFlags flags) -> void
  {
    g_settings_bind (gobj (),
                     key.c_str (),
                     object->gobj (),
                     property.c_str (),
                     static_cast<GSettingsBindFlags> (flags));
  }

  auto
  Settings::bind_writable (const glib::ustring& key,
                           ObjectBase* object,
                           const glib::ustring& property,
                           const bool inverted) -> void
  {
    g_settings_bind_writable (gobj (),
                              key.c_str (),
                              object->gobj (),
                              property.c_str (),
                              inverted);
  }

  auto
  Settings::create_action (const glib::ustring& key) -> glib::RefPtr<Action>
  {
    return glib::wrap (g_settings_create_action (gobj (), key.c_str ()));
  }

  auto
  Settings::signal_changed (const glib::ustring& key) -> glib::SignalProxyDetailed<void (const glib::ustring&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&)> (
        this,
        &Settings_signal_changed_info,
        key);
  }

  auto
  Settings::signal_writable_change_event () -> glib::SignalProxy<bool (GQuark)>
  {
    return {this, &Settings_signal_writable_change_event_info};
  }

  auto
  Settings::signal_writable_changed (const glib::ustring& key) -> glib::SignalProxyDetailed<void (const glib::ustring&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&)> (
        this,
        &Settings_signal_writable_changed_info,
        key);
  }

  auto
  Settings::property_delay_apply () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "delay-apply"};
  }

  auto
  Settings::property_has_unapplied () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-unapplied"};
  }

  auto
  Settings::property_path () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return {this, "path"};
  }

  auto
  Settings::property_schema_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "schema-id"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SettingsSchema>>::value,
      "Type glib::RefPtr<SettingsSchema> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Settings::property_settings_schema () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SettingsSchema>>
  {
    return {this, "settings-schema"};
  }

  auto
  Settings::on_changed (const glib::ustring& key) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj (), key.c_str ());
  }

  auto
  Settings::on_writable_change_event (const GQuark key) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->writable_change_event)
      return (*base->writable_change_event) (gobj (), key);

    using RType = bool;
    return RType ();
  }

  auto
  Settings::on_writable_changed (const glib::ustring& key) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->writable_changed)
      (*base->writable_changed) (gobj (), key.c_str ());
  }

} // namespace gio
