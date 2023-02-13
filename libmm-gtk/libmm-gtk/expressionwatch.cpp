


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/expressionwatch.hpp>
#include <libmm-gtk/expressionwatch_p.hpp>


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

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<ExpressionWatchBase*>(gobject) is needed:
 *
 * A ExpressionWatchBase instance is in fact always a GtkExpressionWatch instance.
 * Unfortunately, GtkExpressionWatch cannot be a member of ExpressionWatchBase,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because ExpressionWatchBase does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

auto wrap(GtkExpressionWatch* object, const bool take_copy) -> RefPtr<Gtk::ExpressionWatchBase>
{
  if(take_copy && object)
    gtk_expression_watch_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::make_refptr_for_instance<Gtk::ExpressionWatchBase>(reinterpret_cast<Gtk::ExpressionWatchBase*>(object));
}

} // namespace Glib


namespace Gtk
{

auto ExpressionWatchBase::reference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_expression_watch_ref(reinterpret_cast<GtkExpressionWatch*>(const_cast<ExpressionWatchBase*>(this)));
}

auto ExpressionWatchBase::unreference () const -> void
{
  // See the comment at the top of this file, if you want to know why the cast works.
  gtk_expression_watch_unref(reinterpret_cast<GtkExpressionWatch*>(const_cast<ExpressionWatchBase*>(this)));
}

auto ExpressionWatchBase::gobj() -> GtkExpressionWatch*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GtkExpressionWatch*>(this);
}

auto ExpressionWatchBase::gobj() const -> const GtkExpressionWatch*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GtkExpressionWatch*>(this);
}

auto ExpressionWatchBase::gobj_copy() const -> GtkExpressionWatch*
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GtkExpressionWatch*>(const_cast<ExpressionWatchBase*>(this));
  gtk_expression_watch_ref(gobject);
  return gobject;
}


auto ExpressionWatchBase::unwatch () -> void
{
  gtk_expression_watch_unwatch(gobj());
}


} // namespace Gtk


