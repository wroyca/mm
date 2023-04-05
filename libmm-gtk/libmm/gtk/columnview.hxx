// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEW_H
#define _GTKMM_COLUMNVIEW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/columnviewcolumn.hxx>
#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/selectionmodel.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColumnView_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ColumnView : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class ColumnView_Class;
    static CppClassType columnview_class_;

  protected:
    explicit ColumnView (const glib::ConstructParams& construct_params);
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
    explicit ColumnView (const glib::RefPtr<SelectionModel>& model = {});

    auto
    get_columns () -> glib::RefPtr<gio::ListModel>;

    auto
    get_columns () const -> glib::RefPtr<const gio::ListModel>;

    auto
    append_column (const glib::RefPtr<ColumnViewColumn>& column) -> void;

    auto
    remove_column (const glib::RefPtr<ColumnViewColumn>& column) -> void;

    auto
    insert_column (guint position, const glib::RefPtr<ColumnViewColumn>& column)
        -> void;

    auto
    get_model () -> glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> glib::RefPtr<const SelectionModel>;

    auto
    set_model (const glib::RefPtr<SelectionModel>& model) -> void;

    auto
    get_show_row_separators () const -> bool;

    auto
    set_show_row_separators (bool show_separators = true) -> void;

    auto
    get_show_column_separators () const -> bool;

    auto
    set_show_column_separators (bool show_separators = true) -> void;

    auto
    get_sorter () -> glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> glib::RefPtr<const Sorter>;

    auto
    sort_by_column (const glib::RefPtr<ColumnViewColumn>& column,
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
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>;

    auto
    property_show_row_separators () -> glib::PropertyProxy<bool>;

    auto
    property_show_row_separators () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_column_separators () -> glib::PropertyProxy<bool>;

    auto
    property_show_column_separators () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_sorter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>>;

    auto
    property_single_click_activate () -> glib::PropertyProxy<bool>;

    auto
    property_single_click_activate () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_reorderable () -> glib::PropertyProxy<bool>;

    auto
    property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_rubberband () -> glib::PropertyProxy<bool>;

    auto
    property_enable_rubberband () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColumnView* object, bool take_copy = false) -> gtk::ColumnView*;
} // namespace glib

#endif
