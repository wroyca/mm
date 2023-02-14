// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/border.hxx>
#include <libmm-gtk/border_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBorder* object, const bool take_copy) -> Gtk::Border
  {
    return Gtk::Border (object, take_copy);
  }

} // namespace Glib

namespace Gtk
{

  auto
  Border::get_type () -> GType
  {
    return gtk_border_get_type ();
  }

  Border::Border ()
    : gobject_ (gtk_border_new ())
  {
  }

  Border::Border (const Border& other)
    : gobject_ (other.gobject_ ? gtk_border_copy (other.gobject_) : nullptr)
  {
  }

  Border::Border (Border&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  Border::operator= (Border&& other) noexcept -> Border&
  {
    Border temp (std::move (other));
    swap (temp);
    return *this;
  }

  Border::Border (GtkBorder* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? gtk_border_copy (gobject) : gobject)
  {
  }

  auto
  Border::operator= (const Border& other) -> Border&
  {
    Border temp (other);
    swap (temp);
    return *this;
  }

  Border::~Border () noexcept
  {
    if (gobject_)
      gtk_border_free (gobject_);
  }

  auto
  Border::swap (Border& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  Border::gobj_copy () const -> GtkBorder*
  {
    return gtk_border_copy (gobject_);
  }

  auto
  Border::get_left () const -> int
  {
    return gobj ()->left;
  }

  auto
  Border::set_left (const int& value) -> void
  {
    gobj ()->left = value;
  }

  auto
  Border::get_right () const -> int
  {
    return gobj ()->right;
  }

  auto
  Border::set_right (const int& value) -> void
  {
    gobj ()->right = value;
  }

  auto
  Border::get_top () const -> int
  {
    return gobj ()->top;
  }

  auto
  Border::set_top (const int& value) -> void
  {
    gobj ()->top = value;
  }

  auto
  Border::get_bottom () const -> int
  {
    return gobj ()->bottom;
  }

  auto
  Border::set_bottom (const int& value) -> void
  {
    gobj ()->bottom = value;
  }

} // namespace Gtk
