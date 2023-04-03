// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTBUFFER_H
#define _GTKMM_TEXTBUFFER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/clipboard.hxx>
#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/paintable.hxx>
#include <libmm/gtk/mm-gtkconfig.hxx>
#include <libmm/gtk/textchildanchor.hxx>
#include <libmm/gtk/textiter.hxx>
#include <libmm/gtk/textmark.hxx>
#include <libmm/gtk/texttagtable.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextBuffer = struct _GtkTextBuffer;
using GtkTextBufferClass = struct _GtkTextBufferClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TextBuffer_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TextBuffer : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TextBuffer;
    using CppClassType = TextBuffer_Class;
    using BaseObjectType = GtkTextBuffer;
    using BaseClassType = GtkTextBufferClass;

    TextBuffer (const TextBuffer&) = delete;
    auto
    operator= (const TextBuffer&) -> TextBuffer& = delete;

  private:
    friend class TextBuffer_Class;
    static CppClassType textbuffer_class_;

  protected:
    explicit TextBuffer (const Glib::ConstructParams& construct_params);
    explicit TextBuffer (GtkTextBuffer* castitem);

#endif

  public:
    TextBuffer (TextBuffer&& src) noexcept;
    auto
    operator= (TextBuffer&& src) noexcept -> TextBuffer&;

    ~TextBuffer () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextBuffer*
    {
      return reinterpret_cast<GtkTextBuffer*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextBuffer*
    {
      return reinterpret_cast<GtkTextBuffer*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTextBuffer*;

  private:
  public:
    typedef TextIter iterator;
    typedef TextConstIter const_iterator;
    typedef TextTag Tag;
    typedef TextTagTable TagTable;
    typedef TextMark Mark;
    typedef TextChildAnchor ChildAnchor;

  protected:
    TextBuffer ();
    explicit TextBuffer (const Glib::RefPtr<TagTable>& tag_table);

  public:
    static auto
    create () -> Glib::RefPtr<TextBuffer>;

    static auto
    create (const Glib::RefPtr<TagTable>& tag_table)
        -> Glib::RefPtr<TextBuffer>;

    auto
    get_line_count () const -> int;

    auto
    get_char_count () const -> int;

    auto
    size () const -> int;

    auto
    get_tag_table () -> Glib::RefPtr<TextBuffer::TagTable>;

    auto
    get_tag_table () const -> Glib::RefPtr<const TextBuffer::TagTable>;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    set_text (const char* text_begin, const char* text_end) -> void;

    auto
    insert (const iterator& pos, const Glib::ustring& text) -> iterator;

    auto
    insert (const iterator& pos, const char* text_begin, const char* text_end)
        -> iterator;

    auto
    insert_at_cursor (const Glib::ustring& text) -> void;

    auto
    insert_at_cursor (const char* text_begin, const char* text_end) -> void;

    auto
    insert_interactive (const iterator& pos,
                        const Glib::ustring& text,
                        bool default_editable = true)
        -> std::pair<iterator, bool>;

    auto
    insert_interactive (const iterator& pos,
                        const char* text_begin,
                        const char* text_end,
                        bool default_editable = true)
        -> std::pair<iterator, bool>;

    auto
    insert_interactive_at_cursor (const Glib::ustring& text,
                                  bool default_editable = true) -> bool;

    auto
    insert_interactive_at_cursor (const char* text_begin,
                                  const char* text_end,
                                  bool default_editable = true) -> bool;

    auto
    insert (const iterator& pos,
            const const_iterator& range_begin,
            const const_iterator& range_end) -> iterator;

    auto
    insert_interactive (const iterator& pos,
                        const const_iterator& range_begin,
                        const const_iterator& range_end,
                        bool default_editable = true)
        -> std::pair<iterator, bool>;

    auto
    insert_with_tag (const iterator& pos,
                     const Glib::ustring& text,
                     const Glib::RefPtr<Tag>& tag) -> iterator;
    auto
    insert_with_tag (const iterator& pos,
                     const char* text_begin,
                     const char* text_end,
                     const Glib::RefPtr<Tag>& tag) -> iterator;

    auto
    insert_with_tag (const iterator& pos,
                     const Glib::ustring& text,
                     const Glib::ustring& tag_name) -> iterator;
    auto
    insert_with_tag (const iterator& pos,
                     const char* text_begin,
                     const char* text_end,
                     const Glib::ustring& tag_name) -> iterator;

    auto
    insert_with_tags (const iterator& pos,
                      const Glib::ustring& text,
                      const std::vector<Glib::RefPtr<Tag>>& tags) -> iterator;

    auto
    insert_with_tags (const iterator& pos,
                      const char* text_begin,
                      const char* text_end,
                      const std::vector<Glib::RefPtr<Tag>>& tags) -> iterator;

    auto
    insert_with_tags_by_name (const iterator& pos,
                              const Glib::ustring& text,
                              const std::vector<Glib::ustring>& tag_names)
        -> iterator;

    auto
    insert_with_tags_by_name (const iterator& pos,
                              const char* text_begin,
                              const char* text_end,
                              const std::vector<Glib::ustring>& tag_names)
        -> iterator;

    auto
    insert_markup (const iterator& pos, const Glib::ustring& markup)
        -> iterator;

    auto
    insert_markup (const iterator& pos,
                   const char* markup_begin,
                   const char* markup_end) -> iterator;

    auto
    erase (const iterator& range_begin, const iterator& range_end) -> iterator;

    auto
    erase_interactive (const iterator& range_begin,
                       const iterator& range_end,
                       bool default_editable = true)
        -> std::pair<iterator, bool>;

    auto
    backspace (const iterator& iter,
               bool interactive = true,
               bool default_editable = true) -> iterator;

    auto
    get_text (const const_iterator& range_start,
              const const_iterator& range_end,
              bool include_hidden_chars = true) const -> Glib::ustring;

    auto
    get_text (bool include_hidden_chars = true) const -> Glib::ustring;

    auto
    get_slice (const const_iterator& range_start,
               const const_iterator& range_end,
               bool include_hidden_chars = true) const -> Glib::ustring;

    auto
    insert_paintable (const iterator& pos,
                      const Glib::RefPtr<Gdk::Paintable>& paintable)
        -> iterator;

    auto
    insert_child_anchor (const iterator& pos,
                         const Glib::RefPtr<ChildAnchor>& anchor) -> iterator;

    auto
    create_child_anchor (const iterator& pos) -> Glib::RefPtr<ChildAnchor>;

    auto
    add_mark (const Glib::RefPtr<TextBuffer::Mark>& mark, const iterator& where)
        -> void;

    auto
    create_mark (const Glib::ustring& mark_name,
                 const iterator& where,
                 bool left_gravity = true) -> Glib::RefPtr<TextBuffer::Mark>;

    auto
    create_mark (const iterator& where, bool left_gravity = true)
        -> Glib::RefPtr<Mark>;

    auto
    move_mark (const Glib::RefPtr<Mark>& mark, const iterator& where) -> void;

    auto
    delete_mark (const Glib::RefPtr<Mark>& mark) -> void;

    auto
    get_mark (const Glib::ustring& name) -> Glib::RefPtr<TextBuffer::Mark>;

    auto
    get_mark (const Glib::ustring& name) const
        -> Glib::RefPtr<const TextBuffer::Mark>;

    auto
    move_mark_by_name (const Glib::ustring& name, const iterator& where)
        -> void;

    auto
    delete_mark_by_name (const Glib::ustring& name) -> void;

    auto
    get_insert () -> Glib::RefPtr<TextBuffer::Mark>;

    auto
    get_selection_bound () -> Glib::RefPtr<TextBuffer::Mark>;

    auto
    place_cursor (const iterator& where) -> void;

    auto
    apply_tag (const Glib::RefPtr<Tag>& tag,
               const iterator& range_start,
               const iterator& range_end) -> void;

    auto
    remove_tag (const Glib::RefPtr<Tag>& tag,
                const iterator& range_start,
                const iterator& range_end) -> void;

    auto
    apply_tag_by_name (const Glib::ustring& name,
                       const iterator& range_start,
                       const iterator& range_end) -> void;

    auto
    remove_tag_by_name (const Glib::ustring& name,
                        const iterator& range_start,
                        const iterator& range_end) -> void;

    auto
    remove_all_tags (const iterator& range_start, const iterator& range_end)
        -> void;

    auto
    create_tag (const Glib::ustring& tag_name) -> Glib::RefPtr<Tag>;

    auto
    create_tag () -> Glib::RefPtr<Tag>;

    auto
    get_iter_at_line_offset (int line_number, int char_offset) -> iterator;
    auto
    get_iter_at_line_offset (int line_number, int char_offset) const
        -> const_iterator;
    auto
    get_iter_at_line_index (int line_number, int byte_index) -> iterator;
    auto
    get_iter_at_line_index (int line_number, int byte_index) const
        -> const_iterator;
    auto
    get_iter_at_offset (int char_offset) -> iterator;
    auto
    get_iter_at_offset (int char_offset) const -> const_iterator;
    auto
    get_iter_at_line (int line_number) -> iterator;
    auto
    get_iter_at_line (int line_number) const -> const_iterator;
    auto
    begin () -> iterator;
    auto
    begin () const -> const_iterator;
    auto
    end () -> iterator;
    auto
    end () const -> const_iterator;
    auto
    get_bounds (iterator& range_begin, iterator& range_end) -> void;
    auto
    get_bounds (const_iterator& range_begin, const_iterator& range_end) const
        -> void;

    auto
    get_iter_at_mark (const Glib::RefPtr<Mark>& mark) -> iterator;

    auto
    get_iter_at_mark (const Glib::RefPtr<Mark>& mark) const -> const_iterator;

    auto
    get_iter_at_child_anchor (const Glib::RefPtr<ChildAnchor>& anchor)
        -> iterator;

    auto
    get_iter_at_child_anchor (const Glib::RefPtr<ChildAnchor>& anchor) const
        -> const_iterator;

    auto
    get_modified () const -> bool;

    auto
    set_modified (bool setting = true) -> void;

    auto
    get_has_selection () const -> bool;

    auto
    add_selection_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard)
        -> void;

    auto
    remove_selection_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard)
        -> void;

    auto
    cut_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                   bool default_editable = true) -> void;

    auto
    copy_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void;

    auto
    paste_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                     const iterator& override_location,
                     bool default_editable = true) -> void;

    auto
    paste_clipboard (const Glib::RefPtr<Gdk::Clipboard>& clipboard,
                     bool default_editable = true) -> void;

    auto
    get_selection_bounds (iterator& range_start, iterator& range_end) -> bool;

    auto
    get_selection_bounds (const_iterator& range_start,
                          const_iterator& range_end) const -> bool;

    auto
    erase_selection (bool interactive = true, bool default_editable = true)
        -> bool;

    auto
    get_selection_content () -> Glib::RefPtr<Gdk::ContentProvider>;

    auto
    select_range (const iterator& ins, const iterator& bound) -> void;

    auto
    get_can_undo () const -> bool;

    auto
    get_can_redo () const -> bool;

    auto
    get_enable_undo () const -> bool;

    auto
    set_enable_undo (bool enable_undo = true) -> void;

    auto
    get_max_undo_levels () const -> guint;

    auto
    set_max_undo_levels (guint max_undo_levels) -> void;

    auto
    undo () -> void;

    auto
    redo () -> void;

    auto
    begin_irreversible_action () -> void;

    auto
    end_irreversible_action () -> void;

    auto
    begin_user_action () -> void;

    auto
    end_user_action () -> void;

    auto
    signal_insert () -> Glib::SignalProxy<
        void (TextBuffer::iterator&, const Glib::ustring&, int)>;

    auto
    signal_insert_paintable ()
        -> Glib::SignalProxy<void (TextBuffer::iterator&,
                                   const Glib::RefPtr<Gdk::Paintable>&)>;

    auto
    signal_insert_child_anchor ()
        -> Glib::SignalProxy<void (TextBuffer::iterator&,
                                   const Glib::RefPtr<ChildAnchor>&)>;

    auto
    signal_erase () -> Glib::SignalProxy<void (TextBuffer::iterator&,
                                               TextBuffer::iterator&)>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_modified_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_mark_set ()
        -> Glib::SignalProxy<void (const TextBuffer::iterator&,
                                   const Glib::RefPtr<TextBuffer::Mark>&)>;

    auto
    signal_mark_deleted ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Mark>&)>;

    auto
    signal_apply_tag ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                   const TextBuffer::iterator&,
                                   const TextBuffer::iterator&)>;

    auto
    signal_remove_tag ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<TextBuffer::Tag>&,
                                   const TextBuffer::iterator&,
                                   const TextBuffer::iterator&)>;

    auto
    signal_begin_user_action () -> Glib::SignalProxy<void ()>;

    auto
    signal_end_user_action () -> Glib::SignalProxy<void ()>;

    auto
    signal_paste_done ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Clipboard>&)>;

    auto
    signal_redo () -> Glib::SignalProxy<void ()>;

    auto
    signal_undo () -> Glib::SignalProxy<void ()>;

    auto
    property_tag_table () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TextBuffer::TagTable>>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cursor_position () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_can_undo () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_redo () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_undo () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_undo () const -> Glib::PropertyProxy_ReadOnly<bool>;

  private:
    friend TextMark;

    auto
    get_iter_at_mark (GtkTextMark* mark) -> iterator;

  public:
  public:
  protected:
    virtual auto
    on_insert (TextBuffer::iterator& pos, const Glib::ustring& text, int bytes)
        -> void;

    virtual auto
    on_insert_paintable (TextBuffer::iterator& pos,
                         const Glib::RefPtr<Gdk::Paintable>& paintable) -> void;

    virtual auto
    on_insert_child_anchor (TextBuffer::iterator& pos,
                            const Glib::RefPtr<ChildAnchor>& anchor) -> void;

    virtual auto
    on_erase (TextBuffer::iterator& range_start,
              TextBuffer::iterator& range_end) -> void;

    virtual auto
    on_changed () -> void;

    virtual auto
    on_modified_changed () -> void;

    virtual auto
    on_mark_set (const TextBuffer::iterator& location,
                 const Glib::RefPtr<TextBuffer::Mark>& mark) -> void;

    virtual auto
    on_mark_deleted (const Glib::RefPtr<TextBuffer::Mark>& mark) -> void;

    virtual auto
    on_apply_tag (const Glib::RefPtr<TextBuffer::Tag>& tag,
                  const TextBuffer::iterator& range_begin,
                  const TextBuffer::iterator& range_end) -> void;

    virtual auto
    on_remove_tag (const Glib::RefPtr<TextBuffer::Tag>& tag,
                   const TextBuffer::iterator& range_begin,
                   const TextBuffer::iterator& range_end) -> void;

    virtual auto
    on_begin_user_action () -> void;

    virtual auto
    on_end_user_action () -> void;

    virtual auto
    on_paste_done (const Glib::RefPtr<Gdk::Clipboard>& clipboard) -> void;

    virtual auto
    on_redo () -> void;

    virtual auto
    on_undo () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextBuffer* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TextBuffer>;
} // namespace Glib

#endif
