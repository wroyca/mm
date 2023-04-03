// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/drawcontext.hxx>
#include <libmm/gdk/drawcontext_p.hxx>

#include <libmm/gdk/cairoutils.hxx>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/surface.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkDrawContext* object, bool take_copy) -> Glib::RefPtr<Gdk::DrawContext>
  {
    return Glib::make_refptr_for_instance<Gdk::DrawContext> (
        dynamic_cast<Gdk::DrawContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  DrawContext_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DrawContext_Class::class_init_function;

      register_derived_type (gdk_draw_context_get_type ());
    }

    return *this;
  }

  auto
  DrawContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  DrawContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DrawContext ((GdkDrawContext*) object);
  }

  auto
  DrawContext::gobj_copy () -> GdkDrawContext*
  {
    reference ();
    return gobj ();
  }

  DrawContext::DrawContext (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  DrawContext::DrawContext (GdkDrawContext* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  DrawContext::DrawContext (DrawContext&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  DrawContext::operator= (DrawContext&& src) noexcept -> DrawContext&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  DrawContext::~DrawContext () noexcept {}

  DrawContext::CppClassType DrawContext::drawcontext_class_;

  auto
  DrawContext::get_type () -> GType
  {
    return drawcontext_class_.init ().get_type ();
  }

  auto
  DrawContext::get_base_type () -> GType
  {
    return gdk_draw_context_get_type ();
  }

  DrawContext::DrawContext ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (drawcontext_class_.init ()))
  {
  }

  auto
  DrawContext::get_display () -> Glib::RefPtr<Display>
  {
    auto retvalue = Glib::wrap (gdk_draw_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DrawContext::get_display () const -> Glib::RefPtr<const Display>
  {
    return const_cast<DrawContext*> (this)->get_display ();
  }

  auto
  DrawContext::get_surface () -> Glib::RefPtr<Surface>
  {
    auto retvalue = Glib::wrap (gdk_draw_context_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DrawContext::get_surface () const -> Glib::RefPtr<const Surface>
  {
    return const_cast<DrawContext*> (this)->get_surface ();
  }

  auto
  DrawContext::begin_frame (
      const ::Cairo::RefPtr<const ::Cairo::Region>& region) -> void
  {
    gdk_draw_context_begin_frame (gobj (),
                                  ((region) ? (region)->cobj () : nullptr));
  }

  auto
  DrawContext::end_frame () -> void
  {
    gdk_draw_context_end_frame (gobj ());
  }

  auto
  DrawContext::is_in_frame () const -> bool
  {
    return gdk_draw_context_is_in_frame (const_cast<GdkDrawContext*> (gobj ()));
  }

  auto
  DrawContext::get_frame_region () const -> ::Cairo::RefPtr<const ::Cairo::Region>
  {
    auto retvalue = Gdk::Cairo::wrap (
        const_cast<cairo_region_t*> (gdk_draw_context_get_frame_region (
            const_cast<GdkDrawContext*> (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Display>>::value,
      "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DrawContext::property_display () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Surface>>::value,
      "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  DrawContext::property_surface () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace Gdk
