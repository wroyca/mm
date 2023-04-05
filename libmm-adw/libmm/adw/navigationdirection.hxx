// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_NAVIGATIONDIRECTION_H
#define _LIBADWAITAMM_NAVIGATIONDIRECTION_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <adwaita.h>

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT NavigationDirection
  {
    BACK,
    FORWARD
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::NavigationDirection>
    : public glib::Value_Enum<adw::NavigationDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

}

#endif
