
#ifndef _GTKMM_TEXT_H
#define _GTKMM_TEXT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/entrybuffer.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkText = struct _GtkText;
using GtkTextClass = struct _GtkTextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Text_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Text : public Widget,
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
    friend GTKMM_API class Text_Class;
    static CppClassType text_class_;

  protected:
    explicit Text (const Glib::ConstructParams& construct_params);
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
    explicit Text (const Glib::RefPtr<EntryBuffer>& buffer);

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
    get_activates_default () const -> bool;

    auto
    get_placeholder_text () const -> Glib::ustring;

    void
    set_placeholder_text (const Glib::ustring& text);

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

    auto
    grab_focus_without_selecting () -> bool;

    void
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model);

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    void
    set_enable_emoji_completion (bool enable_emoji_completion = true);

    auto
    get_enable_emoji_completion () const -> bool;

    void
    set_propagate_text_width (bool propagate_text_width = true);

    auto
    get_propagate_text_width () const -> bool;

    void
    set_truncate_multiline (bool truncate_multiline = true);

    auto
    get_truncate_multiline () const -> bool;

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
    property_im_module () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_im_module () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_placeholder_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

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
    property_enable_emoji_completion () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_emoji_completion () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_propagate_text_width () -> Glib::PropertyProxy<bool>;

    auto
    property_propagate_text_width () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkText* object, bool take_copy = false) -> Gtk::Text*;
} // namespace Glib

#endif
