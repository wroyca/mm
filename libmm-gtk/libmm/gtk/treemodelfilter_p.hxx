// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEMODELFILTER_P_H
#define _GTKMM_TREEMODELFILTER_P_H
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/object_p.hxx>

  #include <libmm/glib/class.hxx>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeModelFilter_Class : public glib::Class
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeModelFilter;
    using BaseObjectType = GtkTreeModelFilter;
    using BaseClassType = GtkTreeModelFilterClass;
    using CppClassParent = glib::Object_Class;
    using BaseClassParent = GObjectClass;

    friend class TreeModelFilter;
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

#endif
