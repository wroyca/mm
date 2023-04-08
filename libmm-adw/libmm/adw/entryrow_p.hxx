// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ENTRYROW_P_H
#define _LIBADWAITAMM_ENTRYROW_P_H

#include <libmm/adw/preferencesrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT entry_row_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = entry_row;
    using BaseObjectType = AdwEntryRow;
    using BaseClassType = AdwEntryRowClass;
    using CppClassParent = adw::preferences_row_class;
    using BaseClassParent = AdwPreferencesRowClass;

    friend class entry_row;
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
