// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-pango/fontset.hxx>
#include <libmm-pango/fontset_p.hxx>

static auto
fontset_foreach_callback (PangoFontset*, PangoFont* font, const gpointer data)
    -> gboolean
{
  try
  {
    const auto& slot = *static_cast<Pango::Fontset::ForeachSlot*> (data);
    const auto cppFont = Glib::wrap (font, true);

    return slot (cppFont);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke ();
  }

  return false;
}

namespace Pango
{

  auto
  Fontset::foreach (const ForeachSlot& slot) -> void
  {
    pango_fontset_foreach (gobj (), &fontset_foreach_callback, (void*) &slot);
  }

} // namespace Pango

namespace
{
}

namespace Glib
{

  auto
  wrap (PangoFontset* object, const bool take_copy) -> RefPtr<Pango::Fontset>
  {
    return Glib::make_refptr_for_instance<Pango::Fontset> (
        dynamic_cast<Pango::Fontset*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Pango
{

  auto
  Fontset_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Fontset_Class::class_init_function;

      register_derived_type (pango_fontset_get_type ());
    }

    return *this;
  }

  auto
  Fontset_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Fontset_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Fontset ((PangoFontset*) object);
  }

  auto
  Fontset::gobj_copy () -> PangoFontset*
  {
    reference ();
    return gobj ();
  }

  Fontset::Fontset (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  Fontset::Fontset (PangoFontset* castitem)
    : Object ((GObject*) castitem)
  {
  }

  Fontset::Fontset (Fontset&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  Fontset::operator= (Fontset&& src) noexcept -> Fontset&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  Fontset::~Fontset () noexcept = default;

  Fontset::CppClassType Fontset::fontset_class_;

  auto
  Fontset::get_type () -> GType
  {
    return fontset_class_.init ().get_type ();
  }

  auto
  Fontset::get_base_type () -> GType
  {
    return pango_fontset_get_type ();
  }

  auto
  Fontset::get_font (const guint wc) const -> Glib::RefPtr<Font>
  {
    return Glib::wrap (
        pango_fontset_get_font (const_cast<PangoFontset*> (gobj ()), wc));
  }

  auto
  Fontset::get_metrics () const -> FontMetrics
  {
    return FontMetrics (
        pango_fontset_get_metrics (const_cast<PangoFontset*> (gobj ())));
  }

} // namespace Pango
