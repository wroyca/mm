

#ifndef _GLIBMM_INTERFACE_P_H
#define _GLIBMM_INTERFACE_P_H

#include <libmm-glib/class.hxx>

namespace Glib
{

  class GLIBMM_API Interface_Class : public Class
  {
  public:
    using CppObjectType = Interface;
    using BaseClassType = GTypeInterface;

    auto
    add_interface (GType instance_type) const -> void;
  };

} // namespace Glib

#endif
