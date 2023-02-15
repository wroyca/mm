// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NUMERICSORTER_H
#define _GTKMM_NUMERICSORTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/expression.hxx>
#include <libmm-gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API NumericSorterBase_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API NumericSorterBase : public Sorter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NumericSorterBase;
    using CppClassType = NumericSorterBase_Class;
    using BaseObjectType = GtkNumericSorter;
    using BaseClassType = GtkNumericSorterClass;

    NumericSorterBase (const NumericSorterBase&) = delete;
    auto
    operator= (const NumericSorterBase&) -> NumericSorterBase& = delete;

  private:
    friend class NumericSorterBase_Class;
    static CppClassType numericsorterbase_class_;

  protected:
    explicit NumericSorterBase (const Glib::ConstructParams& construct_params);
    explicit NumericSorterBase (GtkNumericSorter* castitem);

#endif

  public:
    NumericSorterBase (NumericSorterBase&& src) noexcept;
    auto
    operator= (NumericSorterBase&& src) noexcept -> NumericSorterBase&;

    ~NumericSorterBase () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNumericSorter*
    {
      return reinterpret_cast<GtkNumericSorter*> (gobject_);
    }

    auto
    gobj () const -> const GtkNumericSorter*
    {
      return reinterpret_cast<GtkNumericSorter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNumericSorter*;

  private:
  protected:
    explicit NumericSorterBase (const Glib::RefPtr<ExpressionBase>& expression);

  public:
    auto
    get_sort_order () const -> SortType;

    auto
    set_sort_order (SortType sort_order) -> void;

    auto
    property_sort_order () -> Glib::PropertyProxy<SortType>;

    auto
    property_sort_order () const -> Glib::PropertyProxy_ReadOnly<SortType>;

  public:
  public:
  protected:
  };

  template <class T>
  class NumericSorter : public NumericSorterBase
  {
    static_assert (std::is_arithmetic<T>::value);

  protected:
    NumericSorter (const Glib::RefPtr<Expression<T>>& expression);

  public:
    static auto
    create (const Glib::RefPtr<Expression<T>>& expression)
        -> Glib::RefPtr<NumericSorter>;

    auto
    get_expression () -> Glib::RefPtr<Expression<T>>;

    auto
    get_expression () const -> Glib::RefPtr<const Expression<T>>;

    auto
    set_expression (const Glib::RefPtr<Expression<T>>& expression) -> void;

    auto
    property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Expression<T>>>;

    auto
    property_expression () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>>;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T>
  NumericSorter<T>::NumericSorter (
      const Glib::RefPtr<Expression<T>>& expression)
    : NumericSorterBase (expression)
  {
  }

  template <class T>
  auto
  NumericSorter<T>::create (const Glib::RefPtr<Expression<T>>& expression) -> Glib::RefPtr<NumericSorter<T>>
  {
    return Glib::make_refptr_for_instance<NumericSorter> (
        new NumericSorter (expression));
  }

  template <class T>
  auto
  NumericSorter<T>::set_expression (
      const Glib::RefPtr<Expression<T>>& expression) -> void
  {
    gtk_numeric_sorter_set_expression (
        gobj (),
        const_cast<GtkExpression*> (expression->gobj ()));
  }

  template <class T>
  auto
  NumericSorter<T>::get_expression () -> Glib::RefPtr<Expression<T>>
  {
    return Glib::wrap<T> (gtk_numeric_sorter_get_expression (gobj ()), true);
  }

  template <class T>
  auto
  NumericSorter<T>::get_expression () const -> Glib::RefPtr<const Expression<T>>
  {
    return Glib::wrap<T> (gtk_numeric_sorter_get_expression (
                              const_cast<GtkNumericSorter*> (gobj ())),
                          true);
  }

  template <class T>
  auto
  NumericSorter<T>::property_expression () -> Glib::PropertyProxy<Glib::RefPtr<Expression<T>>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Expression<T>>> (this,
                                                             "expression");
  }

  template <class T>
  auto
  NumericSorter<T>::property_expression () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Expression<T>>> (
        this,
        "expression");
  }

#endif

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkNumericSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NumericSorterBase>;
} // namespace Glib

#endif
