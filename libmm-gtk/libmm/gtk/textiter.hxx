// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTITER_H
#define _GTKMM_TEXTITER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gtk/texttag.hxx>
#include <libmm/pango/language.hxx>
#include <vector>

namespace Gdk
{
  class Paintable;
}

namespace Gtk
{

  enum class TextSearchFlags
  {
    VISIBLE_ONLY = 1 << 0,
    TEXT_ONLY = 1 << 1,
    CASE_INSENSITIVE = 1 << 2
  };

  inline auto
  operator| (TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  {
    return static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  {
    return static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (TextSearchFlags lhs, TextSearchFlags rhs) -> TextSearchFlags
  {
    return static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(TextSearchFlags flags) -> TextSearchFlags
  {
    return static_cast<TextSearchFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  {
    return (lhs = static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  {
    return (lhs = static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (TextSearchFlags& lhs, TextSearchFlags rhs) -> TextSearchFlags&
  {
    return (lhs = static_cast<TextSearchFlags> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TextSearchFlags>
    : public Glib::Value_Flags<Gtk::TextSearchFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TextBuffer;
  class LIBMM_GTK_SYMEXPORT TextMark;
  class LIBMM_GTK_SYMEXPORT TextChildAnchor;

  class LIBMM_GTK_SYMEXPORT TextIterBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextIterBase;
    using BaseObjectType = GtkTextIter;
#endif

    TextIterBase (const TextIterBase& other) noexcept;
    auto
    operator= (const TextIterBase& other) noexcept -> TextIterBase&;

    TextIterBase (TextIterBase&& other) noexcept;
    auto
    operator= (TextIterBase&& other) noexcept -> TextIterBase&;

    static auto
    get_type () -> GType G_GNUC_CONST;

    TextIterBase ();

    explicit TextIterBase (const GtkTextIter* gobject);

    auto
    gobj () -> GtkTextIter*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GtkTextIter*
    {
      return &gobject_;
    }

  protected:
    GtkTextIter gobject_;

  private:
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = gunichar;
    using difference_type = int;
    using reference = value_type;
    using pointer = void;

    inline auto
    operator* () const -> value_type;

    explicit operator bool () const;

    auto
    get_offset () const -> int;

    auto
    get_line () const -> int;

    auto
    get_line_offset () const -> int;

    auto
    get_line_index () const -> int;

    auto
    get_visible_line_offset () const -> int;

    auto
    get_visible_line_index () const -> int;

    auto
    get_char () const -> gunichar;

    auto
    get_slice (const TextIterBase& end) const -> Glib::ustring;

    auto
    get_text (const TextIterBase& end) const -> Glib::ustring;

    auto
    get_visible_slice (const TextIterBase& end) const -> Glib::ustring;

    auto
    get_visible_text (const TextIterBase& end) const -> Glib::ustring;

    auto
    starts_tag (const Glib::RefPtr<const TextTag>& tag = {}) const -> bool;

    auto
    ends_tag (const Glib::RefPtr<const TextTag>& tag = {}) const -> bool;

    auto
    toggles_tag (const Glib::RefPtr<const TextTag>& tag = {}) const -> bool;

    auto
    has_tag (const Glib::RefPtr<const TextTag>& tag) const -> bool;

    auto
    editable (bool default_setting = true) const -> bool;

    auto
    can_insert (bool default_editability = true) const -> bool;

    auto
    starts_word () const -> bool;

    auto
    ends_word () const -> bool;

    auto
    inside_word () const -> bool;

    auto
    starts_sentence () const -> bool;

    auto
    ends_sentence () const -> bool;

    auto
    inside_sentence () const -> bool;

    auto
    starts_line () const -> bool;

    auto
    ends_line () const -> bool;

    auto
    is_cursor_position () const -> bool;

    auto
    get_chars_in_line () const -> int;

    auto
    get_bytes_in_line () const -> int;

    auto
    get_language () const -> Pango::Language;

    auto
    is_end () const -> bool;

    auto
    is_start () const -> bool;

    auto
    forward_char () -> bool;

    auto
    backward_char () -> bool;

    auto
    forward_chars (int count) -> bool;

    auto
    backward_chars (int count) -> bool;

    auto
    forward_line () -> bool;

    auto
    backward_line () -> bool;

    auto
    forward_lines (int count) -> bool;

    auto
    backward_lines (int count) -> bool;

    auto
    forward_word_end () -> bool;

    auto
    backward_word_start () -> bool;

    auto
    forward_word_ends (int count) -> bool;

    auto
    backward_word_starts (int count) -> bool;

    auto
    forward_visible_line () -> bool;

    auto
    backward_visible_line () -> bool;

    auto
    forward_visible_lines (int count) -> bool;

    auto
    backward_visible_lines (int count) -> bool;

    auto
    forward_visible_word_end () -> bool;

    auto
    backward_visible_word_start () -> bool;

    auto
    forward_visible_word_ends (int count) -> bool;

    auto
    backward_visible_word_starts (int count) -> bool;

    auto
    forward_sentence_end () -> bool;

    auto
    backward_sentence_start () -> bool;

    auto
    forward_sentence_ends (int count) -> bool;

    auto
    backward_sentence_starts (int count) -> bool;

    auto
    forward_cursor_position () -> bool;

    auto
    backward_cursor_position () -> bool;

    auto
    forward_cursor_positions (int count) -> bool;

    auto
    backward_cursor_positions (int count) -> bool;

    auto
    forward_visible_cursor_position () -> bool;

    auto
    backward_visible_cursor_position () -> bool;

    auto
    forward_visible_cursor_positions (int count) -> bool;

    auto
    backward_visible_cursor_positions (int count) -> bool;

    auto
    set_offset (int char_offset) -> void;

    auto
    set_line (int line_number) -> void;

    auto
    set_line_offset (int char_on_line) -> void;

    auto
    set_line_index (int byte_on_line) -> void;

    auto
    forward_to_end () -> void;

    auto
    forward_to_line_end () -> bool;

    auto
    set_visible_line_offset (int char_on_line) -> void;

    auto
    set_visible_line_index (int byte_on_line) -> void;

    auto
    forward_to_tag_toggle (const Glib::RefPtr<const TextTag>& tag = {}) -> bool;

    auto
    backward_to_tag_toggle (const Glib::RefPtr<const TextTag>& tag = {})
        -> bool;

    using SlotFindChar = sigc::slot<bool (gunichar)>;

    auto
    forward_find_char (const SlotFindChar& slot, const TextIterBase& limit)
        -> bool;

    auto
    forward_find_char (const SlotFindChar& slot) -> bool;

    auto
    backward_find_char (const SlotFindChar& slot, const TextIterBase& limit)
        -> bool;

    auto
    backward_find_char (const SlotFindChar& slot) -> bool;

    auto
    compare (const TextIterBase& rhs) const -> int;

    auto
    in_range (const TextIterBase& start, const TextIterBase& end) const -> bool;
  };

  class LIBMM_GTK_SYMEXPORT TextIter : public TextIterBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextIter;
    using BaseObjectType = GtkTextIter;
#endif

  private:
  public:
    inline auto
    operator++ () -> TextIter&;
    inline auto
    operator++ (int) -> TextIter;

    inline auto
    operator-- () -> TextIter&;
    inline auto
    operator-- (int) -> TextIter;

    auto
    get_buffer () const -> Glib::RefPtr<TextBuffer>;

    auto
    get_paintable () const -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_marks () const -> std::vector<Glib::RefPtr<TextMark>>;

    auto
    get_child_anchor () const -> Glib::RefPtr<TextChildAnchor>;

    auto
    get_toggled_tags (bool toggled_on = true) const
        -> std::vector<Glib::RefPtr<TextTag>>;

    auto
    get_tags () const -> std::vector<Glib::RefPtr<TextTag>>;

    auto
    forward_search (const Glib::ustring& str,
                    TextSearchFlags flags,
                    TextIter& match_start,
                    TextIter& match_end,
                    const TextIterBase& limit) const -> bool;

    auto
    forward_search (const Glib::ustring& str,
                    TextSearchFlags flags,
                    TextIter& match_start,
                    TextIter& match_end) const -> bool;

    auto
    backward_search (const Glib::ustring& str,
                     TextSearchFlags flags,
                     TextIter& match_start,
                     TextIter& match_end,
                     const TextIterBase& limit) const -> bool;

    auto
    backward_search (const Glib::ustring& str,
                     TextSearchFlags flags,
                     TextIter& match_start,
                     TextIter& match_end) const -> bool;

    auto
    order (TextIter& second) -> void;
  };

  class LIBMM_GTK_SYMEXPORT TextConstIter : public TextIterBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TextConstIter;
    using BaseObjectType = GtkTextIter;
#endif

  private:
  public:
    inline TextConstIter () noexcept;

    inline TextConstIter (const TextIter& other) noexcept;

    inline auto
    operator= (const TextIter& other) noexcept -> TextConstIter&;

    inline auto
    operator++ () -> TextConstIter&;
    inline auto
    operator++ (int) -> TextConstIter;

    inline auto
    operator-- () -> TextConstIter&;
    inline auto
    operator-- (int) -> TextConstIter;

    auto
    get_buffer () const -> Glib::RefPtr<const TextBuffer>;

    auto
    get_paintable () const -> Glib::RefPtr<const Gdk::Paintable>;

    auto
    get_marks () const -> std::vector<Glib::RefPtr<const TextMark>>;

    auto
    get_child_anchor () const -> Glib::RefPtr<const TextChildAnchor>;

    auto
    get_toggled_tags (bool toggled_on = true) const
        -> std::vector<Glib::RefPtr<const TextTag>>;

    auto
    get_tags () const -> std::vector<Glib::RefPtr<const TextTag>>;

    auto
    forward_search (const Glib::ustring& str,
                    TextSearchFlags flags,
                    TextConstIter& match_start,
                    TextConstIter& match_end,
                    const TextIterBase& limit) const -> bool;

    auto
    forward_search (const Glib::ustring& str,
                    TextSearchFlags flags,
                    TextConstIter& match_start,
                    TextConstIter& match_end) const -> bool;

    auto
    backward_search (const Glib::ustring& str,
                     TextSearchFlags flags,
                     TextConstIter& match_start,
                     TextConstIter& match_end,
                     const TextIterBase& limit) const -> bool;

    auto
    backward_search (const Glib::ustring& str,
                     TextSearchFlags flags,
                     TextConstIter& match_start,
                     TextConstIter& match_end) const -> bool;

    auto
    order (TextConstIter& second) -> void;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  inline auto
  TextIterBase::operator* () const -> TextIterBase::value_type
  {
    return get_char ();
  }

  inline TextIterBase::operator bool () const
  {
    return !is_end ();
  }

  inline auto
  TextIter::operator++ () -> TextIter&
  {
    forward_char ();
    return *this;
  }

  inline auto
  TextIter::operator++ (int) -> TextIter
  {
    const TextIter temp (*this);
    forward_char ();
    return temp;
  }

  inline auto
  TextIter::operator-- () -> TextIter&
  {
    backward_char ();
    return *this;
  }

  inline auto
  TextIter::operator-- (int) -> TextIter
  {
    const TextIter temp (*this);
    backward_char ();
    return temp;
  }

  TextConstIter::TextConstIter () noexcept {}

  TextConstIter::TextConstIter (const TextIter& other) noexcept
    : TextIterBase (other.gobj ())
  {
  }

  auto
  TextConstIter::operator= (const TextIter& other) noexcept -> TextConstIter&
  {
    gobject_ = *other.gobj ();
    return *this;
  }

  inline auto
  TextConstIter::operator++ () -> TextConstIter&
  {
    forward_char ();
    return *this;
  }

  inline auto
  TextConstIter::operator++ (int) -> TextConstIter
  {
    const TextConstIter temp (*this);
    forward_char ();
    return temp;
  }

  inline auto
  TextConstIter::operator-- () -> TextConstIter&
  {
    backward_char ();
    return *this;
  }

  inline auto
  TextConstIter::operator-- (int) -> TextConstIter
  {
    const TextConstIter temp (*this);
    backward_char ();
    return temp;
  }

#endif

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap_iter (GtkTextIter* object) -> Gtk::TextIter&;

  LIBMM_GTK_SYMEXPORT auto
  wrap_iter (const GtkTextIter* object) -> const Gtk::TextIter&;

  LIBMM_GTK_SYMEXPORT auto
  wrap_const_iter (GtkTextIter* object) -> Gtk::TextConstIter&;

  LIBMM_GTK_SYMEXPORT auto
  wrap_const_iter (const GtkTextIter* object) -> const Gtk::TextConstIter&;

} // namespace Glib

namespace Gtk
{
  LIBMM_GTK_SYMEXPORT auto
  operator== (const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator!= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator<(const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator> (const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator<= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator>= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool;

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextIter* object) -> Gtk::TextIterBase&;

  LIBMM_GTK_SYMEXPORT auto
  wrap (const GtkTextIter* object) -> const Gtk::TextIterBase&;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TextIterBase>
    : public Glib::Value_Boxed<Gtk::TextIterBase>
  {
  };
#endif

} // namespace Glib

#endif
