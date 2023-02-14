// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ENTRYCOMPLETION_H
#define _GTKMM_ENTRYCOMPLETION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/celllayout.hxx>
#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEntryCompletion = struct _GtkEntryCompletion;
using GtkEntryCompletionClass = struct _GtkEntryCompletionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EntryCompletion_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API CellArea;
  class GTKMM_API Entry;

  class GTKMM_API EntryCompletion : public Glib::Object,
                                    public Gtk::CellLayout,
                                    public Gtk::Buildable
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
    explicit EntryCompletion (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<EntryCompletion>;

    auto
    get_entry () -> Entry*;

    auto
    get_entry () const -> const Entry*;

    void
    set_model (const Glib::RefPtr<TreeModel>& model);

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    void
    unset_model ();

    typedef sigc::slot<bool (const Glib::ustring&,
                             const TreeModel::const_iterator&)>
        SlotMatch;

    void
    set_match_func (const SlotMatch& slot);

    void
    set_minimum_key_length (int length);

    auto
    get_minimum_key_length () const -> int;

    auto
    compute_prefix (const Glib::ustring& key) -> Glib::ustring;

    void
    complete ();

    void
    insert_prefix ();

    void
    set_inline_completion (bool inline_completion = true);

    auto
    get_inline_completion () const -> bool;

    void
    set_inline_selection (bool inline_selection = true);

    auto
    get_inline_selection () const -> bool;

    void
    set_popup_completion (bool popup_completion = true);

    auto
    get_popup_completion () const -> bool;

    void
    set_popup_set_width (bool popup_set_width = true);

    auto
    get_popup_set_width () const -> bool;

    void
    set_popup_single_match (bool popup_single_match = true);

    auto
    get_popup_single_match () const -> bool;

    auto
    get_completion_prefix () const -> Glib::ustring;

    void
    set_text_column (const TreeModelColumnBase& column);

    void
    set_text_column (int column);

    auto
    get_text_column () const -> int;

    auto
    signal_match_selected ()
        -> Glib::SignalProxy<bool (const TreeModel::iterator&)>;

    auto
    signal_cursor_on_match ()
        -> Glib::SignalProxy<bool (const TreeModel::iterator&)>;

    auto
    signal_insert_prefix () -> Glib::SignalProxy<bool (const Glib::ustring&)>;

    auto
    signal_no_matches () -> Glib::SignalProxy<void ()>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gtk::TreeModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gtk::TreeModel>>;

    auto
    property_minimum_key_length () -> Glib::PropertyProxy<int>;

    auto
    property_minimum_key_length () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_text_column () -> Glib::PropertyProxy<int>;

    auto
    property_text_column () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_inline_completion () -> Glib::PropertyProxy<bool>;

    auto
    property_inline_completion () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_completion () -> Glib::PropertyProxy<bool>;

    auto
    property_popup_completion () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_set_width () -> Glib::PropertyProxy<bool>;

    auto
    property_popup_set_width () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_popup_single_match () -> Glib::PropertyProxy<bool>;

    auto
    property_popup_single_match () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inline_selection () -> Glib::PropertyProxy<bool>;

    auto
    property_inline_selection () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_cell_area () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<CellArea>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEntryCompletion* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EntryCompletion>;
} // namespace Glib

#endif
