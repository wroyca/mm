// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NUMERICSORTER_H
#define _GTKMM_NUMERICSORTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT NumericSorterBase_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT NumericSorterBase : public Sorter
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
    explicit NumericSorterBase (const glib::ConstructParams& construct_params);
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
    explicit NumericSorterBase (const glib::RefPtr<ExpressionBase>& expression);

  public:
    auto
    get_sort_order () const -> SortType;

    auto
    set_sort_order (SortType sort_order) -> void;

    auto
    property_sort_order () -> glib::PropertyProxy<SortType>;

    auto
    property_sort_order () const -> glib::PropertyProxy_ReadOnly<SortType>;

  public:
  public:
  protected:
  };

  template <class T>
  class NumericSorter : public NumericSorterBase
  {
    static_assert (std::is_arithmetic<T>::value);

  protected:
    NumericSorter (const glib::RefPtr<Expression<T>>& expression);

  public:
    static auto
    create (const glib::RefPtr<Expression<T>>& expression)
        -> glib::RefPtr<NumericSorter>;

    auto
    get_expression () -> glib::RefPtr<Expression<T>>;

    auto
    get_expression () const -> glib::RefPtr<const Expression<T>>;

    auto
    set_expression (const glib::RefPtr<Expression<T>>& expression) -> void;

    auto
    property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<T>>>;

    auto
    property_expression () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<T>>>;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class T>
  NumericSorter<T>::NumericSorter (
      const glib::RefPtr<Expression<T>>& expression)
    : NumericSorterBase (expression)
  {
  }

  template <class T>
  auto
  NumericSorter<T>::create (const glib::RefPtr<Expression<T>>& expression) -> glib::RefPtr<NumericSorter<T>>
  {
    return glib::make_refptr_for_instance<NumericSorter> (
        new NumericSorter (expression));
  }

  template <class T>
  auto
  NumericSorter<T>::set_expression (
      const glib::RefPtr<Expression<T>>& expression) -> void
  {
    gtk_numeric_sorter_set_expression (
        gobj (),
        const_cast<GtkExpression*> (expression->gobj ()));
  }

  template <class T>
  auto
  NumericSorter<T>::get_expression () -> glib::RefPtr<Expression<T>>
  {
    return glib::wrap<T> (gtk_numeric_sorter_get_expression (gobj ()), true);
  }

  template <class T>
  auto
  NumericSorter<T>::get_expression () const -> glib::RefPtr<const Expression<T>>
  {
    return glib::wrap<T> (gtk_numeric_sorter_get_expression (
                              const_cast<GtkNumericSorter*> (gobj ())),
                          true);
  }

  template <class T>
  auto
  NumericSorter<T>::property_expression () -> glib::PropertyProxy<glib::RefPtr<Expression<T>>>
  {
    return glib::PropertyProxy<glib::RefPtr<Expression<T>>> (this,
                                                             "expression");
  }

  template <class T>
  auto
  NumericSorter<T>::property_expression () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<T>>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<T>>> (
        this,
        "expression");
  }

#endif

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNumericSorter* object, bool take_copy = false) -> glib::RefPtr<gtk::NumericSorterBase>;
} // namespace glib

#endif
