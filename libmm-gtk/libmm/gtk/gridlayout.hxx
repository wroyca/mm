// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDLAYOUT_H
#define _GTKMM_GRIDLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/layoutmanager.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GridLayout_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GridLayout : public LayoutManager
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GridLayout;
    using CppClassType = GridLayout_Class;
    using BaseObjectType = GtkGridLayout;
    using BaseClassType = GtkGridLayoutClass;

    GridLayout (const GridLayout&) = delete;
    auto
    operator= (const GridLayout&) -> GridLayout& = delete;

  private:
    friend class GridLayout_Class;
    static CppClassType gridlayout_class_;

  protected:
    explicit GridLayout (const glib::ConstructParams& construct_params);
    explicit GridLayout (GtkGridLayout* castitem);

#endif

  public:
    GridLayout (GridLayout&& src) noexcept;
    auto
    operator= (GridLayout&& src) noexcept -> GridLayout&;

    ~GridLayout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGridLayout*
    {
      return reinterpret_cast<GtkGridLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkGridLayout*
    {
      return reinterpret_cast<GtkGridLayout*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGridLayout*;

  private:
  protected:
    GridLayout ();

  public:
    static auto
    create () -> glib::RefPtr<GridLayout>;

    auto
    set_row_homogeneous (bool homogeneous = true) -> void;

    auto
    get_row_homogeneous () const -> bool;

    auto
    set_row_spacing (guint spacing) -> void;

    auto
    get_row_spacing () const -> guint;

    auto
    set_column_homogeneous (bool homogeneous = true) -> void;

    auto
    get_column_homogeneous () const -> bool;

    auto
    set_column_spacing (guint spacing) -> void;

    auto
    get_column_spacing () const -> guint;

    auto
    set_row_baseline_position (int row, BaselinePosition pos) -> void;

    auto
    get_row_baseline_position (int row) const -> BaselinePosition;

    auto
    set_baseline_row (int row) -> void;

    auto
    get_baseline_row () const -> int;

    auto
    property_row_spacing () -> glib::PropertyProxy<int>;

    auto
    property_row_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_column_spacing () -> glib::PropertyProxy<int>;

    auto
    property_column_spacing () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_row_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_row_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_column_homogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_column_homogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_baseline_row () -> glib::PropertyProxy<int>;

    auto
    property_baseline_row () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGridLayout* object, bool take_copy = false) -> glib::RefPtr<gtk::GridLayout>;
} // namespace glib

#endif
