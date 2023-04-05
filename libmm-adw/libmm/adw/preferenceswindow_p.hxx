// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESWINDOW_P_H
#define _LIBADWAITAMM_PREFERENCESWINDOW_P_H

#include <libmm/adw/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesWindow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = PreferencesWindow;
    using BaseObjectType = AdwPreferencesWindow;
    using BaseClassType = AdwPreferencesWindowClass;
    using CppClassParent = adw::Window_Class;
    using BaseClassParent = AdwWindowClass;

    friend class PreferencesWindow;
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
