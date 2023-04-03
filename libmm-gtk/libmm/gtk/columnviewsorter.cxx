// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/columnviewsorter.hxx>
#include <libmm/gtk/columnviewsorter_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  ColumnViewSorter::get_nth_sort_column (unsigned int position) -> std::pair<Glib::RefPtr<ColumnViewColumn>, SortType>
  {
    GtkSortType sort_order;
    auto retvalue = Glib::wrap (gtk_column_view_sorter_get_nth_sort_column (
        gobj (),
        position,
        (GtkSortType*) &sort_order));
    if (retvalue)
      retvalue->reference ();
    return {retvalue, (SortType) sort_order};
  }

  auto
  ColumnViewSorter::get_nth_sort_column (unsigned int position) const -> std::pair<Glib::RefPtr<const ColumnViewColumn>, SortType>
  {
    return const_cast<ColumnViewSorter*> (this)->get_nth_sort_column (position);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkColumnViewSorter* object, bool take_copy) -> Glib::RefPtr<Gtk::ColumnViewSorter>
  {
    return Glib::make_refptr_for_instance<Gtk::ColumnViewSorter> (
        dynamic_cast<Gtk::ColumnViewSorter*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColumnViewSorter_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_column_view_sorter_get_type ();
    }

    return *this;
  }

  auto
  ColumnViewSorter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ColumnViewSorter ((GtkColumnViewSorter*) object);
  }

  auto
  ColumnViewSorter::gobj_copy () -> GtkColumnViewSorter*
  {
    reference ();
    return gobj ();
  }

  ColumnViewSorter::ColumnViewSorter (
      const Glib::ConstructParams& construct_params)
    : Gtk::Sorter (construct_params)
  {
  }

  ColumnViewSorter::ColumnViewSorter (GtkColumnViewSorter* castitem)
    : Gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  ColumnViewSorter::ColumnViewSorter (ColumnViewSorter&& src) noexcept
    : Gtk::Sorter (std::move (src))
  {
  }

  auto
  ColumnViewSorter::operator= (ColumnViewSorter&& src) noexcept -> ColumnViewSorter&
  {
    Gtk::Sorter::operator= (std::move (src));
    return *this;
  }

  ColumnViewSorter::~ColumnViewSorter () noexcept {}

  ColumnViewSorter::CppClassType ColumnViewSorter::columnviewsorter_class_;

  auto
  ColumnViewSorter::get_type () -> GType
  {
    return columnviewsorter_class_.init ().get_type ();
  }

  auto
  ColumnViewSorter::get_base_type () -> GType
  {
    return gtk_column_view_sorter_get_type ();
  }

  ColumnViewSorter::ColumnViewSorter ()
    : Glib::ObjectBase (nullptr),
      Gtk::Sorter (Glib::ConstructParams (columnviewsorter_class_.init ()))
  {
  }

  auto
  ColumnViewSorter::get_primary_sort_column () -> Glib::RefPtr<ColumnViewColumn>
  {
    auto retvalue =
        Glib::wrap (gtk_column_view_sorter_get_primary_sort_column (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewSorter::get_primary_sort_column () const -> Glib::RefPtr<const ColumnViewColumn>
  {
    return const_cast<ColumnViewSorter*> (this)->get_primary_sort_column ();
  }

  auto
  ColumnViewSorter::get_primary_sort_order () const -> SortType
  {
    return static_cast<SortType> (
        gtk_column_view_sorter_get_primary_sort_order (
            const_cast<GtkColumnViewSorter*> (gobj ())));
  }

  auto
  ColumnViewSorter::get_n_sort_columns () const -> unsigned int
  {
    return gtk_column_view_sorter_get_n_sort_columns (
        const_cast<GtkColumnViewSorter*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<ColumnViewColumn>>::value,
      "Type Glib::RefPtr<ColumnViewColumn> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewSorter::property_primary_sort_column () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColumnViewColumn>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ColumnViewColumn>> (
        this,
        "primary-sort-column");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
      "Type SortType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ColumnViewSorter::property_primary_sort_order () const -> Glib::PropertyProxy_ReadOnly<SortType>
  {
    return Glib::PropertyProxy_ReadOnly<SortType> (this, "primary-sort-order");
  }

} // namespace Gtk
