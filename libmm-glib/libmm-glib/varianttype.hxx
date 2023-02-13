
#ifndef _GLIBMM_VARIANTTYPE_H
#define _GLIBMM_VARIANTTYPE_H


/* Copyright 2010 The glibmm Development Team
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


#include <libmm-glib/mm-glibconfig.hxx>
#include <glib-object.h> //For gsize
#include <libmm-glib/value.hxx>
#include <string>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GVariantType GVariantType;
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{

/** VariantType - The VariantBase type system.
 * The VariantBase type system is based, in large part, on the D-Bus type
 * system, with two major changes and some minor lifting of restrictions. <a
 * href="http://dbus.freedesktop.org/doc/dbus-specification.html">The
 * D-Bus specification</a>, therefore, provides a significant amount of
 * information that is useful when working with VariantBase.
 *
 * The first major change with respect to the D-Bus type system is the
 * introduction of maybe (or "nullable") types. Any type in VariantBase
 * can be converted to a maybe type, in which case, "nothing" (or "null")
 * becomes a valid value. Maybe types have been added by introducing the
 * character "m" to type strings.
 *
 * The second major change is that the VariantBase type system supports
 * the concept of "indefinite types" -- types that are less specific than the
 * normal types found in D-Bus. For example, it is possible to speak of "an
 * array of any type" in VariantBase, where the D-Bus type system would
 * require you to speak of "an array of integers" or "an array of strings".
 * Indefinite types have been added by introducing the characters "*", "?" and
 * "r" to type strings.
 *
 * Finally, all arbitrary restrictions relating to the complexity of types are
 * lifted along with the restriction that dictionary entries may only appear
 * nested inside of arrays.
 *
 * Just as in D-Bus, VariantBase types are described with strings ("type
 * strings"). Subject to the differences mentioned above, these strings are of
 * the same form as those found in D-Bus. Note, however: D-Bus always works in
 * terms of messages and therefore individual type strings appear nowhere in
 * its interface. Instead, "signatures" are a concatenation of the strings of
 * the type of each argument in a message. VariantBase deals with single
 * values directly so VariantBase type strings always describe the type
 * of exactly one value. This means that a D-Bus signature string is generally
 * not a valid VariantBase type string -- except in the case that it is
 * the signature of a message containing exactly one argument.
 *
 * An indefinite type is similar in spirit to what may be called an abstract
 * type in other type systems. No value can exist that has an indefinite type
 * as its type, but values can exist that have types that are subtypes of
 * indefinite types. That is to say, VariantBase::get_type() will never
 * return an indefinite type, but calling VariantBase::is_of_type() with
 * an indefinite type may return <tt>true</tt>. For example, you cannot have a
 * value that represents "an array of no particular type", but you can have an
 * "array of integers" which certainly matches the type of "an array of no
 * particular type", since "array of integers" is a subtype of "array of no
 * particular type".
 *
 * This is similar to how instances of abstract classes may not directly exist
 * in other type systems, but instances of their non-abstract subtypes may. For
 * example, in gtkmm, no object that has the type of Gtk::Bin can exist (since
 * Gtk::Bin is an abstract class), but a Gtk::Window can certainly be
 * instantiated, and you would say that the Gtk::Window is a Gtk::Bin (since
 * Gtk::Window is a subclass of Gtk::Bin).
 *
 * See the underlying GVariantType documentation for <a href="http://library.gnome.org/devel/glib/unstable/glib-GVariantType.html#gvariant-typestrings">detailed description of the VariantBase type strings</a>.
 *
 * @newin{2,28}
 * @ingroup Variant
 */
class GLIBMM_API VariantType
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VariantType;
  using BaseObjectType = GVariantType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Constructs an invalid object.
   * E.g. for output arguments to methods. There is not much you can do with
   * the object before it has been assigned a valid value.
   */
  VariantType();

  // Use make_a_copy=true when getting it directly from a struct.
  explicit VariantType(GVariantType* castitem, bool make_a_copy = false);

  VariantType(const VariantType& src);
  auto operator=(const VariantType& src) -> VariantType&;

  VariantType(VariantType&& other) noexcept;
  auto operator=(VariantType&& other) noexcept -> VariantType&;

  ~VariantType() noexcept;

  void swap(VariantType& other) noexcept;

  auto       gobj() -> GVariantType*       { return gobject_; }
  auto gobj() const -> const GVariantType* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GVariantType*;

protected:
  GVariantType* gobject_;

private:


public:

  /** Copy the C item into a new VariantType instance.
   */
  explicit VariantType(const GVariantType* castitem);

  /** Creates a new VariantType corresponding to the type string given by @a type_string.
    *
    * It is a programmer error to call this function with an invalid type string. Use string_is_valid() if you are unsure.
    */
  explicit VariantType(const std::string& type_string);


  auto operator=(const GVariantType* castitem) -> VariantType&;


//The C parameters are actually const, but gmmproc doesn't understand that,
//so we add a m4 conversion to satisfy it:


  /** Constructs the type corresponding to an array of elements of the
   * type @a type.
   *
   * It is appropriate to call g_variant_type_free() on the return value.
   *
   * @newin{2,24}
   *
   * @param element A VariantType.
   * @return A new array VariantType.
   */
  static auto create_array(const VariantType& element) -> VariantType;

  /** Constructs the type corresponding to a maybe instance containing
   * type @a type or Nothing.
   *
   * It is appropriate to call g_variant_type_free() on the return value.
   *
   * @newin{2,24}
   *
   * @param element A VariantType.
   * @return A new maybe VariantType.
   */
  static auto create_maybe(const VariantType& element) -> VariantType;

  /** Constructs a new tuple type, from @a items.
    *
    * @param items A vector of VariantTypes, one for each item.
    * @return A new tuple VariantType.
    *
    * @newin{2,36}
    */
  static auto create_tuple(const std::vector<VariantType>& items) -> VariantType;


  /** Constructs the type corresponding to a dictionary entry with a key
   * of type @a key and a value of type @a value.
   *
   * It is appropriate to call g_variant_type_free() on the return value.
   *
   * @newin{2,24}
   *
   * @param key A basic VariantType.
   * @param value A VariantType.
   * @return A new dictionary entry VariantType.
   */
  static auto create_dict_entry(const VariantType& key, const VariantType& value) -> VariantType;


  /** Returns the length of the type string corresponding to the given
   *  @a type.  This function must be used to determine the valid extent of
   * the memory region returned by g_variant_type_peek_string().
   *
   * @newin{2,24}
   *
   * @return The length of the corresponding type string.
   */
  auto get_string_length() const -> gsize;

  /** Returns the type string corresponding to the given @a type.  The
   * result is not nul-terminated; in order to determine its length you
   * must call g_variant_type_get_string_length().
   *
   * To get a nul-terminated string, see g_variant_type_dup_string().
   *
   * @newin{2,24}
   *
   * @return The corresponding type string (not nul-terminated).
   */

  auto get_string() const -> std::string;


  /** Determines if the given @a type is definite (ie: not indefinite).
   *
   * A type is definite if its type string does not contain any indefinite
   * type characters ('*', '?', or 'r').
   *
   * A Variant instance may not have an indefinite type, so calling
   * this function on the result of g_variant_get_type() will always
   * result in <tt>true</tt> being returned.  Calling this function on an
   * indefinite type like G_VARIANT_TYPE_ARRAY, however, will result in
   * <tt>false</tt> being returned.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is definite.
   */
  auto is_definite() const -> bool;

  /** Determines if the given @a type is a container type.
   *
   * Container types are any array, maybe, tuple, or dictionary
   * entry types plus the variant type.
   *
   * This function returns <tt>true</tt> for any indefinite type for which every
   * definite subtype is a container -- G_VARIANT_TYPE_ARRAY, for
   * example.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is a container type.
   */
  auto is_container() const -> bool;

  /** Determines if the given @a type is a basic type.
   *
   * Basic types are booleans, bytes, integers, doubles, strings, object
   * paths and signatures.
   *
   * Only a basic type may be used as the key of a dictionary entry.
   *
   * This function returns <tt>false</tt> for all indefinite types except
   * G_VARIANT_TYPE_BASIC.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is a basic type.
   */
  auto is_basic() const -> bool;

  /** Determines if the given @a type is a maybe type.  This is true if the
   * type string for @a type starts with an 'm'.
   *
   * This function returns <tt>true</tt> for any indefinite type for which every
   * definite subtype is a maybe type -- G_VARIANT_TYPE_MAYBE, for
   * example.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is a maybe type.
   */
  auto is_maybe() const -> bool;

  /** Determines if the given @a type is an array type.  This is true if the
   * type string for @a type starts with an 'a'.
   *
   * This function returns <tt>true</tt> for any indefinite type for which every
   * definite subtype is an array type -- G_VARIANT_TYPE_ARRAY, for
   * example.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is an array type.
   */
  auto is_array() const -> bool;

  /** Determines if the given @a type is a tuple type.  This is true if the
   * type string for @a type starts with a '(' or if @a type is
   * G_VARIANT_TYPE_TUPLE.
   *
   * This function returns <tt>true</tt> for any indefinite type for which every
   * definite subtype is a tuple type -- G_VARIANT_TYPE_TUPLE, for
   * example.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is a tuple type.
   */
  auto is_tuple() const -> bool;

  /** Determines if the given @a type is a dictionary entry type.  This is
   * true if the type string for @a type starts with a '{'.
   *
   * This function returns <tt>true</tt> for any indefinite type for which every
   * definite subtype is a dictionary entry type --
   * G_VARIANT_TYPE_DICT_ENTRY, for example.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is a dictionary entry type.
   */
  auto is_dict_entry() const -> bool;

  /** Determines if the given @a type is the variant type.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a type is the variant type.
   */
  auto is_variant() const -> bool;


  /** Hashes @a type.
   *
   * The argument type of @a type is only #gconstpointer to allow use with
   * HashTable without function pointer casting.  A valid
   * VariantType must be provided.
   *
   * @newin{2,24}
   *
   * @return The hash value.
   */
  auto hash() const -> guint;


  /** Compares @a *this and @a other for equality.
   *
   * Only returns <tt>true</tt> if the types are exactly equal.  Even if one type
   * is an indefinite type and the other is a subtype of it, <tt>false</tt> will
   * be returned if they are not exactly equal.  If you want to check for
   * subtypes, use is_subtype_of().
   *
   * @param other The VariantType to compare with.
   * @return <tt>true</tt> if @a *this and @a other are exactly equal.
   *
   * @newin{2,24}
   */
  auto equal(const VariantType& other) const -> bool;


  /** Checks if @a type is a subtype of @a supertype.
   *
   * This function returns <tt>true</tt> if @a type is a subtype of @a supertype.  All
   * types are considered to be subtypes of themselves.  Aside from that,
   * only indefinite types can have subtypes.
   *
   * @newin{2,24}
   *
   * @param supertype A VariantType.
   * @return <tt>true</tt> if @a type is a subtype of @a supertype.
   */
  auto is_subtype_of(const VariantType& supertype) const -> bool;

// It's necessary to take an extra reference of the 'const GVariantType*'
// returned by g_variant_type_element(), g_variant_type_key() and
// g_variant_type_value() because they don't do that already.


  /** Determines the element type of an array or maybe type.
   *
   * This function may only be used with array or maybe types.
   *
   * @newin{2,24}
   *
   * @return The element type of @a type.
   */
  auto element() const -> VariantType;

  /** Determines the number of items contained in a tuple or
   * dictionary entry type.
   *
   * This function may only be used with tuple or dictionary entry types,
   * but must not be used with the generic tuple type
   * G_VARIANT_TYPE_TUPLE.
   *
   * In the case of a dictionary entry type, this function will always
   * return 2.
   *
   * @newin{2,24}
   *
   * @return The number of items in @a type.
   */
  auto n_items() const -> gsize;

  /** Determines the key type of a dictionary entry type.
   *
   * This function may only be used with a dictionary entry type.  Other
   * than the additional restriction, this call is equivalent to
   * g_variant_type_first().
   *
   * @newin{2,24}
   *
   * @return The key type of the dictionary entry.
   */
  auto key() const -> VariantType;

  /** Determines the value type of a dictionary entry type.
   *
   * This function may only be used with a dictionary entry type.
   *
   * @newin{2,24}
   *
   * @return The value type of the dictionary entry.
   */
  auto value() const -> VariantType;

  /** Determines the item types of a tuple or dictionary entry type.
   *
   * This function may only be used with tuple or dictionary entry types,
   * but must not be used with the generic tuple type VARIANT_TYPE_TUPLE.
   *
   * In the case of a dictionary entry type, returns a vector with
   * 2 elements, the type of the key followed by the value type.
   *
   * An empty vector is returned in case of this %VariantType being VARIANT_TYPE_UNIT.
   *
   * @newin{2,52}
   *
   * @return The item types of this %VariantType, or an empty vector.
   */
  auto get_item_types() const -> std::vector<VariantType>;


  // This function is part of unexposed API in gvarianttypeinfo.{h,c} for an
  // also unexposed GVariantTypeInfo structure of glib.


};

extern GLIBMM_API const VariantType VARIANT_TYPE_BOOL;

extern GLIBMM_API const VariantType VARIANT_TYPE_BYTE;

extern GLIBMM_API const VariantType VARIANT_TYPE_INT16;

extern GLIBMM_API const VariantType VARIANT_TYPE_UINT16;

extern GLIBMM_API const VariantType VARIANT_TYPE_INT32;

extern GLIBMM_API const VariantType VARIANT_TYPE_UINT32;

extern GLIBMM_API const VariantType VARIANT_TYPE_INT64;

extern GLIBMM_API const VariantType VARIANT_TYPE_UINT64;

extern GLIBMM_API const VariantType VARIANT_TYPE_DOUBLE;

extern GLIBMM_API const VariantType VARIANT_TYPE_STRING;

extern GLIBMM_API const VariantType VARIANT_TYPE_OBJECT_PATH;

extern GLIBMM_API const VariantType VARIANT_TYPE_SIGNATURE;

extern GLIBMM_API const VariantType VARIANT_TYPE_VARIANT;

extern GLIBMM_API const VariantType VARIANT_TYPE_HANDLE;

extern GLIBMM_API const VariantType VARIANT_TYPE_UNIT;

extern GLIBMM_API const VariantType VARIANT_TYPE_ANY;

extern GLIBMM_API const VariantType VARIANT_TYPE_BASIC;

extern GLIBMM_API const VariantType VARIANT_TYPE_MAYBE;

extern GLIBMM_API const VariantType VARIANT_TYPE_ARRAY;

extern GLIBMM_API const VariantType VARIANT_TYPE_TUPLE;

extern GLIBMM_API const VariantType VARIANT_TYPE_DICT_ENTRY;

extern GLIBMM_API const VariantType VARIANT_TYPE_DICTIONARY;

extern GLIBMM_API const VariantType VARIANT_TYPE_STRING_ARRAY;

extern GLIBMM_API const VariantType VARIANT_TYPE_OBJECT_PATH_ARRAY;

extern GLIBMM_API const VariantType VARIANT_TYPE_BYTESTRING;

extern GLIBMM_API const VariantType VARIANT_TYPE_BYTESTRING_ARRAY;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// This is needed so Glib::VariantType can be used with
// Glib::Value and _WRAP_PROPERTY in Gio::Action and elsewhere.
template <>
class GLIBMM_API Value<Glib::VariantType> : public ValueBase_Boxed
{
public:
  using CppType = Glib::VariantType;
  using CType = GVariantType*;

  static auto value_type() -> GType;

  void set(const CppType& data);
  auto get() const -> CppType;
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


namespace Glib
{

/** @relates Glib::VariantType
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(VariantType& lhs, VariantType& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Glib

namespace Glib
{

  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Glib::VariantType
   */
  GLIBMM_API
  auto wrap(GVariantType* object, bool take_copy = false) -> Glib::VariantType;

} // namespace Glib


#endif /* _GLIBMM_VARIANTTYPE_H */

