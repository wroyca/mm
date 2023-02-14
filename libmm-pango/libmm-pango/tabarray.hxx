
#ifndef _PANGOMM_TABARRAY_H
#define _PANGOMM_TABARRAY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-pango/attrlist.hxx>
#include <pango/pango.h>
#include <utility>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _PangoTabArray PangoTabArray;
}
#endif

namespace Pango
{

  enum class TabAlign
  {
    LEFT,
    RIGHT,
    CENTER,
    DECIMAL
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::TabAlign>
    : public Glib::Value_Enum<Pango::TabAlign>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class PANGOMM_API TabArray
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

    void
    swap (TabArray& other) noexcept;

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

    void
    resize (int new_size);

    void
    set_tab (int tab_index, TabAlign alignment, int location);

    auto
    get_tab (int tab_index) const -> std::pair<TabAlign, int>;

    auto
    get_tabs () const -> std::vector<std::pair<TabAlign, int>>;

    auto
    get_positions_in_pixels () const -> bool;
  };

} // namespace Pango

namespace Pango
{

  inline void
  swap (TabArray& lhs, TabArray& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoTabArray* object, bool take_copy = false) -> Pango::TabArray;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class PANGOMM_API Value<Pango::TabArray>
    : public Glib::Value_Boxed<Pango::TabArray>
  {
  };
#endif

} // namespace Glib

#endif
