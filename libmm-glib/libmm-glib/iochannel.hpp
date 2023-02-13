
#ifndef _GLIBMM_IOCHANNEL_H
#define _GLIBMM_IOCHANNEL_H


/* Copyright (C) 2002 The gtkmm Development Team
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


#include <mm/glib/mm-glibconfig.hpp>
#include <glib.h> //For the GIOCondition enum values.
#include <mm/glib/error.hpp>
#include <mm/glib/refptr.hpp>
#include <mm/glib/ustring.hpp>
#include <sigc++/sigc++.h>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GIOChannel GIOChannel; }
#endif

namespace Glib
{

class Source;
class IOSource;

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/**
 *  @var SeekType CUR
 * The current position in the file.
 *
 *  @var SeekType SET
 * The start of the file.
 *
 *  @var SeekType END
 * The end of the file.
 *
 *  @enum SeekType
 *
 * An enumeration specifying the base position for a
 * g_io_channel_seek_position() operation.
 *
 * @ingroup glibmmEnums
 */
enum class SeekType
{
  CUR,
  SET,
  END
};


/**
 *  @var IOStatus ERROR
 * An error occurred.
 *
 *  @var IOStatus NORMAL
 * Success.
 *
 *  @var IOStatus ENDOFFILE
 * End of file.
 *
 *  @var IOStatus AGAIN
 * Resource temporarily unavailable.
 *
 *  @enum IOStatus
 *
 * Statuses returned by most of the IOFuncs functions.
 *
 * @ingroup glibmmEnums
 */
enum class IOStatus
{
  ERROR,
  NORMAL,
  ENDOFFILE,
  AGAIN
};


/**
 *  @var IOFlags NONE
 * No special flags set. @newin{2,74}
 *
 *  @var IOFlags APPEND
 * Turns on append mode, corresponds to O_APPEND
 * (see the documentation of the UNIX open() syscall).
 *
 *  @var IOFlags NONBLOCK
 * Turns on nonblocking mode, corresponds to
 * O_NONBLOCK/O_NDELAY (see the documentation of the UNIX open()
 * syscall).
 *
 *  @var IOFlags IS_READABLE
 * Indicates that the io channel is readable.
 * This flag cannot be changed.
 *
 *  @var IOFlags IS_WRITABLE
 * Indicates that the io channel is writable.
 * This flag cannot be changed.
 *
 *  @var IOFlags IS_WRITEABLE
 * A misspelled version of @a G_IO_FLAG_IS_WRITABLE
 * that existed before the spelling was fixed in GLib 2.30. It is kept
 * here for compatibility reasons. Deprecated since 2.30.
 *
 *  @var IOFlags IS_SEEKABLE
 * Indicates that the io channel is seekable,
 * i.e. that g_io_channel_seek_position() can be used on it.
 * This flag cannot be changed.
 *
 *  @var IOFlags MASK
 * The mask that specifies all the valid flags.
 *
 *  @var IOFlags GET_MASK
 * The mask of the flags that are returned from
 * g_io_channel_get_flags().
 *
 *  @var IOFlags SET_MASK
 * The mask of the flags that the user can modify
 * with g_io_channel_set_flags().
 *
 *  @enum IOFlags
 *
 * Specifies properties of a IOChannel. Some of the flags can only be
 * read with g_io_channel_get_flags(), but not changed with
 * g_io_channel_set_flags().
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>IOFlags operator|(IOFlags, IOFlags)</tt><br>
 * <tt>IOFlags operator&(IOFlags, IOFlags)</tt><br>
 * <tt>IOFlags operator^(IOFlags, IOFlags)</tt><br>
 * <tt>IOFlags operator~(IOFlags)</tt><br>
 * <tt>IOFlags& operator|=(IOFlags&, IOFlags)</tt><br>
 * <tt>IOFlags& operator&=(IOFlags&, IOFlags)</tt><br>
 * <tt>IOFlags& operator^=(IOFlags&, IOFlags)</tt><br>
 */
enum class IOFlags
{
  NONE = 0x0,
  APPEND = 1 << 0,
  NONBLOCK = 1 << 1,
  IS_READABLE = 1 << 2,
  IS_WRITABLE = 1 << 3,
  IS_WRITEABLE = 1 << 3,
  IS_SEEKABLE = 1 << 4,
  MASK = (1 << 5) - 1,
  GET_MASK = 0x1f,
  SET_MASK = 0x3
};

/** @ingroup glibmmEnums */
inline auto operator|(IOFlags lhs, IOFlags rhs) -> IOFlags
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(IOFlags lhs, IOFlags rhs) -> IOFlags
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(IOFlags lhs, IOFlags rhs) -> IOFlags
  { return static_cast<IOFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(IOFlags flags) -> IOFlags
  { return static_cast<IOFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(IOFlags& lhs, IOFlags rhs) -> IOFlags&
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(IOFlags& lhs, IOFlags rhs) -> IOFlags&
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(IOFlags& lhs, IOFlags rhs) -> IOFlags&
  { return (lhs = static_cast<IOFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


// Glib::IOCondition::IN and Glib::IOCondition::OUT would be problematic.
// IN and OUT can be preprocessor macros.
// See https://bugzilla.gnome.org/show_bug.cgi?id=786717
/**  @enum IOCondition
 * A bitwise combination representing an I/O condition to watch for on an
 * event source.
 * The flags correspond to those used by the <tt>%poll()</tt> system call
 * on UNIX (see <tt>man 2 poll</tt>).  To test for individual flags, do
 * something like this:
 * @code
 * if ((condition & Glib::IOCondition::IO_OUT) == Glib::IOCondition::IO_OUT)
 *   do_some_output();
 * @endcode
 *  @var IOCondition IO_IN
 * There is data to read.
 *
 *  @var IOCondition IO_OUT
 * Data can be written (without blocking).
 *
 *  @var IOCondition IO_PRI
 * There is urgent data to read.
 *
 *  @var IOCondition IO_ERR
 * Error condition.
 *
 *  @var IOCondition IO_HUP
 * Hung up (the connection has been broken, usually for
 * pipes and sockets).
 *
 *  @var IOCondition IO_NVAL
 * Invalid request. The file descriptor is not open.
 *
 *  @enum IOCondition
 *
 * A bitwise combination representing a condition to watch for on an
 * event source.
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>IOCondition operator|(IOCondition, IOCondition)</tt><br>
 * <tt>IOCondition operator&(IOCondition, IOCondition)</tt><br>
 * <tt>IOCondition operator^(IOCondition, IOCondition)</tt><br>
 * <tt>IOCondition operator~(IOCondition)</tt><br>
 * <tt>IOCondition& operator|=(IOCondition&, IOCondition)</tt><br>
 * <tt>IOCondition& operator&=(IOCondition&, IOCondition)</tt><br>
 * <tt>IOCondition& operator^=(IOCondition&, IOCondition)</tt><br>
 */
enum class IOCondition
{
  IO_IN = G_IO_IN,
  IO_OUT = G_IO_OUT,
  IO_PRI = G_IO_PRI,
  IO_ERR = G_IO_ERR,
  IO_HUP = G_IO_HUP,
  IO_NVAL = G_IO_NVAL
};

/** @ingroup glibmmEnums */
inline auto operator|(IOCondition lhs, IOCondition rhs) -> IOCondition
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator&(IOCondition lhs, IOCondition rhs) -> IOCondition
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator^(IOCondition lhs, IOCondition rhs) -> IOCondition
  { return static_cast<IOCondition>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline auto operator~(IOCondition flags) -> IOCondition
  { return static_cast<IOCondition>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline auto operator|=(IOCondition& lhs, IOCondition rhs) -> IOCondition&
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator&=(IOCondition& lhs, IOCondition rhs) -> IOCondition&
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline auto operator^=(IOCondition& lhs, IOCondition rhs) -> IOCondition&
  { return (lhs = static_cast<IOCondition>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**  %Exception class for IOChannel errors.
 */
class IOChannelError : public Glib::Error
{
public:
  /**  @var Code FILE_TOO_BIG
   * File too large.
   *
   *  @var Code INVALID_ARGUMENT
   * Invalid argument.
   *
   *  @var Code IO_ERROR
   * IO error.
   *
   *  @var Code IS_DIRECTORY
   * File is a directory.
   *
   *  @var Code NO_SPACE_LEFT
   * No space left on device.
   *
   *  @var Code NO_SUCH_DEVICE
   * No such device or address.
   *
   *  @var Code OVERFLOWN
   * Value too large for defined datatype.
   *
   *  @var Code BROKEN_PIPE
   * Broken pipe.
   *
   *  @var Code FAILED
   * Some other error.
   *
   *  @enum Code
   *
   * %Error codes returned by IOChannel operations.
   */
  enum Code
  {
    FILE_TOO_BIG,
    INVALID_ARGUMENT,
    IO_ERROR,
    IS_DIRECTORY,
    NO_SPACE_LEFT,
    NO_SUCH_DEVICE,
    OVERFLOWN,
    BROKEN_PIPE,
    FAILED
  };

  GLIBMM_API IOChannelError(Code error_code, const Glib::ustring& error_message);
  GLIBMM_API explicit IOChannelError(GError* gobject);
  GLIBMM_API auto code() const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  GLIBMM_API static void throw_func(GError* gobject);

  friend GLIBMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS
class GlibmmIOChannel;
#endif

/** IOChannel aims to provide portable I/O support for files, pipes
 * and sockets, and to integrate them with the GLib main event loop.
 *
 * Note that IOChannels implement an automatic implicit character set
 * conversion to the data stream, and usually will not pass by default
 * binary data unchanged.  To set the encoding of the channel, use e.g.
 * set_encoding("ISO-8859-15"). To set the channel to no encoding, use
 * set_encoding() without any arguments.
 *
 * You can create an IOChannel with one of the static create methods.
 */
class GLIBMM_API IOChannel : public sigc::trackable
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = IOChannel;
  using BaseObjectType = GIOChannel;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:


  IOChannel(IOChannel&& other) noexcept;
  auto operator=(IOChannel&& other) noexcept -> IOChannel&;


public:
  virtual ~IOChannel();

  /** Open a file @a filename as an I/O channel using mode @a mode.
   * This channel will be closed when the last reference to it is dropped,
   * so there is no need to call close() (though doing so will not cause
   * problems, as long as no attempt is made to access the channel after
   * it is closed).
   * @param filename The name of the file to open.
   * @param mode One of <tt>"r"</tt>, <tt>"w"</tt>, <tt>"a"</tt>,
   *  <tt>"r+"</tt>, <tt>"w+"</tt>, <tt>"a+"</tt>. These have the
   *  same meaning as in <tt>fopen()</tt>.
   * @return An IOChannel for the opened file.
   * @throw Glib::FileError
   */
  static auto create_from_file(const std::string& filename, const std::string& mode) -> Glib::RefPtr<IOChannel>;


  /** Creates an I/O channel from a file descriptor.
   * On Unix, IOChannels created with this function work for any file
   * descriptor or socket.
   *
   * On Win32, this can be used either for files opened with the MSVCRT (the
   * Microsoft run-time C library) <tt>_open()</tt> or <tt>_pipe()</tt>,
   * including file descriptors 0, 1 and 2 (corresponding to <tt>stdin</tt>,
   * <tt>stdout</tt> and <tt>stderr</tt>), or for Winsock <tt>SOCKET</tt>s. If
   * the parameter is a legal file descriptor, it is assumed to be such,
   * otherwise it should be a <tt>SOCKET</tt>. This relies on <tt>SOCKET</tt>s
   * and file descriptors not overlapping. If you want to be certain, call
   * either create_from_win32_fd() or create_from_win32_socket() instead as
   * appropriate.
   *
   * The term file descriptor as used in the context of Win32 refers to the
   * emulated Unix-like file descriptors MSVCRT provides. The native
   * corresponding concept is file <tt>HANDLE</tt>. There isn't as of yet
   * a way to get IOChannels for Win32 file <tt>HANDLE</tt>s.
   */
  static auto create_from_fd(int fd) -> Glib::RefPtr<IOChannel>;


#ifdef G_OS_WIN32

  /** Create an I/O channel for C runtime (emulated Unix-like) file descriptors.
   * After calling add_watch() on a I/O channel returned by this function, you
   * shouldn't call read() on the file descriptor. This is because adding
   * polling for a file descriptor is implemented on Win32 by starting a thread
   * that sits blocked in a <tt>%read()</tt> from the file descriptor most of
   * the time.  All reads from the file descriptor should be done by this
   * internal GLib thread. Your code should call only IOChannel::read().
   */
  static Glib::RefPtr<IOChannel> create_from_win32_fd(int fd);


  /** Create an I/O channel for a winsock socket. The parameter should be a
   * <tt>SOCKET</tt>. Contrary to I/O channels for file descriptors (on Win32),
   * you can use normal <tt>recv()</tt> or <tt>recvfrom()</tt> on sockets even
   * if GLib is polling them.
   */
  static Glib::RefPtr<IOChannel> create_from_win32_socket(int socket);


#endif /* G_OS_WIN32 */


  /** Read a single UCS-4 character.
   * @param[out] thechar The Unicode character.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto read(gunichar& thechar) -> IOStatus;


  /** Read a character sequence into memory.
   * @param buf A buffer to read data into.
   * @param count The size of the buffer in bytes.  Note that the buffer may
   * not be complelely filled even if there is data in the buffer if the
   * remaining data is not a complete character.
   * @param[out] bytes_read The number of bytes read.  This may be zero even on
   * success if @a count < 6 and the channel's encoding is not <tt>""</tt>.
   * This indicates that the next UTF-8 character is too wide for the buffer.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto read(char* buf, gsize count, gsize& bytes_read) -> IOStatus;

  /** Read a maximum of @a count bytes into @a str.
   * @param[out] str The characters that have been read.
   * @param count The maximum number of bytes to read.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto read(Glib::ustring& str, gsize count) -> IOStatus;

  /** Read a whole line.
   * Reads until the line separator is found, which is included
   * in the result string.
   * @param[out] line The line that was read.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto read_line(Glib::ustring& line) -> IOStatus;


  /** Reads all the remaining data from the file.
   * @param[out] str The resulting string.
   * @return Glib::IOStatus::NORMAL on success. This function never
   *  returns Glib::IOStatus::ENDOFFILE.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto read_to_end(Glib::ustring& str) -> IOStatus;


  /** Write a string to the I/O channel.
   * Note that this method does not return the number of characters written.
   * If the channel is blocking and the returned value is
   * Glib::IOStatus::NORMAL, the whole string was written.
   * @param str the string to write.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto write(const Glib::ustring& str) -> IOStatus;


  /** Write a memory area of @a count bytes to the I/O channel.
   * @param buf The start of the memory area.
   * @param count The number of bytes to write.
   * @param[out] bytes_written The number of bytes written to the channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto write(const char* buf, gssize count, gsize& bytes_written) -> IOStatus;


  /** Write a single UCS-4 character to the I/O channel.
   * @param unichar The character to write.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto write(gunichar unichar) -> IOStatus;


  /** Seek the I/O channel to a specific position.
   * @param offset The offset in bytes from the position specified by @a type.
   * @param type A SeekType. The type Glib::SeekType::CUR is only allowed in
   * those cases where a call to set_encoding() is allowed. See the
   * documentation for set_encoding() for details.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto seek(gint64 offset, SeekType type =  SeekType::SET) -> IOStatus;


  /** Flush the buffers of the I/O channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   * @throw Glib::ConvertError
   */
  auto flush() -> IOStatus;


  /** Close the I/O channel.
   * Any pending data to be written will be flushed if @a flush is <tt>true</tt>.
   * The channel will not be freed until the last reference is dropped.
   * Accessing the channel after closing it is considered an error.
   * @param flush_pending Whether to flush() pending data before closing the channel.
   * @return The status of the operation.
   * @throw Glib::IOChannelError
   */
  auto close(bool flush_pending =  true) -> IOStatus;


  /** Get the IOChannel internal buffer size.
   * @return The buffer size.
   */
  auto get_buffer_size() const -> gsize;


  /** Set the internal IOChannel buffer size.
   * @param size The buffer size the IOChannel should use.
   */
  void set_buffer_size(gsize size);


  /** Get the current flags for a IOChannel, including read-only
   * flags such as Glib::IOFlags::IS_READABLE.
   *
   * The values of the flags Glib::IOFlags::IS_READABLE and
   * Glib::IOFlags::IS_WRITEABLE are cached for internal use by the channel when
   * it is created.  If they should change at some later point (e.g. partial
   * shutdown of a socket with the UNIX <tt>shutdown()</tt> function), the user
   * should immediately call get_flags() to update the internal values of these
   * flags.
   * @return Bitwise combination of the flags set on the channel.
   */
  auto get_flags() const -> IOFlags;


  /** Set flags on the IOChannel.
   * @param flags Bitwise combination of the flags to set.
   * @return The operation result code.
   * @throw Glib::IOChannelError
   */
  auto set_flags(IOFlags flags) -> IOStatus;


  /** Set the buffering status of the I/O channel.
   * The buffering state can only be set if the channel's encoding is
   * <tt>""</tt>. For any other encoding, the channel must be buffered.
   *
   * A buffered channel can only be set unbuffered if the channel's internal
   * buffers have been flushed. Newly created channels or channels which have
   * returned Glib::IOStatus::ENDOFFILE not require such a flush. For write-only
   * channels, a call to flush() is sufficient. For all other channels, the
   * buffers may be flushed by a call to seek().  This includes the possibility
   * of seeking with seek type Glib::SeekType::CUR and an offset of zero. Note
   * that this means that socket-based channels cannot be set unbuffered once
   * they have had data read from them.
   *
   * The default state of the channel is buffered.
   *
   * @param buffered Whether to set the channel buffered or unbuffered.
   */
  void set_buffered(bool buffered);


  /** Get the buffering status of the I/O channel.
   * @return The buffering status of the channel.
   */
  auto get_buffered() const -> bool;


  /** Returns an IOCondition depending on whether there is data to be
   * read/space to write data in the internal buffers in the I/O channel.
   * Only the flags Glib::IOCondition::IO_IN and Glib::IOCondition::IO_OUT may be set.
   * @return Bitwise combination of Glib::IOCondition flags.
   */
  auto get_buffer_condition() const -> IOCondition;


  /** Returns whether the file/socket/whatever associated with the I/O channel
   * will be closed when the channel receives its final unref and is destroyed.
   * The default value of this is <tt>true</tt> for channels created by
   * create_from_file(), and <tt>false</tt> for all other channels.
   * @return Whether the channel will be closed on the final unref of the
   * IOChannel object.
   */
  auto get_close_on_unref() const -> bool;


  /** Setting this flag to <tt>true</tt> for a channel you have already closed
   * can cause problems.
   * @param do_close Whether to close the channel on the final unref of the
   * IOChannel object.  The default value of this is <tt>true</tt> for channels
   * created by create_from_file(), and <tt>false</tt> for all other channels.
   */
  void set_close_on_unref(bool do_close);

  /** Sets the encoding for the input/output of the channel.
   * The internal encoding is always UTF-8.  The default encoding for the
   * external file is UTF-8.  The encoding <tt>""</tt> is safe to use with
   * binary data.
   *
   * The encoding can only be set if one of the following conditions
   * is true:
   *
   * -# The channel was just created, and has not been written to or read from
   *  yet.
   * -# The channel is write-only.
   * -# The channel is a file, and the file pointer was just repositioned by a
   *  call to seek_position().  (This flushes all the internal buffers.)
   * -# The current encoding is <tt>""</tt> or UTF-8.
   * -# One of the read methods has just returned Glib::IOStatus::ENDOFFILE (or, in
   *  the case of read_to_end(), Glib::IOStatus::NORMAL).
   * -# The read() method has returned Glib::IOStatus::AGAIN or thrown
   *  a Glib::Error exception.  This may be useful in the case of
   *  ConvertError::ILLEGAL_SEQUENCE.  Returning one of these statuses
   *  from read_line() or read_to_end() does <em>not</em> guarantee that
   *  the encoding can be changed.
   *
   * Channels which do not meet one of the above conditions cannot call
   * seek_position() with a seek type of Glib::SeekType::CUR and, if they
   * are "seekable", cannot call write() after calling one of the API
   * "read" methods.
   *
   * @param encoding The encoding name, or <tt>""</tt> for binary.
   * @return Glib::IOStatus::NORMAL if the encoding was successfully set.
   * @throw Glib::IOChannelError
   */
  auto set_encoding(const std::string& encoding = {}) -> IOStatus;


  /** Get the encoding of the I/O channel.
   * @return The current encoding of the channel.
   */
  auto get_encoding() const -> std::string;


  void set_line_term(const std::string& term = {});


  auto get_line_term() const -> std::string;


  /** Creates an IOSource object.
   * Create a slot from a function to be called when condition is met
   * for the channel with sigc::ptr_fun() or sigc::mem_fun() and pass
   * it into the connect() function of the returned IOSource object.
   * Polling of the channel will start when you attach a MainContext
   * object to the returned IOSource object using its attach() function.
   *
   * Glib::signal_io().connect() is a simpler interface to the same
   * functionality, for the case where you want to add the source to the
   * default main context.
   * @param condition The condition to watch for.
   * @return An IOSource object that can be polled from a MainContext's event loop.
   */
  auto create_watch(IOCondition condition) -> Glib::RefPtr<IOSource>;

  virtual void reference()   const;
  virtual void unreference() const;


  auto       gobj() -> GIOChannel*       { return gobject_; }
  auto gobj() const -> const GIOChannel* { return gobject_; }

protected:
  GIOChannel* gobject_;


#ifndef DOXYGEN_SHOULD_SKIP_THIS
  IOChannel(GIOChannel* gobject, bool take_copy);
#endif

private:
  void release_gobject();


};

GLIBMM_API auto wrap(GIOChannel* gobject, bool take_copy = false) -> Glib::RefPtr<IOChannel>;

} // namespace Glib


#endif /* _GLIBMM_IOCHANNEL_H */

