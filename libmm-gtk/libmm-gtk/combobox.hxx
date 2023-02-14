// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COMBOBOX_H
#define _GTKMM_COMBOBOX_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/celleditable.hxx>
#include <libmm-gtk/celllayout.hxx>
#include <libmm-gtk/entry.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treeview.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBox = struct _GtkComboBox;
using GtkComboBoxClass = struct _GtkComboBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ComboBox_Class;
}
#endif

namespace Gdk
{
  class GTKMM_API Device;
}

namespace Gtk
{

  class GTKMM_API ComboBox : public Widget,
                             public CellLayout,
                             public CellEditable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ComboBox CppObjectType;
    typedef ComboBox_Class CppClassType;
    typedef GtkComboBox BaseObjectType;
    typedef GtkComboBoxClass BaseClassType;
#endif

    ComboBox (ComboBox&& src) noexcept;
    auto
    operator= (ComboBox&& src) noexcept -> ComboBox&;

    ComboBox (const ComboBox&) = delete;
    auto
    operator= (const ComboBox&) -> ComboBox& = delete;

    ~ComboBox () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ComboBox_Class;
    static CppClassType combobox_class_;

  protected:
    explicit ComboBox (const Glib::ConstructParams& construct_params);
    explicit ComboBox (GtkComboBox* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkComboBox*
    {
      return reinterpret_cast<GtkComboBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkComboBox*
    {
      return reinterpret_cast<GtkComboBox*> (gobject_);
    }

  private:
  public:
    explicit ComboBox (bool has_entry = false);

    explicit ComboBox (const Glib::RefPtr<TreeModel>& model,
                       bool has_entry = false);

    auto
    get_active_row_number () const -> int;

    auto
    get_active () -> TreeModel::iterator;

    auto
    get_active () const -> TreeModel::const_iterator;

    void
    set_active (int index);

    void
    set_active (const TreeModel::const_iterator& iter);

    auto
    get_entry_text () const -> Glib::ustring;

    void
    unset_active ();

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    void
    set_model (const Glib::RefPtr<TreeModel>& model);

    void
    unset_model ();

    typedef TreeView::SlotRowSeparator SlotRowSeparator;

    void
    set_row_separator_func (const SlotRowSeparator& slot);

    void
    unset_row_separator_func ();

    void
    set_button_sensitivity (SensitivityType sensitivity);

    auto
    get_button_sensitivity () const -> SensitivityType;

    auto
    get_has_entry () const -> bool;

    void
    set_entry_text_column (const TreeModelColumnBase& text_column) const;

    void
    set_entry_text_column (int text_column);

    auto
    get_entry_text_column () const -> int;

    void
    set_popup_fixed_width (bool fixed = true);

    auto
    get_popup_fixed_width () const -> bool;

    void
    popup ();

    void
    popup (const Glib::RefPtr<Gdk::Device>& device);

    void
    popdown ();

    auto
    get_id_column () const -> int;

    void
    set_id_column (int id_column);

    auto
    get_active_id () const -> Glib::ustring;

    auto
    set_active_id (const Glib::ustring& active_id) -> bool;

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    get_entry () -> Entry*;

    auto
    get_entry () const -> const Entry*;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>;

    auto
    property_active () -> Glib::PropertyProxy<int>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_shown () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_button_sensitivity () -> Glib::PropertyProxy<SensitivityType>;

    auto
    property_button_sensitivity () const
        -> Glib::PropertyProxy_ReadOnly<SensitivityType>;

    auto
    property_popup_fixed_width () -> Glib::PropertyProxy<bool>;

    auto
    property_popup_fixed_width () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_entry () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_entry_text_column () -> Glib::PropertyProxy<int>;

    auto
    property_entry_text_column () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_id_column () -> Glib::PropertyProxy<int>;

    auto
    property_id_column () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_active_id () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_active_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_format_entry_text ()
        -> Glib::SignalProxy<Glib::ustring (const TreeModel::Path&)>;

  public:
  public:
  protected:
    virtual void
    on_changed ();

    virtual auto
    on_format_entry_text (const TreeModel::Path& path) -> Glib::ustring;
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkComboBox* object, bool take_copy = false) -> Gtk::ComboBox*;
} // namespace Glib

#endif
