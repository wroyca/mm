// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/easing.hxx>
#include <libmm/adw/easing_p.hxx>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  ease (adw::Easing ease, double d) -> double
  {
    return adw_easing_ease (static_cast<AdwEasing> (ease), d);
  }

} // namespace adw

namespace
{
}

auto
glib::Value<adw::Easing>::value_type () -> GType
{
  return adw_easing_get_type ();
}
