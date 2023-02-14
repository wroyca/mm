// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/extraclassinit.hxx>

namespace Glib
{

  ExtraClassInit::ExtraClassInit (const GClassInitFunc class_init_func,
                                  void* class_data,
                                  const GInstanceInitFunc instance_init_func)
  {
    if (class_init_func)
      add_custom_class_init_function (class_init_func, class_data);

    if (instance_init_func)
      set_custom_instance_init_function (instance_init_func);
  }

} // namespace Glib
