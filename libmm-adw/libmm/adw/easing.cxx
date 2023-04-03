// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/easing.hxx>
#include <libmm/adw/easing_p.hxx>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  ease (Adw::Easing ease, double d) -> double
  {
    return adw_easing_ease (static_cast<AdwEasing> (ease), d);
  }

} // namespace Adw

namespace
{
}

auto
Glib::Value<Adw::Easing>::value_type () -> GType
{
  return adw_easing_get_type ();
}
