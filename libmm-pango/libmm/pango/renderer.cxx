// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/renderer.hxx>
#include <libmm/pango/renderer_p.hxx>

#include <pango/pango.h>

using Part = pango::Renderer::Part;

namespace pango
{

  auto
  Renderer::get_matrix () const -> Matrix
  {
    const auto* matrix =
        pango_renderer_get_matrix (const_cast<PangoRenderer*> (gobj ()));
    if (matrix)
      return *matrix;
    else
    {
      const PangoMatrix identity_transform = PANGO_MATRIX_INIT;
      return identity_transform;
    }
  }

} // namespace pango

namespace
{
}

auto
glib::Value<pango::Renderer::Part>::value_type () -> GType
{
  return pango_render_part_get_type ();
}

namespace glib
{

  auto
  wrap (PangoRenderer* object, const bool take_copy) -> RefPtr<pango::Renderer>
  {
    return glib::make_refptr_for_instance<pango::Renderer> (
        dynamic_cast<pango::Renderer*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace pango
{

  auto
  Renderer_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Renderer_Class::class_init_function;

      register_derived_type (pango_renderer_get_type ());
    }

    return *this;
  }

  auto
  Renderer_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->draw_glyphs = &draw_glyphs_vfunc_callback;
    klass->draw_rectangle = &draw_rectangle_vfunc_callback;
    klass->draw_error_underline = &draw_error_underline_vfunc_callback;
    klass->draw_shape = &draw_shape_vfunc_callback;
    klass->draw_trapezoid = &draw_trapezoid_vfunc_callback;
    klass->draw_glyph = &draw_glyph_vfunc_callback;
    klass->part_changed = &part_changed_vfunc_callback;
    klass->begin = &begin_vfunc_callback;
    klass->end = &end_vfunc_callback;
    klass->prepare_run = &prepare_run_vfunc_callback;
    klass->draw_glyph_item = &draw_glyph_item_vfunc_callback;
  }

  auto
  Renderer_Class::draw_glyphs_vfunc_callback (PangoRenderer* self,
                                              PangoFont* font,
                                              PangoGlyphString* glyphs,
                                              const int x,
                                              const int y) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_glyphs_vfunc (glib::wrap (font, true),
                                  glib::wrap (glyphs, true),
                                  x,
                                  y);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_glyphs)
      (*base->draw_glyphs) (self, font, glyphs, x, y);
  }

  auto
  Renderer_Class::draw_rectangle_vfunc_callback (PangoRenderer* self,
                                                 PangoRenderPart part,
                                                 const int x,
                                                 const int y,
                                                 const int width,
                                                 const int height) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_rectangle_vfunc (static_cast<Part> (part),
                                     x,
                                     y,
                                     width,
                                     height);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_rectangle)
      (*base->draw_rectangle) (self, part, x, y, width, height);
  }

  auto
  Renderer_Class::draw_error_underline_vfunc_callback (PangoRenderer* self,
                                                       const int x,
                                                       const int y,
                                                       const int width,
                                                       const int height) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_error_underline_vfunc (x, y, width, height);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_error_underline)
      (*base->draw_error_underline) (self, x, y, width, height);
  }

  auto
  Renderer_Class::draw_shape_vfunc_callback (PangoRenderer* self,
                                             PangoAttrShape* attr,
                                             const int x,
                                             const int y) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_shape_vfunc (glib::wrap (attr, true), x, y);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_shape)
      (*base->draw_shape) (self, attr, x, y);
  }

  auto
  Renderer_Class::draw_trapezoid_vfunc_callback (PangoRenderer* self,
                                                 PangoRenderPart part,
                                                 const double y1,
                                                 const double x11,
                                                 const double x21,
                                                 const double y2,
                                                 const double x12,
                                                 const double x22) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_trapezoid_vfunc (static_cast<Part> (part),
                                     y1,
                                     x11,
                                     x21,
                                     y2,
                                     x12,
                                     x22);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_trapezoid)
      (*base->draw_trapezoid) (self, part, y1, x11, x21, y2, x12, x22);
  }

  auto
  Renderer_Class::draw_glyph_vfunc_callback (PangoRenderer* self,
                                             PangoFont* font,
                                             const PangoGlyph glyph,
                                             const double x,
                                             const double y) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_glyph_vfunc (glib::wrap (font, true), glyph, x, y);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_glyph)
      (*base->draw_glyph) (self, font, glyph, x, y);
  }

  auto
  Renderer_Class::part_changed_vfunc_callback (PangoRenderer* self,
                                               PangoRenderPart part) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->part_changed_vfunc (static_cast<Part> (part));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->part_changed)
      (*base->part_changed) (self, part);
  }

  auto
  Renderer_Class::begin_vfunc_callback (PangoRenderer* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->begin_vfunc ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->begin)
      (*base->begin) (self);
  }

  auto
  Renderer_Class::end_vfunc_callback (PangoRenderer* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->end_vfunc ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->end)
      (*base->end) (self);
  }

  auto
  Renderer_Class::prepare_run_vfunc_callback (PangoRenderer* self,
                                              PangoGlyphItem* run) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->prepare_run_vfunc (glib::wrap (run, true));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->prepare_run)
      (*base->prepare_run) (self, run);
  }

  auto
  Renderer_Class::draw_glyph_item_vfunc_callback (PangoRenderer* self,
                                                  const char* text,
                                                  PangoGlyphItem* glyph_item,
                                                  const int x,
                                                  const int y) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->draw_glyph_item_vfunc (
              glib::convert_const_gchar_ptr_to_ustring (text),
              glib::wrap (glyph_item, true),
              x,
              y);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->draw_glyph_item)
      (*base->draw_glyph_item) (self, text, glyph_item, x, y);
  }

  auto
  Renderer_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Renderer ((PangoRenderer*) object);
  }

  auto
  Renderer::gobj_copy () -> PangoRenderer*
  {
    reference ();
    return gobj ();
  }

  Renderer::Renderer (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Renderer::Renderer (PangoRenderer* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Renderer::Renderer (Renderer&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Renderer::operator= (Renderer&& src) noexcept -> Renderer&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Renderer::~Renderer () noexcept = default;

  Renderer::CppClassType Renderer::renderer_class_;

  auto
  Renderer::get_type () -> GType
  {
    return renderer_class_.init ().get_type ();
  }

  auto
  Renderer::get_base_type () -> GType
  {
    return pango_renderer_get_type ();
  }

  auto
  Renderer::draw_layout (const glib::RefPtr<Layout>& layout,
                         const int x,
                         const int y) -> void
  {
    pango_renderer_draw_layout (gobj (), glib::unwrap (layout), x, y);
  }

  auto
  Renderer::draw_layout_line (const glib::RefPtr<LayoutLine>& line,
                              const int x,
                              const int y) -> void
  {
    pango_renderer_draw_layout_line (gobj (), glib::unwrap (line), x, y);
  }

  auto
  Renderer::draw_glyphs (const glib::RefPtr<Font>& font,
                         const GlyphString& glyphs,
                         const int x,
                         const int y) -> void
  {
    pango_renderer_draw_glyphs (gobj (),
                                glib::unwrap (font),
                                const_cast<PangoGlyphString*> (glyphs.gobj ()),
                                x,
                                y);
  }

  auto
  Renderer::draw_glyph_item (const glib::ustring& text,
                             const GlyphItem& glyph_item,
                             const int x,
                             const int y) -> void
  {
    pango_renderer_draw_glyph_item (
        gobj (),
        text.c_str (),
        const_cast<PangoGlyphItem*> (glyph_item.gobj ()),
        x,
        y);
  }

  auto
  Renderer::draw_rectangle (Part part,
                            const int x,
                            const int y,
                            const int width,
                            const int height) -> void
  {
    pango_renderer_draw_rectangle (gobj (),
                                   static_cast<PangoRenderPart> (part),
                                   x,
                                   y,
                                   width,
                                   height);
  }

  auto
  Renderer::draw_error_underline (const int x,
                                  const int y,
                                  const int width,
                                  const int height) -> void
  {
    pango_renderer_draw_error_underline (gobj (), x, y, width, height);
  }

  auto
  Renderer::draw_trapezoid (Part part,
                            const double y1,
                            const double x11,
                            const double x21,
                            const double y2,
                            const double x12,
                            const double x22) -> void
  {
    pango_renderer_draw_trapezoid (gobj (),
                                   static_cast<PangoRenderPart> (part),
                                   y1,
                                   x11,
                                   x21,
                                   y2,
                                   x12,
                                   x22);
  }

  auto
  Renderer::draw_glyph (const glib::RefPtr<Font>& font,
                        const Glyph glyph,
                        const double x,
                        const double y) -> void
  {
    pango_renderer_draw_glyph (gobj (), glib::unwrap (font), glyph, x, y);
  }

  auto
  Renderer::activate () -> void
  {
    pango_renderer_activate (gobj ());
  }

  auto
  Renderer::deactivate () -> void
  {
    pango_renderer_deactivate (gobj ());
  }

  auto
  Renderer::part_changed (Part part) -> void
  {
    pango_renderer_part_changed (gobj (), static_cast<PangoRenderPart> (part));
  }

  auto
  Renderer::set_color (Part part, const Color& color) -> void
  {
    pango_renderer_set_color (gobj (),
                              static_cast<PangoRenderPart> (part),
                              color.gobj ());
  }

  auto
  Renderer::get_color (Part part) const -> Color
  {
    return Color (
        pango_renderer_get_color (const_cast<PangoRenderer*> (gobj ()),
                                  static_cast<PangoRenderPart> (part)));
  }

  auto
  Renderer::set_alpha (Part part, const guint16 alpha) -> void
  {
    pango_renderer_set_alpha (gobj (),
                              static_cast<PangoRenderPart> (part),
                              alpha);
  }

  auto
  Renderer::get_alpha (Part part) const -> guint16
  {
    return pango_renderer_get_alpha (const_cast<PangoRenderer*> (gobj ()),
                                     static_cast<PangoRenderPart> (part));
  }

  auto
  Renderer::set_matrix (const Matrix& matrix) -> void
  {
    pango_renderer_set_matrix (gobj (), &matrix);
  }

  auto
  Renderer::get_layout () -> glib::RefPtr<Layout>
  {
    auto retvalue = glib::wrap (pango_renderer_get_layout (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Renderer::get_layout () const -> glib::RefPtr<const Layout>
  {
    return const_cast<Renderer*> (this)->get_layout ();
  }

  auto
  Renderer::get_layout_line () -> glib::RefPtr<LayoutLine>
  {
    auto retvalue = glib::wrap (pango_renderer_get_layout_line (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Renderer::get_layout_line () const -> glib::RefPtr<const LayoutLine>
  {
    return const_cast<Renderer*> (this)->get_layout_line ();
  }

  auto
  Renderer::draw_glyphs_vfunc (const glib::RefPtr<Font>& font,
                               const GlyphString& glyphs,
                               const int x,
                               const int y) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_glyphs)
    {
      (*base->draw_glyphs) (gobj (),
                            glib::unwrap (font),
                            const_cast<PangoGlyphString*> (glyphs.gobj ()),
                            x,
                            y);
    }
  }

  auto
  Renderer::draw_rectangle_vfunc (Part part,
                                  const int x,
                                  const int y,
                                  const int width,
                                  const int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_rectangle)
    {
      (*base->draw_rectangle) (gobj (),
                               static_cast<PangoRenderPart> (part),
                               x,
                               y,
                               width,
                               height);
    }
  }

  auto
  Renderer::draw_error_underline_vfunc (const int x,
                                        const int y,
                                        const int width,
                                        const int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_error_underline)
    {
      (*base->draw_error_underline) (gobj (), x, y, width, height);
    }
  }

  auto
  Renderer::draw_shape_vfunc (const AttrShape& attr, const int x, const int y) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_shape)
    {
      (*base->draw_shape) (gobj (),
                           const_cast<PangoAttrShape*> (attr.gobj ()),
                           x,
                           y);
    }
  }

  auto
  Renderer::draw_trapezoid_vfunc (Part part,
                                  const double y1,
                                  const double x11,
                                  const double x21,
                                  const double y2,
                                  const double x12,
                                  const double x22) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_trapezoid)
    {
      (*base->draw_trapezoid) (gobj (),
                               static_cast<PangoRenderPart> (part),
                               y1,
                               x11,
                               x21,
                               y2,
                               x12,
                               x22);
    }
  }

  auto
  Renderer::draw_glyph_vfunc (const glib::RefPtr<Font>& font,
                              const Glyph glyph,
                              const double x,
                              const double y) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_glyph)
    {
      (*base->draw_glyph) (gobj (), glib::unwrap (font), glyph, x, y);
    }
  }

  auto
  Renderer::part_changed_vfunc (Part part) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->part_changed)
    {
      (*base->part_changed) (gobj (), static_cast<PangoRenderPart> (part));
    }
  }

  auto
  Renderer::begin_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->begin)
    {
      (*base->begin) (gobj ());
    }
  }

  auto
  Renderer::end_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->end)
    {
      (*base->end) (gobj ());
    }
  }

  auto
  Renderer::prepare_run_vfunc (const GlyphItem& run) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->prepare_run)
    {
      (*base->prepare_run) (gobj (), const_cast<PangoGlyphItem*> (run.gobj ()));
    }
  }

  auto
  Renderer::draw_glyph_item_vfunc (const glib::ustring& text,
                                   const GlyphItem& glyph_item,
                                   const int x,
                                   const int y) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->draw_glyph_item)
    {
      (*base->draw_glyph_item) (
          gobj (),
          text.c_str (),
          const_cast<PangoGlyphItem*> (glyph_item.gobj ()),
          x,
          y);
    }
  }

} // namespace pango
