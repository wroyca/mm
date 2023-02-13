


#include <mm/glib/mm-glib.hpp>

#include <mm/glib/optionentry.hpp>
#include <mm/glib/private/optionentry_p.hpp>


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

#include <mm/glib/utility.hpp>
#include <glib.h>

namespace Glib
{

using Flags = OptionEntry::Flags;

OptionEntry::OptionEntry()
{
  gobject_ = g_new0(GOptionEntry, 1);
}

OptionEntry::~OptionEntry()
{
  release_gobject();
}

auto OptionEntry::release_gobject () noexcept -> void
{
  if (!gobject_)
    return;

  g_free(const_cast<char*>(gobject_->long_name));
  g_free(const_cast<char*>(gobject_->description));
  g_free(const_cast<char*>(gobject_->arg_description));
  g_free(gobject_);
}

OptionEntry::OptionEntry(const OptionEntry& src)
{
  gobject_ = g_new0(GOptionEntry, 1);

  operator=(src);
}

auto
OptionEntry::operator=(const OptionEntry& src) -> OptionEntry&
{
  if (this != &src)
  {
    if (gobject_->long_name)
      g_free(const_cast<char*>(gobject_->long_name));

    gobject_->long_name = g_strdup(src.gobject_->long_name);

    gobject_->short_name = src.gobject_->short_name; // It's just one char.

    gobject_->flags = src.gobject_->flags;
    gobject_->arg = src.gobject_->arg;
    gobject_->arg_data =
      src.gobject_
        ->arg_data; // Shared, because it's not owned by any instance of this class anyway.

    if (gobject_->description)
      g_free(const_cast<char*>(gobject_->description));

    gobject_->description = g_strdup(src.gobject_->description);

    if (gobject_->arg_description)
      g_free(const_cast<char*>(gobject_->arg_description));

    gobject_->arg_description = g_strdup(src.gobject_->arg_description);
  }

  return *this;
}

OptionEntry::OptionEntry(OptionEntry&& other) noexcept : gobject_(std::move(other.gobject_))
{
  other.gobject_ = nullptr;
}

auto
OptionEntry::operator=(OptionEntry&& other) noexcept -> OptionEntry&
{
  release_gobject();

  gobject_ = std::move(other.gobject_);
  other.gobject_ = nullptr;

  return *this;
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{


auto OptionEntry::get_long_name() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(gobj()->long_name);
}

auto OptionEntry::set_long_name (const ustring &value) -> void
{
  g_free((char*)gobj()->long_name); // Cast away const, if any
  gobj()->long_name = g_strdup(value.c_str());
}

auto OptionEntry::get_short_name() const -> gchar
{
  return gobj()->short_name;
}

auto OptionEntry::set_short_name (const gchar &value) -> void
{
  gobj()->short_name = value;
}

auto OptionEntry::get_flags() const -> Flags
{
  return static_cast<Flags>(gobj()->flags);
}

auto OptionEntry::set_flags (const Flags &value) -> void
{
  gobj()->flags = static_cast<int>(value);
}

auto OptionEntry::get_description() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(gobj()->description);
}

auto OptionEntry::set_description (const ustring &value) -> void
{
  g_free((char*)gobj()->description); // Cast away const, if any
  gobj()->description = g_strdup(c_str_or_nullptr(value));
}

auto OptionEntry::get_arg_description() const -> ustring
{
  return convert_const_gchar_ptr_to_ustring(gobj()->arg_description);
}

auto OptionEntry::set_arg_description (const ustring &value) -> void
{
  g_free((char*)gobj()->arg_description); // Cast away const, if any
  gobj()->arg_description = g_strdup(c_str_or_nullptr(value));
}


} // namespace Glib


