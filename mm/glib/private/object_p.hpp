// -*- c++ -*-

#ifndef _GLIBMM_OBJECT_P_H
#define _GLIBMM_OBJECT_P_H

#include <mm/glib/class.hpp>

namespace Glib
{

class GLIBMM_API Object_Class : public Glib::Class
{
public:
  using CppObjectType = Object;
  using BaseObjectType = GObject;
  using BaseClassType = GObjectClass;

  static auto class_init_function (void *g_class, void *class_data) -> void;

  auto init () -> const Glib::Class&;

  static auto wrap_new (GObject *) -> Glib::Object*;
};

} // namespace Glib

#endif /* _GLIBMM_OBJECT_P_H */
