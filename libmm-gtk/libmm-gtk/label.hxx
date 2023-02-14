// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LABEL_H
#define _GTKMM_LABEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/widget.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/tabarray.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLabel = struct _GtkLabel;
using GtkLabelClass = struct _GtkLabelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Label_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Menu;

  class GTKMM_API Label : public Widget
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
    friend GTKMM_API class Label_Class;
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

    void
    set_text (const Glib::ustring& str);

    auto
    get_text () const -> Glib::ustring;

    void
    set_attributes (Pango::AttrList& attrs);

    auto
    get_attributes () const -> Pango::AttrList;

    void
    set_label (const Glib::ustring& str);

    auto
    get_label () const -> Glib::ustring;

    void
    set_markup (const Glib::ustring& str);

    void
    set_use_markup (bool setting = true);

    auto
    get_use_markup () const -> bool;

    void
    set_use_underline (bool setting = true);

    auto
    get_use_underline () const -> bool;

    void
    set_markup_with_mnemonic (const Glib::ustring& str);

    auto
    get_mnemonic_keyval () const -> guint;

    void
    set_mnemonic_widget (Widget& widget);

    auto
    get_mnemonic_widget () -> Widget*;

    auto
    get_mnemonic_widget () const -> const Widget*;

    void
    set_text_with_mnemonic (const Glib::ustring& str);

    void
    set_justify (Justification jtype);

    auto
    get_justify () const -> Justification;

    void
    set_ellipsize (Pango::EllipsizeMode mode);

    auto
    get_ellipsize () const -> Pango::EllipsizeMode;

    void
    set_width_chars (int n_chars);

    auto
    get_width_chars () const -> int;

    void
    set_max_width_chars (int n_chars);

    auto
    get_max_width_chars () const -> int;

    void
    set_lines (int lines);

    auto
    get_lines () const -> int;

    void
    set_wrap (bool wrap = true);

    auto
    get_wrap () const -> bool;

    void
    set_wrap_mode (Pango::WrapMode wrap_mode);

    auto
    get_wrap_mode () const -> Pango::WrapMode;

    void
    set_natural_wrap_mode (NaturalWrapMode wrap_mode);

    auto
    get_natural_wrap_mode () const -> NaturalWrapMode;

    void
    set_selectable (bool setting = true);

    auto
    get_selectable () const -> bool;

    void
    select_region (int start_offset, int end_offset);

    void
    select_region (int start_offset);

    auto
    get_selection_bounds (int& start, int& end) const -> bool;

    auto
    get_layout () -> Glib::RefPtr<Pango::Layout>;

    auto
    get_layout () const -> Glib::RefPtr<const Pango::Layout>;

    void
    get_layout_offsets (int& x, int& y) const;

    void
    set_single_line_mode (bool single_line_mode = true);

    auto
    get_single_line_mode () const -> bool;

    auto
    get_current_uri () const -> Glib::ustring;

    void
    set_xalign (float xalign);

    auto
    get_xalign () const -> float;

    void
    set_yalign (float yalign);

    auto
    get_yalign () const -> float;

    void
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model);

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    void
    set_tabs (const Pango::TabArray& tabs);

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

  GTKMM_API
  auto
  wrap (GtkLabel* object, bool take_copy = false) -> Gtk::Label*;
} // namespace Glib

#endif
