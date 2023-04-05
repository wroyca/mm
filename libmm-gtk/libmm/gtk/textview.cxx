// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/textview.hxx>
#include <libmm/gtk/textview_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace gtk
{

  TextView::TextView (const glib::RefPtr<TextBuffer>& buffer)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (textview_class_.init ()))
  {
    set_buffer (buffer);
  }

  auto
  TextView::scroll_to (TextBuffer::iterator& iter, double within_margin) -> bool
  {
    return gtk_text_view_scroll_to_iter (gobj (),
                                         (iter).gobj (),
                                         within_margin,
                                         FALSE,
                                         0.0,
                                         0.0);
  }

  auto
  TextView::scroll_to (TextBuffer::iterator& iter,
                       double within_margin,
                       double xalign,
                       double yalign) -> bool
  {
    return gtk_text_view_scroll_to_iter (gobj (),
                                         (iter).gobj (),
                                         within_margin,
                                         TRUE,
                                         xalign,
                                         yalign);
  }

  auto
  TextView::scroll_to (const glib::RefPtr<TextBuffer::Mark>& mark,
                       double within_margin) -> void
  {
    gtk_text_view_scroll_to_mark (gobj (),
                                  glib::unwrap (mark),
                                  within_margin,
                                  FALSE,
                                  0.0,
                                  0.0);
  }

  auto
  TextView::scroll_to (const glib::RefPtr<TextBuffer::Mark>& mark,
                       double within_margin,
                       double xalign,
                       double yalign) -> void
  {
    gtk_text_view_scroll_to_mark (gobj (),
                                  glib::unwrap (mark),
                                  within_margin,
                                  TRUE,
                                  xalign,
                                  yalign);
  }

  auto
  TextView::unset_gutter (TextWindowType win) -> void
  {
    gtk_text_view_set_gutter (gobj (),
                              static_cast<GtkTextWindowType> (win),
                              nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo TextView_signal_set_anchor_info = {
      "set_anchor",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  TextView_signal_insert_at_cursor_callback (GtkTextView* self,
                                             const gchar* p0,
                                             void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<TextView*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo TextView_signal_insert_at_cursor_info = {
      "insert_at_cursor",
      (GCallback) &TextView_signal_insert_at_cursor_callback,
      (GCallback) &TextView_signal_insert_at_cursor_callback};

} // namespace

auto
glib::Value<gtk::TextWindowType>::value_type () -> GType
{
  return gtk_text_window_type_get_type ();
}

namespace glib
{

  auto
  wrap (GtkTextView* object, bool take_copy) -> gtk::TextView*
  {
    return dynamic_cast<gtk::TextView*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  TextView_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TextView_Class::class_init_function;

      register_derived_type (gtk_text_view_get_type ());

      Scrollable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  TextView_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->set_anchor = &set_anchor_callback;
    klass->insert_at_cursor = &insert_at_cursor_callback;
  }

  auto
  TextView_Class::set_anchor_callback (GtkTextView* self) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_set_anchor ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->set_anchor)
      (*base->set_anchor) (self);
  }

  auto
  TextView_Class::insert_at_cursor_callback (GtkTextView* self, const gchar* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert_at_cursor (
              glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->insert_at_cursor)
      (*base->insert_at_cursor) (self, p0);
  }

  auto
  TextView_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new TextView ((GtkTextView*) (o)));
  }

  TextView::TextView (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  TextView::TextView (GtkTextView* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  TextView::TextView (TextView&& src) noexcept
    : gtk::Widget (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  TextView::operator= (TextView&& src) noexcept -> TextView&
  {
    gtk::Widget::operator= (std::move (src));
    Scrollable::operator= (std::move (src));
    return *this;
  }

  TextView::~TextView () noexcept
  {
    destroy_ ();
  }

  TextView::CppClassType TextView::textview_class_;

  auto
  TextView::get_type () -> GType
  {
    return textview_class_.init ().get_type ();
  }

  auto
  TextView::get_base_type () -> GType
  {
    return gtk_text_view_get_type ();
  }

  TextView::TextView ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (textview_class_.init ()))
  {
  }

  auto
  TextView::set_buffer (const glib::RefPtr<TextBuffer>& buffer) -> void
  {
    gtk_text_view_set_buffer (gobj (), glib::unwrap (buffer));
  }

  auto
  TextView::get_buffer () -> glib::RefPtr<TextBuffer>
  {
    auto retvalue = glib::wrap (gtk_text_view_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_buffer () const -> glib::RefPtr<const TextBuffer>
  {
    return const_cast<TextView*> (this)->get_buffer ();
  }

  auto
  TextView::move_mark_onscreen (const glib::RefPtr<TextBuffer::Mark>& mark) -> bool
  {
    return gtk_text_view_move_mark_onscreen (gobj (), glib::unwrap (mark));
  }

  auto
  TextView::place_cursor_onscreen () -> bool
  {
    return gtk_text_view_place_cursor_onscreen (gobj ());
  }

  auto
  TextView::get_visible_rect (gdk::Rectangle& visible_rect) const -> void
  {
    gtk_text_view_get_visible_rect (const_cast<GtkTextView*> (gobj ()),
                                    (visible_rect).gobj ());
  }

  auto
  TextView::set_cursor_visible (bool setting) -> void
  {
    gtk_text_view_set_cursor_visible (gobj (), static_cast<int> (setting));
  }

  auto
  TextView::get_cursor_visible () const -> bool
  {
    return gtk_text_view_get_cursor_visible (
        const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::reset_cursor_blink () -> void
  {
    gtk_text_view_reset_cursor_blink (gobj ());
  }

  auto
  TextView::get_cursor_locations (const TextBuffer::const_iterator& iter,
                                  gdk::Rectangle& strong,
                                  gdk::Rectangle& weak) const -> void
  {
    gtk_text_view_get_cursor_locations (const_cast<GtkTextView*> (gobj ()),
                                        (iter).gobj (),
                                        (strong).gobj (),
                                        (weak).gobj ());
  }

  auto
  TextView::get_cursor_locations (gdk::Rectangle& strong,
                                  gdk::Rectangle& weak) const -> void
  {
    gtk_text_view_get_cursor_locations (const_cast<GtkTextView*> (gobj ()),
                                        nullptr,
                                        (strong).gobj (),
                                        (weak).gobj ());
  }

  auto
  TextView::get_iter_location (const TextBuffer::const_iterator& iter,
                               gdk::Rectangle& location) const -> void
  {
    gtk_text_view_get_iter_location (const_cast<GtkTextView*> (gobj ()),
                                     (iter).gobj (),
                                     (location).gobj ());
  }

  auto
  TextView::get_iter_at_location (TextBuffer::iterator& iter, int x, int y) -> bool
  {
    return gtk_text_view_get_iter_at_location (gobj (), (iter).gobj (), x, y);
  }

  auto
  TextView::get_iter_at_location (TextBuffer::const_iterator& iter,
                                  int x,
                                  int y) const -> bool
  {
    return gtk_text_view_get_iter_at_location (
        const_cast<GtkTextView*> (gobj ()),
        (iter).gobj (),
        x,
        y);
  }

  auto
  TextView::get_iter_at_position (TextBuffer::iterator& iter,
                                  int& trailing,
                                  int x,
                                  int y) -> bool
  {
    return gtk_text_view_get_iter_at_position (gobj (),
                                               (iter).gobj (),
                                               &(trailing),
                                               x,
                                               y);
  }

  auto
  TextView::get_iter_at_position (TextBuffer::const_iterator& iter,
                                  int& trailing,
                                  int x,
                                  int y) const -> bool
  {
    return gtk_text_view_get_iter_at_position (
        const_cast<GtkTextView*> (gobj ()),
        (iter).gobj (),
        &(trailing),
        x,
        y);
  }

  auto
  TextView::get_line_yrange (const TextBuffer::const_iterator& iter,
                             int& y,
                             int& height) const -> void
  {
    gtk_text_view_get_line_yrange (const_cast<GtkTextView*> (gobj ()),
                                   (iter).gobj (),
                                   &(y),
                                   &(height));
  }

  auto
  TextView::get_line_at_y (TextBuffer::iterator& target_iter,
                           int y,
                           int& line_top) -> void
  {
    gtk_text_view_get_line_at_y (gobj (),
                                 (target_iter).gobj (),
                                 y,
                                 &(line_top));
  }

  auto
  TextView::get_line_at_y (TextBuffer::const_iterator& target_iter,
                           int y,
                           int& line_top) const -> void
  {
    gtk_text_view_get_line_at_y (const_cast<GtkTextView*> (gobj ()),
                                 (target_iter).gobj (),
                                 y,
                                 &(line_top));
  }

  auto
  TextView::buffer_to_window_coords (TextWindowType win,
                                     int buffer_x,
                                     int buffer_y,
                                     int& window_x,
                                     int& window_y) const -> void
  {
    gtk_text_view_buffer_to_window_coords (const_cast<GtkTextView*> (gobj ()),
                                           static_cast<GtkTextWindowType> (win),
                                           buffer_x,
                                           buffer_y,
                                           &(window_x),
                                           &(window_y));
  }

  auto
  TextView::window_to_buffer_coords (TextWindowType win,
                                     int window_x,
                                     int window_y,
                                     int& buffer_x,
                                     int& buffer_y) const -> void
  {
    gtk_text_view_window_to_buffer_coords (const_cast<GtkTextView*> (gobj ()),
                                           static_cast<GtkTextWindowType> (win),
                                           window_x,
                                           window_y,
                                           &(buffer_x),
                                           &(buffer_y));
  }

  auto
  TextView::forward_display_line (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_forward_display_line (gobj (), (iter).gobj ());
  }

  auto
  TextView::backward_display_line (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_backward_display_line (gobj (), (iter).gobj ());
  }

  auto
  TextView::forward_display_line_end (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_forward_display_line_end (gobj (), (iter).gobj ());
  }

  auto
  TextView::backward_display_line_start (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_backward_display_line_start (gobj (), (iter).gobj ());
  }

  auto
  TextView::starts_display_line (const TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_starts_display_line (gobj (), (iter).gobj ());
  }

  auto
  TextView::move_visually (TextBuffer::iterator& iter, int count) -> bool
  {
    return gtk_text_view_move_visually (gobj (), (iter).gobj (), count);
  }

  auto
  TextView::im_context_filter_keypress (const glib::RefPtr<gdk::Event>& event) -> bool
  {
    return gtk_text_view_im_context_filter_keypress (gobj (),
                                                     glib::unwrap (event));
  }

  auto
  TextView::reset_im_context () -> void
  {
    gtk_text_view_reset_im_context (gobj ());
  }

  auto
  TextView::get_gutter (TextWindowType win) -> Widget*
  {
    return glib::wrap (
        gtk_text_view_get_gutter (gobj (),
                                  static_cast<GtkTextWindowType> (win)));
  }

  auto
  TextView::get_gutter (TextWindowType win) const -> const Widget*
  {
    return const_cast<TextView*> (this)->get_gutter (win);
  }

  auto
  TextView::set_gutter (TextWindowType win, Widget& widget) -> void
  {
    gtk_text_view_set_gutter (gobj (),
                              static_cast<GtkTextWindowType> (win),
                              (widget).gobj ());
  }

  auto
  TextView::add_child_at_anchor (
      Widget& child,
      const glib::RefPtr<TextBuffer::ChildAnchor>& anchor) -> void
  {
    gtk_text_view_add_child_at_anchor (gobj (),
                                       (child).gobj (),
                                       glib::unwrap (anchor));
  }

  auto
  TextView::add_overlay (Widget& child, int xpos, int ypos) -> void
  {
    gtk_text_view_add_overlay (gobj (), (child).gobj (), xpos, ypos);
  }

  auto
  TextView::move_overlay (Widget& child, int xpos, int ypos) -> void
  {
    gtk_text_view_move_overlay (gobj (), (child).gobj (), xpos, ypos);
  }

  auto
  TextView::remove (Widget& child) -> void
  {
    gtk_text_view_remove (gobj (), (child).gobj ());
  }

  auto
  TextView::set_wrap_mode (WrapMode wrap_mode) -> void
  {
    gtk_text_view_set_wrap_mode (gobj (), static_cast<GtkWrapMode> (wrap_mode));
  }

  auto
  TextView::get_wrap_mode () const -> WrapMode
  {
    return static_cast<WrapMode> (
        gtk_text_view_get_wrap_mode (const_cast<GtkTextView*> (gobj ())));
  }

  auto
  TextView::set_editable (bool setting) -> void
  {
    gtk_text_view_set_editable (gobj (), static_cast<int> (setting));
  }

  auto
  TextView::get_editable () const -> bool
  {
    return gtk_text_view_get_editable (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_pixels_above_lines (int pixels_above_lines) -> void
  {
    gtk_text_view_set_pixels_above_lines (gobj (), pixels_above_lines);
  }

  auto
  TextView::get_pixels_above_lines () const -> int
  {
    return gtk_text_view_get_pixels_above_lines (
        const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_pixels_below_lines (int pixels_below_lines) -> void
  {
    gtk_text_view_set_pixels_below_lines (gobj (), pixels_below_lines);
  }

  auto
  TextView::get_pixels_below_lines () const -> int
  {
    return gtk_text_view_get_pixels_below_lines (
        const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_pixels_inside_wrap (int pixels_inside_wrap) -> void
  {
    gtk_text_view_set_pixels_inside_wrap (gobj (), pixels_inside_wrap);
  }

  auto
  TextView::get_pixels_inside_wrap () const -> int
  {
    return gtk_text_view_get_pixels_inside_wrap (
        const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_justification (Justification justification) -> void
  {
    gtk_text_view_set_justification (
        gobj (),
        static_cast<GtkJustification> (justification));
  }

  auto
  TextView::get_justification () const -> Justification
  {
    return static_cast<Justification> (
        gtk_text_view_get_justification (const_cast<GtkTextView*> (gobj ())));
  }

  auto
  TextView::set_left_margin (int left_margin) -> void
  {
    gtk_text_view_set_left_margin (gobj (), left_margin);
  }

  auto
  TextView::get_left_margin () const -> int
  {
    return gtk_text_view_get_left_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_right_margin (int right_margin) -> void
  {
    gtk_text_view_set_right_margin (gobj (), right_margin);
  }

  auto
  TextView::get_right_margin () const -> int
  {
    return gtk_text_view_get_right_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_top_margin (int top_margin) -> void
  {
    gtk_text_view_set_top_margin (gobj (), top_margin);
  }

  auto
  TextView::get_top_margin () const -> int
  {
    return gtk_text_view_get_top_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_bottom_margin (int bottom_margin) -> void
  {
    gtk_text_view_set_bottom_margin (gobj (), bottom_margin);
  }

  auto
  TextView::get_bottom_margin () const -> int
  {
    return gtk_text_view_get_bottom_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_indent (int indent) -> void
  {
    gtk_text_view_set_indent (gobj (), indent);
  }

  auto
  TextView::get_indent () const -> int
  {
    return gtk_text_view_get_indent (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_tabs (pango::TabArray& tabs) -> void
  {
    gtk_text_view_set_tabs (gobj (), (tabs).gobj ());
  }

  auto
  TextView::get_tabs () const -> pango::TabArray
  {
    return pango::TabArray (
        (gtk_text_view_get_tabs (const_cast<GtkTextView*> (gobj ()))),
        false);
  }

  auto
  TextView::set_overwrite (bool overwrite) -> void
  {
    gtk_text_view_set_overwrite (gobj (), static_cast<int> (overwrite));
  }

  auto
  TextView::get_overwrite () const -> bool
  {
    return gtk_text_view_get_overwrite (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_accepts_tab (bool accepts_tab) -> void
  {
    gtk_text_view_set_accepts_tab (gobj (), static_cast<int> (accepts_tab));
  }

  auto
  TextView::get_accepts_tab () const -> bool
  {
    return gtk_text_view_get_accepts_tab (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_input_purpose (InputPurpose purpose) -> void
  {
    gtk_text_view_set_input_purpose (gobj (),
                                     static_cast<GtkInputPurpose> (purpose));
  }

  auto
  TextView::get_input_purpose () const -> InputPurpose
  {
    return static_cast<InputPurpose> (
        gtk_text_view_get_input_purpose (const_cast<GtkTextView*> (gobj ())));
  }

  auto
  TextView::set_input_hints (InputHints hints) -> void
  {
    gtk_text_view_set_input_hints (gobj (), static_cast<GtkInputHints> (hints));
  }

  auto
  TextView::get_input_hints () const -> InputHints
  {
    return static_cast<InputHints> (
        gtk_text_view_get_input_hints (const_cast<GtkTextView*> (gobj ())));
  }

  auto
  TextView::set_monospace (bool monospace) -> void
  {
    gtk_text_view_set_monospace (gobj (), static_cast<int> (monospace));
  }

  auto
  TextView::get_monospace () const -> bool
  {
    return gtk_text_view_get_monospace (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_text_view_set_extra_menu (gobj (), glib::unwrap (model));
  }

  auto
  TextView::get_extra_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_text_view_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<TextView*> (this)->get_extra_menu ();
  }

  auto
  TextView::get_rtl_context () -> glib::RefPtr<pango::Context>
  {
    auto retvalue = glib::wrap (gtk_text_view_get_rtl_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_rtl_context () const -> glib::RefPtr<const pango::Context>
  {
    return const_cast<TextView*> (this)->get_rtl_context ();
  }

  auto
  TextView::get_ltr_context () -> glib::RefPtr<pango::Context>
  {
    auto retvalue = glib::wrap (gtk_text_view_get_ltr_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_ltr_context () const -> glib::RefPtr<const pango::Context>
  {
    return const_cast<TextView*> (this)->get_ltr_context ();
  }

  auto
  TextView::signal_set_anchor () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &TextView_signal_set_anchor_info);
  }

  auto
  TextView::signal_insert_at_cursor () -> glib::SignalProxy<void (const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&)> (
        this,
        &TextView_signal_insert_at_cursor_info);
  }

  auto
  TextView::property_pixels_above_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-above-lines");
  }

  auto
  TextView::property_pixels_above_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-above-lines");
  }

  auto
  TextView::property_pixels_below_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-below-lines");
  }

  auto
  TextView::property_pixels_below_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-below-lines");
  }

  auto
  TextView::property_pixels_inside_wrap () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pixels-inside-wrap");
  }

  auto
  TextView::property_pixels_inside_wrap () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pixels-inside-wrap");
  }

  auto
  TextView::property_editable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "editable");
  }

  auto
  TextView::property_editable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "editable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<WrapMode>::value,
      "Type WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_wrap_mode () -> glib::PropertyProxy<WrapMode>
  {
    return glib::PropertyProxy<WrapMode> (this, "wrap-mode");
  }

  auto
  TextView::property_wrap_mode () const -> glib::PropertyProxy_ReadOnly<WrapMode>
  {
    return glib::PropertyProxy_ReadOnly<WrapMode> (this, "wrap-mode");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_justification () -> glib::PropertyProxy<Justification>
  {
    return glib::PropertyProxy<Justification> (this, "justification");
  }

  auto
  TextView::property_justification () const -> glib::PropertyProxy_ReadOnly<Justification>
  {
    return glib::PropertyProxy_ReadOnly<Justification> (this, "justification");
  }

  auto
  TextView::property_left_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "left-margin");
  }

  auto
  TextView::property_left_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "left-margin");
  }

  auto
  TextView::property_right_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "right-margin");
  }

  auto
  TextView::property_right_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "right-margin");
  }

  auto
  TextView::property_top_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "top-margin");
  }

  auto
  TextView::property_top_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "top-margin");
  }

  auto
  TextView::property_bottom_margin () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "bottom-margin");
  }

  auto
  TextView::property_bottom_margin () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "bottom-margin");
  }

  auto
  TextView::property_indent () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "indent");
  }

  auto
  TextView::property_indent () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "indent");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::TabArray>::value,
      "Type pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_tabs () -> glib::PropertyProxy<pango::TabArray>
  {
    return glib::PropertyProxy<pango::TabArray> (this, "tabs");
  }

  auto
  TextView::property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>
  {
    return glib::PropertyProxy_ReadOnly<pango::TabArray> (this, "tabs");
  }

  auto
  TextView::property_cursor_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "cursor-visible");
  }

  auto
  TextView::property_cursor_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "cursor-visible");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<TextBuffer>>::value,
      "Type glib::RefPtr<TextBuffer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_buffer () -> glib::PropertyProxy<glib::RefPtr<TextBuffer>>
  {
    return glib::PropertyProxy<glib::RefPtr<TextBuffer>> (this, "buffer");
  }

  auto
  TextView::property_buffer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TextBuffer>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<TextBuffer>> (this,
                                                                   "buffer");
  }

  auto
  TextView::property_overwrite () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "overwrite");
  }

  auto
  TextView::property_overwrite () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "overwrite");
  }

  auto
  TextView::property_accepts_tab () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "accepts-tab");
  }

  auto
  TextView::property_accepts_tab () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "accepts-tab");
  }

  auto
  TextView::property_im_module () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "im-module");
  }

  auto
  TextView::property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "im-module");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
      "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_input_purpose () -> glib::PropertyProxy<InputPurpose>
  {
    return glib::PropertyProxy<InputPurpose> (this, "input-purpose");
  }

  auto
  TextView::property_input_purpose () const -> glib::PropertyProxy_ReadOnly<InputPurpose>
  {
    return glib::PropertyProxy_ReadOnly<InputPurpose> (this, "input-purpose");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
      "Type InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_input_hints () -> glib::PropertyProxy<InputHints>
  {
    return glib::PropertyProxy<InputHints> (this, "input-hints");
  }

  auto
  TextView::property_input_hints () const -> glib::PropertyProxy_ReadOnly<InputHints>
  {
    return glib::PropertyProxy_ReadOnly<InputHints> (this, "input-hints");
  }

  auto
  TextView::property_monospace () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "monospace");
  }

  auto
  TextView::property_monospace () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "monospace");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  TextView::property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  TextView::property_extra_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "extra-menu");
  }

  auto
  gtk::TextView::on_set_anchor () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->set_anchor)
      (*base->set_anchor) (gobj ());
  }

  auto
  gtk::TextView::on_insert_at_cursor (const glib::ustring& str) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->insert_at_cursor)
      (*base->insert_at_cursor) (gobj (), str.c_str ());
  }

} // namespace gtk
