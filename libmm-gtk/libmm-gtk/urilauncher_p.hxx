// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_URILAUNCHER_P_H
#define _GTKMM_URILAUNCHER_P_H

#include <libmm-glib/object_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT UriLauncher_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = UriLauncher;
    using BaseObjectType = GtkUriLauncher;
    using CppClassParent = Glib::Object_Class;

    friend class UriLauncher;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
