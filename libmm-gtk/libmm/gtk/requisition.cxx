// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/requisition.hxx>
#include <libmm/gtk/requisition_p.hxx>

#include <cstring>

namespace gtk
{

  Requisition::Requisition (int width, int height)
  {
    gobject_.width = width;
    gobject_.height = height;
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkRequisition* object) -> gtk::Requisition&
  {
    return *reinterpret_cast<gtk::Requisition*> (object);
  }

  auto
  wrap (const GtkRequisition* object) -> const gtk::Requisition&
  {
    return *reinterpret_cast<const gtk::Requisition*> (object);
  }

} // namespace glib

namespace gtk
{

  Requisition::Requisition (const Requisition& other) noexcept
    : gobject_ (other.gobject_)
  {
  }

  auto
  Requisition::operator= (const Requisition& other) noexcept -> Requisition&
  {
    gobject_ = other.gobject_;
    return *this;
  }

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

} // namespace gtk
