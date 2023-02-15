// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREPAN_P_H
#define _GTKMM_GESTUREPAN_P_H

#include <libmm-gtk/gesturedrag_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GesturePan_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = GesturePan;
    using BaseObjectType = GtkGesturePan;
    using BaseClassType = GtkGesturePanClass;
    using CppClassParent = GestureDrag_Class;
    using BaseClassParent = GtkGestureDragClass;

    friend class GesturePan;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
