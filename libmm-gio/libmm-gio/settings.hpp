
#ifndef _GIOMM_SETTINGS_H
#define _GIOMM_SETTINGS_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 Jonathon Jongsma
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


#include <mm/glib/object.hpp>
#include <mm/glib/variant.hpp>
#include <mm/gio/action.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSettings = struct _GSettings;
using GSettingsClass = struct _GSettingsClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Settings_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{
class GIOMM_API SettingsSchema;

/** A high-level API for application settings
 *
 * The Settings class provides a convenient API for storing and retrieving
 * application settings.
 *
 * @newin{2,28}
 */

class GIOMM_API Settings : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Settings;
  using CppClassType = Settings_Class;
  using BaseObjectType = GSettings;
  using BaseClassType = GSettingsClass;

  // noncopyable
  Settings(const Settings&) = delete;
  auto operator=(const Settings&) -> Settings& = delete;

private:  friend class Settings_Class;
  static CppClassType settings_class_;

protected:
  explicit Settings(const Glib::ConstructParams& construct_params);
  explicit Settings(GSettings* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Settings(Settings&& src) noexcept;
  auto operator=(Settings&& src) noexcept -> Settings&;

  ~Settings() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GSettings*       { return reinterpret_cast<GSettings*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GSettings* { return reinterpret_cast<GSettings*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GSettings*;

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var BindFlags DEFAULT
   * Equivalent to `G_SETTINGS_BIND_GET|G_SETTINGS_BIND_SET`.
   *
   *  @var BindFlags GET
   * Update the Object property when the setting changes.
   * It is an error to use this flag if the property is not writable.
   *
   *  @var BindFlags SET
   * Update the setting when the Object property changes.
   * It is an error to use this flag if the property is not readable.
   *
   *  @var BindFlags NO_SENSITIVITY
   * Do not try to bind a "sensitivity" property to the writability of the setting.
   *
   *  @var BindFlags GET_NO_CHANGES
   * When set in addition to Gio::Settings::BindFlags::GET, set the Object property
   * value initially from the setting, but do not listen for changes of the setting.
   *
   *  @var BindFlags INVERT_BOOLEAN
   * When passed to g_settings_bind(), uses a pair of mapping functions that invert
   * the boolean value when mapping between the setting and the property.  The setting and property must both
   * be booleans.  You cannot pass this flag to g_settings_bind_with_mapping().
   *
   *  @enum BindFlags
   *
   * Flags used when creating a binding. These flags determine in which
   * direction the binding works. The default is to synchronize in both
   * directions.
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Settings::BindFlags operator|(Settings::BindFlags, Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags operator&(Settings::BindFlags, Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags operator^(Settings::BindFlags, Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags operator~(Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags& operator|=(Settings::BindFlags&, Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags& operator&=(Settings::BindFlags&, Settings::BindFlags)</tt><br>
   * <tt>Settings::BindFlags& operator^=(Settings::BindFlags&, Settings::BindFlags)</tt><br>
   */
  enum class BindFlags
  {
    DEFAULT = 0x0,
    GET = (1<<0),
    SET = (1<<1),
    NO_SENSITIVITY = (1<<2),
    GET_NO_CHANGES = (1<<3),
    INVERT_BOOLEAN = (1<<4)
  };


protected:
    explicit Settings(const Glib::ustring& schema_id);

    explicit Settings(const Glib::ustring& schema_id, const Glib::ustring& path);

  //TODO: Requires SettingsBackend: _WRAP_CTOR(Settings(const Glib::ustring& schema_id, const Glib::RefPtr<SettingsBackend>& backend), g_settings_new_with_backend)
  //TODO: Requires SettingsBackend: _WRAP_CTOR(Settings(const Glib::ustring& schema_id, const Glib::RefPtr<SettingsBackend>& backend, const Glib::ustring& path), g_settings_new_with_backend_and_path)
  //TODO: Requires SettingsBackend: _WRAP_CTOR(Settings(const Glib::RefPtr<SettingsSchema>& settings_schema, const Glib::RefPtr<SettingsBackend>& backend, const Glib::ustring& path), g_settings_new_full)

public:

  static auto create(const Glib::ustring& schema_id) -> Glib::RefPtr<Settings>;


  static auto create(const Glib::ustring& schema_id, const Glib::ustring& path) -> Glib::RefPtr<Settings>;

  //TODO: Requires SettingsBackend: _WRAP_CREATE(const Glib::ustring& schema_id, const Glib::RefPtr<SettingsBackend>& backend)
  //TODO: Requires SettingsBackend: _WRAP_CREATE(const Glib::ustring& schema_id, const Glib::RefPtr<SettingsBackend>& backend, const Glib::ustring& path)
  //TODO: Requires SettingsBackend: _WRAP_CREATE(const Glib::RefPtr<SettingsSchema>& settings_schema, const Glib::RefPtr<SettingsBackend>& backend, const Glib::ustring& path)

  //TODO: Rename these to get/set_*_value_variant() and add templated get/set_*_value() methods as elsewhere?

  /** Sets @a key in @a settings to @a value.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for @a settings or for @a value to have the incorrect type, per
   * the schema.
   *
   * If @a value is floating then this function consumes the reference.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value A Variant of the correct type.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_value(const Glib::ustring& key, const Glib::VariantBase& value) -> bool;


  /** Gets the value that is stored in the settings for a @a key.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for the settings.
   *
   * @param key The key to get the value for.
   * @param value A Variant of the expected type.
   *
   * @newin{2,28}
   */
  void get_value(const Glib::ustring& key, Glib::VariantBase& value) const;


  //TODO: We've added a bool return to handle the nullptr return value case,
  //but maybe other get_value() methods can return nullptrs too.

  /** Checks the "user value" of a @a key, if there is one.
   *
   * The user value of a key is the last value that was set by the user.
   *
   * After calling reset() this function should always return
   * false (assuming something is not wrong with the system
   * configuration).
   *
   * It is possible that get_value() will return a different
   * value than this method.  This can happen in the case that the user
   * set a value for a key that was subsequently locked down by the system
   * administrator -- this method will return the user's old value.
   *
   * This method may be useful for adding a "reset" option to a UI or
   * for providing indication that a particular value has been changed.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for the settings.
   *
   * @param key The key to get the user value for.
   * @param value A Variant of the expected type.
   * @result true if a user value was found.
   *
   * @newin{2,40}
   */
  auto get_user_value(const Glib::ustring& key, Glib::VariantBase& value) const -> bool;


  /** Gets the "default value" of a key.
   *
   * This is the value that would be read if reset() were to be
   * called on the key.
   *
   * Note that this may be a different value than returned by
   * get_default_value() if the system administrator
   * has provided a default value.
   *
   * Comparing the return values of get_default_value() and
   * value() is not sufficient for determining if a value
   * has been set because the user may have explicitly set the value to
   * something that happens to be equal to the default.  The difference
   * here is that if the default changes in the future, the user's key
   * will still be set.
   *
   * This method may be useful for adding an indication to a UI of what
   * the default value was before the user set it.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for the settings.
   *
   * @param key The key to get the default value for.
   * @param value A Variant of the expected type.
   *
   * @newin{2,40}
   */
  void get_default_value(const Glib::ustring& key, Glib::VariantBase& value) const;


  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for 32-bit integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a int32 type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return An integer.
   */
  auto get_int(const Glib::ustring& key) const -> int;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for 32-bit integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a int32 type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_int(const Glib::ustring& key, int value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for 64-bit integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a int64 type in the schema for @a settings.
   *
   * @newin{2,50}
   *
   * @param key The key to get the value for.
   * @return A 64-bit integer.
   */
  auto get_int64(const Glib::ustring& key) const -> gint64;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for 64-bit integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a int64 type in the schema for @a settings.
   *
   * @newin{2,50}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_int64(const Glib::ustring& key, gint64 value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for 32-bit unsigned
   * integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a uint32 type in the schema for @a settings.
   *
   * @newin{2,30}
   *
   * @param key The key to get the value for.
   * @return An unsigned integer.
   */
  auto get_uint(const Glib::ustring& key) const -> guint;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for 32-bit unsigned
   * integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a uint32 type in the schema for @a settings.
   *
   * @newin{2,30}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_uint(const Glib::ustring& key, guint value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for 64-bit unsigned
   * integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a uint64 type in the schema for @a settings.
   *
   * @newin{2,50}
   *
   * @param key The key to get the value for.
   * @return A 64-bit unsigned integer.
   */
  auto get_uint64(const Glib::ustring& key) const -> guint64;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for 64-bit unsigned
   * integers.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a uint64 type in the schema for @a settings.
   *
   * @newin{2,50}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_uint64(const Glib::ustring& key, guint64 value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for booleans.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a boolean type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return A boolean.
   */
  auto get_boolean(const Glib::ustring& key) const -> bool;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for booleans.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a boolean type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_boolean(const Glib::ustring& key, bool value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for strings.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a string type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return A newly-allocated string.
   */
  auto get_string(const Glib::ustring& key) const -> Glib::ustring;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for strings.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a string type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_string(const Glib::ustring& key, const Glib::ustring& value) -> bool;

  /** Gets the value that is stored at @a key in @a settings.
   *
   * A convenience variant of g_settings_get() for doubles.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a 'double' type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return A double.
   */
  auto get_double(const Glib::ustring& key) const -> double;

  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for doubles.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having a 'double' type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_double(const Glib::ustring& key, double value) -> bool;


  /** A convenience variant of g_settings_get() for string arrays.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having an array of strings type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return A
   * newly-allocated, <tt>nullptr</tt>-terminated array of strings, the value that
   * is stored at @a key in @a settings.
   */
  auto get_string_array(const Glib::ustring& key) const -> std::vector<Glib::ustring>;


  /** Sets @a key in @a settings to @a value.
   *
   * A convenience variant of g_settings_set() for string arrays.  If
   *  @a value is <tt>nullptr</tt>, then @a key is set to be the empty array.
   *
   * It is a programmer error to give a @a key that isn't specified as
   * having an array of strings type in the schema for @a settings.
   *
   * @newin{2,26}
   *
   * @param key The name of the key to set.
   * @param value The value to set it to, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if setting the key succeeded,
   * <tt>false</tt> if the key was not writable.
   */
  auto set_string_array(const Glib::ustring& key, const std::vector<Glib::ustring>& value) -> bool;


  /** Gets the value that is stored in @a settings for @a key and converts it
   * to the enum value that it represents.
   *
   * In order to use this function the type of the value must be a string
   * and it must be marked in the schema file as an enumerated type.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for @a settings or is not marked as an enumerated type.
   *
   * If the value stored in the configuration database is not a valid
   * value for the enumerated type then this function will return the
   * default value.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return The enum value.
   */
  auto get_enum(const Glib::ustring& key) const -> int;

  /** Looks up the enumerated type nick for @a value and writes it to @a key,
   * within @a settings.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for @a settings or is not marked as an enumerated type, or for
   *  @a value not to be a valid value for the named type.
   *
   * After performing the write, accessing @a key directly with
   * g_settings_get_string() will return the 'nick' associated with
   *  @a value.
   *
   * @param key A key, within @a settings.
   * @param value An enumerated value.
   * @return <tt>true</tt>, if the set succeeds.
   */
  auto set_enum(const Glib::ustring& key, int value) -> bool;

  /** Gets the value that is stored in @a settings for @a key and converts it
   * to the flags value that it represents.
   *
   * In order to use this function the type of the value must be an array
   * of strings and it must be marked in the schema file as a flags type.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for @a settings or is not marked as a flags type.
   *
   * If the value stored in the configuration database is not a valid
   * value for the flags type then this function will return the default
   * value.
   *
   * @newin{2,26}
   *
   * @param key The key to get the value for.
   * @return The flags value.
   */
  auto get_flags(const Glib::ustring& key) const -> guint;

  /** Looks up the flags type nicks for the bits specified by @a value, puts
   * them in an array of strings and writes the array to @a key, within
   *  @a settings.
   *
   * It is a programmer error to give a @a key that isn't contained in the
   * schema for @a settings or is not marked as a flags type, or for @a value
   * to contain any bits that are not value for the named type.
   *
   * After performing the write, accessing @a key directly with
   * g_settings_get_strv() will return an array of 'nicks'; one for each
   * bit in @a value.
   *
   * @param key A key, within @a settings.
   * @param value A flags value.
   * @return <tt>true</tt>, if the set succeeds.
   */
  auto set_flags(const Glib::ustring& key, guint value) -> bool;

  // Ignore varargs functions.


  /** Creates a child settings object which has a base path of
   * `base-path/ @a name`, where `base-path` is the base path of
   *  @a settings.
   *
   * The schema for the child settings object must have been declared
   * in the schema of @a settings using a `<child>` element.
   *
   * The created child settings object will inherit the Settings::property_delay_apply()
   * mode from @a settings.
   *
   * @newin{2,26}
   *
   * @param name The name of the child schema.
   * @return A 'child' settings object.
   */
  auto get_child(const Glib::ustring& name) -> Glib::RefPtr<Settings>;

  /** Creates a child settings object which has a base path of
   * `base-path/ @a name`, where `base-path` is the base path of
   *  @a settings.
   *
   * The schema for the child settings object must have been declared
   * in the schema of @a settings using a `<child>` element.
   *
   * The created child settings object will inherit the Settings::property_delay_apply()
   * mode from @a settings.
   *
   * @newin{2,26}
   *
   * @param name The name of the child schema.
   * @return A 'child' settings object.
   */
  auto get_child(const Glib::ustring& name) const -> Glib::RefPtr<const Settings>;

  /** Finds out if a key can be written or not
   *
   * @newin{2,26}
   *
   * @param name The name of a key.
   * @return <tt>true</tt> if the key @a name is writable.
   */
  auto is_writable(const Glib::ustring& name) const -> bool;


  /** Changes the Settings object into 'delay-apply' mode. In this
   * mode, changes to @a settings are not immediately propagated to the
   * backend, but kept locally until g_settings_apply() is called.
   *
   * @newin{2,26}
   */
  void delay();

  /** Applies any changes that have been made to the settings.  This
   * function does nothing unless @a settings is in 'delay-apply' mode;
   * see g_settings_delay().  In the normal case settings are always
   * applied immediately.
   */
  void apply();

  /** Reverts all non-applied changes to the settings.  This function
   * does nothing unless @a settings is in 'delay-apply' mode; see
   * g_settings_delay().  In the normal case settings are always applied
   * immediately.
   *
   * Change notifications will be emitted for affected keys.
   */
  void revert();

  /** Returns whether the Settings object has any unapplied
   * changes.  This can only be the case if it is in 'delayed-apply' mode.
   *
   * @newin{2,26}
   *
   * @return <tt>true</tt> if @a settings has unapplied changes.
   */
  auto get_has_unapplied() const -> bool;


  /** Resets @a key to its default value.
   *
   * This call resets the key, as much as possible, to its default value.
   * That might be the value specified in the schema or the one set by the
   * administrator.
   *
   * @param key The name of a key.
   */
  void reset(const Glib::ustring& key);


  /** Gets the list of children on @a settings.
   *
   * The list is exactly the list of strings for which it is not an error
   * to call g_settings_get_child().
   *
   * There is little reason to call this function from "normal" code, since
   * you should already know what children are in your schema. This function
   * may still be useful there for introspection reasons, however.
   *
   * @return A list of the children
   * on @a settings, in no defined order.
   */
  auto list_children() const -> std::vector<Glib::ustring>;


   // deprecated


  /** Create a binding between the @a key in the @a settings object
   * and the property @a property of @a object.
   *
   * The binding uses the default GIO mapping functions to map
   * between the settings and property values. These functions
   * handle booleans, numeric types and string types in a
   * straightforward way. Use g_settings_bind_with_mapping() if
   * you need a custom mapping, or map between types that are not
   * supported by the default mapping functions.
   *
   * Unless the @a flags include Gio::Settings::BindFlags::NO_SENSITIVITY, this
   * function also establishes a binding between the writability of
   *  @a key and the "sensitive" property of @a object (if @a object has
   * a boolean property by that name). See g_settings_bind_writable()
   * for more details about writable bindings.
   *
   * Note that the lifecycle of the binding is tied to @a object,
   * and that you can have only one binding per object property.
   * If you bind the same property twice on the same object, the second
   * binding overrides the first one.
   *
   * @newin{2,26}
   *
   * @param key The key to bind.
   * @param object A Object.
   * @param property The name of the property to bind.
   * @param flags Flags for the binding.
   */
  void bind(const Glib::ustring& key, Glib::ObjectBase* object, const Glib::ustring& property, BindFlags flags =  BindFlags::DEFAULT);
  void bind(const Glib::ustring& key, const Glib::PropertyProxy_Base& property_proxy, BindFlags flags = BindFlags::DEFAULT);
  // TODO: implement bind_with_mapping

  /** Create a binding between the writability of @a key in the
   *  @a settings object and the property @a property of @a object.
   * The property must be boolean; "sensitive" or "visible"
   * properties of widgets are the most likely candidates.
   *
   * Writable bindings are always uni-directional; changes of the
   * writability of the setting will be propagated to the object
   * property, not the other way.
   *
   * When the @a inverted argument is <tt>true</tt>, the binding inverts the
   * value as it passes from the setting to the object, i.e. @a property
   * will be set to <tt>true</tt> if the key is not writable.
   *
   * Note that the lifecycle of the binding is tied to @a object,
   * and that you can have only one binding per object property.
   * If you bind the same property twice on the same object, the second
   * binding overrides the first one.
   *
   * @newin{2,26}
   *
   * @param key The key to bind.
   * @param object A Object.
   * @param property The name of a boolean property to bind.
   * @param inverted Whether to 'invert' the value.
   */
  void bind_writable(const Glib::ustring& key, Glib::ObjectBase* object, const Glib::ustring& property, bool inverted = false);
  void bind_writable(const Glib::ustring& key, const Glib::PropertyProxy_Base& property_proxy, bool inverted=false);
  // TODO: unbind is not actually a class method


  /** Creates a Action corresponding to a given Settings key.
   *
   * The action has the same name as the key.
   *
   * The value of the key becomes the state of the action and the action
   * is enabled when the key is writable.  Changing the state of the
   * action results in the key being written to.  Changes to the value or
   * writability of the key cause appropriate change notifications to be
   * emitted for the action.
   *
   * For boolean-valued keys, action activations take no parameter and
   * result in the toggling of the value.  For all other types,
   * activations take the new value for the key (which must have the
   * correct type).
   *
   * @newin{2,32}
   *
   * @param key The name of a key in @a settings.
   * @return A new Action.
   */
  auto create_action(const Glib::ustring& key) -> Glib::RefPtr<Action>;

  //TODO?: _WRAP_PROPERTY("backend", Glib::RefPtr<SettingsBackend>)

  /** Whether the Settings object is in 'delay-apply' mode. See
   * g_settings_delay() for details.
   *
   * @newin{2,28}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_delay_apply() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** If this property is <tt>true</tt>, the Settings object has outstanding
   * changes that will be applied when g_settings_apply() is called.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_has_unapplied() const -> Glib::PropertyProxy_ReadOnly< bool >;


  /** The path within the backend where the settings are stored.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_path() const -> Glib::PropertyProxy_ReadOnly< std::string >;


  /** The name of the schema that describes the types of keys
   * for this Settings object.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_schema_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


  /** The SettingsSchema describing the types of keys for this
   * Settings object.
   *
   * Ideally, this property would be called 'schema'.  SettingsSchema
   * has only existed since version 2.32, however, and before then the
   * 'schema' property was used to refer to the ID of the schema rather
   * than the schema itself.  Take care.
   *
   * @newin{2,58}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_settings_schema() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SettingsSchema> >;


  //TODO?: _WRAP_SIGNAL(bool change_event(const std::vector<Glib::QueryQuark>&  keys, int n_keys), "change-event")


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed(const Glib::ustring& key)</tt>
   *
   * Flags: Run Last
   *
   * The "changed" signal is emitted when a key has potentially changed.
   * You should call one of the g_settings_get() calls to check the new
   * value.
   *
   * This signal supports detailed connections.  You can connect to the
   * detailed signal "changed::x" in order to only receive callbacks
   * when key "x" changes.
   *
   * Note that @a settings only emits this signal if you have read @a key at
   * least once while a signal handler was already connected for @a key.
   *
   * @param key The name of the key that changed.
   */

  auto signal_changed(const Glib::ustring& key = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%writable_change_event(GQuark key)</tt>
   *
   * Flags: Run Last
   *
   * The "writable-change-event" signal is emitted once per writability
   * change event that affects this settings object.  You should connect
   * to this signal if you are interested in viewing groups of changes
   * before they are split out into multiple emissions of the
   * "writable-changed" signal.  For most use cases it is more
   * appropriate to use the "writable-changed" signal.
   *
   * In the event that the writability change applies only to a single
   * key, @a key will be set to the Quark for that key.  In the event
   * that the writability change affects the entire settings object,
   *  @a key will be 0.
   *
   * The default handler for this signal invokes the "writable-changed"
   * and "changed" signals for each affected key.  This is done because
   * changes in writability might also imply changes in value (if for
   * example, a new mandatory setting is introduced).  If any other
   * connected handler returns <tt>true</tt> then this default functionality
   * will be suppressed.
   *
   * @param key The quark of the key, or 0.
   * @return <tt>true</tt> to stop other handlers from being invoked for the
   * event. <tt>false</tt> to propagate the event further.
   */

  auto signal_writable_change_event() -> Glib::SignalProxy<bool(GQuark)>;


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%writable_changed(const Glib::ustring& key)</tt>
   *
   * Flags: Run Last
   *
   * The "writable-changed" signal is emitted when the writability of a
   * key has potentially changed.  You should call
   * g_settings_is_writable() in order to determine the new status.
   *
   * This signal supports detailed connections.  You can connect to the
   * detailed signal "writable-changed::x" in order to only receive
   * callbacks when the writability of "x" changes.
   *
   * @param key The key.
   */

  auto signal_writable_changed(const Glib::ustring& key = {}) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed(const Glib::ustring& key);
  /// This is a default handler for the signal signal_writable_change_event().
  virtual auto on_writable_change_event(GQuark key) -> bool;
  /// This is a default handler for the signal signal_writable_changed().
  virtual void on_writable_changed(const Glib::ustring& key);


};

} // namespace Gio

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  { return static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  { return static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Settings::BindFlags lhs, Settings::BindFlags rhs) -> Settings::BindFlags
  { return static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Settings::BindFlags flags) -> Settings::BindFlags
  { return static_cast<Settings::BindFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  { return (lhs = static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  { return (lhs = static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Settings::BindFlags& lhs, Settings::BindFlags rhs) -> Settings::BindFlags&
  { return (lhs = static_cast<Settings::BindFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Settings::BindFlags> : public Glib::Value_Flags<Gio::Settings::BindFlags>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Settings
   */
  GIOMM_API
  auto wrap(GSettings* object, bool take_copy = false) -> Glib::RefPtr<Gio::Settings>;
}


#endif /* _GIOMM_SETTINGS_H */

