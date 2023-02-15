// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_EXPANDERROW_P_H
#define _LIBADWAITAMM_EXPANDERROW_P_H

#include <libmm-adw/preferencesrow_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class ExpanderRow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ExpanderRow;
    using BaseObjectType = AdwExpanderRow;
    using BaseClassType = AdwExpanderRowClass;
    using CppClassParent = Adw::PreferencesRow_Class;
    using BaseClassParent = AdwPreferencesRowClass;

    friend class ExpanderRow;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
