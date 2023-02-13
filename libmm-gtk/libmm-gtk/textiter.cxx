


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/textiter.hxx>
#include <libmm-gtk/textiter_p.hxx>

#include <gtk/gtk.h>
#include <cstring> // std::memset()

/* Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-glib/vectorutils.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gtk/textbuffer.hxx>
#include <libmm-gtk/textmark.hxx>
#include <libmm-gtk/textchildanchor.hxx>

/**** Gtk::TextIterBase *******************************************************/

namespace
{
auto TextIterBase_find_char_callback(
  const gunichar ch, void* user_data) -> gboolean
{
  try
  {
    const auto slot = static_cast<Gtk::TextIterBase::SlotFindChar*>(user_data);
    return (*slot)(ch);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
    return false;
  }
}

} // anonymous namespace

namespace Gtk
{
auto TextIterBase::forward_find_char(const SlotFindChar& slot, const TextIterBase& limit) -> bool
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotFindChar*>(&slot);

  return gtk_text_iter_forward_find_char(gobj(), &TextIterBase_find_char_callback, slot_copy, limit.gobj());
}

auto TextIterBase::forward_find_char(const SlotFindChar& slot) -> bool
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotFindChar*>(&slot);

  return gtk_text_iter_forward_find_char(gobj(), &TextIterBase_find_char_callback, slot_copy, nullptr);
}

auto TextIterBase::backward_find_char(const SlotFindChar& slot, const TextIterBase& limit) -> bool
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotFindChar*>(&slot);

  return gtk_text_iter_backward_find_char(gobj(), &TextIterBase_find_char_callback, slot_copy, limit.gobj());
}

auto TextIterBase::backward_find_char(const SlotFindChar& slot) -> bool
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotFindChar*>(&slot);

  return gtk_text_iter_backward_find_char(gobj(), &TextIterBase_find_char_callback, slot_copy, nullptr);
}

} // namespace Gtk

/**** Gtk::TextIter and Gtk::TextConstIter ************************************/

namespace Glib
{
// Can't have overloaded functions that differ only in return type.
// These can't be called Glib::wrap().

auto wrap_iter(GtkTextIter* object) -> Gtk::TextIter&
{
  return *reinterpret_cast<Gtk::TextIter*>(object);
}

auto wrap_iter(const GtkTextIter* object) -> const Gtk::TextIter&
{
  return *reinterpret_cast<const Gtk::TextIter*>(object);
}

auto wrap_const_iter(GtkTextIter* object) -> Gtk::TextConstIter&
{
  return *reinterpret_cast<Gtk::TextConstIter*>(object);
}

auto wrap_const_iter(const GtkTextIter* object) -> const Gtk::TextConstIter&
{
  return *reinterpret_cast<const Gtk::TextConstIter*>(object);
}

} // namespace Glib

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Gtk::TextSearchFlags>::value_type() -> GType
{
  return gtk_text_search_flags_get_type();
}


namespace Glib
{

auto wrap(GtkTextIter* object) -> Gtk::TextIterBase&
{
  return *reinterpret_cast<Gtk::TextIterBase*>(object);
}

auto wrap(const GtkTextIter* object) -> const Gtk::TextIterBase&
{
  return *reinterpret_cast<const Gtk::TextIterBase*>(object);
}

} // namespace Glib


namespace Gtk
{


TextIterBase::TextIterBase(const TextIterBase& other) noexcept = default;

auto TextIterBase::operator=(const TextIterBase& other) noexcept -> TextIterBase& = default;

TextIterBase::TextIterBase(TextIterBase&& other) noexcept
:
  gobject_(std::move(other.gobject_))
{
  //We could wipe other.gobject_ via memset,
  //but that is not really necessary:
  //other.gobject_ = nullptr;
}

auto TextIterBase::operator=(TextIterBase&& other) noexcept -> TextIterBase&
{
  gobject_ = std::move(other.gobject_);
  return *this;
}

// static
auto TextIterBase::get_type() -> GType
{
  return gtk_text_iter_get_type();
}

TextIterBase::TextIterBase()
{
  std::memset(&gobject_, 0, sizeof(GtkTextIter));
}

TextIterBase::TextIterBase(const GtkTextIter* gobject)
{
  if(gobject)
    gobject_ = *gobject;
  else
    std::memset(&gobject_, 0, sizeof(GtkTextIter));
}


auto TextIterBase::get_offset() const -> int
{
  return gtk_text_iter_get_offset(gobj());
}

auto TextIterBase::get_line() const -> int
{
  return gtk_text_iter_get_line(gobj());
}

auto TextIterBase::get_line_offset() const -> int
{
  return gtk_text_iter_get_line_offset(gobj());
}

auto TextIterBase::get_line_index() const -> int
{
  return gtk_text_iter_get_line_index(gobj());
}

auto TextIterBase::get_visible_line_offset() const -> int
{
  return gtk_text_iter_get_visible_line_offset(gobj());
}

auto TextIterBase::get_visible_line_index() const -> int
{
  return gtk_text_iter_get_visible_line_index(gobj());
}

auto TextIterBase::get_char() const -> gunichar
{
  return gtk_text_iter_get_char(gobj());
}

auto TextIterBase::get_slice(const TextIterBase& end) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_text_iter_get_slice(gobj(), end.gobj()));
}

auto TextIterBase::get_text(const TextIterBase& end) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_text_iter_get_text(gobj(), end.gobj()));
}

auto TextIterBase::get_visible_slice(const TextIterBase& end) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_text_iter_get_visible_slice(gobj(), end.gobj()));
}

auto TextIterBase::get_visible_text(const TextIterBase& end) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_text_iter_get_visible_text(gobj(), end.gobj()));
}

auto TextIterBase::starts_tag(const Glib::RefPtr<const TextTag>& tag) const -> bool
{
  return gtk_text_iter_starts_tag(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::ends_tag(const Glib::RefPtr<const TextTag>& tag) const -> bool
{
  return gtk_text_iter_ends_tag(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::toggles_tag(const Glib::RefPtr<const TextTag>& tag) const -> bool
{
  return gtk_text_iter_toggles_tag(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::has_tag(const Glib::RefPtr<const TextTag>& tag) const -> bool
{
  return gtk_text_iter_has_tag(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::editable(
  const bool default_setting) const -> bool
{
  return gtk_text_iter_editable(gobj(), default_setting);
}

auto TextIterBase::can_insert(
  const bool default_editability) const -> bool
{
  return gtk_text_iter_can_insert(gobj(), default_editability);
}

auto TextIterBase::starts_word() const -> bool
{
  return gtk_text_iter_starts_word(gobj());
}

auto TextIterBase::ends_word() const -> bool
{
  return gtk_text_iter_ends_word(gobj());
}

auto TextIterBase::inside_word() const -> bool
{
  return gtk_text_iter_inside_word(gobj());
}

auto TextIterBase::starts_sentence() const -> bool
{
  return gtk_text_iter_starts_sentence(gobj());
}

auto TextIterBase::ends_sentence() const -> bool
{
  return gtk_text_iter_ends_sentence(gobj());
}

auto TextIterBase::inside_sentence() const -> bool
{
  return gtk_text_iter_inside_sentence(gobj());
}

auto TextIterBase::starts_line() const -> bool
{
  return gtk_text_iter_starts_line(gobj());
}

auto TextIterBase::ends_line() const -> bool
{
  return gtk_text_iter_ends_line(gobj());
}

auto TextIterBase::is_cursor_position() const -> bool
{
  return gtk_text_iter_is_cursor_position(gobj());
}

auto TextIterBase::get_chars_in_line() const -> int
{
  return gtk_text_iter_get_chars_in_line(gobj());
}

auto TextIterBase::get_bytes_in_line() const -> int
{
  return gtk_text_iter_get_bytes_in_line(gobj());
}

auto TextIterBase::get_language() const -> Pango::Language
{
  return Pango::Language(gtk_text_iter_get_language(gobj()));
}

auto TextIterBase::is_end() const -> bool
{
  return gtk_text_iter_is_end(gobj());
}

auto TextIterBase::is_start() const -> bool
{
  return gtk_text_iter_is_start(gobj());
}

auto TextIterBase::forward_char() -> bool
{
  return gtk_text_iter_forward_char(gobj());
}

auto TextIterBase::backward_char() -> bool
{
  return gtk_text_iter_backward_char(gobj());
}

auto TextIterBase::forward_chars(
  const int count) -> bool
{
  return gtk_text_iter_forward_chars(gobj(), count);
}

auto TextIterBase::backward_chars(
  const int count) -> bool
{
  return gtk_text_iter_backward_chars(gobj(), count);
}

auto TextIterBase::forward_line() -> bool
{
  return gtk_text_iter_forward_line(gobj());
}

auto TextIterBase::backward_line() -> bool
{
  return gtk_text_iter_backward_line(gobj());
}

auto TextIterBase::forward_lines(
  const int count) -> bool
{
  return gtk_text_iter_forward_lines(gobj(), count);
}

auto TextIterBase::backward_lines(
  const int count) -> bool
{
  return gtk_text_iter_backward_lines(gobj(), count);
}

auto TextIterBase::forward_word_end() -> bool
{
  return gtk_text_iter_forward_word_end(gobj());
}

auto TextIterBase::backward_word_start() -> bool
{
  return gtk_text_iter_backward_word_start(gobj());
}

auto TextIterBase::forward_word_ends(
  const int count) -> bool
{
  return gtk_text_iter_forward_word_ends(gobj(), count);
}

auto TextIterBase::backward_word_starts(
  const int count) -> bool
{
  return gtk_text_iter_backward_word_starts(gobj(), count);
}

auto TextIterBase::forward_visible_line() -> bool
{
  return gtk_text_iter_forward_visible_line(gobj());
}

auto TextIterBase::backward_visible_line() -> bool
{
  return gtk_text_iter_backward_visible_line(gobj());
}

auto TextIterBase::forward_visible_lines(
  const int count) -> bool
{
  return gtk_text_iter_forward_visible_lines(gobj(), count);
}

auto TextIterBase::backward_visible_lines(
  const int count) -> bool
{
  return gtk_text_iter_backward_visible_lines(gobj(), count);
}

auto TextIterBase::forward_visible_word_end() -> bool
{
  return gtk_text_iter_forward_visible_word_end(gobj());
}

auto TextIterBase::backward_visible_word_start() -> bool
{
  return gtk_text_iter_backward_visible_word_start(gobj());
}

auto TextIterBase::forward_visible_word_ends(
  const int count) -> bool
{
  return gtk_text_iter_forward_visible_word_ends(gobj(), count);
}

auto TextIterBase::backward_visible_word_starts(
  const int count) -> bool
{
  return gtk_text_iter_backward_visible_word_starts(gobj(), count);
}

auto TextIterBase::forward_sentence_end() -> bool
{
  return gtk_text_iter_forward_sentence_end(gobj());
}

auto TextIterBase::backward_sentence_start() -> bool
{
  return gtk_text_iter_backward_sentence_start(gobj());
}

auto TextIterBase::forward_sentence_ends(
  const int count) -> bool
{
  return gtk_text_iter_forward_sentence_ends(gobj(), count);
}

auto TextIterBase::backward_sentence_starts(
  const int count) -> bool
{
  return gtk_text_iter_backward_sentence_starts(gobj(), count);
}

auto TextIterBase::forward_cursor_position() -> bool
{
  return gtk_text_iter_forward_cursor_position(gobj());
}

auto TextIterBase::backward_cursor_position() -> bool
{
  return gtk_text_iter_backward_cursor_position(gobj());
}

auto TextIterBase::forward_cursor_positions(
  const int count) -> bool
{
  return gtk_text_iter_forward_cursor_positions(gobj(), count);
}

auto TextIterBase::backward_cursor_positions(
  const int count) -> bool
{
  return gtk_text_iter_backward_cursor_positions(gobj(), count);
}

auto TextIterBase::forward_visible_cursor_position() -> bool
{
  return gtk_text_iter_forward_visible_cursor_position(gobj());
}

auto TextIterBase::backward_visible_cursor_position() -> bool
{
  return gtk_text_iter_backward_visible_cursor_position(gobj());
}

auto TextIterBase::forward_visible_cursor_positions(
  const int count) -> bool
{
  return gtk_text_iter_forward_visible_cursor_positions(gobj(), count);
}

auto TextIterBase::backward_visible_cursor_positions(
  const int count) -> bool
{
  return gtk_text_iter_backward_visible_cursor_positions(gobj(), count);
}

auto TextIterBase::set_offset (
  const int char_offset) -> void
{
  gtk_text_iter_set_offset(gobj(), char_offset);
}

auto TextIterBase::set_line (
  const int line_number) -> void
{
  gtk_text_iter_set_line(gobj(), line_number);
}

auto TextIterBase::set_line_offset (
  const int char_on_line) -> void
{
  gtk_text_iter_set_line_offset(gobj(), char_on_line);
}

auto TextIterBase::set_line_index (
  const int byte_on_line) -> void
{
  gtk_text_iter_set_line_index(gobj(), byte_on_line);
}

auto TextIterBase::forward_to_end () -> void
{
  gtk_text_iter_forward_to_end(gobj());
}

auto TextIterBase::forward_to_line_end() -> bool
{
  return gtk_text_iter_forward_to_line_end(gobj());
}

auto TextIterBase::set_visible_line_offset (
  const int char_on_line) -> void
{
  gtk_text_iter_set_visible_line_offset(gobj(), char_on_line);
}

auto TextIterBase::set_visible_line_index (
  const int byte_on_line) -> void
{
  gtk_text_iter_set_visible_line_index(gobj(), byte_on_line);
}

auto TextIterBase::forward_to_tag_toggle(const Glib::RefPtr<const TextTag>& tag) -> bool
{
  return gtk_text_iter_forward_to_tag_toggle(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::backward_to_tag_toggle(const Glib::RefPtr<const TextTag>& tag) -> bool
{
  return gtk_text_iter_backward_to_tag_toggle(gobj(), const_cast<GtkTextTag*>(Glib::unwrap<TextTag>(tag)));
}

auto TextIterBase::compare(const TextIterBase& rhs) const -> int
{
  return gtk_text_iter_compare(gobj(), rhs.gobj());
}

auto TextIterBase::in_range(const TextIterBase& start, const TextIterBase& end) const -> bool
{
  return gtk_text_iter_in_range(gobj(), start.gobj(), end.gobj());
}


auto operator==(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_equal(lhs.gobj(), rhs.gobj()) != 0;
}

auto operator!=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_equal(lhs.gobj(), rhs.gobj()) == 0;
}

auto operator<(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_compare(lhs.gobj(), rhs.gobj()) < 0;
}

auto operator>(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_compare(lhs.gobj(), rhs.gobj()) > 0;
}

auto operator<=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_compare(lhs.gobj(), rhs.gobj()) <= 0;
}

auto operator>=(const TextIterBase& lhs, const TextIterBase& rhs) -> bool
{
  return gtk_text_iter_compare(lhs.gobj(), rhs.gobj()) >= 0;
}


} // namespace Gtk


namespace Gtk
{


auto TextIter::get_buffer() const -> Glib::RefPtr<TextBuffer>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_buffer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextIter::get_paintable() const -> Glib::RefPtr<Gdk::Paintable>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_paintable(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextIter::get_marks() const -> std::vector<Glib::RefPtr<TextMark>>
{
  return Glib::SListHandler<Glib::RefPtr<TextMark> >::slist_to_vector(gtk_text_iter_get_marks(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto TextIter::get_child_anchor() const -> Glib::RefPtr<TextChildAnchor>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_child_anchor(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextIter::get_toggled_tags(
  const bool toggled_on) const -> std::vector<Glib::RefPtr<TextTag>>
{
  return Glib::SListHandler<Glib::RefPtr<TextTag> >::slist_to_vector(gtk_text_iter_get_toggled_tags(gobj(), toggled_on), Glib::OWNERSHIP_SHALLOW);
}

auto TextIter::get_tags() const -> std::vector<Glib::RefPtr<TextTag>>
{
  return Glib::SListHandler<Glib::RefPtr<TextTag> >::slist_to_vector(gtk_text_iter_get_tags(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto TextIter::forward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end, const TextIterBase& limit) const -> bool
{
  return gtk_text_iter_forward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), limit.gobj());
}

auto TextIter::forward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end) const -> bool
{
  return gtk_text_iter_forward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), nullptr);
}

auto TextIter::backward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end, const TextIterBase& limit) const -> bool
{
  return gtk_text_iter_backward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), limit.gobj());
}

auto TextIter::backward_search(const Glib::ustring& str, TextSearchFlags flags, TextIter& match_start, TextIter& match_end) const -> bool
{
  return gtk_text_iter_backward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), nullptr);
}

auto TextIter::order (TextIter &second) -> void
{
  gtk_text_iter_order(gobj(), second.gobj());
}


} // namespace Gtk


namespace Gtk
{


auto TextConstIter::get_buffer() const -> Glib::RefPtr<const TextBuffer>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_buffer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextConstIter::get_paintable() const -> Glib::RefPtr<const Gdk::Paintable>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_paintable(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextConstIter::get_marks() const -> std::vector<Glib::RefPtr<const TextMark>>
{
  return Glib::SListHandler<Glib::RefPtr<const TextMark> >::slist_to_vector(gtk_text_iter_get_marks(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto TextConstIter::get_child_anchor() const -> Glib::RefPtr<const TextChildAnchor>
{
  auto retvalue = Glib::wrap(gtk_text_iter_get_child_anchor(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto TextConstIter::get_toggled_tags(
  const bool toggled_on) const -> std::vector<Glib::RefPtr<const TextTag>>
{
  return Glib::SListHandler<Glib::RefPtr<const TextTag> >::slist_to_vector(gtk_text_iter_get_toggled_tags(gobj(), toggled_on), Glib::OWNERSHIP_SHALLOW);
}

auto TextConstIter::get_tags() const -> std::vector<Glib::RefPtr<const TextTag>>
{
  return Glib::SListHandler<Glib::RefPtr<const TextTag> >::slist_to_vector(gtk_text_iter_get_tags(gobj()), Glib::OWNERSHIP_SHALLOW);
}

auto TextConstIter::forward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end, const TextIterBase& limit) const -> bool
{
  return gtk_text_iter_forward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), limit.gobj());
}

auto TextConstIter::forward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end) const -> bool
{
  return gtk_text_iter_forward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), nullptr);
}

auto TextConstIter::backward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end, const TextIterBase& limit) const -> bool
{
  return gtk_text_iter_backward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), limit.gobj());
}

auto TextConstIter::backward_search(const Glib::ustring& str, TextSearchFlags flags, TextConstIter& match_start, TextConstIter& match_end) const -> bool
{
  return gtk_text_iter_backward_search(gobj(), str.c_str(), static_cast<GtkTextSearchFlags>(flags), match_start.gobj(), match_end.gobj(), nullptr);
}

auto TextConstIter::order (TextConstIter &second) -> void
{
  gtk_text_iter_order(gobj(), second.gobj());
}


} // namespace Gtk

