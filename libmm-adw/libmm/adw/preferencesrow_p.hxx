// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESROW_P_H
#define _LIBADWAITAMM_PREFERENCESROW_P_H

#include <libmm/gtk/listboxrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesRow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PreferencesRow;
    using BaseObjectType = AdwPreferencesRow;
    using BaseClassType = AdwPreferencesRowClass;
    using CppClassParent = Gtk::ListBoxRow_Class;
    using BaseClassParent = GtkListBoxRowClass;

    friend class PreferencesRow;
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
