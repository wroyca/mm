#ifndef _GLIBMM_PATTERN_H
#define _GLIBMM_PATTERN_H

extern "C"
{
  using GPatternSpec = struct _GPatternSpec;
}

#include <libmm-glib/ustring.hxx>

namespace Glib
{

  class GLIBMM_API PatternSpec
  {
  public:
    explicit PatternSpec (const Glib::ustring& pattern);
    explicit PatternSpec (GPatternSpec* gobject);
    ~PatternSpec () noexcept;

    PatternSpec (const PatternSpec&) = delete;
    auto
    operator= (const PatternSpec&) -> PatternSpec& = delete;

    auto
    match (const Glib::ustring& str) const -> bool;
    auto
    match (const Glib::ustring& str, const Glib::ustring& str_reversed) const
        -> bool;

    auto
    operator== (const PatternSpec& rhs) const -> bool;
    auto
    operator!= (const PatternSpec& rhs) const -> bool;

    auto
    gobj () -> GPatternSpec*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GPatternSpec*
    {
      return gobject_;
    }

  private:
    GPatternSpec* gobject_;
  };

} // namespace Glib

#endif
