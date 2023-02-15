// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_LAYOUT_H
#define _PANGOMM_LAYOUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-pango/attrlist.hxx>
#include <libmm-pango/context.hxx>
#include <libmm-pango/font.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <libmm-pango/layoutiter.hxx>
#include <libmm-pango/layoutline.hxx>
#include <libmm-pango/tabarray.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoLayout = struct _PangoLayout;
using PangoLayoutClass = struct _PangoLayoutClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class PANGOMM_API Layout_Class;
}
#endif

namespace Pango
{

  enum class Alignment
  {
    LEFT,
    CENTER,
    RIGHT
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::Alignment>
    : public Glib::Value_Enum<Pango::Alignment>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class WrapMode
  {
    WORD,
    CHAR,
    WORD_CHAR
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::WrapMode>
    : public Glib::Value_Enum<Pango::WrapMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  enum class EllipsizeMode
  {
    NONE,
    START,
    MIDDLE,
    END
  };

} // namespace Pango

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class PANGOMM_API Value<Pango::EllipsizeMode>
    : public Glib::Value_Enum<Pango::EllipsizeMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Pango
{

  class PANGOMM_API Layout : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Layout;
    using CppClassType = Layout_Class;
    using BaseObjectType = PangoLayout;
    using BaseClassType = PangoLayoutClass;

    Layout (const Layout&) = delete;
    auto
    operator= (const Layout&) -> Layout& = delete;

  private:
    friend class Layout_Class;
    static CppClassType layout_class_;

  protected:
    explicit Layout (const Glib::ConstructParams& construct_params);
    explicit Layout (PangoLayout* castitem);

#endif

  public:
    Layout (Layout&& src) noexcept;
    auto
    operator= (Layout&& src) noexcept -> Layout&;

    ~Layout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoLayout*
    {
      return reinterpret_cast<PangoLayout*> (gobject_);
    }

    auto
    gobj () const -> const PangoLayout*
    {
      return reinterpret_cast<PangoLayout*> (gobject_);
    }

    auto
    gobj_copy () -> PangoLayout*;

  private:
  protected:
    explicit Layout (const Glib::RefPtr<Context>& context);

  public:
    static auto
    create (const Glib::RefPtr<Context>& context) -> Glib::RefPtr<Layout>;

    static auto
    create (const Cairo::RefPtr<Cairo::Context>& context)
        -> Glib::RefPtr<Layout>;

    auto
    update_from_cairo_context (const Cairo::RefPtr<Cairo::Context>& context)
        -> void;

    auto
    copy () -> Glib::RefPtr<Layout>;

    auto
    get_context () const -> Glib::RefPtr<Context>;

    auto
    set_attributes (AttrList& attrs) -> void;

    auto
    get_attributes () const -> AttrList;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    get_text () const -> Glib::ustring;

    auto
    get_character_count () const -> int;

    auto
    set_markup (const Glib::ustring& markup) -> void;

    auto
    set_markup (const Glib::ustring& markup,
                gunichar accel_marker,
                gunichar& accel_char) -> void;

    auto
    set_font_description (const FontDescription& desc) -> void;
    auto
    unset_font_description () -> void;

    auto
    get_font_description () const -> FontDescription;

    auto
    set_width (int width) -> void;

    auto
    get_width () const -> int;

    auto
    set_height (int height) -> void;

    auto
    get_height () const -> int;

    auto
    set_wrap (WrapMode wrap) -> void;

    auto
    get_wrap () const -> WrapMode;

    auto
    is_wrapped () const -> bool;

    auto
    set_indent (int indent) -> void;

    auto
    get_indent () const -> int;

    auto
    set_spacing (int spacing) -> void;

    auto
    get_spacing () const -> int;

    auto
    set_line_spacing (float factor) -> void;

    auto
    get_line_spacing () const -> float;

    auto
    set_justify (bool justify = true) -> void;

    auto
    get_justify () const -> bool;

    auto
    get_auto_dir () const -> bool;

    auto
    set_auto_dir (bool auto_dir = true) -> void;

    auto
    set_alignment (Alignment alignment) -> void;

    auto
    get_alignment () const -> Alignment;

    auto
    set_tabs (TabArray& tabs) -> void;

    auto
    get_tabs () const -> TabArray;

    auto
    set_single_paragraph_mode (bool setting = true) -> void;

    auto
    get_single_paragraph_mode () const -> bool;

    auto
    set_ellipsize (EllipsizeMode ellipsize) -> void;

    auto
    get_ellipsize () const -> EllipsizeMode;

    auto
    is_ellipsized () const -> bool;

    auto
    get_unknown_glyphs_count () const -> int;

    auto
    context_changed () -> void;

    auto
    get_serial () const -> guint;

    auto
    get_log_attrs () const -> std::vector<LogAttr>;

    auto
    index_to_pos (int index) const -> Rectangle;

    auto
    index_to_line_x (int index_, bool trailing, int& line, int& x_pos) const
        -> void;

    auto
    get_cursor_pos (int index, Rectangle& strong_pos, Rectangle& weak_pos) const
        -> void;

    auto
    get_cursor_strong_pos (int index) const -> Rectangle;

    auto
    get_cursor_weak_pos (int index) const -> Rectangle;

    auto
    move_cursor_visually (bool strong,
                          int old_index,
                          int old_trailing,
                          int direction,
                          int& new_index,
                          int& new_trailing) const -> void;

    auto
    xy_to_index (int x, int y, int& index, int& trailing) const -> bool;

    auto
    get_extents (Rectangle& ink_rect, Rectangle& logical_rect) const -> void;

    auto
    get_ink_extents () const -> Rectangle;

    auto
    get_logical_extents () const -> Rectangle;

    auto
    get_pixel_extents (Rectangle& ink_rect, Rectangle& logical_rect) const
        -> void;

    auto
    get_pixel_ink_extents () const -> Rectangle;

    auto
    get_pixel_logical_extents () const -> Rectangle;

    auto
    get_size (int& width, int& height) const -> void;

    auto
    get_pixel_size (int& width, int& height) const -> void;

    auto
    get_baseline () const -> int;

    auto
    get_line_count () const -> int;

    auto
    get_line (int line) -> Glib::RefPtr<LayoutLine>;

    auto
    get_line (int line) const -> Glib::RefPtr<const LayoutLine>;

    auto
    get_const_line (int line) const -> Glib::RefPtr<const LayoutLine>;

    auto
    get_lines () -> std::vector<Glib::RefPtr<LayoutLine>>;

    auto
    get_lines () const -> std::vector<Glib::RefPtr<const LayoutLine>>;

    auto
    get_const_lines () const -> std::vector<Glib::RefPtr<const LayoutLine>>;

    auto
    get_iter () -> LayoutIter;

    auto
    add_to_cairo_context (const Cairo::RefPtr<Cairo::Context>& context) -> void;

    auto
    show_in_cairo_context (const Cairo::RefPtr<Cairo::Context>& context)
        -> void;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoLayout* object, bool take_copy = false) -> Glib::RefPtr<Pango::Layout>;
} // namespace Glib

#endif
