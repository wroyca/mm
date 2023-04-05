// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ACTIONROW_P_H
#define _LIBADWAITAMM_ACTIONROW_P_H

#include <libmm/adw/preferencesrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ActionRow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ActionRow;
    using BaseObjectType = AdwActionRow;
    using BaseClassType = AdwActionRowClass;
    using CppClassParent = adw::PreferencesRow_Class;
    using BaseClassParent = AdwPreferencesRowClass;

    friend class ActionRow;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
