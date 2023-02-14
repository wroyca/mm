

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/textview.hxx>
#include <libmm-gtk/textview_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace Gtk
{

  TextView::TextView (const Glib::RefPtr<TextBuffer>& buffer)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (textview_class_.init ()))
  {
    set_buffer (buffer);
  }

  auto
  TextView::scroll_to (TextBuffer::iterator& iter, const double within_margin) -> bool
  {
    return gtk_text_view_scroll_to_iter (gobj (),
                                         iter.gobj (),
                                         within_margin,
                                         FALSE,
                                         0.0,
                                         0.0);
  }

  auto
  TextView::scroll_to (TextBuffer::iterator& iter,
                       const double within_margin,
                       const double xalign,
                       const double yalign) -> bool
  {
    return gtk_text_view_scroll_to_iter (gobj (),
                                         iter.gobj (),
                                         within_margin,
                                         TRUE,
                                         xalign,
                                         yalign);
  }

  auto
  TextView::scroll_to (const Glib::RefPtr<TextBuffer::Mark>& mark,
                       const double within_margin) -> void
  {
    gtk_text_view_scroll_to_mark (gobj (),
                                  Glib::unwrap (mark),
                                  within_margin,
                                  FALSE,
                                  0.0,
                                  0.0);
  }

  auto
  TextView::scroll_to (const Glib::RefPtr<TextBuffer::Mark>& mark,
                       const double within_margin,
                       const double xalign,
                       const double yalign) -> void
  {
    gtk_text_view_scroll_to_mark (gobj (),
                                  Glib::unwrap (mark),
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

} // namespace Gtk

namespace
{

  const Glib::SignalProxyInfo TextView_signal_set_anchor_info = {
      "set_anchor",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  auto
  TextView_signal_insert_at_cursor_callback (GtkTextView* self,
                                             const gchar* p0,
                                             void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    const auto obj = dynamic_cast<TextView*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo TextView_signal_insert_at_cursor_info = {
      "insert_at_cursor",
      (GCallback) &TextView_signal_insert_at_cursor_callback,
      (GCallback) &TextView_signal_insert_at_cursor_callback};

} // namespace

auto
Glib::Value<Gtk::TextWindowType>::value_type () -> GType
{
  return gtk_text_window_type_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkTextView* object, const bool take_copy) -> Gtk::TextView*
  {
    return dynamic_cast<Gtk::TextView*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TextView_Class::init () -> const Class&
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

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
          Glib::exception_handlers_invoke ();
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_insert_at_cursor (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
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

    if (base && base->insert_at_cursor)
      (*base->insert_at_cursor) (self, p0);
  }

  auto
  TextView_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new TextView ((GtkTextView*) o));
  }

  TextView::TextView (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  TextView::TextView (GtkTextView* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  TextView::TextView (TextView&& src) noexcept
    : Widget (std::move (src)),
      Scrollable (std::move (src))
  {
  }

  auto
  TextView::operator= (TextView&& src) noexcept -> TextView&
  {
    Widget::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (textview_class_.init ()))
  {
  }

  auto
  TextView::set_buffer (const Glib::RefPtr<TextBuffer>& buffer) -> void
  {
    gtk_text_view_set_buffer (gobj (), Glib::unwrap (buffer));
  }

  auto
  TextView::get_buffer () -> Glib::RefPtr<TextBuffer>
  {
    auto retvalue = Glib::wrap (gtk_text_view_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_buffer () const -> Glib::RefPtr<const TextBuffer>
  {
    return const_cast<TextView*> (this)->get_buffer ();
  }

  auto
  TextView::move_mark_onscreen (const Glib::RefPtr<TextBuffer::Mark>& mark) -> bool
  {
    return gtk_text_view_move_mark_onscreen (gobj (), Glib::unwrap (mark));
  }

  auto
  TextView::place_cursor_onscreen () -> bool
  {
    return gtk_text_view_place_cursor_onscreen (gobj ());
  }

  auto
  TextView::get_visible_rect (Gdk::Rectangle& visible_rect) const -> void
  {
    gtk_text_view_get_visible_rect (const_cast<GtkTextView*> (gobj ()),
                                    visible_rect.gobj ());
  }

  auto
  TextView::set_cursor_visible (const bool setting) -> void
  {
    gtk_text_view_set_cursor_visible (gobj (), setting);
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
                                  Gdk::Rectangle& strong,
                                  Gdk::Rectangle& weak) const -> void
  {
    gtk_text_view_get_cursor_locations (const_cast<GtkTextView*> (gobj ()),
                                        iter.gobj (),
                                        strong.gobj (),
                                        weak.gobj ());
  }

  auto
  TextView::get_cursor_locations (Gdk::Rectangle& strong,
                                  Gdk::Rectangle& weak) const -> void
  {
    gtk_text_view_get_cursor_locations (const_cast<GtkTextView*> (gobj ()),
                                        nullptr,
                                        strong.gobj (),
                                        weak.gobj ());
  }

  auto
  TextView::get_iter_location (const TextBuffer::const_iterator& iter,
                               Gdk::Rectangle& location) const -> void
  {
    gtk_text_view_get_iter_location (const_cast<GtkTextView*> (gobj ()),
                                     iter.gobj (),
                                     location.gobj ());
  }

  auto
  TextView::get_iter_at_location (TextBuffer::iterator& iter,
                                  const int x,
                                  const int y) -> bool
  {
    return gtk_text_view_get_iter_at_location (gobj (), iter.gobj (), x, y);
  }

  auto
  TextView::get_iter_at_location (TextBuffer::const_iterator& iter,
                                  const int x,
                                  const int y) const -> bool
  {
    return gtk_text_view_get_iter_at_location (
        const_cast<GtkTextView*> (gobj ()),
        iter.gobj (),
        x,
        y);
  }

  auto
  TextView::get_iter_at_position (TextBuffer::iterator& iter,
                                  int& trailing,
                                  const int x,
                                  const int y) -> bool
  {
    return gtk_text_view_get_iter_at_position (gobj (),
                                               iter.gobj (),
                                               &trailing,
                                               x,
                                               y);
  }

  auto
  TextView::get_iter_at_position (TextBuffer::const_iterator& iter,
                                  int& trailing,
                                  const int x,
                                  const int y) const -> bool
  {
    return gtk_text_view_get_iter_at_position (
        const_cast<GtkTextView*> (gobj ()),
        iter.gobj (),
        &trailing,
        x,
        y);
  }

  auto
  TextView::get_line_yrange (const TextBuffer::const_iterator& iter,
                             int& y,
                             int& height) const -> void
  {
    gtk_text_view_get_line_yrange (const_cast<GtkTextView*> (gobj ()),
                                   iter.gobj (),
                                   &y,
                                   &height);
  }

  auto
  TextView::get_line_at_y (TextBuffer::iterator& target_iter,
                           const int y,
                           int& line_top) -> void
  {
    gtk_text_view_get_line_at_y (gobj (), target_iter.gobj (), y, &line_top);
  }

  auto
  TextView::get_line_at_y (TextBuffer::const_iterator& target_iter,
                           const int y,
                           int& line_top) const -> void
  {
    gtk_text_view_get_line_at_y (const_cast<GtkTextView*> (gobj ()),
                                 target_iter.gobj (),
                                 y,
                                 &line_top);
  }

  auto
  TextView::buffer_to_window_coords (TextWindowType win,
                                     const int buffer_x,
                                     const int buffer_y,
                                     int& window_x,
                                     int& window_y) const -> void
  {
    gtk_text_view_buffer_to_window_coords (const_cast<GtkTextView*> (gobj ()),
                                           static_cast<GtkTextWindowType> (win),
                                           buffer_x,
                                           buffer_y,
                                           &window_x,
                                           &window_y);
  }

  auto
  TextView::window_to_buffer_coords (TextWindowType win,
                                     const int window_x,
                                     const int window_y,
                                     int& buffer_x,
                                     int& buffer_y) const -> void
  {
    gtk_text_view_window_to_buffer_coords (const_cast<GtkTextView*> (gobj ()),
                                           static_cast<GtkTextWindowType> (win),
                                           window_x,
                                           window_y,
                                           &buffer_x,
                                           &buffer_y);
  }

  auto
  TextView::forward_display_line (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_forward_display_line (gobj (), iter.gobj ());
  }

  auto
  TextView::backward_display_line (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_backward_display_line (gobj (), iter.gobj ());
  }

  auto
  TextView::forward_display_line_end (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_forward_display_line_end (gobj (), iter.gobj ());
  }

  auto
  TextView::backward_display_line_start (TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_backward_display_line_start (gobj (), iter.gobj ());
  }

  auto
  TextView::starts_display_line (const TextBuffer::iterator& iter) -> bool
  {
    return gtk_text_view_starts_display_line (gobj (), iter.gobj ());
  }

  auto
  TextView::move_visually (TextBuffer::iterator& iter, const int count) -> bool
  {
    return gtk_text_view_move_visually (gobj (), iter.gobj (), count);
  }

  auto
  TextView::im_context_filter_keypress (const Glib::RefPtr<Gdk::Event>& event) -> bool
  {
    return gtk_text_view_im_context_filter_keypress (gobj (),
                                                     Glib::unwrap (event));
  }

  auto
  TextView::reset_im_context () -> void
  {
    gtk_text_view_reset_im_context (gobj ());
  }

  auto
  TextView::get_gutter (TextWindowType win) -> Widget*
  {
    return Glib::wrap (
        gtk_text_view_get_gutter (gobj (),
                                  static_cast<GtkTextWindowType> (win)));
  }

  auto
  TextView::get_gutter (const TextWindowType win) const -> const Widget*
  {
    return const_cast<TextView*> (this)->get_gutter (win);
  }

  auto
  TextView::set_gutter (TextWindowType win, Widget& widget) -> void
  {
    gtk_text_view_set_gutter (gobj (),
                              static_cast<GtkTextWindowType> (win),
                              widget.gobj ());
  }

  auto
  TextView::add_child_at_anchor (
      Widget& child,
      const Glib::RefPtr<TextBuffer::ChildAnchor>& anchor) -> void
  {
    gtk_text_view_add_child_at_anchor (gobj (),
                                       child.gobj (),
                                       Glib::unwrap (anchor));
  }

  auto
  TextView::add_overlay (Widget& child, const int xpos, const int ypos) -> void
  {
    gtk_text_view_add_overlay (gobj (), child.gobj (), xpos, ypos);
  }

  auto
  TextView::move_overlay (Widget& child, const int xpos, const int ypos) -> void
  {
    gtk_text_view_move_overlay (gobj (), child.gobj (), xpos, ypos);
  }

  auto
  TextView::remove (Widget& child) -> void
  {
    gtk_text_view_remove (gobj (), child.gobj ());
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
  TextView::set_editable (const bool setting) -> void
  {
    gtk_text_view_set_editable (gobj (), setting);
  }

  auto
  TextView::get_editable () const -> bool
  {
    return gtk_text_view_get_editable (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_pixels_above_lines (const int pixels_above_lines) -> void
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
  TextView::set_pixels_below_lines (const int pixels_below_lines) -> void
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
  TextView::set_pixels_inside_wrap (const int pixels_inside_wrap) -> void
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
  TextView::set_left_margin (const int left_margin) -> void
  {
    gtk_text_view_set_left_margin (gobj (), left_margin);
  }

  auto
  TextView::get_left_margin () const -> int
  {
    return gtk_text_view_get_left_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_right_margin (const int right_margin) -> void
  {
    gtk_text_view_set_right_margin (gobj (), right_margin);
  }

  auto
  TextView::get_right_margin () const -> int
  {
    return gtk_text_view_get_right_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_top_margin (const int top_margin) -> void
  {
    gtk_text_view_set_top_margin (gobj (), top_margin);
  }

  auto
  TextView::get_top_margin () const -> int
  {
    return gtk_text_view_get_top_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_bottom_margin (const int bottom_margin) -> void
  {
    gtk_text_view_set_bottom_margin (gobj (), bottom_margin);
  }

  auto
  TextView::get_bottom_margin () const -> int
  {
    return gtk_text_view_get_bottom_margin (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_indent (const int indent) -> void
  {
    gtk_text_view_set_indent (gobj (), indent);
  }

  auto
  TextView::get_indent () const -> int
  {
    return gtk_text_view_get_indent (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_tabs (Pango::TabArray& tabs) -> void
  {
    gtk_text_view_set_tabs (gobj (), tabs.gobj ());
  }

  auto
  TextView::get_tabs () const -> Pango::TabArray
  {
    return Pango::TabArray (
        gtk_text_view_get_tabs (const_cast<GtkTextView*> (gobj ())),
        false);
  }

  auto
  TextView::set_overwrite (const bool overwrite) -> void
  {
    gtk_text_view_set_overwrite (gobj (), overwrite);
  }

  auto
  TextView::get_overwrite () const -> bool
  {
    return gtk_text_view_get_overwrite (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_accepts_tab (const bool accepts_tab) -> void
  {
    gtk_text_view_set_accepts_tab (gobj (), accepts_tab);
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
  TextView::set_monospace (const bool monospace) -> void
  {
    gtk_text_view_set_monospace (gobj (), monospace);
  }

  auto
  TextView::get_monospace () const -> bool
  {
    return gtk_text_view_get_monospace (const_cast<GtkTextView*> (gobj ()));
  }

  auto
  TextView::set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_text_view_set_extra_menu (gobj (), Glib::unwrap (model));
  }

  auto
  TextView::get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_text_view_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<TextView*> (this)->get_extra_menu ();
  }

  auto
  TextView::get_rtl_context () -> Glib::RefPtr<Pango::Context>
  {
    auto retvalue = Glib::wrap (gtk_text_view_get_rtl_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_rtl_context () const -> Glib::RefPtr<const Pango::Context>
  {
    return const_cast<TextView*> (this)->get_rtl_context ();
  }

  auto
  TextView::get_ltr_context () -> Glib::RefPtr<Pango::Context>
  {
    auto retvalue = Glib::wrap (gtk_text_view_get_ltr_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TextView::get_ltr_context () const -> Glib::RefPtr<const Pango::Context>
  {
    return const_cast<TextView*> (this)->get_ltr_context ();
  }

  auto
  TextView::signal_set_anchor () -> Glib::SignalProxy<void ()>
  {
    return {this, &TextView_signal_set_anchor_info};
  }

  auto
  TextView::signal_insert_at_cursor () -> Glib::SignalProxy<void (const Glib::ustring&)>
  {
    return {this, &TextView_signal_insert_at_cursor_info};
  }

  auto
  TextView::property_pixels_above_lines () -> Glib::PropertyProxy<int>
  {
    return {this, "pixels-above-lines"};
  }

  auto
  TextView::property_pixels_above_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "pixels-above-lines"};
  }

  auto
  TextView::property_pixels_below_lines () -> Glib::PropertyProxy<int>
  {
    return {this, "pixels-below-lines"};
  }

  auto
  TextView::property_pixels_below_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "pixels-below-lines"};
  }

  auto
  TextView::property_pixels_inside_wrap () -> Glib::PropertyProxy<int>
  {
    return {this, "pixels-inside-wrap"};
  }

  auto
  TextView::property_pixels_inside_wrap () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "pixels-inside-wrap"};
  }

  auto
  TextView::property_editable () -> Glib::PropertyProxy<bool>
  {
    return {this, "editable"};
  }

  auto
  TextView::property_editable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "editable"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<WrapMode>::value,
      "Type WrapMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_wrap_mode () -> Glib::PropertyProxy<WrapMode>
  {
    return {this, "wrap-mode"};
  }

  auto
  TextView::property_wrap_mode () const -> Glib::PropertyProxy_ReadOnly<WrapMode>
  {
    return {this, "wrap-mode"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
      "Type Justification cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_justification () -> Glib::PropertyProxy<Justification>
  {
    return {this, "justification"};
  }

  auto
  TextView::property_justification () const -> Glib::PropertyProxy_ReadOnly<Justification>
  {
    return {this, "justification"};
  }

  auto
  TextView::property_left_margin () -> Glib::PropertyProxy<int>
  {
    return {this, "left-margin"};
  }

  auto
  TextView::property_left_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "left-margin"};
  }

  auto
  TextView::property_right_margin () -> Glib::PropertyProxy<int>
  {
    return {this, "right-margin"};
  }

  auto
  TextView::property_right_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "right-margin"};
  }

  auto
  TextView::property_top_margin () -> Glib::PropertyProxy<int>
  {
    return {this, "top-margin"};
  }

  auto
  TextView::property_top_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "top-margin"};
  }

  auto
  TextView::property_bottom_margin () -> Glib::PropertyProxy<int>
  {
    return {this, "bottom-margin"};
  }

  auto
  TextView::property_bottom_margin () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "bottom-margin"};
  }

  auto
  TextView::property_indent () -> Glib::PropertyProxy<int>
  {
    return {this, "indent"};
  }

  auto
  TextView::property_indent () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "indent"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
      "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_tabs () -> Glib::PropertyProxy<Pango::TabArray>
  {
    return {this, "tabs"};
  }

  auto
  TextView::property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>
  {
    return {this, "tabs"};
  }

  auto
  TextView::property_cursor_visible () -> Glib::PropertyProxy<bool>
  {
    return {this, "cursor-visible"};
  }

  auto
  TextView::property_cursor_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "cursor-visible"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TextBuffer>>::value,
      "Type Glib::RefPtr<TextBuffer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_buffer () -> Glib::PropertyProxy<Glib::RefPtr<TextBuffer>>
  {
    return {this, "buffer"};
  }

  auto
  TextView::property_buffer () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TextBuffer>>
  {
    return {this, "buffer"};
  }

  auto
  TextView::property_overwrite () -> Glib::PropertyProxy<bool>
  {
    return {this, "overwrite"};
  }

  auto
  TextView::property_overwrite () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "overwrite"};
  }

  auto
  TextView::property_accepts_tab () -> Glib::PropertyProxy<bool>
  {
    return {this, "accepts-tab"};
  }

  auto
  TextView::property_accepts_tab () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "accepts-tab"};
  }

  auto
  TextView::property_im_module () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "im-module"};
  }

  auto
  TextView::property_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "im-module"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
      "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_input_purpose () -> Glib::PropertyProxy<InputPurpose>
  {
    return {this, "input-purpose"};
  }

  auto
  TextView::property_input_purpose () const -> Glib::PropertyProxy_ReadOnly<InputPurpose>
  {
    return {this, "input-purpose"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
      "Type InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_input_hints () -> Glib::PropertyProxy<InputHints>
  {
    return {this, "input-hints"};
  }

  auto
  TextView::property_input_hints () const -> Glib::PropertyProxy_ReadOnly<InputHints>
  {
    return {this, "input-hints"};
  }

  auto
  TextView::property_monospace () -> Glib::PropertyProxy<bool>
  {
    return {this, "monospace"};
  }

  auto
  TextView::property_monospace () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "monospace"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TextView::property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "extra-menu"};
  }

  auto
  TextView::property_extra_menu () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "extra-menu"};
  }

  auto
  TextView::on_set_anchor () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->set_anchor)
      (*base->set_anchor) (gobj ());
  }

  auto
  TextView::on_insert_at_cursor (const Glib::ustring& str) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->insert_at_cursor)
      (*base->insert_at_cursor) (gobj (), str.c_str ());
  }

} // namespace Gtk
