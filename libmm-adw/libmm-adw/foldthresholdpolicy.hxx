// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_FOLDTHRESHOLDPOLICY_H
#define _LIBADWAITAMM_FOLDTHRESHOLDPOLICY_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <adwaita.h>

namespace Adw
{

  enum class LIBMM_ADW_SYMEXPORT FoldThresholdPolicy
  {
    MINIMUM,
    NATURAL
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<Adw::FoldThresholdPolicy>
    : public Glib::Value_Enum<Adw::FoldThresholdPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

}

#endif
