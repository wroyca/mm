// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEW_H
#define _GTKMM_COLUMNVIEW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/columnviewcolumn.hxx>
#include <libmm-gtk/scrollable.hxx>
#include <libmm-gtk/selectionmodel.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ColumnView_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ColumnView : public Widget,
                               public Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ColumnView CppObjectType;
    typedef ColumnView_Class CppClassType;
    typedef GtkColumnView BaseObjectType;
    typedef GtkColumnViewClass BaseClassType;
#endif

    ColumnView (ColumnView&& src) noexcept;
    auto
    operator= (ColumnView&& src) noexcept -> ColumnView&;

    ColumnView (const ColumnView&) = delete;
    auto
    operator= (const ColumnView&) -> ColumnView& = delete;

    ~ColumnView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ColumnView_Class;
    static CppClassType columnview_class_;

  protected:
    explicit ColumnView (const Glib::ConstructParams& construct_params);
    explicit ColumnView (GtkColumnView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColumnView*
    {
      return reinterpret_cast<GtkColumnView*> (gobject_);
    }

    auto
    gobj () const -> const GtkColumnView*
    {
      return reinterpret_cast<GtkColumnView*> (gobject_);
    }

  private:
  public:
    explicit ColumnView (const Glib::RefPtr<SelectionModel>& model = {});

    auto
    get_columns () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_columns () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    append_column (const Glib::RefPtr<ColumnViewColumn>& column) -> void;

    auto
    remove_column (const Glib::RefPtr<ColumnViewColumn>& column) -> void;

    auto
    insert_column (guint position, const Glib::RefPtr<ColumnViewColumn>& column)
        -> void;

    auto
    get_model () -> Glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> Glib::RefPtr<const SelectionModel>;

    auto
    set_model (const Glib::RefPtr<SelectionModel>& model) -> void;

    auto
    get_show_row_separators () const -> bool;

    auto
    set_show_row_separators (bool show_separators = true) -> void;

    auto
    get_show_column_separators () const -> bool;

    auto
    set_show_column_separators (bool show_separators = true) -> void;

    auto
    get_sorter () -> Glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> Glib::RefPtr<const Sorter>;

    auto
    sort_by_column (const Glib::RefPtr<ColumnViewColumn>& column,
                    SortType direction) -> void;

    auto
    set_single_click_activate (bool single_click_activate = true) -> void;

    auto
    get_single_click_activate () const -> bool;

    auto
    set_reorderable (bool reorderable = true) -> void;

    auto
    get_reorderable () const -> bool;

    auto
    set_enable_rubberband (bool enable_rubberband = true) -> void;

    auto
    get_enable_rubberband () const -> bool;

    auto
    property_columns () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>;

    auto
    property_show_row_separators () -> Glib::PropertyProxy<bool>;

    auto
    property_show_row_separators () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_column_separators () -> Glib::PropertyProxy<bool>;

    auto
    property_show_column_separators () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sorter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>>;

    auto
    property_single_click_activate () -> Glib::PropertyProxy<bool>;

    auto
    property_single_click_activate () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reorderable () -> Glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_rubberband () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_rubberband () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> Glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkColumnView* object, bool take_copy = false) -> Gtk::ColumnView*;
} // namespace Glib

#endif
