// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILEDIALOG_P_H
#define _GTKMM_FILEDIALOG_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API FileDialog_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = FileDialog;
    using BaseObjectType = GtkFileDialog;
    using CppClassParent = Glib::Object_Class;

    friend class FileDialog;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
