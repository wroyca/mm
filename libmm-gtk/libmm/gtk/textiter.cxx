// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/textiter.hxx>
#include <libmm/gtk/textiter_p.hxx>

#include <cstring>
#include <gtk/gtk.h>

#include <libmm/gdk/paintable.hxx>
#include <libmm/glib/vectorutils.hxx>
#include <libmm/gtk/textbuffer.hxx>
#include <libmm/gtk/textchildanchor.hxx>
#include <libmm/gtk/textmark.hxx>

namespace
{
  auto
  TextIterBase_find_char_callback (gunichar ch, void* user_data) -> gboolean
  {
    try
    {
      auto slot = static_cast<gtk::TextIterBase::SlotFindChar*> (user_data);
      return (*slot) (ch);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
      return false;
    }
  }

} // namespace

namespace gtk
{
  auto
  TextIterBase::forward_find_char (const SlotFindChar& slot,
                                   const TextIterBase& limit) -> bool
  {
    auto slot_copy = const_cast<SlotFindChar*> (&slot);

    return gtk_text_iter_forward_find_char (gobj (),
                                            &TextIterBase_find_char_callback,
                                            slot_copy,
                                            limit.gobj ());
  }

  auto
  TextIterBase::forward_find_char (const SlotFindChar& slot) -> bool
  {
    auto slot_copy = const_cast<SlotFindChar*> (&slot);

    return gtk_text_iter_forward_find_char (gobj (),
                                            &TextIterBase_find_char_callback,
                                            slot_copy,
                                            nullptr);
  }

  auto
  TextIterBase::backward_find_char (const SlotFindChar& slot,
                                    const TextIterBase& limit) -> bool
  {
    auto slot_copy = const_cast<SlotFindChar*> (&slot);

    return gtk_text_iter_backward_find_char (gobj (),
                                             &TextIterBase_find_char_callback,
                                             slot_copy,
                                             limit.gobj ());
  }

  auto
  TextIterBase::backward_find_char (const SlotFindChar& slot) -> bool
  {
    auto slot_copy = const_cast<SlotFindChar*> (&slot);

    return gtk_text_iter_backward_find_char (gobj (),
                                             &TextIterBase_find_char_callback,
                                             slot_copy,
                                             nullptr);
  }

} // namespace gtk

namespace glib
{

  auto
  wrap_iter (GtkTextIter* object) -> gtk::TextIter&
  {
    return *reinterpret_cast<gtk::TextIter*> (object);
  }

  auto
  wrap_iter (const GtkTextIter* object) -> const gtk::TextIter&
  {
    return *reinterpret_cast<const gtk::TextIter*> (object);
  }

  auto
  wrap_const_iter (GtkTextIter* object) -> gtk::TextConstIter&
  {
    return *reinterpret_cast<gtk::TextConstIter*> (object);
  }

  auto
  wrap_const_iter (const GtkTextIter* object) -> const gtk::TextConstIter&
  {
    return *reinterpret_cast<const gtk::TextConstIter*> (object);
  }

} // namespace glib

namespace
{
}

auto
glib::Value<gtk::TextSearchFlags>::value_type () -> GType
{
  return gtk_text_search_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GtkTextIter* object) -> gtk::TextIterBase&
  {
    return *reinterpret_cast<gtk::TextIterBase*> (object);
  }

  auto
  wrap (const GtkTextIter* object) -> const gtk::TextIterBase&
  {
    return *reinterpret_cast<const gtk::TextIterBase*> (object);
  }

} // namespace glib

namespace gtk
{

  TextIterBase::TextIterBase (const TextIterBase& other) noexcept
    : gobject_ (other.gobject_)
  {
  }

  auto
  TextIterBase::operator= (const TextIterBase& other) noexcept -> TextIterBase&
  {
    gobject_ = other.gobject_;
    return *this;
  }

  TextIterBase::TextIterBase (TextIterBase&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
  }

  auto
  TextIterBase::operator= (TextIterBase&& other) noexcept -> TextIterBase&
  {
    gobject_ = std::move (other.gobject_);
    return *this;
  }

  auto
  TextIterBase::get_type () -> GType
  {
    return gtk_text_iter_get_type ();
  }

  TextIterBase::TextIterBase ()
  {
    std::memset (&gobject_, 0, sizeof (GtkTextIter));
  }

  TextIterBase::TextIterBase (const GtkTextIter* gobject)
  {
    if (gobject)
      gobject_ = *gobject;
    else
      std::memset (&gobject_, 0, sizeof (GtkTextIter));
  }

  auto
  TextIterBase::get_offset () const -> int
  {
    return gtk_text_iter_get_offset (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_line () const -> int
  {
    return gtk_text_iter_get_line (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_line_offset () const -> int
  {
    return gtk_text_iter_get_line_offset (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_line_index () const -> int
  {
    return gtk_text_iter_get_line_index (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_visible_line_offset () const -> int
  {
    return gtk_text_iter_get_visible_line_offset (
        const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_visible_line_index () const -> int
  {
    return gtk_text_iter_get_visible_line_index (
        const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_char () const -> gunichar
  {
    return gtk_text_iter_get_char (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_slice (const TextIterBase& end) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_iter_get_slice (const_cast<GtkTextIter*> (gobj ()),
                                 (end).gobj ()));
  }

  auto
  TextIterBase::get_text (const TextIterBase& end) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_iter_get_text (const_cast<GtkTextIter*> (gobj ()),
                                (end).gobj ()));
  }

  auto
  TextIterBase::get_visible_slice (const TextIterBase& end) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_iter_get_visible_slice (const_cast<GtkTextIter*> (gobj ()),
                                         (end).gobj ()));
  }

  auto
  TextIterBase::get_visible_text (const TextIterBase& end) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_iter_get_visible_text (const_cast<GtkTextIter*> (gobj ()),
                                        (end).gobj ()));
  }

  auto
  TextIterBase::starts_tag (const glib::RefPtr<const TextTag>& tag) const -> bool
  {
    return gtk_text_iter_starts_tag (
        const_cast<GtkTextIter*> (gobj ()),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::ends_tag (const glib::RefPtr<const TextTag>& tag) const -> bool
  {
    return gtk_text_iter_ends_tag (
        const_cast<GtkTextIter*> (gobj ()),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::toggles_tag (const glib::RefPtr<const TextTag>& tag) const -> bool
  {
    return gtk_text_iter_toggles_tag (
        const_cast<GtkTextIter*> (gobj ()),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::has_tag (const glib::RefPtr<const TextTag>& tag) const -> bool
  {
    return gtk_text_iter_has_tag (
        const_cast<GtkTextIter*> (gobj ()),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::editable (bool default_setting) const -> bool
  {
    return gtk_text_iter_editable (const_cast<GtkTextIter*> (gobj ()),
                                   static_cast<int> (default_setting));
  }

  auto
  TextIterBase::can_insert (bool default_editability) const -> bool
  {
    return gtk_text_iter_can_insert (const_cast<GtkTextIter*> (gobj ()),
                                     static_cast<int> (default_editability));
  }

  auto
  TextIterBase::starts_word () const -> bool
  {
    return gtk_text_iter_starts_word (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::ends_word () const -> bool
  {
    return gtk_text_iter_ends_word (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::inside_word () const -> bool
  {
    return gtk_text_iter_inside_word (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::starts_sentence () const -> bool
  {
    return gtk_text_iter_starts_sentence (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::ends_sentence () const -> bool
  {
    return gtk_text_iter_ends_sentence (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::inside_sentence () const -> bool
  {
    return gtk_text_iter_inside_sentence (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::starts_line () const -> bool
  {
    return gtk_text_iter_starts_line (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::ends_line () const -> bool
  {
    return gtk_text_iter_ends_line (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::is_cursor_position () const -> bool
  {
    return gtk_text_iter_is_cursor_position (
        const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_chars_in_line () const -> int
  {
    return gtk_text_iter_get_chars_in_line (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_bytes_in_line () const -> int
  {
    return gtk_text_iter_get_bytes_in_line (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::get_language () const -> pango::Language
  {
    return pango::Language (
        gtk_text_iter_get_language (const_cast<GtkTextIter*> (gobj ())));
  }

  auto
  TextIterBase::is_end () const -> bool
  {
    return gtk_text_iter_is_end (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::is_start () const -> bool
  {
    return gtk_text_iter_is_start (const_cast<GtkTextIter*> (gobj ()));
  }

  auto
  TextIterBase::forward_char () -> bool
  {
    return gtk_text_iter_forward_char (gobj ());
  }

  auto
  TextIterBase::backward_char () -> bool
  {
    return gtk_text_iter_backward_char (gobj ());
  }

  auto
  TextIterBase::forward_chars (int count) -> bool
  {
    return gtk_text_iter_forward_chars (gobj (), count);
  }

  auto
  TextIterBase::backward_chars (int count) -> bool
  {
    return gtk_text_iter_backward_chars (gobj (), count);
  }

  auto
  TextIterBase::forward_line () -> bool
  {
    return gtk_text_iter_forward_line (gobj ());
  }

  auto
  TextIterBase::backward_line () -> bool
  {
    return gtk_text_iter_backward_line (gobj ());
  }

  auto
  TextIterBase::forward_lines (int count) -> bool
  {
    return gtk_text_iter_forward_lines (gobj (), count);
  }

  auto
  TextIterBase::backward_lines (int count) -> bool
  {
    return gtk_text_iter_backward_lines (gobj (), count);
  }

  auto
  TextIterBase::forward_word_end () -> bool
  {
    return gtk_text_iter_forward_word_end (gobj ());
  }

  auto
  TextIterBase::backward_word_start () -> bool
  {
    return gtk_text_iter_backward_word_start (gobj ());
  }

  auto
  TextIterBase::forward_word_ends (int count) -> bool
  {
    return gtk_text_iter_forward_word_ends (gobj (), count);
  }

  auto
  TextIterBase::backward_word_starts (int count) -> bool
  {
    return gtk_text_iter_backward_word_starts (gobj (), count);
  }

  auto
  TextIterBase::forward_visible_line () -> bool
  {
    return gtk_text_iter_forward_visible_line (gobj ());
  }

  auto
  TextIterBase::backward_visible_line () -> bool
  {
    return gtk_text_iter_backward_visible_line (gobj ());
  }

  auto
  TextIterBase::forward_visible_lines (int count) -> bool
  {
    return gtk_text_iter_forward_visible_lines (gobj (), count);
  }

  auto
  TextIterBase::backward_visible_lines (int count) -> bool
  {
    return gtk_text_iter_backward_visible_lines (gobj (), count);
  }

  auto
  TextIterBase::forward_visible_word_end () -> bool
  {
    return gtk_text_iter_forward_visible_word_end (gobj ());
  }

  auto
  TextIterBase::backward_visible_word_start () -> bool
  {
    return gtk_text_iter_backward_visible_word_start (gobj ());
  }

  auto
  TextIterBase::forward_visible_word_ends (int count) -> bool
  {
    return gtk_text_iter_forward_visible_word_ends (gobj (), count);
  }

  auto
  TextIterBase::backward_visible_word_starts (int count) -> bool
  {
    return gtk_text_iter_backward_visible_word_starts (gobj (), count);
  }

  auto
  TextIterBase::forward_sentence_end () -> bool
  {
    return gtk_text_iter_forward_sentence_end (gobj ());
  }

  auto
  TextIterBase::backward_sentence_start () -> bool
  {
    return gtk_text_iter_backward_sentence_start (gobj ());
  }

  auto
  TextIterBase::forward_sentence_ends (int count) -> bool
  {
    return gtk_text_iter_forward_sentence_ends (gobj (), count);
  }

  auto
  TextIterBase::backward_sentence_starts (int count) -> bool
  {
    return gtk_text_iter_backward_sentence_starts (gobj (), count);
  }

  auto
  TextIterBase::forward_cursor_position () -> bool
  {
    return gtk_text_iter_forward_cursor_position (gobj ());
  }

  auto
  TextIterBase::backward_cursor_position () -> bool
  {
    return gtk_text_iter_backward_cursor_position (gobj ());
  }

  auto
  TextIterBase::forward_cursor_positions (int count) -> bool
  {
    return gtk_text_iter_forward_cursor_positions (gobj (), count);
  }

  auto
  TextIterBase::backward_cursor_positions (int count) -> bool
  {
    return gtk_text_iter_backward_cursor_positions (gobj (), count);
  }

  auto
  TextIterBase::forward_visible_cursor_position () -> bool
  {
    return gtk_text_iter_forward_visible_cursor_position (gobj ());
  }

  auto
  TextIterBase::backward_visible_cursor_position () -> bool
  {
    return gtk_text_iter_backward_visible_cursor_position (gobj ());
  }

  auto
  TextIterBase::forward_visible_cursor_positions (int count) -> bool
  {
    return gtk_text_iter_forward_visible_cursor_positions (gobj (), count);
  }

  auto
  TextIterBase::backward_visible_cursor_positions (int count) -> bool
  {
    return gtk_text_iter_backward_visible_cursor_positions (gobj (), count);
  }

  auto
  TextIterBase::set_offset (int char_offset) -> void
  {
    gtk_text_iter_set_offset (gobj (), char_offset);
  }

  auto
  TextIterBase::set_line (int line_number) -> void
  {
    gtk_text_iter_set_line (gobj (), line_number);
  }

  auto
  TextIterBase::set_line_offset (int char_on_line) -> void
  {
    gtk_text_iter_set_line_offset (gobj (), char_on_line);
  }

  auto
  TextIterBase::set_line_index (int byte_on_line) -> void
  {
    gtk_text_iter_set_line_index (gobj (), byte_on_line);
  }

  auto
  TextIterBase::forward_to_end () -> void
  {
    gtk_text_iter_forward_to_end (gobj ());
  }

  auto
  TextIterBase::forward_to_line_end () -> bool
  {
    return gtk_text_iter_forward_to_line_end (gobj ());
  }

  auto
  TextIterBase::set_visible_line_offset (int char_on_line) -> void
  {
    gtk_text_iter_set_visible_line_offset (gobj (), char_on_line);
  }

  auto
  TextIterBase::set_visible_line_index (int byte_on_line) -> void
  {
    gtk_text_iter_set_visible_line_index (gobj (), byte_on_line);
  }

  auto
  TextIterBase::forward_to_tag_toggle (const glib::RefPtr<const TextTag>& tag) -> bool
  {
    return gtk_text_iter_forward_to_tag_toggle (
        gobj (),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::backward_to_tag_toggle (const glib::RefPtr<const TextTag>& tag) -> bool
  {
    return gtk_text_iter_backward_to_tag_toggle (
        gobj (),
        const_cast<GtkTextTag*> (glib::unwrap<TextTag> (tag)));
  }

  auto
  TextIterBase::compare (const TextIterBase& rhs) const -> int
  {
    return gtk_text_iter_compare (const_cast<GtkTextIter*> (gobj ()),
                                  (rhs).gobj ());
  }

  auto
  TextIterBase::in_range (const TextIterBase& start,
                          const TextIterBase& end) const -> bool
  {
    return gtk_text_iter_in_range (const_cast<GtkTextIter*> (gobj ()),
                                   (start).gobj (),
                                   (end).gobj ());
  }

  auto
  operator== (const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_equal (lhs.gobj (), rhs.gobj ()) != 0);
  }

  auto
  operator!= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_equal (lhs.gobj (), rhs.gobj ()) == 0);
  }

  auto
  operator<(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_compare (lhs.gobj (), rhs.gobj ()) < 0);
  }

  auto
  operator> (const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_compare (lhs.gobj (), rhs.gobj ()) > 0);
  }

  auto
  operator<= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_compare (lhs.gobj (), rhs.gobj ()) <= 0);
  }

  auto
  operator>= (const TextIterBase& lhs, const TextIterBase& rhs) -> bool
  {
    return (gtk_text_iter_compare (lhs.gobj (), rhs.gobj ()) >= 0);
  }

} // namespace gtk

namespace gtk
{

  auto
  TextIter::get_buffer () const -> glib::RefPtr<TextBuffer>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_buffer (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextIter::get_paintable () const -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_paintable (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextIter::get_marks () const -> std::vector<glib::RefPtr<TextMark>>
  {
    return glib::SListHandler<glib::RefPtr<TextMark>>::slist_to_vector (
        gtk_text_iter_get_marks (const_cast<GtkTextIter*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextIter::get_child_anchor () const -> glib::RefPtr<TextChildAnchor>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_child_anchor (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextIter::get_toggled_tags (bool toggled_on) const -> std::vector<glib::RefPtr<TextTag>>
  {
    return glib::SListHandler<glib::RefPtr<TextTag>>::slist_to_vector (
        gtk_text_iter_get_toggled_tags (const_cast<GtkTextIter*> (gobj ()),
                                        static_cast<int> (toggled_on)),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextIter::get_tags () const -> std::vector<glib::RefPtr<TextTag>>
  {
    return glib::SListHandler<glib::RefPtr<TextTag>>::slist_to_vector (
        gtk_text_iter_get_tags (const_cast<GtkTextIter*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextIter::forward_search (const glib::ustring& str,
                            TextSearchFlags flags,
                            TextIter& match_start,
                            TextIter& match_end,
                            const TextIterBase& limit) const -> bool
  {
    return gtk_text_iter_forward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        (limit).gobj ());
  }

  auto
  TextIter::forward_search (const glib::ustring& str,
                            TextSearchFlags flags,
                            TextIter& match_start,
                            TextIter& match_end) const -> bool
  {
    return gtk_text_iter_forward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        nullptr);
  }

  auto
  TextIter::backward_search (const glib::ustring& str,
                             TextSearchFlags flags,
                             TextIter& match_start,
                             TextIter& match_end,
                             const TextIterBase& limit) const -> bool
  {
    return gtk_text_iter_backward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        (limit).gobj ());
  }

  auto
  TextIter::backward_search (const glib::ustring& str,
                             TextSearchFlags flags,
                             TextIter& match_start,
                             TextIter& match_end) const -> bool
  {
    return gtk_text_iter_backward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        nullptr);
  }

  auto
  TextIter::order (TextIter& second) -> void
  {
    gtk_text_iter_order (gobj (), (second).gobj ());
  }

} // namespace gtk

namespace gtk
{

  auto
  TextConstIter::get_buffer () const -> glib::RefPtr<const TextBuffer>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_buffer (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextConstIter::get_paintable () const -> glib::RefPtr<const gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_paintable (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextConstIter::get_marks () const -> std::vector<glib::RefPtr<const TextMark>>
  {
    return glib::SListHandler<glib::RefPtr<const TextMark>>::slist_to_vector (
        gtk_text_iter_get_marks (const_cast<GtkTextIter*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextConstIter::get_child_anchor () const -> glib::RefPtr<const TextChildAnchor>
  {
    auto retvalue = glib::wrap (
        gtk_text_iter_get_child_anchor (const_cast<GtkTextIter*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextConstIter::get_toggled_tags (bool toggled_on) const -> std::vector<glib::RefPtr<const TextTag>>
  {
    return glib::SListHandler<glib::RefPtr<const TextTag>>::slist_to_vector (
        gtk_text_iter_get_toggled_tags (const_cast<GtkTextIter*> (gobj ()),
                                        static_cast<int> (toggled_on)),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextConstIter::get_tags () const -> std::vector<glib::RefPtr<const TextTag>>
  {
    return glib::SListHandler<glib::RefPtr<const TextTag>>::slist_to_vector (
        gtk_text_iter_get_tags (const_cast<GtkTextIter*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  TextConstIter::forward_search (const glib::ustring& str,
                                 TextSearchFlags flags,
                                 TextConstIter& match_start,
                                 TextConstIter& match_end,
                                 const TextIterBase& limit) const -> bool
  {
    return gtk_text_iter_forward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        (limit).gobj ());
  }

  auto
  TextConstIter::forward_search (const glib::ustring& str,
                                 TextSearchFlags flags,
                                 TextConstIter& match_start,
                                 TextConstIter& match_end) const -> bool
  {
    return gtk_text_iter_forward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        nullptr);
  }

  auto
  TextConstIter::backward_search (const glib::ustring& str,
                                  TextSearchFlags flags,
                                  TextConstIter& match_start,
                                  TextConstIter& match_end,
                                  const TextIterBase& limit) const -> bool
  {
    return gtk_text_iter_backward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        (limit).gobj ());
  }

  auto
  TextConstIter::backward_search (const glib::ustring& str,
                                  TextSearchFlags flags,
                                  TextConstIter& match_start,
                                  TextConstIter& match_end) const -> bool
  {
    return gtk_text_iter_backward_search (
        const_cast<GtkTextIter*> (gobj ()),
        str.c_str (),
        static_cast<GtkTextSearchFlags> (flags),
        (match_start).gobj (),
        (match_end).gobj (),
        nullptr);
  }

  auto
  TextConstIter::order (TextConstIter& second) -> void
  {
    gtk_text_iter_order (gobj (), (second).gobj ());
  }

} // namespace gtk
