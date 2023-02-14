// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/fontface.hxx>
#include <libmm-pango/fontface_p.hxx>

#include <libmm-pango/fontfamily.hxx>

namespace Pango
{

  auto
  FontFace::list_sizes () const -> std::vector<int>
  {
    int* sizes = nullptr;
    int n_sizes = 0;
    pango_font_face_list_sizes (const_cast<PangoFontFace*> (gobj ()),
                                &sizes,
                                &n_sizes);

    return Glib::ArrayHandler<int>::array_to_vector (sizes,
                                                     n_sizes,
                                                     Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoFontFace* object, const bool take_copy) -> RefPtr<Pango::FontFace>
  {
    return Glib::make_refptr_for_instance<Pango::FontFace> (
        dynamic_cast<Pango::FontFace*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Pango
{

  auto
  FontFace_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontFace_Class::class_init_function;

      register_derived_type (pango_font_face_get_type ());
    }

    return *this;
  }

  auto
  FontFace_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontFace_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FontFace ((PangoFontFace*) object);
  }

  auto
  FontFace::gobj_copy () -> PangoFontFace*
  {
    reference ();
    return gobj ();
  }

  FontFace::FontFace (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FontFace::FontFace (PangoFontFace* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FontFace::FontFace (FontFace&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  FontFace::operator= (FontFace&& src) noexcept -> FontFace&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  FontFace::~FontFace () noexcept = default;

  FontFace::CppClassType FontFace::fontface_class_;

  auto
  FontFace::get_type () -> GType
  {
    return fontface_class_.init ().get_type ();
  }

  auto
  FontFace::get_base_type () -> GType
  {
    return pango_font_face_get_type ();
  }

  auto
  FontFace::describe () const -> FontDescription
  {
    return FontDescription (
        pango_font_face_describe (const_cast<PangoFontFace*> (gobj ())));
  }

  auto
  FontFace::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        pango_font_face_get_face_name (const_cast<PangoFontFace*> (gobj ())));
  }

  auto
  FontFace::is_synthesized () const -> bool
  {
    return pango_font_face_is_synthesized (
        const_cast<PangoFontFace*> (gobj ()));
  }

  auto
  FontFace::get_family () -> Glib::RefPtr<FontFamily>
  {
    auto retvalue = Glib::wrap (pango_font_face_get_family (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontFace::get_family () const -> Glib::RefPtr<const FontFamily>
  {
    return const_cast<FontFace*> (this)->get_family ();
  }

} // namespace Pango
