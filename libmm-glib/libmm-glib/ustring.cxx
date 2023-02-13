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

#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/convert.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/utility.hxx>

#include <algorithm>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <utility> // For std::move()
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// If glibmm is built with Autotools, GLIBMM_SIZEOF_WCHAR_T is not defined and
// SIZEOF_WCHAR_T is defined in config.h.
// If glibmm is built with Meson, config.h does not exist and
// GLIBMM_SIZEOF_WCHAR_T is defined in glibmmconfig.h.
#if !defined(SIZEOF_WCHAR_T) && defined(GLIBMM_SIZEOF_WCHAR_T)
#define SIZEOF_WCHAR_T GLIBMM_SIZEOF_WCHAR_T
#endif

namespace
{

using Glib::ustring;
using Glib::UStringView;

// Little helper to make the conversion from gunichar to UTF-8 a one-liner.
//
struct UnicharToUtf8
{
  char buf[6];
  ustring::size_type len;

  explicit UnicharToUtf8(const gunichar uc) : len(g_unichar_to_utf8(uc, buf)) {}
};

// All utf8_*_offset() functions return npos if offset is out of range.
// The caller should decide if npos is a valid argument and just marks
// the whole string, or if it is not allowed (e.g. for start positions).
// In the latter case std::out_of_range should be thrown, but usually
// std::string will do that for us.

// First overload: stop on '\0' character.
auto
utf8_byte_offset(const char* str, ustring::size_type offset) -> ustring::size_type
{
  if (offset == ustring::npos)
    return ustring::npos;

  const char* const utf8_skip = g_utf8_skip;
  const char* p = str;

  for (; offset != 0; --offset)
  {
    const unsigned int c = static_cast<unsigned char>(*p);

    if (c == 0)
      return ustring::npos;

    p += utf8_skip[c];
  }

  return p - str;
}

// Second overload: stop when reaching maxlen.
auto
utf8_byte_offset(const char* str, ustring::size_type offset, const ustring::size_type maxlen) -> ustring::size_type
{
  if (offset == ustring::npos)
    return ustring::npos;

  const char* const utf8_skip = g_utf8_skip;
  const char* const pend = str + maxlen;
  const char* p = str;

  for (; offset != 0; --offset)
  {
    if (p >= pend)
      return ustring::npos;

    p += utf8_skip[static_cast<unsigned char>(*p)];
  }

  return p - str;
}

// Third overload: stop when reaching str.size().
//
inline auto
utf8_byte_offset(const std::string& str, const ustring::size_type offset) -> ustring::size_type
{
  return utf8_byte_offset(str.data(), offset, str.size());
}

// Takes UTF-8 character offset and count in ci and cn.
// Returns the byte offset and count in i and n.
//
struct Utf8SubstrBounds
{
  ustring::size_type i;
  ustring::size_type n;

  Utf8SubstrBounds(const std::string& str, const ustring::size_type ci, const ustring::size_type cn)
  : i(utf8_byte_offset(str, ci)), n(ustring::npos)
  {
    if (i != ustring::npos)
      n = utf8_byte_offset(str.data() + i, cn, str.size() - i);
  }
};

// Converts byte offset to UTF-8 character offset.
inline auto
utf8_char_offset(const std::string& str, const ustring::size_type offset) -> ustring::size_type
{
  if (offset == ustring::npos)
    return ustring::npos;

  const char* const pdata = str.data();
  return g_utf8_pointer_to_offset(pdata, pdata + offset);
}

// Helper to implement ustring::find_first_of() and find_first_not_of().
// Returns the UTF-8 character offset, or ustring::npos if not found.
auto
utf8_find_first_of(const std::string& str, ustring::size_type offset, const char* utf8_match, const long utf8_match_size, const bool find_not_of) -> ustring::size_type
{
  const ustring::size_type byte_offset = utf8_byte_offset(str, offset);
  if (byte_offset == ustring::npos)
    return ustring::npos;

  long ucs4_match_size = 0;
  const auto ucs4_match =
    Glib::make_unique_ptr_gfree(g_utf8_to_ucs4_fast(utf8_match, utf8_match_size, &ucs4_match_size));

  const gunichar* const match_begin = ucs4_match.get();
  const gunichar* const match_end = match_begin + ucs4_match_size;

  const char* const str_begin = str.data();
  const char* const str_end = str_begin + str.size();

  for (const char* pstr = str_begin + byte_offset; pstr < str_end; pstr = g_utf8_next_char(pstr))
  {
    const gunichar* const pfound = std::find(match_begin, match_end, g_utf8_get_char(pstr));

    if (pfound != match_end != find_not_of)
      return offset;

    ++offset;
  }

  return ustring::npos;
}

// Helper to implement ustring::find_last_of() and find_last_not_of().
// Returns the UTF-8 character offset, or ustring::npos if not found.
auto
utf8_find_last_of(const std::string& str, const ustring::size_type offset, const char* utf8_match, const long utf8_match_size, const bool find_not_of) -> ustring::size_type
{
  long ucs4_match_size = 0;
  const auto ucs4_match =
    Glib::make_unique_ptr_gfree(g_utf8_to_ucs4_fast(utf8_match, utf8_match_size, &ucs4_match_size));

  const gunichar* const match_begin = ucs4_match.get();
  const gunichar* const match_end = match_begin + ucs4_match_size;

  const char* const str_begin = str.data();
  const char* pstr = str_begin;

  // Set pstr one byte beyond the actual start position.
  const ustring::size_type byte_offset = utf8_byte_offset(str, offset);
  pstr += byte_offset < str.size() ? byte_offset + 1 : str.size();

  while (pstr > str_begin)
  {
    // Move to previous character.
    do
      --pstr;
    while ((static_cast<unsigned char>(*pstr) & 0xC0u) == 0x80);

    const gunichar* const pfound = std::find(match_begin, match_end, g_utf8_get_char(pstr));

    if (pfound != match_end != find_not_of)
      return g_utf8_pointer_to_offset(str_begin, pstr);
  }

  return ustring::npos;
}

} // anonymous namespace

namespace Glib
{

#ifndef GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS
// Initialize static member here,
// because the compiler did not allow us do it inline.
const ustring::size_type ustring::npos = std::string::npos;
#endif

/*
 * We need our own version of g_utf8_get_char(), because the std::string
 * iterator is not necessarily a plain pointer (it's in fact not in GCC's
 * libstdc++-v3).  Copying the UTF-8 data into a temporary buffer isn't an
 * option since this operation is quite time critical.  The implementation
 * is quite different from g_utf8_get_char() -- both more generic and likely
 * faster.
 *
 * By looking at the first byte of a UTF-8 character one can determine the
 * number of bytes used.  GLib offers the g_utf8_skip[] array for this purpose,
 * but accessing this global variable would, on IA32 at least, introduce
 * a function call to fetch the Global Offset Table, plus two levels of
 * indirection in order to read the value.  Even worse, fetching the GOT is
 * always done right at the start of the function instead of the branch that
 * actually uses the variable.
 *
 * Fortunately, there's a better way to get the byte count.  As this table
 * shows, there's a nice regular pattern in the UTF-8 encoding scheme:
 *
 * 0x00000000 - 0x0000007F: 0xxxxxxx
 * 0x00000080 - 0x000007FF: 110xxxxx 10xxxxxx
 * 0x00000800 - 0x0000FFFF: 1110xxxx 10xxxxxx 10xxxxxx
 * 0x00010000 - 0x001FFFFF: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 0x00200000 - 0x03FFFFFF: 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 0x04000000 - 0x7FFFFFFF: 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 * Except for the single byte case, the number of leading 1-bits equals the
 * byte count.  All that is needed is to shift the first byte to the left
 * until bit 7 becomes 0.  Naturally, doing so requires a loop -- but since
 * we already have one, no additional cost is introduced.  This shifting can
 * further be combined with the computation of the bitmask needed to eliminate
 * the leading length bits, thus saving yet another register.
 *
 * Note:  If you change this code, it is advisable to also review what the
 * compiler makes of it in the assembler output.  Except for some pointless
 * register moves, the generated code is sufficiently close to the optimum
 * with GCC 4.1.2 on x86_64.
 */
auto
get_unichar_from_std_iterator(std::string::const_iterator pos) -> gunichar
{
  unsigned int result = static_cast<unsigned char>(*pos);

  if ((result & 0x80) != 0)
  {
    unsigned int mask = 0x40;

    do
    {
      result <<= 6;
      const unsigned int c = static_cast<unsigned char>(*++pos);
      mask <<= 5;
      result += c - 0x80;
    } while ((result & mask) != 0);

    result &= mask - 1;
  }

  return result;
}

/**** Glib::ustring ********************************************************/

ustring::ustring() : string_()
{
}

ustring::ustring(const ustring& other) = default;

ustring::ustring(ustring&& other) : string_(std::move(other.string_))
{
}

ustring::ustring(const ustring& src, const size_type i, const size_type n) : string_()
{
  const Utf8SubstrBounds bounds(src.string_, i, n);
  string_.assign(src.string_, bounds.i, bounds.n);
}

ustring::ustring(const char* src, const size_type n) : string_(src, utf8_byte_offset(src, n))
{
}

ustring::ustring(const char* src) : string_(src)
{
}

ustring::ustring(size_type n, const gunichar uc) : string_()
{
  if (uc < 0x80)
  {
    // Optimize the probably most common case.
    string_.assign(n, static_cast<char>(uc));
  }
  else
  {
    const UnicharToUtf8 conv(uc);
    string_.reserve(n * conv.len);

    for (; n > 0; --n)
      string_.append(conv.buf, conv.len);
  }
}

ustring::ustring(const size_type n, const char c) : string_(n, c)
{
}

ustring::ustring(const std::string& src) : string_(src)
{
}

ustring::ustring(std::string&& src) : string_(std::move(src))
{
}

ustring::~ustring() noexcept = default;

auto ustring::swap (ustring &other) -> void
{
  string_.swap(other.string_);
}

/**** Glib::ustring::operator=() *******************************************/

auto
ustring::operator=(const ustring& other) -> ustring& = default;

auto
ustring::operator=(ustring&& other) -> ustring&
{
  string_ = std::move(other.string_);
  return *this;
}

auto
ustring::operator=(const std::string& src) -> ustring&
{
  string_ = src;
  return *this;
}

auto
ustring::operator=(std::string&& src) -> ustring&
{
  string_ = std::move(src);
  return *this;
}

auto
ustring::operator=(const char* src) -> ustring&
{
  string_ = src;
  return *this;
}

auto
ustring::operator=(
  const gunichar uc) -> ustring&
{
  const UnicharToUtf8 conv(uc);
  string_.assign(conv.buf, conv.len);
  return *this;
}

auto
ustring::operator=(
  const char c) -> ustring&
{
  string_ = c;
  return *this;
}

/**** Glib::ustring::assign() **********************************************/

auto
ustring::assign(const ustring& src) -> ustring&
{
  string_ = src.string_;
  return *this;
}

auto
ustring::assign(ustring&& src) -> ustring&
{
  string_ = std::move(src.string_);
  return *this;
}

auto
ustring::assign(const ustring& src, const size_type i, const size_type n) -> ustring&
{
  const Utf8SubstrBounds bounds(src.string_, i, n);
  string_.assign(src.string_, bounds.i, bounds.n);
  return *this;
}

auto
ustring::assign(const char* src, const size_type n) -> ustring&
{
  string_.assign(src, utf8_byte_offset(src, n));
  return *this;
}

auto
ustring::assign(const char* src) -> ustring&
{
  string_ = src;
  return *this;
}

auto
ustring::assign(
  const size_type n, const gunichar uc) -> ustring&
{
  ustring temp(n, uc);
  string_.swap(temp.string_);
  return *this;
}

auto
ustring::assign(
  const size_type n, const char c) -> ustring&
{
  string_.assign(n, c);
  return *this;
}

/**** Glib::ustring::operator+=() ******************************************/

auto
ustring::operator+=(const ustring& src) -> ustring&
{
  string_ += src.string_;
  return *this;
}

auto
ustring::operator+=(const char* src) -> ustring&
{
  string_ += src;
  return *this;
}

auto
ustring::operator+=(
  const gunichar uc) -> ustring&
{
  const UnicharToUtf8 conv(uc);
  string_.append(conv.buf, conv.len);
  return *this;
}

auto
ustring::operator+=(
  const char c) -> ustring&
{
  string_ += c;
  return *this;
}

/**** Glib::ustring::push_back() *******************************************/

auto ustring::push_back (
  const gunichar uc) -> void
{
  const UnicharToUtf8 conv(uc);
  string_.append(conv.buf, conv.len);
}

auto ustring::push_back (
  const char c) -> void
{
  string_ += c;
}

/**** Glib::ustring::append() **********************************************/

auto
ustring::append(const ustring& src) -> ustring&
{
  string_ += src.string_;
  return *this;
}

auto
ustring::append(const ustring& src, const size_type i, const size_type n) -> ustring&
{
  const Utf8SubstrBounds bounds(src.string_, i, n);
  string_.append(src.string_, bounds.i, bounds.n);
  return *this;
}

auto
ustring::append(const char* src, const size_type n) -> ustring&
{
  string_.append(src, utf8_byte_offset(src, n));
  return *this;
}

auto
ustring::append(const char* src) -> ustring&
{
  string_ += src;
  return *this;
}

auto
ustring::append(
  const size_type n, const gunichar uc) -> ustring&
{
  string_.append(ustring(n, uc).string_);
  return *this;
}

auto
ustring::append(
  const size_type n, const char c) -> ustring&
{
  string_.append(n, c);
  return *this;
}

/**** Glib::ustring::insert() **********************************************/

auto
ustring::insert(
  const size_type i, const ustring& src) -> ustring&
{
  string_.insert(utf8_byte_offset(string_, i), src.string_);
  return *this;
}

auto
ustring::insert(
  const size_type i, const ustring& src, const size_type i2, const size_type n) -> ustring&
{
  const Utf8SubstrBounds bounds2(src.string_, i2, n);
  string_.insert(utf8_byte_offset(string_, i), src.string_, bounds2.i, bounds2.n);
  return *this;
}

auto
ustring::insert(
  const size_type i, const char* src, const size_type n) -> ustring&
{
  string_.insert(utf8_byte_offset(string_, i), src, utf8_byte_offset(src, n));
  return *this;
}

auto
ustring::insert(
  const size_type i, const char* src) -> ustring&
{
  string_.insert(utf8_byte_offset(string_, i), src);
  return *this;
}

auto
ustring::insert(
  const size_type i, const size_type n, const gunichar uc) -> ustring&
{
  string_.insert(utf8_byte_offset(string_, i), ustring(n, uc).string_);
  return *this;
}

auto
ustring::insert(
  const size_type i, const size_type n, const char c) -> ustring&
{
  string_.insert(utf8_byte_offset(string_, i), n, c);
  return *this;
}

auto
ustring::insert(
  const iterator p, const gunichar uc) -> iterator
{
  const size_type offset = p.base() - string_.begin();
  const UnicharToUtf8 conv(uc);
  string_.insert(offset, conv.buf, conv.len);
  return iterator(string_.begin() + offset);
}

auto
ustring::insert(
  const iterator p, const char c) -> iterator
{
  return iterator(string_.insert(p.base(), c));
}

auto ustring::insert (
  const iterator p, const size_type n, const gunichar uc) -> void
{
  string_.insert(p.base() - string_.begin(), ustring(n, uc).string_);
}

auto ustring::insert (
  const iterator p, const size_type n, const char c) -> void
{
  string_.insert(p.base(), n, c);
}

/**** Glib::ustring::replace() *********************************************/

auto
ustring::replace(
  const size_type i, const size_type n, const ustring& src) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.replace(bounds.i, bounds.n, src.string_);
  return *this;
}

auto
ustring::replace(
  const size_type i, const size_type n, const ustring& src, const size_type i2, const size_type n2) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  const Utf8SubstrBounds bounds2(src.string_, i2, n2);
  string_.replace(bounds.i, bounds.n, src.string_, bounds2.i, bounds2.n);
  return *this;
}

auto
ustring::replace(
  const size_type i, const size_type n, const char* src, const size_type n2) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.replace(bounds.i, bounds.n, src, utf8_byte_offset(src, n2));
  return *this;
}

auto
ustring::replace(
  const size_type i, const size_type n, const char* src) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.replace(bounds.i, bounds.n, src);
  return *this;
}

auto
ustring::replace(
  const size_type i, const size_type n, const size_type n2, const gunichar uc) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.replace(bounds.i, bounds.n, ustring(n2, uc).string_);
  return *this;
}

auto
ustring::replace(
  const size_type i, const size_type n, const size_type n2, const char c) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.replace(bounds.i, bounds.n, n2, c);
  return *this;
}

auto
ustring::replace(
  const iterator pbegin, const iterator pend, const ustring& src) -> ustring&
{
  string_.replace(pbegin.base(), pend.base(), src.string_);
  return *this;
}

auto
ustring::replace(
  const iterator pbegin, const iterator pend, const char* src, const size_type n) -> ustring&
{
  string_.replace(pbegin.base(), pend.base(), src, utf8_byte_offset(src, n));
  return *this;
}

auto
ustring::replace(
  const iterator pbegin, const iterator pend, const char* src) -> ustring&
{
  string_.replace(pbegin.base(), pend.base(), src);
  return *this;
}

auto
ustring::replace(
  const iterator pbegin, const iterator pend, const size_type n, const gunichar uc) -> ustring&
{
  string_.replace(pbegin.base(), pend.base(), ustring(n, uc).string_);
  return *this;
}

auto
ustring::replace(
  const iterator pbegin, const iterator pend, const size_type n, const char c) -> ustring&
{
  string_.replace(pbegin.base(), pend.base(), n, c);
  return *this;
}

/**** Glib::ustring::erase() ***********************************************/

auto ustring::clear () -> void
{
  string_.erase();
}

auto
ustring::erase(
  const size_type i, const size_type n) -> ustring&
{
  const Utf8SubstrBounds bounds(string_, i, n);
  string_.erase(bounds.i, bounds.n);
  return *this;
}

auto
ustring::erase() -> ustring&
{
  string_.erase();
  return *this;
}

auto
ustring::erase(
  const iterator p) -> iterator
{
  iterator iter_end = p;
  ++iter_end;

  return iterator(string_.erase(p.base(), iter_end.base()));
}

auto
ustring::erase(
  const iterator pbegin, const iterator pend) -> iterator
{
  return iterator(string_.erase(pbegin.base(), pend.base()));
}

/**** Glib::ustring::compare() *********************************************/

auto
ustring::compare(
  const UStringView rhs) const -> int
{
  return g_utf8_collate(string_.c_str(), rhs.c_str());
}

auto
ustring::compare(
  const size_type i, const size_type n, const UStringView rhs) const -> int
{
  return ustring(*this, i, n).compare(rhs.c_str());
}

auto
ustring::compare(
  const size_type i, const size_type n, const ustring& rhs, const size_type i2, const size_type n2) const -> int
{
  return ustring(*this, i, n).compare(ustring(rhs, i2, n2));
}

auto
ustring::compare(
  const size_type i, const size_type n, const char* rhs, const size_type n2) const -> int
{
  return ustring(*this, i, n).compare(ustring(rhs, n2));
}

/**** Glib::ustring -- index access ****************************************/

auto ustring::operator[](
  const size_type i) const -> value_type
{
  return g_utf8_get_char(g_utf8_offset_to_pointer(string_.data(), i));
}

auto
ustring::at(
  const size_type i) const -> value_type
{
  const size_type byte_offset = utf8_byte_offset(string_, i);

  // Throws std::out_of_range if the index is invalid.
  return g_utf8_get_char(&string_.at(byte_offset));
}

/**** Glib::ustring -- iterator access *************************************/

auto
ustring::begin() -> iterator
{
  return iterator(string_.begin());
}

auto
ustring::end() -> iterator
{
  return iterator(string_.end());
}

auto
ustring::begin() const -> const_iterator
{
  return const_iterator(string_.begin());
}

auto
ustring::end() const -> const_iterator
{
  return const_iterator(string_.end());
}

auto
ustring::rbegin() -> reverse_iterator
{
  return reverse_iterator(iterator(string_.end()));
}

auto
ustring::rend() -> reverse_iterator
{
  return reverse_iterator(iterator(string_.begin()));
}

auto
ustring::rbegin() const -> const_reverse_iterator
{
  return const_reverse_iterator(const_iterator(string_.end()));
}

auto
ustring::rend() const -> const_reverse_iterator
{
  return const_reverse_iterator(const_iterator(string_.begin()));
}

auto
ustring::cbegin() const -> const_iterator
{
  return const_iterator(string_.begin());
}

auto
ustring::cend() const -> const_iterator
{
  return const_iterator(string_.end());
}

/**** Glib::ustring::find() ************************************************/

auto
ustring::find(const ustring& str, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.find(str.string_, utf8_byte_offset(string_, i)));
}

auto
ustring::find(const char* str, const size_type i, const size_type n) const -> size_type
{
  return utf8_char_offset(
    string_, string_.find(str, utf8_byte_offset(string_, i), utf8_byte_offset(str, n)));
}

auto
ustring::find(const char* str, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.find(str, utf8_byte_offset(string_, i)));
}

auto
ustring::find(
  const gunichar uc, const size_type i) const -> size_type
{
  const UnicharToUtf8 conv(uc);
  return utf8_char_offset(string_, string_.find(conv.buf, utf8_byte_offset(string_, i), conv.len));
}

auto
ustring::find(
  const char c, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.find(c, utf8_byte_offset(string_, i)));
}

/**** Glib::ustring::rfind() ***********************************************/

auto
ustring::rfind(const ustring& str, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.rfind(str.string_, utf8_byte_offset(string_, i)));
}

auto
ustring::rfind(const char* str, const size_type i, const size_type n) const -> size_type
{
  return utf8_char_offset(
    string_, string_.rfind(str, utf8_byte_offset(string_, i), utf8_byte_offset(str, n)));
}

auto
ustring::rfind(const char* str, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.rfind(str, utf8_byte_offset(string_, i)));
}

auto
ustring::rfind(
  const gunichar uc, const size_type i) const -> size_type
{
  const UnicharToUtf8 conv(uc);
  return utf8_char_offset(string_, string_.rfind(conv.buf, utf8_byte_offset(string_, i), conv.len));
}

auto
ustring::rfind(
  const char c, const size_type i) const -> size_type
{
  return utf8_char_offset(string_, string_.rfind(c, utf8_byte_offset(string_, i)));
}

/**** Glib::ustring::find_first_of() ***************************************/

auto
ustring::find_first_of(const ustring& match, const size_type i) const -> size_type
{
  return utf8_find_first_of(string_, i, match.string_.data(), match.string_.size(), false);
}

auto
ustring::find_first_of(const char* match, const size_type i, const size_type n) const -> size_type
{
  return utf8_find_first_of(string_, i, match, n, false);
}

auto
ustring::find_first_of(const char* match, const size_type i) const -> size_type
{
  return utf8_find_first_of(string_, i, match, -1, false);
}

auto
ustring::find_first_of(
  const gunichar uc, const size_type i) const -> size_type
{
  return find(uc, i);
}

auto
ustring::find_first_of(
  const char c, const size_type i) const -> size_type
{
  return find(c, i);
}

/**** Glib::ustring::find_last_of() ****************************************/

auto
ustring::find_last_of(const ustring& match, const size_type i) const -> size_type
{
  return utf8_find_last_of(string_, i, match.string_.data(), match.string_.size(), false);
}

auto
ustring::find_last_of(const char* match, const size_type i, const size_type n) const -> size_type
{
  return utf8_find_last_of(string_, i, match, n, false);
}

auto
ustring::find_last_of(const char* match, const size_type i) const -> size_type
{
  return utf8_find_last_of(string_, i, match, -1, false);
}

auto
ustring::find_last_of(
  const gunichar uc, const size_type i) const -> size_type
{
  return rfind(uc, i);
}

auto
ustring::find_last_of(
  const char c, const size_type i) const -> size_type
{
  return rfind(c, i);
}

/**** Glib::ustring::find_first_not_of() ***********************************/

auto
ustring::find_first_not_of(const ustring& match, const size_type i) const -> size_type
{
  return utf8_find_first_of(string_, i, match.string_.data(), match.string_.size(), true);
}

auto
ustring::find_first_not_of(const char* match, const size_type i, const size_type n) const -> size_type
{
  return utf8_find_first_of(string_, i, match, n, true);
}

auto
ustring::find_first_not_of(const char* match, const size_type i) const -> size_type
{
  return utf8_find_first_of(string_, i, match, -1, true);
}

// Unfortunately, all of the find_*_not_of() methods for single
// characters need their own special implementation.
//
auto
ustring::find_first_not_of(
  const gunichar uc, size_type i) const -> size_type
{
  const size_type bi = utf8_byte_offset(string_, i);
  if (bi != npos)
  {
    const char* const pbegin = string_.data();
    const char* const pend = pbegin + string_.size();

    for (const char *p = pbegin + bi; p < pend; p = g_utf8_next_char(p), ++i)
    {
      if (g_utf8_get_char(p) != uc)
        return i;
    }
  }
  return npos;
}

auto
ustring::find_first_not_of(
  const char c, size_type i) const -> size_type
{
  const size_type bi = utf8_byte_offset(string_, i);
  if (bi != npos)
  {
    const char* const pbegin = string_.data();
    const char* const pend = pbegin + string_.size();

    for (const char *p = pbegin + bi; p < pend; p = g_utf8_next_char(p), ++i)
    {
      if (*p != c)
        return i;
    }
  }
  return npos;
}

/**** Glib::ustring::find_last_not_of() ************************************/

auto
ustring::find_last_not_of(const ustring& match, const size_type i) const -> size_type
{
  return utf8_find_last_of(string_, i, match.string_.data(), match.string_.size(), true);
}

auto
ustring::find_last_not_of(const char* match, const size_type i, const size_type n) const -> size_type
{
  return utf8_find_last_of(string_, i, match, n, true);
}

auto
ustring::find_last_not_of(const char* match, const size_type i) const -> size_type
{
  return utf8_find_last_of(string_, i, match, -1, true);
}

// Unfortunately, all of the find_*_not_of() methods for single
// characters need their own special implementation.
//
auto
ustring::find_last_not_of(
  const gunichar uc, const size_type i) const -> size_type
{
  const char* const pbegin = string_.data();
  const char* const pend = pbegin + string_.size();
  size_type i_cur = 0;
  size_type i_found = npos;

  for (const char *p = pbegin; p < pend && i_cur <= i; p = g_utf8_next_char(p), ++i_cur)
  {
    if (g_utf8_get_char(p) != uc)
      i_found = i_cur;
  }
  return i_found;
}

auto
ustring::find_last_not_of(
  const char c, const size_type i) const -> size_type
{
  const char* const pbegin = string_.data();
  const char* const pend = pbegin + string_.size();
  size_type i_cur = 0;
  size_type i_found = npos;

  for (const char *p = pbegin; p < pend && i_cur <= i; p = g_utf8_next_char(p), ++i_cur)
  {
    if (*p != c)
      i_found = i_cur;
  }
  return i_found;
}

/**** Glib::ustring -- get size and resize *********************************/

auto
ustring::empty() const -> bool
{
  return string_.empty();
}

auto
ustring::size() const -> size_type
{
  const char* const pdata = string_.data();
  return g_utf8_pointer_to_offset(pdata, pdata + string_.size());
}

auto
ustring::length() const -> size_type
{
  const char* const pdata = string_.data();
  return g_utf8_pointer_to_offset(pdata, pdata + string_.size());
}

auto
ustring::bytes() const -> size_type
{
  return string_.size();
}

auto
ustring::capacity() const -> size_type
{
  return string_.capacity();
}

auto
ustring::max_size() const -> size_type
{
  return string_.max_size();
}

auto ustring::resize (
  const size_type n, const gunichar uc) -> void
{
  const size_type size_now = size();
  if (n < size_now)
    erase(n, npos);
  else if (n > size_now)
    append(n - size_now, uc);
}

auto ustring::resize (
  const size_type n, const char c) -> void
{
  const size_type size_now = size();
  if (n < size_now)
    erase(n, npos);
  else if (n > size_now)
    string_.append(n - size_now, c);
}

auto ustring::reserve (
  const size_type n) -> void
{
  string_.reserve(n);
}

/**** Glib::ustring -- C string access *************************************/

auto
ustring::data() const -> const char*
{
  return string_.data();
}

auto
ustring::c_str() const -> const char*
{
  return string_.c_str();
}

// Note that copy() requests UTF-8 character offsets as
// parameters, but returns the number of copied bytes.
//
auto
ustring::copy(char* dest, const size_type n, const size_type i) const -> size_type
{
  const Utf8SubstrBounds bounds(string_, i, n);
  return string_.copy(dest, bounds.n, bounds.i);
}

/**** Glib::ustring -- UTF-8 utilities *************************************/

auto
ustring::validate() const -> bool
{
  return g_utf8_validate(string_.data(), string_.size(), nullptr) != 0;
}

auto
ustring::validate(
  iterator & first_invalid) -> bool
{
  const char* const pdata = string_.data();
  const char* valid_end = pdata;
  const int is_valid = g_utf8_validate(pdata, string_.size(), &valid_end);

  first_invalid = iterator(string_.begin() + (valid_end - pdata));
  return is_valid != 0;
}

auto
ustring::validate(
  const_iterator & first_invalid) const -> bool
{
  const char* const pdata = string_.data();
  const char* valid_end = pdata;
  const int is_valid = g_utf8_validate(pdata, string_.size(), &valid_end);

  first_invalid = const_iterator(string_.begin() + (valid_end - pdata));
  return is_valid != 0;
}

auto
ustring::make_valid() const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_utf8_make_valid(string_.data(), string_.size()));
}

auto
ustring::is_ascii() const -> bool
{
  const char* p = string_.data();
  const char* const pend = p + string_.size();

  for (; p != pend; ++p)
  {
    if ((static_cast<unsigned char>(*p) & 0x80u) != 0)
      return false;
  }

  return true;
}

auto
ustring::normalize(NormalizeMode mode) const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(
    g_utf8_normalize(string_.data(), string_.size(), static_cast<GNormalizeMode>(int(mode))));
}

auto
ustring::uppercase() const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_utf8_strup(string_.data(), string_.size()));
}

auto
ustring::lowercase() const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_utf8_strdown(string_.data(), string_.size()));
}

auto
ustring::casefold() const -> ustring
{
  return convert_return_gchar_ptr_to_ustring(g_utf8_casefold(string_.data(), string_.size()));
}

auto
ustring::collate_key() const -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_utf8_collate_key(string_.data(), string_.size()));
}

auto
ustring::casefold_collate_key() const -> std::string
{
  char* const casefold_buf = g_utf8_casefold(string_.data(), string_.size());
  char* const key_buf = g_utf8_collate_key(casefold_buf, -1);
  g_free(casefold_buf);
  return std::string(make_unique_ptr_gfree(key_buf).get());
}

/**** Glib::ustring -- Message formatting **********************************/

// static
auto
ustring::compose_private(const ustring & fmt, std::initializer_list<const ustring*> const ilist) -> ustring
{
  std::string::size_type result_size = fmt.raw().size();

  // Guesstimate the final string size.
  for (auto const it: ilist)
    result_size += it->raw().size();

  std::string result;
  result.reserve(result_size);

  const char* const pfmt = fmt.raw().c_str();
  const char* start = pfmt;

  while (const char* const stop = std::strchr(start, '%'))
  {
    if (stop[1] == '%')
    {
      result.append(start, stop - start + 1);
      start = stop + 2;
    }
    else
    {
      const int index = Ascii::digit_value(stop[1]) - 1;
      const int size = ilist.size();

      if (index >= 0 && index < size)
      {
        result.append(start, stop - start);
        result += (*(ilist.begin() + index))->raw();
        start = stop + 2;
      }
      else
      {
        const char* const next = stop[1] != '\0' ? g_utf8_next_char(stop + 1) : stop + 1;

        // Copy invalid substitutions literally to the output.
        result.append(start, next - start);

        g_warning("invalid substitution \"%s\" in fmt string \"%s\"",
          result.c_str() + result.size() - (next - stop), pfmt);
        start = next;
      }
    }
  }

  result.append(start, pfmt + fmt.raw().size() - start);

  return result;
}

/**** Glib::ustring::SequenceToString **************************************/

ustring::SequenceToString<ustring::iterator, gunichar>::SequenceToString(const ustring::iterator pbegin, const ustring::iterator pend)
: std::string(pbegin.base(), pend.base())
{
}

ustring::SequenceToString<ustring::const_iterator, gunichar>::SequenceToString(const ustring::const_iterator pbegin, const ustring::const_iterator pend)
: std::string(pbegin.base(), pend.base())
{
}

/**** Glib::ustring::FormatStream ******************************************/

ustring::FormatStream::FormatStream() : stream_()
{
}

ustring::FormatStream::~FormatStream() noexcept = default;

auto
ustring::FormatStream::to_string() const -> ustring
{
  GError* error = nullptr;

#ifdef GLIBMM_HAVE_WIDE_STREAM
  const std::wstring str = stream_.str();

#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
  // Avoid going through iconv if wchar_t always contains UCS-4.
  glong n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
    reinterpret_cast<const gunichar*>(str.data()), str.size(), nullptr, &n_bytes, &error));
#elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2
  // Avoid going through iconv if wchar_t always contains UTF-16.
  glong n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_utf16_to_utf8(
    reinterpret_cast<const gunichar2*>(str.data()), str.size(), nullptr, &n_bytes, &error));
#else
  gsize n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_convert(reinterpret_cast<const char*>(str.data()),
    str.size() * sizeof(std::wstring::value_type), "UTF-8", "WCHAR_T", nullptr, &n_bytes, &error));
#endif /* !(__STDC_ISO_10646__ || G_OS_WIN32) */

#else /* !GLIBMM_HAVE_WIDE_STREAM */
  const std::string str = stream_.str();

  gsize n_bytes = 0;
  const auto buf =
    make_unique_ptr_gfree(g_locale_to_utf8(str.data(), str.size(), 0, &n_bytes, &error));
#endif /* !GLIBMM_HAVE_WIDE_STREAM */

  if (error)
  {
    Error::throw_exception(error);
  }

  return {buf.get(), buf.get() + n_bytes};
}

/**** Glib::ustring -- stream I/O operators ********************************/

auto
operator>>(std::istream& is, ustring & utf8_string) -> std::istream&
{
  std::string str;
  is >> str;

  GError* error = nullptr;
  gsize n_bytes = 0;
  const auto buf =
    make_unique_ptr_gfree(g_locale_to_utf8(str.data(), str.size(), nullptr, &n_bytes, &error));

  if (error)
  {
    Error::throw_exception(error);
  }

  utf8_string.assign(buf.get(), buf.get() + n_bytes);

  return is;
}

auto
operator<<(std::ostream& os, const ustring & utf8_string) -> std::ostream&
{
  GError* error = nullptr;
  const auto buf = make_unique_ptr_gfree(g_locale_from_utf8(
    utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
  if (error)
  {
    Error::throw_exception(error);
  }

  // This won't work if the string contains NUL characters.  Unfortunately,
  // std::ostream::write() ignores format flags, so we cannot use that.
  // The only option would be to create a temporary std::string.  However,
  // even then GCC's libstdc++-v3 prints only the characters up to the first
  // NUL.  Given this, there doesn't seem much of a point in allowing NUL in
  // formatted output.  The semantics would be unclear anyway: what's the
  // screen width of a NUL?
  os << buf.get();

  return os;
}

#ifdef GLIBMM_HAVE_WIDE_STREAM

auto
operator>>(std::wistream& is, ustring& utf8_string) -> std::wistream&
{
  GError* error = nullptr;

  std::wstring wstr;
  is >> wstr;

#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
  // Avoid going through iconv if wchar_t always contains UCS-4.
  glong n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_ucs4_to_utf8(
    reinterpret_cast<const gunichar*>(wstr.data()), wstr.size(), nullptr, &n_bytes, &error));
#elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2
  // Avoid going through iconv if wchar_t always contains UTF-16.
  glong n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_utf16_to_utf8(
    reinterpret_cast<const gunichar2*>(wstr.data()), wstr.size(), nullptr, &n_bytes, &error));
#else
  gsize n_bytes = 0;
  const auto buf = make_unique_ptr_gfree(g_convert(reinterpret_cast<const char*>(wstr.data()),
    wstr.size() * sizeof(std::wstring::value_type), "UTF-8", "WCHAR_T", nullptr, &n_bytes, &error));
#endif // !(__STDC_ISO_10646__ || G_OS_WIN32)

  if (error)
  {
    Error::throw_exception(error);
  }

  utf8_string.assign(buf.get(), buf.get() + n_bytes);

  return is;
}

auto
operator<<(std::wostream& os, const ustring& utf8_string) -> std::wostream&
{
  GError* error = nullptr;

#if (defined(__STDC_ISO_10646__) || defined(_LIBCPP_VERSION)) && SIZEOF_WCHAR_T == 4
  // Avoid going through iconv if wchar_t always contains UCS-4.
  const auto buf = make_unique_ptr_gfree(
    g_utf8_to_ucs4(utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
#elif defined(G_OS_WIN32) && SIZEOF_WCHAR_T == 2
  // Avoid going through iconv if wchar_t always contains UTF-16.
  const auto buf = make_unique_ptr_gfree(
    g_utf8_to_utf16(utf8_string.raw().data(), utf8_string.raw().size(), nullptr, nullptr, &error));
#else
  const auto buf = make_unique_ptr_gfree(g_convert(utf8_string.raw().data(),
    utf8_string.raw().size(), "WCHAR_T", "UTF-8", nullptr, nullptr, &error));
#endif // !(__STDC_ISO_10646__ || G_OS_WIN32)

  if (error)
  {
    Error::throw_exception(error);
  }

  // This won't work if the string contains NUL characters.  Unfortunately,
  // std::wostream::write() ignores format flags, so we cannot use that.
  // The only option would be to create a temporary std::wstring.  However,
  // even then GCC's libstdc++-v3 prints only the characters up to the first
  // NUL.  Given this, there doesn't seem much of a point in allowing NUL in
  // formatted output.  The semantics would be unclear anyway: what's the
  // screen width of a NUL?
  os << reinterpret_cast<wchar_t*>(buf.get());

  return os;
}

#endif /* GLIBMM_HAVE_WIDE_STREAM */

} // namespace Glib
