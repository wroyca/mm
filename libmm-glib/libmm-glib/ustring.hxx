// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_USTRING_H
#define _GLIBMM_USTRING_H

#include <glib.h>
#include <libmm-glib/mm-glibconfig.hxx>
#include <libmm-glib/unicode.hxx>

#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <iterator>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

#if defined(_MSC_VER) && _MSC_VER >= 1600 && \
    !defined(GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS)
const std::basic_string<char>::size_type std::basic_string<char>::npos =
    (std::basic_string<char>::size_type) - 1;
#endif

namespace Glib
{

  class ustring;

  class GLIBMM_API StdStringView
  {
  public:
    StdStringView (const std::string& s)
      : pstring_ (s.c_str ())
    {
    }

    StdStringView (const char* s)
      : pstring_ (s)
    {
    }

    auto
    c_str () const -> const char*
    {
      return pstring_;
    }

  private:
    const char* pstring_;
  };

  class GLIBMM_API UStringView
  {
  public:
    inline UStringView (const Glib::ustring& s);

    UStringView (const char* s)
      : pstring_ (s)
    {
    }

    auto
    c_str () const -> const char*
    {
      return pstring_;
    }

  private:
    const char* pstring_;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  #ifndef GLIBMM_HAVE_STD_ITERATOR_TRAITS

  template <class T>
  struct IteratorTraits
  {
    using iterator_category = typename T::iterator_category;
    using value_type = typename T::value_type;
    using difference_type = typename T::difference_type;
    using pointer = typename T::pointer;
    using reference = typename T::reference;
  };

  template <class T>
  struct IteratorTraits<T*>
  {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;
  };

  template <class T>
  struct IteratorTraits<const T*>
  {
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;
  };

  #endif
#endif

  template <class T>
  class ustring_Iterator
  {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = gunichar;
    using difference_type = std::string::difference_type;
    using reference = value_type;
    using pointer = void;

    inline ustring_Iterator ();
    inline ustring_Iterator (
        const ustring_Iterator<std::string::iterator>& other);
    auto
    operator= (const ustring_Iterator& other) -> ustring_Iterator& = default;

    inline auto
    operator* () const -> value_type;

    inline auto
    operator++ () -> ustring_Iterator<T>&;
    inline auto
    operator++ (int) -> const ustring_Iterator<T>;
    inline auto
    operator-- () -> ustring_Iterator<T>&;
    inline auto
    operator-- (int) -> const ustring_Iterator<T>;

    explicit inline ustring_Iterator (T pos);
    inline auto
    base () const -> T;

  private:
    T pos_;
  };

  GLIBMM_API
  auto
  get_unichar_from_std_iterator (std::string::const_iterator pos) -> gunichar G_GNUC_PURE;

  class ustring
  {
  public:
    using size_type = std::string::size_type;
    using difference_type = std::string::difference_type;

    using value_type = gunichar;
    using reference = gunichar&;
    using const_reference = const gunichar&;

    using iterator = ustring_Iterator<std::string::iterator>;
    using const_iterator = ustring_Iterator<std::string::const_iterator>;

#ifndef GLIBMM_HAVE_SUN_REVERSE_ITERATOR

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

#else

    typedef std::reverse_iterator<iterator,
                                  iterator::iterator_category,
                                  iterator::value_type,
                                  iterator::reference,
                                  iterator::pointer,
                                  iterator::difference_type>
        reverse_iterator;
    typedef std::reverse_iterator<const_iterator,
                                  const_iterator::iterator_category,
                                  const_iterator::value_type,
                                  const_iterator::reference,
                                  const_iterator::pointer,
                                  const_iterator::difference_type>
        const_reverse_iterator;

#endif

#ifdef GLIBMM_HAVE_ALLOWS_STATIC_INLINE_NPOS
    GLIBMM_API static const size_type npos = std::string::npos;
#else

    GLIBMM_API static const size_type npos;
#endif

    GLIBMM_API
    ustring ();

    GLIBMM_API ~ustring () noexcept;

    GLIBMM_API
    ustring (const ustring& other);

    GLIBMM_API
    ustring (ustring&& other);

    GLIBMM_API auto
    operator= (const ustring& other) -> ustring&;

    GLIBMM_API auto
    operator= (ustring&& other) -> ustring&;

    GLIBMM_API auto
    swap (ustring& other) -> void;

    GLIBMM_API
    ustring (const std::string& src);

    GLIBMM_API
    ustring (std::string&& src);

    GLIBMM_API
    ustring (const ustring& src, size_type i, size_type n = npos);

    GLIBMM_API
    ustring (const char* src, size_type n);

    GLIBMM_API
    ustring (const char* src);

    GLIBMM_API
    ustring (size_type n, gunichar uc);

    GLIBMM_API
    ustring (size_type n, char c);

    template <class In>
    ustring (In pbegin, In pend);

    GLIBMM_API auto
    operator= (const std::string& src) -> ustring&;
    GLIBMM_API auto
    operator= (std::string&& src) -> ustring&;
    GLIBMM_API auto
    operator= (const char* src) -> ustring&;
    GLIBMM_API auto
    operator= (gunichar uc) -> ustring&;
    GLIBMM_API auto
    operator= (char c) -> ustring&;

    GLIBMM_API auto
    assign (const ustring& src) -> ustring&;
    GLIBMM_API auto
    assign (ustring&& src) -> ustring&;
    GLIBMM_API auto
    assign (const ustring& src, size_type i, size_type n) -> ustring&;
    GLIBMM_API auto
    assign (const char* src, size_type n) -> ustring&;
    GLIBMM_API auto
    assign (const char* src) -> ustring&;
    GLIBMM_API auto
    assign (size_type n, gunichar uc) -> ustring&;
    GLIBMM_API auto
    assign (size_type n, char c) -> ustring&;
    template <class In>
    auto
    assign (In pbegin, In pend) -> ustring&;

    GLIBMM_API auto
    operator+= (const ustring& src) -> ustring&;
    GLIBMM_API auto
    operator+= (const char* src) -> ustring&;
    GLIBMM_API auto
    operator+= (gunichar uc) -> ustring&;
    GLIBMM_API auto
    operator+= (char c) -> ustring&;
    GLIBMM_API auto
    push_back (gunichar uc) -> void;
    GLIBMM_API auto
    push_back (char c) -> void;

    GLIBMM_API auto
    append (const ustring& src) -> ustring&;
    GLIBMM_API auto
    append (const ustring& src, size_type i, size_type n) -> ustring&;
    GLIBMM_API auto
    append (const char* src, size_type n) -> ustring&;
    GLIBMM_API auto
    append (const char* src) -> ustring&;
    GLIBMM_API auto
    append (size_type n, gunichar uc) -> ustring&;
    GLIBMM_API auto
    append (size_type n, char c) -> ustring&;
    template <class In>
    auto
    append (In pbegin, In pend) -> ustring&;

    GLIBMM_API auto
    insert (size_type i, const ustring& src) -> ustring&;
    GLIBMM_API auto
    insert (size_type i, const ustring& src, size_type i2, size_type n)
        -> ustring&;
    GLIBMM_API auto
    insert (size_type i, const char* src, size_type n) -> ustring&;
    GLIBMM_API auto
    insert (size_type i, const char* src) -> ustring&;
    GLIBMM_API auto
    insert (size_type i, size_type n, gunichar uc) -> ustring&;
    GLIBMM_API auto
    insert (size_type i, size_type n, char c) -> ustring&;

    GLIBMM_API auto
    insert (iterator p, gunichar uc) -> iterator;
    GLIBMM_API auto
    insert (iterator p, char c) -> iterator;
    GLIBMM_API auto
    insert (iterator p, size_type n, gunichar uc) -> void;
    GLIBMM_API auto
    insert (iterator p, size_type n, char c) -> void;
    template <class In>
    auto
    insert (iterator p, In pbegin, In pend) -> void;

    GLIBMM_API auto
    replace (size_type i, size_type n, const ustring& src) -> ustring&;
    GLIBMM_API auto
    replace (size_type i,
             size_type n,
             const ustring& src,
             size_type i2,
             size_type n2) -> ustring&;
    GLIBMM_API auto
    replace (size_type i, size_type n, const char* src, size_type n2)
        -> ustring&;
    GLIBMM_API auto
    replace (size_type i, size_type n, const char* src) -> ustring&;
    GLIBMM_API auto
    replace (size_type i, size_type n, size_type n2, gunichar uc) -> ustring&;
    GLIBMM_API auto
    replace (size_type i, size_type n, size_type n2, char c) -> ustring&;

    GLIBMM_API auto
    replace (iterator pbegin, iterator pend, const ustring& src) -> ustring&;
    GLIBMM_API auto
    replace (iterator pbegin, iterator pend, const char* src, size_type n)
        -> ustring&;
    GLIBMM_API auto
    replace (iterator pbegin, iterator pend, const char* src) -> ustring&;
    GLIBMM_API auto
    replace (iterator pbegin, iterator pend, size_type n, gunichar uc)
        -> ustring&;
    GLIBMM_API auto
    replace (iterator pbegin, iterator pend, size_type n, char c) -> ustring&;
    template <class In>
    auto
    replace (iterator pbegin, iterator pend, In pbegin2, In pend2) -> ustring&;

    GLIBMM_API auto
    clear () -> void;
    GLIBMM_API auto
    erase (size_type i, size_type n = npos) -> ustring&;
    GLIBMM_API auto
    erase () -> ustring&;
    GLIBMM_API auto
    erase (iterator p) -> iterator;
    GLIBMM_API auto
    erase (iterator pbegin, iterator pend) -> iterator;

    GLIBMM_API auto
    compare (UStringView rhs) const -> int;
    GLIBMM_API auto
    compare (size_type i, size_type n, UStringView rhs) const -> int;
    GLIBMM_API auto
    compare (size_type i,
             size_type n,
             const ustring& rhs,
             size_type i2,
             size_type n2) const -> int;
    GLIBMM_API auto
    compare (size_type i, size_type n, const char* rhs, size_type n2) const
        -> int;

    GLIBMM_API auto
    collate_key () const -> std::string;

    GLIBMM_API auto
    casefold_collate_key () const -> std::string;

    GLIBMM_API auto
    operator[] (size_type i) const -> value_type;

    GLIBMM_API auto
    at (size_type i) const -> value_type;

    GLIBMM_API inline auto
    substr (size_type i = 0, size_type n = npos) const -> ustring;

    GLIBMM_API auto
    begin () -> iterator;
    GLIBMM_API auto
    end () -> iterator;
    GLIBMM_API auto
    begin () const -> const_iterator;
    GLIBMM_API auto
    end () const -> const_iterator;
    GLIBMM_API auto
    rbegin () -> reverse_iterator;
    GLIBMM_API auto
    rend () -> reverse_iterator;
    GLIBMM_API auto
    rbegin () const -> const_reverse_iterator;
    GLIBMM_API auto
    rend () const -> const_reverse_iterator;

    GLIBMM_API auto
    cbegin () const -> const_iterator;

    GLIBMM_API auto
    cend () const -> const_iterator;

    GLIBMM_API auto
    find (const ustring& str, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find (const char* str, size_type i, size_type n) const -> size_type;
    GLIBMM_API auto
    find (const char* str, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find (gunichar uc, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find (char c, size_type i = 0) const -> size_type;

    GLIBMM_API auto
    rfind (const ustring& str, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    rfind (const char* str, size_type i, size_type n) const -> size_type;
    GLIBMM_API auto
    rfind (const char* str, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    rfind (gunichar uc, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    rfind (char c, size_type i = npos) const -> size_type;

    GLIBMM_API auto
    find_first_of (const ustring& match, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find_first_of (const char* match, size_type i, size_type n) const
        -> size_type;
    GLIBMM_API auto
    find_first_of (const char* match, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find_first_of (gunichar uc, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find_first_of (char c, size_type i = 0) const -> size_type;

    GLIBMM_API auto
    find_last_of (const ustring& match, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    find_last_of (const char* match, size_type i, size_type n) const
        -> size_type;
    GLIBMM_API auto
    find_last_of (const char* match, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    find_last_of (gunichar uc, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    find_last_of (char c, size_type i = npos) const -> size_type;

    GLIBMM_API auto
    find_first_not_of (const ustring& match, size_type i = 0) const
        -> size_type;
    GLIBMM_API auto
    find_first_not_of (const char* match, size_type i, size_type n) const
        -> size_type;
    GLIBMM_API auto
    find_first_not_of (const char* match, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find_first_not_of (gunichar uc, size_type i = 0) const -> size_type;
    GLIBMM_API auto
    find_first_not_of (char c, size_type i = 0) const -> size_type;

    GLIBMM_API auto
    find_last_not_of (const ustring& match, size_type i = npos) const
        -> size_type;
    GLIBMM_API auto
    find_last_not_of (const char* match, size_type i, size_type n) const
        -> size_type;
    GLIBMM_API auto
    find_last_not_of (const char* match, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    find_last_not_of (gunichar uc, size_type i = npos) const -> size_type;
    GLIBMM_API auto
    find_last_not_of (char c, size_type i = npos) const -> size_type;

    GLIBMM_API auto
    empty () const -> bool;

    GLIBMM_API auto
    size () const -> size_type;

    GLIBMM_API auto
    length () const -> size_type;

    GLIBMM_API auto
    bytes () const -> size_type;

    GLIBMM_API auto
    resize (size_type n, gunichar uc) -> void;
    GLIBMM_API auto
    resize (size_type n, char c = '\0') -> void;

    GLIBMM_API auto
    capacity () const -> size_type;
    GLIBMM_API auto
    max_size () const -> size_type;
    GLIBMM_API auto
    reserve (size_type n = 0) -> void;

    GLIBMM_API inline operator std::string () const;
    GLIBMM_API inline auto
    raw () const -> const std::string&;

    GLIBMM_API inline auto
    release () -> std::string;

    GLIBMM_API auto
    data () const -> const char*;
    GLIBMM_API auto
    c_str () const -> const char*;

    GLIBMM_API auto
    copy (char* dest, size_type n, size_type i = 0) const -> size_type;

    GLIBMM_API auto
    validate () const -> bool;

    GLIBMM_API auto
    validate (iterator& first_invalid) -> bool;

    GLIBMM_API auto
    validate (const_iterator& first_invalid) const -> bool;

    GLIBMM_API auto
    make_valid () const -> ustring;

    GLIBMM_API auto
    is_ascii () const -> bool;

    GLIBMM_API auto
    normalize (NormalizeMode mode = NormalizeMode::DEFAULT_COMPOSE) const
        -> ustring;

    GLIBMM_API auto
    uppercase () const -> ustring;

    GLIBMM_API auto
    lowercase () const -> ustring;

    GLIBMM_API auto
    casefold () const -> ustring;

    GLIBMM_API static inline auto
    compose (const ustring& fmt) -> ustring;

    template <class... Ts>
    static inline auto
    compose (const ustring& fmt, const Ts&... args) -> ustring;

    template <class... Ts>
    static inline auto
    format (const Ts&... args) -> ustring;

    template <class... Ts>
    static inline auto
    sprintf (const ustring& fmt, const Ts&... args) -> ustring;

    template <class... Ts>
    static inline auto
    sprintf (const char* fmt, const Ts&... args) -> ustring;

    GLIBMM_API static inline auto
    sprintf (const ustring& fmt) -> ustring;

    GLIBMM_API static inline auto
    sprintf (const char* fmt) -> ustring;

  private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  #ifdef GLIBMM_HAVE_STD_ITERATOR_TRAITS
    template <class In,
              class ValueType = typename std::iterator_traits<In>::value_type>
  #else
    template <class In,
              class ValueType = typename Glib::IteratorTraits<In>::value_type>
  #endif
    struct SequenceToString;

    template <class In>
    struct SequenceToString<In, char>;
    template <class In>
    struct SequenceToString<In, gunichar>;

    template <class T>
    class Stringify;

    GLIBMM_API static auto
    compose_private (const ustring& fmt,
                     std::initializer_list<const ustring*> ilist) -> ustring;

    class FormatStream;

    template <class T>
    static inline auto
    sprintify (const T& arg) -> const T&;
    GLIBMM_API static inline auto
    sprintify (const ustring& arg) -> const char*;
    GLIBMM_API static inline auto
    sprintify (const std::string& arg) -> const char*;

#endif

    std::string string_;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class In, class ValueType>
  struct ustring::SequenceToString
  {
  };

  template <class In>
  struct ustring::SequenceToString<In, char> : public std::string
  {
    SequenceToString (In pbegin, In pend);
  };

  template <class In>
  struct ustring::SequenceToString<In, gunichar> : public std::string
  {
    SequenceToString (In pbegin, In pend);
  };

  template <>
  struct ustring::SequenceToString<Glib::ustring::iterator, gunichar>
    : public std::string
  {
    GLIBMM_API
    SequenceToString (Glib::ustring::iterator pbegin,
                      Glib::ustring::iterator pend);
  };

  template <>
  struct ustring::SequenceToString<Glib::ustring::const_iterator, gunichar>
    : public std::string
  {
    GLIBMM_API
    SequenceToString (Glib::ustring::const_iterator pbegin,
                      Glib::ustring::const_iterator pend);
  };

  class ustring::FormatStream
  {
  public:
    FormatStream (const ustring::FormatStream&) = delete;
    auto
    operator= (const ustring::FormatStream&) -> FormatStream& = delete;

  private:
  #ifdef GLIBMM_HAVE_WIDE_STREAM
    using StreamType = std::wostringstream;
  #else
    using StreamType = std::ostringstream;
  #endif
    StreamType stream_;

  public:
    GLIBMM_API
    FormatStream ();
    GLIBMM_API ~FormatStream () noexcept;

    template <class T>
    inline auto
    stream (const T& value) -> void;

    GLIBMM_API inline auto
    stream (const char* value) -> void;

    GLIBMM_API inline auto
    stream (char* value) -> void;

    GLIBMM_API auto
    to_string () const -> ustring;
  };

#endif

  GLIBMM_API
  auto
  operator>> (std::istream& is, Glib::ustring& utf8_string) -> std::istream&;

  GLIBMM_API
  auto
  operator<< (std::ostream& os, const Glib::ustring& utf8_string) -> std::ostream&;

#ifdef GLIBMM_HAVE_WIDE_STREAM

  auto
  operator>> (std::wistream& is, ustring& utf8_string) -> std::wistream&;

  GLIBMM_API
  auto
  operator<< (std::wostream& os, const ustring& utf8_string) -> std::wostream&;

#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T>
  inline ustring_Iterator<T>::ustring_Iterator (T pos)
    : pos_ (pos)
  {
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::base () const -> T
  {
    return pos_;
  }

  template <class T>
  inline ustring_Iterator<T>::ustring_Iterator ()
    : pos_ ()
  {
  }

  template <class T>
  inline ustring_Iterator<T>::ustring_Iterator (
      const ustring_Iterator<std::string::iterator>& other)
    : pos_ (other.base ())
  {
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::operator* () const ->
      typename ustring_Iterator<T>::value_type
  {
    return Glib::get_unichar_from_std_iterator (pos_);
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::operator++ () -> ustring_Iterator<T>&
  {
    pos_ += g_utf8_skip[static_cast<unsigned char> (*pos_)];
    return *this;
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::operator++ (int) -> const ustring_Iterator<T>
  {
    const ustring_Iterator<T> temp (*this);
    this->operator++ ();
    return temp;
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::operator-- () -> ustring_Iterator<T>&
  {
    while ((static_cast<unsigned char> (*--pos_) & 0xC0u) == 0x80)
    {
      ;
    }

    return *this;
  }

  template <class T>
  inline auto
  ustring_Iterator<T>::operator-- (int) -> const ustring_Iterator<T>
  {
    const ustring_Iterator<T> temp (*this);
    this->operator-- ();
    return temp;
  }

#endif

  inline auto
  operator== (const Glib::ustring::const_iterator& lhs,
              const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () == rhs.base ());
  }

  inline auto
  operator!= (const Glib::ustring::const_iterator& lhs,
              const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () != rhs.base ());
  }

  inline auto
  operator<(const Glib::ustring::const_iterator& lhs,
            const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () < rhs.base ());
  }

  inline auto
  operator> (const Glib::ustring::const_iterator& lhs,
             const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () > rhs.base ());
  }

  inline auto
  operator<= (const Glib::ustring::const_iterator& lhs,
              const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () <= rhs.base ());
  }

  inline auto
  operator>= (const Glib::ustring::const_iterator& lhs,
              const Glib::ustring::const_iterator& rhs) -> bool
  {
    return (lhs.base () >= rhs.base ());
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class In>
  ustring::SequenceToString<In, char>::SequenceToString (In pbegin, In pend)
    : std::string (pbegin, pend)
  {
  }

  template <class In>
  ustring::SequenceToString<In, gunichar>::SequenceToString (In pbegin, In pend)
  {
    char utf8_buf[6];

    for (; pbegin != pend; ++pbegin)
    {
      const std::string::size_type utf8_len = g_unichar_to_utf8 (*pbegin,
                                                                 utf8_buf);
      this->append (utf8_buf, utf8_len);
    }
  }

  template <class T>
  inline auto
  ustring::FormatStream::stream (const T& value) -> void
  {
    stream_ << value;
  }

  inline auto
  ustring::FormatStream::stream (const char* value) -> void
  {
    stream_ << ustring (value);
  }

  inline auto
  ustring::FormatStream::stream (char* value) -> void
  {
    stream_ << ustring (value);
  }

  template <class In>
  ustring::ustring (In pbegin, In pend)
    : string_ (Glib::ustring::SequenceToString<In> (pbegin, pend))
  {
  }

  template <class In>
  auto
  ustring::assign (In pbegin, In pend) -> ustring&
  {
    Glib::ustring::SequenceToString<In> temp_string (pbegin, pend);
    string_.swap (temp_string);
    return *this;
  }

  template <class In>
  auto
  ustring::append (In pbegin, In pend) -> ustring&
  {
    string_.append (Glib::ustring::SequenceToString<In> (pbegin, pend));
    return *this;
  }

  template <class In>
  auto
  ustring::insert (ustring::iterator p, In pbegin, In pend) -> void
  {
    size_type pos = p.base () - string_.begin ();
    string_.insert (pos, Glib::ustring::SequenceToString<In> (pbegin, pend));
  }

  template <class In>
  auto
  ustring::replace (ustring::iterator pbegin,
                    ustring::iterator pend,
                    In pbegin2,
                    In pend2) -> ustring&
  {
    string_.replace (pbegin.base (),
                     pend.base (),
                     Glib::ustring::SequenceToString<In> (pbegin2, pend2));
    return *this;
  }

  inline auto
  ustring::substr (ustring::size_type i, ustring::size_type n) const -> ustring
  {
    return ustring (*this, i, n);
  }

  inline ustring::operator std::string () const
  {
    return string_;
  }

  inline auto
  ustring::raw () const -> const std::string&
  {
    return string_;
  }

  inline auto
  ustring::release () -> std::string
  {
    return std::move (string_);
  }

  template <class... Ts>
  inline auto
  ustring::format (const Ts&... args) -> ustring
  {
    ustring::FormatStream buf;
    (buf.stream (args), ...);
    return buf.to_string ();
  }

  template <class T>
  class ustring::Stringify
  {
  private:
    const ustring string_;

  public:
    explicit inline Stringify (const T& arg)
      : string_ (ustring::format (arg))
    {
    }

    Stringify (const ustring::Stringify<T>&) = delete;
    auto
    operator= (const ustring::Stringify<T>&) -> Stringify<T>& = delete;

    inline auto
    ref () const -> const ustring&
    {
      return string_;
    }
  };

  template <>
  class ustring::Stringify<ustring>
  {
  private:
    const ustring& string_;

  public:
    explicit inline Stringify (const ustring& arg)
      : string_ (arg)
    {
    }

    Stringify (const ustring::Stringify<ustring>&) = delete;
    auto
    operator= (const ustring::Stringify<ustring>&)
        -> Stringify<ustring>& = delete;

    inline auto
    ref () const -> const ustring&
    {
      return string_;
    }
  };

  template <>
  class ustring::Stringify<const char*>
  {
  private:
    const ustring string_;

  public:
    explicit inline Stringify (const char* arg)
      : string_ (arg)
    {
    }

    Stringify (const ustring::Stringify<const char*>&) = delete;
    auto
    operator= (const ustring::Stringify<const char*>&)
        -> Stringify<ustring>& = delete;

    inline auto
    ref () const -> const ustring&
    {
      return string_;
    }
  };

  template <std::size_t N>
  class ustring::Stringify<char[N]>
  {
  private:
    const ustring string_;

  public:
    explicit inline Stringify (const char arg[N])
      : string_ (arg)
    {
    }

    Stringify (const ustring::Stringify<char[N]>&) = delete;
    auto
    operator= (const ustring::Stringify<char[N]>&)
        -> Stringify<ustring>& = delete;

    inline auto
    ref () const -> const ustring&
    {
      return string_;
    }
  };

  template <std::size_t N>
  class ustring::Stringify<const char[N]>
  {
  private:
    const ustring string_;

  public:
    explicit inline Stringify (const char arg[N])
      : string_ (arg)
    {
    }

    Stringify (const ustring::Stringify<const char[N]>&) = delete;
    auto
    operator= (const ustring::Stringify<const char[N]>&)
        -> Stringify<ustring>& = delete;

    inline auto
    ref () const -> const ustring&
    {
      return string_;
    }
  };

  template <typename T>
  inline auto
  ustring::sprintify (const T& arg) -> const T&
  {
    return arg;
  }

  inline auto
  ustring::sprintify (const ustring& arg) -> const char*
  {
    return arg.c_str ();
  }

  inline auto
  ustring::sprintify (const std::string& arg) -> const char*
  {
    return arg.c_str ();
  }

  inline auto
  ustring::compose (const ustring& fmt) -> ustring
  {
    return ustring::compose_private (fmt, {});
  }

  template <class... Ts>
  inline auto
  ustring::compose (const ustring& fmt, const Ts&... args) -> ustring
  {
    static_assert (sizeof...(Ts) <= 9,
                   "ustring::compose only supports up to 9 placeholders.");

    return compose_private (fmt, {&Stringify<Ts> (args).ref ()...});
  }

  template <class... Ts>
  inline auto
  ustring::sprintf (const ustring& fmt, const Ts&... args) -> ustring
  {
    return sprintf (fmt.c_str (), args...);
  }

  template <class... Ts>
  inline auto
  ustring::sprintf (const char* fmt, const Ts&... args) -> ustring
  {
    auto c_str = g_strdup_printf (fmt, sprintify (args)...);
    Glib::ustring ustr (c_str);
    g_free (c_str);

    return ustr;
  }

  inline auto
  ustring::sprintf (const ustring& fmt) -> ustring
  {
    return fmt;
  }

  inline auto
  ustring::sprintf (const char* fmt) -> ustring
  {
    return ustring (fmt);
  }

#endif

  inline auto
  swap (ustring& lhs, ustring& rhs) -> void
  {
    lhs.swap (rhs);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator== (const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) == 0);
  }

  inline auto
  operator== (UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) == 0);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator!= (const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) != 0);
  }

  inline auto
  operator!= (UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) != 0);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator<(const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) < 0);
  }

  inline auto
  operator<(UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) > 0);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator> (const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) > 0);
  }

  inline auto
  operator> (UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) < 0);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator<= (const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) <= 0);
  }

  inline auto
  operator<= (UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) >= 0);
  }

  template <typename T,
            typename = std::enable_if_t<!std::is_base_of_v<ustring, T>>>
  inline auto
  operator>= (const ustring& lhs, const T& rhs) -> bool
  {
    return (lhs.compare (rhs) >= 0);
  }

  inline auto
  operator>= (UStringView lhs, const ustring& rhs) -> bool
  {
    return (rhs.compare (lhs) <= 0);
  }

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  auto
  operator== (const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator== (int lhs, const ustring& rhs) -> bool = delete;
  auto
  operator!= (const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator!= (int lhs, const ustring& rhs) -> bool = delete;
  auto
  operator<(const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator<(int lhs, const ustring& rhs) -> bool = delete;
  auto
  operator> (const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator> (int lhs, const ustring& rhs) -> bool = delete;
  auto
  operator<= (const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator<= (int lhs, const ustring& rhs) -> bool = delete;
  auto
  operator>= (const ustring& lhs, int rhs) -> bool = delete;
  auto
  operator>= (int lhs, const ustring& rhs) -> bool = delete;
#endif

  inline auto
  operator+ (const ustring& lhs, const ustring& rhs) -> ustring
  {
    ustring temp (lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (const ustring& lhs, const char* rhs) -> ustring
  {
    ustring temp (lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (const char* lhs, const ustring& rhs) -> ustring
  {
    ustring temp (lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (const ustring& lhs, gunichar rhs) -> ustring
  {
    ustring temp (lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (gunichar lhs, const ustring& rhs) -> ustring
  {
    ustring temp (1, lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (const ustring& lhs, char rhs) -> ustring
  {
    ustring temp (lhs);
    temp += rhs;
    return temp;
  }

  inline auto
  operator+ (char lhs, const ustring& rhs) -> ustring
  {
    ustring temp (1, lhs);
    temp += rhs;
    return temp;
  }

  inline UStringView::UStringView (const ustring& s)
    : pstring_ (s.c_str ())
  {
  }

} // namespace Glib

#endif
