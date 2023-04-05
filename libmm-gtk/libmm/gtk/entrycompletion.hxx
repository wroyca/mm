// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRYCOMPLETION_H
#define _GTKMM_ENTRYCOMPLETION_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntryCompletion = struct _GtkEntryCompletion;
using GtkEntryCompletionClass = struct _GtkEntryCompletionClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EntryCompletion_Class;
}
  #endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellArea;
  class LIBMM_GTK_SYMEXPORT Entry;

  class LIBMM_GTK_SYMEXPORT EntryCompletion : public glib::Object,
                                    public gtk::CellLayout,
                                    public gtk::Buildable
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EntryCompletion;
    using CppClassType = EntryCompletion_Class;
    using BaseObjectType = GtkEntryCompletion;
    using BaseClassType = GtkEntryCompletionClass;

    EntryCompletion (const EntryCompletion&) = delete;
    auto
    operator= (const EntryCompletion&) -> EntryCompletion& = delete;

  private:
    friend class EntryCompletion_Class;
    static CppClassType entrycompletion_class_;

  protected:
    explicit EntryCompletion (const glib::ConstructParams& construct_params);
    explicit EntryCompletion (GtkEntryCompletion* castitem);

  #endif

  public:
    EntryCompletion (EntryCompletion&& src) noexcept;
    auto
    operator= (EntryCompletion&& src) noexcept -> EntryCompletion&;

    ~EntryCompletion () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkEntryCompletion*
    {
      return reinterpret_cast<GtkEntryCompletion*> (gobject_);
    }

    auto
    gobj () const -> const GtkEntryCompletion*
    {
      return reinterpret_cast<GtkEntryCompletion*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEntryCompletion*;

  private:
  protected:
    EntryCompletion ();

  public:
    static auto
    create () -> glib::RefPtr<EntryCompletion>;

    auto
    get_entry () -> Entry*;

    auto
    get_entry () const -> const Entry*;

    auto
    set_model (const glib::RefPtr<TreeModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<TreeModel>;

    auto
    get_model () const -> glib::RefPtr<const TreeModel>;

    auto
    unset_model () -> void;

    typedef sigc::slot<bool (const glib::ustring&,
                             const TreeModel::const_iterator&)>
        SlotMatch;

    auto
    set_match_func (const SlotMatch& slot) -> void;

    auto
    set_minimum_key_length (int length) -> void;

    auto
    get_minimum_key_length () const -> int;

    auto
    compute_prefix (const glib::ustring& key) -> glib::ustring;

    auto
    complete () -> void;

    auto
    insert_prefix () -> void;

    auto
    set_inline_completion (bool inline_completion = true) -> void;

    auto
    get_inline_completion () const -> bool;

    auto
    set_inline_selection (bool inline_selection = true) -> void;

    auto
    get_inline_selection () const -> bool;

    auto
    set_popup_completion (bool popup_completion = true) -> void;

    auto
    get_popup_completion () const -> bool;

    auto
    set_popup_set_width (bool popup_set_width = true) -> void;

    auto
    get_popup_set_width () const -> bool;

    auto
    set_popup_single_match (bool popup_single_match = true) -> void;

    auto
    get_popup_single_match () const -> bool;

    auto
    get_completion_prefix () const -> glib::ustring;

    auto
    set_text_column (const TreeModelColumnBase& column) -> void;

    auto
    set_text_column (int column) -> void;

    auto
    get_text_column () const -> int;

    auto
    signal_match_selected ()
        -> glib::SignalProxy<bool (const TreeModel::iterator&)>;

    auto
    signal_cursor_on_match ()
        -> glib::SignalProxy<bool (const TreeModel::iterator&)>;

    auto
    signal_insert_prefix () -> glib::SignalProxy<bool (const glib::ustring&)>;

    auto
    signal_no_matches () -> glib::SignalProxy<void ()>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gtk::TreeModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gtk::TreeModel>>;

    auto
    property_minimum_key_length () -> glib::PropertyProxy<int>;

    auto
    property_minimum_key_length () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text_column () -> glib::PropertyProxy<int>;

    auto
    property_text_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_inline_completion () -> glib::PropertyProxy<bool>;

    auto
    property_inline_completion () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_completion () -> glib::PropertyProxy<bool>;

    auto
    property_popup_completion () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_set_width () -> glib::PropertyProxy<bool>;

    auto
    property_popup_set_width () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_single_match () -> glib::PropertyProxy<bool>;

    auto
    property_popup_single_match () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inline_selection () -> glib::PropertyProxy<bool>;

    auto
    property_inline_selection () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cell_area () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<CellArea>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEntryCompletion* object, bool take_copy = false) -> glib::RefPtr<gtk::EntryCompletion>;
} // namespace glib

#endif

#endif
