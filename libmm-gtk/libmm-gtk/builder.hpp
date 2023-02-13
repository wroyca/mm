
#ifndef _GTKMM_BUILDER_H
#define _GTKMM_BUILDER_H


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <vector>

#include <libmm-gtk/widget.hpp>
#include <libmm-gio/resource.hpp> //For ResourceError, thrown by create_from_resource().
#include <utility> //For std::forward()


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilder = struct _GtkBuilder;
using GtkBuilderClass = struct _GtkBuilderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API Builder_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{
class GTKMM_API Application;

/**  %Exception class for Gdk::Builder errors.
 */
class BuilderError : public Glib::Error
{
public:
  /**  @var Code INVALID_TYPE_FUNCTION
   * A type-func attribute didn’t name
   * a function that returns a `GType`.
   *
   *  @var Code UNHANDLED_TAG
   * The input contained a tag that `Gtk::Builder`
   * can’t handle.
   *
   *  @var Code MISSING_ATTRIBUTE
   * An attribute that is required by
   * `Gtk::Builder` was missing.
   *
   *  @var Code INVALID_ATTRIBUTE
   * `Gtk::Builder` found an attribute that
   * it doesn’t understand.
   *
   *  @var Code INVALID_TAG
   * `Gtk::Builder` found a tag that
   * it doesn’t understand.
   *
   *  @var Code MISSING_PROPERTY_VALUE
   * A required property value was
   * missing.
   *
   *  @var Code INVALID_VALUE
   * `Gtk::Builder` couldn’t parse
   * some attribute value.
   *
   *  @var Code VERSION_MISMATCH
   * The input file requires a newer version
   * of GTK.
   *
   *  @var Code DUPLICATE_ID
   * An object id occurred twice.
   *
   *  @var Code OBJECT_TYPE_REFUSED
   * A specified object type is of the same type or
   * derived from the type of the composite class being extended with builder XML.
   *
   *  @var Code TEMPLATE_MISMATCH
   * The wrong type was specified in a composite class’s template XML.
   *
   *  @var Code INVALID_PROPERTY
   * The specified property is unknown for the object class.
   *
   *  @var Code INVALID_SIGNAL
   * The specified signal is unknown for the object class.
   *
   *  @var Code INVALID_ID
   * An object id is unknown.
   *
   *  @var Code INVALID_FUNCTION
   * A function could not be found. This often happens
   * when symbols are set to be kept private. Compiling code with -rdynamic or using the
   * `gmodule-export-2.0` pkgconfig module can fix this problem.
   *
   *  @enum Code
   *
   * %Error codes that identify various errors that can occur while using
   * `Gtk::Builder`.
   */
  enum Code
  {
    INVALID_TYPE_FUNCTION,
    UNHANDLED_TAG,
    MISSING_ATTRIBUTE,
    INVALID_ATTRIBUTE,
    INVALID_TAG,
    MISSING_PROPERTY_VALUE,
    INVALID_VALUE,
    VERSION_MISMATCH,
    DUPLICATE_ID,
    OBJECT_TYPE_REFUSED,
    TEMPLATE_MISMATCH,
    INVALID_PROPERTY,
    INVALID_SIGNAL,
    INVALID_ID,
    INVALID_FUNCTION
  };

  GTKMM_API BuilderError(Code error_code, const Glib::ustring& error_message);
  GTKMM_API explicit BuilderError(GError* gobject);
  GTKMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GTKMM_API static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::BuilderError::Code> : public Glib::Value_Enum<Gtk::BuilderError::Code>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Build an interface from an XML UI definition description.
 *
 * This object represents an `instantiation' of an UI definition description.
 * When one of these objects is created, the XML file is read, and the user interface
 * is created. The %Gtk::Builder object then provides an interface for accessing the
 * widgets in the user interface by the names assigned to them inside the UI description.
 *
 * A %Gtk::Builder holds a reference to all objects that it has constructed
 * and drops these references when it is deleted. This deletion can
 * cause the destruction of non-widget objects or widgets which are not
 * contained in a toplevel window. For toplevel windows constructed by a
 * builder, it is the responsibility of the user to get them with get_widget()
 * or get_widget_derived() and delete them to get rid of them and all
 * the widgets they contain.
 *
 * The methods get_widget() and get_widget_derived()
 * can be used to access the widgets in the interface by the names assigned
 * to them inside the UI description. Toplevel windows returned by these
 * methods will stay around until the user explicitly deletes them.
 * Other widgets will either be part of a
 * larger hierarchy constructed by the builder (in which case you should
 * not have to worry about their lifecycle), or without a parent, in which
 * case they have to be added to some container before the builder is deleted
 * to make use of them.
 *
 * Non-widget objects need to be fetched with get_object() or get_objects()
 * to keep them beyond the lifespan of the builder.
 *
 * @par %Gtk::Builder and Glib::Property
 * A derived widget that contains Glib::Property members must be registered with
 * its own name in the GType system. It must be registered before any of the
 * create_from_*() or add_from_*() methods are called, meaning that you may have
 * to create an instance of your derived widget just to have its class registered.
 * There is no reasonably easy way to combine %Gtk::Builder with non-widget objects
 * containing Glib::Property members. Combining it with widgets containing
 * Glib::Property members requires glibmm 2.62 or newer.
 * See also get_widget_derived() and Glib::Property.
 *
 * @newin{2,12}
 */

class GTKMM_API Builder : public Glib::Object
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Builder;
  using CppClassType = Builder_Class;
  using BaseObjectType = GtkBuilder;
  using BaseClassType = GtkBuilderClass;

  // noncopyable
  Builder(const Builder&) = delete;
  auto operator=(const Builder&) -> Builder& = delete;

private:  friend class Builder_Class;
  static CppClassType builder_class_;

protected:
  explicit Builder(const Glib::ConstructParams& construct_params);
  explicit Builder(GtkBuilder* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Builder(Builder&& src) noexcept;
  auto operator=(Builder&& src) noexcept -> Builder&;

  ~Builder() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GtkBuilder*       { return reinterpret_cast<GtkBuilder*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GtkBuilder* { return reinterpret_cast<GtkBuilder*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() -> GtkBuilder*;

private:


protected:
  Builder();


public:
  /** Creates a new builder object.
   */

  static auto create() -> Glib::RefPtr<Builder>;


  /** Parses a file containing a GtkBuilder UI definition.
   *
   * @param filename the name of the file to parse.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::FileError
   *
   * @newin{2,12}
   */
  static auto create_from_file(const std::string& filename) -> Glib::RefPtr<Builder>;

  /** Parses a file containing a GtkBuilder UI definition, building only the requested object.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param filename the name of the file to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::FileError
   *
   * @newin{2,14}
   */
  static auto create_from_file(const std::string& filename, const Glib::ustring& object_id) -> Glib::RefPtr<Builder>;

  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a file containing a GtkBuilder UI definition, building only the requested object.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param filename the name of the file to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::FileError
   *
   * @newin{2,16}
   */
  static auto create_from_file(const std::string& filename, const char* object_id) -> Glib::RefPtr<Builder>;

  /** Parses a file containing a GtkBuilder UI definition, building only the requested objects.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param filename the name of the file to parse.
   * @param object_ids The objects to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::FileError
   *
   * @newin{2,14}
   */
  static auto create_from_file(const std::string& filename, const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>;


  /** Parses a resource file containing a GtkBuilder UI definition.
   *
   * @param resource_path The path of the resource file to parse.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  static auto create_from_resource(const std::string& resource_path) -> Glib::RefPtr<Builder>;

  /** Parses a resource file containing a GtkBuilder UI definition, building only the requested object.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  static auto create_from_resource(const std::string& resource_path, const Glib::ustring& object_id) -> Glib::RefPtr<Builder>;

  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a resource file containing a GtkBuilder UI definition, building only the requested object.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  static auto create_from_resource(const std::string& resource_path, const char* object_id) -> Glib::RefPtr<Builder>;

  /** Parses a resource file containing a GtkBuilder UI definition, building only the requested objects.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_ids The objects to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  static auto create_from_resource(const std::string& resource_path, const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>;


  /** Parses a string containing a GtkBuilder UI definition.
   *
   * @param buffer: the string to parse
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,12}
   */
  static auto create_from_string(const Glib::ustring& buffer) -> Glib::RefPtr<Builder>;

  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a string containing a GtkBuilder UI definition building only the requested object.
   *
   * @param buffer The string to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,16}
   */
  static auto create_from_string(const Glib::ustring& buffer, const char* object_id) -> Glib::RefPtr<Builder>;

  /** Parses a string containing a GtkBuilder UI definition building only the requested object.
   *
   * @param buffer The string to parse.
   * @param object_id The object to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  static auto create_from_string(const Glib::ustring& buffer, const Glib::ustring& object_id) -> Glib::RefPtr<Builder>;

  /** Parses a string containing a GtkBuilder UI definition building only the requested objects.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param buffer the string to parse
   * @param object_ids The objects to build.
   * @result A new Builder object, or a null pointer if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  static auto create_from_string(const Glib::ustring& buffer, const std::vector<Glib::ustring>& object_ids) -> Glib::RefPtr<Builder>;


  /** Parses a file containing a GtkBuilder UI definition,
   * and merges it with the current contents of the builder.
   *
   * @param filename The file to parse.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  auto add_from_file(const std::string& filename) -> bool;

  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a file containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param filename The file to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::MarkupError
   *
   * @newin{2,16}
   */
  auto add_from_file(const std::string& filename, const char* object_id) -> bool;

  /** Parses a file containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param filename The file to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  auto add_from_file(const std::string& filename, const Glib::ustring& object_id) -> bool;


  /** Parses a file containing a UI definition building only the
   * requested objects and merges them with the current contents
   * of @a builder.
   *
   * Upon errors, 0 will be returned and @a error will be assigned a
   * `GError` from the GTK_BUILDER_ERROR, G_MARKUP_ERROR or G_FILE_ERROR
   * domain.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a `Gtk::TreeView` that depends on its
   * `Gtk::TreeModel`), you have to explicitly list all of them in @a object_ids.
   *
   * @param filename The name of the file to parse.
   * @param object_ids Nul-terminated array of objects to build.
   * @return <tt>true</tt> on success, <tt>false</tt> if an error occurred.
   *
   * @throws Glib::Error
   */
  auto add_from_file(const std::string& filename, const std::vector<Glib::ustring>& object_ids) -> bool;


  /** Parses a resource file containing a GtkBuilder UI definition,
   * and merges it with the current contents of the builder.
   *
   * @param resource_path The path of the resource file to parse.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  auto add_from_resource(const std::string& resource_path) -> bool;

  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a resource file containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  auto add_from_resource(const std::string& resource_path, const char* object_id) -> bool;

  /** Parses a resource file containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a GtkTreeView that depends on its
   * GtkTreeModel), you have to explicitely list all of them.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError, Gio::ResourceError
   *
   * @newin{3,6}
   */
  auto add_from_resource(const std::string& resource_path, const Glib::ustring& object_id) -> bool;


  /** Parses a resource file containing a UI definition, building
   * only the requested objects and merges them with the current
   * contents of @a builder.
   *
   * Upon errors, 0 will be returned and @a error will be assigned a
   * `GError` from the GTK_BUILDER_ERROR, G_MARKUP_ERROR or G_RESOURCE_ERROR
   * domain.
   *
   * If you are adding an object that depends on an object that is not
   * its child (for instance a `Gtk::TreeView` that depends on its
   * `Gtk::TreeModel`), you have to explicitly list all of them in @a object_ids.
   *
   * @param resource_path The path of the resource file to parse.
   * @param object_ids Nul-terminated array of objects to build.
   * @return <tt>true</tt> on success, <tt>false</tt> if an error occurred.
   *
   * @throws Glib::Error
   */
  auto add_from_resource(const std::string& resource_path, const std::vector<Glib::ustring>& object_ids) -> bool;


  //This is just to avoid the ambiguous call when using a string literal,
  //caused by the overload that takes a std::vector<Glib::ustring>.
  /** Parses a string containing a GtkBuilder UI definition
   * and merges it with the current contents of the builder.
   *
   * @param buffer The string to parse.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,12}
   */
  auto add_from_string(const Glib::ustring& buffer) -> bool;

  /** Parses a string containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * @param buffer The string to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,16}
   */
  auto add_from_string(const Glib::ustring& buffer, const char* object_id) -> bool;

  /** Parses a string containing a GtkBuilder UI definition,
   * building only the requested object,
   * and merges it with the current contents of the builder.
   *
   * @param buffer The string to parse.
   * @param object_id The object to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  auto add_from_string(const Glib::ustring& buffer, const Glib::ustring& object_id) -> bool;

  /** Parses a string containing a GtkBuilder UI definition,
   * building only the requested objects,
   * and merges it with the current contents of the builder.
   *
   * @param buffer The string to parse.
   * @param object_ids The objects to build.
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,14}
   */
  auto add_from_string(const Glib::ustring& buffer, const std::vector<Glib::ustring>& object_ids) -> bool;


  /** Parses a string containing a GtkBuilder UI definition
   * and merges it with the current contents of the builder.
   *
   * @param buffer The string to parse.
   * @param length The length of @a buffer (may be -1 if @a buffer is nul-terminated).
   * @result true on success or false if an error occurred.
   * @throws BuilderError, Glib::MarkupError
   *
   * @newin{2,12}
   */
  auto add_from_string(const char* buffer, gssize length) -> bool;


  /** Add @a object to the @a builder object pool so it can be
   * referenced just like any other object built by builder.
   *
   * Only a single object may be added using @a name. However,
   * it is not an error to expose the same object under multiple
   * names. `get_object()` may be used to determine
   * if an object has already been added with @a name.
   *
   * @param name The name of the object exposed to the builder.
   * @param object The object to expose.
   */
  void expose_object(const Glib::ustring& name, const Glib::RefPtr<Glib::Object>& object);


  /** Add @a widget to the builder object pool so it can be referenced just like any
   * other object built by builder.
   *
   * @newin{3,12}
   *
   * @param name The name of the widget exposed to the builder.
   * @param widget The widget to expose.
   */
  void expose_widget(const Glib::ustring& name, Widget& widget);

  //TODO: Custom-implement this and prevent it from being used with GTK_WIDGET-derived types?
  // A Builder can contain objects that don't derive from Buildable,
  // for instance if objects have been added with expose_object().


  /** Gets the object named @a name.
   *
   * @newin{2,12}
   *
   * @param name Name of object to get.
   * @return The object named @a name or <tt>nullptr</tt> if it could not be found in the object tree.
   */
  auto get_object(const Glib::ustring& name) -> Glib::RefPtr<Glib::Object>;


  /** Gets the object named @a name.
   *
   * @newin{3,8}
   *
   * @param name Name of object to get.
   * @return The object named @a name or <tt>nullptr</tt> if it could not be found in the object tree.
   */
  auto get_object(const Glib::ustring& name) const -> Glib::RefPtr<const Glib::Object>;

  /** Gets the object named @a name, cast to a specific derived type.
   *
   * For instance:
   * @code
   * auto adjustment = refBuilder->get_object<Gtk::Adjustment>("adjustment_id");
   * adjustment->set_value(42);
   * @endcode
   *
   * @newin{3,96}
   *
   * @param name Name of object to get.
   * @return The object named @a name or <tt>nullptr</tt> if it could not be
   *   found in the object tree or could not be cast to the specified type.
   */
  template <class T_Object> inline
  auto get_object(const Glib::ustring& name) -> Glib::RefPtr<T_Object>
  {
    return std::dynamic_pointer_cast<T_Object>(get_object(name));
  }

  /** See the non-const version.
   * @newin{3,96}
   */
  template <class T_Object> inline
  auto get_object(const Glib::ustring& name) const -> Glib::RefPtr<const T_Object>
  {
    return const_cast<Builder*>(this)->get_object<const T_Object>(name);
  }

  /** Gets a widget from the Builder file.
   *
   * For instance:
   * @code
   * auto pGrid = refBuilder->get_widget<Gtk::Grid>("mygrid");
   * @endcode
   *
   * This method prints a warning message to the console if the widget
   * doesn't exist or has the wrong type, so you don't need to check that
   * manually.
   *
   * Note that you are responsible for deleting top-level widgets (windows and
   * dialogs) instantiated by the Builder object. Other widgets are instantiated as
   * managed so they will be deleted automatically if you add them to a
   * container widget.
   *
   * @param name The name of the widget.
   * @return A pointer to the widget, or <tt>nullptr</tt> on failure.
   *
   * @newin{3,96}
   */
  template <class T_Widget> inline
  auto get_widget(const Glib::ustring& name) -> T_Widget*
  {
    T_Widget* widget = nullptr;

    // The dynamic_cast<> should never fail if get_widget_checked() succeeded.
    widget = dynamic_cast<T_Widget*>(this->get_widget_checked(name, T_Widget::get_base_type()));

    if(!widget)
      g_critical("Gtk::Builder::get_widget(): dynamic_cast<> failed.");

    return widget;
  }

  /** See the non-const version.
   * @newin{3,96}
   */
  template <class T_Widget> inline
  auto get_widget(const Glib::ustring& name) const -> const T_Widget*
  {
    return const_cast<Builder*>(this)->get_widget<const T_Widget>(name);
  }

  /** Gets a widget whose details are specified in the GtkBuilder file,
   * but which is implemented by your own derived class.
   *
   * Your class must have a constructor like so:
   * @code
   * MyDerivedDialog::MyDerivedDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
   * : Gtk::Dialog(cobject) //Calls the base class constructor
   * @endcode
   * or, with additional parameters, for example:
   * @code
   * MyDerivedDialog::MyDerivedDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder,
   *   const Glib::ustring& msg, bool warning)
   * : Gtk::Dialog(cobject) //Calls the base class constructor
   * @endcode
   *
   * For instance:
   * @code
   * auto pDialog1 = Gtk::Builder::get_widget_derived<MyDerivedDialog>(refBuilder, "mydialog1");
   * auto pDialog2 = Gtk::Builder::get_widget_derived<MyDerivedDialog>(refBuilder, "mydialog2", "A storm is imminent!", true);
   * @endcode
   *
   * @note
   * If get_widget_derived() is called more than once for the same widget (the
   * same @a name), only the first call will call the widget's constructor.
   * The following calls will return a pointer to the widget instance that
   * was constructed by the first call.
   *
   * @par %Gtk::Builder and Glib::Property
   * If the widget contains Glib::Property members, your constructor must call
   * the Glib::ObjectBase constructor with a new GType name:
   * @code
   * MyDerivedDialog::MyDerivedDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
   * : Glib::ObjectBase("MyDialog"), // The GType name will be gtkmm__CustomObject_MyDialog
   *   Gtk::Dialog(cobject) // Calls the base class constructor
   *   m_my_property(*this, "my-property")
   * @endcode
   *
   * @param builder The Gtk::Builder from which to get the widget.
   * @param name The name of the widget.
   * @param args Additional arguments to pass to the constructor of the derived class.
   * @return A pointer to the widget, or <tt>nullptr</tt> on failure.
   *
   * @newin{3,96}
   */
  template <typename T_Widget, typename... Args> inline
  static auto get_widget_derived(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring& name, Args&&... args) -> T_Widget*
  {
     // Get the widget from the GtkBuilder file.
     using cwidget_type = typename T_Widget::BaseObjectType;
     auto pCWidget = (cwidget_type*)builder->get_cwidget(name);

     //The error was already reported by get_cwidget().
     if(!pCWidget)
       return nullptr;

     T_Widget* widget = nullptr;

     //Check whether there is already a C++ wrapper instance associated with this C instance:
     Glib::ObjectBase* pObjectBase = ObjectBase::_get_current_wrapper((GObject*)pCWidget);

     //If there is already a C++ instance, then return it again:
     if(pObjectBase)
     {
       widget = dynamic_cast<T_Widget*>( Glib::wrap((GtkWidget*)pCWidget) );
       //Newer, more spec-complaint, versions of g++ cannot resolve a specific wrap() function in a template.

       //The dynamic cast checks that it is of the correct type.
       //Somebody might be trying to call get_widget_derived() after already calling get_widget(),
       //or after already calling get_widget_derived() with a different derived C++ type.
       if(!widget)
        g_critical("Gtk::Builder::get_widget_derived(): dynamic_cast<> failed. An existing C++ instance, of a different type, seems to exist.");
     }
     else
     {
       //Create a new C++ instance to wrap the existing C instance:

       //Set the output variable. We needed to do this because we can not template the return type.
       widget = new T_Widget(pCWidget, builder, std::forward<Args>(args)...);
       // Don't add reference to widget. That's done only in methods that return
       // a Glib::RefPtr<Something>.
     }

    return widget;
  }

  /** See the non-const version.
   * @newin{3,96}
   */
  template <typename T_Widget, typename... Args> inline
  static auto get_widget_derived(const Glib::RefPtr<const Gtk::Builder>& builder, const Glib::ustring& name, Args&&... args) -> const T_Widget*
  {
    return get_widget_derived<const T_Widget>(std::const_pointer_cast<Gtk::Builder>(builder), name, std::forward<Args>(args)...);
  }


  /** Gets all objects that have been constructed by the Gtk::Builder.
   *
   * @newin{3,8}
   *
   * @return A vector containing all the objects
   * constructed by the Gtk::Builder instance.
   */
  auto get_objects() -> std::vector<Glib::RefPtr<Glib::Object> >;


  /** Gets all objects that have been constructed by the Gtk::Builder.
   *
   * @newin{3,8}
   *
   * @return A vector containing all the objects
   * constructed by the Gtk::Builder instance.
   */
  auto get_objects() const -> std::vector<Glib::RefPtr<const Glib::Object> >;


  /** Sets the translation domain of @a builder.
   *
   * @param domain The translation domain.
   */
  void set_translation_domain(const Glib::ustring& domain);

  /** Gets the translation domain of @a builder.
   *
   * @return The translation domain.
   */
  auto get_translation_domain() const -> Glib::ustring;

  // We ignore gtk_builder_get_type_from_name() because it only seems useful when implementing GtkBuildable for widgets.

  // We ignore BuilderScope methods and property because it seems unlikely
  // that a user of Builder wants to change the scope.


  /** The translation domain used when translating property values that
   * have been marked as translatable.
   *
   * If the translation domain is <tt>nullptr</tt>, `Gtk::Builder` uses gettext(),
   * otherwise Glib::dgettext().
   *
   * Default value: ""
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_translation_domain() -> Glib::PropertyProxy< Glib::ustring > ;

/** The translation domain used when translating property values that
   * have been marked as translatable.
   *
   * If the translation domain is <tt>nullptr</tt>, `Gtk::Builder` uses gettext(),
   * otherwise Glib::dgettext().
   *
   * Default value: ""
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  auto property_translation_domain() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >;


protected:
  auto get_widget_checked(const Glib::ustring& name, GType type) -> Gtk::Widget*;
  auto get_cwidget(const Glib::ustring& name) -> GtkWidget*;

private:
  bool no_gtkmm_derived_types {false};
  void set_no_gtkmm_derived_types(bool status);
  auto get_no_gtkmm_derived_types() const -> bool;
  friend class GTKMM_API Buildable_Class;
  friend class GTKMM_API BuilderScope_Class;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Builder
   */
  GTKMM_API
  auto wrap(GtkBuilder* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Builder>;
}


#endif /* _GTKMM_BUILDER_H */

