// -*- c++ -*-

#ifndef _GLIBMM_INTERFACE_P_H
#define _GLIBMM_INTERFACE_P_H

#include <mm/glib/class.h>

namespace Glib
{

class GLIBMM_API Interface_Class : public Glib::Class
{
public:
  using CppObjectType = Interface;
  using BaseClassType = GTypeInterface;

  void add_interface(GType instance_type) const;
};

} // namespace Glib

#endif /* _GLIBMM_INTERFACE_P_H */
