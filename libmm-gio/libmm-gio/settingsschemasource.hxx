
#ifndef _GIOMM_SETTINGSSCHEMASOURCE_H
#define _GIOMM_SETTINGSSCHEMASOURCE_H

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


#include <libmm-gio/settingsschema.hxx>

#include <libmm-glib/ustring.hxx>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSettingsSchemaSource GSettingsSchemaSource;
#endif

namespace Gio
{

//TODO: Add some class documentation, though there is none in the C docs.

/** See SettingsSchema.
 *
 * @newin{2,32}
 */
class GIOMM_API SettingsSchemaSource final
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = SettingsSchemaSource;
  using BaseObjectType = GSettingsSchemaSource;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GSettingsSchemaSource*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GSettingsSchemaSource*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GSettingsSchemaSource*;

  SettingsSchemaSource() = delete;

  // noncopyable
  SettingsSchemaSource(const SettingsSchemaSource&) = delete;
  auto operator=(const SettingsSchemaSource&) -> SettingsSchemaSource& = delete;

protected:
  // Do not derive this.  Gio::SettingsSchemaSource can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


protected:


public:

  /** Gets the default system schema source.
   *
   * This function is not required for normal uses of Settings but it
   * may be useful to authors of plugin management systems or to those who
   * want to introspect the content of schemas.
   *
   * If no schemas are installed, <tt>nullptr</tt> will be returned.
   *
   * The returned source may actually consist of multiple schema sources
   * from different directories, depending on which directories were given
   * in `XDG_DATA_DIRS` and `GSETTINGS_SCHEMA_DIR`. For this reason, all
   * lookups performed against the default source should probably be done
   * recursively.
   *
   * @newin{2,32}
   *
   * @return The default schema source.
   */
  static auto get_default() -> Glib::RefPtr<SettingsSchemaSource>;


  /** Attempts to create a new schema source corresponding to the contents
   * of the given directory.
   *
   * This function is not required for normal uses of Settings but it
   * may be useful to authors of plugin management systems.
   *
   * The directory should contain a file called `gschemas.compiled` as
   * produced by the [glib-compile-schemas][glib-compile-schemas] tool.
   *
   * If @a trusted is <tt>true</tt> then `gschemas.compiled` is trusted not to be
   * corrupted. This assumption has a performance advantage, but can result
   * in crashes or inconsistent behaviour in the case of a corrupted file.
   * Generally, you should set @a trusted to <tt>true</tt> for files installed by the
   * system and to <tt>false</tt> for files in the home directory.
   *
   * In either case, an empty file or some types of corruption in the file will
   * result in Glib::FileError::INVALID_ARGUMENT being returned.
   *
   * If @a parent is non-<tt>nullptr</tt> then there are two effects.
   *
   * First, if g_settings_schema_source_lookup() is called with the
   *  @a recursive flag set to <tt>true</tt> and the schema can not be found in the
   * source, the lookup will recurse to the parent.
   *
   * Second, any references to other schemas specified within this
   * source (ie: `child` or `extends`) references may be resolved
   * from the @a parent.
   *
   * For this second reason, except in very unusual situations, the
   *  @a parent should probably be given as the default schema source, as
   * returned by g_settings_schema_source_get_default().
   *
   * @newin{2,32}
   *
   * @param directory The filename of a directory.
   * @param parent A SettingsSchemaSource, or <tt>nullptr</tt>.
   * @param trusted <tt>true</tt>, if the directory is trusted.
   *
   * @throws Glib::Error
   */
  static auto create(const std::string& directory, bool trusted, const Glib::RefPtr<SettingsSchemaSource>& parent =  get_default()) -> Glib::RefPtr<SettingsSchemaSource>;

  //Note this doesn't need refreturn because the C function returns a reference.
  //- it is documented as transfer:full

  /** Looks up a schema with the identifier @a schema_id in @a source.
   *
   * This function is not required for normal uses of Settings but it
   * may be useful to authors of plugin management systems or to those who
   * want to introspect the content of schemas.
   *
   * If the schema isn't found directly in @a source and @a recursive is <tt>true</tt>
   * then the parent sources will also be checked.
   *
   * If the schema isn't found, <tt>nullptr</tt> is returned.
   *
   * @newin{2,32}
   *
   * @param schema_id A schema ID.
   * @param recursive <tt>true</tt> if the lookup should be recursive.
   * @return A new SettingsSchema.
   */
  auto lookup(const Glib::ustring& schema_id, bool recursive) -> Glib::RefPtr<SettingsSchema>;

  /** Looks up a schema with the identifier @a schema_id in @a source.
   *
   * This function is not required for normal uses of Settings but it
   * may be useful to authors of plugin management systems or to those who
   * want to introspect the content of schemas.
   *
   * If the schema isn't found directly in @a source and @a recursive is <tt>true</tt>
   * then the parent sources will also be checked.
   *
   * If the schema isn't found, <tt>nullptr</tt> is returned.
   *
   * @newin{2,32}
   *
   * @param schema_id A schema ID.
   * @param recursive <tt>true</tt> if the lookup should be recursive.
   * @return A new SettingsSchema.
   */
  auto lookup(const Glib::ustring& schema_id, bool recursive) const -> Glib::RefPtr<const SettingsSchema>;


  /** Lists the schemas in a given source.
   *
   * Do not call this function from normal programs. It is designed for use by
   * database editors, commandline tools, etc.
   *
   * @newin{2,64}
   *
   * @param relocatable Whether you want the list of relocatable schemas
   * (<tt>true</tt>) or the list of non-relocatable schemas (<tt>false</tt>)
   * for this source. Non-relocatable schemas are those for which you can call
   * Gio::Settings::create() without specifying a path. Relocatable schemas are
   * those for which you must pass a path to Gio::Settings::create().
   *
   * @param recursive If <tt>true</tt>, the list will include parent sources.
   * If <tt>false</tt>, it will only include the schemas from one source (i.e.
   * one directory). You probably want to recurse.
   *
   * @return a vector of the names of the schemas matching the given parameters.
   */
  auto list_schemas(bool relocatable, bool recursive) const -> std::vector<Glib::ustring>;


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
 * @relates Gio::SettingsSchemaSource
 */
GIOMM_API
auto wrap(GSettingsSchemaSource* object, bool take_copy = false) -> Glib::RefPtr<Gio::SettingsSchemaSource>;

} // namespace Glib


#endif /* _GIOMM_SETTINGSSCHEMASOURCE_H */

