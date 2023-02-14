// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/expression.hxx>
#include <libmm-gtk/expression_p.hxx>

#include <libmm-gtk/expression.hxx>

namespace Gtk::Expression_Private
{

  auto
  watch_callback (const gpointer data) -> void
  {
    const auto slot = static_cast<sigc::slot<void ()>*> (data);
    (*slot) ();
  }

  auto
  closure_callback_func () -> void
  {
  }

} // namespace Gtk::Expression_Private

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkExpression* object, const bool take_copy) -> RefPtr<Gtk::ExpressionBase>
  {
    if (take_copy && object)
      gtk_expression_ref (object);

    return Glib::make_refptr_for_instance<Gtk::ExpressionBase> (
        reinterpret_cast<Gtk::ExpressionBase*> (object));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ExpressionBase::reference () const -> void
  {
    gtk_expression_ref (
        reinterpret_cast<GtkExpression*> (const_cast<ExpressionBase*> (this)));
  }

  auto
  ExpressionBase::unreference () const -> void
  {
    gtk_expression_unref (
        reinterpret_cast<GtkExpression*> (const_cast<ExpressionBase*> (this)));
  }

  auto
  ExpressionBase::gobj () -> GtkExpression*
  {
    return reinterpret_cast<GtkExpression*> (this);
  }

  auto
  ExpressionBase::gobj () const -> const GtkExpression*
  {
    return reinterpret_cast<const GtkExpression*> (this);
  }

  auto
  ExpressionBase::gobj_copy () const -> GtkExpression*
  {
    const auto gobject =
        reinterpret_cast<GtkExpression*> (const_cast<ExpressionBase*> (this));
    gtk_expression_ref (gobject);
    return gobject;
  }

  auto
  ExpressionBase::get_value_type () const -> GType
  {
    return gtk_expression_get_value_type (const_cast<GtkExpression*> (gobj ()));
  }

  auto
  ExpressionBase::is_static () const -> bool
  {
    return gtk_expression_is_static (const_cast<GtkExpression*> (gobj ()));
  }

} // namespace Gtk
