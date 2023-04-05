// SPDX-License-Identifier: LGPL-2.1-or-later

#include <glib.h>
#include <libmm/glib/utility.hxx>
#include <libmm/glib/value.hxx>

namespace
{

  auto
  warn_already_registered (const char* location, const std::string& full_name) -> void
  {
    g_warning (
        "file %s: (%s): The type name `%s' has been registered already.\n"
        "This is not supposed to happen -- please send a mail with detailed "
        "information about your platform to gtkmm-list@gnome.org.  Thanks.\n",
        __FILE__,
        location,
        full_name.c_str ());
  }

} // namespace

namespace glib
{

  auto
  custom_boxed_type_register (const char* type_name,
                              const ValueInitFunc init_func,
                              const ValueFreeFunc free_func,
                              const ValueCopyFunc copy_func) -> GType
  {
    std::string full_name ("glibmm__CustomBoxed_");
    append_canonical_typename (full_name, type_name);

    if (const GType existing_type = g_type_from_name (full_name.c_str ()))
    {
      warn_already_registered ("glib::custom_boxed_type_register", full_name);
      return existing_type;
    }

    const GTypeValueTable value_table = {
        init_func,
        free_func,
        copy_func,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
    };

    const GTypeInfo type_info = {
        0,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        0,
        0,
        nullptr,
        &value_table,
    };

    return g_type_register_static (G_TYPE_BOXED,
                                   full_name.c_str (),
                                   &type_info,
                                   GTypeFlags (0));
  }

  auto
  custom_pointer_type_register (const char* type_name) -> GType
  {
    std::string full_name ("glibmm__CustomPointer_");
    append_canonical_typename (full_name, type_name);

    if (const GType existing_type = g_type_from_name (full_name.c_str ()))
    {
      warn_already_registered ("glib::custom_pointer_type_register", full_name);
      return existing_type;
    }

    const GTypeInfo type_info = {
        0,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        0,
        0,
        nullptr,
        nullptr,
    };

    return g_type_register_static (G_TYPE_POINTER,
                                   full_name.c_str (),
                                   &type_info,
                                   GTypeFlags (0));
  }

} // namespace glib
