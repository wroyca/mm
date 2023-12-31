// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_EXTRACLASSINIT_H
#define _GLIBMM_EXTRACLASSINIT_H

#include <libmm/glib/objectbase.hxx>

namespace glib
{

  class LIBMM_GLIB_SYMEXPORT ExtraClassInit : virtual public ObjectBase
  {
  protected:
    explicit ExtraClassInit (GClassInitFunc class_init_func,
                             void* class_data = nullptr,
                             GInstanceInitFunc instance_init_func = nullptr);
  };

} // namespace glib

#endif
