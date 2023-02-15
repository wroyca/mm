// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/cairocontext.hxx>
#include <libmm-gdk/cairocontext_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/cairoutils.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkCairoContext* object, bool take_copy) -> Glib::RefPtr<Gdk::CairoContext>
  {
    return Glib::make_refptr_for_instance<Gdk::CairoContext> (
        dynamic_cast<Gdk::CairoContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  CairoContext_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CairoContext_Class::class_init_function;

      register_derived_type (gdk_cairo_context_get_type ());
    }

    return *this;
  }

  auto
  CairoContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CairoContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CairoContext ((GdkCairoContext*) object);
  }

  auto
  CairoContext::gobj_copy () -> GdkCairoContext*
  {
    reference ();
    return gobj ();
  }

  CairoContext::CairoContext (const Glib::ConstructParams& construct_params)
    : Gdk::DrawContext (construct_params)
  {
  }

  CairoContext::CairoContext (GdkCairoContext* castitem)
    : Gdk::DrawContext ((GdkDrawContext*) (castitem))
  {
  }

  CairoContext::CairoContext (CairoContext&& src) noexcept
    : Gdk::DrawContext (std::move (src))
  {
  }

  auto
  CairoContext::operator= (CairoContext&& src) noexcept -> CairoContext&
  {
    Gdk::DrawContext::operator= (std::move (src));
    return *this;
  }

  CairoContext::~CairoContext () noexcept {}

  CairoContext::CppClassType CairoContext::cairocontext_class_;

  auto
  CairoContext::get_type () -> GType
  {
    return cairocontext_class_.init ().get_type ();
  }

  auto
  CairoContext::get_base_type () -> GType
  {
    return gdk_cairo_context_get_type ();
  }

  CairoContext::CairoContext ()
    : Glib::ObjectBase (nullptr),
      Gdk::DrawContext (Glib::ConstructParams (cairocontext_class_.init ()))
  {
  }

  auto
  CairoContext::cairo_create () -> ::Cairo::RefPtr<::Cairo::Context>
  {
    return Gdk::Cairo::wrap (gdk_cairo_context_cairo_create (gobj ()));
  }

} // namespace Gdk
