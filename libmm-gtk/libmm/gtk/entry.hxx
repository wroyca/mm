// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRY_H
#define _GTKMM_ENTRY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/border.hxx>
#include <libmm/gtk/celleditable.hxx>
#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/entrybuffer.hxx>
#include <libmm/gtk/entrycompletion.hxx>
#include <libmm/gtk/image.hxx>
#include <libmm/gtk/widget.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntry = struct _GtkEntry;
using GtkEntryClass = struct _GtkEntryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Entry_Class;
}
#endif

namespace gtk
{

  class Entry : public Widget,
                public Editable,
                public CellEditable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Entry CppObjectType;
    typedef Entry_Class CppClassType;
    typedef GtkEntry BaseObjectType;
    typedef GtkEntryClass BaseClassType;
#endif

    Entry (Entry&& src) noexcept;
    auto
    operator= (Entry&& src) noexcept -> Entry&;

    Entry (const Entry&) = delete;
    auto
    operator= (const Entry&) -> Entry& = delete;

    ~Entry () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Entry_Class;
    static CppClassType entry_class_;

  protected:
    explicit Entry (const glib::ConstructParams& construct_params);
    explicit Entry (GtkEntry* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEntry*
    {
      return reinterpret_cast<GtkEntry*> (gobject_);
    }

    auto
    gobj () const -> const GtkEntry*
    {
      return reinterpret_cast<GtkEntry*> (gobject_);
    }

  private:
  public:
    enum class IconPosition
    {
      PRIMARY,
      SECONDARY
    };

    Entry ();
    explicit Entry (const glib::RefPtr<EntryBuffer>& buffer);

    auto
    get_buffer () -> glib::RefPtr<EntryBuffer>;

    auto
    get_buffer () const -> glib::RefPtr<const EntryBuffer>;

    auto
    set_buffer (const glib::RefPtr<EntryBuffer>& buffer) -> void;

    auto
    set_visibility (bool visible = true) -> void;

    auto
    get_visibility () const -> bool;

    auto
    set_invisible_char (gunichar ch) -> void;

    auto
    unset_invisible_char () -> void;

    auto
    get_invisible_char () const -> gunichar;

    auto
    set_has_frame (bool setting = true) -> void;

    auto
    get_has_frame () const -> bool;

    auto
    set_overwrite_mode (bool overwrite = true) -> void;

    auto
    get_overwrite_mode () const -> bool;

    auto
    set_max_length (int max) -> void;

    auto
    get_max_length () const -> int;

    auto
    get_text_length () const -> guint16;

    auto
    set_activates_default (bool setting = true) -> void;

    auto
    get_activates_default () const -> gboolean;

    auto
    set_alignment (float xalign) -> void;

    auto
    set_alignment (Align xalign) -> void;

    auto
    get_alignment () const -> float;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_completion (const glib::RefPtr<EntryCompletion>& completion) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_completion () -> glib::RefPtr<EntryCompletion>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_completion () const -> glib::RefPtr<const EntryCompletion>;
#endif

    auto
    set_progress_fraction (double fraction) -> void;

    auto
    get_progress_fraction () const -> double;

    auto
    set_progress_pulse_step (double fraction) -> void;

    auto
    get_progress_pulse_step () -> double;

    auto
    progress_pulse () -> void;

    auto
    get_placeholder_text () const -> glib::ustring;

    auto
    set_placeholder_text (const glib::ustring& text) -> void;

    auto
    set_icon_from_paintable (const glib::RefPtr<gdk::Paintable>& paintable,
                             IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    set_icon_from_icon_name (const glib::ustring& icon_name,
                             IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    set_icon_from_gicon (const glib::RefPtr<gio::Icon>& icon,
                         IconPosition icon_pos = IconPosition::PRIMARY) -> void;

    auto
    unset_icon (IconPosition icon_pos = IconPosition::PRIMARY) -> void;

    auto
    get_icon_storage_type (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Image::Type;

    auto
    get_icon_paintable (IconPosition icon_pos = IconPosition::PRIMARY)
        -> glib::RefPtr<gdk::Paintable>;

    auto
    get_icon_paintable (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> glib::RefPtr<const gdk::Paintable>;

    auto
    get_icon_name (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> glib::ustring;

    auto
    get_icon_gicon (IconPosition icon_pos = IconPosition::PRIMARY)
        -> glib::RefPtr<gio::Icon>;

    auto
    get_icon_gicon (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> glib::RefPtr<const gio::Icon>;

    auto
    set_icon_activatable (bool activatable = true,
                          IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    get_icon_activatable (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> bool;

    auto
    set_icon_sensitive (IconPosition icon_pos = IconPosition::PRIMARY,
                        bool sensitive = true) -> void;

    auto
    get_icon_sensitive (IconPosition icon_pos = IconPosition::PRIMARY) -> bool;

    auto
    get_icon_at_pos (int x, int y) const -> int;

    auto
    set_icon_tooltip_text (const glib::ustring& tooltip,
                           IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    get_icon_tooltip_text (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> glib::ustring;

    auto
    set_icon_tooltip_markup (const glib::ustring& tooltip,
                             IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    get_icon_tooltip_markup (
        IconPosition icon_pos = IconPosition::PRIMARY) const -> glib::ustring;

    auto
    set_icon_drag_source (const glib::RefPtr<gdk::ContentProvider>& provider,
                          gdk::DragAction actions = gdk::DragAction::COPY,
                          IconPosition icon_pos = IconPosition::PRIMARY)
        -> void;

    auto
    get_icon_area (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> gdk::Rectangle;

    auto
    get_current_icon_drag_source () -> int;

    auto
    reset_im_context () -> void;

    auto
    set_input_purpose (InputPurpose purpose) -> void;

    auto
    get_input_purpose () const -> InputPurpose;

    auto
    set_input_hints (InputHints hints) -> void;

    auto
    get_input_hints () const -> InputHints;

    auto
    set_attributes (pango::AttrList& attrs) -> void;

    auto
    get_attributes () const -> pango::AttrList;

    auto
    set_tabs (const pango::TabArray& tabs) -> void;

    auto
    get_tabs () const -> pango::TabArray;

    auto
    grab_focus_without_selecting () -> void;

    auto
    set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    signal_activate () -> glib::SignalProxy<void ()>;

    auto
    signal_icon_release () -> glib::SignalProxy<void (IconPosition)>;

    auto
    signal_icon_press () -> glib::SignalProxy<void (IconPosition)>;

    auto
    property_buffer () -> glib::PropertyProxy<glib::RefPtr<EntryBuffer>>;

    auto
    property_buffer () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryBuffer>>;

    auto
    property_max_length () -> glib::PropertyProxy<int>;

    auto
    property_max_length () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_visibility () -> glib::PropertyProxy<bool>;

    auto
    property_visibility () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_frame () -> glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_invisible_char () -> glib::PropertyProxy<gunichar>;

    auto
    property_invisible_char () const -> glib::PropertyProxy_ReadOnly<gunichar>;

    auto
    property_invisible_char_set () -> glib::PropertyProxy<bool>;

    auto
    property_invisible_char_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_activates_default () -> glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_offset () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_truncate_multiline () -> glib::PropertyProxy<bool>;

    auto
    property_truncate_multiline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overwrite_mode () -> glib::PropertyProxy<bool>;

    auto
    property_overwrite_mode () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_length () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_progress_fraction () -> glib::PropertyProxy<double>;

    auto
    property_progress_fraction () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_progress_pulse_step () -> glib::PropertyProxy<double>;

    auto
    property_progress_pulse_step () const
        -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_primary_icon_paintable ()
        -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_primary_icon_paintable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

    auto
    property_secondary_icon_paintable ()
        -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_secondary_icon_paintable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

    auto
    property_primary_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_primary_icon_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_secondary_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_secondary_icon_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_primary_icon_gicon ()
        -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_primary_icon_gicon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_secondary_icon_gicon ()
        -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_secondary_icon_gicon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_primary_icon_storage_type () const
        -> glib::PropertyProxy_ReadOnly<Image::Type>;

    auto
    property_secondary_icon_storage_type () const
        -> glib::PropertyProxy_ReadOnly<Image::Type>;

    auto
    property_primary_icon_activatable () -> glib::PropertyProxy<bool>;

    auto
    property_primary_icon_activatable () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_activatable () -> glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_activatable () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_sensitive () -> glib::PropertyProxy<bool>;

    auto
    property_primary_icon_sensitive () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_sensitive () -> glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_sensitive () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_tooltip_text () -> glib::PropertyProxy<bool>;

    auto
    property_primary_icon_tooltip_text () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_tooltip_text () -> glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_tooltip_text () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_tooltip_markup () -> glib::PropertyProxy<bool>;

    auto
    property_primary_icon_tooltip_markup () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_tooltip_markup () -> glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_tooltip_markup () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_im_module () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_placeholder_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_placeholder_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_completion ()
        -> glib::PropertyProxy<glib::RefPtr<EntryCompletion>>;

    auto
    property_completion () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<EntryCompletion>>;

#endif

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
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

    auto
    property_tabs () -> glib::PropertyProxy<pango::TabArray>;

    auto
    property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>;

    auto
    property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_show_emoji_icon () -> glib::PropertyProxy<bool>;

    auto
    property_show_emoji_icon () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_emoji_completion () -> glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Entry::IconPosition>
    : public glib::Value_Enum<gtk::Entry::IconPosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEntry* object, bool take_copy = false) -> gtk::Entry*;
} // namespace glib

#endif
