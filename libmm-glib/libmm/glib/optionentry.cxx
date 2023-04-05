// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/glib/optionentry.hxx>
#include <libmm/glib/optionentry_p.hxx>

#include <glib.h>
#include <libmm/glib/utility.hxx>

namespace glib
{

  using Flags = OptionEntry::Flags;

  OptionEntry::OptionEntry ()
  {
    gobject_ = g_new0 (GOptionEntry, 1);
  }

  OptionEntry::~OptionEntry ()
  {
    release_gobject ();
  }

  auto
  OptionEntry::release_gobject () noexcept -> void
  {
    if (!gobject_)
      return;

    g_free (const_cast<char*> (gobject_->long_name));
    g_free (const_cast<char*> (gobject_->description));
    g_free (const_cast<char*> (gobject_->arg_description));
    g_free (gobject_);
  }

  OptionEntry::OptionEntry (const OptionEntry& src)
  {
    gobject_ = g_new0 (GOptionEntry, 1);

    operator= (src);
  }

  auto
  OptionEntry::operator= (const OptionEntry& src) -> OptionEntry&
  {
    if (this != &src)
    {
      if (gobject_->long_name)
        g_free (const_cast<char*> (gobject_->long_name));

      gobject_->long_name = g_strdup (src.gobject_->long_name);

      gobject_->short_name = src.gobject_->short_name;

      gobject_->flags = src.gobject_->flags;
      gobject_->arg = src.gobject_->arg;
      gobject_->arg_data = src.gobject_->arg_data;

      if (gobject_->description)
        g_free (const_cast<char*> (gobject_->description));

      gobject_->description = g_strdup (src.gobject_->description);

      if (gobject_->arg_description)
        g_free (const_cast<char*> (gobject_->arg_description));

      gobject_->arg_description = g_strdup (src.gobject_->arg_description);
    }

    return *this;
  }

  OptionEntry::OptionEntry (OptionEntry&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  OptionEntry::operator= (OptionEntry&& other) noexcept -> OptionEntry&
  {
    release_gobject ();

    gobject_ = std::move (other.gobject_);
    other.gobject_ = nullptr;

    return *this;
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  OptionEntry::get_long_name () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (gobj ()->long_name);
  }

  auto
  OptionEntry::set_long_name (const ustring& value) -> void
  {
    g_free ((char*) gobj ()->long_name);
    gobj ()->long_name = g_strdup (value.c_str ());
  }

  auto
  OptionEntry::get_short_name () const -> gchar
  {
    return gobj ()->short_name;
  }

  auto
  OptionEntry::set_short_name (const gchar& value) -> void
  {
    gobj ()->short_name = value;
  }

  auto
  OptionEntry::get_flags () const -> Flags
  {
    return static_cast<Flags> (gobj ()->flags);
  }

  auto
  OptionEntry::set_flags (const Flags& value) -> void
  {
    gobj ()->flags = static_cast<int> (value);
  }

  auto
  OptionEntry::get_description () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (gobj ()->description);
  }

  auto
  OptionEntry::set_description (const ustring& value) -> void
  {
    g_free ((char*) gobj ()->description);
    gobj ()->description = g_strdup (c_str_or_nullptr (value));
  }

  auto
  OptionEntry::get_arg_description () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (gobj ()->arg_description);
  }

  auto
  OptionEntry::set_arg_description (const ustring& value) -> void
  {
    g_free ((char*) gobj ()->arg_description);
    gobj ()->arg_description = g_strdup (c_str_or_nullptr (value));
  }

} // namespace glib
