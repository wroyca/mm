// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/textbuffer.hxx>
#include <libmm/gtk/textbuffer_p.hxx>

#include <libmm/glib/vectorutils.hxx>

#include <glib.h>
#include <gtk/gtk.h>
#include <libmm/gtk/textiter.hxx>
#include <libmm/gtk/textmark.hxx>

namespace Gtk
{

  typedef TextChildAnchor ChildAnchor;

  TextBuffer::TextBuffer (const Glib::RefPtr<TagTable>& tag_table)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (textbuffer_class_.init (),
                                           "tag_table",
                                           Glib::unwrap (tag_table),
                                           nullptr))
  {
  }

  auto
  TextBuffer::create_tag (const Glib::ustring& tag_name) -> Glib::RefPtr<TextBuffer::Tag>
  {
    return Glib::wrap (
        gtk_text_buffer_create_tag (gobj (), tag_name.c_str (), nullptr),
        true);
  }

  auto
  TextBuffer::create_tag () -> Glib::RefPtr<TextBuffer::Tag>
  {
    return Glib::wrap (gtk_text_buffer_create_tag (gobj (), nullptr, nullptr),
                       true);
  }

  auto
  TextBuffer::create_mark (const TextBuffer::iterator& where, bool left_gravity) -> Glib::RefPtr<TextBuffer::Mark>
  {
    return Glib::wrap (
        gtk_text_buffer_create_mark (gobj (),
                                     nullptr,
                                     const_cast<GtkTextIter*> (where.gobj ()),
                                     left_gravity),
        true);
  }

  auto
  TextBuffer::get_iter_at_line_offset (int line_number, int char_offset) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_line_offset (gobj (),
                                             iter.gobj (),
                                             line_number,
                                             char_offset);
    return iter;
  }

  auto
  TextBuffer::get_iter_at_line_offset (int line_number, int char_offset) const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_line_offset (
        line_number,
        char_offset);
  }

  auto
  TextBuffer::get_iter_at_line_index (int line_number, int byte_index) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_line_index (gobj (),
                                            iter.gobj (),
                                            line_number,
                                            byte_index);
    return iter;
  }

  auto
  TextBuffer::get_iter_at_line_index (int line_number, int byte_index) const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_line_index (line_number,
                                                                   byte_index);
  }

  auto
  TextBuffer::get_iter_at_offset (int char_offset) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_offset (gobj (), iter.gobj (), char_offset);
    return iter;
  }

  auto
  TextBuffer::get_iter_at_offset (int char_offset) const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_offset (char_offset);
  }

  auto
  TextBuffer::get_iter_at_line (int line_number) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_line (gobj (), iter.gobj (), line_number);
    return iter;
  }

  auto
  TextBuffer::get_iter_at_line (int line_number) const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_line (line_number);
  }

  auto
  TextBuffer::begin () -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_start_iter (gobj (), iter.gobj ());
    return iter;
  }

  auto
  TextBuffer::begin () const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->begin ();
  }

  auto
  TextBuffer::end () -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_end_iter (gobj (), iter.gobj ());
    return iter;
  }

  auto
  TextBuffer::end () const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->end ();
  }

  auto
  TextBuffer::get_bounds (iterator& range_begin, iterator& range_end) -> void
  {
    gtk_text_buffer_get_bounds (gobj (),
                                range_begin.gobj (),
                                range_end.gobj ());
  }

  auto
  TextBuffer::get_bounds (const_iterator& range_begin,
                          const_iterator& range_end) const -> void
  {
    gtk_text_buffer_get_bounds (const_cast<GtkTextBuffer*> (gobj ()),
                                range_begin.gobj (),
                                range_end.gobj ());
  }

  auto
  TextBuffer::get_iter_at_mark (const Glib::RefPtr<Mark>& mark) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_mark (gobj (), iter.gobj (), mark->gobj ());
    return iter;
  }

  auto
  TextBuffer::get_iter_at_mark (GtkTextMark* mark) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_mark (gobj (), iter.gobj (), mark);
    return iter;
  }

  auto
  TextBuffer::get_iter_at_mark (const Glib::RefPtr<Mark>& mark) const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_mark (mark);
  }

  auto
  TextBuffer::set_text (const Glib::ustring& text) -> void
  {
    gtk_text_buffer_set_text (gobj (), text.data (), text.bytes ());
  }

  auto
  TextBuffer::set_text (const char* text_begin, const char* text_end) -> void
  {
    gtk_text_buffer_set_text (gobj (), text_begin, text_end - text_begin);
  }

  auto
  TextBuffer::insert (const iterator& pos, const Glib::ustring& text) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert (gobj (),
                            iterCopy.gobj (),
                            text.data (),
                            text.bytes ());

    return iterCopy;
  }

  auto
  TextBuffer::insert (const iterator& pos,
                      const char* text_begin,
                      const char* text_end) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert (gobj (),
                            iterCopy.gobj (),
                            text_begin,
                            text_end - text_begin);

    return iterCopy;
  }

  auto
  TextBuffer::insert_paintable (const iterator& pos,
                                const Glib::RefPtr<Gdk::Paintable>& paintable) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert_paintable (gobj (),
                                      iterCopy.gobj (),
                                      paintable->gobj ());
    return iterCopy;
  }

  auto
  TextBuffer::insert_child_anchor (const iterator& pos,
                                   const Glib::RefPtr<ChildAnchor>& anchor) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert_child_anchor (gobj (),
                                         iterCopy.gobj (),
                                         Glib::unwrap (anchor));
    return iterCopy;
  }

  auto
  TextBuffer::create_child_anchor (const iterator& pos) -> Glib::RefPtr<ChildAnchor>
  {
    iterator iterCopy (pos);
    return Glib::wrap (
        gtk_text_buffer_create_child_anchor (gobj (), iterCopy.gobj ()),
        true);
  }

  auto
  TextBuffer::insert_at_cursor (const Glib::ustring& text) -> void
  {
    gtk_text_buffer_insert_at_cursor (gobj (), text.data (), text.bytes ());
  }

  auto
  TextBuffer::insert_at_cursor (const char* text_begin, const char* text_end) -> void
  {
    gtk_text_buffer_insert_at_cursor (gobj (),
                                      text_begin,
                                      text_end - text_begin);
  }

  auto
  TextBuffer::insert_interactive (const iterator& pos,
                                  const Glib::ustring& text,
                                  bool default_editable) -> std::pair<TextBuffer::iterator, bool>
  {
    std::pair<iterator, bool> pair_iter_success (pos, false);

    pair_iter_success.second = gtk_text_buffer_insert_interactive (
        gobj (),
        pair_iter_success.first.gobj (),
        text.data (),
        text.bytes (),
        default_editable);

    return pair_iter_success;
  }

  auto
  TextBuffer::insert_interactive (const iterator& pos,
                                  const char* text_begin,
                                  const char* text_end,
                                  bool default_editable) -> std::pair<TextBuffer::iterator, bool>
  {
    std::pair<iterator, bool> pair_iter_success (pos, false);

    pair_iter_success.second = gtk_text_buffer_insert_interactive (
        gobj (),
        pair_iter_success.first.gobj (),
        text_begin,
        text_end - text_begin,
        default_editable);

    return pair_iter_success;
  }

  auto
  TextBuffer::insert_interactive_at_cursor (const Glib::ustring& text,
                                            bool default_editable) -> bool
  {
    return gtk_text_buffer_insert_interactive_at_cursor (gobj (),
                                                         text.data (),
                                                         text.bytes (),
                                                         default_editable);
  }

  auto
  TextBuffer::insert_interactive_at_cursor (const char* text_begin,
                                            const char* text_end,
                                            bool default_editable) -> bool
  {
    return gtk_text_buffer_insert_interactive_at_cursor (gobj (),
                                                         text_begin,
                                                         text_end - text_begin,
                                                         default_editable);
  }

  auto
  TextBuffer::insert_with_tag (const iterator& pos,
                               const Glib::ustring& text,
                               const Glib::RefPtr<Tag>& tag) -> TextBuffer::iterator
  {
    const int offset = pos.get_offset ();

    iterator iterCopy (pos);
    gtk_text_buffer_insert_with_tags (gobj (),
                                      iterCopy.gobj (),
                                      text.data (),
                                      text.bytes (),
                                      tag->gobj (),
                                      nullptr);

    return get_iter_at_offset (offset + text.size ());
  }

  auto
  TextBuffer::insert_with_tag (const iterator& pos,
                               const char* text_begin,
                               const char* text_end,
                               const Glib::RefPtr<Tag>& tag) -> TextBuffer::iterator
  {
    const int offset = pos.get_offset ();

    iterator iterCopy (pos);
    gtk_text_buffer_insert_with_tags (gobj (),
                                      iterCopy.gobj (),
                                      text_begin,
                                      text_end - text_begin,
                                      tag->gobj (),
                                      nullptr);

    return get_iter_at_offset (offset + (text_end - text_begin));
  }

  auto
  TextBuffer::insert_with_tag (const iterator& pos,
                               const Glib::ustring& text,
                               const Glib::ustring& tag_name) -> TextBuffer::iterator
  {
    const int offset = pos.get_offset ();

    iterator iterCopy (pos);
    gtk_text_buffer_insert_with_tags_by_name (gobj (),
                                              iterCopy.gobj (),
                                              text.data (),
                                              text.bytes (),
                                              tag_name.c_str (),
                                              nullptr);

    return get_iter_at_offset (offset + text.size ());
  }

  auto
  TextBuffer::insert_with_tag (const iterator& pos,
                               const char* text_begin,
                               const char* text_end,
                               const Glib::ustring& tag_name) -> TextBuffer::iterator
  {
    const int offset = pos.get_offset ();

    iterator iterCopy (pos);
    gtk_text_buffer_insert_with_tags_by_name (gobj (),
                                              iterCopy.gobj (),
                                              text_begin,
                                              text_end - text_begin,
                                              tag_name.c_str (),
                                              nullptr);

    return get_iter_at_offset (offset + (text_end - text_begin));
  }

  auto
  TextBuffer::insert_with_tags (const iterator& pos,
                                const Glib::ustring& text,
                                const std::vector<Glib::RefPtr<Tag>>& tags) -> TextBuffer::iterator
  {
    const char* const text_begin = text.data ();
    return insert_with_tags (pos, text_begin, text_begin + text.bytes (), tags);
  }

  auto
  TextBuffer::insert_with_tags (const iterator& pos,
                                const char* text_begin,
                                const char* text_end,
                                const std::vector<Glib::RefPtr<Tag>>& tags) -> TextBuffer::iterator
  {
    const int start_offset = pos.get_offset ();
    iterator range_end (insert (pos, text_begin, text_end));

    GtkTextIter range_begin;
    gtk_text_buffer_get_iter_at_offset (gobj (), &range_begin, start_offset);

    Glib::ArrayHandler<Glib::RefPtr<Tag>>::ArrayKeeperType array_keeper (
        Glib::ArrayHandler<Glib::RefPtr<Tag>>::vector_to_array (tags));

    GtkTextTag* const* const tags_begin = array_keeper.data ();
    GtkTextTag* const* const tags_end = tags_begin + tags.size ();

    for (GtkTextTag* const* ptag = tags_begin; ptag != tags_end; ++ptag)
    {
      gtk_text_buffer_apply_tag (gobj (),
                                 *ptag,
                                 &range_begin,
                                 range_end.gobj ());
    }

    return range_end;
  }

  auto
  TextBuffer::insert_with_tags_by_name (
      const iterator& pos,
      const Glib::ustring& text,
      const std::vector<Glib::ustring>& tag_names) -> TextBuffer::iterator
  {
    const char* const text_begin = text.data ();
    return insert_with_tags_by_name (pos,
                                     text_begin,
                                     text_begin + text.bytes (),
                                     tag_names);
  }

  auto
  TextBuffer::insert_with_tags_by_name (
      const iterator& pos,
      const char* text_begin,
      const char* text_end,
      const std::vector<Glib::ustring>& tag_names) -> TextBuffer::iterator
  {
    const int start_offset = pos.get_offset ();
    iterator range_end (insert (pos, text_begin, text_end));

    GtkTextIter range_begin;
    gtk_text_buffer_get_iter_at_offset (gobj (), &range_begin, start_offset);

    const auto tag_table = gtk_text_buffer_get_tag_table (gobj ());
    Glib::ArrayHandler<Glib::ustring>::ArrayKeeperType array_keeper (
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (tag_names));

    const char* const* const names_begin = array_keeper.data ();
    const char* const* const names_end = names_begin + tag_names.size ();

    for (const char* const* pname = names_begin; pname != names_end; ++pname)
    {
      if (GtkTextTag* const tag = gtk_text_tag_table_lookup (tag_table, *pname))
      {
        gtk_text_buffer_apply_tag (gobj (),
                                   tag,
                                   &range_begin,
                                   range_end.gobj ());
      }
      else
      {
        g_warning ("Gtk::TextBuffer::insert_with_tags_by_name(): no tag with "
                   "name '%s'!",
                   *pname);
      }
    }

    return range_end;
  }

  auto
  TextBuffer::insert_markup (const iterator& pos, const Glib::ustring& markup) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert_markup (gobj (),
                                   iterCopy.gobj (),
                                   markup.data (),
                                   markup.bytes ());

    return iterCopy;
  }

  auto
  TextBuffer::insert_markup (const iterator& pos,
                             const char* markup_begin,
                             const char* markup_end) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert_markup (gobj (),
                                   iterCopy.gobj (),
                                   markup_begin,
                                   markup_end - markup_begin);

    return iterCopy;
  }

  auto
  TextBuffer::insert (const iterator& pos,
                      const const_iterator& range_begin,
                      const const_iterator& range_end) -> TextBuffer::iterator
  {
    iterator iterCopy (pos);
    gtk_text_buffer_insert_range (gobj (),
                                  iterCopy.gobj (),
                                  range_begin.gobj (),
                                  range_end.gobj ());
    return iterCopy;
  }

  auto
  TextBuffer::insert_interactive (const iterator& pos,
                                  const const_iterator& range_begin,
                                  const const_iterator& range_end,
                                  bool default_editable) -> std::pair<TextBuffer::iterator, bool>
  {
    std::pair<iterator, bool> pair_iter_success (pos, false);

    pair_iter_success.second = gtk_text_buffer_insert_range_interactive (
        gobj (),
        pair_iter_success.first.gobj (),
        range_begin.gobj (),
        range_end.gobj (),
        default_editable);

    return pair_iter_success;
  }

  auto
  TextBuffer::erase (const iterator& range_begin, const iterator& range_end) -> TextBuffer::iterator
  {
    iterator beginCopy (range_begin);
    iterator endCopy (range_end);
    gtk_text_buffer_delete (gobj (), beginCopy.gobj (), endCopy.gobj ());
    return beginCopy;
  }

  auto
  TextBuffer::backspace (const iterator& iter,
                         bool interactive,
                         bool default_editable) -> TextBuffer::iterator
  {
    iterator copy (iter);
    gtk_text_buffer_backspace (gobj (),
                               copy.gobj (),
                               interactive,
                               default_editable);
    return copy;
  }

  auto
  TextBuffer::erase_interactive (const iterator& range_begin,
                                 const iterator& range_end,
                                 bool default_editable) -> std::pair<TextBuffer::iterator, bool>
  {
    std::pair<iterator, bool> pair_iter_success (range_begin, false);

    iterator endCopy (range_end);

    pair_iter_success.second = gtk_text_buffer_delete_interactive (
        gobj (),
        pair_iter_success.first.gobj (),
        endCopy.gobj (),
        default_editable);

    return pair_iter_success;
  }

  auto
  TextBuffer::get_iter_at_child_anchor (const Glib::RefPtr<ChildAnchor>& anchor) -> TextBuffer::iterator
  {
    iterator iter;
    gtk_text_buffer_get_iter_at_child_anchor (gobj (),
                                              iter.gobj (),
                                              anchor->gobj ());
    return iter;
  }

  auto
  TextBuffer::get_iter_at_child_anchor (const Glib::RefPtr<ChildAnchor>& anchor)
      const -> TextBuffer::const_iterator
  {
    return const_cast<TextBuffer*> (this)->get_iter_at_child_anchor (anchor);
  }

  auto
  TextBuffer::size () const -> int
  {
    return get_char_count ();
  }

  auto
  TextBuffer::get_text (bool include_hidden_chars) const -> Glib::ustring
  {
    auto unconst = const_cast<TextBuffer*> (this);
    return get_text (unconst->begin (), unconst->end (), include_hidden_chars);
  }

} // namespace Gtk

namespace
{

  static auto
  TextBuffer_signal_insert_callback (GtkTextBuffer* self,
                                     GtkTextIter* p0,
                                     const gchar* p1,
                                     gint p2,
                                     void* data) -> void
  {
    using namespace Gtk;
    using SlotType =
        sigc::slot<void (TextBuffer::iterator&, const Glib::ustring&, int)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (
              slot)) (Glib::wrap_iter (p0), Glib::ustring (p1, p1 + p2), p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_insert_info = {
      "insert_text",
      (GCallback) &TextBuffer_signal_insert_callback,
      (GCallback) &TextBuffer_signal_insert_callback};

  static auto
  TextBuffer_signal_insert_paintable_callback (GtkTextBuffer* self,
                                               GtkTextIter* p0,
                                               GdkPaintable* p1,
                                               void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (TextBuffer::iterator&,
                                      const Glib::RefPtr<Gdk::Paintable>&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap_iter (p0),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_insert_paintable_info = {
      "insert_paintable",
      (GCallback) &TextBuffer_signal_insert_paintable_callback,
      (GCallback) &TextBuffer_signal_insert_paintable_callback};

  static auto
  TextBuffer_signal_insert_child_anchor_callback (GtkTextBuffer* self,
                                                  GtkTextIter* p0,
                                                  GtkTextChildAnchor* p1,
                                                  void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (TextBuffer::iterator&,
                                      const Glib::RefPtr<ChildAnchor>&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap_iter (p0),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      TextBuffer_signal_insert_child_anchor_info = {
          "insert_child_anchor",
          (GCallback) &TextBuffer_signal_insert_child_anchor_callback,
          (GCallback) &TextBuffer_signal_insert_child_anchor_callback};

  static auto
  TextBuffer_signal_erase_callback (GtkTextBuffer* self,
                                    GtkTextIter* p0,
                                    GtkTextIter* p1,
                                    void* data) -> void
  {
    using namespace Gtk;
    using SlotType =
        sigc::slot<void (TextBuffer::iterator&, TextBuffer::iterator&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap_iter (p0),
                                            Glib::wrap_iter (p1));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_erase_info = {
      "delete_range",
      (GCallback) &TextBuffer_signal_erase_callback,
      (GCallback) &TextBuffer_signal_erase_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_changed_info = {
      "changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_modified_changed_info = {
      "modified_changed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  TextBuffer_signal_mark_set_callback (GtkTextBuffer* self,
                                       const GtkTextIter* p0,
                                       GtkTextMark* p1,
                                       void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const TextBuffer::iterator&,
                                      const Glib::RefPtr<TextBuffer::Mark>&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap_iter (p0),
                                            Glib::wrap (p1, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_mark_set_info = {
      "mark_set",
      (GCallback) &TextBuffer_signal_mark_set_callback,
      (GCallback) &TextBuffer_signal_mark_set_callback};

  static auto
  TextBuffer_signal_mark_deleted_callback (GtkTextBuffer* self,
                                           GtkTextMark* p0,
                                           void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TextBuffer::Mark>&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_mark_deleted_info = {
      "mark_deleted",
      (GCallback) &TextBuffer_signal_mark_deleted_callback,
      (GCallback) &TextBuffer_signal_mark_deleted_callback};

  static auto
  TextBuffer_signal_apply_tag_callback (GtkTextBuffer* self,
                                        GtkTextTag* p0,
                                        const GtkTextIter* p1,
                                        const GtkTextIter* p2,
                                        void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                      const TextBuffer::iterator&,
                                      const TextBuffer::iterator&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap_iter (p1),
                                            Glib::wrap_iter (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_apply_tag_info = {
      "apply_tag",
      (GCallback) &TextBuffer_signal_apply_tag_callback,
      (GCallback) &TextBuffer_signal_apply_tag_callback};

  static auto
  TextBuffer_signal_remove_tag_callback (GtkTextBuffer* self,
                                         GtkTextTag* p0,
                                         const GtkTextIter* p1,
                                         const GtkTextIter* p2,
                                         void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                      const TextBuffer::iterator&,
                                      const TextBuffer::iterator&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap_iter (p1),
                                            Glib::wrap_iter (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_remove_tag_info = {
      "remove_tag",
      (GCallback) &TextBuffer_signal_remove_tag_callback,
      (GCallback) &TextBuffer_signal_remove_tag_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_begin_user_action_info =
      {"begin_user_action",
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_end_user_action_info = {
      "end_user_action",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  TextBuffer_signal_paste_done_callback (GtkTextBuffer* self,
                                         GdkClipboard* p0,
                                         void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Gdk::Clipboard>&)>;

    auto obj = dynamic_cast<TextBuffer*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo TextBuffer_signal_paste_done_info = {
      "paste_done",
      (GCallback) &TextBuffer_signal_paste_done_callback,
      (GCallback) &TextBuffer_signal_paste_done_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_redo_info = {
      "redo",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo TextBuffer_signal_undo_info = {
      "undo",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkTextBuffer* object, bool take_copy) -> Glib::RefPtr<Gtk::TextBuffer>
  {
    return Glib::make_refptr_for_instance<Gtk::TextBuffer> (
        dynamic_cast<Gtk::TextBuffer*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextBuffer_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextBuffer_Class::class_init_function;

      register_derived_type (gtk_text_buffer_get_type ());
    }

    return *this;
  }

  auto
  TextBuffer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->insert_text = &insert_text_callback;
    klass->insert_paintable = &insert_paintable_callback;
    klass->insert_child_anchor = &insert_child_anchor_callback;
    klass->delete_range = &delete_range_callback;
    klass->changed = &changed_callback;
    klass->modified_changed = &modified_changed_callback;
    klass->mark_set = &mark_set_callback;
    klass->mark_deleted = &mark_deleted_callback;
    klass->apply_tag = &apply_tag_callback;
    klass->remove_tag = &remove_tag_callback;
    klass->begin_user_action = &begin_user_action_callback;
    klass->end_user_action = &end_user_action_callback;
    klass->paste_done = &paste_done_callback;
    klass->redo = &redo_callback;
    klass->undo = &undo_callback;
  }

  auto
  TextBuffer_Class::insert_text_callback (GtkTextBuffer* self,
                                          GtkTextIter* p0,
                                          const gchar* p1,
                                          gint p2) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert (Glib::wrap_iter (p0),
                          Glib::ustring (p1, p1 + p2),
                          p2);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->insert_text)
      (*base->insert_text) (self, p0, p1, p2);
  }

  auto
  TextBuffer_Class::insert_paintable_callback (GtkTextBuffer* self,
                                               GtkTextIter* p0,
                                               GdkPaintable* p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert_paintable (Glib::wrap_iter (p0),
                                    Glib::wrap (p1, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->insert_paintable)
      (*base->insert_paintable) (self, p0, p1);
  }

  auto
  TextBuffer_Class::insert_child_anchor_callback (GtkTextBuffer* self,
                                                  GtkTextIter* p0,
                                                  GtkTextChildAnchor* p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert_child_anchor (Glib::wrap_iter (p0),
                                       Glib::wrap (p1, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->insert_child_anchor)
      (*base->insert_child_anchor) (self, p0, p1);
  }

  auto
  TextBuffer_Class::delete_range_callback (GtkTextBuffer* self,
                                           GtkTextIter* p0,
                                           GtkTextIter* p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_erase (Glib::wrap_iter (p0), Glib::wrap_iter (p1));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->delete_range)
      (*base->delete_range) (self, p0, p1);
  }

  auto
  TextBuffer_Class::changed_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self);
  }

  auto
  TextBuffer_Class::modified_changed_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_modified_changed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->modified_changed)
      (*base->modified_changed) (self);
  }

  auto
  TextBuffer_Class::mark_set_callback (GtkTextBuffer* self,
                                       const GtkTextIter* p0,
                                       GtkTextMark* p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_mark_set (Glib::wrap_iter (p0), Glib::wrap (p1, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mark_set)
      (*base->mark_set) (self, p0, p1);
  }

  auto
  TextBuffer_Class::mark_deleted_callback (GtkTextBuffer* self, GtkTextMark* p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_mark_deleted (Glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->mark_deleted)
      (*base->mark_deleted) (self, p0);
  }

  auto
  TextBuffer_Class::apply_tag_callback (GtkTextBuffer* self,
                                        GtkTextTag* p0,
                                        const GtkTextIter* p1,
                                        const GtkTextIter* p2) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_apply_tag (Glib::wrap (p0, true),
                             Glib::wrap_iter (p1),
                             Glib::wrap_iter (p2));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->apply_tag)
      (*base->apply_tag) (self, p0, p1, p2);
  }

  auto
  TextBuffer_Class::remove_tag_callback (GtkTextBuffer* self,
                                         GtkTextTag* p0,
                                         const GtkTextIter* p1,
                                         const GtkTextIter* p2) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_remove_tag (Glib::wrap (p0, true),
                              Glib::wrap_iter (p1),
                              Glib::wrap_iter (p2));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->remove_tag)
      (*base->remove_tag) (self, p0, p1, p2);
  }

  auto
  TextBuffer_Class::begin_user_action_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_begin_user_action ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->begin_user_action)
      (*base->begin_user_action) (self);
  }

  auto
  TextBuffer_Class::end_user_action_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_end_user_action ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->end_user_action)
      (*base->end_user_action) (self);
  }

  auto
  TextBuffer_Class::paste_done_callback (GtkTextBuffer* self, GdkClipboard* p0) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_paste_done (Glib::wrap (p0, true));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->paste_done)
      (*base->paste_done) (self, p0);
  }

  auto
  TextBuffer_Class::redo_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_redo ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->redo)
      (*base->redo) (self);
  }

  auto
  TextBuffer_Class::undo_callback (GtkTextBuffer* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_undo ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->undo)
      (*base->undo) (self);
  }

  auto
  TextBuffer_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TextBuffer ((GtkTextBuffer*) object);
  }

  auto
  TextBuffer::gobj_copy () -> GtkTextBuffer*
  {
    reference ();
    return gobj ();
  }

  TextBuffer::TextBuffer (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TextBuffer::TextBuffer (GtkTextBuffer* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TextBuffer::TextBuffer (TextBuffer&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TextBuffer::operator= (TextBuffer&& src) noexcept -> TextBuffer&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  TextBuffer::~TextBuffer () noexcept {}

  TextBuffer::CppClassType TextBuffer::textbuffer_class_;

  auto
  TextBuffer::get_type () -> GType
  {
    return textbuffer_class_.init ().get_type ();
  }

  auto
  TextBuffer::get_base_type () -> GType
  {
    return gtk_text_buffer_get_type ();
  }

  TextBuffer::TextBuffer ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (textbuffer_class_.init ()))
  {
  }

  auto
  TextBuffer::create () -> Glib::RefPtr<TextBuffer>
  {
    return Glib::make_refptr_for_instance<TextBuffer> (new TextBuffer ());
  }

  auto
  TextBuffer::create (const Glib::RefPtr<TagTable>& tag_table) -> Glib::RefPtr<TextBuffer>
  {
    return Glib::make_refptr_for_instance<TextBuffer> (
        new TextBuffer (tag_table));
  }

  auto
  TextBuffer::get_line_count () const -> int
  {
    return gtk_text_buffer_get_line_count (
        const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::get_char_count () const -> int
  {
    return gtk_text_buffer_get_char_count (
        const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::get_tag_table () -> Glib::RefPtr<TextBuffer::TagTable>
  {
    auto retvalue = Glib::wrap (gtk_text_buffer_get_tag_table (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextBuffer::get_tag_table () const -> Glib::RefPtr<const TextBuffer::TagTable>
  {
    return const_cast<TextBuffer*> (this)->get_tag_table ();
  }

  auto
  TextBuffer::get_text (const const_iterator& range_start,
                        const const_iterator& range_end,
                        bool include_hidden_chars) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_buffer_get_text (const_cast<GtkTextBuffer*> (gobj ()),
                                  (range_start).gobj (),
                                  (range_end).gobj (),
                                  static_cast<int> (include_hidden_chars)));
  }

  auto
  TextBuffer::get_slice (const const_iterator& range_start,
                         const const_iterator& range_end,
                         bool include_hidden_chars) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_text_buffer_get_slice (const_cast<GtkTextBuffer*> (gobj ()),
                                   (range_start).gobj (),
                                   (range_end).gobj (),
                                   static_cast<int> (include_hidden_chars)));
  }

  auto
  TextBuffer::add_mark (const Glib::RefPtr<TextBuffer::Mark>& mark,
                        const iterator& where) -> void
  {
    gtk_text_buffer_add_mark (gobj (), Glib::unwrap (mark), (where).gobj ());
  }

  auto
  TextBuffer::create_mark (const Glib::ustring& mark_name,
                           const iterator& where,
                           bool left_gravity) -> Glib::RefPtr<TextBuffer::Mark>
  {
    auto retvalue = Glib::wrap (
        gtk_text_buffer_create_mark (gobj (),
                                     mark_name.c_str (),
                                     (where).gobj (),
                                     static_cast<int> (left_gravity)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextBuffer::move_mark (const Glib::RefPtr<Mark>& mark, const iterator& where) -> void
  {
    gtk_text_buffer_move_mark (gobj (), Glib::unwrap (mark), (where).gobj ());
  }

  auto
  TextBuffer::delete_mark (const Glib::RefPtr<Mark>& mark) -> void
  {
    gtk_text_buffer_delete_mark (gobj (), Glib::unwrap (mark));
  }

  auto
  TextBuffer::get_mark (const Glib::ustring& name) -> Glib::RefPtr<TextBuffer::Mark>
  {
    auto retvalue =
        Glib::wrap (gtk_text_buffer_get_mark (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextBuffer::get_mark (const Glib::ustring& name) const -> Glib::RefPtr<const TextBuffer::Mark>
  {
    return const_cast<TextBuffer*> (this)->get_mark (name);
  }

  auto
  TextBuffer::move_mark_by_name (const Glib::ustring& name,
                                 const iterator& where) -> void
  {
    gtk_text_buffer_move_mark_by_name (gobj (), name.c_str (), (where).gobj ());
  }

  auto
  TextBuffer::delete_mark_by_name (const Glib::ustring& name) -> void
  {
    gtk_text_buffer_delete_mark_by_name (gobj (), name.c_str ());
  }

  auto
  TextBuffer::get_insert () -> Glib::RefPtr<TextBuffer::Mark>
  {
    auto retvalue = Glib::wrap (gtk_text_buffer_get_insert (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextBuffer::get_selection_bound () -> Glib::RefPtr<TextBuffer::Mark>
  {
    auto retvalue = Glib::wrap (gtk_text_buffer_get_selection_bound (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextBuffer::place_cursor (const iterator& where) -> void
  {
    gtk_text_buffer_place_cursor (gobj (), (where).gobj ());
  }

  auto
  TextBuffer::apply_tag (const Glib::RefPtr<Tag>& tag,
                         const iterator& range_start,
                         const iterator& range_end) -> void
  {
    gtk_text_buffer_apply_tag (gobj (),
                               Glib::unwrap (tag),
                               (range_start).gobj (),
                               (range_end).gobj ());
  }

  auto
  TextBuffer::remove_tag (const Glib::RefPtr<Tag>& tag,
                          const iterator& range_start,
                          const iterator& range_end) -> void
  {
    gtk_text_buffer_remove_tag (gobj (),
                                Glib::unwrap (tag),
                                (range_start).gobj (),
                                (range_end).gobj ());
  }

  auto
  TextBuffer::apply_tag_by_name (const Glib::ustring& name,
                                 const iterator& range_start,
                                 const iterator& range_end) -> void
  {
    gtk_text_buffer_apply_tag_by_name (gobj (),
                                       name.c_str (),
                                       (range_start).gobj (),
                                       (range_end).gobj ());
  }

  auto
  TextBuffer::remove_tag_by_name (const Glib::ustring& name,
                                  const iterator& range_start,
                                  const iterator& range_end) -> void
  {
    gtk_text_buffer_remove_tag_by_name (gobj (),
                                        name.c_str (),
                                        (range_start).gobj (),
                                        (range_end).gobj ());
  }

  auto
  TextBuffer::remove_all_tags (const iterator& range_start,
                               const iterator& range_end) -> void
  {
    gtk_text_buffer_remove_all_tags (gobj (),
                                     (range_start).gobj (),
                                     (range_end).gobj ());
  }

  auto
  TextBuffer::get_modified () const -> bool
  {
    return gtk_text_buffer_get_modified (const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::set_modified (bool setting) -> void
  {
    gtk_text_buffer_set_modified (gobj (), static_cast<int> (setting));
  }

  auto
  TextBuffer::get_has_selection () const -> bool
  {
    return gtk_text_buffer_get_has_selection (
        const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::add_selection_clipboard (
      const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void
  {
    gtk_text_buffer_add_selection_clipboard (gobj (), Glib::unwrap (clipboard));
  }

  auto
  TextBuffer::remove_selection_clipboard (
      const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void
  {
    gtk_text_buffer_remove_selection_clipboard (gobj (),
                                                Glib::unwrap (clipboard));
  }

  auto
  TextBuffer::cut_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                             bool default_editable) -> void
  {
    gtk_text_buffer_cut_clipboard (gobj (),
                                   Glib::unwrap (clipboard),
                                   static_cast<int> (default_editable));
  }

  auto
  TextBuffer::copy_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void
  {
    gtk_text_buffer_copy_clipboard (gobj (), Glib::unwrap (clipboard));
  }

  auto
  TextBuffer::paste_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                               const iterator& override_location,
                               bool default_editable) -> void
  {
    gtk_text_buffer_paste_clipboard (
        gobj (),
        Glib::unwrap (clipboard),
        const_cast<GtkTextIter*> ((override_location).gobj ()),
        static_cast<int> (default_editable));
  }

  auto
  TextBuffer::paste_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                               bool default_editable) -> void
  {
    gtk_text_buffer_paste_clipboard (gobj (),
                                     Glib::unwrap (clipboard),
                                     nullptr,
                                     static_cast<int> (default_editable));
  }

  auto
  TextBuffer::get_selection_bounds (iterator& range_start, iterator& range_end) -> bool
  {
    return gtk_text_buffer_get_selection_bounds (gobj (),
                                                 (range_start).gobj (),
                                                 (range_end).gobj ());
  }

  auto
  TextBuffer::get_selection_bounds (const_iterator& range_start,
                                    const_iterator& range_end) const -> bool
  {
    return gtk_text_buffer_get_selection_bounds (
        const_cast<GtkTextBuffer*> (gobj ()),
        const_cast<GtkTextIter*> ((range_start).gobj ()),
        const_cast<GtkTextIter*> ((range_end).gobj ()));
  }

  auto
  TextBuffer::erase_selection (bool interactive, bool default_editable) -> bool
  {
    return gtk_text_buffer_delete_selection (
        gobj (),
        static_cast<int> (interactive),
        static_cast<int> (default_editable));
  }

  auto
  TextBuffer::get_selection_content () -> Glib::RefPtr<Gdk::ContentProvider>
  {
    return Glib::wrap (gtk_text_buffer_get_selection_content (gobj ()));
  }

  auto
  TextBuffer::select_range (const iterator& ins, const iterator& bound) -> void
  {
    gtk_text_buffer_select_range (gobj (), (ins).gobj (), (bound).gobj ());
  }

  auto
  TextBuffer::get_can_undo () const -> bool
  {
    return gtk_text_buffer_get_can_undo (const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::get_can_redo () const -> bool
  {
    return gtk_text_buffer_get_can_redo (const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::get_enable_undo () const -> bool
  {
    return gtk_text_buffer_get_enable_undo (
        const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::set_enable_undo (bool enable_undo) -> void
  {
    gtk_text_buffer_set_enable_undo (gobj (), static_cast<int> (enable_undo));
  }

  auto
  TextBuffer::get_max_undo_levels () const -> guint
  {
    return gtk_text_buffer_get_max_undo_levels (
        const_cast<GtkTextBuffer*> (gobj ()));
  }

  auto
  TextBuffer::set_max_undo_levels (guint max_undo_levels) -> void
  {
    gtk_text_buffer_set_max_undo_levels (gobj (), max_undo_levels);
  }

  auto
  TextBuffer::undo () -> void
  {
    gtk_text_buffer_undo (gobj ());
  }

  auto
  TextBuffer::redo () -> void
  {
    gtk_text_buffer_redo (gobj ());
  }

  auto
  TextBuffer::begin_irreversible_action () -> void
  {
    gtk_text_buffer_begin_irreversible_action (gobj ());
  }

  auto
  TextBuffer::end_irreversible_action () -> void
  {
    gtk_text_buffer_end_irreversible_action (gobj ());
  }

  auto
  TextBuffer::begin_user_action () -> void
  {
    gtk_text_buffer_begin_user_action (gobj ());
  }

  auto
  TextBuffer::end_user_action () -> void
  {
    gtk_text_buffer_end_user_action (gobj ());
  }

  auto
  TextBuffer::signal_insert () -> Glib::SignalProxy<
      void (TextBuffer::iterator&, const Glib::ustring&, int)>
  {
    return Glib::SignalProxy<
        void (TextBuffer::iterator&, const Glib::ustring&, int)> (
        this,
        &TextBuffer_signal_insert_info);
  }

  auto
  TextBuffer::signal_insert_paintable () -> Glib::SignalProxy<void (TextBuffer::iterator&,
                                 const Glib::RefPtr<Gdk::Paintable>&)>
  {
    return Glib::SignalProxy<void (TextBuffer::iterator&,
                                   const Glib::RefPtr<Gdk::Paintable>&)> (
        this,
        &TextBuffer_signal_insert_paintable_info);
  }

  auto
  TextBuffer::signal_insert_child_anchor () -> Glib::SignalProxy<void (TextBuffer::iterator&,
                                 const Glib::RefPtr<ChildAnchor>&)>
  {
    return Glib::SignalProxy<void (TextBuffer::iterator&,
                                   const Glib::RefPtr<ChildAnchor>&)> (
        this,
        &TextBuffer_signal_insert_child_anchor_info);
  }

  auto
  TextBuffer::signal_erase () -> Glib::SignalProxy<void (TextBuffer::iterator&, TextBuffer::iterator&)>
  {
    return Glib::SignalProxy<void (TextBuffer::iterator&,
                                   TextBuffer::iterator&)> (
        this,
        &TextBuffer_signal_erase_info);
  }

  auto
  TextBuffer::signal_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &TextBuffer_signal_changed_info);
  }

  auto
  TextBuffer::signal_modified_changed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &TextBuffer_signal_modified_changed_info);
  }

  auto
  TextBuffer::signal_mark_set () -> Glib::SignalProxy<void (const TextBuffer::iterator&,
                                 const Glib::RefPtr<TextBuffer::Mark>&)>
  {
    return Glib::SignalProxy<void (const TextBuffer::iterator&,
                                   const Glib::RefPtr<TextBuffer::Mark>&)> (
        this,
        &TextBuffer_signal_mark_set_info);
  }

  auto
  TextBuffer::signal_mark_deleted () -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Mark>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Mark>&)> (
        this,
        &TextBuffer_signal_mark_deleted_info);
  }

  auto
  TextBuffer::signal_apply_tag () -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                 const TextBuffer::iterator&,
                                 const TextBuffer::iterator&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                   const TextBuffer::iterator&,
                                   const TextBuffer::iterator&)> (
        this,
        &TextBuffer_signal_apply_tag_info);
  }

  auto
  TextBuffer::signal_remove_tag () -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                 const TextBuffer::iterator&,
                                 const TextBuffer::iterator&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                   const TextBuffer::iterator&,
                                   const TextBuffer::iterator&)> (
        this,
        &TextBuffer_signal_remove_tag_info);
  }

  auto
  TextBuffer::signal_begin_user_action () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (
        this,
        &TextBuffer_signal_begin_user_action_info);
  }

  auto
  TextBuffer::signal_end_user_action () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &TextBuffer_signal_end_user_action_info);
  }

  auto
  TextBuffer::signal_paste_done () -> Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Clipboard>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Clipboard>&)> (
        this,
        &TextBuffer_signal_paste_done_info);
  }

  auto
  TextBuffer::signal_redo () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &TextBuffer_signal_redo_info);
  }

  auto
  TextBuffer::signal_undo () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &TextBuffer_signal_undo_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TextBuffer::TagTable>>::value,
      "Type Glib::RefPtr<TextBuffer::TagTable> cannot be used in "
      "_WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextBuffer::property_tag_table () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TextBuffer::TagTable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TextBuffer::TagTable>> (
        this,
        "tag-table");
  }

  auto
  TextBuffer::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text");
  }

  auto
  TextBuffer::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text");
  }

  auto
  TextBuffer::property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-selection");
  }

  auto
  TextBuffer::property_cursor_position () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "cursor-position");
  }

  auto
  TextBuffer::property_can_undo () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-undo");
  }

  auto
  TextBuffer::property_can_redo () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "can-redo");
  }

  auto
  TextBuffer::property_enable_undo () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-undo");
  }

  auto
  TextBuffer::property_enable_undo () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-undo");
  }

  auto
  Gtk::TextBuffer::on_insert (TextBuffer::iterator& pos,
                              const Glib::ustring& text,
                              int bytes) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->insert_text)
      (*base->insert_text) (gobj (), (pos).gobj (), text.c_str (), bytes);
  }

  auto
  Gtk::TextBuffer::on_insert_paintable (
      TextBuffer::iterator& pos,
      const Glib::RefPtr<Gdk::Paintable>& paintable) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->insert_paintable)
      (*base->insert_paintable) (gobj (),
                                 (pos).gobj (),
                                 Glib::unwrap (paintable));
  }

  auto
  Gtk::TextBuffer::on_insert_child_anchor (
      TextBuffer::iterator& pos,
      const Glib::RefPtr<ChildAnchor>& anchor) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->insert_child_anchor)
      (*base->insert_child_anchor) (gobj (),
                                    (pos).gobj (),
                                    Glib::unwrap (anchor));
  }

  auto
  Gtk::TextBuffer::on_erase (TextBuffer::iterator& range_start,
                             TextBuffer::iterator& range_end) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->delete_range)
      (*base->delete_range) (gobj (),
                             (range_start).gobj (),
                             (range_end).gobj ());
  }

  auto
  Gtk::TextBuffer::on_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj ());
  }

  auto
  Gtk::TextBuffer::on_modified_changed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->modified_changed)
      (*base->modified_changed) (gobj ());
  }

  auto
  Gtk::TextBuffer::on_mark_set (const TextBuffer::iterator& location,
                                const Glib::RefPtr<TextBuffer::Mark>& mark) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mark_set)
      (*base->mark_set) (gobj (), (location).gobj (), Glib::unwrap (mark));
  }

  auto
  Gtk::TextBuffer::on_mark_deleted (const Glib::RefPtr<TextBuffer::Mark>& mark) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->mark_deleted)
      (*base->mark_deleted) (gobj (), Glib::unwrap (mark));
  }

  auto
  Gtk::TextBuffer::on_apply_tag (const Glib::RefPtr<TextBuffer::Tag>& tag,
                                 const TextBuffer::iterator& range_begin,
                                 const TextBuffer::iterator& range_end) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->apply_tag)
      (*base->apply_tag) (gobj (),
                          Glib::unwrap (tag),
                          (range_begin).gobj (),
                          (range_end).gobj ());
  }

  auto
  Gtk::TextBuffer::on_remove_tag (const Glib::RefPtr<TextBuffer::Tag>& tag,
                                  const TextBuffer::iterator& range_begin,
                                  const TextBuffer::iterator& range_end) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->remove_tag)
      (*base->remove_tag) (gobj (),
                           Glib::unwrap (tag),
                           (range_begin).gobj (),
                           (range_end).gobj ());
  }

  auto
  Gtk::TextBuffer::on_begin_user_action () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->begin_user_action)
      (*base->begin_user_action) (gobj ());
  }

  auto
  Gtk::TextBuffer::on_end_user_action () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->end_user_action)
      (*base->end_user_action) (gobj ());
  }

  auto
  Gtk::TextBuffer::on_paste_done (const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->paste_done)
      (*base->paste_done) (gobj (), Glib::unwrap (clipboard));
  }

  auto
  Gtk::TextBuffer::on_redo () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->redo)
      (*base->redo) (gobj ());
  }

  auto
  Gtk::TextBuffer::on_undo () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->undo)
      (*base->undo) (gobj ());
  }

} // namespace Gtk
