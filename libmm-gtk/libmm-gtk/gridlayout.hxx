// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDLAYOUT_H
#define _GTKMM_GRIDLAYOUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/layoutmanager.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GridLayout_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API GridLayout : public LayoutManager
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
    explicit GridLayout (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<GridLayout>;

    void
    set_row_homogeneous (bool homogeneous = true);

    auto
    get_row_homogeneous () const -> bool;

    void
    set_row_spacing (guint spacing);

    auto
    get_row_spacing () const -> guint;

    void
    set_column_homogeneous (bool homogeneous = true);

    auto
    get_column_homogeneous () const -> bool;

    void
    set_column_spacing (guint spacing);

    auto
    get_column_spacing () const -> guint;

    void
    set_row_baseline_position (int row, BaselinePosition pos);

    auto
    get_row_baseline_position (int row) const -> BaselinePosition;

    void
    set_baseline_row (int row);

    auto
    get_baseline_row () const -> int;

    auto
    property_row_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_row_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_column_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_column_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_row_homogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_row_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_column_homogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_column_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_baseline_row () -> Glib::PropertyProxy<int>;

    auto
    property_baseline_row () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkGridLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GridLayout>;
} // namespace Glib

#endif
