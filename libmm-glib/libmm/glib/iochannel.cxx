// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/iochannel.hxx>
#include <libmm/glib/iochannel_p.hxx>

#include <libmm/glib/exceptionhandler.hxx>
#include <libmm/glib/iochannel.hxx>
#include <libmm/glib/main.hxx>
#include <libmm/glib/utility.hxx>

namespace
{

  class ForeignIOChannel : public Glib::IOChannel
  {
  public:
    ForeignIOChannel (GIOChannel* gobject, const bool take_copy)
      : IOChannel (gobject, take_copy),
        ref_count_ (0)
    {
    }

    auto
    reference () const -> void override;
    auto
    unreference () const -> void override;

  private:
    mutable int ref_count_;
  };

  auto
  ForeignIOChannel::reference () const -> void
  {
    ++ref_count_;
  }

  auto
  ForeignIOChannel::unreference () const -> void
  {
    if (!--ref_count_)
      delete this;
  }

} // namespace

namespace Glib
{

  IOChannel::IOChannel (IOChannel&& other) noexcept
    : trackable (std::move (other)),
      gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  IOChannel::operator= (IOChannel&& other) noexcept -> IOChannel&
  {
    trackable::operator= (std::move (other));

    release_gobject ();

    gobject_ = std::move (other.gobject_);
    other.gobject_ = nullptr;

    return *this;
  }

  IOChannel::IOChannel (GIOChannel* gobject, const bool take_copy)
    : gobject_ (gobject)
  {
    g_assert (gobject != nullptr);

    if (take_copy)
      g_io_channel_ref (gobject_);
  }

  auto
  IOChannel::release_gobject () -> void
  {
    if (gobject_)
    {
      const auto tmp_gobject = gobject_;
      gobject_ = nullptr;

      g_io_channel_unref (tmp_gobject);
    }
  }

  IOChannel::~IOChannel ()
  {
    release_gobject ();
  }

  auto
  IOChannel::create_from_file (const std::string& filename,
                               const std::string& mode) -> RefPtr<IOChannel>
  {
    GError* gerror = nullptr;
    const auto channel =
        g_io_channel_new_file (filename.c_str (), mode.c_str (), &gerror);

    if (gerror)
    {
      Error::throw_exception (gerror);
    }

    return wrap (channel, false);
  }

  auto
  IOChannel::create_from_fd (const int fd) -> RefPtr<IOChannel>
  {
    return wrap (g_io_channel_unix_new (fd), false);
  }

#ifdef G_OS_WIN32

  auto
  IOChannel::create_from_win32_fd (const int fd) -> RefPtr<IOChannel>
  {
    return wrap (g_io_channel_win32_new_fd (fd), false);
  }

  auto
  IOChannel::create_from_win32_socket (const int socket) -> RefPtr<IOChannel>
  {
    return wrap (g_io_channel_win32_new_socket (socket), false);
  }

#endif

  auto
  IOChannel::write (const ustring& str) -> IOStatus
  {
    gsize bytes_written = 0;
    return write (str.data (), str.bytes (), bytes_written);
  }

  auto
  IOChannel::read_line (ustring& line) -> IOStatus
  {
    GError* gerror = nullptr;
    gsize bytes = 0;
    char* pch_buf = nullptr;

    const auto status =
        g_io_channel_read_line (gobj (), &pch_buf, &bytes, nullptr, &gerror);
    const auto buf = make_unique_ptr_gfree (pch_buf);
    if (gerror)
    {
      Error::throw_exception (gerror);
    }

    if (buf.get ())
      line.assign (buf.get (), buf.get () + bytes);
    else
      line.erase ();

    return (IOStatus) status;
  }

  auto
  IOChannel::read_to_end (ustring& str) -> IOStatus
  {
    GError* gerror = nullptr;
    gsize bytes = 0;
    char* pch_buf = nullptr;

    const auto status =
        g_io_channel_read_to_end (gobj (), &pch_buf, &bytes, &gerror);
    const auto buf = make_unique_ptr_gfree (pch_buf);
    if (gerror)
    {
      Error::throw_exception (gerror);
    }

    if (buf.get ())
      str.assign (buf.get (), buf.get () + bytes);
    else
      str.erase ();

    return (IOStatus) status;
  }

  auto
  IOChannel::read (ustring& str, const gsize count) -> IOStatus
  {
    const auto buf = make_unique_ptr_gfree (g_new (char, count));
    GError* gerror = nullptr;
    gsize bytes = 0;

    const auto status =
        g_io_channel_read_chars (gobj (), buf.get (), count, &bytes, &gerror);

    if (gerror)
    {
      Error::throw_exception (gerror);
    }

    if (buf.get ())
      str.assign (buf.get (), buf.get () + bytes);
    else
      str.erase ();

    return (IOStatus) status;
  }

  auto
  IOChannel::set_encoding (const std::string& encoding) -> IOStatus
  {
    GError* gerror = nullptr;

    const auto status = g_io_channel_set_encoding (gobj (),
                                                   c_str_or_nullptr (encoding),
                                                   &gerror);

    if (gerror)
    {
      Error::throw_exception (gerror);
    }

    return (IOStatus) status;
  }

  auto
  IOChannel::get_encoding () const -> std::string
  {
    const char* const encoding = g_io_channel_get_encoding (gobject_);
    return convert_const_gchar_ptr_to_stdstring (encoding);
  }

  auto
  IOChannel::set_line_term (const std::string& term) -> void
  {
    if (term.empty ())
      g_io_channel_set_line_term (gobj (), nullptr, 0);
    else
      g_io_channel_set_line_term (gobj (), term.data (), term.size ());
  }

  auto
  IOChannel::get_line_term () const -> std::string
  {
    int len = 0;
    const char* const term = g_io_channel_get_line_term (gobject_, &len);

    return term ? std::string (term, len) : std::string ();
  }

  auto
  IOChannel::create_watch (const IOCondition condition) -> RefPtr<IOSource>
  {
    return IOSource::create (gobj (), condition);
  }

  auto
  IOChannel::reference () const -> void
  {
    g_io_channel_ref (gobject_);
  }

  auto
  IOChannel::unreference () const -> void
  {
    g_io_channel_unref (gobject_);
  }

  auto
  wrap (GIOChannel* gobject, const bool take_copy) -> RefPtr<IOChannel>
  {
    IOChannel* cpp_object = nullptr;

    if (gobject)
    {
      cpp_object = new ForeignIOChannel (gobject, take_copy);
      cpp_object->reference ();
    }

    return Glib::make_refptr_for_instance<IOChannel> (cpp_object);
  }

} // namespace Glib

namespace
{
}

Glib::IOChannelError::IOChannelError (const Code error_code,
                                      const ustring& error_message)
  : Error (G_IO_CHANNEL_ERROR, error_code, error_message)
{
}

Glib::IOChannelError::IOChannelError (GError* gobject)
  : Error (gobject)
{
}

auto
Glib::IOChannelError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Glib::IOChannelError::throw_func (GError* gobject) -> void
{
  throw IOChannelError (gobject);
}

namespace Glib
{

  auto
  IOChannel::read (gunichar& thechar) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_read_unichar (gobj (), &thechar, &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::read (char* buf, const gsize count, gsize& bytes_read) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_read_chars (gobj (), buf, count, &bytes_read, &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::write (const char* buf, const gssize count, gsize& bytes_written) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<IOStatus> (g_io_channel_write_chars (gobj (),
                                                         buf,
                                                         count,
                                                         &bytes_written,
                                                         &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::write (const gunichar unichar) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_write_unichar (gobj (), unichar, &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::seek (const gint64 offset, SeekType type) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_seek_position (gobj (),
                                    offset,
                                    static_cast<GSeekType> (type),
                                    &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::flush () -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue =
        static_cast<IOStatus> (g_io_channel_flush (gobj (), &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::close (const bool flush_pending) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_shutdown (gobj (), flush_pending, &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::get_buffer_size () const -> gsize
  {
    return g_io_channel_get_buffer_size (const_cast<GIOChannel*> (gobj ()));
  }

  auto
  IOChannel::set_buffer_size (const gsize size) -> void
  {
    g_io_channel_set_buffer_size (gobj (), size);
  }

  auto
  IOChannel::get_flags () const -> IOFlags
  {
    return static_cast<IOFlags> (
        g_io_channel_get_flags (const_cast<GIOChannel*> (gobj ())));
  }

  auto
  IOChannel::set_flags (IOFlags flags) -> IOStatus
  {
    GError* gerror = nullptr;
    const auto retvalue = static_cast<IOStatus> (
        g_io_channel_set_flags (gobj (),
                                static_cast<GIOFlags> (flags),
                                &gerror));
    if (gerror)
      Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  IOChannel::set_buffered (const bool buffered) -> void
  {
    g_io_channel_set_buffered (gobj (), buffered);
  }

  auto
  IOChannel::get_buffered () const -> bool
  {
    return g_io_channel_get_buffered (const_cast<GIOChannel*> (gobj ()));
  }

  auto
  IOChannel::get_buffer_condition () const -> IOCondition
  {
    return static_cast<IOCondition> (
        g_io_channel_get_buffer_condition (const_cast<GIOChannel*> (gobj ())));
  }

  auto
  IOChannel::get_close_on_unref () const -> bool
  {
    return g_io_channel_get_close_on_unref (const_cast<GIOChannel*> (gobj ()));
  }

  auto
  IOChannel::set_close_on_unref (const bool do_close) -> void
  {
    g_io_channel_set_close_on_unref (gobj (), do_close);
  }

} // namespace Glib
