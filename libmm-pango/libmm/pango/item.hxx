// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_ITEM_H
#define _PANGOMM_ITEM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/pango/attributes.hxx>
#include <libmm/pango/language.hxx>
#include <pango/pango.h>

namespace pango
{

  enum class ShapeFlags
  {
    NONE = 0x0,
    ROUND_POSITIONS = 1 << 0
  };

  inline auto
  operator| (ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  {
    return static_cast<ShapeFlags> (static_cast<unsigned> (lhs) |
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  {
    return static_cast<ShapeFlags> (static_cast<unsigned> (lhs) &
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (ShapeFlags lhs, ShapeFlags rhs) -> ShapeFlags
  {
    return static_cast<ShapeFlags> (static_cast<unsigned> (lhs) ^
                                    static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(ShapeFlags flags) -> ShapeFlags
  {
    return static_cast<ShapeFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  {
    return (lhs = static_cast<ShapeFlags> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  {
    return (lhs = static_cast<ShapeFlags> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (ShapeFlags& lhs, ShapeFlags rhs) -> ShapeFlags&
  {
    return (lhs = static_cast<ShapeFlags> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs)));
  }

} // namespace pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_PANGO_SYMEXPORT Value<pango::ShapeFlags>
    : public glib::Value_Flags<pango::ShapeFlags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace pango
{

  class Font;
  class GlyphString;

  class LIBMM_PANGO_SYMEXPORT Analysis
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Analysis;
    using BaseObjectType = PangoAnalysis;
#endif

  private:
  protected:
    Analysis ();

  public:
    explicit Analysis (const PangoAnalysis* src);

  public:
    auto
    get_font () -> glib::RefPtr<Font>;
    auto
    get_font () const -> glib::RefPtr<const Font>;

    auto
    get_level () const -> guint8;

    auto
    get_language () const -> Language;

    auto
    get_extra_attrs () const -> std::vector<Attribute>;

    auto
    gobj () -> PangoAnalysis*
    {
      return &gobject_;
    }

    auto
    gobj () const -> const PangoAnalysis*
    {
      return &gobject_;
    }

  protected:
    PangoAnalysis gobject_;
  };

  class LIBMM_PANGO_SYMEXPORT Item
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Item;
    using BaseObjectType = PangoItem;
#endif

  private:
  public:
    explicit Item (PangoItem* castitem, bool make_a_copy = true);

    Item (const Item& src);
    auto
    operator= (const Item& src) -> Item&;

    ~Item ();

    auto
    gobj_copy () const -> PangoItem*;

  public:
    auto
    split (int split_index, int split_offset) -> Item;

    auto
    get_offset () const -> int;

    auto
    get_length () const -> int;

    auto
    get_num_chars () const -> int;

    auto
    get_analysis () const -> Analysis;

    auto
    get_segment (const glib::ustring& text) const -> glib::ustring;

    auto
    shape (const glib::ustring& text) const -> GlyphString;

    auto
    shape (const glib::ustring& item_text,
           const glib::ustring& paragraph_text,
           ShapeFlags flags = ShapeFlags::NONE) const -> GlyphString;

    auto
    gobj () -> PangoItem*
    {
      return gobject_;
    }

    auto
    gobj () const -> const PangoItem*
    {
      return gobject_;
    }

  protected:
    PangoItem* gobject_;
  };

} // namespace pango

namespace glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoAnalysis* object) -> pango::Analysis&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (const PangoAnalysis* object) -> const pango::Analysis&;

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoItem* object, bool take_copy = true) -> pango::Item;

} // namespace glib

#endif
