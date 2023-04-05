// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SLICELISTMODEL_P_H
#define _GTKMM_SLICELISTMODEL_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SliceListModel_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SliceListModel;
    using BaseObjectType = GtkSliceListModel;
    using BaseClassType = GtkSliceListModelClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class SliceListModel;
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
