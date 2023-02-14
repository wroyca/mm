

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/fontfamily.hxx>
#include <libmm-pango/fontfamily_p.hxx>

namespace Pango
{

  auto
  FontFamily::list_faces () const -> std::vector<Glib::RefPtr<FontFace>>
  {
    PangoFontFace** pFontFaces = nullptr;
    int n_fonts = 0;
    pango_font_family_list_faces (const_cast<PangoFontFamily*> (gobj ()),
                                  &pFontFaces,
                                  &n_fonts);

    return Glib::ArrayHandler<Glib::RefPtr<FontFace>>::array_to_vector (
        pFontFaces,
        n_fonts,
        Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoFontFamily* object, const bool take_copy) -> RefPtr<Pango::FontFamily>
  {
    return Glib::make_refptr_for_instance<Pango::FontFamily> (
        dynamic_cast<Pango::FontFamily*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Pango
{

  auto
  FontFamily_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontFamily_Class::class_init_function;

      register_derived_type (pango_font_family_get_type ());

      Gio::ListModel::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FontFamily_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontFamily_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FontFamily ((PangoFontFamily*) object);
  }

  auto
  FontFamily::gobj_copy () -> PangoFontFamily*
  {
    reference ();
    return gobj ();
  }

  FontFamily::FontFamily (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FontFamily::FontFamily (PangoFontFamily* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FontFamily::FontFamily (FontFamily&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  FontFamily::operator= (FontFamily&& src) noexcept -> FontFamily&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  FontFamily::~FontFamily () noexcept = default;

  FontFamily::CppClassType FontFamily::fontfamily_class_;

  auto
  FontFamily::get_type () -> GType
  {
    return fontfamily_class_.init ().get_type ();
  }

  auto
  FontFamily::get_base_type () -> GType
  {
    return pango_font_family_get_type ();
  }

  auto
  FontFamily::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        pango_font_family_get_name (const_cast<PangoFontFamily*> (gobj ())));
  }

  auto
  FontFamily::is_monospace () const -> bool
  {
    return pango_font_family_is_monospace (
        const_cast<PangoFontFamily*> (gobj ()));
  }

  auto
  FontFamily::is_variable () const -> bool
  {
    return pango_font_family_is_variable (
        const_cast<PangoFontFamily*> (gobj ()));
  }

  auto
  FontFamily::get_face (const Glib::ustring& name) -> Glib::RefPtr<FontFace>
  {
    auto retvalue = Glib::wrap (
        pango_font_family_get_face (gobj (),
                                    name.empty () ? nullptr : name.c_str ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FontFamily::get_face (const Glib::ustring& name) const -> Glib::RefPtr<const FontFace>
  {
    return const_cast<FontFamily*> (this)->get_face (name);
  }

} // namespace Pango
