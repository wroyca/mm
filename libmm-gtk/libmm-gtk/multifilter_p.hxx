
#ifndef _GTKMM_MULTIFILTER_P_H
#define _GTKMM_MULTIFILTER_P_H

#include <libmm-gtk/filter_p.hxx>

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API MultiFilter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = MultiFilter;
    using BaseObjectType = GtkMultiFilter;
    using BaseClassType = GtkMultiFilterClass;
    using CppClassParent = Filter_Class;
    using BaseClassParent = GtkFilterClass;

    friend class MultiFilter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API AnyFilter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = AnyFilter;
    using BaseObjectType = GtkAnyFilter;
    using BaseClassType = GtkAnyFilterClass;
    using CppClassParent = MultiFilter_Class;
    using BaseClassParent = GtkMultiFilterClass;

    friend class AnyFilter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#include <libmm-glib/class.hxx>

namespace Gtk
{

  class GTKMM_API EveryFilter_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = EveryFilter;
    using BaseObjectType = GtkEveryFilter;
    using BaseClassType = GtkEveryFilterClass;
    using CppClassParent = MultiFilter_Class;
    using BaseClassParent = GtkMultiFilterClass;

    friend class EveryFilter;
#endif

    auto
    init () -> const Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Gtk

#endif
