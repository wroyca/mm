// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/foldthresholdpolicy.hxx>
#include <libmm/adw/foldthresholdpolicy_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::FoldThresholdPolicy>::value_type () -> GType
{
  return adw_fold_threshold_policy_get_type ();
}
