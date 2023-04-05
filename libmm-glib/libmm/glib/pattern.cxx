// SPDX-License-Identifier: LGPL-2.1-or-later

#include <glib.h>
#include <libmm/glib/pattern.hxx>

namespace glib
{

  PatternSpec::PatternSpec (const ustring& pattern)
    : gobject_ (g_pattern_spec_new (pattern.c_str ()))
  {
  }

  PatternSpec::PatternSpec (GPatternSpec* gobject)
    : gobject_ (gobject)
  {
  }

  PatternSpec::~PatternSpec () noexcept
  {
    g_pattern_spec_free (gobject_);
  }

  G_GNUC_BEGIN_IGNORE_DEPRECATIONS
  auto
  PatternSpec::match (const ustring& str) const -> bool
  {
    return g_pattern_match (gobject_, str.bytes (), str.c_str (), nullptr);
  }

  auto
  PatternSpec::match (const ustring& str, const ustring& str_reversed) const -> bool
  {
    return g_pattern_match (gobject_,
                            str.bytes (),
                            str.c_str (),
                            str_reversed.c_str ());
  }

  G_GNUC_END_IGNORE_DEPRECATIONS

  auto
  PatternSpec::operator== (const PatternSpec& rhs) const -> bool
  {
    return g_pattern_spec_equal (gobject_, rhs.gobject_);
  }

  auto
  PatternSpec::operator!= (const PatternSpec& rhs) const -> bool
  {
    return !g_pattern_spec_equal (gobject_, rhs.gobject_);
  }

} // namespace glib
