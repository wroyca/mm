// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GRIDLAYOUTCHILD_H
#define _GTKMM_GRIDLAYOUTCHILD_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gtk/layoutchild.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GridLayoutChild_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GridLayoutChild : public LayoutChild
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GridLayoutChild;
    using CppClassType = GridLayoutChild_Class;
    using BaseObjectType = GtkGridLayoutChild;
    using BaseClassType = GtkGridLayoutChildClass;

    GridLayoutChild (const GridLayoutChild&) = delete;
    auto
    operator= (const GridLayoutChild&) -> GridLayoutChild& = delete;

  private:
    friend class GridLayoutChild_Class;
    static CppClassType gridlayoutchild_class_;

  protected:
    explicit GridLayoutChild (const glib::ConstructParams& construct_params);
    explicit GridLayoutChild (GtkGridLayoutChild* castitem);

#endif

  public:
    GridLayoutChild (GridLayoutChild&& src) noexcept;
    auto
    operator= (GridLayoutChild&& src) noexcept -> GridLayoutChild&;

    ~GridLayoutChild () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGridLayoutChild*
    {
      return reinterpret_cast<GtkGridLayoutChild*> (gobject_);
    }

    auto
    gobj () const -> const GtkGridLayoutChild*
    {
      return reinterpret_cast<GtkGridLayoutChild*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGridLayoutChild*;

  private:
  protected:
    GridLayoutChild ();

  public:
    auto
    set_row (int row) -> void;

    auto
    get_row () const -> int;

    auto
    set_column (int column) -> void;

    auto
    get_column () const -> int;

    auto
    set_column_span (int span) -> void;

    auto
    get_column_span () const -> int;

    auto
    set_row_span (int span) -> void;

    auto
    get_row_span () const -> int;

    auto
    property_column () -> glib::PropertyProxy<int>;

    auto
    property_column () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_row () -> glib::PropertyProxy<int>;

    auto
    property_row () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_column_span () -> glib::PropertyProxy<int>;

    auto
    property_column_span () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_row_span () -> glib::PropertyProxy<int>;

    auto
    property_row_span () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGridLayoutChild* object, bool take_copy = false) -> glib::RefPtr<gtk::GridLayoutChild>;
} // namespace glib

#endif
