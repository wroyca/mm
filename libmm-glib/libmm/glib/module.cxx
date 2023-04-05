// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/module.hxx>
#include <libmm/glib/module_p.hxx>

#include <gmodule.h>
#include <libmm/glib/utility.hxx>

namespace glib
{

  Module::Module (const std::string& file_name, Flags flags)
    : gobject_ (g_module_open (file_name.c_str (), (GModuleFlags) flags))
  {
  }

  Module::Module (Module&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  Module::operator= (Module&& other) noexcept -> Module&
  {
    if (gobject_)
      g_module_close (gobject_);

    gobject_ = std::move (other.gobject_);
    other.gobject_ = nullptr;

    return *this;
  }

  Module::~Module ()
  {
    if (gobject_)
      g_module_close (gobject_);
  }

  Module::operator bool () const
  {
    return gobject_ != nullptr;
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  Module::get_supported () -> bool
  {
    return g_module_supported ();
  }

  auto
  Module::make_resident () -> void
  {
    g_module_make_resident (gobj ());
  }

  auto
  Module::get_last_error () -> std::string
  {
    return convert_const_gchar_ptr_to_stdstring (g_module_error ());
  }

  auto
  Module::get_symbol (const std::string& symbol_name, void*& symbol) const -> bool
  {
    return g_module_symbol (const_cast<GModule*> (gobj ()),
                            symbol_name.c_str (),
                            &symbol);
  }

  auto
  Module::get_name () const -> std::string
  {
    return convert_const_gchar_ptr_to_stdstring (
        g_module_name (const_cast<GModule*> (gobj ())));
  }

  auto
  Module::build_path (const std::string& directory,
                      const std::string& module_name) -> std::string
  {
    return convert_return_gchar_ptr_to_stdstring (
        g_module_build_path (directory.c_str (), module_name.c_str ()));
  }

} // namespace glib
