// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_CLASS_H
#define _GLIBMM_CLASS_H

#include <glib-object.h>
#include <libmm-glib/mm-glibconfig.hxx>

#include <tuple>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace Glib
{
  class GLIBMM_API Interface_Class;

  class GLIBMM_API Class
  {
  public:
    inline auto
    get_type () const -> GType;

    using interface_classes_type = std::vector<const Interface_Class*>;

    using class_init_funcs_type =
        std::vector<std::tuple<GClassInitFunc, void*>>;

    auto
    clone_custom_type (const char* custom_type_name,
                       const interface_classes_type* interface_classes,
                       const class_init_funcs_type* class_init_funcs,
                       GInstanceInitFunc instance_init_func) const -> GType;

  protected:
    GType gtype_;
    GClassInitFunc class_init_func_;

    auto
    register_derived_type (GType base_type) -> void;

    auto
    register_derived_type (GType base_type, GTypeModule* module) -> void;

  private:
    static auto
    custom_class_base_finalize_function (void* g_class) -> void;
    static auto
    custom_class_init_function (void* g_class, void* class_data) -> void;

  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    using iface_properties_type = std::vector<GValue*>;

    static GQuark iface_properties_quark;
  #endif
  };

  inline auto
  Class::get_type () const -> GType
  {
    return gtype_;
  }

} // namespace Glib

#endif

#endif
