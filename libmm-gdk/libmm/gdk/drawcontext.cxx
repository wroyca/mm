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

namespace glib
{

  auto
  wrap (GdkDrawContext* object, bool take_copy) -> glib::RefPtr<gdk::DrawContext>
  {
    return glib::make_refptr_for_instance<gdk::DrawContext> (
        dynamic_cast<gdk::DrawContext*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  DrawContext_Class::init () -> const glib::Class&
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
  DrawContext_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DrawContext ((GdkDrawContext*) object);
  }

  auto
  DrawContext::gobj_copy () -> GdkDrawContext*
  {
    reference ();
    return gobj ();
  }

  DrawContext::DrawContext (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  DrawContext::DrawContext (GdkDrawContext* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  DrawContext::DrawContext (DrawContext&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  DrawContext::operator= (DrawContext&& src) noexcept -> DrawContext&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (drawcontext_class_.init ()))
  {
  }

  auto
  DrawContext::get_display () -> glib::RefPtr<Display>
  {
    auto retvalue = glib::wrap (gdk_draw_context_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DrawContext::get_display () const -> glib::RefPtr<const Display>
  {
    return const_cast<DrawContext*> (this)->get_display ();
  }

  auto
  DrawContext::get_surface () -> glib::RefPtr<Surface>
  {
    auto retvalue = glib::wrap (gdk_draw_context_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  DrawContext::get_surface () const -> glib::RefPtr<const Surface>
  {
    return const_cast<DrawContext*> (this)->get_surface ();
  }

  auto
  DrawContext::begin_frame (
      const ::cairo::RefPtr<const ::cairo::Region>& region) -> void
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
  DrawContext::get_frame_region () const -> ::cairo::RefPtr<const ::cairo::Region>
  {
    auto retvalue = gdk::cairo::wrap (
        const_cast<cairo_region_t*> (gdk_draw_context_get_frame_region (
            const_cast<GdkDrawContext*> (gobj ()))));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Display>>::value,
      "Type glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DrawContext::property_display () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>> (this,
                                                                "display");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Surface>>::value,
      "Type glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  DrawContext::property_surface () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>> (this,
                                                                "surface");
  }

} // namespace gdk
