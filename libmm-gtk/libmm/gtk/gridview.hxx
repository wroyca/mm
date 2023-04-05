// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDVIEW_H
#define _GTKMM_GRIDVIEW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/listbase.hxx>
#include <libmm/gtk/listitemfactory.hxx>
#include <libmm/gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGridView = struct _GtkGridView;
using GtkGridViewClass = struct _GtkGridViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GridView_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GridView : public ListBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef GridView CppObjectType;
    typedef GridView_Class CppClassType;
    typedef GtkGridView BaseObjectType;
    typedef GtkGridViewClass BaseClassType;
#endif

    GridView (GridView&& src) noexcept;
    auto
    operator= (GridView&& src) noexcept -> GridView&;

    GridView (const GridView&) = delete;
    auto
    operator= (const GridView&) -> GridView& = delete;

    ~GridView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class GridView_Class;
    static CppClassType gridview_class_;

  protected:
    explicit GridView (const glib::ConstructParams& construct_params);
    explicit GridView (GtkGridView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGridView*
    {
      return reinterpret_cast<GtkGridView*> (gobject_);
    }

    auto
    gobj () const -> const GtkGridView*
    {
      return reinterpret_cast<GtkGridView*> (gobject_);
    }

  private:
  public:
    explicit GridView (const glib::RefPtr<SelectionModel>& model = {},
                       const glib::RefPtr<ListItemFactory>& factory = {});

    auto
    get_model () -> glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> glib::RefPtr<const SelectionModel>;

    auto
    set_model (const glib::RefPtr<SelectionModel>& model) -> void;

    auto
    set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> glib::RefPtr<const ListItemFactory>;

    auto
    get_min_columns () const -> guint;

    auto
    set_min_columns (guint min_columns) -> void;

    auto
    get_max_columns () const -> guint;

    auto
    set_max_columns (guint max_columns) -> void;

    auto
    set_enable_rubberband (bool enable_rubberband = true) -> void;

    auto
    get_enable_rubberband () const -> bool;

    auto
    set_single_click_activate (bool single_click_activate = true) -> void;

    auto
    get_single_click_activate () const -> bool;

    auto
    property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>;

    auto
    property_max_columns () -> glib::PropertyProxy<guint>;

    auto
    property_max_columns () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_min_columns () -> glib::PropertyProxy<guint>;

    auto
    property_min_columns () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>;

    auto
    property_single_click_activate () -> glib::PropertyProxy<bool>;

    auto
    property_single_click_activate () const
        -> glib::PropertyProxy_ReadOnly<bool>;

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
  wrap (GtkGridView* object, bool take_copy = false) -> gtk::GridView*;
} // namespace glib

#endif
