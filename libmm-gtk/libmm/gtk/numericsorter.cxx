// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/numericsorter.hxx>
#include <libmm/gtk/numericsorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkNumericSorter* object, bool take_copy) -> glib::RefPtr<gtk::NumericSorterBase>
  {
    return glib::make_refptr_for_instance<gtk::NumericSorterBase> (
        dynamic_cast<gtk::NumericSorterBase*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NumericSorterBase_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NumericSorterBase_Class::class_init_function;

      gtype_ = gtk_numeric_sorter_get_type ();
    }

    return *this;
  }

  auto
  NumericSorterBase_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NumericSorterBase_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NumericSorterBase ((GtkNumericSorter*) object);
  }

  auto
  NumericSorterBase::gobj_copy () -> GtkNumericSorter*
  {
    reference ();
    return gobj ();
  }

  NumericSorterBase::NumericSorterBase (
      const glib::ConstructParams& construct_params)
    : gtk::Sorter (construct_params)
  {
  }

  NumericSorterBase::NumericSorterBase (GtkNumericSorter* castitem)
    : gtk::Sorter ((GtkSorter*) (castitem))
  {
  }

  NumericSorterBase::NumericSorterBase (NumericSorterBase&& src) noexcept
    : gtk::Sorter (std::move (src))
  {
  }

  auto
  NumericSorterBase::operator= (NumericSorterBase&& src) noexcept -> NumericSorterBase&
  {
    gtk::Sorter::operator= (std::move (src));
    return *this;
  }

  NumericSorterBase::~NumericSorterBase () noexcept {}

  NumericSorterBase::CppClassType NumericSorterBase::numericsorterbase_class_;

  auto
  NumericSorterBase::get_type () -> GType
  {
    return numericsorterbase_class_.init ().get_type ();
  }

  auto
  NumericSorterBase::get_base_type () -> GType
  {
    return gtk_numeric_sorter_get_type ();
  }

  NumericSorterBase::NumericSorterBase (
      const glib::RefPtr<ExpressionBase>& expression)
    : glib::ObjectBase (nullptr),
      gtk::Sorter (glib::ConstructParams (
          numericsorterbase_class_.init (),
          "expression",
          ((expression) ? (expression)->gobj () : nullptr),
          nullptr))
  {
  }

  auto
  NumericSorterBase::get_sort_order () const -> SortType
  {
    return static_cast<SortType> (gtk_numeric_sorter_get_sort_order (
        const_cast<GtkNumericSorter*> (gobj ())));
  }

  auto
  NumericSorterBase::set_sort_order (SortType sort_order) -> void
  {
    gtk_numeric_sorter_set_sort_order (gobj (),
                                       static_cast<GtkSortType> (sort_order));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
      "Type SortType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  NumericSorterBase::property_sort_order () -> glib::PropertyProxy<SortType>
  {
    return glib::PropertyProxy<SortType> (this, "sort-order");
  }

  auto
  NumericSorterBase::property_sort_order () const -> glib::PropertyProxy_ReadOnly<SortType>
  {
    return glib::PropertyProxy_ReadOnly<SortType> (this, "sort-order");
  }

} // namespace gtk
