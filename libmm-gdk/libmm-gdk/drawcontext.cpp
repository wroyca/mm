


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/drawcontext.hpp>
#include <libmm-gdk/drawcontext_p.hpp>


/* Copyright (C) 2016 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmm-gdk/cairoutils.hpp>
#include <libmm-gdk/display.hpp>
#include <libmm-gdk/surface.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkDrawContext* object, const bool take_copy) -> RefPtr<Gdk::DrawContext>
{
  return Glib::make_refptr_for_instance<Gdk::DrawContext>( dynamic_cast<Gdk::DrawContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto DrawContext_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DrawContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_draw_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto DrawContext_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DrawContext_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new DrawContext((GdkDrawContext*)object);
}


/* The implementation: */

auto DrawContext::gobj_copy() -> GdkDrawContext*
{
  reference();
  return gobj();
}

DrawContext::DrawContext(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

DrawContext::DrawContext(GdkDrawContext* castitem)
: Object((GObject*)castitem)
{}


DrawContext::DrawContext(DrawContext&& src) noexcept
: Object(std::move(src))
{}

auto DrawContext::operator=(DrawContext&& src) noexcept -> DrawContext&
{
  Object::operator=(std::move(src));
  return *this;
}


DrawContext::~DrawContext() noexcept = default;

DrawContext::CppClassType DrawContext::drawcontext_class_; // initialize static member

auto DrawContext::get_type() -> GType
{
  return drawcontext_class_.init().get_type();
}


auto DrawContext::get_base_type() -> GType
{
  return gdk_draw_context_get_type();
}


DrawContext::DrawContext()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(drawcontext_class_.init()))
{


}

auto DrawContext::get_display() -> Glib::RefPtr<Display>
{
  auto retvalue = Glib::wrap(gdk_draw_context_get_display(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DrawContext::get_display() const -> Glib::RefPtr<const Display>
{
  return const_cast<DrawContext*>(this)->get_display();
}

auto DrawContext::get_surface() -> Glib::RefPtr<Surface>
{
  auto retvalue = Glib::wrap(gdk_draw_context_get_surface(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto DrawContext::get_surface() const -> Glib::RefPtr<const Surface>
{
  return const_cast<DrawContext*>(this)->get_surface();
}

auto DrawContext::begin_frame (const ::Cairo::RefPtr <const ::Cairo::Region> &region) -> void
{
  gdk_draw_context_begin_frame(gobj(), region ? region->cobj() : nullptr);
}

auto DrawContext::end_frame () -> void
{
  gdk_draw_context_end_frame(gobj());
}

auto DrawContext::is_in_frame() const -> bool
{
  return gdk_draw_context_is_in_frame(const_cast<GdkDrawContext*>(gobj()));
}

auto DrawContext::get_frame_region() const -> ::Cairo::RefPtr<const ::Cairo::Region>
{
  auto retvalue = Cairo::wrap(const_cast<cairo_region_t*>(gdk_draw_context_get_frame_region(const_cast<GdkDrawContext*>(gobj()))));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Display>>::value,
  "Type Glib::RefPtr<Display> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DrawContext::property_display() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> >
{
  return {this, "display"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Surface>>::value,
  "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto DrawContext::property_surface() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >
{
  return {this, "surface"};
}


} // namespace Gdk


