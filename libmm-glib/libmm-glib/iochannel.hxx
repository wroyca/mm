
#ifndef _GLIBMM_IOCHANNEL_H
#define _GLIBMM_IOCHANNEL_H

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>
#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GIOChannel GIOChannel;
}
#endif

namespace Glib
{

  class Source;
  class IOSource;

  enum class SeekType
  {
    CUR,
    SET,
    END
  };

  enum class IOStatus
  {
    ERROR,
    NORMAL,
    ENDOFFILE,
    AGAIN
  };

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

  inline auto
  operator| (IOFlags lhs, IOFlags rhs) -> IOFlags
  {
    return static_cast<IOFlags> (static_cast<unsigned> (lhs) |
                                 static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (IOFlags lhs, IOFlags rhs) -> IOFlags
  {
    return static_cast<IOFlags> (static_cast<unsigned> (lhs) &
                                 static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (IOFlags lhs, IOFlags rhs) -> IOFlags
  {
    return static_cast<IOFlags> (static_cast<unsigned> (lhs) ^
                                 static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(IOFlags flags) -> IOFlags
  {
    return static_cast<IOFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (IOFlags& lhs, IOFlags rhs) -> IOFlags&
  {
    return (lhs = static_cast<IOFlags> (static_cast<unsigned> (lhs) |
                                        static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (IOFlags& lhs, IOFlags rhs) -> IOFlags&
  {
    return (lhs = static_cast<IOFlags> (static_cast<unsigned> (lhs) &
                                        static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (IOFlags& lhs, IOFlags rhs) -> IOFlags&
  {
    return (lhs = static_cast<IOFlags> (static_cast<unsigned> (lhs) ^
                                        static_cast<unsigned> (rhs)));
  }

  enum class IOCondition
  {
    IO_IN = G_IO_IN,
    IO_OUT = G_IO_OUT,
    IO_PRI = G_IO_PRI,
    IO_ERR = G_IO_ERR,
    IO_HUP = G_IO_HUP,
    IO_NVAL = G_IO_NVAL
  };

  inline auto
  operator| (IOCondition lhs, IOCondition rhs) -> IOCondition
  {
    return static_cast<IOCondition> (static_cast<unsigned> (lhs) |
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (IOCondition lhs, IOCondition rhs) -> IOCondition
  {
    return static_cast<IOCondition> (static_cast<unsigned> (lhs) &
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (IOCondition lhs, IOCondition rhs) -> IOCondition
  {
    return static_cast<IOCondition> (static_cast<unsigned> (lhs) ^
                                     static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(IOCondition flags) -> IOCondition
  {
    return static_cast<IOCondition> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (IOCondition& lhs, IOCondition rhs) -> IOCondition&
  {
    return (lhs = static_cast<IOCondition> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (IOCondition& lhs, IOCondition rhs) -> IOCondition&
  {
    return (lhs = static_cast<IOCondition> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (IOCondition& lhs, IOCondition rhs) -> IOCondition&
  {
    return (lhs = static_cast<IOCondition> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs)));
  }

  class IOChannelError : public Glib::Error
  {
  public:
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

    GLIBMM_API
    IOChannelError (Code error_code, const Glib::ustring& error_message);
    GLIBMM_API explicit IOChannelError (GError* gobject);
    GLIBMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GLIBMM_API static void
    throw_func (GError* gobject);

    friend GLIBMM_API void
    wrap_init ();

#endif
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class GlibmmIOChannel;
#endif

  class GLIBMM_API IOChannel : public sigc::trackable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = IOChannel;
    using BaseObjectType = GIOChannel;
#endif

  private:
    IOChannel (IOChannel&& other) noexcept;
    auto
    operator= (IOChannel&& other) noexcept -> IOChannel&;

  public:
    virtual ~IOChannel ();

    static auto
    create_from_file (const std::string& filename, const std::string& mode)
        -> Glib::RefPtr<IOChannel>;

    static auto
    create_from_fd (int fd) -> Glib::RefPtr<IOChannel>;

#ifdef G_OS_WIN32

    static Glib::RefPtr<IOChannel>
    create_from_win32_fd (int fd);

    static Glib::RefPtr<IOChannel>
    create_from_win32_socket (int socket);

#endif

    auto
    read (gunichar& thechar) -> IOStatus;

    auto
    read (char* buf, gsize count, gsize& bytes_read) -> IOStatus;

    auto
    read (Glib::ustring& str, gsize count) -> IOStatus;

    auto
    read_line (Glib::ustring& line) -> IOStatus;

    auto
    read_to_end (Glib::ustring& str) -> IOStatus;

    auto
    write (const Glib::ustring& str) -> IOStatus;

    auto
    write (const char* buf, gssize count, gsize& bytes_written) -> IOStatus;

    auto
    write (gunichar unichar) -> IOStatus;

    auto
    seek (gint64 offset, SeekType type = SeekType::SET) -> IOStatus;

    auto
    flush () -> IOStatus;

    auto
    close (bool flush_pending = true) -> IOStatus;

    auto
    get_buffer_size () const -> gsize;

    void
    set_buffer_size (gsize size);

    auto
    get_flags () const -> IOFlags;

    auto
    set_flags (IOFlags flags) -> IOStatus;

    void
    set_buffered (bool buffered);

    auto
    get_buffered () const -> bool;

    auto
    get_buffer_condition () const -> IOCondition;

    auto
    get_close_on_unref () const -> bool;

    void
    set_close_on_unref (bool do_close);

    auto
    set_encoding (const std::string& encoding = {}) -> IOStatus;

    auto
    get_encoding () const -> std::string;

    void
    set_line_term (const std::string& term = {});

    auto
    get_line_term () const -> std::string;

    auto
    create_watch (IOCondition condition) -> Glib::RefPtr<IOSource>;

    virtual void
    reference () const;
    virtual void
    unreference () const;

    auto
    gobj () -> GIOChannel*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GIOChannel*
    {
      return gobject_;
    }

  protected:
    GIOChannel* gobject_;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    IOChannel (GIOChannel* gobject, bool take_copy);
#endif

  private:
    void
    release_gobject ();
  };

  GLIBMM_API auto
  wrap (GIOChannel* gobject, bool take_copy = false) -> Glib::RefPtr<IOChannel>;

} // namespace Glib

#endif
