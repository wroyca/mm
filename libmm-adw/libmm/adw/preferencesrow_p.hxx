// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESROW_P_H
#define _LIBADWAITAMM_PREFERENCESROW_P_H

#include <libmm/gtk/listboxrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_row_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = preferences_row;
    using BaseObjectType = AdwPreferencesRow;
    using BaseClassType = AdwPreferencesRowClass;
    using CppClassParent = gtk::ListBoxRow_Class;
    using BaseClassParent = GtkListBoxRowClass;

    friend class preferences_row;
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
