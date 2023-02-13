
#ifndef _GLIBMM_VARIANT_H
#define _GLIBMM_VARIANT_H


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


#include <libmm-glib/mm-glibconfig.hpp>
#include <libmm-glib/varianttype.hpp>
#include <libmm-glib/variantiter.hpp>
#include <libmm-glib/variantdbusstring.hpp>
#include <libmm-glib/refptr.hpp>
#include <libmm-glib/ustring.hpp>
#include <libmm-glib/error.hpp>
#include <utility>
#include <vector>
#include <map>
#include <memory>
#include <tuple>
#include <stdexcept>
#include <typeinfo>

namespace Glib
{
class Bytes;

/** @defgroup Variant Variant Data Types
 *
 * The Variant classes deal with strongly typed
 * variant data. A Variant stores a value along with
 * information about the type of that value. The range of possible
 * values is determined by the type. The type system used is VariantType.
 *
 * See the VariantBase class and its derived types, such as VariantContainerBase,
 * and the Variant<> template type.
 *
 * Variant instances always have a type and a value (which are given
 * at construction time). The type and value of a Variant
 * can never change other than by the Variant itself being
 * destroyed.  A Variant cannot contain a pointer.
 *
 * Variant is heavily optimised for dealing with data in serialised
 * form. It works particularly well with data located in memory-mapped
 * files. It can perform nearly all deserialisation operations in a
 * small constant time, usually touching only a single memory page.
 * Serialised Variant data can also be sent over the network.
 *
 * Variant is largely compatible with D-Bus.  Almost all types of
 * Variant instances can be sent over D-Bus.  See VariantType for
 * exceptions.
 *
 * There is a Python-inspired text language for describing Variant
 * values. Variant includes a printer for this language and a parser
 * with type inferencing.
 */

//Note: We wrap this because it is thrown by GtkBuilder's functions.
// See https://bugzilla.gnome.org/show_bug.cgi?id=708206
// It would also be thrown by parse() if we wrap g_variant_parse().
// Now (2014-01-30) it's also thrown by Gio::Action::parse_detailed_name().
/**  %Exception class for Variant parse errors.
 */
class VariantParseError : public Glib::Error
{
public:
  /**  @var Code FAILED
   * Generic error (unused).
   *
   *  @var Code BASIC_TYPE_EXPECTED
   * A non-basic VariantType was given where a basic type was expected.
   *
   *  @var Code CANNOT_INFER_TYPE
   * Cannot infer the VariantType.
   *
   *  @var Code DEFINITE_TYPE_EXPECTED
   * An indefinite VariantType was given where a definite type was expected.
   *
   *  @var Code INPUT_NOT_AT_END
   * Extra data after parsing finished.
   *
   *  @var Code INVALID_CHARACTER
   * Invalid character in number or unicode escape.
   *
   *  @var Code INVALID_FORMAT_STRING
   * Not a valid Variant format string.
   *
   *  @var Code INVALID_OBJECT_PATH
   * Not a valid object path.
   *
   *  @var Code INVALID_SIGNATURE
   * Not a valid type signature.
   *
   *  @var Code INVALID_TYPE_STRING
   * Not a valid Variant type string.
   *
   *  @var Code NO_COMMON_TYPE
   * Could not find a common type for array entries.
   *
   *  @var Code NUMBER_OUT_OF_RANGE
   * The numerical value is out of range of the given type.
   *
   *  @var Code NUMBER_TOO_BIG
   * The numerical value is out of range for any type.
   *
   *  @var Code TYPE_ERROR
   * Cannot parse as variant of the specified type.
   *
   *  @var Code UNEXPECTED_TOKEN
   * An unexpected token was encountered.
   *
   *  @var Code UNKNOWN_KEYWORD
   * An unknown keyword was encountered.
   *
   *  @var Code UNTERMINATED_STRING_CONSTANT
   * Unterminated string constant.
   *
   *  @var Code VALUE_EXPECTED
   * No value given.
   *
   *  @var Code RECURSION
   * Variant was too deeply nested; Variant is only guaranteed to handle nesting up to 64 levels (Since: 2.64).
   *
   *  @enum Code
   *
   * %Error codes returned by parsing text-format GVariants.
   */
  enum Code
  {
    FAILED,
    BASIC_TYPE_EXPECTED,
    CANNOT_INFER_TYPE,
    DEFINITE_TYPE_EXPECTED,
    INPUT_NOT_AT_END,
    INVALID_CHARACTER,
    INVALID_FORMAT_STRING,
    INVALID_OBJECT_PATH,
    INVALID_SIGNATURE,
    INVALID_TYPE_STRING,
    NO_COMMON_TYPE,
    NUMBER_OUT_OF_RANGE,
    NUMBER_TOO_BIG,
    TYPE_ERROR,
    UNEXPECTED_TOKEN,
    UNKNOWN_KEYWORD,
    UNTERMINATED_STRING_CONSTANT,
    VALUE_EXPECTED,
    RECURSION
  };

  GLIBMM_API VariantParseError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit VariantParseError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


//TODO: Add this documentation from the API if we are confident of it for the C++ wrapper:
// #GVariant is completely threadsafe.  A #GVariant instance can be
// concurrently accessed in any way from any number of threads without
// problems.
// Note that we don't copy GVariant's documentation about Memory Use because
// it seems easy to get out of sync and people can look at that C documentation if necessary.

/** This is the base class for all Variant types.
 *
 * If the actual type is known at compile-time then you should use a specific
 * Variant<>, such as Variant<int>. Otherwise, you may use get_type(),
 * is_of_type(), or cast_dynamic().
 *
 * @newin{2,28}
 * @ingroup Variant
 */
class GLIBMM_API VariantBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VariantBase;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Constructs an invalid object.
   * E.g. for output arguments to methods. There is not much you can do with
   * the object before it has been assigned a valid value.
   */
  VariantBase();

  // Use make_a_copy=true when getting it directly from a struct.
  explicit VariantBase(GVariant* castitem, bool make_a_copy = false);

  VariantBase(const VariantBase& src);
  auto operator=(const VariantBase& src) -> VariantBase&;

  VariantBase(VariantBase&& other) noexcept;
  auto operator=(VariantBase&& other) noexcept -> VariantBase&;

  ~VariantBase() noexcept;

  void swap(VariantBase& other) noexcept;

  auto       gobj() -> GVariant*       { return gobject_; }
  auto gobj() const -> const GVariant* { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GVariant*;

protected:
  GVariant* gobject_;

private:


public:

   /** Test whether the Variant has an underlying instance.
    *
    * @newin{2,50}
    */
   explicit operator bool() const;

  /** Replace the underlying GVariant.
   * This is for use by methods that take a VariantBase& as an output
   * parameter.
   *
   * @param cobject The GVariant* obtained from a C function.
   * @param take_a_reference Whether this method should take a reference, for
   * instance if the C function has not given one.
   */
  void init(const GVariant* cobject, bool take_a_reference = false);

// It's necessary to take an extra reference of the 'const GVariantType*'
// returned by g_variant_get_type() because it doesn't do that already.


  /** Determines the type of @a value.
   *
   * The return value is valid for the lifetime of @a value and must not
   * be freed.
   *
   * @newin{2,24}
   *
   * @return A VariantType.
   */
  auto get_type() const -> VariantType;


  /** Returns the type string of @a value.  Unlike the result of calling
   * g_variant_type_peek_string(), this string is nul-terminated.  This
   * string belongs to Variant and must not be freed.
   *
   * @newin{2,24}
   *
   * @return The type string for the type of @a value.
   */
  auto get_type_string() const -> std::string;

  /** Checks whether @a value has a floating reference count.
   *
   * This function should only ever be used to assert that a given variant
   * is or is not floating, or for debug purposes. To acquire a reference
   * to a variant that might be floating, always use g_variant_ref_sink()
   * or g_variant_take_ref().
   *
   * See g_variant_ref_sink() for more information about floating reference
   * counts.
   *
   * @newin{2,26}
   *
   * @return Whether @a value is floating.
   */
  auto is_floating() const -> bool;

  /** Checks if a value has a type matching the provided type.
   *
   * @newin{2,24}
   *
   * @param type A VariantType.
   * @return <tt>true</tt> if the type of @a value matches @a type.
   */
  auto is_of_type(const VariantType& type) const -> bool;

  /** Checks if @a value is a container.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a value is a container.
   */
  auto is_container() const -> bool;

  /** Classifies @a value according to its top-level type.
   *
   * @newin{2,24}
   *
   * @return The VariantClass of @a value.
   */
  auto classify() const -> GVariantClass;


  /** Determines the number of bytes that would be required to store @a value
   * with g_variant_store().
   *
   * If @a value has a fixed-sized type then this function always returned
   * that fixed size.
   *
   * In the case that @a value is already in serialized form or the size has
   * already been calculated (ie: this function has been called before)
   * then this function is O(1).  Otherwise, the size is calculated, an
   * operation which is approximately O(n) in the number of values
   * involved.
   *
   * @newin{2,24}
   *
   * @return The serialized size of @a value.
   */
  auto get_size() const -> gsize;

  /** Returns a pointer to the serialized form of a Variant instance.
   * The returned data may not be in fully-normalised form if read from an
   * untrusted source.  The returned data must not be freed; it remains
   * valid for as long as @a value exists.
   *
   * If @a value is a fixed-sized value that was deserialized from a
   * corrupted serialized container then <tt>nullptr</tt> may be returned.  In this
   * case, the proper thing to do is typically to use the appropriate
   * number of nul bytes in place of @a value.  If @a value is not fixed-sized
   * then <tt>nullptr</tt> is never returned.
   *
   * In the case that @a value is already in serialized form, this function
   * is O(1).  If the value is not already in serialized form,
   * serialization occurs implicitly and is approximately O(n) in the size
   * of the result.
   *
   * To deserialize the data returned by this function, in addition to the
   * serialized data, you must know the type of the Variant, and (if the
   * machine might be different) the endianness of the machine that stored
   * it. As a result, file formats or network messages that incorporate
   * serialized Variants must include this information either
   * implicitly (for instance "the file always contains a
   * G_VARIANT_TYPE_VARIANT and it is always in little-endian order") or
   * explicitly (by storing the type and/or endianness in addition to the
   * serialized data).
   *
   * @newin{2,46}
   *
   * @return The serialized form of @a value, or <tt>nullptr</tt>.
   */
  auto get_data() const -> gconstpointer;

  /** Returns a pointer to the serialized form of a Variant instance.
   * The semantics of this function are exactly the same as
   * g_variant_get_data(), except that the returned Bytes holds
   * a reference to the variant data.
   *
   * @newin{2,46}
   *
   * @return A new Bytes representing the variant data.
   */
  auto get_data_as_bytes() const -> Glib::RefPtr<const Glib::Bytes>;

  /** Stores the serialized form of @a value at @a data.  @a data should be
   * large enough.  See g_variant_get_size().
   *
   * The stored data is in machine native byte order but may not be in
   * fully-normalised form if read from an untrusted source.  See
   * g_variant_get_normal_form() for a solution.
   *
   * As with g_variant_get_data(), to be able to deserialize the
   * serialized variant successfully, its type and (if the destination
   * machine might be different) its endianness must also be available.
   *
   * This function is approximately O(n) in the size of @a data.
   *
   * @newin{2,24}
   *
   * @param data The location to store the serialized data at.
   */
  void store(gpointer data) const;


  /** Pretty-prints @a value in the format understood by g_variant_parse().
   *
   * The format is described [here][gvariant-text].
   *
   * If @a type_annotate is <tt>true</tt>, then type information is included in
   * the output.
   *
   * @newin{2,24}
   *
   * @param type_annotate <tt>true</tt> if type information should be included in
   * the output.
   * @return A newly-allocated string holding the result.
   */
  auto print(bool type_annotate =  false) const -> Glib::ustring;


  /** Generates a hash value for a Variant instance.
   *
   * The output of this function is guaranteed to be the same for a given
   * value only per-process.  It may change between different processor
   * architectures or even different versions of GLib.  Do not use this
   * function as a basis for building protocols or file formats.
   *
   * The type of @a value is #gconstpointer only to allow use of this
   * function with HashTable.  @a value must be a Variant.
   *
   * @newin{2,24}
   *
   * @return A hash value corresponding to @a value.
   */
  auto hash() const -> guint;


  /** Checks if @a *this and @a other have the same type and value.
   *
   * @newin{2,24}
   *
   * @param other The Variant to compare with.
   * @return <tt>true</tt> if @a *this and @a other are equal.
   */
  auto equal(const VariantBase& other) const -> bool;

  /** Checks if @a *this and @a other have the same type and value.
   *
   * @newin{2,58}
   *
   * @param other The Variant to compare with.
   * @return <tt>true</tt> if @a *this and @a other are equal.
   */
  auto operator==(const VariantBase& other) const -> bool;

  /** Checks if @a *this and @a other have the same type and value.
   *
   * @newin{2,58}
   *
   * @param other The Variant to compare with.
   * @return <tt>true</tt> if @a *this and @a other are not equal.
   */
  auto operator!=(const VariantBase& other) const -> bool;

  /** Ordering relational operators.
   * These are explicitly deleted to prevent the compiler from generating
   * error messages containing long lists of operators that can't be used.
   */
  auto operator<(const VariantBase& other) const -> bool = delete;

  /// See operator<().
  auto operator<=(const VariantBase& other) const -> bool = delete;

  /// See operator<().
  auto operator>(const VariantBase& other) const -> bool = delete;

  /// See operator<().
  auto operator>=(const VariantBase& other) const -> bool = delete;

  /** Gets a VariantBase instance that has the same value as this variant and
   * is trusted to be in normal form.
   *
   * If this variant is already trusted to be in normal form then a new
   * reference to the variant is returned.
   *
   * If this variant is not already trusted, then it is scanned to check if it
   * is in normal form. If it is found to be in normal form then it is marked
   * as trusted and a new reference to it is returned.
   *
   * If this variant is found not to be in normal form then a new trusted
   * VariantBase is created with the same value as this variant.
   *
   * It makes sense to call this function if you've received variant data from
   * untrusted sources and you want to ensure your serialised output is
   * definitely in normal form.
   *
   * @param result A location in which to store the trusted VariantBase.
   * @newin{2,24}
   */
  void get_normal_form(VariantBase& result) const;


  /** Checks if @a value is in normal form.
   *
   * The main reason to do this is to detect if a given chunk of
   * serialized data is in normal form: load the data into a Variant
   * using g_variant_new_from_data() and then use this function to
   * check.
   *
   * If @a value is found to be in normal form then it will be marked as
   * being trusted.  If the value was already marked as being trusted then
   * this function will immediately return <tt>true</tt>.
   *
   * There may be implementation specific restrictions on deeply nested values.
   * GVariant is guaranteed to handle nesting up to at least 64 levels.
   *
   * @newin{2,24}
   *
   * @return <tt>true</tt> if @a value is in normal form.
   */
  auto is_normal_form() const -> bool;

  /** Performs a byteswapping operation on the contents of this variant. The
   * result is that all multi-byte numeric data contained in the variant is
   * byteswapped. That includes 16, 32, and 64bit signed and unsigned integers
   * as well as file handles and double precision floating point values.
   *
   * This function is an identity mapping on any value that does not contain
   * multi-byte numeric data. That include strings, booleans, bytes and
   * containers containing only these things (recursively).
   *
   * The returned value is always in normal form and is marked as trusted.
   *
   * @param result A location in which to store the byteswapped form of this
   * variant.
   * @newin{2,24}
   */
   void byteswap(VariantBase& result) const;


  /** Checks if calling g_variant_get() with @a format_string on @a value would
   * be valid from a type-compatibility standpoint.  @a format_string is
   * assumed to be a valid format string (from a syntactic standpoint).
   *
   * If @a copy_only is <tt>true</tt> then this function additionally checks that it
   * would be safe to call g_variant_unref() on @a value immediately after
   * the call to g_variant_get() without invalidating the result.  This is
   * only possible if deep copies are made (ie: there are no pointers to
   * the data inside of the soon-to-be-freed Variant instance).  If this
   * check fails then a g_critical() is printed and <tt>false</tt> is returned.
   *
   * This function is meant to be used by functions that wish to provide
   * varargs accessors to Variant values of uncertain values (eg:
   * g_variant_lookup() or Glib::menu_model_get_item_attribute()).
   *
   * @newin{2,34}
   *
   * @param format_string A valid Variant format string.
   * @param copy_only <tt>true</tt> to ensure the format string makes deep copies.
   * @return <tt>true</tt> if @a format_string is safe to use.
   */
  auto check_format_string(const std::string& format_string, bool copy_only =  false) const -> bool;

   //Ignore private API from gvariant-core.h:


   /** Cast to a specific variant type.
    * For instance:
    * @code
    * Variant<std::string> derived = VariantBase::cast_dynamic< Variant<std::string> >(base);
    * @endcode
    *
    * @param v The variant to cast to a specific type.
    * @result The variant as a specific type.
    * @throws std::bad_cast if the Variant was not of the expected type.
    */
   template<class V_CastTo>
   static auto cast_dynamic(const VariantBase& v) -> V_CastTo;


protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Used by cast_dynamic().
   * In addition to an exact match, the following casts are possible:
   * - VARIANT_TYPE_OBJECT_PATH and VARIANT_TYPE_SIGNATURE can be cast to
   *   VARIANT_TYPE_STRING (Glib::ustring).
   * - VARIANT_TYPE_STRING, VARIANT_TYPE_OBJECT_PATH and VARIANT_TYPE_SIGNATURE
   *   can be cast to VARIANT_TYPE_BYTESTRING (std::string).
   * - VARIANT_TYPE_HANDLE can be cast to VARIANT_TYPE_INT32.
   *
   * These casts are possible also when they are parts of a more complicated type.
   * E.g. in Variant<std::map<Glib::ustring, std::vector<std::string> > > the map's keys
   * can be VARIANT_TYPE_OBJECT_PATH and the vector's elements can be VARIANT_TYPE_SIGNATURE.
   * @newin{2,46}
   */
  auto is_castable_to(const VariantType& supertype) const -> bool;
#endif //DOXYGEN_SHOULD_SKIP_THIS


};

template<class V_CastTo>
auto VariantBase::cast_dynamic(const VariantBase& v) -> V_CastTo
{
  if(!(v.gobj()))
  {
    return V_CastTo();
  }
  if(v.is_castable_to(V_CastTo::variant_type()))
  {
    return V_CastTo(const_cast<GVariant*>(v.gobj()), true);
  }
  else
  {
   throw std::bad_cast();
  }
}

/** Base class from which string variant classes derive.
 * @newin{2,28}
 * @ingroup Variant
 */
class GLIBMM_API VariantStringBase : public VariantBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VariantStringBase;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  using CType = GVariant*;
  using CppType = VariantStringBase;

  /// Default constructor.
  VariantStringBase();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit VariantStringBase(GVariant* castitem,  bool take_a_reference = false);

  /** Creates a D-Bus object path variant with the contents of @a object_path.
   * @a object_path must be a valid D-Bus object path. Use is_object_path() if unsure.
   *
   * @param[out] output A location in which to store the new object path variant
   * instance.
   * @param object_path An object path string.
   * @newin{2,28}
   */
  static void create_object_path(VariantStringBase& output,
    const std::string& object_path);


  /** Determines if a given string is a valid D-Bus object path.  You
   * should ensure that a string is a valid D-Bus object path before
   * passing it to g_variant_new_object_path().
   *
   * A valid object path starts with `/` followed by zero or more
   * sequences of characters separated by `/` characters.  Each sequence
   * must contain only the characters `[A-Z][a-z][0-9]_`.  No sequence
   * (including the one following the final `/` character) may be empty.
   *
   * @newin{2,24}
   *
   * @param string A normal C nul-terminated string.
   * @return <tt>true</tt> if @a string is a D-Bus object path.
   */
  static auto is_object_path(const std::string& string) -> bool;

  /** Creates a D-Bus type signature variant with the contents of @a signature.
   * @a signature must be a valid D-Bus type signature. Use is_signature() if unsure.
   *
   * @param[out] output A location in which to store the new signature variant
   * instance.
   * @param signature A signature string.
   * @newin{2,28}
   */
  static void create_signature(VariantStringBase& output,
    const std::string& signature);


  /** Determines if a given string is a valid D-Bus type signature.  You
   * should ensure that a string is a valid D-Bus type signature before
   * passing it to g_variant_new_signature().
   *
   * D-Bus type signatures consist of zero or more definite VariantType
   * strings in sequence.
   *
   * @newin{2,24}
   *
   * @param string A normal C nul-terminated string.
   * @return <tt>true</tt> if @a string is a D-Bus type signature.
   */
  static auto is_signature(const std::string& string) -> bool;


};

/** The base class for multiple-item Variants, such as Variants containing
 * tuples or arrays, and also for maybe-typed (that is, nullable) Variant types.
 *
 * @newin{2,28}
 * @ingroup Variant
 */
class GLIBMM_API VariantContainerBase : public VariantBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = VariantContainerBase;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  using CType = GVariant*;
  using CppType = VariantContainerBase;

  /// Default constructor.
  VariantContainerBase();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit VariantContainerBase(GVariant* castitem, bool take_a_reference = false);

  /** Create a tuple variant from a vector of its variant children.
   * @param children The vector containing the children of the container.
   * @return The newly created tuple variant (as a VariantContainerBase).
   */
  static auto create_tuple(const std::vector<VariantBase>& children) -> VariantContainerBase;

  /** Create a tuple variant with a single variant child.
   * @param child The child variant.
   * @return The newly created tuple variant (as a VariantContainerBase).
   */
  static auto create_tuple(const VariantBase& child) -> VariantContainerBase;


  /** Depending on if @a child is <tt>nullptr</tt>, either wraps @a child inside of a
   * maybe container or creates a Nothing instance for the given @a type.
   *
   * At least one of @a child_type and @a child must be non-<tt>nullptr</tt>.
   * If @a child_type is non-<tt>nullptr</tt> then it must be a definite type.
   * If they are both non-<tt>nullptr</tt> then @a child_type must be the type
   * of @a child.
   *
   * If @a child is a floating reference (see g_variant_ref_sink()), the new
   * instance takes ownership of @a child.
   *
   * @newin{2,24}
   *
   * @param child_type The VariantType of the child, or <tt>nullptr</tt>.
   * @param child The child value, or <tt>nullptr</tt>.
   * @return A floating reference to a new Variant maybe instance.
   */

  static auto create_maybe(const VariantType& child_type,
    const VariantBase& child = {}) -> VariantContainerBase;


  /** Determines the number of children in a container Variant instance.
   * This includes variants, maybes, arrays, tuples and dictionary
   * entries.  It is an error to call this function on any other type of
   * Variant.
   *
   * For variants, the return value is always 1.  For values with maybe
   * types, it is always zero or one.  For arrays, it is the length of the
   * array.  For tuples it is the number of tuple items (which depends
   * only on the type).  For dictionary entries, it is always 2
   *
   * This function is O(1).
   *
   * @newin{2,24}
   *
   * @return The number of children in the container.
   */
  auto get_n_children() const -> gsize;

  /** Reads a child item out of this instance. This method is valid for
   * variants, maybes, arrays, tuples and dictionary entries.
   *
   * It is an error if @a index is greater than the number of child items in
   * the container. See get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the child to fetch.
   * @param child A location in which to store the child at the specified
   * index.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  void get_child(VariantBase& child, gsize index = 0) const;


  /** Reads a child item out of a container Variant instance.  This
   * includes variants, maybes, arrays, tuples and dictionary
   * entries.  It is an error to call this function on any other type of
   * Variant.
   *
   * It is an error if @a index is greater than the number of child items
   * in the container.  See g_variant_n_children().
   *
   * The returned value is never floating.  You should free it with
   * g_variant_unref() when you're done with it.
   *
   * Note that values borrowed from the returned child are not guaranteed to
   * still be valid after the child is freed even if you still hold a reference
   * to @a value, if @a value has not been serialized at the time this function is
   * called. To avoid this, you can serialize @a value by calling
   * g_variant_get_data() and optionally ignoring the return value.
   *
   * There may be implementation specific restrictions on deeply nested values,
   * which would result in the unit tuple being returned as the child value,
   * instead of further nested children. Variant is guaranteed to handle
   * nesting up to at least 64 levels.
   *
   * This function is O(1).
   *
   * @newin{2,24}
   *
   * @param index The index of the child to fetch.
   * @return The child at the specified index.
   */
  auto get_child(gsize index =  0) -> VariantBase;

  /* TODO?:
  /// A get() method to return the contents of the variant in the container.
  template <class DataType>
  DataType get_child(gsize index = 0) const;
  */

  /** If this is a maybe-typed instance, try to extract its value. If there is
   * no value (the value is <tt>nothing</tt>), return <tt>false</tt>. Otherwise,
   * the value is copied to the supplied Variant and <tt>true</tt> is returned.
   *
   * @param maybe A place in which to return the value, if it isn’t
   * <tt>nothing</tt>.
   * @newin{2,28}
   */
  auto get_maybe(VariantBase& maybe) const -> bool;


protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Used by get_iter() in the subclasses.
   * @newin{2,46}
   */
  auto get_iter(const VariantType& container_variant_type) const -> VariantIter;
#endif //DOXYGEN_SHOULD_SKIP_THIS


};

template<>
GLIBMM_API auto VariantBase::cast_dynamic<VariantContainerBase>(const VariantBase& v) -> VariantContainerBase;

/** Template class used for the specialization of the Variant<> classes.
 * @newin{2,28}
 * @ingroup Variant
 */
template<class T>
class Variant : public VariantBase
{
public:
  using CppType = T;
};

/****************** Specializations ***********************************/

/** Specialization of Variant containing a VariantBase.
 * Perhaps the main use of this is as a maybe-typed (i.e. nullable) Variant, as
 * it inherits the methods create_maybe() and get_maybe() from
 * VariantContainerBase, plus get_n_children() to allow checking whether there
 * is a contained value, i.e. the inner Variant is not <tt>nothing</tt>.
 *
 * @newin{2,28}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<VariantBase> : public VariantContainerBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Variant<VariantBase>;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


public:
  using CType = GVariant*;
  using CppType = VariantBase;
  using CppContainerType = Variant<VariantBase>;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  //This must have a create() method because otherwise it would be a copy
  //constructor.
  /** Creates a new Variant<VariantBase>.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto create(const VariantBase& data) -> Variant<VariantBase>;


  //TODO: Documentation
  void get(VariantBase& variant) const;

  //TODO: Deprecate this in favour of get(VariantBase&)?

  /** Unboxes @a value.  The result is the Variant instance that was
   * contained in @a value.
   *
   * @newin{2,24}
   *
   * @return The item contained in the variant.
   */
  auto get() const -> VariantBase;


};

/** Specialization of Variant containing a Variant<T>.
 * Perhaps the main use of this is as a maybe-typed (i.e. nullable) Variant, as
 * it inherits the methods create_maybe() and get_maybe() from
 * VariantContainerBase, plus get_n_children() to allow checking whether there
 * is a contained value, i.e. the inner Variant is not <tt>nothing</tt>.
 *
 * @newin{2,36}
 * @ingroup Variant
 */
template<class T>
class Variant< Variant<T> > : public VariantContainerBase
{
public:
  using CType = GVariant*;
  using CppType = Variant<T>;
  using CppContainerType = Variant<CppType>;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   * @newin{2,36}
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,36}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant< Variant<T> >.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,36}
   */
  static auto create(const Variant<T>& data) -> Variant< Variant<T> >;

  /** Gets the contents of the Variant.
   * @return The contents of the Variant.
   * @newin{2,36}
   */
  auto get() const -> Variant<T>;
};

/** Specialization of Variant containing a Glib::ustring, for variants of type
 * string, object path, or signature.
 * @newin{2,28}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<Glib::ustring> : public VariantStringBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Variant<Glib::ustring>;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  using CType = char*;
  using CppType = Glib::ustring;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,  bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant<Glib::ustring>.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto create(const Glib::ustring& data) -> Variant<Glib::ustring>;

  //We can't use WRAP_METHOD() here because g_variant_get_string() takes an extra length parameter.
  /** Gets the contents of the Variant.
   * @return The contents of the Variant.
   * @newin{2,28}
   */
  auto get() const -> Glib::ustring;


};

/** Specialization of Variant containing a Glib::DBusObjectPathString,
 * for variants of type object path.
 * @newin{2,54}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<Glib::DBusObjectPathString> : public VariantStringBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Variant<Glib::DBusObjectPathString>;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  using CType = char*;
  using CppType = Glib::DBusObjectPathString;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,  bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,54}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant<Glib::DBusObjectPathString>.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,54}
   */
  static auto create(const CppType& data) -> Variant<CppType>;

  //We can't use WRAP_METHOD() here because g_variant_get_string() takes an extra length parameter.
  /** Gets the contents of the Variant.
   * @return The contents of the Variant.
   * @newin{2,54}
   */
  auto get() const -> CppType;


};

/** Specialization of Variant containing a Glib::DBusSignatureString,
 * for variants of type signature.
 * @newin{2,54}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<Glib::DBusSignatureString> : public VariantStringBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Variant<Glib::DBusSignatureString>;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  using CType = char*;
  using CppType = Glib::DBusSignatureString;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,  bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,54}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant<Glib::DBusSignatureString>.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,54}
   */
  static auto create(const CppType& data) -> Variant<CppType>;

  //We can't use WRAP_METHOD() here because g_variant_get_string() takes an extra length parameter.
  /** Gets the contents of the Variant.
   * @return The contents of the Variant.
   * @newin{2,54}
   */
  auto get() const -> CppType;


};

/** Specialization of Variant containing a std::string, for variants of type
 * bytestring, string, object path, or signature.
 * See also Variant<Glib::ustring> for UTF-8 strings.
 * @newin{2,28}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<std::string> : public VariantStringBase
{
  // Trick gmmproc into thinking this is derived from GVariant to wrap some methods.
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = Variant<std::string>;
  using BaseObjectType = GVariant;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  using CType = char*                ;
  using CppType = std::string;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant<std::string>.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto create(const std::string& data) -> Variant<std::string>;

  //TODO: Documentation.
  auto get() const -> std::string;


};

/** Specialization of Variant containing a dictionary entry.  See also
 * Variant< std::map<K, V> >.
 * @newin{2,28}
 * @ingroup Variant
 */
template<class K, class V>
class Variant< std::pair<K, V> > : public VariantContainerBase
{
public:
  using CppType = std::pair<K, V>;
  using CppContainerType = Variant<CppType>;

  /// Default constructor.
  Variant()
  : VariantContainerBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,
    bool take_a_reference = false)
  : VariantContainerBase(castitem, take_a_reference)
  {}

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant< std::pair<K, V> >.
   * @param data The value of the new Variant.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto create(const std::pair<K, V>& data) -> Variant< std::pair<K, V> >;


  /** Gets the contents of the Variant.
   * @return The contents of the Variant.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  auto get() const -> std::pair<K, V>;
};

/** Specialization of Variant containing an array of items.
 * @newin{2,28}
 * @ingroup Variant
 */
template<class T>
class Variant< std::vector<T> > : public VariantContainerBase
{
public:
  using CppType = T                    ;
  using CppContainerType = std::vector<T>;

  /// Default constructor.
  Variant()
  : VariantContainerBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,
    bool take_a_reference = false)
  : VariantContainerBase(castitem, take_a_reference)
  {}

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant from an array of numeric types.
   * @param data The array to use for creation.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto create(const std::vector<T>& data) -> Variant< std::vector<T> >;


  /** Gets a specific element of the array.  It is an error if @a index is
   * greater than the number of child items in the container.  See
   * VariantContainerBase::get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the element.
   * @return The element at index @a index.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  auto get_child(gsize index) const -> T;

  /** Gets the vector of the Variant.
   * @return The vector.
   * @newin{2,28}
   */
  auto get() const -> std::vector<T>;


  /** Gets a VariantIter of the Variant.
   * @return the VariantIter.
   * @newin{2,28}
   */
  auto get_iter() const -> VariantIter;
};

/** Specialization of Variant containing an array of UTF-8 capable
 * strings.
 * @newin{2,28}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant< std::vector<Glib::ustring> > : public VariantContainerBase
{
public:
  using CppType = Glib::ustring                ;
  using CppContainerType = std::vector<Glib::ustring>;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant from an array of strings.
   * @param data The array to use for creation.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto
    create(const std::vector<Glib::ustring>& data) -> Variant< std::vector<Glib::ustring> >;

  /** Gets a specific element of the string array.  It is an error if @a index
   * is greater than the number of child items in the container.  See
   * VariantContainerBase::get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the element.
   * @return The element at index @a index.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  auto get_child(gsize index) const -> Glib::ustring;

  /** Gets the string vector of the Variant.
   * @return The vector.
   * @newin{2,28}
   */
  auto get() const -> std::vector<Glib::ustring>;


  /** Gets a VariantIter of the Variant.
   * @return the VariantIter.
   * @newin{2,28}
   */
  auto get_iter() const -> VariantIter;
};

/** Specialization of Variant containing an array of D-Bus object paths.
 *
 * @newin{2,54}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant<std::vector<Glib::DBusObjectPathString>> : public VariantContainerBase
{
public:
  using CppType = Glib::DBusObjectPathString;
  using CppContainerType = std::vector<Glib::DBusObjectPathString>;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,54}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant from an array of strings.
   * @param data The array to use for creation.
   * @return The new Variant.
   * @newin{2,54}
   */
  static auto create(const CppContainerType& data) -> Variant<CppContainerType>;

  /** Gets a specific element of the string array.  It is an error if @a index
   * is greater than the number of child items in the container.  See
   * VariantContainerBase::get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the element.
   * @return The element at index @a index.
   * @throw std::out_of_range
   * @newin{2,54}
   */
  auto get_child(gsize index) const -> CppType;

  /** Gets the string vector of the Variant.
   * @return The vector.
   * @newin{2,54}
   */
  auto get() const -> CppContainerType;

  /** Gets a VariantIter of the Variant.
   * @return the VariantIter.
   * @newin{2,54}
   */
  auto get_iter() const -> VariantIter;
};

/** Specialization of Variant containing an array of non-UTF-8 strings
 * (byte string arrays).
 * @newin{2,28}
 * @ingroup Variant
 */
template<>
class GLIBMM_API Variant< std::vector<std::string> > : public VariantContainerBase
{
public:
  using CppType = std::string                  ;
  using CppContainerType = std::vector<std::string>;

  /// Default constructor.
  Variant();

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false);

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant from an array of strings.
   * @param data The array to use for creation.
   * @return The new Variant.
   * @newin{2,28}
   */
  static auto
    create(const std::vector<std::string>& data) -> Variant< std::vector<std::string> >;

  /** Creates a new Variant from an array of D-Bus object paths.
   * @param paths The array to use for creation.
   * @return The new Variant.
   * @newin{2,36}
   */
  static auto
    create_from_object_paths(const std::vector<std::string>& paths) -> Variant< std::vector<std::string> >;

  /** Gets a specific element of the string array.  It is an error if @a index
   * is greater than the number of child items in the container.  See
   * VariantContainerBase::get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the element.
   * @return The element at index @a index.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  auto get_child(gsize index) const -> std::string;

  /** Gets the string vector of the Variant.
   * @return The vector.
   * @newin{2,28}
   */
  auto get() const -> std::vector<std::string>;


  // Object paths are merely strings so it is possible to get them already with
  // the existing get() methods in this class.


  /** Gets a VariantIter of the Variant.
   * @return the VariantIter.
   * @newin{2,28}
   */
  auto get_iter() const -> VariantIter;
};

/** Specialization of Variant containing a dictionary (a map of (key,
 * value) elements).
 * @newin{2,28}
 * @ingroup Variant
 */
template<class K, class V>
class Variant< std::map<K, V> >: public VariantContainerBase
{
public:
  using CppType = std::pair<K, V>;
  using CppContainerType = std::map<K, V>;

  /// Default constructor.
  Variant()
  : VariantContainerBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the
   * GVariant or not (not taking one could destroy the GVariant with the
   * wrapper).
   */
  explicit Variant(GVariant* castitem,
    bool take_a_reference = false)
  : VariantContainerBase(castitem, take_a_reference)
  {}

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,28}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Creates a new Variant containing a dictionary from a map.
   * @param data The map to use for creation.
   * @return The new Variant holding a dictionary.
   * @newin{2,28}
   */
  static auto create(const std::map<K, V>& data) -> Variant< std::map<K, V> >;

  /** Gets a specific dictionary entry from the string array.  It is an error
   * if @a index is greater than the number of child items in the container.
   * See VariantContainerBase::get_n_children().
   *
   * This function is O(1).
   *
   * @param index The index of the element.
   * @return The dictionary entry at index @a index.
   * @throw std::out_of_range
   * @newin{2,28}
   */
  auto get_child(gsize index) const -> std::pair<K, V>;

  /** Looks up a value in a dictionary Variant.
   * @param key The key to look up.
   * @param value A location in which to store the value if found.
   * @return <tt>true</tt> if the key is found, <tt>false</tt> otherwise.
   */
  auto lookup(const K& key, V& value) const -> bool;


  /** Gets the map (the dictionary) of the Variant.
   * @return The vector.
   * @newin{2,28}
   */
  auto get() const -> std::map<K, V>;

  /** Gets a VariantIter of the Variant.
   * @return the VariantIter.
   * @newin{2,28}
   */
  auto get_iter() const -> VariantIter;
};

/** Specialization of Variant containing a tuple.
 * @newin{2,54}
 * @ingroup Variant
 */
template <class... Types>
class Variant<std::tuple<Types...>> : public VariantContainerBase
{
public:
  using CppContainerType = std::tuple<Types...>;

  /// Default constructor
  Variant()
  : VariantContainerBase()
  {}

  /** GVariant constructor.
   * @param castitem The GVariant to wrap.
   * @param take_a_reference Whether to take an extra reference of the GVariant
   *        or not (not taking one could destroy the GVariant with the wrapper).
   */
  explicit Variant(GVariant* castitem, bool take_a_reference = false)
  : VariantContainerBase(castitem, take_a_reference)
  {}

  /** Creates a new Variant containing a tuple.
   * @param data The tuple to use for creation.
   * @return The new Variant holding a tuple.
   * @newin{2,54}
   */
  static auto create(const std::tuple<Types...>& data) -> Variant<std::tuple<Types...>>;

  /** Gets the VariantType.
   * @return The VariantType.
   * @newin{2,54}
   */
  static auto variant_type() -> const VariantType& G_GNUC_CONST;

  /** Gets a specific element from the tuple.
   * It is an error if @a index is greater than or equal to the number of
   * elements in the tuple. See VariantContainerBase::get_n_children().
   *
   * @param index The index of the element.
   * @return The tuple element at index @a index.
   * @throw std::out_of_range
   * @newin{2,54}
   */
  template<class T>
  auto get_child(gsize index) const -> T;

  template<class T>
  auto get_child_variant(gsize index) const -> Variant<T>;

  /** Gets the tuple of the Variant.
   * @return The tuple.
   * @newin{2,54}
   */
  auto get() const -> std::tuple<Types...>;

  /** Gets a VariantIter of the Variant.
   * @return The VariantIter.
   * @newin{2,54}
   */
  auto get_iter() const -> VariantIter;
};

} // namespace Glib


//We ignore g_variant_get_*() methods that are wrapped by Variant<> specializations, such as in variant_basictypes.h.m4.


/* Include generated specializations of Variant<> for fundamental types:
 */
#define _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H
#include <libmm-glib/variant_basictypes.hpp>
#undef _GLIBMM_VARIANT_H_INCLUDE_VARIANT_BASICTYPES_H

namespace Glib
{

/*--------------------Variant< Variant<T> >---------------------*/

template<class T>
Variant< Variant<T> >::Variant()
: VariantContainerBase()
{
}

template<class T>
Variant< Variant<T> >::Variant(GVariant* castitem, bool take_a_reference)
: VariantContainerBase(castitem, take_a_reference)
{
}

// static
template<class T>
auto Variant< Variant<T> >::variant_type() -> const VariantType&
{
  return VARIANT_TYPE_VARIANT;
}

template<class T>
auto Variant< Variant<T> >::create(const Variant<T>& data) -> Variant< Variant<T> >
{
  Variant< Variant<T> > result = Variant< Variant<T> >(
    g_variant_new_variant(const_cast<GVariant*>(data.gobj())));
  return result;
}

template<class T>
auto Variant< Variant<T> >::get() const -> Variant<T>
{
  GVariant* const gvariant = g_variant_get_variant(gobject_);
  return Variant<T>(gvariant);
}

/*--------------------Variant< std::pair<K, V> >---------------------*/

// static
template<class K, class V>
auto Variant< std::pair<K, V> >::variant_type() -> const VariantType&
{
  static VariantType type(
    g_variant_type_new_dict_entry(Variant<K>::variant_type().gobj(),
    Variant<V>::variant_type().gobj()));

  return type;
}

template<class K, class V>
auto
Variant< std::pair<K, V> >::create(const std::pair<K, V>& data) -> Variant< std::pair<K, V> >
{
  Variant<K> key = Variant<K>::create(data.first);
  Variant<V> value = Variant<V>::create(data.second);

  Variant< std::pair<K, V> > result = Variant< std::pair<K, V> >(
    g_variant_new_dict_entry(key.gobj(), value.gobj()));

  return result;
}

template<class K, class V>
auto Variant< std::pair<K, V> >::get() const -> std::pair<K, V>
{
  // Get the key (the first element of this VariantContainerBase).
  Variant<K> key;
  VariantContainerBase::get_child(key, 0);

  // Get the value (the second element of this VariantContainerBase).
  Variant<V> value;
  VariantContainerBase::get_child(value, 1);

  std::pair<K, V> result(key.get(), value.get());

  return result;
}

/*---------------------Variant< std::vector<T> >---------------------*/

// static
template<class T>
auto Variant< std::vector<T> >::variant_type() -> const VariantType&
{
  static VariantType type =
    VariantType::create_array(Variant<T>::variant_type());

  return type;
}

template<class T>
auto
Variant< std::vector<T> >::create(const std::vector<T>& data) -> Variant< std::vector<T> >
{
  // Get the variant type of the array.
  VariantType array_variant_type = Variant< std::vector<T> >::variant_type();

  // Create a GVariantBuilder to build the array.
  GVariantBuilder* builder = g_variant_builder_new(array_variant_type.gobj());

  // Add the elements of the vector into the builder.
  for(const auto& element : data)
  {
    Glib::Variant<T> variant = Glib::Variant<T>::create(element);
    g_variant_builder_add_value(builder, variant.gobj());
  }

  // Create the variant using the builder.
  Variant< std::vector<T> > result =
    Variant< std::vector<T> >(g_variant_new(
      reinterpret_cast<const gchar*>(array_variant_type.gobj()), builder));

  g_variant_builder_unref(builder);

  return result;
}

template<class T>
auto Variant< std::vector<T> >::get_child(gsize index) const -> T
{
  if (index >= get_n_children())
    throw std::out_of_range(
      "Variant< std::vector<T> >::get_child(): Index out of bounds.");

  Glib::Variant<T> variant;

  GVariant* gvariant =
    g_variant_get_child_value(const_cast<GVariant*>(gobj()), index);

  variant.init(gvariant);
  return variant.get();
}

template<class T>
auto Variant< std::vector<T> >::get() const -> std::vector<T>
{
  std::vector<T> result;

  for (gsize i = 0, n_children = get_n_children(); i < n_children; ++i)
  {
    Glib::Variant<T> variant;

    GVariant* gvariant =
      g_variant_get_child_value(const_cast<GVariant*>(gobj()), i);

    variant.init(gvariant);
    result.emplace_back(variant.get());
  }

  return result;
}

template<class T>
auto Variant< std::vector<T> >::get_iter() const -> VariantIter
{
  return VariantContainerBase::get_iter(variant_type());
}

/*---------------------Variant< std::map<K, V> > --------------------*/

// static
template<class K, class V>
auto Variant< std::map<K, V> >::variant_type() -> const VariantType&
{
  static VariantType type =
    VariantType::create_array(Variant< std::pair<K, V> >::variant_type());

  return type;
}

template<class K, class V>
auto
Variant< std::map<K, V> >::create(const std::map<K, V>& data) -> Variant< std::map<K, V> >
{
  // Get the variant type of the elements.
  VariantType element_variant_type =
    Variant< std::pair<K, V> >::variant_type();

  // Get the variant type of the array.
  VariantType array_variant_type = Variant< std::map<K, V> >::variant_type();

  // Create a GVariantBuilder to build the array.
  GVariantBuilder* builder = g_variant_builder_new(array_variant_type.gobj());

  // Add the elements of the map into the builder.
  for(const auto& element : data)
  {
    auto dict_entry =
      Variant< std::pair<K, V> >::create(element);

    g_variant_builder_add_value(builder, dict_entry.gobj());
  }

  // Create the variant using the builder.
  Variant< std::map<K, V> > result = Variant< std::map<K, V> >(g_variant_new(
    reinterpret_cast<const gchar*>(array_variant_type.gobj()), builder));

  g_variant_builder_unref(builder);

  return result;
}

template<class K, class V>
auto
Variant< std::map<K, V> >::get_child(gsize index) const -> std::pair<K, V>
{
  Variant< std::pair<K, V> > dict_entry;
  VariantContainerBase::get_child(dict_entry, index);
  return dict_entry.get();
}

template<class K, class V>
auto Variant< std::map<K, V> >::lookup(const K& key, V& value) const -> bool
{
  // The code in this method pretty much reflects the g_variant_lookup_value()
  // function except that it's more general to deal with keys that are not
  // just strings.
  VariantIter iter = get_iter();

  Variant< std::pair<K, V> > entry;

  while(iter.next_value(entry))
  {
    std::pair<K, V> element = entry.get();

    if(element.first == key)
    {
      value = element.second;
      return true;
    }
  }

  return false;
}

template<class K, class V>
auto Variant< std::map<K, V> >::get() const -> std::map<K, V>
{
  std::map<K, V> result;
  VariantIter iter = get_iter();
  Variant< std::pair<K, V> > entry;

  while(iter.next_value(entry))
  {
    result.insert(entry.get());
  }

  return result;
}

template<class K, class V>
auto Variant< std::map<K, V> >::get_iter() const -> VariantIter
{
  return VariantContainerBase::get_iter(variant_type());
}

/*---------------------Variant<std::tuple<class... Types>> --------------------*/

// static
template <class... Types>
auto Variant<std::tuple<Types...>>::variant_type() -> const VariantType&
{
  std::vector<VariantType> types;
  auto expander = [&types](const VariantType &type) mutable -> int
  {
    types.push_back(type);
    return 0;
  };

  // expands the variadic template parameters
  using swallow = int[]; // ensures left to right order
  (void)swallow{(expander(Variant<Types>::variant_type()))...};
  static auto type = VariantType::create_tuple(types);

  return type;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace detail
{
template <class Tuple, std::size_t... Is>
void expand_tuple(std::vector<VariantBase> &variants, const Tuple & t,
                  std::index_sequence<Is...>)
{
  using swallow = int[]; // ensures left to right order
  auto expander = [&variants](const VariantBase &variant) -> int
  {
    variants.push_back(variant);
    return 0;
  };
  (void)swallow {(expander(Variant<typename std::tuple_element<Is, Tuple>::type>::create(std::get<Is>(t))))...};
}
} // namespace detail
#endif // DOXYGEN_SHOULD_SKIP_THIS

template <class... Types>
auto
Variant<std::tuple<Types...>>::create(const std::tuple<Types...>& data) -> Variant<std::tuple<Types...>>
{
  // create a vector containing all tuple values as variants
  std::vector<Glib::VariantBase> variants;
  detail::expand_tuple(variants, data, std::index_sequence_for<Types...>{});

  using var_ptr = GVariant*;
  auto var_array = std::make_unique<var_ptr[]>(sizeof... (Types));

  for (std::vector<VariantBase>::size_type i = 0; i < variants.size(); i++)
    var_array[i] = const_cast<GVariant*>(variants[i].gobj());

  Variant<std::tuple<Types...>> result = Variant<std::tuple<Types...>>(
          g_variant_new_tuple(var_array.get(), variants.size()));

  return result;
}

template <class... Types>
template <class T>
auto Variant<std::tuple<Types...>>::get_child(gsize index) const -> T
{
  Variant<T> entry;
  VariantContainerBase::get_child(entry, index);
  return entry.get();
}

template <class... Types>
template <class T>
auto Variant<std::tuple<Types...>>::get_child_variant(gsize index) const -> Variant<T>
{
  Variant<T> entry;
  VariantContainerBase::get_child(entry, index);
  return entry;
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace detail
{
// swallows any argument
template <class T>
constexpr auto any_arg(T&& arg) -> int
{
  (void)arg;
  return 0;
}

template <class Tuple, std::size_t... Is>
void assign_tuple(std::vector<VariantBase> &variants, Tuple & t, std::index_sequence<Is...>)
{
  int i = 0;
  using swallow = int[]; // ensures left to right order
  (void)swallow {(any_arg(std::get<Is>(t) = VariantBase::cast_dynamic<Variant<typename std::tuple_element<Is, Tuple>::type > >(variants[i++]).get()))...};
}
} // namespace detail
#endif // DOXYGEN_SHOULD_SKIP_THIS

template <class... Types>
auto Variant<std::tuple<Types...>>::get() const -> std::tuple<Types...>
{
  std::tuple<Types...> data;
  int i = 0;

  std::vector<VariantBase> variants;
  using swallow = int[]; // ensures left to right order
  auto expander = [&variants, &i](const VariantBase &variant) -> int
  {
    variants.push_back(variant);
    return i++;
  };
  (void)swallow{(expander(get_child_variant<Types>(i)))...};
  detail::assign_tuple(variants, data, std::index_sequence_for<Types...>{});

  return data;
}

template< class... Types>
auto Variant<std::tuple<Types...>>::get_iter() const -> VariantIter
{
  const auto type = variant_type();
  return VariantContainerBase::get_iter(type);
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// This is needed so Glib::VariantBase can be used with
// Glib::Value and _WRAP_PROPERTY in Gio::Action and elsewhere.
template <>
class GLIBMM_API Value<Glib::VariantBase> : public ValueBase_Variant
{
public:
  using CppType = Glib::VariantBase;

  void set(CppType data);
  auto get() const -> CppType;
};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


namespace Glib
{

/** @relates Glib::VariantBase
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(VariantBase& lhs, VariantBase& rhs) noexcept
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
   * @relates Glib::VariantBase
   */
  GLIBMM_API
  auto wrap(GVariant* object, bool take_copy = false) -> Glib::VariantBase;

} // namespace Glib


#endif /* _GLIBMM_VARIANT_H */

