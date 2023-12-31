// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SELECTIONMODEL_H
#define _GTKMM_SELECTIONMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>
#include <libmm/gtk/bitset.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkSelectionModelInterface GtkSelectionModelInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSelectionModel = struct _GtkSelectionModel;
using GtkSelectionModelClass = struct _GtkSelectionModelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SelectionModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SelectionModel : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SelectionModel;
    using CppClassType = SelectionModel_Class;
    using BaseObjectType = GtkSelectionModel;
    using BaseClassType = GtkSelectionModelInterface;

    SelectionModel (const SelectionModel&) = delete;
    auto
    operator= (const SelectionModel&) -> SelectionModel& = delete;

  private:
    friend class SelectionModel_Class;
    static CppClassType selectionmodel_class_;

#endif
  protected:
    SelectionModel ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit SelectionModel (const glib::Interface_Class& interface_class);

  public:
    explicit SelectionModel (GtkSelectionModel* castitem);

  protected:
#endif

  public:
    SelectionModel (SelectionModel&& src) noexcept;
    auto
    operator= (SelectionModel&& src) noexcept -> SelectionModel&;

    ~SelectionModel () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSelectionModel*
    {
      return reinterpret_cast<GtkSelectionModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkSelectionModel*
    {
      return reinterpret_cast<GtkSelectionModel*> (gobject_);
    }

  private:
  public:
    auto
    is_selected (guint position) const -> bool;

    auto
    get_selection () const -> glib::RefPtr<const Bitset>;

    auto
    get_selection (guint position, guint n_items) const
        -> glib::RefPtr<const Bitset>;

    auto
    select_item (guint position, bool unselect_rest) -> bool;

    auto
    unselect_item (guint position) -> bool;

    auto
    select_range (guint position, guint n_items, bool unselect_rest) -> bool;

    auto
    unselect_range (guint position, guint n_items) -> bool;

    auto
    select_all () -> bool;

    auto
    unselect_all () -> bool;

    auto
    set_selection (const glib::RefPtr<const Bitset>& selected,
                   const glib::RefPtr<const Bitset>& mask) -> bool;

    auto
    signal_selection_changed () -> glib::SignalProxy<void (guint, guint)>;

  protected:
    auto
    selection_changed (guint position, guint n_items) -> void;

    virtual auto
    is_selected_vfunc (guint position) const -> bool;

    virtual auto
    get_selection_vfunc (guint position, guint n_items)
        -> glib::RefPtr<const Bitset>;

    virtual auto
    select_item_vfunc (guint position, bool unselect_rest) -> bool;

    virtual auto
    unselect_item_vfunc (guint position) -> bool;

    virtual auto
    select_range_vfunc (guint position, guint n_items, bool unselect_rest)
        -> bool;

    virtual auto
    unselect_range_vfunc (guint position, guint n_items) -> bool;

    virtual auto
    select_all_vfunc () -> bool;

    virtual auto
    unselect_all_vfunc () -> bool;

    virtual auto
    set_selection_vfunc (const glib::RefPtr<const Bitset>& selected,
                         const glib::RefPtr<const Bitset>& mask) -> bool;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSelectionModel* object, bool take_copy = false) -> glib::RefPtr<gtk::SelectionModel>;

} // namespace glib

#endif
