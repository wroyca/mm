// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/srvtarget.hxx>
#include <libmm/gio/srvtarget_p.hxx>

#include <gio/gio.h>
#include <libmm/glib/utility.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSrvTarget* object, const bool take_copy) -> Gio::SrvTarget
  {
    return Gio::SrvTarget (object, take_copy);
  }

} // namespace Glib

namespace Gio
{

  auto
  SrvTarget::get_type () -> GType
  {
    return g_srv_target_get_type ();
  }

  SrvTarget::SrvTarget ()
    : gobject_ (nullptr)
  {
  }

  SrvTarget::SrvTarget (const SrvTarget& other)
    : gobject_ (other.gobject_ ? g_srv_target_copy (other.gobject_) : nullptr)
  {
  }

  SrvTarget::SrvTarget (SrvTarget&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  SrvTarget::operator= (SrvTarget&& other) noexcept -> SrvTarget&
  {
    SrvTarget temp (std::move (other));
    swap (temp);
    return *this;
  }

  SrvTarget::SrvTarget (GSrvTarget* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? g_srv_target_copy (gobject) : gobject)
  {
  }

  auto
  SrvTarget::operator= (const SrvTarget& other) -> SrvTarget&
  {
    SrvTarget temp (other);
    swap (temp);
    return *this;
  }

  SrvTarget::~SrvTarget () noexcept
  {
    if (gobject_)
      g_srv_target_free (gobject_);
  }

  auto
  SrvTarget::swap (SrvTarget& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  SrvTarget::gobj_copy () const -> GSrvTarget*
  {
    return g_srv_target_copy (gobject_);
  }

  auto
  SrvTarget::get_hostname () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_srv_target_get_hostname (const_cast<GSrvTarget*> (gobj ())));
  }

  auto
  SrvTarget::get_port () const -> guint16
  {
    return g_srv_target_get_port (const_cast<GSrvTarget*> (gobj ()));
  }

  auto
  SrvTarget::get_priority () const -> guint16
  {
    return g_srv_target_get_priority (const_cast<GSrvTarget*> (gobj ()));
  }

  auto
  SrvTarget::get_weight () const -> guint16
  {
    return g_srv_target_get_weight (const_cast<GSrvTarget*> (gobj ()));
  }

} // namespace Gio
