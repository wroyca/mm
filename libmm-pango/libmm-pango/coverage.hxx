// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_COVERAGE_H
#define _PANGOMM_COVERAGE_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/value.hxx>
#include <pango/pango.h>

namespace Pango
{

  class PANGOMM_API Coverage final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Coverage;
    using BaseObjectType = PangoCoverage;
#endif

    static auto
    create () -> Glib::RefPtr<Coverage>;

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

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

    void
    set (int index, Level level);
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Coverage::Level>
    : public Glib::Value_Enum<Pango::Coverage::Level>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoCoverage* object, bool take_copy = false) -> Glib::RefPtr<Pango::Coverage>;

} // namespace Glib

#endif
