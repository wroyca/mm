// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CSSLOCATION_H
#define _GTKMM_CSSLOCATION_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <cstddef>
#include <gtk/gtk.h>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CssLocation
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CssLocation;
    using BaseObjectType = GtkCssLocation;
#endif

  private:
  public:
    CssLocation ();
    CssLocation (const GtkCssLocation* location);
    CssLocation (std::size_t bytes,
                 std::size_t chars,
                 std::size_t lines,
                 std::size_t line_bytes,
                 std::size_t line_chars);

    auto
    get_bytes () const -> std::size_t;
    auto
    set_bytes (const std::size_t& value) -> void;

    auto
    get_chars () const -> std::size_t;
    auto
    set_chars (const std::size_t& value) -> void;

    auto
    get_lines () const -> std::size_t;
    auto
    set_lines (const std::size_t& value) -> void;

    auto
    get_line_bytes () const -> std::size_t;
    auto
    set_line_bytes (const std::size_t& value) -> void;

    auto
    get_line_chars () const -> std::size_t;
    auto
    set_line_chars (const std::size_t& value) -> void;

    auto
    gobj () -> GtkCssLocation*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const GtkCssLocation*
    {
      return &gobject_;
    }

  protected:
    GtkCssLocation gobject_;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (const GtkCssLocation* object) -> Gtk::CssLocation;

} // namespace Glib

#endif
