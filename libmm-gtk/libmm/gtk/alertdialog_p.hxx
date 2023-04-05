// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ALERTDIALOG_P_H
#define _GTKMM_ALERTDIALOG_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AlertDialog_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AlertDialog;
    using BaseObjectType = GtkAlertDialog;
    using CppClassParent = glib::Object_Class;

    friend class AlertDialog;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
