


#include <libmm-glib/mm-glib.hxx>

#include <libmm-glib/module.hxx>
#include <libmm-glib/module_p.hxx>


/* Copyright (C) 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-glib/utility.hxx>
#include <gmodule.h>

namespace Glib
{

Module::Module(const std::string& file_name, Flags flags)
: gobject_(g_module_open(file_name.c_str(), (GModuleFlags)flags))
{
}

Module::Module(Module&& other) noexcept : gobject_(std::move(other.gobject_))
{
  other.gobject_ = nullptr;
}

auto
Module::operator=(Module&& other) noexcept -> Module&
{
  if (gobject_)
    g_module_close(gobject_);

  gobject_ = std::move(other.gobject_);
  other.gobject_ = nullptr;

  return *this;
}

Module::~Module()
{
  if (gobject_)
    g_module_close(gobject_);
}

Module::operator bool() const
{
  return gobject_ != nullptr;
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{


auto Module::get_supported() -> bool
{
  return g_module_supported();
}

auto Module::make_resident () -> void
{
  g_module_make_resident(gobj());
}

auto Module::get_last_error() -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_module_error());
}

auto Module::get_symbol(const std::string& symbol_name, void*& symbol) const -> bool
{
  return g_module_symbol(const_cast<GModule*>(gobj()), symbol_name.c_str(), &symbol);
}

auto Module::get_name() const -> std::string
{
  return convert_const_gchar_ptr_to_stdstring(g_module_name(const_cast<GModule*>(gobj())));
}

auto Module::build_path(const std::string& directory, const std::string& module_name) -> std::string
{
  return convert_return_gchar_ptr_to_stdstring(g_module_build_path(directory.c_str(), module_name.c_str()));
}


} // namespace Glib


