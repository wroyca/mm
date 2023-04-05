// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NATIVEDIALOG_P_H
#define _GTKMM_NATIVEDIALOG_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT NativeDialog_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NativeDialog;
    using BaseObjectType = GtkNativeDialog;
    using BaseClassType = GtkNativeDialogClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class NativeDialog;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
    static auto
    response_callback (GtkNativeDialog* self, gint p0) -> void;
  };

} // namespace gtk

#endif
