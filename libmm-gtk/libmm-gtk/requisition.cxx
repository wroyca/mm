// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/requisition.hxx>
#include <libmm-gtk/requisition_p.hxx>

#include <cstring>

namespace Gtk
{

  Requisition::Requisition (const int width, const int height)
  {
    gobject_.width = width;
    gobject_.height = height;
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkRequisition* object) -> Gtk::Requisition&
  {
    return *reinterpret_cast<Gtk::Requisition*> (object);
  }

  auto
  wrap (const GtkRequisition* object) -> const Gtk::Requisition&
  {
    return *reinterpret_cast<const Gtk::Requisition*> (object);
  }

} // namespace Glib

namespace Gtk
{

  Requisition::Requisition (const Requisition& other) noexcept = default;

  auto
  Requisition::operator= (const Requisition& other) noexcept -> Requisition& = default;

  Requisition::Requisition (Requisition&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
  }

  auto
  Requisition::operator= (Requisition&& other) noexcept -> Requisition&
  {
    gobject_ = std::move (other.gobject_);
    return *this;
  }

  auto
  Requisition::get_type () -> GType
  {
    return gtk_requisition_get_type ();
  }

  Requisition::Requisition ()
  {
    std::memset (&gobject_, 0, sizeof (GtkRequisition));
  }

  Requisition::Requisition (const GtkRequisition* gobject)
  {
    if (gobject)
      gobject_ = *gobject;
    else
      std::memset (&gobject_, 0, sizeof (GtkRequisition));
  }

  auto
  Requisition::get_width () const -> int
  {
    return gobj ()->width;
  }

  auto
  Requisition::set_width (const int& value) -> void
  {
    gobj ()->width = value;
  }

  auto
  Requisition::get_height () const -> int
  {
    return gobj ()->height;
  }

  auto
  Requisition::set_height (const int& value) -> void
  {
    gobj ()->height = value;
  }

} // namespace Gtk
