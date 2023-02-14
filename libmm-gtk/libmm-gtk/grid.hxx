
#ifndef _GTKMM_GRID_H
#define _GTKMM_GRID_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGrid = struct _GtkGrid;
using GtkGridClass = struct _GtkGridClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Grid_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Grid : public Widget,
                         public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Grid CppObjectType;
    typedef Grid_Class CppClassType;
    typedef GtkGrid BaseObjectType;
    typedef GtkGridClass BaseClassType;
#endif

    Grid (Grid&& src) noexcept;
    auto
    operator= (Grid&& src) noexcept -> Grid&;

    Grid (const Grid&) = delete;
    auto
    operator= (const Grid&) -> Grid& = delete;

    ~Grid () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Grid_Class;
    static CppClassType grid_class_;

  protected:
    explicit Grid (const Glib::ConstructParams& construct_params);
    explicit Grid (GtkGrid* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGrid*
    {
      return reinterpret_cast<GtkGrid*> (gobject_);
    }

    auto
    gobj () const -> const GtkGrid*
    {
      return reinterpret_cast<GtkGrid*> (gobject_);
    }

  private:
  public:
    Grid ();

    void
    attach (Widget& child, int column, int row, int width = 1, int height = 1);

    void
    attach_next_to (Widget& child,
                    Widget& sibling,
                    PositionType side,
                    int width = 1,
                    int height = 1);

    void
    attach_next_to (Widget& child,
                    PositionType side,
                    int width = 1,
                    int height = 1);

    auto
    get_child_at (int column, int row) -> Widget*;

    auto
    get_child_at (int column, int row) const -> const Widget*;

    void
    remove (Widget& child);

    void
    insert_row (int position);

    void
    insert_column (int position);

    void
    remove_row (int position);

    void
    remove_column (int position);

    void
    insert_next_to (Widget& sibling, PositionType side);

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

    void
    query_child (const Widget& child,
                 int& column,
                 int& row,
                 int& width,
                 int& height) const;

    auto
    property_row_spacing () -> Glib::PropertyProxy<guint>;

    auto
    property_row_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_column_spacing () -> Glib::PropertyProxy<guint>;

    auto
    property_column_spacing () const -> Glib::PropertyProxy_ReadOnly<guint>;

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
  wrap (GtkGrid* object, bool take_copy = false) -> Gtk::Grid*;
} // namespace Glib

#endif
