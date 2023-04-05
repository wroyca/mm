// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/coverage.hxx>
#include <libmm/pango/coverage_p.hxx>

using Level = pango::Coverage::Level;

namespace
{
}

auto
glib::Value<pango::Coverage::Level>::value_type () -> GType
{
  return pango_coverage_level_get_type ();
}

namespace glib
{

  auto
  wrap (PangoCoverage* object, const bool take_copy) -> RefPtr<pango::Coverage>
  {
    if (take_copy && object)
      pango_coverage_ref (object);

    return glib::make_refptr_for_instance<pango::Coverage> (
        reinterpret_cast<pango::Coverage*> (object));
  }

} // namespace glib

namespace pango
{

  auto
  Coverage::create () -> glib::RefPtr<Coverage>
  {
    return glib::make_refptr_for_instance<Coverage> (
        reinterpret_cast<Coverage*> (pango_coverage_new ()));
  }

  auto
  Coverage::reference () const -> void
  {
    pango_coverage_ref (
        reinterpret_cast<PangoCoverage*> (const_cast<Coverage*> (this)));
  }

  auto
  Coverage::unreference () const -> void
  {
    pango_coverage_unref (
        reinterpret_cast<PangoCoverage*> (const_cast<Coverage*> (this)));
  }

  auto
  Coverage::gobj () -> PangoCoverage*
  {
    return reinterpret_cast<PangoCoverage*> (this);
  }

  auto
  Coverage::gobj () const -> const PangoCoverage*
  {
    return reinterpret_cast<const PangoCoverage*> (this);
  }

  auto
  Coverage::gobj_copy () const -> PangoCoverage*
  {
    const auto gobject =
        reinterpret_cast<PangoCoverage*> (const_cast<Coverage*> (this));
    pango_coverage_ref (gobject);
    return gobject;
  }

  auto
  Coverage::get (const int index) const -> Level
  {
    return static_cast<Level> (
        pango_coverage_get (const_cast<PangoCoverage*> (gobj ()), index));
  }

  auto
  Coverage::set (const int index, Level level) -> void
  {
    pango_coverage_set (gobj (),
                        index,
                        static_cast<PangoCoverageLevel> (level));
  }

} // namespace pango
