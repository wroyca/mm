// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_COVERAGE_H
#define _PANGOMM_COVERAGE_H

#include <libmm/pango/mm-pangoconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/value.hxx>
#include <pango/pango.h>

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT Coverage final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Coverage;
    using BaseObjectType = PangoCoverage;
#endif

    static auto
    create () -> glib::RefPtr<Coverage>;

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> PangoCoverage*;

    auto
    gobj () const -> const PangoCoverage*;

    auto
    gobj_copy () const -> PangoCoverage*;

    Coverage () = delete;

    Coverage (const Coverage&) = delete;
    auto
    operator= (const Coverage&) -> Coverage& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    enum class Level
    {
      NONE,
      FALLBACK,
      APPROXIMATE,
      EXACT
    };

    auto
    get (int index) const -> Level;

    auto
    set (int index, Level level) -> void;
  };

} // namespace pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::Coverage::Level>
    : public glib::Value_Enum<pango::Coverage::Level>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoCoverage* object, bool take_copy = false) -> glib::RefPtr<pango::Coverage>;

} // namespace glib

#endif
