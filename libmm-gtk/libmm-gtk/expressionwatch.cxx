

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/expressionwatch.hxx>
#include <libmm-gtk/expressionwatch_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkExpressionWatch* object, const bool take_copy) -> RefPtr<Gtk::ExpressionWatchBase>
  {
    if (take_copy && object)
      gtk_expression_watch_ref (object);

    return Glib::make_refptr_for_instance<Gtk::ExpressionWatchBase> (
        reinterpret_cast<Gtk::ExpressionWatchBase*> (object));
  }

} // namespace Glib

namespace Gtk
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

} // namespace Gtk
