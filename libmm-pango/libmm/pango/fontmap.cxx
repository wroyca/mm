// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/fontmap.hxx>
#include <libmm/pango/fontmap_p.hxx>

#include <libmm/pango/cairofontmapimpl.hxx>
#include <libmm/pango/context.hxx>
#include <pango/pangocairo.h>

namespace pango
{

  auto
  FontMap_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    if (PANGO_IS_CAIRO_FONT_MAP (object))
      return new CairoFontMapImpl ((PangoFontMap*) object);
    return new FontMap ((PangoFontMap*) object);
  }

  auto
  FontMap::list_families () const -> std::vector<glib::RefPtr<FontFamily>>
  {
    PangoFontFamily** pFamilies = nullptr;
    int n_families = 0;
    pango_font_map_list_families (const_cast<PangoFontMap*> (gobj ()),
                                  &pFamilies,
                                  &n_families);

    return glib::ArrayHandler<glib::RefPtr<FontFamily>>::array_to_vector (
        pFamilies,
        n_families,
        glib::OWNERSHIP_SHALLOW);
  }

} // namespace pango

namespace
{
}

namespace glib
{

  auto
  wrap (PangoFontMap* object, const bool take_copy) -> RefPtr<pango::FontMap>
  {
    return glib::make_refptr_for_instance<pango::FontMap> (
        dynamic_cast<pango::FontMap*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace pango
{

  auto
  FontMap_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontMap_Class::class_init_function;

      register_derived_type (pango_font_map_get_type ());

      gio::ListModel::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FontMap_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontMap::gobj_copy () -> PangoFontMap*
  {
    reference ();
    return gobj ();
  }

  FontMap::FontMap (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FontMap::FontMap (PangoFontMap* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FontMap::FontMap (FontMap&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  FontMap::operator= (FontMap&& src) noexcept -> FontMap&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  FontMap::~FontMap () noexcept = default;

  FontMap::CppClassType FontMap::fontmap_class_;

  auto
  FontMap::get_type () -> GType
  {
    return fontmap_class_.init ().get_type ();
  }

  auto
  FontMap::get_base_type () -> GType
  {
    return pango_font_map_get_type ();
  }

  auto
  FontMap::load_font (const glib::RefPtr<Context>& context,
                      const FontDescription& desc) const -> glib::RefPtr<Font>
  {
    return glib::wrap (
        pango_font_map_load_font (const_cast<PangoFontMap*> (gobj ()),
                                  glib::unwrap (context),
                                  desc.gobj ()));
  }

  auto
  FontMap::load_fontset (const glib::RefPtr<Context>& context,
                         const FontDescription& desc,
                         const Language& language) const -> glib::RefPtr<Fontset>
  {
    return glib::wrap (pango_font_map_load_fontset (
        const_cast<PangoFontMap*> (gobj ()),
        glib::unwrap (context),
        desc.gobj (),
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  FontMap::create_context () -> glib::RefPtr<Context>
  {
    return glib::wrap (pango_font_map_create_context (gobj ()));
  }

  auto
  FontMap::get_serial () const -> guint
  {
    return pango_font_map_get_serial (const_cast<PangoFontMap*> (gobj ()));
  }

  auto
  FontMap::get_family (const glib::ustring& name) -> glib::RefPtr<FontFamily>
  {
    auto retvalue =
        glib::wrap (pango_font_map_get_family (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontMap::get_family (const glib::ustring& name) const -> glib::RefPtr<const FontFamily>
  {
    return const_cast<FontMap*> (this)->get_family (name);
  }

} // namespace pango
