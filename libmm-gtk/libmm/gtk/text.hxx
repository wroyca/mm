// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TEXT_H
#define _GTKMM_TEXT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/entrybuffer.hxx>
#include <libmm/gtk/widget.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkText = struct _GtkText;
using GtkTextClass = struct _GtkTextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Text_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Text : public Widget,
                         public Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Text CppObjectType;
    typedef Text_Class CppClassType;
    typedef GtkText BaseObjectType;
    typedef GtkTextClass BaseClassType;
#endif

    Text (Text&& src) noexcept;
    auto
    operator= (Text&& src) noexcept -> Text&;

    Text (const Text&) = delete;
    auto
    operator= (const Text&) -> Text& = delete;

    ~Text () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Text_Class;
    static CppClassType text_class_;

  protected:
    explicit Text (const glib::ConstructParams& construct_params);
    explicit Text (GtkText* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkText*
    {
      return reinterpret_cast<GtkText*> (gobject_);
    }

    auto
    gobj () const -> const GtkText*
    {
      return reinterpret_cast<GtkText*> (gobject_);
    }

  private:
  public:
    Text ();
    explicit Text (const glib::RefPtr<EntryBuffer>& buffer);

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
    get_activates_default () const -> bool;

    auto
    get_placeholder_text () const -> glib::ustring;

    auto
    set_placeholder_text (const glib::ustring& text) -> void;

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
    grab_focus_without_selecting () -> bool;

    auto
    set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    set_enable_emoji_completion (bool enable_emoji_completion = true) -> void;

    auto
    get_enable_emoji_completion () const -> bool;

    auto
    set_propagate_text_width (bool propagate_text_width = true) -> void;

    auto
    get_propagate_text_width () const -> bool;

    auto
    set_truncate_multiline (bool truncate_multiline = true) -> void;

    auto
    get_truncate_multiline () const -> bool;

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
    property_im_module () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_im_module () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_placeholder_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_placeholder_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

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
    property_enable_emoji_completion () -> glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_propagate_text_width () -> glib::PropertyProxy<bool>;

    auto
    property_propagate_text_width () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkText* object, bool take_copy = false) -> gtk::Text*;
} // namespace glib

#endif
