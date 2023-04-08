// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <libmm/adw/preferencesrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{
  class LIBMM_ADW_SYMEXPORT action_row_class : public glib::Class
  {
    using CppObjectType = action_row;
    using BaseObjectType = AdwActionRow;
    using BaseClassType = AdwActionRowClass;
    using CppClassParent = PreferencesRow_Class;
    using BaseClassParent = AdwPreferencesRowClass;

  public:
    friend class action_row;

    auto init () -> const Class &;
    static auto class_init_function (void *g_class, void *class_data) -> void;
    static auto wrap_new (GObject *) -> glib::ObjectBase *;
  };
} // namespace adw
