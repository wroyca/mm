// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ABOUTWINDOW_P_H
#define _LIBADWAITAMM_ABOUTWINDOW_P_H

#include <libmm/adw/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT about_window_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = about_window;
    using BaseObjectType = AdwAboutWindow;
    using CppClassParent = adw::Window_Class;

    friend class about_window;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
