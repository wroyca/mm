// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/cairofontmap.hxx>
#include <libmm-pango/cairofontmap_p.hxx>

#include <pango/pangocairo.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoCairoFontMap* object, const bool take_copy) -> RefPtr<Pango::CairoFontMap>
  {
    return Glib::make_refptr_for_instance<Pango::CairoFontMap> (
        Glib::wrap_auto_interface<Pango::CairoFontMap> ((GObject*) object,
                                                        take_copy));
  }

} // namespace Glib

namespace Pango
{

  auto
  CairoFontMap_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CairoFontMap_Class::iface_init_function;

      gtype_ = pango_cairo_font_map_get_type ();
    }

    return *this;
  }

  auto
  CairoFontMap_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  CairoFontMap_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CairoFontMap ((PangoCairoFontMap*) object);
  }

  CairoFontMap::CairoFontMap ()
    : Interface (cairofontmap_class_.init ())
  {
  }

  CairoFontMap::CairoFontMap (PangoCairoFontMap* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  CairoFontMap::CairoFontMap (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  CairoFontMap::CairoFontMap (CairoFontMap&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  CairoFontMap::operator= (CairoFontMap&& src) noexcept -> CairoFontMap&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  CairoFontMap::~CairoFontMap () noexcept = default;

  auto
  CairoFontMap::add_interface (const GType gtype_implementer) -> void
  {
    cairofontmap_class_.init ().add_interface (gtype_implementer);
  }

  CairoFontMap::CppClassType CairoFontMap::cairofontmap_class_;

  auto
  CairoFontMap::get_type () -> GType
  {
    return cairofontmap_class_.init ().get_type ();
  }

  auto
  CairoFontMap::get_base_type () -> GType
  {
    return pango_cairo_font_map_get_type ();
  }

  auto
  CairoFontMap::get_default () -> Glib::RefPtr<FontMap>
  {
    auto retvalue = Glib::wrap (pango_cairo_font_map_get_default ());
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CairoFontMap::set_default () -> void
  {
    pango_cairo_font_map_set_default (gobj ());
  }

  auto
  CairoFontMap::get_font_type () const -> Cairo::FontType
  {
    return static_cast<Cairo::FontType> (pango_cairo_font_map_get_font_type (
        const_cast<PangoCairoFontMap*> (gobj ())));
  }

  auto
  CairoFontMap::set_resolution (const double dpi) -> void
  {
    pango_cairo_font_map_set_resolution (gobj (), dpi);
  }

  auto
  CairoFontMap::get_resolution () const -> double
  {
    return pango_cairo_font_map_get_resolution (
        const_cast<PangoCairoFontMap*> (gobj ()));
  }

} // namespace Pango
