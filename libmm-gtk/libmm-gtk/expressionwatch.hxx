// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EXPRESSIONWATCH_H
#define _GTKMM_EXPRESSIONWATCH_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-glib/object.hxx>
#include <optional>

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ExpressionWatchBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ExpressionWatchBase;
    using BaseObjectType = GtkExpressionWatch;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GtkExpressionWatch*;

    auto
    gobj () const -> const GtkExpressionWatch*;

    auto
    gobj_copy () const -> GtkExpressionWatch*;

    ExpressionWatchBase () = delete;

    ExpressionWatchBase (const ExpressionWatchBase&) = delete;
    auto
    operator= (const ExpressionWatchBase&) -> ExpressionWatchBase& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    auto
    unwatch () -> void;
  };

  template <class T>
  class ExpressionWatch final : public ExpressionWatchBase
  {
  public:
    auto
    evaluate () -> std::optional<T>;
  };

  template <class T>
  auto
  ExpressionWatch<T>::evaluate () -> std::optional<T>
  {
    Glib::Value<T> value;
    bool result = gtk_expression_watch_evaluate (gobj (), value.gobj ());
    if (!result)
      return {};

    if (!G_VALUE_HOLDS (value.gobj (), Glib::Value<T>::value_type ()))
    {
      g_warning ("%s: The evaluated expression has type '%s', expected '%s'",
                 G_STRLOC,
                 g_type_name (G_VALUE_TYPE (value.gobj ())),
                 g_type_name (Glib::Value<T>::value_type ()));
      return {};
    }

    return value.get ();
  }

} // namespace Gtk

namespace Glib
{

  template <class T>
  auto
  wrap (GtkExpressionWatch* object, bool take_copy = false) -> RefPtr<Gtk::ExpressionWatch<T>>
  {
    if (take_copy && object)
      gtk_expression_watch_ref (object);

    return Glib::make_refptr_for_instance<Gtk::ExpressionWatch<T>> (
        reinterpret_cast<Gtk::ExpressionWatch<T>*> (object));
  }

} // namespace Glib

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkExpressionWatch* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ExpressionWatchBase>;

} // namespace Glib

#endif
