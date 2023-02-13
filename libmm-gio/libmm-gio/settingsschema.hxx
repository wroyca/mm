
#ifndef _GIOMM_SETTINGSSCHEMA_H
#define _GIOMM_SETTINGSSCHEMA_H

#include <libmm-gio/gioconfig.hxx>


#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

/* Copyright (C) 2015 The giomm Development Team
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


#include <libmm-gio/settingsschemakey.hxx>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchema GSettingsSchema;
#endif

namespace Gio
{

//TODO: Translate more of the class documentation from the C docs.

/** Introspecting and controlling the loading of GSettings schemas.
 *
 * The SettingsSchemaSource and SettingsSchema APIs provide a
 * mechanism for advanced control over the loading of schemas and a
 * mechanism for introspecting their content.
 *
 * Plugin loading systems that wish to provide plugins a way to access
 * settings face the problem of how to make the schemas for these
 * settings visible to GSettings.  Typically, a plugin will want to ship
 * the schema along with itself and it won't be installed into the
 * standard system directories for schemas.
 *
 * SettingsSchemaSource provides a mechanism for dealing with this by
 * allowing the creation of a new 'schema source' from which schemas can
 * be acquired.  This schema source can then become part of the metadata
 * associated with the plugin and queried whenever the plugin requires
 * access to some settings.
 *
 * @newin{2,32}
 */
class GIOMM_API SettingsSchema final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SettingsSchema;
  using BaseObjectType = GSettingsSchema;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType G_GNUC_CONST;


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GSettingsSchema*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GSettingsSchema*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GSettingsSchema*;

  SettingsSchema() = delete;

  // noncopyable
  SettingsSchema(const SettingsSchema&) = delete;
  auto operator=(const SettingsSchema&) -> SettingsSchema& = delete;

protected:
  // Do not derive this.  Gio::SettingsSchema can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


protected:


  //Ignore internal GSettingsSchema functions.


public:

  /** Get the ID of @a schema.
   *
   * @return The ID.
   */
  auto get_id() const -> Glib::ustring;

  /** Gets the path associated with @a schema, or <tt>nullptr</tt>.
   *
   * Schemas may be single-instance or relocatable.  Single-instance
   * schemas correspond to exactly one set of keys in the backend
   * database: those located at the path returned by this function.
   *
   * Relocatable schemas can be referenced by other schemas and can
   * therefore describe multiple sets of keys at different locations.  For
   * relocatable schemas, this function will return <tt>nullptr</tt>.
   *
   * @newin{2,32}
   *
   * @return The path of the schema, or <tt>nullptr</tt>.
   */
  auto get_path() const -> Glib::ustring;

  //Note that these don't need refreturn because they seem to return a reference
  //(they are documented as transfer:full)

  /** Gets the key named @a name from @a schema.
   *
   * It is a programmer error to request a key that does not exist.  See
   * g_settings_schema_list_keys().
   *
   * @newin{2,40}
   *
   * @param name The name of a key.
   * @return The SettingsSchemaKey for @a name.
   */
  auto get_key(const Glib::ustring& name) -> Glib::RefPtr<SettingsSchemaKey>;

  /** Gets the key named @a name from @a schema.
   *
   * It is a programmer error to request a key that does not exist.  See
   * g_settings_schema_list_keys().
   *
   * @newin{2,40}
   *
   * @param name The name of a key.
   * @return The SettingsSchemaKey for @a name.
   */
  auto get_key(const Glib::ustring& name) const -> Glib::RefPtr<const SettingsSchemaKey>;


  /** Checks if @a schema has a key named @a name.
   *
   * @newin{2,40}
   *
   * @param name The name of a key.
   * @return <tt>true</tt> if such a key exists.
   */
  auto has_key(const Glib::ustring& name) const -> bool;


  /** Introspects the list of keys on @a schema.
   *
   * You should probably not be calling this function from "normal" code
   * (since you should already know what keys are in your schema).  This
   * function is intended for introspection reasons.
   *
   * @newin{2,46}
   *
   * @return A list
   * of the keys on @a schema, in no defined order.
   */
  auto list_keys() const -> std::vector<Glib::ustring>;


  /** Gets the list of children in @a schema.
   *
   * @newin{2,44}
   *
   * @return A list of
   * the children on @a settings, in no defined order.
   */
  auto list_children() const -> std::vector<Glib::ustring>;


};

} // namespace Gio


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gio::SettingsSchema
 */
GIOMM_API
auto wrap(GSettingsSchema* object, bool take_copy = false) -> Glib::RefPtr<Gio::SettingsSchema>;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class GIOMM_API Value<Glib::RefPtr<Gio::SettingsSchema>> : public Glib::Value_RefPtrBoxed<Gio::SettingsSchema>
{
public:
  auto get() const -> CppType { return Glib::wrap(static_cast<GSettingsSchema*>(get_boxed()), true); }
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GIOMM_SETTINGSSCHEMA_H */

