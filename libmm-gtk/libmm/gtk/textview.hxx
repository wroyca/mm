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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TextView_Class;
}
#endif

namespace gtk
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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::TextWindowType>
    : public glib::Value_Enum<gtk::TextWindowType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
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
    explicit TextView (const glib::ConstructParams& construct_params);
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
    explicit TextView (const glib::RefPtr<TextBuffer>& buffer);

    auto
    set_buffer (const glib::RefPtr<TextBuffer>& buffer) -> void;

    auto
    get_buffer () -> glib::RefPtr<TextBuffer>;

    auto
    get_buffer () const -> glib::RefPtr<const TextBuffer>;

    auto
    scroll_to (TextBuffer::iterator& iter, double within_margin = 0) -> bool;

    auto
    scroll_to (TextBuffer::iterator& iter,
               double within_margin,
               double xalign,
               double yalign) -> bool;

    auto
    scroll_to (const glib::RefPtr<TextBuffer::Mark>& mark,
               double within_margin = 0) -> void;

    auto
    scroll_to (const glib::RefPtr<TextBuffer::Mark>& mark,
               double within_margin,
               double xalign,
               double yalign) -> void;

    auto
    move_mark_onscreen (const glib::RefPtr<TextBuffer::Mark>& mark) -> bool;

    auto
    place_cursor_onscreen () -> bool;

    auto
    get_visible_rect (gdk::Rectangle& visible_rect) const -> void;

    auto
    set_cursor_visible (bool setting = true) -> void;

    auto
    get_cursor_visible () const -> bool;

    auto
    reset_cursor_blink () -> void;

    auto
    get_cursor_locations (const TextBuffer::const_iterator& iter,
                          gdk::Rectangle& strong,
                          gdk::Rectangle& weak) const -> void;

    auto
    get_cursor_locations (gdk::Rectangle& strong, gdk::Rectangle& weak) const
        -> void;

    auto
    get_iter_location (const TextBuffer::const_iterator& iter,
                       gdk::Rectangle& location) const -> void;

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
    im_context_filter_keypress (const glib::RefPtr<gdk::Event>& event) -> bool;

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
                         const glib::RefPtr<TextBuffer::ChildAnchor>& anchor)
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
    set_tabs (pango::TabArray& tabs) -> void;

    auto
    get_tabs () const -> pango::TabArray;

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
    set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    get_rtl_context () -> glib::RefPtr<pango::Context>;

    auto
    get_rtl_context () const -> glib::RefPtr<const pango::Context>;

    auto
    get_ltr_context () -> glib::RefPtr<pango::Context>;

    auto
    get_ltr_context () const -> glib::RefPtr<const pango::Context>;

    auto
    signal_set_anchor () -> glib::SignalProxy<void ()>;

    auto
    signal_insert_at_cursor ()
        -> glib::SignalProxy<void (const glib::ustring&)>;

    auto
    property_pixels_above_lines () -> glib::PropertyProxy<int>;

    auto
    property_pixels_above_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_below_lines () -> glib::PropertyProxy<int>;

    auto
    property_pixels_below_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_pixels_inside_wrap () -> glib::PropertyProxy<int>;

    auto
    property_pixels_inside_wrap () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_editable () -> glib::PropertyProxy<bool>;

    auto
    property_editable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> glib::PropertyProxy<WrapMode>;

    auto
    property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<WrapMode>;

    auto
    property_justification () -> glib::PropertyProxy<Justification>;

    auto
    property_justification () const
        -> glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_left_margin () -> glib::PropertyProxy<int>;

    auto
    property_left_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_right_margin () -> glib::PropertyProxy<int>;

    auto
    property_right_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_top_margin () -> glib::PropertyProxy<int>;

    auto
    property_top_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_bottom_margin () -> glib::PropertyProxy<int>;

    auto
    property_bottom_margin () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_indent () -> glib::PropertyProxy<int>;

    auto
    property_indent () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tabs () -> glib::PropertyProxy<pango::TabArray>;

    auto
    property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>;

    auto
    property_cursor_visible () -> glib::PropertyProxy<bool>;

    auto
    property_cursor_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_buffer () -> glib::PropertyProxy<glib::RefPtr<TextBuffer>>;

    auto
    property_buffer () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TextBuffer>>;

    auto
    property_overwrite () -> glib::PropertyProxy<bool>;

    auto
    property_overwrite () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_accepts_tab () -> glib::PropertyProxy<bool>;

    auto
    property_accepts_tab () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_im_module () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_input_purpose () -> glib::PropertyProxy<InputPurpose>;

    auto
    property_input_purpose () const
        -> glib::PropertyProxy_ReadOnly<InputPurpose>;

    auto
    property_input_hints () -> glib::PropertyProxy<InputHints>;

    auto
    property_input_hints () const -> glib::PropertyProxy_ReadOnly<InputHints>;

    auto
    property_monospace () -> glib::PropertyProxy<bool>;

    auto
    property_monospace () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

  public:
  public:
  protected:
    virtual auto
    on_set_anchor () -> void;

    virtual auto
    on_insert_at_cursor (const glib::ustring& str) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTextView* object, bool take_copy = false) -> gtk::TextView*;
} // namespace glib

#endif
