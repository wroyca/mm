// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/utility.hxx>

auto
Glib::append_canonical_typename (std::string& dest, const char* type_name)
    -> void
{
  const std::string::size_type offset = dest.size ();
  dest += type_name;

  std::string::iterator p = dest.begin () + offset;
  const std::string::iterator pend = dest.end ();

  for (; p != pend; ++p)
  {
    if (!(g_ascii_isalnum (*p) || *p == '_' || *p == '-'))
      *p = '+';
  }
}
