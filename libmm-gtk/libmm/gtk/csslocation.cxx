// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/csslocation.hxx>
#include <libmm/gtk/csslocation_p.hxx>

namespace Gtk
{

  CssLocation::CssLocation ()
    : gobject_{}
  {
  }

  CssLocation::CssLocation (const GtkCssLocation* location)
    : gobject_ (*location)
  {
  }

  CssLocation::CssLocation (std::size_t bytes,
                            std::size_t chars,
                            std::size_t lines,
                            std::size_t line_bytes,
                            std::size_t line_chars)
  {
    gobject_.bytes = bytes;
    gobject_.chars = chars;
    gobject_.lines = lines;
    gobject_.line_bytes = line_bytes;
    gobject_.line_chars = line_chars;
  }

} // namespace Gtk

namespace Glib
{

  auto
  wrap (const GtkCssLocation* object) -> Gtk::CssLocation
  {
    return Gtk::CssLocation (object);
  }

} // namespace Glib

namespace
{
}

namespace Gtk
{

  auto
  CssLocation::get_bytes () const -> std::size_t
  {
    return gobj ()->bytes;
  }

  auto
  CssLocation::set_bytes (const std::size_t& value) -> void
  {
    gobj ()->bytes = value;
  }

  auto
  CssLocation::get_chars () const -> std::size_t
  {
    return gobj ()->chars;
  }

  auto
  CssLocation::set_chars (const std::size_t& value) -> void
  {
    gobj ()->chars = value;
  }

  auto
  CssLocation::get_lines () const -> std::size_t
  {
    return gobj ()->lines;
  }

  auto
  CssLocation::set_lines (const std::size_t& value) -> void
  {
    gobj ()->lines = value;
  }

  auto
  CssLocation::get_line_bytes () const -> std::size_t
  {
    return gobj ()->line_bytes;
  }

  auto
  CssLocation::set_line_bytes (const std::size_t& value) -> void
  {
    gobj ()->line_bytes = value;
  }

  auto
  CssLocation::get_line_chars () const -> std::size_t
  {
    return gobj ()->line_chars;
  }

  auto
  CssLocation::set_line_chars (const std::size_t& value) -> void
  {
    gobj ()->line_chars = value;
  }

} // namespace Gtk
