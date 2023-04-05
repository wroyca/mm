// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COMBOBOX_H
#define _GTKMM_COMBOBOX_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/celleditable.hxx>
  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/entry.hxx>
  #include <libmm/gtk/enums.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treeview.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkComboBox = struct _GtkComboBox;
using GtkComboBoxClass = struct _GtkComboBoxClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ComboBox_Class;
}
  #endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT Device;
}

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ComboBox : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class ComboBox_Class;
    static CppClassType combobox_class_;

  protected:
    explicit ComboBox (const glib::ConstructParams& construct_params);
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

    explicit ComboBox (const glib::RefPtr<TreeModel>& model,
                       bool has_entry = false);

    auto
    get_active_row_number () const -> int;

    auto
    get_active () -> TreeModel::iterator;

    auto
    get_active () const -> TreeModel::const_iterator;

    auto
    set_active (int index) -> void;

    auto
    set_active (const TreeModel::const_iterator& iter) -> void;

    auto
    get_entry_text () const -> glib::ustring;

    auto
    unset_active () -> void;

    auto
    get_model () -> glib::RefPtr<TreeModel>;

    auto
    get_model () const -> glib::RefPtr<const TreeModel>;

    auto
    set_model (const glib::RefPtr<TreeModel>& model) -> void;

    auto
    unset_model () -> void;

    typedef TreeView::SlotRowSeparator SlotRowSeparator;

    auto
    set_row_separator_func (const SlotRowSeparator& slot) -> void;

    auto
    unset_row_separator_func () -> void;

    auto
    set_button_sensitivity (SensitivityType sensitivity) -> void;

    auto
    get_button_sensitivity () const -> SensitivityType;

    auto
    get_has_entry () const -> bool;

    auto
    set_entry_text_column (const TreeModelColumnBase& text_column) const
        -> void;

    auto
    set_entry_text_column (int text_column) -> void;

    auto
    get_entry_text_column () const -> int;

    auto
    set_popup_fixed_width (bool fixed = true) -> void;

    auto
    get_popup_fixed_width () const -> bool;

    auto
    popup () -> void;

    auto
    popup (const glib::RefPtr<gdk::Device>& device) -> void;

    auto
    popdown () -> void;

    auto
    get_id_column () const -> int;

    auto
    set_id_column (int id_column) -> void;

    auto
    get_active_id () const -> glib::ustring;

    auto
    set_active_id (const glib::ustring& active_id) -> bool;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    get_entry () -> Entry*;

    auto
    get_entry () const -> const Entry*;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<TreeModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeModel>>;

    auto
    property_active () -> glib::PropertyProxy<int>;

    auto
    property_active () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_has_frame () -> glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_shown () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_button_sensitivity () -> glib::PropertyProxy<SensitivityType>;

    auto
    property_button_sensitivity () const
        -> glib::PropertyProxy_ReadOnly<SensitivityType>;

    auto
    property_popup_fixed_width () -> glib::PropertyProxy<bool>;

    auto
    property_popup_fixed_width () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_entry () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_entry_text_column () -> glib::PropertyProxy<int>;

    auto
    property_entry_text_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_id_column () -> glib::PropertyProxy<int>;

    auto
    property_id_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_active_id () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_active_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    signal_changed () -> glib::SignalProxy<void ()>;

    auto
    signal_format_entry_text ()
        -> glib::SignalProxy<glib::ustring (const TreeModel::Path&)>;

  public:
  public:
  protected:
    virtual auto
    on_changed () -> void;

    virtual auto
    on_format_entry_text (const TreeModel::Path& path) -> glib::ustring;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkComboBox* object, bool take_copy = false) -> gtk::ComboBox*;
} // namespace glib

#endif

#endif
