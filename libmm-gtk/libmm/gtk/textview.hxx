// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXTVIEW_H
#define _GTKMM_TEXTVIEW_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/textbuffer.hxx>
#include <libmm/gtk/textmark.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTextView = struct _GtkTextView;
using GtkTextViewClass = struct _GtkTextViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TextView_Class;
}
#endif

namespace Gtk
{

  enum class TextWindowType
  {
    WIDGET = 1,
    TEXT,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TextWindowType>
    : public Glib::Value_Enum<Gtk::TextWindowType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TextView : public Widget,
                             public Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TextView CppObjectType;
    typedef TextView_Class CppClassType;
    typedef GtkTextView BaseObjectType;
    typedef GtkTextViewClass BaseClassType;
#endif

    TextView (TextView&& src) noexcept;
    auto
    operator= (TextView&& src) noexcept -> TextView&;

    TextView (const TextView&) = delete;
    auto
    operator= (const TextView&) -> TextView& = delete;

    ~TextView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class TextView_Class;
    static CppClassType textview_class_;

  protected:
    explicit TextView (const Glib::ConstructParams& construct_params);
    explicit TextView (GtkTextView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTextView*
    {
      return reinterpret_cast<GtkTextView*> (gobject_);
    }

    auto
    gobj () const -> const GtkTextView*
    {
      return reinterpret_cast<GtkTextView*> (gobject_);
    }

  private:
  public:
    TextView ();
    explicit TextView (const Glib::RefPtr<TextBuffer>& buffer);

    auto
    set_buffer (const Glib::RefPtr<TextBuffer>& buffer) -> void;

    auto
    get_buffer () -> Glib::RefPtr<TextBuffer>;

    auto
    get_buffer () const -> Glib::RefPtr<const TextBuffer>;

    auto
    scroll_to (TextBuffer::iterator& iter, double within_margin = 0) -> bool;

    auto
    scroll_to (TextBuffer::iterator& iter,
               double within_margin,
               double xalign,
               double yalign) -> bool;

    auto
    scroll_to (const Glib::RefPtr<TextBuffer::Mark>& mark,
               double within_margin = 0) -> void;

    auto
    scroll_to (const Glib::RefPtr<TextBuffer::Mark>& mark,
               double within_margin,
               double xalign,
               double yalign) -> void;

    auto
    move_mark_onscreen (const Glib::RefPtr<TextBuffer::Mark>& mark) -> bool;

    auto
    place_cursor_onscreen () -> bool;

    auto
    get_visible_rect (Gdk::Rectangle& visible_rect) const -> void;

    auto
    set_cursor_visible (bool setting = true) -> void;

    auto
    get_cursor_visible () const -> bool;

    auto
    reset_cursor_blink () -> void;

    auto
    get_cursor_locations (const TextBuffer::const_iterator& iter,
                          Gdk::Rectangle& strong,
                          Gdk::Rectangle& weak) const -> void;

    auto
    get_cursor_locations (Gdk::Rectangle& strong, Gdk::Rectangle& weak) const
        -> void;

    auto
    get_iter_location (const TextBuffer::const_iterator& iter,
                       Gdk::Rectangle& location) const -> void;

    auto
    get_iter_at_location (TextBuffer::iterator& iter, int x, int y) -> bool;

    auto
    get_iter_at_location (TextBuffer::const_iterator& iter, int x, int y) const
        -> bool;

    auto
    get_iter_at_position (TextBuffer::iterator& iter,
                          int& trailing,
                          int x,
                          int y) -> bool;

    auto
    get_iter_at_position (TextBuffer::const_iterator& iter,
                          int& trailing,
                          int x,
                          int y) const -> bool;

    auto
    get_line_yrange (const TextBuffer::const_iterator& iter,
                     int& y,
                     int& height) const -> void;

    auto
    get_line_at_y (TextBuffer::iterator& target_iter, int y, int& line_top)
        -> void;

    auto
    get_line_at_y (TextBuffer::const_iterator& target_iter,
                   int y,
                   int& line_top) const -> void;

    auto
    buffer_to_window_coords (TextWindowType win,
                             int buffer_x,
                             int buffer_y,
                             int& window_x,
                             int& window_y) const -> void;

    auto
    window_to_buffer_coords (TextWindowType win,
                             int window_x,
                             int window_y,
                             int& buffer_x,
                             int& buffer_y) const -> void;

    auto
    forward_display_line (TextBuffer::iterator& iter) -> bool;

    auto
    backward_display_line (TextBuffer::iterator& iter) -> bool;

    auto
    forward_display_line_end (TextBuffer::iterator& iter) -> bool;

    auto
    backward_display_line_start (TextBuffer::iterator& iter) -> bool;

    auto
    starts_display_line (const TextBuffer::iterator& iter) -> bool;

    auto
    move_visually (TextBuffer::iterator& iter, int count) -> bool;

    auto
    im_context_filter_keypress (const Glib::RefPtr<Gdk::Event>& event) -> bool;

    auto
    reset_im_context () -> void;

    auto
    get_gutter (TextWindowType win) -> Widget*;

    auto
    get_gutter (TextWindowType win) const -> const Widget*;

    auto
    set_gutter (TextWindowType win, Widget& widget) -> void;

    auto
    unset_gutter (TextWindowType win) -> void;

    auto
    add_child_at_anchor (Widget& child,
                         const Glib::RefPtr<TextBuffer::ChildAnchor>& anchor)
        -> void;

    auto
    add_overlay (Widget& child, int xpos, int ypos) -> void;

    auto
    move_overlay (Widget& child, int xpos, int ypos) -> void;

    auto
    remove (Widget& child) -> void;

    auto
    set_wrap_mode (WrapMode wrap_mode) -> void;

    auto
    get_wrap_mode () const -> WrapMode;

    auto
    set_editable (bool setting = true) -> void;

    auto
    get_editable () const -> bool;

    auto
    set_pixels_above_lines (int pixels_above_lines) -> void;

    auto
    get_pixels_above_lines () const -> int;

    auto
    set_pixels_below_lines (int pixels_below_lines) -> void;

    auto
    get_pixels_below_lines () const -> int;

    auto
    set_pixels_inside_wrap (int pixels_inside_wrap) -> void;

    auto
    get_pixels_inside_wrap () const -> int;

    auto
    set_justification (Justification justification) -> void;

    auto
    get_justification () const -> Justification;

    auto
    set_left_margin (int left_margin) -> void;

    auto
    get_left_margin () const -> int;

    auto
    set_right_margin (int right_margin) -> void;

    auto
    get_right_margin () const -> int;

    auto
    set_top_margin (int top_margin) -> void;

    auto
    get_top_margin () const -> int;

    auto
    set_bottom_margin (int bottom_margin) -> void;

    auto
    get_bottom_margin () const -> int;

    auto
    set_indent (int indent) -> void;

    auto
    get_indent () const -> int;

    auto
    set_tabs (Pango::TabArray& tabs) -> void;

    auto
    get_tabs () const -> Pango::TabArray;

    auto
    set_overwrite (bool overwrite = true) -> void;

    auto
    get_overwrite () const -> bool;

    auto
    set_accepts_tab (bool accepts_tab = true) -> void;

    auto
    get_accepts_tab () const -> bool;

    auto
    set_input_purpose (InputPurpose purpose) -> void;

    auto
    get_input_purpose () const -> InputPurpose;

    auto
    set_input_hints (InputHints hints) -> void;

    auto
    get_input_hints () const -> InputHints;

    auto
    set_monospace (bool monospace = true) -> void;

    auto
    get_monospace () const -> bool;

    auto
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    get_rtl_context () -> Glib::RefPtr<Pango::Context>;

    auto
    get_rtl_context () const -> Glib::RefPtr<const Pango::Context>;

    auto
    get_ltr_context () -> Glib::RefPtr<Pango::Context>;

    auto
    get_ltr_context () const -> Glib::RefPtr<const Pango::Context>;

    auto
    signal_set_anchor () -> Glib::SignalProxy<void ()>;

    auto
    signal_insert_at_cursor ()
        -> Glib::SignalProxy<void (const Glib::ustring&)>;

    auto
    property_pixels_above_lines () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_above_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_below_lines () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_below_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_inside_wrap () -> Glib::PropertyProxy<int>;

    auto
    property_pixels_inside_wrap () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_editable () -> Glib::PropertyProxy<bool>;

    auto
    property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> Glib::PropertyProxy<WrapMode>;

    auto
    property_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<WrapMode>;

    auto
    property_justification () -> Glib::PropertyProxy<Justification>;

    auto
    property_justification () const
        -> Glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_left_margin () -> Glib::PropertyProxy<int>;

    auto
    property_left_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_right_margin () -> Glib::PropertyProxy<int>;

    auto
    property_right_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_top_margin () -> Glib::PropertyProxy<int>;

    auto
    property_top_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_bottom_margin () -> Glib::PropertyProxy<int>;

    auto
    property_bottom_margin () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_indent () -> Glib::PropertyProxy<int>;

    auto
    property_indent () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tabs () -> Glib::PropertyProxy<Pango::TabArray>;

    auto
    property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>;

    auto
    property_cursor_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_cursor_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_buffer () -> Glib::PropertyProxy<Glib::RefPtr<TextBuffer>>;

    auto
    property_buffer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TextBuffer>>;

    auto
    property_overwrite () -> Glib::PropertyProxy<bool>;

    auto
    property_overwrite () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepts_tab () -> Glib::PropertyProxy<bool>;

    auto
    property_accepts_tab () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_im_module () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_input_purpose () -> Glib::PropertyProxy<InputPurpose>;

    auto
    property_input_purpose () const
        -> Glib::PropertyProxy_ReadOnly<InputPurpose>;

    auto
    property_input_hints () -> Glib::PropertyProxy<InputHints>;

    auto
    property_input_hints () const -> Glib::PropertyProxy_ReadOnly<InputHints>;

    auto
    property_monospace () -> Glib::PropertyProxy<bool>;

    auto
    property_monospace () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

  public:
  public:
  protected:
    virtual auto
    on_set_anchor () -> void;

    virtual auto
    on_insert_at_cursor (const Glib::ustring& str) -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextView* object, bool take_copy = false) -> Gtk::TextView*;
} // namespace Glib

#endif