
#ifndef _GTKMM_EXPRESSIONWATCH_H
#define _GTKMM_EXPRESSIONWATCH_H

#include <libmm-gtk/mm-gtkconfig.hpp>


#include <libmm-glib/ustring.hpp>
#include <sigc++/sigc++.h>

/* Copyright (C) 2020 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */


#include <libmm-glib/object.hpp>
#include <gtk/gtk.h>
#include <optional>


namespace Gtk
{
class GTKMM_API ExpressionWatchBase
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = ExpressionWatchBase;
  using BaseObjectType = GtkExpressionWatch;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


  /** Increment the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void reference()   const;

  /** Decrement the reference count for this object.
   * You should never need to do this manually - use the object via a RefPtr instead.
   */
  void unreference() const;

  ///Provides access to the underlying C instance.
  auto       gobj() -> GtkExpressionWatch*;

  ///Provides access to the underlying C instance.
  auto gobj() const -> const GtkExpressionWatch*;

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  auto gobj_copy() const -> GtkExpressionWatch*;

  ExpressionWatchBase() = delete;

  // noncopyable
  ExpressionWatchBase(const ExpressionWatchBase&) = delete;
  auto operator=(const ExpressionWatchBase&) -> ExpressionWatchBase& = delete;

protected:
  // Do not derive this.  Gtk::ExpressionWatchBase can neither be constructed nor deleted.

  void operator delete(void*, std::size_t);

private:


public:

  /** Stops watching an expression that was established via Gtk::Expression::watch().
   */
  void unwatch();


};

template<class T>
class ExpressionWatch final : public ExpressionWatchBase
{
public:
  /** Evaluates the watched expression and on success returns the result.
   *
   * This is equivalent to calling Gtk::Expression::evaluate() with the
   * expression and this pointer originally used to create the watch.
   *
   * @return The optional result of the evaluation.
   */
  auto evaluate() -> std::optional<T>;
};

template<class T>
auto ExpressionWatch<T>::evaluate() -> std::optional<T>
{
  Glib::Value<T> value;
  bool result = gtk_expression_watch_evaluate(gobj(), value.gobj());
  if (!result)
    return {};

  if (!G_VALUE_HOLDS(value.gobj(), Glib::Value<T>::value_type()))
  {
    g_warning("%s: The evaluated expression has type '%s', expected '%s'", G_STRLOC,
      g_type_name(G_VALUE_TYPE(value.gobj())), g_type_name(Glib::Value<T>::value_type()));
    return {};
  }

  return value.get();
}

} // namespace Gtk

namespace Glib
{

template<class T>
auto wrap(GtkExpressionWatch* object, bool take_copy = false) -> RefPtr<Gtk::ExpressionWatch<T>>
{
  if (take_copy && object)
    gtk_expression_watch_ref(object);

  return Glib::make_refptr_for_instance<Gtk::ExpressionWatch<T>>(
    reinterpret_cast<Gtk::ExpressionWatch<T>*>(object));
}

} // namespace Glib


namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::ExpressionWatchBase
 */
GTKMM_API
auto wrap(GtkExpressionWatch* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ExpressionWatchBase>;

} // namespace Glib


#endif /* _GTKMM_EXPRESSIONWATCH_H */

