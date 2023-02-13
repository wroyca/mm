
#ifndef _GTKMM_MULTIFILTER_P_H
#define _GTKMM_MULTIFILTER_P_H


#include <mm/gtk/private/filter_p.hpp>

#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#include <mm/glib/class.hpp>

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
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  auto init () -> const Class&;


  static auto class_init_function (void *g_class, void *class_data) -> void;

  static auto wrap_new (GObject *) -> Glib::ObjectBase*;

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_MULTIFILTER_P_H */

