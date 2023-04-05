// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_TABARRAY_H
#define _PANGOMM_TABARRAY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/pango/attrlist.hxx>
#include <pango/pango.h>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoTabArray PangoTabArray;
}
#endif

namespace pango
{

  enum class TabAlign
  {
    LEFT,
    RIGHT,
    CENTER,
    DECIMAL
  };

} // namespace pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::TabAlign>
    : public glib::Value_Enum<pango::TabAlign>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace pango
{

  class LIBMM_PANGO_SYMEXPORT TabArray
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TabArray;
    using BaseObjectType = PangoTabArray;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    TabArray ();

    explicit TabArray (PangoTabArray* gobject, bool make_a_copy = true);

    TabArray (const TabArray& other);
    auto
    operator= (const TabArray& other) -> TabArray&;

    TabArray (TabArray&& other) noexcept;
    auto
    operator= (TabArray&& other) noexcept -> TabArray&;

    ~TabArray () noexcept;

    auto
    swap (TabArray& other) noexcept -> void;

    auto
    gobj () -> PangoTabArray*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoTabArray*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> PangoTabArray*;

  protected:
    PangoTabArray* gobject_;

  private:
  public:
    explicit TabArray (int initial_size, bool positions_in_pixels = true);

    auto
    get_size () const -> int;

    auto
    resize (int new_size) -> void;

    auto
    set_tab (int tab_index, TabAlign alignment, int location) -> void;

    auto
    get_tab (int tab_index) const -> std::pair<TabAlign, int>;

    auto
    get_tabs () const -> std::vector<std::pair<TabAlign, int>>;

    auto
    get_positions_in_pixels () const -> bool;
  };

} // namespace pango

namespace pango
{

  inline auto
  swap (TabArray& lhs, TabArray& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoTabArray* object, bool take_copy = false) -> pango::TabArray;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::TabArray>
    : public glib::Value_Boxed<pango::TabArray>
  {
  };
#endif

} // namespace glib

#endif
