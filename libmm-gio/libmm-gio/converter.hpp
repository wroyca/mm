
#ifndef _GIOMM_CONVERTER_H
#define _GIOMM_CONVERTER_H

#include <mm/gio/gioconfig.hpp>


#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2012 The giomm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GConverterIface GConverterIface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverter = struct _GConverter;
using GConverterClass = struct _GConverterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API Converter_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{


/** Converter - Data conversion interface.
 * Converter is implemented by objects that convert binary data in various
 * ways. The conversion can be stateful and may fail at any place.
 *
 * Some example conversions are: character set conversion, compression,
 * decompression and regular expression replace.
 *
 * @newin{2,34}
 */

class GIOMM_API Converter : public Glib::Interface
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Converter;
  using CppClassType = Converter_Class;
  using BaseObjectType = GConverter;
  using BaseClassType = GConverterIface;

  // noncopyable
  Converter(const Converter&) = delete;
  auto operator=(const Converter&) -> Converter& = delete;

private:
  friend class Converter_Class;
  static CppClassType converter_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  Converter();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit Converter(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit Converter(GConverter* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Converter(Converter&& src) noexcept;
  auto operator=(Converter&& src) noexcept -> Converter&;

  ~Converter() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static auto get_type() -> GType      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static auto get_base_type() -> GType G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  auto       gobj() -> GConverter*       { return reinterpret_cast<GConverter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  auto gobj() const -> const GConverter* { return reinterpret_cast<GConverter*>(gobject_); }

private:


public:
  /** @addtogroup giommEnums giomm Enums and Flags */

  /**
   *  @var Result ERROR
   * There was an error during conversion.
   *
   *  @var Result CONVERTED
   * Some data was consumed or produced.
   *
   *  @var Result FINISHED
   * The conversion is finished.
   *
   *  @var Result FLUSHED
   * Flushing is finished.
   *
   *  @enum Result
   *
   * Results returned from g_converter_convert().
   *
   * @newin{2,24}
   *
   * @ingroup giommEnums
   */
  enum class Result
  {
    ERROR,
    CONVERTED,
    FINISHED,
    FLUSHED
  };


  /**
   *  @var Flags NO_FLAGS
   * No flags.
   *
   *  @var Flags INPUT_AT_END
   * At end of input data.
   *
   *  @var Flags FLUSH
   * Flush data.
   *
   *  @enum Flags
   *
   * Flags used when calling a g_converter_convert().
   *
   * @newin{2,24}
   *
   * @ingroup giommEnums
   * @par Bitwise operators:
   * <tt>Converter::Flags operator|(Converter::Flags, Converter::Flags)</tt><br>
   * <tt>Converter::Flags operator&(Converter::Flags, Converter::Flags)</tt><br>
   * <tt>Converter::Flags operator^(Converter::Flags, Converter::Flags)</tt><br>
   * <tt>Converter::Flags operator~(Converter::Flags)</tt><br>
   * <tt>Converter::Flags& operator|=(Converter::Flags&, Converter::Flags)</tt><br>
   * <tt>Converter::Flags& operator&=(Converter::Flags&, Converter::Flags)</tt><br>
   * <tt>Converter::Flags& operator^=(Converter::Flags&, Converter::Flags)</tt><br>
   */
  enum class Flags
  {
    NO_FLAGS = 0x0,
    INPUT_AT_END = (1 << 0),
    FLUSH = (1 << 1)
  };


  /** This is the main operation used when converting data. It is to be called
   * multiple times in a loop, and each time it will do some work, i.e.
   * producing some output (in @a outbuf) or consuming some input (from @a inbuf) or
   * both. If its not possible to do any work an error is returned.
   *
   * Note that a single call may not consume all input (or any input at all).
   * Also a call may produce output even if given no input, due to state stored
   * in the converter producing output.
   *
   * If any data was either produced or consumed, and then an error happens, then
   * only the successful conversion is reported and the error is returned on the
   * next call.
   *
   * A full conversion loop involves calling this method repeatedly, each time
   * giving it new input and space output space. When there is no more input
   * data after the data in @a inbuf, the flag Gio::Converter::Flags::INPUT_AT_END must be set.
   * The loop will be (unless some error happens) returning Gio::Converter::Result::CONVERTED
   * each time until all data is consumed and all output is produced, then
   * Gio::Converter::Result::FINISHED is returned instead. Note, that Gio::Converter::Result::FINISHED
   * may be returned even if Gio::Converter::Flags::INPUT_AT_END is not set, for instance
   * in a decompression converter where the end of data is detectable from the
   * data (and there might even be other data after the end of the compressed data).
   *
   * When some data has successfully been converted @a bytes_read and is set to
   * the number of bytes read from @a inbuf, and @a bytes_written is set to indicate
   * how many bytes was written to @a outbuf. If there are more data to output
   * or consume (i.e. unless the Gio::Converter::Flags::INPUT_AT_END is specified) then
   * Gio::Converter::Result::CONVERTED is returned, and if no more data is to be output
   * then Gio::Converter::Result::FINISHED is returned.
   *
   * On error Gio::Converter::Result::ERROR is returned and @a error is set accordingly.
   * Some errors need special handling:
   *
   * Gio::Error::NO_SPACE is returned if there is not enough space
   * to write the resulting converted data, the application should
   * call the function again with a larger @a outbuf to continue.
   *
   * Gio::Error::PARTIAL_INPUT is returned if there is not enough
   * input to fully determine what the conversion should produce,
   * and the Gio::Converter::Flags::INPUT_AT_END flag is not set. This happens for
   * example with an incomplete multibyte sequence when converting text,
   * or when a regexp matches up to the end of the input (and may match
   * further input). It may also happen when @a inbuf_size is zero and
   * there is no more data to produce.
   *
   * When this happens the application should read more input and then
   * call the function again. If further input shows that there is no
   * more data call the function again with the same data but with
   * the Gio::Converter::Flags::INPUT_AT_END flag set. This may cause the conversion
   * to finish as e.g. in the regexp match case (or, to fail again with
   * Gio::Error::PARTIAL_INPUT in e.g. a charset conversion where the
   * input is actually partial).
   *
   * After g_converter_convert() has returned Gio::Converter::Result::FINISHED the
   * converter object is in an invalid state where its not allowed
   * to call g_converter_convert() anymore. At this time you can only
   * free the object or call g_converter_reset() to reset it to the
   * initial state.
   *
   * If the flag Gio::Converter::Flags::FLUSH is set then conversion is modified
   * to try to write out all internal state to the output. The application
   * has to call the function multiple times with the flag set, and when
   * the available input has been consumed and all internal state has
   * been produced then Gio::Converter::Result::FLUSHED (or Gio::Converter::Result::FINISHED if
   * really at the end) is returned instead of Gio::Converter::Result::CONVERTED.
   * This is somewhat similar to what happens at the end of the input stream,
   * but done in the middle of the data.
   *
   * This has different meanings for different conversions. For instance
   * in a compression converter it would mean that we flush all the
   * compression state into output such that if you uncompress the
   * compressed data you get back all the input data. Doing this may
   * make the final file larger due to padding though. Another example
   * is a regexp conversion, where if you at the end of the flushed data
   * have a match, but there is also a potential longer match. In the
   * non-flushed case we would ask for more input, but when flushing we
   * treat this as the end of input and do the match.
   *
   * Flushing is not always possible (like if a charset converter flushes
   * at a partial multibyte sequence). Converters are supposed to try
   * to produce as much output as possible and then return an error
   * (typically Gio::Error::PARTIAL_INPUT).
   *
   * @newin{2,24}
   *
   * @param inbuf The buffer
   * containing the data to convert.
   * @param inbuf_size The number of bytes in @a inbuf.
   * @param outbuf A buffer to write
   * converted data in.
   * @param outbuf_size The number of bytes in @a outbuf, must be at least one.
   * @param flags A Gio::Converter::Flags controlling the conversion details.
   * @param bytes_read Will be set to the number of bytes read from @a inbuf on success.
   * @param bytes_written Will be set to the number of bytes written to @a outbuf on success.
   * @return A Gio::Converter::Result, Gio::Converter::Result::ERROR on error.
   *
   * @throws Glib::Error
   */
  auto convert(const void* inbuf, gsize inbuf_size, void* outbuf, gsize outbuf_size, Flags flags, gsize& bytes_read, gsize& bytes_written) -> Result;

  /** Resets all internal state in the converter, making it behave
   * as if it was just created. If the converter has any internal
   * state that would produce output then that output is lost.
   *
   * @newin{2,24}
   */
  void reset();

protected:


  /// @throws Glib::Error.
  virtual auto convert_vfunc(const void* inbuf, gsize inbuf_size, void* outbuf, gsize outbuf_size, Flags flags, gsize& bytes_read, gsize& bytes_written) -> Result;


    virtual void reset_vfunc();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Converter::Result> : public Glib::Value_Enum<Gio::Converter::Result>
{
public:
  static auto value_type() -> GType G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{

/** @ingroup giommEnums */
inline auto operator|(Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  { return static_cast<Converter::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator&(Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  { return static_cast<Converter::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator^(Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  { return static_cast<Converter::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup giommEnums */
inline auto operator~(Converter::Flags flags) -> Converter::Flags
  { return static_cast<Converter::Flags>(~static_cast<unsigned>(flags)); }

/** @ingroup giommEnums */
inline auto operator|=(Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  { return (lhs = static_cast<Converter::Flags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator&=(Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  { return (lhs = static_cast<Converter::Flags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup giommEnums */
inline auto operator^=(Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  { return (lhs = static_cast<Converter::Flags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::Converter::Flags> : public Glib::Value_Flags<Gio::Converter::Flags>
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
   * @relates Gio::Converter
   */
  GIOMM_API
  auto wrap(GConverter* object, bool take_copy = false) -> Glib::RefPtr<Gio::Converter>;

} // namespace Glib


#endif /* _GIOMM_CONVERTER_H */

