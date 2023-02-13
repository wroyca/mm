


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/expression.hxx>
#include <libmm-gtk/expression_p.hxx>


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

#include <libmm-gtk/expression.hxx>


namespace Gtk::Expression_Private
{

auto watch_callback (
  const gpointer data) -> void
{
  const auto slot = static_cast<sigc::slot<void()>*>(data);
  (*slot)();
}

auto closure_callback_func () -> void
{}

} // namespace Gtk

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<ExpressionBase*>(gobject) is needed:
 *
 * A ExpressionBase instance is in fact always a GtkExpression instance.
 * Unfortunately, GtkExpression cannot be a member of ExpressionBase,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ExpressionBase does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GtkExpression* object, const bool take_copy) -> RefPtr<Gtk::ExpressionBase>
{
  if(take_copy && object)
    gtk_expression_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gtk::ExpressionBase>(reinterpret_cast<Gtk::ExpressionBase*>(object));
}

} // namespace Glib


namespace Gtk
{

auto ExpressionBase::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_expression_ref(reinterpret_cast<GtkExpression*>(const_cast<ExpressionBase*>(this)));
}

auto ExpressionBase::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_expression_unref(reinterpret_cast<GtkExpression*>(const_cast<ExpressionBase*>(this)));
}

auto ExpressionBase::gobj() -> GtkExpression*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GtkExpression*>(this);
}

auto ExpressionBase::gobj() const -> const GtkExpression*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GtkExpression*>(this);
}

auto ExpressionBase::gobj_copy() const -> GtkExpression*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GtkExpression*>(const_cast<ExpressionBase*>(this));
  gtk_expression_ref(gobject);
  return gobject;
}


auto ExpressionBase::get_value_type() const -> GType
{
  return gtk_expression_get_value_type(const_cast<GtkExpression*>(gobj()));
}

auto ExpressionBase::is_static() const -> bool
{
  return gtk_expression_is_static(const_cast<GtkExpression*>(gobj()));
}


} // namespace Gtk


