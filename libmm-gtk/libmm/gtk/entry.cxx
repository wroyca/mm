// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/entry.hxx>
#include <libmm/gtk/entry_p.hxx>

#include <gtk/gtk.h>

using IconPosition = Gtk::Entry::IconPosition;

namespace Gtk
{

  auto
  Entry::set_icon_from_icon_name (const Glib::ustring& icon_name,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_icon_name (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        icon_name.c_str ());
  }

  auto
  Entry::set_icon_from_gicon (const Glib::RefPtr<Gio::Icon>& icon,
                              IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_gicon (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (icon)));
  }

  auto
  Entry::unset_icon (IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_paintable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        nullptr);
  }

  auto
  Entry::set_icon_activatable (bool activatable, IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_activatable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        static_cast<int> (activatable));
  }

  auto
  Entry::set_icon_tooltip_text (const Glib::ustring& tooltip,
                                IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_tooltip_text (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        tooltip.c_str ());
  }

  auto
  Entry::set_icon_tooltip_markup (const Glib::ustring& tooltip,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_tooltip_markup (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        tooltip.c_str ());
  }

  auto
  Entry::get_icon_area (IconPosition icon_pos) const -> Gdk::Rectangle
  {
    Gdk::Rectangle result;
    gtk_entry_get_icon_area (const_cast<GtkEntry*> (gobj ()),
                             (GtkEntryIconPosition) icon_pos,
                             result.gobj ());
    return result;
  }

} // namespace Gtk

namespace
{

  static const Glib::SignalProxyInfo Entry_signal_activate_info = {
      "activate",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Entry_signal_icon_release_callback (GtkEntry* self,
                                      GtkEntryIconPosition p0,
                                      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (IconPosition)>;

    auto obj = dynamic_cast<Entry*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<IconPosition> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Entry_signal_icon_release_info = {
      "icon-release",
      (GCallback) &Entry_signal_icon_release_callback,
      (GCallback) &Entry_signal_icon_release_callback};

  static auto
  Entry_signal_icon_press_callback (GtkEntry* self,
                                    GtkEntryIconPosition p0,
                                    void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (IconPosition)>;

    auto obj = dynamic_cast<Entry*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<IconPosition> (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo Entry_signal_icon_press_info = {
      "icon-press",
      (GCallback) &Entry_signal_icon_press_callback,
      (GCallback) &Entry_signal_icon_press_callback};

} // namespace

auto
Glib::Value<Gtk::Entry::IconPosition>::value_type () -> GType
{
  return gtk_entry_icon_position_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkEntry* object, bool take_copy) -> Gtk::Entry*
  {
    return dynamic_cast<Gtk::Entry*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Entry_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Entry_Class::class_init_function;

      register_derived_type (gtk_entry_get_type ());

      Editable::add_interface (get_type ());
      CellEditable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  Entry_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Entry_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Entry ((GtkEntry*) (o)));
  }

  Entry::Entry (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Entry::Entry (GtkEntry* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Entry::Entry (Entry&& src) noexcept
    : Gtk::Widget (std::move (src)),
      Editable (std::move (src)),
      CellEditable (std::move (src))
  {
  }

  auto
  Entry::operator= (Entry&& src) noexcept -> Entry&
  {
    Gtk::Widget::operator= (std::move (src));
    Editable::operator= (std::move (src));
    CellEditable::operator= (std::move (src));
    return *this;
  }

  Entry::~Entry () noexcept
  {
    destroy_ ();
  }

  Entry::CppClassType Entry::entry_class_;

  auto
  Entry::get_type () -> GType
  {
    return entry_class_.init ().get_type ();
  }

  auto
  Entry::get_base_type () -> GType
  {
    return gtk_entry_get_type ();
  }

  Entry::Entry ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (entry_class_.init ()))
  {
  }

  Entry::Entry (const Glib::RefPtr<EntryBuffer>& buffer)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (entry_class_.init (),
                                          "buffer",
                                          Glib::unwrap (buffer),
                                          nullptr))
  {
  }

  auto
  Entry::get_buffer () -> Glib::RefPtr<EntryBuffer>
  {
    auto retvalue = Glib::wrap (gtk_entry_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_buffer () const -> Glib::RefPtr<const EntryBuffer>
  {
    return const_cast<Entry*> (this)->get_buffer ();
  }

  auto
  Entry::set_buffer (const Glib::RefPtr<EntryBuffer>& buffer) -> void
  {
    gtk_entry_set_buffer (gobj (), Glib::unwrap (buffer));
  }

  auto
  Entry::set_visibility (bool visible) -> void
  {
    gtk_entry_set_visibility (gobj (), static_cast<int> (visible));
  }

  auto
  Entry::get_visibility () const -> bool
  {
    return gtk_entry_get_visibility (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_invisible_char (gunichar ch) -> void
  {
    gtk_entry_set_invisible_char (gobj (), ch);
  }

  auto
  Entry::unset_invisible_char () -> void
  {
    gtk_entry_unset_invisible_char (gobj ());
  }

  auto
  Entry::get_invisible_char () const -> gunichar
  {
    return gtk_entry_get_invisible_char (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_has_frame (bool setting) -> void
  {
    gtk_entry_set_has_frame (gobj (), static_cast<int> (setting));
  }

  auto
  Entry::get_has_frame () const -> bool
  {
    return gtk_entry_get_has_frame (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_overwrite_mode (bool overwrite) -> void
  {
    gtk_entry_set_overwrite_mode (gobj (), static_cast<int> (overwrite));
  }

  auto
  Entry::get_overwrite_mode () const -> bool
  {
    return gtk_entry_get_overwrite_mode (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_max_length (int max) -> void
  {
    gtk_entry_set_max_length (gobj (), max);
  }

  auto
  Entry::get_max_length () const -> int
  {
    return gtk_entry_get_max_length (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::get_text_length () const -> guint16
  {
    return gtk_entry_get_text_length (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_activates_default (bool setting) -> void
  {
    gtk_entry_set_activates_default (gobj (), static_cast<int> (setting));
  }

  auto
  Entry::get_activates_default () const -> gboolean
  {
    return gtk_entry_get_activates_default (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_alignment (float xalign) -> void
  {
    gtk_entry_set_alignment (gobj (), xalign);
  }

  auto
  Entry::set_alignment (Align xalign) -> void
  {
    gtk_entry_set_alignment (gobj (), _gtkmm_align_float_from_enum (xalign));
  }

  auto
  Entry::get_alignment () const -> float
  {
    return gtk_entry_get_alignment (const_cast<GtkEntry*> (gobj ()));
  }

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Entry::set_completion (const Glib::RefPtr<EntryCompletion>& completion) -> void
  {
    gtk_entry_set_completion (gobj (), Glib::unwrap (completion));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Entry::get_completion () -> Glib::RefPtr<EntryCompletion>
  {
    auto retvalue = Glib::wrap (gtk_entry_get_completion (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Entry::get_completion () const -> Glib::RefPtr<const EntryCompletion>
  {
    return const_cast<Entry*> (this)->get_completion ();
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

  auto
  Entry::set_progress_fraction (double fraction) -> void
  {
    gtk_entry_set_progress_fraction (gobj (), fraction);
  }

  auto
  Entry::get_progress_fraction () const -> double
  {
    return gtk_entry_get_progress_fraction (const_cast<GtkEntry*> (gobj ()));
  }

  auto
  Entry::set_progress_pulse_step (double fraction) -> void
  {
    gtk_entry_set_progress_pulse_step (gobj (), fraction);
  }

  auto
  Entry::get_progress_pulse_step () -> double
  {
    return gtk_entry_get_progress_pulse_step (gobj ());
  }

  auto
  Entry::progress_pulse () -> void
  {
    gtk_entry_progress_pulse (gobj ());
  }

  auto
  Entry::get_placeholder_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_get_placeholder_text (const_cast<GtkEntry*> (gobj ())));
  }

  auto
  Entry::set_placeholder_text (const Glib::ustring& text) -> void
  {
    gtk_entry_set_placeholder_text (gobj (), text.c_str ());
  }

  auto
  Entry::set_icon_from_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_paintable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        Glib::unwrap (paintable));
  }

  auto
  Entry::get_icon_storage_type (IconPosition icon_pos) const -> Image::Type
  {
    return static_cast<Image::Type> (gtk_entry_get_icon_storage_type (
        const_cast<GtkEntry*> (gobj ()),
        static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_paintable (IconPosition icon_pos) -> Glib::RefPtr<Gdk::Paintable>
  {
    auto retvalue = Glib::wrap (gtk_entry_get_icon_paintable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_icon_paintable (IconPosition icon_pos) const -> Glib::RefPtr<const Gdk::Paintable>
  {
    return const_cast<Entry*> (this)->get_icon_paintable (icon_pos);
  }

  auto
  Entry::get_icon_name (IconPosition icon_pos) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_get_icon_name (const_cast<GtkEntry*> (gobj ()),
                                 static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_gicon (IconPosition icon_pos) -> Glib::RefPtr<Gio::Icon>
  {
    auto retvalue = Glib::wrap (gtk_entry_get_icon_gicon (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_icon_gicon (IconPosition icon_pos) const -> Glib::RefPtr<const Gio::Icon>
  {
    return const_cast<Entry*> (this)->get_icon_gicon (icon_pos);
  }

  auto
  Entry::get_icon_activatable (IconPosition icon_pos) const -> bool
  {
    return gtk_entry_get_icon_activatable (
        const_cast<GtkEntry*> (gobj ()),
        static_cast<GtkEntryIconPosition> (icon_pos));
  }

  auto
  Entry::set_icon_sensitive (IconPosition icon_pos, bool sensitive) -> void
  {
    gtk_entry_set_icon_sensitive (gobj (),
                                  static_cast<GtkEntryIconPosition> (icon_pos),
                                  static_cast<int> (sensitive));
  }

  auto
  Entry::get_icon_sensitive (IconPosition icon_pos) -> bool
  {
    return gtk_entry_get_icon_sensitive (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos));
  }

  auto
  Entry::get_icon_at_pos (int x, int y) const -> int
  {
    return gtk_entry_get_icon_at_pos (const_cast<GtkEntry*> (gobj ()), x, y);
  }

  auto
  Entry::get_icon_tooltip_text (IconPosition icon_pos) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_entry_get_icon_tooltip_text (
            const_cast<GtkEntry*> (gobj ()),
            static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_tooltip_markup (IconPosition icon_pos) const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_entry_get_icon_tooltip_markup (
            const_cast<GtkEntry*> (gobj ()),
            static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::set_icon_drag_source (
      const Glib::RefPtr<Gdk::ContentProvider>& provider,
      Gdk::DragAction actions,
      IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_drag_source (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        Glib::unwrap (provider),
        static_cast<GdkDragAction> (actions));
  }

  auto
  Entry::get_current_icon_drag_source () -> int
  {
    return gtk_entry_get_current_icon_drag_source (gobj ());
  }

  auto
  Entry::reset_im_context () -> void
  {
    gtk_entry_reset_im_context (gobj ());
  }

  auto
  Entry::set_input_purpose (InputPurpose purpose) -> void
  {
    gtk_entry_set_input_purpose (gobj (),
                                 static_cast<GtkInputPurpose> (purpose));
  }

  auto
  Entry::get_input_purpose () const -> InputPurpose
  {
    return static_cast<InputPurpose> (
        gtk_entry_get_input_purpose (const_cast<GtkEntry*> (gobj ())));
  }

  auto
  Entry::set_input_hints (InputHints hints) -> void
  {
    gtk_entry_set_input_hints (gobj (), static_cast<GtkInputHints> (hints));
  }

  auto
  Entry::get_input_hints () const -> InputHints
  {
    return static_cast<InputHints> (
        gtk_entry_get_input_hints (const_cast<GtkEntry*> (gobj ())));
  }

  auto
  Entry::set_attributes (Pango::AttrList& attrs) -> void
  {
    gtk_entry_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Entry::get_attributes () const -> Pango::AttrList
  {
    return Pango::AttrList (
        (gtk_entry_get_attributes (const_cast<GtkEntry*> (gobj ()))));
  }

  auto
  Entry::set_tabs (const Pango::TabArray& tabs) -> void
  {
    gtk_entry_set_tabs (gobj (), const_cast<Pango::TabArray&> (tabs).gobj ());
  }

  auto
  Entry::get_tabs () const -> Pango::TabArray
  {
    return Pango::TabArray (
        (gtk_entry_get_tabs (const_cast<GtkEntry*> (gobj ()))));
  }

  auto
  Entry::grab_focus_without_selecting () -> void
  {
    gtk_entry_grab_focus_without_selecting (gobj ());
  }

  auto
  Entry::set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_entry_set_extra_menu (gobj (), Glib::unwrap (model));
  }

  auto
  Entry::get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_entry_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<Entry*> (this)->get_extra_menu ();
  }

  auto
  Entry::signal_activate () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &Entry_signal_activate_info);
  }

  auto
  Entry::signal_icon_release () -> Glib::SignalProxy<void (IconPosition)>
  {
    return Glib::SignalProxy<void (IconPosition)> (
        this,
        &Entry_signal_icon_release_info);
  }

  auto
  Entry::signal_icon_press () -> Glib::SignalProxy<void (IconPosition)>
  {
    return Glib::SignalProxy<void (IconPosition)> (
        this,
        &Entry_signal_icon_press_info);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<EntryBuffer>>::value,
      "Type Glib::RefPtr<EntryBuffer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_buffer () -> Glib::PropertyProxy<Glib::RefPtr<EntryBuffer>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<EntryBuffer>> (this, "buffer");
  }

  auto
  Entry::property_buffer () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryBuffer>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryBuffer>> (this,
                                                                    "buffer");
  }

  auto
  Entry::property_max_length () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "max-length");
  }

  auto
  Entry::property_max_length () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "max-length");
  }

  auto
  Entry::property_visibility () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "visibility");
  }

  auto
  Entry::property_visibility () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "visibility");
  }

  auto
  Entry::property_has_frame () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  Entry::property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<gunichar>::value,
      "Type gunichar cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_invisible_char () -> Glib::PropertyProxy<gunichar>
  {
    return Glib::PropertyProxy<gunichar> (this, "invisible-char");
  }

  auto
  Entry::property_invisible_char () const -> Glib::PropertyProxy_ReadOnly<gunichar>
  {
    return Glib::PropertyProxy_ReadOnly<gunichar> (this, "invisible-char");
  }

  auto
  Entry::property_invisible_char_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "invisible-char-set");
  }

  auto
  Entry::property_invisible_char_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "invisible-char-set");
  }

  auto
  Entry::property_activates_default () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  Entry::property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  Entry::property_scroll_offset () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "scroll-offset");
  }

  auto
  Entry::property_truncate_multiline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "truncate-multiline");
  }

  auto
  Entry::property_truncate_multiline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "truncate-multiline");
  }

  auto
  Entry::property_overwrite_mode () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "overwrite-mode");
  }

  auto
  Entry::property_overwrite_mode () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "overwrite-mode");
  }

  auto
  Entry::property_text_length () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "text-length");
  }

  auto
  Entry::property_progress_fraction () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "progress-fraction");
  }

  auto
  Entry::property_progress_fraction () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "progress-fraction");
  }

  auto
  Entry::property_progress_pulse_step () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "progress-pulse-step");
  }

  auto
  Entry::property_progress_pulse_step () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "progress-pulse-step");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Paintable>>::value,
      "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_primary_icon_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "primary-icon-paintable");
  }

  auto
  Entry::property_primary_icon_paintable () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "primary-icon-paintable");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Paintable>>::value,
      "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_secondary_icon_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "secondary-icon-paintable");
  }

  auto
  Entry::property_secondary_icon_paintable () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "secondary-icon-paintable");
  }

  auto
  Entry::property_primary_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "primary-icon-name");
  }

  auto
  Entry::property_primary_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "primary-icon-name");
  }

  auto
  Entry::property_secondary_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "secondary-icon-name");
  }

  auto
  Entry::property_secondary_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "secondary-icon-name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_primary_icon_gicon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (this,
                                                         "primary-icon-gicon");
  }

  auto
  Entry::property_primary_icon_gicon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (
        this,
        "primary-icon-gicon");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_secondary_icon_gicon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (
        this,
        "secondary-icon-gicon");
  }

  auto
  Entry::property_secondary_icon_gicon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (
        this,
        "secondary-icon-gicon");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
      "Type Image::Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_primary_icon_storage_type () const -> Glib::PropertyProxy_ReadOnly<Image::Type>
  {
    return Glib::PropertyProxy_ReadOnly<Image::Type> (
        this,
        "primary-icon-storage-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
      "Type Image::Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_secondary_icon_storage_type () const -> Glib::PropertyProxy_ReadOnly<Image::Type>
  {
    return Glib::PropertyProxy_ReadOnly<Image::Type> (
        this,
        "secondary-icon-storage-type");
  }

  auto
  Entry::property_primary_icon_activatable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "primary-icon-activatable");
  }

  auto
  Entry::property_primary_icon_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-activatable");
  }

  auto
  Entry::property_secondary_icon_activatable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "secondary-icon-activatable");
  }

  auto
  Entry::property_secondary_icon_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-activatable");
  }

  auto
  Entry::property_primary_icon_sensitive () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "primary-icon-sensitive");
  }

  auto
  Entry::property_primary_icon_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "primary-icon-sensitive");
  }

  auto
  Entry::property_secondary_icon_sensitive () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "secondary-icon-sensitive");
  }

  auto
  Entry::property_secondary_icon_sensitive () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-sensitive");
  }

  auto
  Entry::property_primary_icon_tooltip_text () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "primary-icon-tooltip-text");
  }

  auto
  Entry::property_primary_icon_tooltip_text () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-tooltip-text");
  }

  auto
  Entry::property_secondary_icon_tooltip_text () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "secondary-icon-tooltip-text");
  }

  auto
  Entry::property_secondary_icon_tooltip_text () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-tooltip-text");
  }

  auto
  Entry::property_primary_icon_tooltip_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "primary-icon-tooltip-markup");
  }

  auto
  Entry::property_primary_icon_tooltip_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-tooltip-markup");
  }

  auto
  Entry::property_secondary_icon_tooltip_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "secondary-icon-tooltip-markup");
  }

  auto
  Entry::property_secondary_icon_tooltip_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-tooltip-markup");
  }

  auto
  Entry::property_im_module () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "im-module");
  }

  auto
  Entry::property_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "im-module");
  }

  auto
  Entry::property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "placeholder-text");
  }

  auto
  Entry::property_placeholder_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "placeholder-text");
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<EntryCompletion>>::value,
      "Type Glib::RefPtr<EntryCompletion> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_completion () -> Glib::PropertyProxy<Glib::RefPtr<EntryCompletion>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<EntryCompletion>> (this,
                                                               "completion");
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Entry::property_completion () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryCompletion>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryCompletion>> (
        this,
        "completion");
  }
#endif

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
      "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_input_purpose () -> Glib::PropertyProxy<InputPurpose>
  {
    return Glib::PropertyProxy<InputPurpose> (this, "input-purpose");
  }

  auto
  Entry::property_input_purpose () const -> Glib::PropertyProxy_ReadOnly<InputPurpose>
  {
    return Glib::PropertyProxy_ReadOnly<InputPurpose> (this, "input-purpose");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
      "Type InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_input_hints () -> Glib::PropertyProxy<InputHints>
  {
    return Glib::PropertyProxy<InputHints> (this, "input-hints");
  }

  auto
  Entry::property_input_hints () const -> Glib::PropertyProxy_ReadOnly<InputHints>
  {
    return Glib::PropertyProxy_ReadOnly<InputHints> (this, "input-hints");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
      "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_attributes () -> Glib::PropertyProxy<Pango::AttrList>
  {
    return Glib::PropertyProxy<Pango::AttrList> (this, "attributes");
  }

  auto
  Entry::property_attributes () const -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::AttrList> (this, "attributes");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
      "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_tabs () -> Glib::PropertyProxy<Pango::TabArray>
  {
    return Glib::PropertyProxy<Pango::TabArray> (this, "tabs");
  }

  auto
  Entry::property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::TabArray> (this, "tabs");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Entry::property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  Entry::property_extra_menu () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "extra-menu");
  }

  auto
  Entry::property_show_emoji_icon () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-emoji-icon");
  }

  auto
  Entry::property_show_emoji_icon () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-emoji-icon");
  }

  auto
  Entry::property_enable_emoji_completion () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-emoji-completion");
  }

  auto
  Entry::property_enable_emoji_completion () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-emoji-completion");
  }

} // namespace Gtk
