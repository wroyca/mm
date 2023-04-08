// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <libmm/adw/window_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{
  class LIBMM_ADW_SYMEXPORT about_window_class : public glib::Class
  {
    using CppObjectType  = about_window;
    using BaseObjectType = AdwAboutWindow;
    using CppClassParent = Window_Class;

  public:
    friend class about_window;
    auto init () -> const glib::Class &;
    static auto wrap_new (GObject *) -> glib::ObjectBase *;
  };
} // namespace adw
