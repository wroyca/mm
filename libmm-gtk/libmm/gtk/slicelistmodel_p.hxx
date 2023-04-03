// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SLICELISTMODEL_P_H
#define _GTKMM_SLICELISTMODEL_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT SliceListModel_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SliceListModel;
    using BaseObjectType = GtkSliceListModel;
    using BaseClassType = GtkSliceListModelClass;
    using CppClassParent = Glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SliceListModel;
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