

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/numericsorter.hxx>
#include <libmm-gtk/numericsorter_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkNumericSorter* object, const bool take_copy) -> RefPtr<Gtk::NumericSorterBase>
  {
    return Glib::make_refptr_for_instance<Gtk::NumericSorterBase> (
        dynamic_cast<Gtk::NumericSorterBase*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  NumericSorterBase_Class::init () -> const Class&
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
  NumericSorterBase_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Sorter (construct_params)
  {
  }

  NumericSorterBase::NumericSorterBase (GtkNumericSorter* castitem)
    : Sorter ((GtkSorter*) castitem)
  {
  }

  NumericSorterBase::NumericSorterBase (NumericSorterBase&& src) noexcept
    : Sorter (std::move (src))
  {
  }

  auto
  NumericSorterBase::operator= (NumericSorterBase&& src) noexcept -> NumericSorterBase&
  {
    Sorter::operator= (std::move (src));
    return *this;
  }

  NumericSorterBase::~NumericSorterBase () noexcept = default;

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
      const Glib::RefPtr<ExpressionBase>& expression)
    : ObjectBase (nullptr),
      Sorter (Glib::ConstructParams (numericsorterbase_class_.init (),
                                     "expression",
                                     expression ? expression->gobj () : nullptr,
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
      Glib::Traits::ValueCompatibleWithWrapProperty<SortType>::value,
      "Type SortType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  NumericSorterBase::property_sort_order () -> Glib::PropertyProxy<SortType>
  {
    return {this, "sort-order"};
  }

  auto
  NumericSorterBase::property_sort_order () const -> Glib::PropertyProxy_ReadOnly<SortType>
  {
    return {this, "sort-order"};
  }

} // namespace Gtk
