// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/entry.hxx>
#include <libmm/gtk/entry_p.hxx>

#include <gtk/gtk.h>

using IconPosition = gtk::Entry::IconPosition;

namespace gtk
{

  auto
  Entry::set_icon_from_icon_name (const glib::ustring& icon_name,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_icon_name (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        icon_name.c_str ());
  }

  auto
  Entry::set_icon_from_gicon (const glib::RefPtr<gio::Icon>& icon,
                              IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_gicon (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)));
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
  Entry::set_icon_tooltip_text (const glib::ustring& tooltip,
                                IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_tooltip_text (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        tooltip.c_str ());
  }

  auto
  Entry::set_icon_tooltip_markup (const glib::ustring& tooltip,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_tooltip_markup (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        tooltip.c_str ());
  }

  auto
  Entry::get_icon_area (IconPosition icon_pos) const -> gdk::Rectangle
  {
    gdk::Rectangle result;
    gtk_entry_get_icon_area (const_cast<GtkEntry*> (gobj ()),
                             (GtkEntryIconPosition) icon_pos,
                             result.gobj ());
    return result;
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo Entry_signal_activate_info = {
      "activate",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static auto
  Entry_signal_icon_release_callback (GtkEntry* self,
                                      GtkEntryIconPosition p0,
                                      void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (IconPosition)>;

    auto obj = dynamic_cast<Entry*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<IconPosition> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Entry_signal_icon_release_info = {
      "icon-release",
      (GCallback) &Entry_signal_icon_release_callback,
      (GCallback) &Entry_signal_icon_release_callback};

  static auto
  Entry_signal_icon_press_callback (GtkEntry* self,
                                    GtkEntryIconPosition p0,
                                    void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (IconPosition)>;

    auto obj = dynamic_cast<Entry*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (static_cast<IconPosition> (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo Entry_signal_icon_press_info = {
      "icon-press",
      (GCallback) &Entry_signal_icon_press_callback,
      (GCallback) &Entry_signal_icon_press_callback};

} // namespace

auto
glib::Value<gtk::Entry::IconPosition>::value_type () -> GType
{
  return gtk_entry_icon_position_get_type ();
}

namespace glib
{

  auto
  wrap (GtkEntry* object, bool take_copy) -> gtk::Entry*
  {
    return dynamic_cast<gtk::Entry*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  Entry_Class::init () -> const glib::Class&
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
  Entry_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Entry ((GtkEntry*) (o)));
  }

  Entry::Entry (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Entry::Entry (GtkEntry* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Entry::Entry (Entry&& src) noexcept
    : gtk::Widget (std::move (src)),
      Editable (std::move (src)),
      CellEditable (std::move (src))
  {
  }

  auto
  Entry::operator= (Entry&& src) noexcept -> Entry&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (entry_class_.init ()))
  {
  }

  Entry::Entry (const glib::RefPtr<EntryBuffer>& buffer)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (entry_class_.init (),
                                          "buffer",
                                          glib::unwrap (buffer),
                                          nullptr))
  {
  }

  auto
  Entry::get_buffer () -> glib::RefPtr<EntryBuffer>
  {
    auto retvalue = glib::wrap (gtk_entry_get_buffer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_buffer () const -> glib::RefPtr<const EntryBuffer>
  {
    return const_cast<Entry*> (this)->get_buffer ();
  }

  auto
  Entry::set_buffer (const glib::RefPtr<EntryBuffer>& buffer) -> void
  {
    gtk_entry_set_buffer (gobj (), glib::unwrap (buffer));
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
  Entry::set_completion (const glib::RefPtr<EntryCompletion>& completion) -> void
  {
    gtk_entry_set_completion (gobj (), glib::unwrap (completion));
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Entry::get_completion () -> glib::RefPtr<EntryCompletion>
  {
    auto retvalue = glib::wrap (gtk_entry_get_completion (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  G_GNUC_END_IGNORE_DEPRECATIONS
#endif

#ifndef GTKMM_DISABLE_DEPRECATED
  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  Entry::get_completion () const -> glib::RefPtr<const EntryCompletion>
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
  Entry::get_placeholder_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_get_placeholder_text (const_cast<GtkEntry*> (gobj ())));
  }

  auto
  Entry::set_placeholder_text (const glib::ustring& text) -> void
  {
    gtk_entry_set_placeholder_text (gobj (), text.c_str ());
  }

  auto
  Entry::set_icon_from_paintable (const glib::RefPtr<gdk::Paintable>& paintable,
                                  IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_from_paintable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        glib::unwrap (paintable));
  }

  auto
  Entry::get_icon_storage_type (IconPosition icon_pos) const -> Image::Type
  {
    return static_cast<Image::Type> (gtk_entry_get_icon_storage_type (
        const_cast<GtkEntry*> (gobj ()),
        static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_paintable (IconPosition icon_pos) -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (gtk_entry_get_icon_paintable (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_icon_paintable (IconPosition icon_pos) const -> glib::RefPtr<const gdk::Paintable>
  {
    return const_cast<Entry*> (this)->get_icon_paintable (icon_pos);
  }

  auto
  Entry::get_icon_name (IconPosition icon_pos) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_entry_get_icon_name (const_cast<GtkEntry*> (gobj ()),
                                 static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_gicon (IconPosition icon_pos) -> glib::RefPtr<gio::Icon>
  {
    auto retvalue = glib::wrap (gtk_entry_get_icon_gicon (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos)));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_icon_gicon (IconPosition icon_pos) const -> glib::RefPtr<const gio::Icon>
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
  Entry::get_icon_tooltip_text (IconPosition icon_pos) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_entry_get_icon_tooltip_text (
            const_cast<GtkEntry*> (gobj ()),
            static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::get_icon_tooltip_markup (IconPosition icon_pos) const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_entry_get_icon_tooltip_markup (
            const_cast<GtkEntry*> (gobj ()),
            static_cast<GtkEntryIconPosition> (icon_pos)));
  }

  auto
  Entry::set_icon_drag_source (
      const glib::RefPtr<gdk::ContentProvider>& provider,
      gdk::DragAction actions,
      IconPosition icon_pos) -> void
  {
    gtk_entry_set_icon_drag_source (
        gobj (),
        static_cast<GtkEntryIconPosition> (icon_pos),
        glib::unwrap (provider),
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
  Entry::set_attributes (pango::AttrList& attrs) -> void
  {
    gtk_entry_set_attributes (gobj (), (attrs).gobj ());
  }

  auto
  Entry::get_attributes () const -> pango::AttrList
  {
    return pango::AttrList (
        (gtk_entry_get_attributes (const_cast<GtkEntry*> (gobj ()))));
  }

  auto
  Entry::set_tabs (const pango::TabArray& tabs) -> void
  {
    gtk_entry_set_tabs (gobj (), const_cast<pango::TabArray&> (tabs).gobj ());
  }

  auto
  Entry::get_tabs () const -> pango::TabArray
  {
    return pango::TabArray (
        (gtk_entry_get_tabs (const_cast<GtkEntry*> (gobj ()))));
  }

  auto
  Entry::grab_focus_without_selecting () -> void
  {
    gtk_entry_grab_focus_without_selecting (gobj ());
  }

  auto
  Entry::set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_entry_set_extra_menu (gobj (), glib::unwrap (model));
  }

  auto
  Entry::get_extra_menu () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_entry_get_extra_menu (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Entry::get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<Entry*> (this)->get_extra_menu ();
  }

  auto
  Entry::signal_activate () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &Entry_signal_activate_info);
  }

  auto
  Entry::signal_icon_release () -> glib::SignalProxy<void (IconPosition)>
  {
    return glib::SignalProxy<void (IconPosition)> (
        this,
        &Entry_signal_icon_release_info);
  }

  auto
  Entry::signal_icon_press () -> glib::SignalProxy<void (IconPosition)>
  {
    return glib::SignalProxy<void (IconPosition)> (
        this,
        &Entry_signal_icon_press_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<EntryBuffer>>::value,
      "Type glib::RefPtr<EntryBuffer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_buffer () -> glib::PropertyProxy<glib::RefPtr<EntryBuffer>>
  {
    return glib::PropertyProxy<glib::RefPtr<EntryBuffer>> (this, "buffer");
  }

  auto
  Entry::property_buffer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryBuffer>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryBuffer>> (this,
                                                                    "buffer");
  }

  auto
  Entry::property_max_length () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "max-length");
  }

  auto
  Entry::property_max_length () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "max-length");
  }

  auto
  Entry::property_visibility () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visibility");
  }

  auto
  Entry::property_visibility () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visibility");
  }

  auto
  Entry::property_has_frame () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  Entry::property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gunichar>::value,
      "Type gunichar cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_invisible_char () -> glib::PropertyProxy<gunichar>
  {
    return glib::PropertyProxy<gunichar> (this, "invisible-char");
  }

  auto
  Entry::property_invisible_char () const -> glib::PropertyProxy_ReadOnly<gunichar>
  {
    return glib::PropertyProxy_ReadOnly<gunichar> (this, "invisible-char");
  }

  auto
  Entry::property_invisible_char_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "invisible-char-set");
  }

  auto
  Entry::property_invisible_char_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "invisible-char-set");
  }

  auto
  Entry::property_activates_default () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  Entry::property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  auto
  Entry::property_scroll_offset () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "scroll-offset");
  }

  auto
  Entry::property_truncate_multiline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "truncate-multiline");
  }

  auto
  Entry::property_truncate_multiline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "truncate-multiline");
  }

  auto
  Entry::property_overwrite_mode () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "overwrite-mode");
  }

  auto
  Entry::property_overwrite_mode () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "overwrite-mode");
  }

  auto
  Entry::property_text_length () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "text-length");
  }

  auto
  Entry::property_progress_fraction () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "progress-fraction");
  }

  auto
  Entry::property_progress_fraction () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "progress-fraction");
  }

  auto
  Entry::property_progress_pulse_step () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "progress-pulse-step");
  }

  auto
  Entry::property_progress_pulse_step () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "progress-pulse-step");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_primary_icon_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (
        this,
        "primary-icon-paintable");
  }

  auto
  Entry::property_primary_icon_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (
        this,
        "primary-icon-paintable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_secondary_icon_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (
        this,
        "secondary-icon-paintable");
  }

  auto
  Entry::property_secondary_icon_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (
        this,
        "secondary-icon-paintable");
  }

  auto
  Entry::property_primary_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "primary-icon-name");
  }

  auto
  Entry::property_primary_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "primary-icon-name");
  }

  auto
  Entry::property_secondary_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "secondary-icon-name");
  }

  auto
  Entry::property_secondary_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "secondary-icon-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Icon>>::value,
      "Type glib::RefPtr<gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_primary_icon_gicon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Icon>> (this,
                                                         "primary-icon-gicon");
  }

  auto
  Entry::property_primary_icon_gicon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>> (
        this,
        "primary-icon-gicon");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Icon>>::value,
      "Type glib::RefPtr<gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_secondary_icon_gicon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Icon>> (
        this,
        "secondary-icon-gicon");
  }

  auto
  Entry::property_secondary_icon_gicon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>> (
        this,
        "secondary-icon-gicon");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
      "Type Image::Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_primary_icon_storage_type () const -> glib::PropertyProxy_ReadOnly<Image::Type>
  {
    return glib::PropertyProxy_ReadOnly<Image::Type> (
        this,
        "primary-icon-storage-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
      "Type Image::Type cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_secondary_icon_storage_type () const -> glib::PropertyProxy_ReadOnly<Image::Type>
  {
    return glib::PropertyProxy_ReadOnly<Image::Type> (
        this,
        "secondary-icon-storage-type");
  }

  auto
  Entry::property_primary_icon_activatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "primary-icon-activatable");
  }

  auto
  Entry::property_primary_icon_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-activatable");
  }

  auto
  Entry::property_secondary_icon_activatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "secondary-icon-activatable");
  }

  auto
  Entry::property_secondary_icon_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-activatable");
  }

  auto
  Entry::property_primary_icon_sensitive () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "primary-icon-sensitive");
  }

  auto
  Entry::property_primary_icon_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "primary-icon-sensitive");
  }

  auto
  Entry::property_secondary_icon_sensitive () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "secondary-icon-sensitive");
  }

  auto
  Entry::property_secondary_icon_sensitive () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-sensitive");
  }

  auto
  Entry::property_primary_icon_tooltip_text () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "primary-icon-tooltip-text");
  }

  auto
  Entry::property_primary_icon_tooltip_text () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-tooltip-text");
  }

  auto
  Entry::property_secondary_icon_tooltip_text () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "secondary-icon-tooltip-text");
  }

  auto
  Entry::property_secondary_icon_tooltip_text () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-tooltip-text");
  }

  auto
  Entry::property_primary_icon_tooltip_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "primary-icon-tooltip-markup");
  }

  auto
  Entry::property_primary_icon_tooltip_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "primary-icon-tooltip-markup");
  }

  auto
  Entry::property_secondary_icon_tooltip_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "secondary-icon-tooltip-markup");
  }

  auto
  Entry::property_secondary_icon_tooltip_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this,
                                               "secondary-icon-tooltip-markup");
  }

  auto
  Entry::property_im_module () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "im-module");
  }

  auto
  Entry::property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "im-module");
  }

  auto
  Entry::property_placeholder_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "placeholder-text");
  }

  auto
  Entry::property_placeholder_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "placeholder-text");
  }

#ifndef GTKMM_DISABLE_DEPRECATED

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<EntryCompletion>>::value,
      "Type glib::RefPtr<EntryCompletion> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_completion () -> glib::PropertyProxy<glib::RefPtr<EntryCompletion>>
  {
    return glib::PropertyProxy<glib::RefPtr<EntryCompletion>> (this,
                                                               "completion");
  }
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

  auto
  Entry::property_completion () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryCompletion>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryCompletion>> (
        this,
        "completion");
  }
#endif

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
      "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_input_purpose () -> glib::PropertyProxy<InputPurpose>
  {
    return glib::PropertyProxy<InputPurpose> (this, "input-purpose");
  }

  auto
  Entry::property_input_purpose () const -> glib::PropertyProxy_ReadOnly<InputPurpose>
  {
    return glib::PropertyProxy_ReadOnly<InputPurpose> (this, "input-purpose");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
      "Type InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_input_hints () -> glib::PropertyProxy<InputHints>
  {
    return glib::PropertyProxy<InputHints> (this, "input-hints");
  }

  auto
  Entry::property_input_hints () const -> glib::PropertyProxy_ReadOnly<InputHints>
  {
    return glib::PropertyProxy_ReadOnly<InputHints> (this, "input-hints");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::AttrList>::value,
      "Type pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return glib::PropertyProxy<pango::AttrList> (this, "attributes");
  }

  auto
  Entry::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return glib::PropertyProxy_ReadOnly<pango::AttrList> (this, "attributes");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<pango::TabArray>::value,
      "Type pango::TabArray cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_tabs () -> glib::PropertyProxy<pango::TabArray>
  {
    return glib::PropertyProxy<pango::TabArray> (this, "tabs");
  }

  auto
  Entry::property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>
  {
    return glib::PropertyProxy_ReadOnly<pango::TabArray> (this, "tabs");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Entry::property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "extra-menu");
  }

  auto
  Entry::property_extra_menu () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "extra-menu");
  }

  auto
  Entry::property_show_emoji_icon () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-emoji-icon");
  }

  auto
  Entry::property_show_emoji_icon () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-emoji-icon");
  }

  auto
  Entry::property_enable_emoji_completion () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enable-emoji-completion");
  }

  auto
  Entry::property_enable_emoji_completion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enable-emoji-completion");
  }

} // namespace gtk
