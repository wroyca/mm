// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LABEL_H
#define _GTKMM_LABEL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/widget.hxx>
#include <libmm/pango/attrlist.hxx>
#include <libmm/pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLabel = struct _GtkLabel;
using GtkLabelClass = struct _GtkLabelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Label_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Menu;

  class LIBMM_GTK_SYMEXPORT Label : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Label CppObjectType;
    typedef Label_Class CppClassType;
    typedef GtkLabel BaseObjectType;
    typedef GtkLabelClass BaseClassType;
#endif

    Label (Label&& src) noexcept;
    auto
    operator= (Label&& src) noexcept -> Label&;

    Label (const Label&) = delete;
    auto
    operator= (const Label&) -> Label& = delete;

    ~Label () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Label_Class;
    static CppClassType label_class_;

  protected:
    explicit Label (const Glib::ConstructParams& construct_params);
    explicit Label (GtkLabel* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLabel*
    {
      return reinterpret_cast<GtkLabel*> (gobject_);
    }

    auto
    gobj () const -> const GtkLabel*
    {
      return reinterpret_cast<GtkLabel*> (gobject_);
    }

  private:
  public:
    Label ();
    explicit Label (const Glib::ustring& label, bool mnemonic = false);

    Label (const Glib::ustring& label,
           Align halign,
           Align valign = Align::CENTER,
           bool mnemonic = false);

    auto
    set_text (const Glib::ustring& str) -> void;

    auto
    get_text () const -> Glib::ustring;

    auto
    set_attributes (Pango::AttrList& attrs) -> void;

    auto
    get_attributes () const -> Pango::AttrList;

    auto
    set_label (const Glib::ustring& str) -> void;

    auto
    get_label () const -> Glib::ustring;

    auto
    set_markup (const Glib::ustring& str) -> void;

    auto
    set_use_markup (bool setting = true) -> void;

    auto
    get_use_markup () const -> bool;

    auto
    set_use_underline (bool setting = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_markup_with_mnemonic (const Glib::ustring& str) -> void;

    auto
    get_mnemonic_keyval () const -> guint;

    auto
    set_mnemonic_widget (Widget& widget) -> void;

    auto
    get_mnemonic_widget () -> Widget*;

    auto
    get_mnemonic_widget () const -> const Widget*;

    auto
    set_text_with_mnemonic (const Glib::ustring& str) -> void;

    auto
    set_justify (Justification jtype) -> void;

    auto
    get_justify () const -> Justification;

    auto
    set_ellipsize (Pango::EllipsizeMode mode) -> void;

    auto
    get_ellipsize () const -> Pango::EllipsizeMode;

    auto
    set_width_chars (int n_chars) -> void;

    auto
    get_width_chars () const -> int;

    auto
    set_max_width_chars (int n_chars) -> void;

    auto
    get_max_width_chars () const -> int;

    auto
    set_lines (int lines) -> void;

    auto
    get_lines () const -> int;

    auto
    set_wrap (bool wrap = true) -> void;

    auto
    get_wrap () const -> bool;

    auto
    set_wrap_mode (Pango::WrapMode wrap_mode) -> void;

    auto
    get_wrap_mode () const -> Pango::WrapMode;

    auto
    set_natural_wrap_mode (NaturalWrapMode wrap_mode) -> void;

    auto
    get_natural_wrap_mode () const -> NaturalWrapMode;

    auto
    set_selectable (bool setting = true) -> void;

    auto
    get_selectable () const -> bool;

    auto
    select_region (int start_offset, int end_offset) -> void;

    auto
    select_region (int start_offset) -> void;

    auto
    get_selection_bounds (int& start, int& end) const -> bool;

    auto
    get_layout () -> Glib::RefPtr<Pango::Layout>;

    auto
    get_layout () const -> Glib::RefPtr<const Pango::Layout>;

    auto
    get_layout_offsets (int& x, int& y) const -> void;

    auto
    set_single_line_mode (bool single_line_mode = true) -> void;

    auto
    get_single_line_mode () const -> bool;

    auto
    get_current_uri () const -> Glib::ustring;

    auto
    set_xalign (float xalign) -> void;

    auto
    get_xalign () const -> float;

    auto
    set_yalign (float yalign) -> void;

    auto
    get_yalign () const -> float;

    auto
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    set_tabs (const Pango::TabArray& tabs) -> void;

    auto
    get_tabs () const -> Pango::TabArray;

    auto
    signal_activate_link () -> Glib::SignalProxy<bool (const Glib::ustring&)>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_attributes () -> Glib::PropertyProxy<Pango::AttrList>;

    auto
    property_attributes () const
        -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>;

    auto
    property_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_justify () -> Glib::PropertyProxy<Justification>;

    auto
    property_justify () const -> Glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_wrap () -> Glib::PropertyProxy<bool>;

    auto
    property_wrap () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> Glib::PropertyProxy<Pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> Glib::PropertyProxy_ReadOnly<Pango::WrapMode>;

    auto
    property_natural_wrap_mode () -> Glib::PropertyProxy<NaturalWrapMode>;

    auto
    property_natural_wrap_mode () const
        -> Glib::PropertyProxy_ReadOnly<NaturalWrapMode>;

    auto
    property_selectable () -> Glib::PropertyProxy<bool>;

    auto
    property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mnemonic_keyval () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_mnemonic_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_mnemonic_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_ellipsize () -> Glib::PropertyProxy<Pango::EllipsizeMode>;

    auto
    property_ellipsize () const
        -> Glib::PropertyProxy_ReadOnly<Pango::EllipsizeMode>;

    auto
    property_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_single_line_mode () -> Glib::PropertyProxy<bool>;

    auto
    property_single_line_mode () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_max_width_chars () -> Glib::PropertyProxy<int>;

    auto
    property_max_width_chars () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_lines () -> Glib::PropertyProxy<int>;

    auto
    property_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_tabs () -> Glib::PropertyProxy<Pango::TabArray>;

    auto
    property_tabs () const -> Glib::PropertyProxy_ReadOnly<Pango::TabArray>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkLabel* object, bool take_copy = false) -> Gtk::Label*;
} // namespace Glib

#endif
