// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_ICON_H
#define _GIOMM_ICON_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The giomm Development Team
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


#include <mm/glib/interface.hpp>
#include <mm/glib/variant.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GIconIface GIconIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GIcon = struct _GIcon;
using GIconClass = struct _GIconClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Icon_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** This is a very minimal interface for icons.
 * It provides functions for checking the equality of two icons,
 * hashing of icons and serializing an icon to and from strings and Variants.
 *
 * Gio::Icon does not provide the actual pixmap for the icon as this is out
 * of GIO's scope. However implementations of Icon may contain the name of an
 * icon (see ThemedIcon), or the path to an icon (see LoadableIcon).
 *
 * To obtain a hash of an Icon instance, see hash().
 *
 * To check if two Icon instances are equal, see equal().
 *
 * For serializing an Icon, use serialize() and deserialize().
 *
 * @newin{2,16}
 */

class GIOMM_API Icon : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Icon;
  using CppClassType = Icon_Class;
  using BaseObjectType = GIcon;
  using BaseClassType = GIconIface;

  // noncopyable
  Icon(const Icon&) = delete;
  auto operator=(const Icon&) -> Icon& = delete;

private:
  friend class Icon_Class;
  static CppClassType icon_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Icon();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Icon(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Icon(GIcon* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Icon(Icon&& src) noexcept;
  auto operator=(Icon&& src) noexcept -> Icon&;

  ~Icon() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GIcon*       { return reinterpret_cast<GIcon*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GIcon* { return reinterpret_cast<GIcon*>(gobject_); }

private:


public:
  // We can't just use a _WRAP_CREATE macro here since this is an abstract
  // interface class, so implement it by hand
  /** Generate an Icon instance from @a str.
   *
   * This function can fail if @a str is not valid. See to_string() for discussion.
   *
   * If your application or library provides one or more Icon
   * implementations, you need to ensure that each GType is registered
   * with the type system prior to calling create().
   *
   * @newin{2,20}
   *
   * @param str A string obtained via to_string().
   * @return An object implementing the Icon interface, or throws an exception.
   * @throw Gio::Error
   */
  static auto create(const std::string& str) -> Glib::RefPtr<Icon>;


  /** Gets a hash for an icon.
   *
   * Virtual: hash
   *
   * @return A <tt>unsigned int</tt> containing a hash for the @a icon, suitable for
   * use in a HashTable or similar data structure.
   */
  auto hash() const -> guint;

  /** Generates a textual representation of @a icon that can be used for
   * serialization such as when passing @a icon to a different process or
   * saving it to persistent storage. Use g_icon_new_for_string() to
   * get @a icon back from the returned string.
   *
   * The encoding of the returned string is proprietary to Icon except
   * in the following two cases
   *
   * - If @a icon is a FileIcon, the returned string is a native path
   * (such as `/path/to/my icon.png`) without escaping
   * if the File for @a icon is a native file.  If the file is not
   * native, the returned string is the result of g_file_get_uri()
   * (such as `sftp://path/to/my%20icon.png`).
   *
   * - If @a icon is a ThemedIcon with exactly one name and no fallbacks,
   * the encoding is simply the name (such as `network-server`).
   *
   * Virtual: to_tokens
   * @newin{2,20}
   *
   * @return An allocated NUL-terminated UTF8 string or
   * <tt>nullptr</tt> if @a icon can't be serialized.
   */
  auto to_string() const -> std::string;


  // TODO: should this, and File's equal(), be virtual, in order to
  // be available to derived classes?
  auto equal(const Glib::RefPtr<Icon>& other) const -> bool;


  /** Serializes a Icon into a Variant. An equivalent Icon can be retrieved
   * back by calling g_icon_deserialize() on the returned value.
   * As serialization will avoid using raw icon data when possible, it only
   * makes sense to transfer the Variant between processes on the same machine,
   * (as opposed to over the network), and within the same file system namespace.
   *
   * @newin{2,48}
   *
   * @return A Variant, or <tt>nullptr</tt> when serialization fails. The Variant will not be floating.
   */
  auto serialize() const -> Glib::VariantBase;

  /** Deserializes a Icon previously serialized using g_icon_serialize().
   *
   * @newin{2,48}
   *
   * @param value A Variant created with g_icon_serialize().
   * @return A Icon, or <tt>nullptr</tt> when deserialization fails.
   */
  static auto deserialize(const Glib::VariantBase& value) -> Glib::RefPtr<Icon>;

protected:
  //_WRAP_VFUNC(guint hash() const, "hash")

  // TODO: also kind of related to equal() being virtual or not,
  // do we need to have equal_vfunc()? Or rather, why would we want
  // to have it generally...


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


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
   * @relates Gio::Icon
   */
  GIOMM_API
  auto wrap(GIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::Icon>;

} // namespace Glib


#endif /* _GIOMM_ICON_H */

