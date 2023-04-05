// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BINLAYOUT_P_H
#define _GTKMM_BINLAYOUT_P_H

#include <libmm/gtk/layoutmanager_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT BinLayout_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = BinLayout;
    using BaseObjectType = GtkBinLayout;
    using BaseClassType = GtkBinLayoutClass;
    using CppClassParent = LayoutManager_Class;
    using BaseClassParent = GtkLayoutManagerClass;

    friend class BinLayout;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace gtk

#endif
