// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/expressionwatch.hxx>
#include <libmm/gtk/expressionwatch_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkExpressionWatch* object, bool take_copy) -> glib::RefPtr<gtk::ExpressionWatchBase>
  {
    if (take_copy && object)
      gtk_expression_watch_ref (object);

    return glib::make_refptr_for_instance<gtk::ExpressionWatchBase> (
        reinterpret_cast<gtk::ExpressionWatchBase*> (object));
  }

} // namespace glib

namespace gtk
{

  auto
  ExpressionWatchBase::reference () const -> void
  {
    gtk_expression_watch_ref (reinterpret_cast<GtkExpressionWatch*> (
        const_cast<ExpressionWatchBase*> (this)));
  }

  auto
  ExpressionWatchBase::unreference () const -> void
  {
    gtk_expression_watch_unref (reinterpret_cast<GtkExpressionWatch*> (
        const_cast<ExpressionWatchBase*> (this)));
  }

  auto
  ExpressionWatchBase::gobj () -> GtkExpressionWatch*
  {
    return reinterpret_cast<GtkExpressionWatch*> (this);
  }

  auto
  ExpressionWatchBase::gobj () const -> const GtkExpressionWatch*
  {
    return reinterpret_cast<const GtkExpressionWatch*> (this);
  }

  auto
  ExpressionWatchBase::gobj_copy () const -> GtkExpressionWatch*
  {
    const auto gobject = reinterpret_cast<GtkExpressionWatch*> (
        const_cast<ExpressionWatchBase*> (this));
    gtk_expression_watch_ref (gobject);
    return gobject;
  }

  auto
  ExpressionWatchBase::unwatch () -> void
  {
    gtk_expression_watch_unwatch (gobj ());
  }

} // namespace gtk
