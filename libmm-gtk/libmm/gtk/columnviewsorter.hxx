// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEWSORTER_H
#define _GTKMM_COLUMNVIEWSORTER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/columnviewcolumn.hxx>
#include <libmm/gtk/sorter.hxx>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ColumnViewSorter_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ColumnViewSorter : public Sorter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ColumnViewSorter;
    using CppClassType = ColumnViewSorter_Class;
    using BaseObjectType = GtkColumnViewSorter;
    using BaseClassType = GtkColumnViewSorterClass;

    ColumnViewSorter (const ColumnViewSorter&) = delete;
    auto
    operator= (const ColumnViewSorter&) -> ColumnViewSorter& = delete;

  private:
    friend class ColumnViewSorter_Class;
    static CppClassType columnviewsorter_class_;

  protected:
    explicit ColumnViewSorter (const Glib::ConstructParams& construct_params);
    explicit ColumnViewSorter (GtkColumnViewSorter* castitem);

#endif

  public:
    ColumnViewSorter (ColumnViewSorter&& src) noexcept;
    auto
    operator= (ColumnViewSorter&& src) noexcept -> ColumnViewSorter&;

    ~ColumnViewSorter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColumnViewSorter*
    {
      return reinterpret_cast<GtkColumnViewSorter*> (gobject_);
    }

    auto
    gobj () const -> const GtkColumnViewSorter*
    {
      return reinterpret_cast<GtkColumnViewSorter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkColumnViewSorter*;

  private:
  protected:
    ColumnViewSorter ();

  public:
    auto
    get_primary_sort_column () -> Glib::RefPtr<ColumnViewColumn>;

    auto
    get_primary_sort_column () const -> Glib::RefPtr<const ColumnViewColumn>;

    auto
    get_primary_sort_order () const -> SortType;

    auto
    get_n_sort_columns () const -> unsigned int;

    auto
    get_nth_sort_column (unsigned int position)
        -> std::pair<Glib::RefPtr<ColumnViewColumn>, SortType>;

    auto
    get_nth_sort_column (unsigned int position) const
        -> std::pair<Glib::RefPtr<const ColumnViewColumn>, SortType>;

    auto
    property_primary_sort_column () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColumnViewColumn>>;

    auto
    property_primary_sort_order () const
        -> Glib::PropertyProxy_ReadOnly<SortType>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColumnViewSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColumnViewSorter>;
} // namespace Glib

#endif
