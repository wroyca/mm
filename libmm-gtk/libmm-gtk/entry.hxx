
#ifndef _GTKMM_ENTRY_H
#define _GTKMM_ENTRY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/border.hxx>
#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/entrybuffer.hxx>
#include <libmm-gtk/entrycompletion.hxx>
#include <libmm-gtk/image.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntry = struct _GtkEntry;
using GtkEntryClass = struct _GtkEntryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Entry_Class;
}
#endif

namespace Gtk
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
    friend GTKMM_API class Entry_Class;
    static CppClassType entry_class_;

  protected:
    explicit Entry (const Glib::ConstructParams& construct_params);
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
    explicit Entry (const Glib::RefPtr<EntryBuffer>& buffer);

    auto
    get_buffer () -> Glib::RefPtr<EntryBuffer>;

    auto
    get_buffer () const -> Glib::RefPtr<const EntryBuffer>;

    void
    set_buffer (const Glib::RefPtr<EntryBuffer>& buffer);

    void
    set_visibility (bool visible = true);

    auto
    get_visibility () const -> bool;

    void
    set_invisible_char (gunichar ch);

    void
    unset_invisible_char ();

    auto
    get_invisible_char () const -> gunichar;

    void
    set_has_frame (bool setting = true);

    auto
    get_has_frame () const -> bool;

    void
    set_overwrite_mode (bool overwrite = true);

    auto
    get_overwrite_mode () const -> bool;

    void
    set_max_length (int max);

    auto
    get_max_length () const -> int;

    auto
    get_text_length () const -> guint16;

    void
    set_activates_default (bool setting = true);

    auto
    get_activates_default () const -> gboolean;

    void
    set_alignment (float xalign);

    void
    set_alignment (Align xalign);

    auto
    get_alignment () const -> float;

    void
    set_completion (const Glib::RefPtr<EntryCompletion>& completion);

    auto
    get_completion () -> Glib::RefPtr<EntryCompletion>;

    auto
    get_completion () const -> Glib::RefPtr<const EntryCompletion>;

    void
    set_progress_fraction (double fraction);

    auto
    get_progress_fraction () const -> double;

    void
    set_progress_pulse_step (double fraction);

    auto
    get_progress_pulse_step () -> double;

    void
    progress_pulse ();

    auto
    get_placeholder_text () const -> Glib::ustring;

    void
    set_placeholder_text (const Glib::ustring& text);

    void
    set_icon_from_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable,
                             IconPosition icon_pos = IconPosition::PRIMARY);

    void
    set_icon_from_icon_name (const Glib::ustring& icon_name,
                             IconPosition icon_pos = IconPosition::PRIMARY);

    void
    set_icon_from_gicon (const Glib::RefPtr<Gio::Icon>& icon,
                         IconPosition icon_pos = IconPosition::PRIMARY);

    void
    unset_icon (IconPosition icon_pos = IconPosition::PRIMARY);

    auto
    get_icon_storage_type (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Image::Type;

    auto
    get_icon_paintable (IconPosition icon_pos = IconPosition::PRIMARY)
        -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_icon_paintable (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Glib::RefPtr<const Gdk::Paintable>;

    auto
    get_icon_name (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Glib::ustring;

    auto
    get_icon_gicon (IconPosition icon_pos = IconPosition::PRIMARY)
        -> Glib::RefPtr<Gio::Icon>;

    auto
    get_icon_gicon (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Glib::RefPtr<const Gio::Icon>;

    void
    set_icon_activatable (bool activatable = true,
                          IconPosition icon_pos = IconPosition::PRIMARY);

    auto
    get_icon_activatable (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> bool;

    void
    set_icon_sensitive (IconPosition icon_pos = IconPosition::PRIMARY,
                        bool sensitive = true);

    auto
    get_icon_sensitive (IconPosition icon_pos = IconPosition::PRIMARY) -> bool;

    auto
    get_icon_at_pos (int x, int y) const -> int;

    void
    set_icon_tooltip_text (const Glib::ustring& tooltip,
                           IconPosition icon_pos = IconPosition::PRIMARY);

    auto
    get_icon_tooltip_text (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Glib::ustring;

    void
    set_icon_tooltip_markup (const Glib::ustring& tooltip,
                             IconPosition icon_pos = IconPosition::PRIMARY);

    auto
    get_icon_tooltip_markup (
        IconPosition icon_pos = IconPosition::PRIMARY) const -> Glib::ustring;

    void
    set_icon_drag_source (const Glib::RefPtr<Gdk::ContentProvider>& provider,
                          Gdk::DragAction actions = Gdk::DragAction::COPY,
                          IconPosition icon_pos = IconPosition::PRIMARY);

    auto
    get_icon_area (IconPosition icon_pos = IconPosition::PRIMARY) const
        -> Gdk::Rectangle;

    auto
    get_current_icon_drag_source () -> int;

    void
    reset_im_context ();

    void
    set_input_purpose (InputPurpose purpose);

    auto
    get_input_purpose () const -> InputPurpose;

    void
    set_input_hints (InputHints hints);

    auto
    get_input_hints () const -> InputHints;

    void
    set_attributes (Pango::AttrList& attrs);

    auto
    get_attributes () const -> Pango::AttrList;

    void
    set_tabs (const Pango::TabArray& tabs);

    auto
    get_tabs () const -> Pango::TabArray;

    void
    grab_focus_without_selecting ();

    void
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model);

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    signal_activate () -> Glib::SignalProxy<void ()>;

    auto
    signal_icon_release () -> Glib::SignalProxy<void (IconPosition)>;

    auto
    signal_icon_press () -> Glib::SignalProxy<void (IconPosition)>;

    auto
    property_buffer () -> Glib::PropertyProxy<Glib::RefPtr<EntryBuffer>>;

    auto
    property_buffer () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryBuffer>>;

    auto
    property_max_length () -> Glib::PropertyProxy<int>;

    auto
    property_max_length () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_visibility () -> Glib::PropertyProxy<bool>;

    auto
    property_visibility () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_invisible_char () -> Glib::PropertyProxy<gunichar>;

    auto
    property_invisible_char () const -> Glib::PropertyProxy_ReadOnly<gunichar>;

    auto
    property_invisible_char_set () -> Glib::PropertyProxy<bool>;

    auto
    property_invisible_char_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_activates_default () -> Glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_scroll_offset () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_truncate_multiline () -> Glib::PropertyProxy<bool>;

    auto
    property_truncate_multiline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_overwrite_mode () -> Glib::PropertyProxy<bool>;

    auto
    property_overwrite_mode () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text_length () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_progress_fraction () -> Glib::PropertyProxy<double>;

    auto
    property_progress_fraction () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_progress_pulse_step () -> Glib::PropertyProxy<double>;

    auto
    property_progress_pulse_step () const
        -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_primary_icon_paintable ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_primary_icon_paintable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_secondary_icon_paintable ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_secondary_icon_paintable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_primary_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_primary_icon_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_secondary_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_secondary_icon_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_primary_icon_gicon ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_primary_icon_gicon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_secondary_icon_gicon ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_secondary_icon_gicon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_primary_icon_storage_type () const
        -> Glib::PropertyProxy_ReadOnly<Image::Type>;

    auto
    property_secondary_icon_storage_type () const
        -> Glib::PropertyProxy_ReadOnly<Image::Type>;

    auto
    property_primary_icon_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_primary_icon_activatable () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_activatable () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_sensitive () -> Glib::PropertyProxy<bool>;

    auto
    property_primary_icon_sensitive () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_sensitive () -> Glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_sensitive () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_tooltip_text () -> Glib::PropertyProxy<bool>;

    auto
    property_primary_icon_tooltip_text () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_tooltip_text () -> Glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_tooltip_text () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary_icon_tooltip_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_primary_icon_tooltip_markup () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_icon_tooltip_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_secondary_icon_tooltip_markup () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_im_module () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_placeholder_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_completion ()
        -> Glib::PropertyProxy<Glib::RefPtr<EntryCompletion>>;

    auto
    property_completion () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<EntryCompletion>>;

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
    property_attributes () -> Glib::PropertyProxy<Pango::AttrList>;

    auto
    property_attributes () const
        -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>;

    auto
    property_tabs () -> Glib::PropertyProxy<Pango::TabArray>;

    auto
    property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>;

    auto
    property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_show_emoji_icon () -> Glib::PropertyProxy<bool>;

    auto
    property_show_emoji_icon () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_emoji_completion () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Entry::IconPosition>
    : public Glib::Value_Enum<Gtk::Entry::IconPosition>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEntry* object, bool take_copy = false) -> Gtk::Entry*;
} // namespace Glib

#endif
