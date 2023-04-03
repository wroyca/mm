// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/pango/fontmap.hxx>
#include <libmm/pango/fontmap_p.hxx>

#include <libmm/pango/cairofontmapimpl.hxx>
#include <libmm/pango/context.hxx>
#include <pango/pangocairo.h>

namespace Pango
{

  auto
  FontMap_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    if (PANGO_IS_CAIRO_FONT_MAP (object))
      return new CairoFontMapImpl ((PangoFontMap*) object);
    return new FontMap ((PangoFontMap*) object);
  }

  auto
  FontMap::list_families () const -> std::vector<Glib::RefPtr<FontFamily>>
  {
    PangoFontFamily** pFamilies = nullptr;
    int n_families = 0;
    pango_font_map_list_families (const_cast<PangoFontMap*> (gobj ()),
                                  &pFamilies,
                                  &n_families);

    return Glib::ArrayHandler<Glib::RefPtr<FontFamily>>::array_to_vector (
        pFamilies,
        n_families,
        Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoFontMap* object, const bool take_copy) -> RefPtr<Pango::FontMap>
  {
    return Glib::make_refptr_for_instance<Pango::FontMap> (
        dynamic_cast<Pango::FontMap*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Pango
{

  auto
  FontMap_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontMap_Class::class_init_function;

      register_derived_type (pango_font_map_get_type ());

      Gio::ListModel::add_interface (get_type ());
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

  FontMap::FontMap (const Glib::ConstructParams& construct_params)
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
  FontMap::load_font (const Glib::RefPtr<Context>& context,
                      const FontDescription& desc) const -> Glib::RefPtr<Font>
  {
    return Glib::wrap (
        pango_font_map_load_font (const_cast<PangoFontMap*> (gobj ()),
                                  Glib::unwrap (context),
                                  desc.gobj ()));
  }

  auto
  FontMap::load_fontset (const Glib::RefPtr<Context>& context,
                         const FontDescription& desc,
                         const Language& language) const -> Glib::RefPtr<Fontset>
  {
    return Glib::wrap (pango_font_map_load_fontset (
        const_cast<PangoFontMap*> (gobj ()),
        Glib::unwrap (context),
        desc.gobj (),
        const_cast<PangoLanguage*> (language.gobj ())));
  }

  auto
  FontMap::create_context () -> Glib::RefPtr<Context>
  {
    return Glib::wrap (pango_font_map_create_context (gobj ()));
  }

  auto
  FontMap::get_serial () const -> guint
  {
    return pango_font_map_get_serial (const_cast<PangoFontMap*> (gobj ()));
  }

  auto
  FontMap::get_family (const Glib::ustring& name) -> Glib::RefPtr<FontFamily>
  {
    auto retvalue =
        Glib::wrap (pango_font_map_get_family (gobj (), name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontMap::get_family (const Glib::ustring& name) const -> Glib::RefPtr<const FontFamily>
  {
    return const_cast<FontMap*> (this)->get_family (name);
  }

} // namespace Pango
