// -*- c++ -*-

#ifndef _GLIBMM_INTERFACE_P_H
#define _GLIBMM_INTERFACE_P_H

#include <mm/glib/class.hpp>

namespace Glib
{

class GLIBMM_API Interface_Class : public Class
{
public:
  using CppObjectType = Interface;
  using BaseClassType = GTypeInterface;

  auto add_interface (GType instance_type) const -> void;
};

} // namespace Glib

#endif /* _GLIBMM_INTERFACE_P_H */
