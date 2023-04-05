// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/expression_p.hxx>

#include <libmm/gtk/expression.hxx>

namespace gtk
{

  namespace Expression_Private
  {

    auto
    watch_callback (gpointer data) -> void
    {
      auto slot = static_cast<sigc::slot<void ()>*> (data);
      (*slot) ();
    }

    auto
    closure_callback_func () -> void
    {
    }

  } // namespace Expression_Private

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkExpression* object, bool take_copy) -> glib::RefPtr<gtk::ExpressionBase>
  {
    if (take_copy && object)
      gtk_expression_ref (object);

    return glib::make_refptr_for_instance<gtk::ExpressionBase> (
        reinterpret_cast<gtk::ExpressionBase*> (object));
  }

} // namespace glib

namespace gtk
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

} // namespace gtk
