// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/layout.hxx>
#include <libmm/pango/layout_p.hxx>

#include <pango/pangocairo.h>

namespace pango
{

  namespace
  {

    struct LayoutLineTraits
    {
      typedef glib::RefPtr<LayoutLine> CppType;
      typedef PangoLayoutLine* CType;
      typedef PangoLayoutLine* CTypeNonConst;

      static auto
      to_c_type (const CppType& ptr) -> CType
      {
        return glib::unwrap (ptr);
      }

      static auto
      to_c_type (const CType ptr) -> CType
      {
        return ptr;
      }

      static auto
      to_cpp_type (const CType ptr) -> CppType
      {
        return glib::wrap (ptr, true);
      }

      static auto
      release_c_type (const CType ptr) -> void
      {
        pango_layout_line_unref (ptr);
      }
    };

    using SListHandler_LayoutLine =
        glib::SListHandler<glib::RefPtr<LayoutLine>, LayoutLineTraits>;
    using SListHandler_ConstLayoutLine =
        glib::SListHandler<glib::RefPtr<const LayoutLine>, LayoutLineTraits>;

  } // namespace

  Layout::Layout (const glib::RefPtr<Context>& context)
    : Object (G_OBJECT (pango_layout_new (context->gobj ())))
  {
  }

  auto
  Layout::create (const cairo::RefPtr<cairo::Context>& context) -> glib::RefPtr<Layout>
  {
    return glib::wrap (pango_cairo_create_layout (context->cobj ()));
  }

  auto
  Layout::update_from_cairo_context (
      const cairo::RefPtr<cairo::Context>& context) -> void
  {
    pango_cairo_update_layout (context->cobj (), gobj ());
  }

  auto
  Layout::set_text (const glib::ustring& text) -> void
  {
    pango_layout_set_text (gobj (), text.c_str (), text.bytes ());
  }

  auto
  Layout::set_markup (const glib::ustring& markup) -> void
  {
    return pango_layout_set_markup (gobj (), markup.c_str (), markup.bytes ());
  }

  auto
  Layout::set_markup (const glib::ustring& markup,
                      const gunichar accel_marker,
                      gunichar& accel_char) -> void
  {
    return pango_layout_set_markup_with_accel (gobj (),
                                               markup.c_str (),
                                               markup.bytes (),
                                               accel_marker,
                                               &accel_char);
  }

  auto
  Layout::get_log_attrs () const -> std::vector<PangoLogAttr>
  {
    int n_attrs = 0;
    const PangoLogAttr* const pAttrs = pango_layout_get_log_attrs_readonly (
        const_cast<PangoLayout*> (gobj ()),
        &n_attrs);

    return glib::ArrayHandler<PangoLogAttr>::array_to_vector (
        pAttrs,
        n_attrs,
        glib::OWNERSHIP_NONE);
  }

  auto
  Layout::index_to_pos (const int index) const -> Rectangle
  {
    Rectangle pos;
    pango_layout_index_to_pos (const_cast<PangoLayout*> (gobj ()),
                               index,
                               pos.gobj ());
    return pos;
  }

  auto
  Layout::get_cursor_strong_pos (const int index) const -> Rectangle
  {
    Rectangle strong_pos;
    pango_layout_get_cursor_pos (const_cast<PangoLayout*> (gobj ()),
                                 index,
                                 strong_pos.gobj (),
                                 0);
    return strong_pos;
  }

  auto
  Layout::get_cursor_weak_pos (const int index) const -> Rectangle
  {
    Rectangle weak_pos;
    pango_layout_get_cursor_pos (const_cast<PangoLayout*> (gobj ()),
                                 index,
                                 0,
                                 weak_pos.gobj ());
    return weak_pos;
  }

  auto
  Layout::get_ink_extents () const -> Rectangle
  {
    Rectangle ink_extents;
    pango_layout_get_extents (const_cast<PangoLayout*> (gobj ()),
                              ink_extents.gobj (),
                              0);
    return ink_extents;
  }

  auto
  Layout::get_logical_extents () const -> Rectangle
  {
    Rectangle logical_extents;
    pango_layout_get_extents (const_cast<PangoLayout*> (gobj ()),
                              0,
                              logical_extents.gobj ());
    return logical_extents;
  }

  auto
  Layout::get_pixel_ink_extents () const -> Rectangle
  {
    Rectangle ink_extents;
    pango_layout_get_pixel_extents (const_cast<PangoLayout*> (gobj ()),
                                    ink_extents.gobj (),
                                    0);
    return ink_extents;
  }

  auto
  Layout::get_pixel_logical_extents () const -> Rectangle
  {
    Rectangle logical_extents;
    pango_layout_get_pixel_extents (const_cast<PangoLayout*> (gobj ()),
                                    0,
                                    logical_extents.gobj ());
    return logical_extents;
  }

  auto
  Layout::get_iter () -> LayoutIter
  {
    auto* cobject = pango_layout_get_iter (gobj ());
    return glib::wrap (cobject, false);
  }

  auto
  Layout::unset_font_description () -> void
  {
    pango_layout_set_font_description (gobj (), 0);
  }

  auto
  Layout::add_to_cairo_context (const cairo::RefPtr<cairo::Context>& context) -> void
  {
    pango_cairo_layout_path (context->cobj (), gobj ());
  }

  auto
  Layout::show_in_cairo_context (const cairo::RefPtr<cairo::Context>& context) -> void
  {
    pango_cairo_show_layout (context->cobj (), gobj ());
  }

} // namespace pango

namespace
{
}

auto
glib::Value<pango::Alignment>::value_type () -> GType
{
  return pango_alignment_get_type ();
}

auto
glib::Value<pango::WrapMode>::value_type () -> GType
{
  return pango_wrap_mode_get_type ();
}

auto
glib::Value<pango::EllipsizeMode>::value_type () -> GType
{
  return pango_ellipsize_mode_get_type ();
}

namespace glib
{

  auto
  wrap (PangoLayout* object, const bool take_copy) -> RefPtr<pango::Layout>
  {
    return glib::make_refptr_for_instance<pango::Layout> (
        dynamic_cast<pango::Layout*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace pango
{

  auto
  Layout_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Layout_Class::class_init_function;

      register_derived_type (pango_layout_get_type ());
    }

    return *this;
  }

  auto
  Layout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Layout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Layout ((PangoLayout*) object);
  }

  auto
  Layout::gobj_copy () -> PangoLayout*
  {
    reference ();
    return gobj ();
  }

  Layout::Layout (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Layout::Layout (PangoLayout* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Layout::Layout (Layout&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Layout::operator= (Layout&& src) noexcept -> Layout&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Layout::~Layout () noexcept = default;

  Layout::CppClassType Layout::layout_class_;

  auto
  Layout::get_type () -> GType
  {
    return layout_class_.init ().get_type ();
  }

  auto
  Layout::get_base_type () -> GType
  {
    return pango_layout_get_type ();
  }

  auto
  Layout::create (const glib::RefPtr<Context>& context) -> glib::RefPtr<Layout>
  {
    return glib::make_refptr_for_instance<Layout> (new Layout (context));
  }

  auto
  Layout::copy () -> glib::RefPtr<Layout>
  {
    return glib::wrap (pango_layout_copy (gobj ()));
  }

  auto
  Layout::get_context () const -> glib::RefPtr<Context>
  {
    auto retvalue = glib::wrap (
        pango_layout_get_context (const_cast<PangoLayout*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Layout::set_attributes (AttrList& attrs) -> void
  {
    pango_layout_set_attributes (gobj (), attrs.gobj ());
  }

  auto
  Layout::get_attributes () const -> AttrList
  {
    return AttrList (
        pango_layout_get_attributes (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        pango_layout_get_text (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::get_character_count () const -> int
  {
    return pango_layout_get_character_count (
        const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_font_description (const FontDescription& desc) -> void
  {
    pango_layout_set_font_description (gobj (), desc.gobj ());
  }

  auto
  Layout::get_font_description () const -> FontDescription
  {
    return FontDescription (
        const_cast<PangoFontDescription*> (pango_layout_get_font_description (
            const_cast<PangoLayout*> (gobj ()))));
  }

  auto
  Layout::set_width (const int width) -> void
  {
    pango_layout_set_width (gobj (), width);
  }

  auto
  Layout::get_width () const -> int
  {
    return pango_layout_get_width (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_height (const int height) -> void
  {
    pango_layout_set_height (gobj (), height);
  }

  auto
  Layout::get_height () const -> int
  {
    return pango_layout_get_height (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_wrap (WrapMode wrap) -> void
  {
    pango_layout_set_wrap (gobj (), static_cast<PangoWrapMode> (wrap));
  }

  auto
  Layout::get_wrap () const -> WrapMode
  {
    return static_cast<WrapMode> (
        pango_layout_get_wrap (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::is_wrapped () const -> bool
  {
    return pango_layout_is_wrapped (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_indent (const int indent) -> void
  {
    pango_layout_set_indent (gobj (), indent);
  }

  auto
  Layout::get_indent () const -> int
  {
    return pango_layout_get_indent (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_spacing (const int spacing) -> void
  {
    pango_layout_set_spacing (gobj (), spacing);
  }

  auto
  Layout::get_spacing () const -> int
  {
    return pango_layout_get_spacing (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_line_spacing (const float factor) -> void
  {
    pango_layout_set_line_spacing (gobj (), factor);
  }

  auto
  Layout::get_line_spacing () const -> float
  {
    return pango_layout_get_line_spacing (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_justify (const bool justify) -> void
  {
    pango_layout_set_justify (gobj (), justify);
  }

  auto
  Layout::get_justify () const -> bool
  {
    return pango_layout_get_justify (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::get_auto_dir () const -> bool
  {
    return pango_layout_get_auto_dir (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_auto_dir (const bool auto_dir) -> void
  {
    pango_layout_set_auto_dir (gobj (), auto_dir);
  }

  auto
  Layout::set_alignment (Alignment alignment) -> void
  {
    pango_layout_set_alignment (gobj (),
                                static_cast<PangoAlignment> (alignment));
  }

  auto
  Layout::get_alignment () const -> Alignment
  {
    return static_cast<Alignment> (
        pango_layout_get_alignment (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::set_tabs (TabArray& tabs) -> void
  {
    pango_layout_set_tabs (gobj (), tabs.gobj ());
  }

  auto
  Layout::get_tabs () const -> TabArray
  {
    return TabArray (
        pango_layout_get_tabs (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::set_single_paragraph_mode (const bool setting) -> void
  {
    pango_layout_set_single_paragraph_mode (gobj (), setting);
  }

  auto
  Layout::get_single_paragraph_mode () const -> bool
  {
    return pango_layout_get_single_paragraph_mode (
        const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::set_ellipsize (EllipsizeMode ellipsize) -> void
  {
    pango_layout_set_ellipsize (gobj (),
                                static_cast<PangoEllipsizeMode> (ellipsize));
  }

  auto
  Layout::get_ellipsize () const -> EllipsizeMode
  {
    return static_cast<EllipsizeMode> (
        pango_layout_get_ellipsize (const_cast<PangoLayout*> (gobj ())));
  }

  auto
  Layout::is_ellipsized () const -> bool
  {
    return pango_layout_is_ellipsized (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::get_unknown_glyphs_count () const -> int
  {
    return pango_layout_get_unknown_glyphs_count (
        const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::context_changed () -> void
  {
    pango_layout_context_changed (gobj ());
  }

  auto
  Layout::get_serial () const -> guint
  {
    return pango_layout_get_serial (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::index_to_line_x (const int index_,
                           const bool trailing,
                           int& line,
                           int& x_pos) const -> void
  {
    pango_layout_index_to_line_x (const_cast<PangoLayout*> (gobj ()),
                                  index_,
                                  trailing,
                                  &line,
                                  &x_pos);
  }

  auto
  Layout::get_cursor_pos (const int index,
                          Rectangle& strong_pos,
                          Rectangle& weak_pos) const -> void
  {
    pango_layout_get_cursor_pos (const_cast<PangoLayout*> (gobj ()),
                                 index,
                                 strong_pos.gobj (),
                                 weak_pos.gobj ());
  }

  auto
  Layout::move_cursor_visually (const bool strong,
                                const int old_index,
                                const int old_trailing,
                                const int direction,
                                int& new_index,
                                int& new_trailing) const -> void
  {
    pango_layout_move_cursor_visually (const_cast<PangoLayout*> (gobj ()),
                                       strong,
                                       old_index,
                                       old_trailing,
                                       direction,
                                       &new_index,
                                       &new_trailing);
  }

  auto
  Layout::xy_to_index (const int x,
                       const int y,
                       int& index,
                       int& trailing) const -> bool
  {
    return pango_layout_xy_to_index (const_cast<PangoLayout*> (gobj ()),
                                     x,
                                     y,
                                     &index,
                                     &trailing);
  }

  auto
  Layout::get_extents (Rectangle& ink_rect, Rectangle& logical_rect) const -> void
  {
    pango_layout_get_extents (const_cast<PangoLayout*> (gobj ()),
                              ink_rect.gobj (),
                              logical_rect.gobj ());
  }

  auto
  Layout::get_pixel_extents (Rectangle& ink_rect, Rectangle& logical_rect) const -> void
  {
    pango_layout_get_pixel_extents (const_cast<PangoLayout*> (gobj ()),
                                    ink_rect.gobj (),
                                    logical_rect.gobj ());
  }

  auto
  Layout::get_size (int& width, int& height) const -> void
  {
    pango_layout_get_size (const_cast<PangoLayout*> (gobj ()), &width, &height);
  }

  auto
  Layout::get_pixel_size (int& width, int& height) const -> void
  {
    pango_layout_get_pixel_size (const_cast<PangoLayout*> (gobj ()),
                                 &width,
                                 &height);
  }

  auto
  Layout::get_baseline () const -> int
  {
    return pango_layout_get_baseline (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::get_line_count () const -> int
  {
    return pango_layout_get_line_count (const_cast<PangoLayout*> (gobj ()));
  }

  auto
  Layout::get_line (const int line) -> glib::RefPtr<LayoutLine>
  {
    auto retvalue = glib::wrap (pango_layout_get_line (gobj (), line));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Layout::get_line (const int line) const -> glib::RefPtr<const LayoutLine>
  {
    auto retvalue = glib::wrap (
        pango_layout_get_line_readonly (const_cast<PangoLayout*> (gobj ()),
                                        line));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Layout::get_const_line (const int line) const -> glib::RefPtr<const LayoutLine>
  {
    auto retvalue = glib::wrap (
        pango_layout_get_line_readonly (const_cast<PangoLayout*> (gobj ()),
                                        line));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Layout::get_lines () -> std::vector<glib::RefPtr<LayoutLine>>
  {
    return SListHandler_LayoutLine::slist_to_vector (
        pango_layout_get_lines (gobj ()),
        glib::OWNERSHIP_NONE);
  }

  auto
  Layout::get_lines () const -> std::vector<glib::RefPtr<const LayoutLine>>
  {
    return SListHandler_ConstLayoutLine::slist_to_vector (
        pango_layout_get_lines_readonly (const_cast<PangoLayout*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  Layout::get_const_lines () const -> std::vector<glib::RefPtr<const LayoutLine>>
  {
    return SListHandler_ConstLayoutLine::slist_to_vector (
        pango_layout_get_lines_readonly (const_cast<PangoLayout*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

} // namespace pango
