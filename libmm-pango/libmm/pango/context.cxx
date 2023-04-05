// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/context.hxx>
#include <libmm/pango/context_p.hxx>

#include <pango/pangocairo.h>

namespace pango
{

  auto
  Context::list_families () const -> std::vector<glib::RefPtr<FontFamily>>
  {
    PangoFontFamily** pFamilies = nullptr;
    int n_families = 0;
    pango_context_list_families (const_cast<PangoContext*> (gobj ()),
                                 &pFamilies,
                                 &n_families);

    return glib::ArrayHandler<glib::RefPtr<FontFamily>>::array_to_vector (
        pFamilies,
        n_families,
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  Context::get_metrics (const FontDescription& desc) const -> FontMetrics
  {
    return FontMetrics (
        pango_context_get_metrics (const_cast<PangoContext*> (gobj ()),
                                   desc.gobj (),
                                   nullptr));
  }

  struct ItemTraits
  {
    typedef Item CppType;
    typedef const PangoItem* CType;
    typedef PangoItem* CTypeNonConst;

    static auto
    to_c_type (const CppType& obj) -> CType
    {
      return obj.gobj ();
    }

    static auto
    to_c_type (const CType ptr) -> CType
    {
      return ptr;
    }

    static auto
    to_cpp_type (const CType ptr) -> CppType
    {
      return CppType (const_cast<CTypeNonConst> (ptr), true);
    }

    static auto
    release_c_type (const CType ptr) -> void
    {
      pango_item_free (const_cast<CTypeNonConst> (ptr));
    }
  };

  using ListHandler_Item = glib::ListHandler<Item, ItemTraits>;

  auto
  Context::itemize (const glib::ustring& text, const AttrList& attrs) const -> std::vector<Item>
  {
    return ListHandler_Item::list_to_vector (
        pango_itemize (const_cast<PangoContext*> (gobj ()),
                       text.c_str (),
                       0,
                       text.bytes (),
                       const_cast<PangoAttrList*> (attrs.gobj ()),
                       nullptr),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Context::itemize (const glib::ustring& text,
                    const int start_index,
                    const int length,
                    const AttrList& attrs,
                    AttrIter& cached_iter) const -> std::vector<Item>
  {
    return ListHandler_Item::list_to_vector (
        pango_itemize (const_cast<PangoContext*> (gobj ()),
                       text.c_str (),
                       start_index,
                       length,
                       const_cast<PangoAttrList*> (attrs.gobj ()),
                       cached_iter.gobj ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  Context::update_from_cairo_context (
      const cairo::RefPtr<cairo::Context>& context) -> void
  {
    pango_cairo_update_context (context->cobj (), gobj ());
  }

  auto
  Context::get_matrix () const -> Matrix
  {
    const auto* matrix =
        pango_context_get_matrix (const_cast<PangoContext*> (gobj ()));
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
glib::Value<pango::Direction>::value_type () -> GType
{
  return pango_direction_get_type ();
}

auto
glib::Value<pango::GravityHint>::value_type () -> GType
{
  return pango_gravity_hint_get_type ();
}

namespace glib
{

  auto
  wrap (PangoContext* object, const bool take_copy) -> RefPtr<pango::Context>
  {
    return glib::make_refptr_for_instance<pango::Context> (
        dynamic_cast<pango::Context*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace pango
{

  auto
  Context_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Context_Class::class_init_function;

      register_derived_type (pango_context_get_type ());
    }

    return *this;
  }

  auto
  Context_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Context_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Context ((PangoContext*) object);
  }

  auto
  Context::gobj_copy () -> PangoContext*
  {
    reference ();
    return gobj ();
  }

  Context::Context (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Context::Context (PangoContext* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Context::Context (Context&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Context::operator= (Context&& src) noexcept -> Context&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Context::~Context () noexcept = default;

  Context::CppClassType Context::context_class_;

  auto
  Context::get_type () -> GType
  {
    return context_class_.init ().get_type ();
  }

  auto
  Context::get_base_type () -> GType
  {
    return pango_context_get_type ();
  }

  Context::Context ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (context_class_.init ()))
  {
  }

  auto
  Context::set_font_map (const glib::RefPtr<FontMap>& font_map) -> void
  {
    pango_context_set_font_map (gobj (), glib::unwrap (font_map));
  }

  auto
  Context::get_font_map () -> glib::RefPtr<FontMap>
  {
    auto retvalue = glib::wrap (pango_context_get_font_map (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Context::get_font_map () const -> glib::RefPtr<const FontMap>
  {
    return const_cast<Context*> (this)->get_font_map ();
  }

  auto
  Context::get_serial () const -> guint
  {
    return pango_context_get_serial (const_cast<PangoContext*> (gobj ()));
  }

  auto
  Context::load_font (const FontDescription& desc) const -> glib::RefPtr<Font>
  {
    return glib::wrap (
        pango_context_load_font (const_cast<PangoContext*> (gobj ()),
                                 desc.gobj ()));
  }

  auto
  Context::load_fontset (const FontDescription& desc,
                         const Language& language) const -> glib::RefPtr<Fontset>
  {
    return glib::wrap (pango_context_load_fontset (
        const_cast<PangoContext*> (gobj ()),
        desc.gobj (),
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  Context::get_metrics (const FontDescription& desc,
                        const Language& language) const -> FontMetrics
  {
    return FontMetrics (pango_context_get_metrics (
        const_cast<PangoContext*> (gobj ()),
        desc.gobj (),
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  Context::set_font_description (const FontDescription& desc) -> void
  {
    pango_context_set_font_description (gobj (), desc.gobj ());
  }

  auto
  Context::get_font_description () const -> FontDescription
  {
    return FontDescription (pango_context_get_font_description (
        const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::get_language () const -> Language
  {
    return Language (
        pango_context_get_language (const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::set_language (const Language& language) -> void
  {
    pango_context_set_language (gobj (),
                                const_cast<PangoLanguage*> (language.gobj ()));
  }

  auto
  Context::set_base_dir (Direction direction) -> void
  {
    pango_context_set_base_dir (gobj (),
                                static_cast<PangoDirection> (direction));
  }

  auto
  Context::get_base_dir () const -> Direction
  {
    return static_cast<Direction> (
        pango_context_get_base_dir (const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::set_base_gravity (Gravity gravity) -> void
  {
    pango_context_set_base_gravity (gobj (),
                                    static_cast<PangoGravity> (gravity));
  }

  auto
  Context::get_base_gravity () const -> Gravity
  {
    return static_cast<Gravity> (
        pango_context_get_base_gravity (const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::get_gravity () const -> Gravity
  {
    return static_cast<Gravity> (
        pango_context_get_gravity (const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::set_gravity_hint (GravityHint hint) -> void
  {
    pango_context_set_gravity_hint (gobj (),
                                    static_cast<PangoGravityHint> (hint));
  }

  auto
  Context::get_gravity_hint () const -> GravityHint
  {
    return static_cast<GravityHint> (
        pango_context_get_gravity_hint (const_cast<PangoContext*> (gobj ())));
  }

  auto
  Context::set_matrix (const Matrix& matrix) -> void
  {
    pango_context_set_matrix (gobj (), &matrix);
  }

  auto
  Context::set_cairo_font_options (const cairo::FontOptions& options) -> void
  {
    pango_cairo_context_set_font_options (gobj (), options.cobj ());
  }

  auto
  Context::get_font_options () const -> cairo::FontOptions
  {
    return cairo::FontOptions (const_cast<cairo_font_options_t*> (
                                   pango_cairo_context_get_font_options (
                                       const_cast<PangoContext*> (gobj ()))),
                               false);
  }

  auto
  Context::set_resolution (const double dpi) -> void
  {
    pango_cairo_context_set_resolution (gobj (), dpi);
  }

  auto
  Context::get_resolution () const -> double
  {
    return pango_cairo_context_get_resolution (
        const_cast<PangoContext*> (gobj ()));
  }

} // namespace pango
