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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Label_Class;
}
#endif

namespace gtk
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
    explicit Label (const glib::ConstructParams& construct_params);
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
    explicit Label (const glib::ustring& label, bool mnemonic = false);

    Label (const glib::ustring& label,
           Align halign,
           Align valign = Align::CENTER,
           bool mnemonic = false);

    auto
    set_text (const glib::ustring& str) -> void;

    auto
    get_text () const -> glib::ustring;

    auto
    set_attributes (pango::AttrList& attrs) -> void;

    auto
    get_attributes () const -> pango::AttrList;

    auto
    set_label (const glib::ustring& str) -> void;

    auto
    get_label () const -> glib::ustring;

    auto
    set_markup (const glib::ustring& str) -> void;

    auto
    set_use_markup (bool setting = true) -> void;

    auto
    get_use_markup () const -> bool;

    auto
    set_use_underline (bool setting = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_markup_with_mnemonic (const glib::ustring& str) -> void;

    auto
    get_mnemonic_keyval () const -> guint;

    auto
    set_mnemonic_widget (Widget& widget) -> void;

    auto
    get_mnemonic_widget () -> Widget*;

    auto
    get_mnemonic_widget () const -> const Widget*;

    auto
    set_text_with_mnemonic (const glib::ustring& str) -> void;

    auto
    set_justify (Justification jtype) -> void;

    auto
    get_justify () const -> Justification;

    auto
    set_ellipsize (pango::EllipsizeMode mode) -> void;

    auto
    get_ellipsize () const -> pango::EllipsizeMode;

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
    set_wrap_mode (pango::WrapMode wrap_mode) -> void;

    auto
    get_wrap_mode () const -> pango::WrapMode;

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
    get_layout () -> glib::RefPtr<pango::Layout>;

    auto
    get_layout () const -> glib::RefPtr<const pango::Layout>;

    auto
    get_layout_offsets (int& x, int& y) const -> void;

    auto
    set_single_line_mode (bool single_line_mode = true) -> void;

    auto
    get_single_line_mode () const -> bool;

    auto
    get_current_uri () const -> glib::ustring;

    auto
    set_xalign (float xalign) -> void;

    auto
    get_xalign () const -> float;

    auto
    set_yalign (float yalign) -> void;

    auto
    get_yalign () const -> float;

    auto
    set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    set_tabs (const pango::TabArray& tabs) -> void;

    auto
    get_tabs () const -> pango::TabArray;

    auto
    signal_activate_link () -> glib::SignalProxy<bool (const glib::ustring&)>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_attributes () -> glib::PropertyProxy<pango::AttrList>;

    auto
    property_attributes () const
        -> glib::PropertyProxy_ReadOnly<pango::AttrList>;

    auto
    property_use_markup () -> glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_justify () -> glib::PropertyProxy<Justification>;

    auto
    property_justify () const -> glib::PropertyProxy_ReadOnly<Justification>;

    auto
    property_wrap () -> glib::PropertyProxy<bool>;

    auto
    property_wrap () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_wrap_mode () -> glib::PropertyProxy<pango::WrapMode>;

    auto
    property_wrap_mode () const
        -> glib::PropertyProxy_ReadOnly<pango::WrapMode>;

    auto
    property_natural_wrap_mode () -> glib::PropertyProxy<NaturalWrapMode>;

    auto
    property_natural_wrap_mode () const
        -> glib::PropertyProxy_ReadOnly<NaturalWrapMode>;

    auto
    property_selectable () -> glib::PropertyProxy<bool>;

    auto
    property_selectable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_mnemonic_keyval () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_mnemonic_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_mnemonic_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_ellipsize () -> glib::PropertyProxy<pango::EllipsizeMode>;

    auto
    property_ellipsize () const
        -> glib::PropertyProxy_ReadOnly<pango::EllipsizeMode>;

    auto
    property_width_chars () -> glib::PropertyProxy<int>;

    auto
    property_width_chars () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_single_line_mode () -> glib::PropertyProxy<bool>;

    auto
    property_single_line_mode () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_max_width_chars () -> glib::PropertyProxy<int>;

    auto
    property_max_width_chars () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_lines () -> glib::PropertyProxy<int>;

    auto
    property_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_xalign () -> glib::PropertyProxy<float>;

    auto
    property_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> glib::PropertyProxy<float>;

    auto
    property_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_tabs () -> glib::PropertyProxy<pango::TabArray>;

    auto
    property_tabs () const -> glib::PropertyProxy_ReadOnly<pango::TabArray>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkLabel* object, bool take_copy = false) -> gtk::Label*;
} // namespace glib

#endif
