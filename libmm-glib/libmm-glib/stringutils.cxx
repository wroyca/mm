

#include <cerrno>
#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/stringutils.hxx>
#include <libmm-glib/utility.hxx>
#include <stdexcept>

auto
Glib::str_has_prefix (const std::string& str, const std::string& prefix) -> bool
{
  return g_str_has_prefix (str.c_str (), prefix.c_str ());
}

auto
Glib::str_has_suffix (const std::string& str, const std::string& suffix) -> bool
{
  return g_str_has_suffix (str.c_str (), suffix.c_str ());
}

auto
Glib::Ascii::strtod (const std::string& str) -> double
{
  std::string::size_type dummy;
  return Ascii::strtod (str, dummy, 0);
}

auto
Glib::Ascii::strtod (const std::string& str,
                     std::string::size_type& end_index,
                     const std::string::size_type start_index) -> double
{
  if (start_index >= str.size ())
  {
    throw std::out_of_range ("out of range (strtod): start_index > str.size()");
  }

  const char* const bufptr = str.c_str ();
  char* endptr = nullptr;

  const double result = g_ascii_strtod (bufptr + start_index, &endptr);
  const int err_no = errno;

  if (err_no != 0)
  {
    g_return_val_if_fail (err_no == ERANGE, result);

    if (result > 0.0)
      throw std::overflow_error (
          "overflow (strtod): positive number too large");

    if (result < 0.0)
      throw std::overflow_error (
          "overflow (strtod): negative number too large");

    throw std::underflow_error ("underflow (strtod): number too small");
  }

  if (endptr)
    end_index = endptr - bufptr;
  else
    end_index = str.size ();

  return result;
}

auto
Glib::Ascii::dtostr (const double d) -> std::string
{
  char buf[G_ASCII_DTOSTR_BUF_SIZE];

  return g_ascii_dtostr (buf, sizeof buf, d);
}

auto
Glib::strescape (const std::string& source) -> std::string
{
  const auto buf =
      make_unique_ptr_gfree (g_strescape (source.c_str (), nullptr));
  return buf.get ();
}

auto
Glib::strescape (const std::string& source, const std::string& exceptions)
    -> std::string
{
  const auto buf = make_unique_ptr_gfree (
      g_strescape (source.c_str (), exceptions.c_str ()));
  return buf.get ();
}

auto
Glib::strcompress (const std::string& source) -> std::string
{
  const auto buf = make_unique_ptr_gfree (g_strcompress (source.c_str ()));
  return buf.get ();
}

auto
Glib::strerror (const int errnum) -> ustring
{
  return g_strerror (errnum);
}

auto
Glib::strsignal (const int signum) -> ustring
{
  return g_strsignal (signum);
}
