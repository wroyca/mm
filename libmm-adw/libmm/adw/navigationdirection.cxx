// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/navigationdirection.hxx>
#include <libmm/adw/navigationdirection_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::NavigationDirection>::value_type () -> GType
{
  return adw_navigation_direction_get_type ();
}
