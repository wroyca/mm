// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/columnviewsorter.hxx>
#include <libmm/gtk/columnviewsorter_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  ColumnViewSorter::get_nth_sort_column (unsigned int position) -> std::pair<glib::RefPtr<ColumnViewColumn>, SortType>
  {
    GtkSortType sort_order;
    auto retvalue = glib::wrap (gtk_column_view_sorter_get_nth_sort_column (
        gobj (),
        position,
        (GtkSortType*) &sort_order));
    if (retvalue)
      retvalue->reference ();
    return {retvalue, (SortType) sort_order};
  }

  auto
  ColumnViewSorter::get_nth_sort_column (unsigned int position) const -> std::pair<glib::RefPtr<const ColumnViewColumn>, SortType>
  {
    return const_cast<ColumnViewSorter*> (this)->get_nth_sort_column (position);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkColumnViewSorter* object, bool take_copy) -> glib::RefPtr<gtk::ColumnViewSorter>
  {
    return glib::make_refptr_for_instance<gtk::ColumnViewSorter> (
        dynamic_cast<gtk::ColumnViewSorter*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  ColumnViewSorter_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_column_view_sorter_get_type ();
    }

    return *this;
  }

  auto
  ColumnViewSorter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
    : gtk::Sorter (construct_params)
  {
  }

  ColumnViewSorter::ColumnViewSorter (GtkColumnViewSorter* castitem)
    : gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  ColumnViewSorter::ColumnViewSorter (ColumnViewSorter&& src) noexcept
    : gtk::Sorter (std::move (src))
  {
  }

  auto
  ColumnViewSorter::operator= (ColumnViewSorter&& src) noexcept -> ColumnViewSorter&
  {
    gtk::Sorter::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Sorter (glib::ConstructParams (columnviewsorter_class_.init ()))
  {
  }

  auto
  ColumnViewSorter::get_primary_sort_column () -> glib::RefPtr<ColumnViewColumn>
  {
    auto retvalue =
        glib::wrap (gtk_column_view_sorter_get_primary_sort_column (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  ColumnViewSorter::get_primary_sort_column () const -> glib::RefPtr<const ColumnViewColumn>
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<ColumnViewColumn>>::value,
      "Type glib::RefPtr<ColumnViewColumn> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewSorter::property_primary_sort_column () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ColumnViewColumn>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<ColumnViewColumn>> (
        this,
        "primary-sort-column");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
      "Type SortType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ColumnViewSorter::property_primary_sort_order () const -> glib::PropertyProxy_ReadOnly<SortType>
  {
    return glib::PropertyProxy_ReadOnly<SortType> (this, "primary-sort-order");
  }

} // namespace gtk
